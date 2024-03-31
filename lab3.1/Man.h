//Man.h
#pragma once
#include <string>
using namespace std;

class Man
{
private:
    string name;
    int age;
    string gender;
    double weight;

public:
    Man();
    Man(const string& name, int age, const string& gender, double weight);
    Man(const Man& other);
    ~Man();

    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    double getWeight() const { return weight; }

    void setName(const string& name);
    void setAge(int age);
    void setGender(const string& gender);
    void setWeight(double weight);

    void changeName(const string& newName);
    void changeAge(int newAge);
    void changeWeight(double newWeight);

    operator string() const;
    friend ostream& operator<<(ostream& out, const Man& r);
    friend istream& operator>>(istream& in, Man& r);
};
