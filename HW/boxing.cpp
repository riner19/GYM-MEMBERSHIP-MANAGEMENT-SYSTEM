#include "boxing.hpp"
#include <iostream>

BoxingMembership::BoxingMembership(const std::string& _startDate, const std::string& _endDate)
    : Membership(_startDate, _endDate) {}

void BoxingMembership::displayDetails() const {
    std::cout << "Membership Type: Boxing\n";
    std::cout << "Start Date: " << startDate << "\n";
    std::cout << "End Date: " << endDate << "\n";
}


std::string BoxingMembership::getStartDate() const {
    return startDate; // Assuming startDate is a member variable of the Membership class
}

std::string BoxingMembership::getEndDate() const {
    return endDate; // Assuming endDate is a member variable of the Membership class
}

std::string BoxingMembership::getType() const {
    return "BoxingMembership"; // Return type of membership
}
