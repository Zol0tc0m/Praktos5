#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>

using namespace std;

std::string reverse(const std::string& word) {
    return std::string(word.rbegin(), word.rend());
}

std::string removeVowels(const std::string& word) {
    std::string result;
    std::string vowels = "ауоиэыяюеёАУОИЭЫЯЮЕЁ";
    for (char с: word) {
        if (vowels.find(с) == std::string::npos) {
            result += с;
        }
    }
    return result;
}

std::string removeConsonants(const std::string& word) {
    std::string result;
    std::string consonants = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    for (char с : word) {
        if (consonants.find(с) == std::string::npos) {
            result += с;
        }
    }
    return result;
}

std::string shuffle(const std::string& word) {
    std::string result = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(result.begin(), result.end(), g);
    return result;
}

int main() {
    SetConsoleCP(1251);
    setlocale(0, "");
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    int choice;
    do {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Вывести слово задом наперед.\n";
        std::cout << "2. Вывести слово без гласных.\n";
        std::cout << "3. Вывести слово без согласных.\n";
        std::cout << "4. Рандомно раскидать буквы заданного слова.\n";
        std::cout << "5. Выход.\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Результат: " << reverse(word) << "\n";
            break;
        case 2:
            std::cout << "Результат: " << removeVowels(word) << "\n";
            break;
        case 3:
            std::cout << "Результат: " << removeConsonants(word) << "\n";
            break;
        case 4:
            std::cout << "Результат: " << shuffle(word) << "\n";
            break;
        case 5:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}