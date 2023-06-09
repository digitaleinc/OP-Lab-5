#include "realization.h"

int main()
{
    int n = input_size("Input N(quantity of students): ");
    Student* student_array = create_array(n);
    show_student_array(student_array, n);

    int m = input_size("Input M(quantity of teachers): ");
    Teacher* teacher_array = create_teacher_array(m);
    show_teacher_array(teacher_array, m);

    student_average_mark(student_array, n);
    teacher_average_mark(teacher_array, m);

    define_debtors(student_array, n);

    return 0;
}