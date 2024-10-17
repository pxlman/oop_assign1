#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Polynomial.h"

using namespace std;

// Default constructor
Polynomial::Polynomial() : coff(1, 0) {}

// Constructor with coefficients
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
    vector<double> result;
    size_t maxSize = max(coff.size(), other.coff.size());
    result.resize(maxSize, 0);

    for (size_t i = 0; i < maxSize; ++i) {
        if (i < coff.size()) result[i] += coff[i];
        if (i < other.coff.size()) result[i] += other.coff[i];
    }

    return Polynomial(result);
}

// Subtraction operator
Polynomial Polynomial::operator-(const Polynomial& other) const {
    vector<double> result;
    size_t maxSize = max(coff.size(), other.coff.size());
    result.resize(maxSize, 0);

    for (size_t i = 0; i < maxSize; ++i) {
        if (i < coff.size()) result[i] += coff[i];
        if (i < other.coff.size()) result[i] -= other.coff[i];
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

// Output operator
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (size_t i = 0; i < poly.coff.size(); ++i) {
        if (i > 0 && poly.coff[i] >= 0) out << "+";
        out << poly.coff[i];
        if (i > 0) out << "x^" << i;
        out << " ";
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
    for (size_t i = 0; i < coff.size(); ++i) {
        result += coff[i] * pow(x, i);
    }
    return result;
}

// Composition of polynomials
Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result;
    for (size_t i = 0; i < coff.size(); ++i) {
        Polynomial term({coff[i]});
        for (size_t j = 0; j < i; ++j) {
            term = term * q;
        }
        result = result + term;
    }
    return result;
}

// Derivative of the polynomial
Polynomial Polynomial::derivative() const {
    vector<double> result;
    for (size_t i = 1; i < coff.size(); ++i) {
        result.push_back(coff[i] * i);
    }
    return Polynomial(result);
}

// Return a polynomial integration
Polynomial Polynomial::integral() const {
    vector<double> result(coff.size() + 1, 0);
    for (size_t i = 0; i < coff.size(); ++i) {
        result[i + 1] = coff[i] / (i + 1);
    }
    return Polynomial(result);
}

// Integrate from x1 to x2
double Polynomial::integral(double x1, double x2) const {
    Polynomial integralPoly = integral();
    return integralPoly.evaluate(x2) - integralPoly.evaluate(x1);
}

// Get root using Newton's method
double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    Polynomial deriv = derivative();
    for (int i = 0; i < maxIter; ++i) {
        double value = evaluate(guess);
        double derivValue = deriv.evaluate(guess);
        if (abs(value) < tolerance) return guess;
        guess = guess - value / derivValue;
    }
    return guess;
}

// Set coefficients
void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coff = coefficients;
}

// Get coefficient of a specific degree
double Polynomial::getCoefficients(int degree) const {
    if (degree < coff.size()) {
        return coff[degree];
    }
    return 0;
}

// Method to read coefficients from the user
vector<double> readCoefficients() {
    vector<double> coefficients;
    double coeff;
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    for (int i = 0; i <= degree; ++i) {
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coeff;
        coefficients.push_back(coeff);
    }

    return coefficients;
}

int main() {
    vector<double> coff1 = readCoefficients();
    vector<double> coff2 = readCoefficients();

    Polynomial p1(coff1);
    Polynomial p2(coff2);

    Polynomial p3 = p1 + p2;
    Polynomial p4 = p1 - p2;
    Polynomial p5 = p1 * p2;

    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;
    cout << "Sum: " << p3 << endl;
    cout << "Difference: " << p4 << endl;
    cout << "Product: " << p5 << endl;
    cout << "Compose: " << p1.compose(p1) << endl;
    cout << "Degree of Polynomial 1: " << p1.degree() << endl;
    cout << "Evaluation of Polynomial 1 at x=2: " << p1.evaluate(2) << endl;
    cout << "Derivative of Polynomial 1: " << p1.derivative() << endl;
    cout << "Integral of Polynomial 1: " << p1.integral() << endl;
    cout << "Definite integral of Polynomial 1 from x=0 to x=1: " << p1.integral(0, 1) << endl;
    cout << "Root of Polynomial 1 near guess 1: " << p1.getRoot(1) << endl;

    return 0;
}
