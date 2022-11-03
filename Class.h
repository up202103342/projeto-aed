#ifndef CLASS_H_
#define CLASS_H_

#include <vector>
#include <iostream>

using namespace std;

class Student;
class Aula;
class UC;

class Turma {
public:
    Turma();
    Turma(string code, UC uc);
    vector<Student> getStudents();
    string getCode();
    vector<Aula> getAulas();
    UC getUc();
    void addStudent(Student s);
    void addAula(Aula a);
    int getN();

private:
    vector<Student> students;
    string code;
    vector<Aula> aulas;
    UC uc;
};

#endif