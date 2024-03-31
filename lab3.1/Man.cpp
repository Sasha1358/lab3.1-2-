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
        cerr << "�������: ��'� �� ���� ���� �������!" << endl;
}
void Man::setAge(int age) {
    if (age >= 0)
        this->age = age;
    else
        cerr << "�������: ³� �� ���� ���� ��'�����!" << endl;
}
void Man::setGender(const string& gender) {
    if (gender == "������" || gender == "Ƴ���")
        this->gender = gender;
    else
        cerr << "�������: ����� �� ���� '������' ��� 'Ƴ���'!" << endl;
}
void Man::setWeight(double weight) {
    if (weight >= 0.0)
        this->weight = weight;
    else
        cerr << "�������: ���� �� ���� ���� ��'�����!" << endl;
}

Man::operator string() const {
    return "��'�: " + name + ", ³�: " + to_string(age) + ", �����: " + gender + ", ����: " + to_string(weight);
}

ostream& operator<<(ostream& out, const Man& r) {
    out << "��'�: " << r.name << ", ³�: " << r.age << ", �����: " << r.gender << ", ����: " << r.weight;
    return out;
}
istream& operator>>(istream& in, Man& r) {
    cout << "������ ��'�: ";
    in >> r.name;
    cout << "������ ��: ";
    if (!(in >> r.age) || r.age < 0) {
        cerr << "�������: ������� ������ �������� ����� ��� ���." << endl;
        in.setstate(std::ios_base::failbit); // ������������ ���� ������� ��� ������ �����
        return in;
    }
    cout << "������ �����: ";
    in >> r.gender;
    cout << "������ ����: ";
    if (!(in >> r.weight) || r.weight < 0.0) {
        cerr << "�������: ������� ������ �������� ����� ��� ����." << endl;
        in.setstate(std::ios_base::failbit); // ������������ ���� ������� ��� ������ �����
        return in;
    }
    return in;
}