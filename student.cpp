#include "student.h"

void Student::set_group(int group) {
    this->group = group;
}

int Student::get_group() {
    return this->group;
}

void Student::set_subject(string subject) {
    this->subject = subject;
}

string Student::get_subject() {
    return this->subject;
}

Student::Student(string name, int group): Person(name), group(group) {

}

double Student::get_average() {
    return get_rating();
}

void Student::show() {
    cout << "Name :" << this->get_name() << endl;
    cout << "Date of birth: " << this->get_date() << endl;
    cout << "Age: " << this->get_age() << endl;
    cout << "Group: " << this->get_group() << endl << endl;
    for(int i = 0; i < this->size; i++)
    {
        cout << "Subject #" << i + 1 << endl;
        cout << this->list[i].subject << " | " << this->list[i].rating << endl;
    }
}

Student::Student(string name, string subject, int group, double mark, Date birth): Person(name), subject(subject), group(group) {
    this->set_date(birth);
    this->set_rating(mark);
}

Student::Student() {
    this->list = nullptr;
    this->size = 0;
}

Student::Student(string name, int group, Date date, StudentSubjects *list, int size): Person(name), group(group), size(size) {
    this->set_date(date);
    this->list = new StudentSubjects[size];
    for(int i = 0; i < size; i++)
    {
        this->list[i] = list[i];
    }
}

Student::Student(Student & other) {
    this->size = other.size;
    this->group = other.group;
    this->set_name(other.get_name());
    this->set_date(other.get_date());
    if(this->list != nullptr)
        delete[] this->list;
    this->list = new StudentSubjects[size];
    for(int i = 0; i < size; i++)
        this->list[i] = other.list[i];
}

int Student::get_size() {
    return this->size;
}

StudentSubjects *Student::get_list() {
    return this->list;
}
