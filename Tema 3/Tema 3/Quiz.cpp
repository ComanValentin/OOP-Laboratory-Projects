#include "Quiz.hpp"

#include <utility>

Quiz::Quiz(const std::string &subjectName, float writtenGrade)
        : Exam(subjectName, writtenGrade) {
}

void Quiz::addEntry(const Quiz::Entry &entry) {
    entries.push_back(entry);
}

int Quiz::getEntriesNum() const {
    return entries.size();
}

const Quiz::Entry &Quiz::getEntry(int index) const {
    return entries.at(index);
}

void Quiz::setEntries(const std::vector<Entry> &entries) {
    Quiz::entries = entries;
}

std::string Quiz::Entry::toString() const {
    return question + "\na) " + a + "\nb) " + b + "\nc) " + c;
}

Quiz::Entry::Entry(std::string question, std::string a, std::string b, std::string c)
        : question(std::move(question)), a(std::move(a)), b(std::move(b)), c(std::move(c)) {
}

std::string Quiz::toString() const {
    std::string str = Exam::toString() + "\n";
    for (int i = 0; i < entries.size(); ++i)
        str += std::to_string(i + 1) + ". " + entries[i].toString() + "\n";

    return str;
}

std::ostream &operator<<(std::ostream &os, const Quiz &quiz) {
    os << quiz.toString();
    return os;
}
