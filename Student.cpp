//
// Created by nando on 02/11/2022.
//
#include "Student.h"
#include "Class.h"


//-------------------------------------------------------------------

//Constructor -------------------
Student::Student(int code, string name) {
    this->code = code;
    this->name = name;
    this->classes;

}

//Getters --------------------
vector<Turma> Student::getClasses() {
    return this->classes;
}

int Student::getCode() const {
    return this->code;
}

string Student::getName() {
    return this->name;
}

void Student::addClass(Turma t) {
    this->classes.push_back(t);
}

bool Student::operator< (const Student & a) {
    if (this->code < a.getCode()) { return true; }
    return false;
}
