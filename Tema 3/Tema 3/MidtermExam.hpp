#pragma once

#include <ostream>
#include "Exam.hpp"

class MidtermExam : public Exam {
    float oralGrade;

public:
    MidtermExam(const std::string &subjectName, float writtenGrade, float oralGrade);

    MidtermExam(const MidtermExam &exam);

    MidtermExam &operator=(const MidtermExam &rhs);

    float getOralGrade() const;

    std::string toString() const override;

    friend std::ostream &operator<<(std::ostream &os, const MidtermExam &exam);
};
