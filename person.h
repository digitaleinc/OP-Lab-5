#ifndef LAB5_PERSON_H
#define LAB5_PERSON_H

#include <iostream>
#include <sstream>
#include "date.h"
using namespace std;

class Person{
private:
    string name;
    Date birth;
    double rating;
    int age;
public:
    Person() = default;
    Person(string);
    int get_age();
    void set_rating(double);
    double get_rating();
    void set_name(string);
    void set_date(Date);
    Date get_date();
    string get_name();
    virtual double get_average() = 0;
    virtual void show() = 0;
};

#endif
