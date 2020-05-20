#include "Student.hpp"

#include <utility>

Student::Student(std::string firstName, std::string lastName, uint64_t cnp)
        : firstName(std::move(firstName)), lastName(std::move(lastName)), CNP(cnp) {
}

const std::string &Student::getFirstName() const {
    return firstName;
}

const std::string &Student::getLastName() const {
    return lastName;
}

uint64_t Student::getCnp() const {
    return CNP;
}

std::string Student::toString() const {
    return firstName + " " + lastName;
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << student.toString();
    return os;
}
