#ifndef GYM_HPP
#define GYM_HPP

#include "membership.hpp"

class GymMembership : public Membership {
private:
    const double studentPrice = 12500;
    const double adultPrice = 15000;

public:
    GymMembership(const std::string& _startDate, const std::string& _endDate);
    void displayDetails() const override;
    std::string getStartDate() const override; // Define getStartDate function
    std::string getEndDate() const override; 
    std::string getType() const override; 
};

#endif // GYM_HPP
