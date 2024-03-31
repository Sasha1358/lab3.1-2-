#include <iostream>
#include "Man.h"
#include "Student.h"
#include <Windows.h>

void displayMenu() {
    std::cout << "����:" << std::endl;
    std::cout << "1. ������ ��� ��� ��������" << std::endl;
    std::cout << "2. �������� �� ��������" << std::endl;
    std::cout << "3. �������� ���������� ��� ��������" << std::endl;
    std::cout << "0. �����" << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student student;

    int choice;
    do {
        displayMenu();
        std::cout << "������� �����: ";
        if (!(std::cin >> choice)) {
            std::cerr << "�������: ������������ ���. ���������� ��������." << std::endl;
            return 1;
        }

        switch (choice) {
        case 1: {
            std::cout << "������ ��� ��� ��������:" << std::endl;
            if (!(std::cin >> student)) {
                std::cerr << "�������: ������� ������ �������� �����. ���������� ��������." << std::endl;
                return 1;
            }
            break;
        }
        case 2: {
            student.increaseYearOfStudy();
            std::cout << "г� �������� �������� �������� �� ����." << std::endl;
            break;
        }
        case 3: {
            std::cout << "���������� ��� ��������:" << std::endl;
            std::cout << student << std::endl;
            break;
        }
        case 0: {
            std::cout << "����� �� ������������! �� ���������." << std::endl;
            break;
        }
        default: {
            std::cerr << "�������: ������������ ����. ��������� �� ���." << std::endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
