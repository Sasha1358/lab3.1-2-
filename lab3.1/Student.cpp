//Student.cpp
#include "Student.h"

Student::Student() : yearOfStudy(0) {}
Student::Student(const Man& person, int yearOfStudy)
    : Man(person), yearOfStudy(yearOfStudy) {}
Student::Student(const Student& other)
    : Man(other), yearOfStudy(other.yearOfStudy) {}
Student::~Student() {}

void Student::increaseYearOfStudy() {
    yearOfStudy++;
}

Student::operator std::string() const {
    return "�����: " + static_cast<std::string>(*this) + ", г� ��������: " + std::to_string(yearOfStudy);
}

std::ostream& operator<<(std::ostream& out, const Student& r) {
    out << "�����: " << static_cast<const Man&>(r) << ", г� ��������: " << r.yearOfStudy;
    return out;
}
istream& operator>>(istream& in, Student& r) {
    cout << "������ ��� �����:" << endl;
    if (!(in >> static_cast<Man&>(r))) {
        return in;
    }

    cout << "������ �� ��������: ";
    if (!(in >> r.yearOfStudy) || r.yearOfStudy < 0) {
        cerr << "�������: ������� ������ �������� ����� ��� ���� ��������." << endl;
        in.setstate(std::ios_base::failbit); // ������������ ���� ������� ��� ������ �����
        return in;
    }

    return in;
}