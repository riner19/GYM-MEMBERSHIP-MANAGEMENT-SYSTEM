#include "member.hpp"
#include "gym.hpp"
#include "muay_thai.hpp"
#include "boxing.hpp"

#include <iostream>

using namespace std;

// Define the static vector to store all members
vector<Member*> Member::members;


// Constructor
Member::Member(int id, const string& n, int a, int num, Membership* mem)
    : member_id(id), name(n), age(a), number(num), membership(mem) {}

// Destructor
Member::~Member() {
    delete membership; // Assuming ownership of membership
}

// Getters
int Member::getMemberID() const {
    return member_id;
}

string Member::getName() const {
    return name;
}

int Member::getAge() const {
    return age;
}

int Member::getNumber() const {
    return number;
}

Membership* Member::getMembership() const {
    return membership;
}

// Setters
void Member::setMembership(Membership* mem) {
    membership = mem;
}

// Static member functions

Member* Member::createMember(int next_id, const string& _name, int _age, int _number) {
    Member* newMember = new Member(next_id, _name, _age, _number, nullptr); // Assuming Membership* membership is initialized as nullptr
    members.push_back(newMember);
    return newMember;
}

void Member::editMember(Member* member, const string& _name, int _age, int _number) {
    member->name = _name;
    member->age = _age;
    member->number = _number;
}

Member* Member::findMemberByID(int id) {
    for (auto& member : members) {
        if (member->getMemberID() == id) {
            return member;
        }
    }
    return nullptr; // Member not found
}

void Member::displayAllMembers() {
    for (auto& member : members) {
        cout << "Member ID: " << member->getMemberID() << ", Name: " << member->getName() << ", Age: " << member->getAge() << ", Number: " << member->getNumber()<< " ";

        if (member->getMembership()) {
            member->getMembership()->displayDetails();
        } else {
            cout << ", Not signed up for any membership";
        }
        cout << endl;
    }
}

void Member::cleanUpMemory() {
    for (Member* member : members) {
        delete member;
    }
    members.clear();
}
