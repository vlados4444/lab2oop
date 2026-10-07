/**
 * @file main.cpp
 * @brief Тестирование класса Flight.
 */

#include "Flight.h"
#include <iostream>

int main()
{
    std::cout << "===== 1. СОЗДАНИЕ ОБЪЕКТОВ =====\n";
    Flight f1;
    Flight f2("SU1234", "Moscow", "Sochi", "15.06.2026 10:30", 180, 145);
    Flight f3 = f2;
    std::cout << "Objects created: " << Flight::getObjectCount() << "\n\n";

    std::cout << "===== 2. НАЧАЛЬНОЕ СОСТОЯНИЕ =====\n";
    f1.print();
    f2.print();
    f3.print();

    std::cout << "\n===== 3. КОРРЕКТНЫЕ ОПЕРАЦИИ =====\n";
    std::cout << "f2.sellTicket(5): " << f2.sellTicket(5) << "\n";
    f2.print();

    std::cout << "f2.setStatus(Boarding): " << f2.setStatus(FlightStatus::Boarding) << "\n";
    f2.print();

    std::cout << "\n===== 4. НЕКОРРЕКТНЫЕ ОПЕРАЦИИ =====\n";
    std::cout << "f2.sellTicket(1000): " << f2.sellTicket(1000) << "\n";
    std::cout << "f2.returnTicket(500): " << f2.returnTicket(500) << "\n";
    std::cout << "f2.sellTicket(-3): " << f2.sellTicket(-3) << "\n";

    std::cout << "\n===== 5. СОСТОЯНИЕ ПОСЛЕ НЕКОРРЕКТНЫХ ОПЕРАЦИЙ =====\n";
    f2.print();

    std::cout << "\n===== 6. ПРОВЕРКА НЕЗАВИСИМОСТИ ОБЪЕКТОВ =====\n";
    f2.sellTicket(10);
    f2.cancel();

    std::cout << "\nf2 (изменён):\n";
    f2.print();

    std::cout << "\nf1 (не должен измениться):\n";
    f1.print();

    std::cout << "\nf3 (не должен измениться):\n";
    f3.print();

    std::cout << "\n===== ЗАВЕРШЕНИЕ =====\n";
    std::cout << "Objects at end: " << Flight::getObjectCount() << "\n";

    return 0;
}