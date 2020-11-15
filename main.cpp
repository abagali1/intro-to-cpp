#ifdef USE_CPP
// C++ Standard Libraries
#include <iostream> // #include <stdio.h> in C

#else

// C Standard Libraries
#include <stdio.h> // #include <iostream> in C++
#endif

#include "people.h" // Non-standard, external libraries always have .h


#define CLASS_SIZE 1000
using namespace std;

class Student {
    private:
        int age, id;
        string name;
        Student* classmates;
    public:
        Student(){
            this->age = 0;
            this->id = 0;
            this->name = "unknown";
            this->classmates = new Student[CLASS_SIZE];
        };
        Student(int age, int id, string name){
            this->age = age;
            this->id = id;
            this->name = name;
            this->classmates = new Student[CLASS_SIZE];
        }
        ~Student(){
            delete[] this->classmates;
        }
        void add_classmate(Student, int);
        int get_age(){
            return this->age;
        }
};

void Student::add_classmate(Student s, int n){
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
#endif

}
