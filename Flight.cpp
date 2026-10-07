/**
 * @file Flight.cpp
 * @brief Реализация класса Flight.
 */

#include "Flight.h"
#include <stdexcept>

int Flight::objectCount = 0;

static std::string statusToString(FlightStatus s)
{
    switch (s)
    {
        case FlightStatus::Scheduled: return "Scheduled";
        case FlightStatus::Boarding:  return "Boarding";
        case FlightStatus::InFlight:  return "InFlight";
        case FlightStatus::Completed: return "Completed";
        case FlightStatus::Cancelled: return "Cancelled";
    }
    return "Unknown";
}

bool Flight::isValid() const
{
    if (flightNumber.empty())                  return false;
    if (origin.empty() || destination.empty()) return false;
    if (origin == destination)                 return false;
    if (totalSeats <= 0)                       return false;
    if (occupiedSeats < 0)                     return false;
    if (occupiedSeats > totalSeats)            return false;
    return true;
}

Flight::Flight()
    : flightNumber("UNKNOWN"),
      origin("Unknown"),
      destination("Unknown"),
      departureTime("00.00.0000 00:00"),
      totalSeats(1),
      occupiedSeats(0),
      status(FlightStatus::Scheduled)
{
    ++objectCount;
}

Flight::Flight(const std::string& number,
               const std::string& from,
               const std::string& to,
               const std::string& time,
               int seats,
               int occupied)
    : flightNumber(number),
      origin(from),
      destination(to),
      departureTime(time),
      totalSeats(seats),
      occupiedSeats(occupied),
      status(FlightStatus::Scheduled)
{
    if (!isValid())
        throw std::invalid_argument("Flight: нарушены инварианты");
    ++objectCount;
}

Flight::Flight(const Flight& other)
    : flightNumber(other.flightNumber),
      origin(other.origin),
      destination(other.destination),
      departureTime(other.departureTime),
      totalSeats(other.totalSeats),
      occupiedSeats(other.occupiedSeats),
      status(other.status)
{
    ++objectCount;
}

Flight::~Flight()
{
    --objectCount;
    std::cout << "[~Flight] " << flightNumber
              << " destroyed. Objects left: " << objectCount << "\n";
}

std::string Flight::getFlightNumber() const { return flightNumber; }
std::string Flight::getOrigin() const { return origin; }
std::string Flight::getDestination() const { return destination; }
std::string Flight::getDepartureTime() const { return departureTime; }
int Flight::getTotalSeats() const { return totalSeats; }
int Flight::getOccupiedSeats() const { return occupiedSeats; }
int Flight::getFreeSeats() const { return totalSeats - occupiedSeats; }
FlightStatus Flight::getStatus() const { return status; }
double Flight::getLoadFactor() const { return 0.0; }
int Flight::getObjectCount() { return objectCount; }
bool Flight::sellTicket(int) { return false; }
bool Flight::returnTicket(int) { return false; }
bool Flight::setStatus(FlightStatus) { return false; }
void Flight::cancel() {}
void Flight::print() const {}