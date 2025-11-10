 #include <iostream>
 #include <numeric> // for std::gcd (C++17)
 using namespace std;
 class Rational {
 private:
    int numerator;
    int denominator;
    // Helper function to simplify fraction
    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0) { // Keep denominator positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }
 public:
    // Constructor
    Rational(int n = 0, int d = 1) {
        if (d == 0) {
            cout << "Denominator cannot be zero!" << endl;
            exit(1);
        }
        numerator = n;
        denominator = d;
        simplify();
    }
    // Arithmetic Operators
    Rational operator+(const Rational& r) const {
        return Rational(numerator * r.denominator + r.numerator * denominator,
                        denominator * r.denominator);
    }
    Rational operator-(const Rational& r) const {
        return Rational(numerator * r.denominator - r.numerator * denominator,
                        denominator * r.denominator);
    }
    Rational operator*(const Rational& r) const {
        return Rational(numerator * r.numerator, denominator * r.denominator);
    }
    Rational operator/(const Rational& r) const {
        return Rational(numerator * r.denominator, denominator * r.numerator);
    }
    // Comparison Operators
    bool operator==(const Rational& r) const {
        return numerator == r.numerator && denominator == r.denominator;
    }
    bool operator!=(const Rational& r) const {
        return !(*this == r);
    }
    bool operator<(const Rational& r) const {
        return numerator * r.denominator < r.numerator * denominator;
    }
    bool operator>(const Rational& r) const {
        return r < *this;
    }
    bool operator<=(const Rational& r) const {
        return !(*this > r);
    }
    bool operator>=(const Rational& r) const {
        return !(*this < r);
    }
    // Display
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
 };
 int main() {
    Rational r1(2, 3);
    Rational r2(4, 5);
    cout << "r1 + r2 = "; (r1 + r2).display();
    cout << "r1 - r2 = "; (r1 - r2).display();
    cout << "r1 * r2 = "; (r1 * r2).display();
    cout << "r1 / r2 = "; (r1 / r2).display();
    cout << "Comparison Results:" << endl;
    cout << "r1 == r2 : " << (r1 == r2) << endl;
    cout << "r1 != r2 : " << (r1 != r2) << endl;
    cout << "r1 < r2  : " << (r1 < r2) << endl;
    cout << "r1 > r2  : " << (r1 > r2) << endl;
    cout << "r1 <= r2 : " << (r1 <= r2) << endl;
    cout << "r1 >= r2 : " << (r1 >= r2) << endl;
    return 0;
 }

