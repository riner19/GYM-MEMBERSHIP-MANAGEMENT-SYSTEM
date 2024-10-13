#ifndef BOXING_HPP
#define BOXING_HPP

#include "membership.hpp"

class BoxingMembership : public Membership {
public:
    BoxingMembership(const std::string& _startDate, const std::string& _endDate);
    virtual void displayDetails() const override;
    std::string getStartDate() const override; // Define getStartDate function
    std::string getEndDate() const override; // Define getEndDate function
    std::string getType() const override; 
};

#endif // BOXING_HPP
