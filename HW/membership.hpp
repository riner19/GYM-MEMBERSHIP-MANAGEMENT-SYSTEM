#ifndef MEMBERSHIP_HPP
#define MEMBERSHIP_HPP

#include <string>

class Membership {
protected:
    std::string startDate;
    std::string endDate;

public:
    Membership(const std::string& _startDate, const std::string& _endDate);
    virtual ~Membership() {}

    virtual void displayDetails() const = 0;
    virtual std::string getStartDate() const = 0;
    virtual std::string getEndDate() const = 0;
    
    virtual std::string getType() const = 0;
};

#endif // MEMBERSHIP_HPP
