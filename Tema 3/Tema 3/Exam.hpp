#pragma once

#include <string>
#include <ostream>

class Exam {
protected:
    static int currentID;
    int id;
    std::string subjectName;
    float writtenGrade;
public:
    Exam(std::string subjectName, float writtenGrade);

    Exam(const Exam &exam);

    Exam &operator=(const Exam &rhs);

    const std::string &getSubjectName() const;

    int getId() const;

    float getWrittenGrade() const;

    virtual std::string toString() const;

    friend std::ostream &operator<<(std::ostream &os, const Exam &exam);
};
