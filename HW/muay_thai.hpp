#ifndef MUAY_THAI_HPP
#define MUAY_THAI_HPP

#include "membership.hpp"

class MuayThaiMembership : public Membership {
public:
    MuayThaiMembership(const std::string& _startDate, const std::string& _endDate);
    virtual void displayDetails() const override;
    std::string getStartDate() const override; // Define getStartDate function
    std::string getEndDate() const override; // Define getEndDate function
    std::string getType() const override; 
};

#endif // MUAY_THAI_HPP
