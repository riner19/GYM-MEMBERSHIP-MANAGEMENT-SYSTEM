
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "member.hpp"
#include "gym.hpp"
#include "muay_thai.hpp"
#include "boxing.hpp"

using namespace std;

void readDataFromFile(const std::string& filename) {
    
    //code is needed
}

void writeDataToFile(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    for (auto& member : Member::members) {
        outputFile << member->getMemberID() << " " << member->getName() << " " << member->getAge() << " " << member->getNumber();
        if (member->getMembership()) {
            outputFile << "writing" << member->getMembership()->getType() << " " << member->getMembership()->getStartDate() << " " << member->getMembership()->getEndDate();
        }
        outputFile << std::endl;
    }

    outputFile.close();
    std::cout<<"data is written";
}


void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Create Member\n";
    cout << "2. Edit Member Data\n";
    cout << "3. Sign Up Member for Gym\n";
    cout << "4. Sign Up Member for Muay Thai\n";
    cout << "5. Sign Up Member for Boxing\n";
    cout << "6. Search Member\n";
    cout << "7. Display All Members\n";
    cout << "9. Exit\n";
}

void createMember(int *next_id) {
    string name;
    int age, number;

    // Get name with exception handling
    while (true) {
        try {
            cout << "Enter name: ";
            cin >> name;
            if (name.empty()) {
                throw invalid_argument("Name cannot be empty.");
            }
            break; // If input is valid, exit the loop
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Get age with exception handling
    while (true) {
        try {
            cout << "Enter age: ";
            cin >> age;
            if (age <= 0) {
                throw invalid_argument("Age must be a positive integer.");
            }
            break; // If input is valid, exit the loop
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Get phone number with exception handling
    while (true) {
        try {
            cout << "Enter phone number: ";
            cin >> number;
            if (number <= 0) {
                throw invalid_argument("Phone number must be a positive integer.");
            }
            break; // If input is valid, exit the loop
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Create the member
    Member* newMember = Member::createMember(*next_id, name, age, number);
    if (newMember) {
        cout << "Member created successfully.\n";
        (*next_id)++;
    } else {
        cout << "Failed to create member.\n";
    }

    // Clear the input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



void editMemberData() {
    int memberId;
    std::cout << "Enter member ID to edit: ";
    std::cin >> memberId;
    Member* member = Member::findMemberByID(memberId);
    if (member) {
        std::string newName;
        int newAge, newNumber;
        std::cout << "Enter new name: ";
        std::cin >> newName;
        std::cout << "Enter new age: ";
        std::cin >> newAge;
        std::cout << "Enter new phone number: ";
        std::cin >> newNumber;

        // Edit member data
        Member::editMember(member, newName, newAge, newNumber);
        std::cout << "Member data edited successfully.\n";

        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "Member not found.\n";
    }
}

void signUpForMemberGym() {
    int memberId;
    std::cout << "Enter member ID: ";
    std::cin >> memberId;
    Member* member = Member::findMemberByID(memberId);
    if (member) {
        // Sign up member for gym
        GymMembership* gymMembership = new GymMembership("2024-05-15", "2024-11-15");
        member->setMembership(gymMembership);
        std::cout << "Member signed up for gym successfully.\n";
    } else {
        std::cout << "Member not found.\n";
    }
}
void signUpForMemberMuayThai() {
    int memberId;
    std::cout << "Enter member ID: ";
    std::cin >> memberId;
    Member* member = Member::findMemberByID(memberId);
    if (member) {
        // Sign up member for Muay Thai
        MuayThaiMembership* muayThaiMembership = new MuayThaiMembership("2024-05-15", "2024-11-15");
        member->setMembership(muayThaiMembership);
        std::cout << "Member signed up for Muay Thai successfully.\n";
    } else {
        std::cout << "Member not found.\n";
    }
}

void signUpForMemberBoxing() {
    int memberId;
    std::cout << "Enter member ID: ";
    std::cin >> memberId;
    Member* member = Member::findMemberByID(memberId);
    if (member) {
        // Sign up member for Boxing
        BoxingMembership* boxingMembership = new BoxingMembership("2024-05-15", "2024-11-15");
        member->setMembership(boxingMembership);
        std::cout << "Member signed up for Boxing successfully.\n";
    } else {
        std::cout << "Member not found.\n";
    }
}

void searchMember() {
    int memberId;
    std::cout << "Enter member ID to search: ";
    std::cin >> memberId;
    Member* member = Member::findMemberByID(memberId);
    if (member) {
        std::cout << "Member found:\n";
        std::cout << "ID: " << member->getMemberID() << ", Name: " << member->getName() << "\n";
    } else {
        std::cout << "Member not found.\n";
    }
}

void displayAllMembers() {
    Member::displayAllMembers();
}

/*void printMemberDataToFile() {
    std::string filename;
    std::cout << "Enter filename to print member data: ";
    std::cin >> filename;
    Member::printMemberDataToFile(filename);
}*/

int main() {
    int next_id = 1000;
    
    readDataFromFile("data.rtf");
    
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        displayMenu();
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
                    // Handle invalid input (non-integer)
                    cout << "Invalid input. Please enter a valid menu choice.\n";
                    cin.clear(); // Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    continue; // Skip the rest of the loop and restart from the beginning
                }
        switch (choice) {
            case 1: {
                createMember(&next_id);
                break;
            }
            case 2: {
                editMemberData();
                break;
            }
            case 3: {
                signUpForMemberGym();
                break;
            }
            case 4: {
                signUpForMemberMuayThai();
                break;
            }
            case 5: {
                signUpForMemberBoxing();
                break;
            }
            case 6: {
                searchMember();
                break;
            }
            case 7: {
                displayAllMembers();
                break;
            }
            case 8: {
                //printMemberDataToFile();
                break;
            }
            case 9: {
                writeDataToFile("data.rtf");
                exitProgram = true;
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }


    
        std::ofstream output;
        output.open("update.dat");
        int x = 2, y =4, z = 2;
        output <<  x + 1 << " " << y + 1 << " " << z + 1 << std::endl;
        output.close();
    
    writeDataToFile("dat.dat");
        //Clean up memory
    Member::cleanUpMemory();

        return 0;
}
