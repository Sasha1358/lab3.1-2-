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
    return "Особа: " + static_cast<std::string>(*this) + ", Рік навчання: " + std::to_string(yearOfStudy);
}

std::ostream& operator<<(std::ostream& out, const Student& r) {
    out << "Особа: " << static_cast<const Man&>(r) << ", Рік навчання: " << r.yearOfStudy;
    return out;
}
istream& operator>>(istream& in, Student& r) {
    cout << "Введіть дані особи:" << endl;
    if (!(in >> static_cast<Man&>(r))) {
        return in;
    }

    cout << "Введіть рік навчання: ";
    if (!(in >> r.yearOfStudy) || r.yearOfStudy < 0) {
        cerr << "Помилка: Невірний формат введених даних для року навчання." << endl;
        in.setstate(std::ios_base::failbit); // Встановлюємо стан помилки для потоку вводу
        return in;
    }

    return in;
}