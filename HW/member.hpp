#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <string>
#include <vector>
#include "membership.hpp" // Assuming you have a header file for the Membership class

using namespace std;
class Member {
private:
    static std::vector<Member*> members;
    int member_id;
    std::string name;
    int age;
    int number;
    Membership* membership;
    friend void writeDataToFile(const string& filename);
    
    

public:
    // Constructor
    Member(int id, const std::string& n, int a, int num, Membership* mem);

    // Destructor
    ~Member();
    
    static void cleanUpMemory();

    // Getters
    int getMemberID() const;
    std::string getName() const;
    int getAge() const;
    int getNumber() const;
    Membership* getMembership() const;

    // Setters
    void setMembership(Membership* mem);

    // Static member functions
    static Member* createMember(int next_id, const std::string& _name, int _age, int _number);
    static void editMember(Member* member, const std::string& _name, int _age, int _number);
    static Member* findMemberByID(int id);
    static void displayAllMembers();

private:
    // Static vector to store all members
    //static std::vector<Member*> members;
};

#endif // MEMBER_HPP
