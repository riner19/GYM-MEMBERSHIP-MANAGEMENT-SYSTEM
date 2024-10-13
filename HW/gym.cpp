#include "gym.hpp"
#include <iostream>

GymMembership::GymMembership(const std::string& _startDate, const std::string& _endDate)
    : Membership(_startDate, _endDate) {}

void GymMembership::displayDetails() const {
    std::cout << "Membership Type: Gym\n";
    std::cout << "Start Date: " << startDate << "\n";
    std::cout << "End Date: " << endDate << "\n";
}

std::string GymMembership::getStartDate() const {
    return startDate; // Assuming startDate is a member variable of the Membership class
}

std::string GymMembership::getEndDate() const {
    return endDate; // Assuming endDate is a member variable of the Membership class
}

std::string GymMembership::getType() const {
    return "GymMembership"; // Return type for Gym membership
}
