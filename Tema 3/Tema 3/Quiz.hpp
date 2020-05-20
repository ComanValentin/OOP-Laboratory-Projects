#pragma once

#include <vector>
#include <ostream>
#include "Exam.hpp"

class Quiz : public Exam {
public:
    struct Entry {
        Entry(std::string question, std::string a, std::string b, std::string c);

        std::string question;
        std::string a, b, c;

        std::string toString() const;
    };

private:
    std::vector<Entry> entries;

public:
    Quiz(const std::string &subjectName, float writtenGrade);

    void addEntry(const Entry &entry);

    int getEntriesNum() const;

    const Entry &getEntry(int index) const;

    void setEntries(const std::vector<Entry> &entries);

    std::string toString() const override;

    friend std::ostream &operator<<(std::ostream &os, const Quiz &quiz);
};
