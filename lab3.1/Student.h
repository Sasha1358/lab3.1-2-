//Student.h
#pragma once
#include "Man.h"
#include <iostream>

class Student : public Man
{
private:
    int yearOfStudy;

public:
    Student();
    Student(const Man& person, int yearOfStudy); 
    Student(const Student& other); 
    ~Student();

    int getYearOfStudy() const { return yearOfStudy; }
    void setYearOfStudy(int year) { this->yearOfStudy = year; }

    void increaseYearOfStudy();

    operator std::string() const;
    friend std::ostream& operator<<(std::ostream& out, const Student& r);
    friend std::istream& operator>>(std::istream& in, Student& r);
};