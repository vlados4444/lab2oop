/**
 * @file Flight.h
 * @brief Класс Flight — авиарейс.
 */

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>

/**
 * @brief Статус авиарейса.
 */
enum class FlightStatus
{
    Scheduled,   ///< Запланирован
    Boarding,    ///< Идёт посадка
    InFlight,    ///< В воздухе
    Completed,   ///< Выполнен
    Cancelled    ///< Отменён
};

/**
 * @brief Класс, описывающий авиарейс.
 *
 * Инварианты:
 *  - 0 <= occupiedSeats <= totalSeats
 *  - totalSeats > 0
 *  - flightNumber не пустой
 *  - origin != destination
 */
class Flight
{
private:
    std::string flightNumber;   ///< Номер рейса.
    std::string origin;         ///< Пункт вылета.
    std::string destination;    ///< Пункт назначения.
    std::string departureTime;  ///< Время вылета.
    int totalSeats;             ///< Общее число мест.
    int occupiedSeats;          ///< Занято мест.
    FlightStatus status;        ///< Текущий статус.

    static int objectCount;     ///< Счётчик существующих объектов.

    /// @brief Проверяет корректность состояния.
    bool isValid() const;

public:
    Flight();                                                    ///< По умолчанию.
    Flight(const std::string& number,
           const std::string& from,
           const std::string& to,
           const std::string& time,
           int seats,
           int occupied = 0);                                    ///< Параметризованный.
    Flight(const Flight& other);                                 ///< Копирования.
    ~Flight();                                                   ///< Деструктор.

    // Методы чтения
    std::string getFlightNumber() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    int getTotalSeats() const;
    int getOccupiedSeats() const;
    int getFreeSeats() const;
    FlightStatus getStatus() const;
    double getLoadFactor() const;
    static int getObjectCount();

    // Методы изменения
    bool sellTicket(int count = 1);
    bool returnTicket(int count = 1);
    bool setStatus(FlightStatus newStatus);
    void cancel();

    // Вывод
    void print() const;
};

#endif // FLIGHT_H