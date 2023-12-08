#include <iostream>
#include <locale> 

// Ввод чисел
void dva(int& x, int& y) {
    std::cout << "Введите два числа: ";
    std::cin >> x >> y;

    // Проверка ошибок
    if (std::cin.fail()) 
    {
        std::cout << "Ошибка! Введен некорректный символ." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        dva(x, y);
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    int x, y, z;
    int choice;

    do {
        // Вывод меню
        std::cout << "Меню выбора:" << std::endl;
        std::cout << "1. Сложение" << std::endl;
        std::cout << "2. Вычитание" << std::endl;
        std::cout << "3. Деление" << std::endl;
        std::cout << "4. Умножение" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите опцию: ";

        // Проверка ошибок
        if (std::cin.fail()) // если предыдущее извлечение было неудачным, эквивалентно if (!cin)
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // извлекаем и отбрасываем максимальное количество символов из входного потока до разделителя '\n' включительно
        }



        // Ввод выбора
        std::cin >> choice;

        // Обработка выбора
        switch (choice) {
        case 1:
            dva(x, y);
            z = x + y;
            std::cout << "Результат: " << z << std::endl;
            break;
        case 2:
            dva(x, y);
            z = x - y;
            std::cout << "Результат: " << z << std::endl;
            break;
        case 3:
            dva(x, y);
            // Проверка деления на ноль
            if (y != 0) {
                z = x / y;
                std::cout << "Результат: " << z << std::endl;
            }
            else {
                std::cout << "Ошибка: деление на ноль!" << std::endl;
            }
            break;
        case 4:
            dva(x, y);
            z = x * y;
            std::cout << "Результат: " << z << std::endl;
            break;
        case 5:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 5); // Выход из цикла, если выбрана опция "Выход"

    return 0;
}
