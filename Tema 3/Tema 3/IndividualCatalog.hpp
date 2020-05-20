#pragma once

#include <typeinfo>
#include <vector>
#include <unordered_map>
#include <ostream>
#include "Student.hpp"
#include "MidtermExam.hpp"
#include "FinalExam.hpp"
#include "Quiz.hpp"

#ifdef __GNUG__

#include <cstdlib>
#include <memory>
#include <cxxabi.h>

#endif

namespace {
    std::unordered_map<int, std::vector<Student *>> failedExams;
}

template<class T>
class IndividualCatalog {
    static int currRegNumber;

    int registrationNumber;
    Student *student;
    std::vector<T *> exams;
    int examsNumber = 0;

public:
    explicit IndividualCatalog(Student *student)
            : student(student), registrationNumber(currRegNumber++) {}

    IndividualCatalog &operator+=(const T &exam) {
        exams.push_back(exam);
        examsNumber = exams.size();
        evaluateGrade(exam);
    }

    IndividualCatalog &addExam(T *exam) {
        exams.push_back(exam);
        examsNumber = exams.size();
        evaluateGrade(exam);
        return *this;
    }

    int getExamsNumber() const {
        return examsNumber;
    }

    Student *getStudent() const {
        return student;
    }

    const std::vector<T *> &getExams() const {
        return exams;
    }

    void setExams(const std::vector<T *> &exams) {
        IndividualCatalog::exams = exams;
        examsNumber = exams.size();
        for (T *exam : this->exams)
            evaluateGrade(exam);
    }

private:
    void evaluateGrade(T *exam) {
        std::string typeName = typeid(exam).name();

        if (dynamic_cast<Exam *>(exam)->getWrittenGrade() < 5.0f) {
            failedExams[exam->getId()].push_back(student);
            return;
        }

        if (typeName == typeid(MidtermExam *).name()) {
            if (dynamic_cast<MidtermExam *>(exam)->getOralGrade() < 5.0f)
                failedExams[exam->getId()].push_back(student);
        }
    }

#ifdef __GNUG__

    // does demangling for GCC/MinGW
    static std::string demangle(const char *name) {
        int status = -4; // some arbitrary value to eliminate the compiler warning
        // enable c++11 by passing the flag -std=c++11 to g++
        std::unique_ptr<char, void (*)(void *)> res{
                abi::__cxa_demangle(name, nullptr, nullptr, &status),
                std::free
        };
        return (status == 0) ? res.get() : name;
    }

#else

    // does demangling for MSVC
    static std::string demangle(const char *name) {
        return std::string(name).erase(0, 6);
    }

#endif

    friend std::ostream &operator<<(std::ostream &os, const IndividualCatalog<T> &catalog) {
        // We need to demangle the name of template parameter
        std::string examType = IndividualCatalog::demangle(typeid(T).name());

        os << *catalog.student << "'s " << examType << "s\n";
        for (const auto &exam : catalog.exams)
            os << *exam << '\n';
        return os;
    }
};

template<>
class IndividualCatalog<Quiz> {
    static std::unordered_map<Student *, int> studentQuizAmounts;

    Student *student;
    std::vector<Quiz *> quizzes;

public:
    explicit IndividualCatalog(Student *student) : student(student) {
    }

    int getQuizzesNum() const {
        return quizzes.size();
    }

    IndividualCatalog<Quiz> &addQuiz(Quiz *quiz) {
        quizzes.push_back(quiz);
        studentQuizAmounts[student] += 1;
        return *this;
    }

    static int getNumOfStudentsOverTwoQuizzes() {
        int result = 0;
        for (auto &item : studentQuizAmounts)
            if (item.second >= 2)
                result++;
        return result;
    }

    friend std::ostream &operator<<(std::ostream &os, const IndividualCatalog<Quiz> &catalog) {
        os << *catalog.student << "'s " << "quizzes\n";
        for (const auto &quiz : catalog.quizzes)
            os << *quiz << '\n';
        return os;
    }
};

template<class T>
int IndividualCatalog<T>::currRegNumber = 0;
std::unordered_map<Student *, int> IndividualCatalog<Quiz>::studentQuizAmounts;