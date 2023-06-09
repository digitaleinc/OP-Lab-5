#include "realization.h"

bool toContinue(string sign) {
    bool result;
    bool flag;
    char ch;
    do{
        cout << sign;
        cin >> ch;
        if (ch == 'y'||ch=='Y')
        {
            fflush(stdin);
            result = true;
            flag = true;
        }
        else if(ch == 'n' || ch == 'N')
        {
            fflush(stdin);
            result = false;
            flag = true;
        }
        else{
            fflush(stdin);
            flag = false;
        }
    }while(!flag);

    return result;
}

int input_size(string sign) {
    int result;
    cout << sign;
    cin >> result;
    return result;
}

Student *create_array(int size) {
    string tmp_name;
    string tmp_subject;
    string tmp_date;
    int tmp_group;
    int tmp_subject_size;
    double tmp_subject_mark;

    Student* tmp_array = new Student[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Student #" << i + 1 << endl;
        fflush(stdin);
        cout << "Input name: ";
        getline(cin, tmp_name);
        fflush(stdin);

        cout << "Input date: ";
        getline(cin, tmp_date);
        fflush(stdin);

        cout << "Input group: ";
        cin >> tmp_group;
        fflush(stdin);

        cout << "Input quantity of subjects: ";
        cin >> tmp_subject_size;
        fflush(stdin);

        StudentSubjects* tmp_subject_array = new StudentSubjects[tmp_subject_size];
        for(int j = 0; j < tmp_subject_size; j++)
        {
            cout << "Subject #" << j + 1 << endl;
            cout << "Name: ";
            getline(cin, tmp_subject);
            fflush(stdin);

            cout << "Rating: ";
            cin >> tmp_subject_mark;
            fflush(stdin);

            StudentSubjects tmp_st_sub;
            tmp_st_sub.rating = tmp_subject_mark;
            tmp_st_sub.subject = tmp_subject;

            tmp_subject_array[j] = tmp_st_sub;
        }
        cout << endl;
        tmp_array[i] = Student(tmp_name, tmp_group, participate_date(tmp_date), tmp_subject_array, tmp_subject_size);
        delete[] tmp_subject_array;
    }

    return tmp_array;
}

Date participate_date(string date_str) {
    int date, month, year;
    char ch;
    istringstream ios(date_str);
    ios >> date >> ch >> month >> ch >> year;
    return Date(date, month, year);
}

void show_student_array(Student *array, int size) {
    cout << "STUDENTS: \n";
    for(int i = 0; i < size; i++)
    {
        cout << "-------------------------------\n";
        cout << "Student #" << i + 1 << endl;
        array[i].show();
        cout << "-------------------------------\n";
    }

    cout << endl;
}

Teacher *create_teacher_array(int size) {
    string tmp_name;
    string tmp_date;
    string tmp_subject;
    int tmp_subject_size;
    double tmp_subject_rating;
    string tmp_subject_name;


    Teacher* tmp_array = new Teacher[size];
    for(int i = 0; i < size; i++)
    {
        fflush(stdin);
        cout << "Input name of teacher: ";
        getline(cin, tmp_name);
        fflush(stdin);

        cout << "Input date of birth: ";
        getline(cin, tmp_date);
        fflush(stdin);

        cout << "Input quantity of subjects: ";
        cin >> tmp_subject_size;
        fflush(stdin);

        TeacherSubject tmp_subject;
        TeacherSubject* tmp_subject_array = new TeacherSubject[tmp_subject_size];
        for(int i = 0; i < tmp_subject_size; i++)
        {
            cout << "Subject #" << i + 1 << endl;
            cout << "Name: ";
            getline(cin, tmp_subject_name);
            fflush(stdin);

            cout << "Rating(0-10): ";
            cin >> tmp_subject_rating;
            fflush(stdin);

            tmp_subject.name = tmp_subject_name;
            tmp_subject.rating = tmp_subject_rating;
            tmp_subject_array[i] = tmp_subject;
        }
        tmp_array[i] = Teacher(tmp_name, participate_date(tmp_date), tmp_subject_array, tmp_subject_size);
        delete[] tmp_subject_array;
    }

    return tmp_array;
}

void show_teacher_array(Teacher *array, int size) {
    cout << "\nTEACHERS\n\n";
    for(int i = 0; i < size; i++)
    {
        cout << "-------------------------------\n";
        cout << "Teacher #" << i + 1 << endl;
        array[i].show();
        cout << "-------------------------------\n";
    }

}

void student_average_mark(Student *array, int size) {
    double average = 0;
    cout << "\nStudent average mark\n";
    for(int i = 0; i < size; i++)
    {
        double tmp_average = 0;
        for(int j = 0; j < array[i].get_size();j++)
        {
            tmp_average += array[i].get_list()[j].rating;
        }
        average += tmp_average / array[i].get_size();
        cout << array[i].get_name() << " | " << tmp_average/array[i].get_size() << endl;
    }

    average = average / size;
    cout << "\nAverage mark of students: " << average;

}

void teacher_average_mark(Teacher *array, int size) {
    cout << "\nTeachers average mark:\n";
    double average = 0;
    for(int i = 0; i < size; i++)
    {
        double tmp_average = 0;
        for(int j = 0; j < array[i].get_size(); j++)
        {
            tmp_average += array[i].get_list()[j].rating;
        }
        average += tmp_average / array[i].get_size();
        cout << array[i].get_name() << " | " << tmp_average / array[i].get_size() << endl;
    }
    cout << "\nAverage mark of teachers: " << average / size << endl;
}

void define_debtors(Student *array, int size) {
    bool flag;
    Date current(8, 6, 2023);
    cout << "Students with less than 60 points\n";
    for(int i = 0; i < size; i++)
    {
        flag = false;
        if(current - array[i].get_date() < 18)
        {
            for(int j = 0; j < array[i].get_size(); j++)
                if(array[i].get_list()[j].rating < 60)
                    flag = true;
            if (flag)
            {
                cout << "-----------------------------\n";
                cout << "Student #" << i + 1 << endl;
                array[i].show();
                cout << "-----------------------------\n";
            }
        }
    }
}
