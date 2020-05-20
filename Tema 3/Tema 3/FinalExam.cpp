#include <sstream>
#include "FinalExam.hpp"

FinalExam::FinalExam(const std::string &subjectName, float writtenGrade, float bonusPoints)
        : Exam(subjectName, writtenGrade), bonusPoints(bonusPoints) {
}

FinalExam::FinalExam(const FinalExam &exam)
        : Exam(exam), bonusPoints(exam.bonusPoints) {
}

FinalExam &FinalExam::operator=(const FinalExam &rhs) {
    if (this != &rhs) {
        Exam::operator=(rhs);
        bonusPoints = rhs.bonusPoints;
    }
    return *this;
}

std::string FinalExam::toString() const {
    std::ostringstream formatter;
    formatter.precision(3);
    formatter << Exam::toString() << ", bonus: " << bonusPoints;
    return formatter.str();
}

std::ostream &operator<<(std::ostream &os, const FinalExam &exam) {
    os << exam.toString();
    return os;
}
