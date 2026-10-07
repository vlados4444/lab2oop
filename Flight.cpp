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

bool Flight::sellTicket(int count)
{
    if (count <= 0) return false;
    if (status == FlightStatus::Cancelled ||
        status == FlightStatus::Completed) return false;
    if (occupiedSeats + count > totalSeats) return false;
    occupiedSeats += count;
    return true;
}

bool Flight::returnTicket(int count)
{
    if (count <= 0) return false;
    if (occupiedSeats - count < 0) return false;
    occupiedSeats -= count;
    return true;
}

bool Flight::setStatus(FlightStatus newStatus)
{
    if (status == FlightStatus::Cancelled &&
        newStatus != FlightStatus::Cancelled) return false;
    status = newStatus;
    return true;
}

void Flight::cancel()
{
    status = FlightStatus::Cancelled;
    occupiedSeats = 0;
}

void Flight::print() const
{
    std::cout << "----- Flight " << flightNumber << " -----\n"
              << "Route:       " << origin << " -> " << destination << "\n"
              << "Departure:   " << departureTime << "\n"
              << "Seats:       " << occupiedSeats << " / " << totalSeats
              << "  (free: " << getFreeSeats() << ")\n"
              << "Load factor: " << getLoadFactor() << " %\n"
              << "Status:      " << statusToString(status) << "\n";
}

std::string Flight::getFlightNumber() const { return flightNumber; }
std::string Flight::getOrigin() const       { return origin; }
std::string Flight::getDestination() const  { return destination; }
std::string Flight::getDepartureTime() const{ return departureTime; }
int Flight::getTotalSeats() const           { return totalSeats; }
int Flight::getOccupiedSeats() const        { return occupiedSeats; }
int Flight::getFreeSeats() const            { return totalSeats - occupiedSeats; }
FlightStatus Flight::getStatus() const      { return status; }

double Flight::getLoadFactor() const
{
    if (totalSeats == 0) return 0.0;
    return 100.0 * occupiedSeats / totalSeats;
}

int Flight::getObjectCount() { return objectCount; }