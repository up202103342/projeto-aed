#ifndef STUDENT_H_
#define STUDENT_H_

#include <vector>
#include <iostream>


using namespace std;

class Turma;

class Student {
public:
    Student(int code, string name);

    vector<Turma> getClasses();                                 //erro "Use of undeclared identifier 'Turma'"
    int getCode() const;
    string getName();
    void addClass(Turma t);
    bool operator< (const Student & a);


private:
    vector<Turma> classes;                                      //erro "Use of undeclared identifier 'Turma'"
    int code;
    string name;
};

#endif
