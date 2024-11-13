#include <iostream>

using namespace std;

class Student {
    char* name;
public:
    Student() {
        name = new char[9] {'B', 'o', 'r', 'i', 's', '\0' };
    }
    Student(const Student& other) {
        delete[] this->name;
        this->name = nullptr;

        this->name = new char[strlen(other.name) + 1];

        for (int i = 0; i < strlen(other.name) + 1; i++) {
            this->name[i] = (char)other.name[i];
        }
    }

   

    void PrintInfo() {
        cout << "Name of student: " << name << endl;
    }

    ~Student() {
        delete[] this->name;
        this->name = nullptr;
    }
};

class Group {
    Student* students;
    Student* tempArr;
    int amountOfStudents;
public:
    Group() {
        amountOfStudents = 3;
        this->students = new Student[amountOfStudents];
        this->tempArr = new Student[amountOfStudents];
    }

    /*Group(const Group& other) {
        delete[] students;
        students = nullptr;

        amountOfStudents = other.amountOfStudents;
        students = new Student[other.amountOfStudents];
    }*/

    void StudentDelete(const Group& other) {
        delete[] students;
        students = nullptr;

        delete[] tempArr;
        tempArr = nullptr;
        
        amountOfStudents = other.amountOfStudents;
        tempArr = new Student[amountOfStudents - 1];
        
    }

    void StudentAdd(const Group& other) {
        delete[] students;
        students = nullptr;

        delete[] tempArr;
        tempArr = nullptr;

        amountOfStudents = other.amountOfStudents;
        tempArr = new Student[amountOfStudents + 1];
    }

    void PrintInfoAboutStudents() {
        for (int i = 0; i < amountOfStudents + 1; i++) {
            this->tempArr[i].PrintInfo();
        }
    }
};

void main() {
    Group obj;
    obj.PrintInfoAboutStudents();
}