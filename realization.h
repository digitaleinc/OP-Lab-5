#ifndef LAB5_REALIZATION_H
#define LAB5_REALIZATION_H

#include "student.h"
#include "teacher.h"
#include "person.h"

bool toContinue(string sign);
int input_size(string sign);
Student* create_array(int);
void show_student_array(Student*, int);
Date participate_date(string);
Teacher* create_teacher_array(int);
void show_teacher_array(Teacher*, int);
void student_average_mark(Student*, int);
void teacher_average_mark(Teacher*, int);
void define_debtors(Student*, int);

#endif
