#include "Fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction(): denominator(1), numerator(0) {

}

Fraction::Fraction(int numerator, int denominator) {
 if(denominator == 0) {
    return;
 }
 else {
    this->denominator = denominator;
    this->numerator = numerator;
 }

 this->denominator = denominator;
 this-> numerator = numerator;

}

void Fraction::print() const {
    cout<< this->numerator << "/" << this->denominator << endl;
}

/**
 * @brief Adds the given fraction to the current fraction.
 *
 * This function adds the given fraction to the current fraction and stores
 * the result in the current fraction object.
 *
 * @param f2 The fraction to be added to the current fraction.
 *
 * Example Usage:
 * @code
 * Fraction f1(10, 2); // Represents 10/2
 * Fraction f2(15, 4); // Represents 15/4
 * f1.add(f2); // Adds f2 to f1, result stored in f1 (f1 = f1 + f2)
 * @endcode
 */
void Fraction::add(Fraction f2) {
    /**< Calculate the LCM (Least Common Multiple) */
    int lcm = this->denominator * f2.denominator;

    /**< Calculate the X value */
    int x = lcm / this->denominator;
    /**< Calculate the Y value */
    int y = lcm / f2.denominator;

    /**< Calculate the numerator of the sum of f1 + f2 */
    int num = (x * this->numerator) + (y * f2.numerator);

    /**< Store the result in the current fraction */
    this->numerator = num;
    this->denominator = lcm;

    simplify();
}

/**
 * @brief Simplifies the fraction to its simplest form.
 *
 * This function simplifies the fraction by finding the greatest common divisor (GCD)
 * of the numerator and denominator and then divides both numerator and denominator
 * by the GCD, resulting in the simplest form of the fraction.
 *
 * Example Usage:
 * @code
 * Fraction f(20, 40); // Represents 20/40
 * f.simplify(); // Simplifies the fraction to 1/2
 * @endcode
 */
void Fraction::simplify(void) {
    int gcd = 1; // Initialize the greatest common divisor to 1
    int j = min(this->numerator, this->denominator);

    // Iterate from 1 to the minimum of numerator and denominator to find GCD
    for(int i = 1; i <= j; i++) {
        // Check if both numerator and denominator are divisible by i
        if((this->denominator % i == 0) && (this->numerator % i == 0)) {
            gcd = i; // Update GCD if both are divisible by i
        }
    }

    // Simplify the numerator and denominator after calculating the GCD
    this->denominator /= gcd;
    this->numerator /= gcd;
}


Fraction::~Fraction() {

}
