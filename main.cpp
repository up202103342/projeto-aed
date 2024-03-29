#include "UC.h"
#include "Class.h"
#include "Student.h"
#include "Aula.h"
#include "UC.cpp"
#include "Class.cpp"
#include "Student.cpp"
#include "Aula.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void readClasses(vector<UC> UCs) {
    ifstream infile("data/classes.cvs");
    string line;

    while (getline(infile, line, ',')) {
        istringstream iss(line);
        string turma, cadeira, dia, tipo;
        float hora, duracao;
        iss >> turma >> cadeira >> dia >> hora >> duracao >> tipo;
        int turmaN;
        std::istringstream(turma.substr(turma.length()-2,2)) >> turmaN;
        for (UC uc : UCs) {
            if (uc.getCode() == cadeira) {
                int len = uc.getClasses().size();
                Turma cl = uc.getClasses()[len/2];
                int min = 0; int max = len;
                while (cl.getN() != turmaN) {
                    if (cl.getN() > turmaN) {
                        max = (max + min)/2;
                    }
                    else {
                        min = (max + min)/2;
                    }
                    cl = uc.getClasses()[(max + min)/2];
                }
                Aula *aula = new Aula(uc, dia, hora, duracao, tipo, cl);
                cl.addAula(aula*);
                break;
            }
        }

    }
}

void readClassesPerUC(vector<UC> UCs) {
    ifstream infile("data/classes_per_uc.cvs");
    string line;
    while (getline(infile, line, ',')) {
        istringstream iss(line);
        string uccode, classcode;
        iss >> uccode >> classcode;
        bool uc_exists = false;
        for (UC uc : UCs) {
            if (uc.getCode() == uccode) {
                Turma *cl = new Turma(classcode, uc*);
                uc.addClass(cl*)
                uc_exists = true;
                break;
            }
        }
        if (!(uc_exists)) {
            UC *u = new UC(uccode);
            Turma *cl = new Turma(classcode, u);
            u->addClass(cl*);
            UCs.push_back(u*);
        }
    }
}

void readStudentsClasses(vector<UC> UCs, vector<Student> students) {
    ifstream infile("data/students_classes.csv");
    string line;
    while(getline(infile, line, ',')) {
        istringstream iss(line);
        string nome, cadeira, turma;
        int codigo;
        iss >> codigo >> nome >> cadeira >> turma;
        int turmaN;
        std::istringstream(turma.substr(turma.length()-2,2)) >> turmaN;
        int mins = 0;
        int maxs = students.size();
        Student s = students[students.size()/2];
        bool student_exists = true;
        while (s.getCode() != codigo) {
            if (maxs - mins == 0) {
                student_exists = false;
                break;
            }
            if (s.getCode() > codigo) {
                maxs = (mins + maxs)/2;
            }
            else {
                mins = (mins + maxs)/2;
            }
        }
        if (!(student_exists)) { Student *s = new Student(codigo, nome); students.push_back(s*); sort(students.begin(), students.end()); }
        for(UC uc : UCs) {
            if (uc.getCode() == cadeira){
                int len = uc.getClasses().size();
                Turma cl = uc.getClasses()[len/2];
                int min = 0; int max = len;
                while (cl.getN() != turmaN) {
                    if (cl.getN() > turmaN) {
                        max = (max + min)/2;
                    }
                    else {
                        min = (max + min)/2;
                    }
                    cl = uc.getClasses()[(max + min)/2];
                }
                s.addClass(cl);
                cl.addStudent(s);
            }
        }
    } 
}

int main() {


    ifstream infile("data/classes.cvs");
    string line;
    vector<UC> UCs;
    vector<Student> students;

    readClassesPerUC(UCs);
    readClasses(UCs);
    readStudentsClasses(UCs, students);
    
    for (UC uc : UCs) {
        for (Turma c : uc.getClasses()) {
            cout << c.getCode();
        }
    }

    return 1;
}
