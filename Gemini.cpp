Polynomial() {
    coff = {0.0}; // Initialize with a single zero coefficient
}

Polynomial(const vector<double>& coefficients) : coff(coefficients) {}

Polynomial(const Polynomial& other) : coff(other.coff) {}

~Polynomial() {}

Polynomial Polynomial::operator=(const Polynomial& other) {
    coff = other.coff;
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxDegree = max(degree(), other.degree());
    vector<double> result(maxDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        result[i] += coff[i];
    }

    for (int i = 0; i <= other.degree(); ++i) {
        result[i] += other.coff[i];
    }

    return Polynomial(result);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    return *this + (-other);
}

Polynomial Polynomial::operator*(const Polynomial& other)   
 const {
    int newDegree = degree() + other.degree();
    vector<double> result(newDegree + 1, 0.0);

    for (int i = 0; i <= degree(); ++i) {
        for (int j = 0; j <= other.degree(); ++j) {
            result[i + j] += coff[i] * other.coff[j];
        }
    }

    return Polynomial(result);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coff == other.coff;
}
Use code with caution.

Output Operator
C++
ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.degree(); i >= 0; --i) {
        if (poly.coff[i] != 0.0) {
            out << poly.coff[i];
            if (i > 1) {
                out << "x^" << i;
            } else if (i == 1) {
                out << "x";
            }
            if (i > 0 && poly.coff[i - 1] > 0) {
                out << " + ";
            }
        }
    }
    return out;
}

int Polynomial::degree() const {
    for (int i = coff.size() - 1; i >= 0; --i) {
        if (coff[i] != 0.0) {
            return i;
        }
    }
    return 0; // For the zero polynomial
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree(); ++i) {
        result += coff[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::compose(const Polynomial& q) const {
int n = degree(), m = q.degree();
    vector<double> result(n * m + 1, 0.0);

    for (int i = 0; i <= n; ++i) {
        double temp = coff[i];
        for (int j = m - 1; j >= 0; --j) {
            result[i * m + j] += temp * q.coff[j];
            temp = result[i * m + j];
        }
    }

    return Polynomial(result);}

Polynomial Polynomial::derivative() const {
if (degree() == 0) {
        return Polynomial(); // Derivative of a constant is zero
    }

    int newDegree = degree() - 1;
    vector<double> result(newDegree + 1, 0.0);

    for (int i = 1; i <= degree(); ++i) {
        result[i - 1] = coff[i] * i;
    }

    return Polynomial(result);}

Polynomial Polynomial::integral() const {
 int newDegree = degree() + 1;
    vector<double> result(newDegree + 1, 0.0);

    result[0] = 0.0; // Constant term of integration
    for (int i = 1; i <= newDegree; ++i) {
        result[i] = coff[i - 1] / i;
    }

    return Polynomial(result);}

double Polynomial::integral(double x1, double x2) const {
 Polynomial integrated = integral();
    return integrated.evaluate(x2) - integrated.evaluate(x1);}

void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coff = coefficients;
}

double Polynomial::getCoefficients(int degree) const {
    if (degree >= 0 && degree < coff.size()) {
        return coff[degree];
    }
    return 0.0;
}
