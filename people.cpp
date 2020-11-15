#include "people.h"

Teacher::Teacher()
    :Human()
{
    this->id = 0;
    this->age = 0;
    this->courses = new string[7];
}

Teacher::Teacher(int a, int i)
    :Human(), age(a), id(i)
{
    this->courses = new string[7];
}

Teacher::Teacher(int a, int i, string n)
    : Human(n), age(a), id(i)
{
    this->courses = new string[7];
}


Teacher::~Teacher(){
    delete[] this->courses;
}

string Teacher::greeting(){
    return "Hello I am teacher " + this->name;
}


void Teacher::add_course(string s, int n){
    if(n >= 0 && n < 7)
        *(this->courses + n) = s;
    else
        cout << "index out of range" << endl;
}
