#ifndef FRACTION_H
#define FRACTION_H


/**
 * @brief Represents a Fraction with a numerator and a denominator.
 *
 * The Fraction class provides functionality to work with fractions, including addition and simplification.
 *
 * Example Usage:
 * @code
 * Fraction f1(1, 2); // Represents the fraction 1/2
 * Fraction f2(3, 4); // Represents the fraction 3/4
 * f1.add(f2); // Adds f1 and f2, result stored in f1
 * f1.print(); // Outputs the simplified result of the addition, e.g., "5/4"
 * @endcode
 */
class Fraction
{
private:
    int numerator; /**< Numerator of the fraction. */
    int denominator; /**< Denominator of the fraction. */

    /**
     * @brief Simplifies the fraction to its simplest form.
     *
     * This private member function simplifies the fraction by finding the greatest common divisor (GCD)
     * of the numerator and denominator and then divides both numerator and denominator
     * by the GCD, resulting in the simplest form of the fraction.
     *
     * @return None.
     */
    void simplify(void);

public:
    /**
     * @brief Default constructor for Fraction class.
     *
     * Initializes the fraction with numerator 0 and denominator 1.
     */
    Fraction();

    /**
    * @brief Parameterized constructor for Fraction class.
    *
    * Initializes the fraction with the specified numerator and denominator.
    *
    * @param numerator The numerator of the fraction.
    * @param denominator The denominator of the fraction.
    */
    Fraction(int numerator, int denominator);

    /**
     * @brief Prints the simplified fraction to the console.
     *
     * Prints the fraction in its simplest form to the console output.
     *
     * @param None.
     *
     * @return None.
     */
    void print(void) const;

    /**
     * @brief Adds another fraction to this fraction.
     *
     * Adds the given fraction to this fraction and stores the result in this fraction.
     *
     * @param f2 The fraction to be added to this fraction.
     *
     * @return None.
     */
    void add(Fraction f2);

    /**
     * @brief Virtual destructor for Fraction class.
     *
     * Ensures correct destruction of derived classes objects if used polymorphically.
     */
    virtual ~Fraction();

protected:
    /**< Protected members, if any, can be added here. */
};


#endif /**< FRACTION_H */
