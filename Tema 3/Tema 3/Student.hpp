#pragma once

#include <string>
#include <ostream>

class Student {
    std::string firstName, lastName;
    uint64_t CNP;

public:
    Student(std::string firstName, std::string lastName, uint64_t cnp);

    std::string toString() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    uint64_t getCnp() const;

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};
