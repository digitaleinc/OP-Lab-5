#include "person.h"

Person::Person(string name): name(name) {

}

void Person::set_rating(double rating) {
    this->rating = rating;
}

double Person::get_rating() {
    return this->rating;
}



void Person::set_date(Date birth) {
    this->birth = birth;
}

Date Person::get_date() {
    return this->birth;
}

int Person::get_age() {
    return (int)(Date(8,6,2023) - this->birth);
}

string Person::get_name()
{
    return this->name;
}

void Person::set_name(string name) {
    this->name = name;
}
