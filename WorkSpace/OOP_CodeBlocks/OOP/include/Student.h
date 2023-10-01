#ifndef STUDENT_H
#define STUDENT_H

#include <stdint.h>
#include <iostream>
#include <cstring>

class Student
{
private:
    uint32_t StudentAge;
    uint32_t StudentRollNumber;
    char *StudentName;

    static uint32_t TotalObjectNumer;
    uint32_t ObjectNumer;

public:
    Student();
    Student(char *StudentName);
    Student(uint32_t StudentAge, uint32_t StudentRollNumber, char *StudentName);
    Student(Student &Student);

    void setStudentName(char *StudentName);
    void setStudentAge(uint32_t StudentAge);
    void setStudentRollNumber(uint32_t StudentRollNumber);

    uint32_t getStudentAge() const;
    uint32_t  getStudentRollNumber() const;

    void displayStudentName(void) const;
};

#endif /**< STUDENT_H */
