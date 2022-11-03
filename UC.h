#ifndef UC_H_
#define UC_H_

#include <vector>
#include <iostream>

using namespace std;

class Turma;

class UC {
public:
    UC();
    UC(string code);
    vector<Turma> getClasses();
    string getCode();
    void addClass(Turma t);
private:
    vector<Turma> classes;
    string code;
};

#endif