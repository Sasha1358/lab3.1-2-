//Man.cpp
#include "Man.h"
#include <iostream>
using namespace std;

Man::Man() : age(0), weight(0.0) {}
Man::Man(const string& name, int age, const string& gender, double weight)
    : name(name), age(age), gender(gender), weight(weight) {}
Man::Man(const Man& other)
    : name(other.name), age(other.age), gender(other.gender), weight(other.weight) {}
Man::~Man() {}

void Man::changeName(const string& newName) {
    setName(newName);
}
void Man::changeAge(int newAge) {
    setAge(newAge);
}
void Man::changeWeight(double newWeight) {
    setWeight(newWeight);
}

void Man::setName(const string& name) {
    if (!name.empty())
        this->name = name;
    else
        cerr << "Помилка: Ім'я не може бути порожнім!" << endl;
}
void Man::setAge(int age) {
    if (age >= 0)
        this->age = age;
    else
        cerr << "Помилка: Вік не може бути від'ємним!" << endl;
}
void Man::setGender(const string& gender) {
    if (gender == "Чоловік" || gender == "Жінка")
        this->gender = gender;
    else
        cerr << "Помилка: Стать має бути 'Чоловік' або 'Жінка'!" << endl;
}
void Man::setWeight(double weight) {
    if (weight >= 0.0)
        this->weight = weight;
    else
        cerr << "Помилка: Вага не може бути від'ємною!" << endl;
}

Man::operator string() const {
    return "Ім'я: " + name + ", Вік: " + to_string(age) + ", Стать: " + gender + ", Вага: " + to_string(weight);
}

ostream& operator<<(ostream& out, const Man& r) {
    out << "Ім'я: " << r.name << ", Вік: " << r.age << ", Стать: " << r.gender << ", Вага: " << r.weight;
    return out;
}
istream& operator>>(istream& in, Man& r) {
    cout << "Введіть ім'я: ";
    in >> r.name;
    cout << "Введіть вік: ";
    if (!(in >> r.age) || r.age < 0) {
        cerr << "Помилка: Невірний формат введених даних для віку." << endl;
        in.setstate(std::ios_base::failbit); // Встановлюємо стан помилки для потоку вводу
        return in;
    }
    cout << "Введіть стать: ";
    in >> r.gender;
    cout << "Введіть вагу: ";
    if (!(in >> r.weight) || r.weight < 0.0) {
        cerr << "Помилка: Невірний формат введених даних для ваги." << endl;
        in.setstate(std::ios_base::failbit); // Встановлюємо стан помилки для потоку вводу
        return in;
    }
    return in;
}