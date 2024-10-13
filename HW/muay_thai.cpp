#include "muay_thai.hpp"
#include <iostream>

MuayThaiMembership::MuayThaiMembership(const std::string& _startDate, const std::string& _endDate)
    : Membership(_startDate, _endDate) {}

void MuayThaiMembership::displayDetails() const {
    std::cout << "Membership Type: Muay Thai\n";
    std::cout << "Start Date: " << startDate << "\n";
    std::cout << "End Date: " << endDate << "\n";
}
std::string MuayThaiMembership::getStartDate() const {
    return startDate; // Assuming startDate is a member variable of the Membership class
}

std::string MuayThaiMembership::getEndDate() const {
    return endDate; // Assuming endDate is a member variable of the Membership class
}

std::string MuayThaiMembership::getType() const {
    return "MuayThaiMembership"; // Return type of membership
}
