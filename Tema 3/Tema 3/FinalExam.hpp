#pragma once

#include <ostream>
#include "Exam.hpp"

class FinalExam : public Exam {
    float bonusPoints;

public:
    FinalExam(const std::string &subjectName, float writtenGrade, float bonusPoints);

    FinalExam(const FinalExam &exam);

    FinalExam &operator=(const FinalExam &rhs);

    std::string toString() const override;

    friend std::ostream &operator<<(std::ostream &os, const FinalExam &exam);
};
