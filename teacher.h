#ifndef LAB5_TEACHER_H
#define LAB5_TEACHER_H

#include "person.h"

struct TeacherSubject{
    string name;
    double rating;
};

class Teacher : public Person{
private:
    int size;
    TeacherSubject* list;
public:
    Teacher() = default;
    Teacher(string, Date, TeacherSubject*, int);
    Teacher(string);
    void add_subject(TeacherSubject);
    TeacherSubject* get_list();
    int get_size();
    void show() override;
    double get_average() override;
    Teacher(Teacher& other);
};

#endif