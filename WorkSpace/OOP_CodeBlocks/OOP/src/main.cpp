#include <iostream>
#include <stdint.h>

#include "student.h"
#include "Fraction.h"

using namespace std;

int main() {
    char Arr[] {"Mahmoud"};
    /**< Create an object from Student Class */
    Student S1(Arr);
    /**< Default Copy Constructor */
    Student S2(S1);
    /**< Display the Name of the object S1 */
    S1.displayStudentName();
    S2.displayStudentName();
    /**< Change the (o -> g) in @Arr before make the Deep Copy the change affect in both S1, S2 but after override to the Default Copy
     * Constructor and support the Deep Copy the change not reflected to the S2.
     */
    Arr[3] = 'g';
    /**< display the Name of object 2 */
    S2.displayStudentName(); /**< The expected output after the deep copy -> "Mahmoud", with Sallow Copy -> "Mahmogd" */
    /**< display the Name of object 1 */
    S1.displayStudentName(); /**< The expected output after the deep copy -> "Mahmogd", with Sallow Copy -> "Mahmogd" there are no visible change */ 

    
    return 0;
}
