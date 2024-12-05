#include <iostream>
#include "..//Solver/CircularLinkedList.h"

using namespace mynamespace;

int main()
{
    std::setlocale(NULL, "ru_RU.UTF-8");

    mynamespace::CircularLinkedList<int> list = { 1, 2, 3, 4 };

    std::cout << "Исходный список: " << list << std::endl;

    std::cout << "Введите числа для добавления (закончите ввод нечисловым символом): ";
    std::cin >> list;

    std::cout << "Список после добавления: " << list << std::endl;

    std::cout << "Введите число для удаления: ";
    int valueToRemove;
    std::cin >> valueToRemove;
    list.remove(valueToRemove);
    std::cout << "Список после удаления: " << list << std::endl;

    std::cout << "Введите число для вставки: ";
    int valueToInsert;
    std::cin >> valueToInsert;
    std::cout << "Введите число после которого вставлять: ";
    int valueToInsertAfter;
    std::cin >> valueToInsertAfter;
    list.insertAfter(valueToInsertAfter, valueToInsert);
    std::cout << "Список после вставки: " << list << std::endl;

    std::cout << "Введите число, после которого удалить: ";
    int valueToRemoveAfter;
    std::cin >> valueToRemoveAfter;
    list.removeAfter(valueToRemoveAfter);
    std::cout << "Список после удаления после: " << list << std::endl;

    std::cout << "Введите число для поиска: ";
    int valueToFind;
    std::cin >> valueToFind;
    if (list.find(valueToFind)) {
        std::cout << "Число найдено в списке." << std::endl;
    }
    else {
        std::cout << "Число не найдено в списке." << std::endl;
    }

    return 0;
}