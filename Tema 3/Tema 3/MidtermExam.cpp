
#include <sstream>
#include "MidtermExam.hpp"

MidtermExam::MidtermExam(const std::string &subjectName, float writtenGrade, float oralGrade)
        : Exam(subjectName, writtenGrade), oralGrade(oralGrade) {
}

MidtermExam::MidtermExam(const MidtermExam &exam)
        : Exam(exam), oralGrade(exam.oralGrade) {
}

MidtermExam &MidtermExam::operator=(const MidtermExam &rhs) {
    if (this != &rhs) {
        Exam::operator=(rhs);
        oralGrade = rhs.oralGrade;
    }
    return *this;
}

float MidtermExam::getOralGrade() const {
    return oralGrade;
}

std::string MidtermExam::toString() const {
    std::ostringstream formatter;
    formatter.precision(3);
    formatter << Exam::toString() << ", oralGrade: " << oralGrade;
    return formatter.str();
}

std::ostream &operator<<(std::ostream &os, const MidtermExam &exam) {
    os << exam.toString();
    return os;
}

