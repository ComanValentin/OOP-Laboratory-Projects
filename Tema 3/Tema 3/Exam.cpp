#include "Exam.hpp"

#include <utility>
#include <sstream>

int Exam::currentID = 0;

Exam::Exam(std::string subjectName, float writtenGrade)
        : subjectName(std::move(subjectName)), writtenGrade(writtenGrade), id(currentID++) {
}

Exam::Exam(const Exam &exam)
        : subjectName(exam.subjectName), writtenGrade(exam.writtenGrade), id(currentID++) {
}

Exam &Exam::operator=(const Exam &rhs) {
    if (this != &rhs) {
        subjectName = rhs.subjectName;
        writtenGrade = rhs.writtenGrade;
    }
    return *this;
}

const std::string &Exam::getSubjectName() const {
    return subjectName;
}

int Exam::getId() const {
    return id;
}

float Exam::getWrittenGrade() const {
    return writtenGrade;
}

std::string Exam::toString() const {
    std::ostringstream formatter;
    formatter.precision(3);
    formatter << "id: " << id << ", subject: " << subjectName << ", writtenGrade: " << (writtenGrade);
    return formatter.str();
}

std::ostream &operator<<(std::ostream &os, const Exam &exam) {
    os << exam.toString();
    return os;
}


