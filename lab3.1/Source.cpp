#include <iostream>
#include "Man.h"
#include "Student.h"
#include <Windows.h>

void displayMenu() {
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Ввести дані про студента" << std::endl;
    std::cout << "2. Збільшити рік навчання" << std::endl;
    std::cout << "3. Показати інформацію про студента" << std::endl;
    std::cout << "0. Вихід" << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student student;

    int choice;
    do {
        displayMenu();
        std::cout << "Виберіть опцію: ";
        if (!(std::cin >> choice)) {
            std::cerr << "Помилка: Неправильний ввід. Завершення програми." << std::endl;
            return 1;
        }

        switch (choice) {
        case 1: {
            std::cout << "Введіть дані про студента:" << std::endl;
            if (!(std::cin >> student)) {
                std::cerr << "Помилка: Невірний формат введених даних. Завершення програми." << std::endl;
                return 1;
            }
            break;
        }
        case 2: {
            student.increaseYearOfStudy();
            std::cout << "Рік навчання студента збільшено на один." << std::endl;
            break;
        }
        case 3: {
            std::cout << "Інформація про студента:" << std::endl;
            std::cout << student << std::endl;
            break;
        }
        case 0: {
            std::cout << "Дякую за користування! До побачення." << std::endl;
            break;
        }
        default: {
            std::cerr << "Помилка: Неправильний вибір. Спробуйте ще раз." << std::endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
