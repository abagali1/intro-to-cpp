#pragma once
#ifdef USE_CPP // ex. Compiler Directives
// C++ Standard Libraries
#include <iostream> // #include <stdio.h> in C

#else

// C Standard Libraries
#include <stdio.h> // #include <iostream> in C++
#endif

#include "people.h" // Non-standard, external libraries always have .h
#include "class.h"

#define CLASS_SIZE 1000 // Compiler Constants
using namespace std; // ignore for now

class Student { // ex. Classes
    private: // private attributes (ONLY ACCESSIBLE INSIDE CLASS)
        int age, id;
        string name;
        Student* classmates;
    public: // public attributes (ACCESSIBLE OUTSIDE AND INSIDE CLASS)
        Student(){ // this-> is a way to reference a named attribute of a pointer
            this->age = 0;
            this->id = 0;
            this->name = "unknown";
            // ALLOCATE classmates on HEAP
//            this->classmates = new Student[CLASS_SIZE]; 
            this->classmates = (Student*)malloc(sizeof(Student) * CLASS_SIZE);
        };
        Student(int age, int id, string name){
            this->age = age;
            this->id = id;
            this->name = name;
            // ALLOCATE classmates on HEAP
            this->classmates = new Student[CLASS_SIZE];
        }
        ~Student(){
            cout << "Deleting " << this->name << endl;
            delete[] this->classmates; // HEAP VARIABLES REQUIRE MANUAL DELETION
        }
        void add_classmate(Student, int); // YOU CAN DECLARE METHODS WITHOUT DEFINITIONS
        int get_age(){
            return this->age;
        }
};

void Student::add_classmate(Student s, int n){ // YOU CAN DEFINE METHODS OUTSIDE THE CLASS
    if(n >= 0 && n < CLASS_SIZE)
        this->classmates[n] = s;
    else
        cout << "index out of bounds" << endl;
}

int main(int argc, char** argv){
#ifdef USE_CPP
    std::cout << "Hello World from C++!\n";
    std::cout << "Hello World from C++!" << std::endl;

    cout << "Hello World from C++!" << endl;
#else
    printf("%s\n", "Hello World from C!");
    return 0;
#endif


    // REFERENCES
    int regular_variable = 11;
    int* reference_pointer = &regular_variable;

    cout << &regular_variable << endl; // OUTPUTS MEMORY ADDR
    cout << reference_pointer << endl; // SAME AS PREV
    cout << regular_variable << endl; // OUTPUTS VALUE
    cout << *reference_pointer << endl; // DEREFERENCES POINTER AND OUTPUTS VALUE OF regular_variable

    regular_variable = 12;
    cout << *reference_pointer << endl;


    // ARRAYS ON STACK 
    int reg_array[5];
    reg_array[0] = 0;
    *(reg_array+1) = 1;
    cout << reg_array << endl;
    cout << reg_array[0] << endl;
    cout << *(reg_array+1) << endl;

    // ARRAYS ON HEAP
    int* new_array = new int[5];
    new_array[0] = 0;
    *(new_array+1) = 1;
    cout << new_array << endl;
    cout << new_array[0] << endl;
    cout << *(new_array+1) << endl;
    delete[] new_array;

    // ARRAYS ON HEAP 
    int* malloc_array = (int*)malloc(sizeof(int) * 5);
    malloc_array[0] = 0;
    *(malloc_array+1) = 1;
    cout << malloc_array << endl;
    cout << malloc_array[0] << endl;
    cout << *(malloc_array+1) << endl;
    delete[] malloc_array;

    Teacher t();
    Student s(0,0,"stack");
    Student* ss = new Student(0,0,"heap");


}
