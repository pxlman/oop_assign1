#include "Polynomial.h"

// Default constructor
Polynomial::Polynomial() : coff({0}) {}

// Constructor with coefficient vector
Polynomial::Polynomial(const vector<double>& coefficients) : coff(coefficients) {}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) : coff(other.coff) {}

// Destructor
Polynomial::~Polynomial() {}

// Assignment operator
Polynomial Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coff = other.coff;
    }
    return *this;
}

// Addition operator
Polynomial Polynomial::operator+(const Polynomial& other) const {
    size_t maxSize = max(coff.size(), other.coff.size());
    vector<double> result(maxSize, 0);

    for (size_t i = 0; i < maxSize; ++i) {
        double a = (i < coff.size()) ? coff[i] : 0;
        double b = (i < other.coff.size()) ? other.coff[i] : 0;
        result[i] = a + b;
    }

    return Polynomial(result);
}

// Subtraction operator
Polynomial Polynomial::operator-(const Polynomial& other) const {
    size_t maxSize = max(coff.size(), other.coff.size());
    vector<double> result(maxSize, 0);

    for (size_t i = 0; i < maxSize; ++i) {
        double a = (i < coff.size()) ? coff[i] : 0;
        double b = (i < other.coff.size()) ? other.coff[i] : 0;
        result[i] = a - b;
    }

    return Polynomial(result);
}

// Multiplication operator
Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> result(coff.size() + other.coff.size() - 1, 0);

    for (size_t i = 0; i < coff.size(); ++i) {
        for (size_t j = 0; j < other.coff.size(); ++j) {
            result[i + j] += coff[i] * other.coff[j];
        }
    }

    return Polynomial(result);
}

// Equality operator
bool Polynomial::operator==(const Polynomial& other) const {
    return coff == other.coff;
}

// Output operator (friend function)
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.coff.size() - 1; i >= 0; --i) {
        if (poly.coff[i] != 0) {
            if (i != poly.coff.size() - 1 && poly.coff[i] > 0) {
                out << "+";
            }
            out << poly.coff[i];
            if (i > 0) {
                out << "x";
                if (i > 1) {
                    out << "^" << i;
                }
            }
        }
    }
    return out;
}

// Return the degree of the polynomial
int Polynomial::degree() const {
    return coff.size() - 1;
}

// Evaluate the polynomial at x
double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = coff.size() - 1; i >= 0; --i) {
        result = result * x + coff[i];
    }
    return result;
}

// Composition of two polynomials
Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result;
    Polynomial temp({1});

    for (size_t i = 0; i < coff.size(); ++i) {
        Polynomial term = temp * Polynomial({coff[i]});
        result = result + term;
        temp = temp * q;
    }

    return result;
}

// Derivative of the polynomial
Polynomial Polynomial::derivative() const {
    vector<double> derivCoeffs;
    for (int i = 1; i < coff.size(); ++i) {
        derivCoeffs.push_back(coff[i] * i);
    }
    return Polynomial(derivCoeffs);
}

// Indefinite integral of the polynomial
Polynomial Polynomial::integral() const {
    vector<double> integralCoeffs(coff.size() + 1, 0);
    for (int i = 0; i < coff.size(); ++i) {
        integralCoeffs[i + 1] = coff[i] / (i + 1);
    }
    return Polynomial(integralCoeffs);
}

// Definite integral from x1 to x2
double Polynomial::integral(double x1, double x2) const {
    Polynomial indefiniteIntegral = integral();
    return indefiniteIntegral.evaluate(x2) - indefiniteIntegral.evaluate(x1);
}

// Find the root using Newton's method
double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    Polynomial deriv = derivative();
    double x = guess;
    for (int i = 0; i < maxIter; ++i) {
        double fx = evaluate(x);
        double fpx = deriv.evaluate(x);
        if (abs(fx) < tolerance) {
            return x;
        }
        x -= fx / fpx;
    }
    return x;
}

// Set the coefficients of the polynomial
void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coff = coefficients;
}

// Get the coefficient of a specific degree
double Polynomial::getCoefficients(int degree) const {
    return (degree < coff.size()) ? coff[degree] : 0;
}
