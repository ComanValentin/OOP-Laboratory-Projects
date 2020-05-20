#include <iostream>
#include "Exam.hpp"
#include "MidtermExam.hpp"
#include "FinalExam.hpp"
#include "Student.hpp"
#include "IndividualCatalog.hpp"

using namespace std;

int main() {
    Exam exam1("Mathematics", 3);
    MidtermExam partial("Databases", 4.69, 7);
    FinalExam final("OOP", 4.99, 0.01);

    auto *student1 = new Student("Valentin", "Coman", 1234567890123);
    auto *student2 = new Student("Mircea", "Halalai", 123450505005);
    auto *student3 = new Student("Matei", "Anita", 121212121212);
    IndividualCatalog<MidtermExam> midtermsCatalog(student1);
    vector<MidtermExam *> midterms{&partial, new MidtermExam("PrBD", 6, 7),
                                   new MidtermExam("Grafica", 10, 10),
                                   new MidtermExam("Comunicare", 9, 4.41)};

    midtermsCatalog.setExams(midterms);

    IndividualCatalog<FinalExam> finalsCatalog(student1);
    finalsCatalog.addExam(&final).addExam(new FinalExam("Retele", 8, 0.5));

    IndividualCatalog<Exam> examCatalog(student2);
    examCatalog.addExam(&exam1);

    cout << midtermsCatalog << endl;
    cout << finalsCatalog;

    Quiz quiz1("Retele1", 5), quiz2("Retele2", 11);
    quiz1.addEntry(Quiz::Entry("Cat face 1+1?", "1", "2", "Depinde cum bate vantul"));
    quiz1.addEntry(Quiz::Entry("Unde se configureaza DNS-ul?", "Server", "Router", "In toamna"));

    quiz2.addEntry(Quiz::Entry("Cum se configureaza conexiunea?", "Static", "RIP V1/2", "Nici una"));
    quiz2.addEntry(Quiz::Entry("Ce tip de router folosim?", "2911", "2910", "Ambele"));

    cout << quiz1 << endl << quiz2 << endl;

    IndividualCatalog<Quiz> quizCatalog1(student1);
    quizCatalog1.addQuiz(&quiz1).addQuiz(&quiz2);

    IndividualCatalog<Quiz> quizCatalog2(student2);
    quizCatalog2.addQuiz(&quiz1).addQuiz(&quiz2);

    IndividualCatalog<Quiz> quizCatalog3(student3);
    quizCatalog3.addQuiz(&quiz2);

    cout << "nr de studenti cu cel putin 2 quizuri date="
         << IndividualCatalog<Quiz>::getNumOfStudentsOverTwoQuizzes() << endl;

    cout << failedExams.size() << endl;

    for (auto &failedExam : failedExams)
        for (auto &student : failedExam.second)
            cout << *student << endl;

    cin.get();
}
