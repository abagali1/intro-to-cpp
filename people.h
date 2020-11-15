#ifndef PEOPLE_HPP_
#define PEOPLE_HPP_

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Human{
    //private:
    protected:
        string name;
    public:
        Human(){
            this->name = "";
        }
        Human(string n){
            this->name = n;
        }
        virtual string greeting() = 0;
};

class Teacher: public Human{
    private:
        int id, age;
        string* courses;
    public:
        Teacher();
        Teacher(int, int);
        Teacher(int, int, string);
        ~Teacher();
        string greeting();
        void add_course(string, int);
};
#endif
