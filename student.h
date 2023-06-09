#ifndef LAB5_STUDENT_H
#define LAB5_STUDENT_H

#include "person.h"

struct StudentSubjects{
    double rating;
    string subject;
};

class Student : public Person{
private:
    int group;
    string subject;
    int size;
    StudentSubjects* list;
public:
    Student();
    Student(Student&);
    Student(string, int, Date, StudentSubjects*, int);
    Student(string, int);
    Student(string, string,int, double, Date);
    void set_group(int);
    int get_group();
    int get_size();
    StudentSubjects* get_list();
    void set_subject(string);
    string get_subject();
    double get_average() override;
    void show() override;

};

#endif
