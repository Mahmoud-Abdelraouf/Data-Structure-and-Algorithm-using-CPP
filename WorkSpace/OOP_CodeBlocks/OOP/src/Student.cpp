#include "student.h"

uint32_t Student::TotalObjectNumer = 0;

/******************************< Constructors ******************************/
Student::Student(): StudentAge(0), StudentRollNumber(0), StudentName(NULL), ObjectNumer(0) {
    TotalObjectNumer++;
    ObjectNumer = TotalObjectNumer;
}

Student::Student(char *StudentName): StudentAge(0), StudentRollNumber(0), StudentName(StudentName) {
    TotalObjectNumer++;
    ObjectNumer = TotalObjectNumer;
}
/******************************< Copy Constructors ******************************/
Student::Student(Student &Student) {
    this->StudentAge = Student.StudentAge;
    this->StudentRollNumber = Student.StudentRollNumber;

    this->StudentName = new char[strlen(Student.StudentName)+1];
    strcpy(this->StudentName, Student.StudentName);

    TotalObjectNumer++;
    ObjectNumer = TotalObjectNumer;
}
/******************************< Setters and getters Fucntions ******************************/
void Student::setStudentName(char *StudentName) {
    this->StudentName = StudentName;
}
void Student::setStudentAge(uint32_t StudentAge) {
    this->StudentAge = StudentAge;
}

void Student::setStudentRollNumber(uint32_t StudentRollNumber) {
    this->StudentRollNumber = StudentRollNumber;
}

uint32_t Student::getStudentAge() const  {
    return this->StudentAge;
}

uint32_t Student::getStudentRollNumber() const  {
    return this->StudentRollNumber;
}

/**
 * @brief used to display the name of the Student
 *
 * @param void
 * @retval void
*/
void Student::displayStudentName(void) const {
    std::cout << "From Object No." << this->ObjectNumer << ", The Name is: " << this->StudentName << std::endl;
}
