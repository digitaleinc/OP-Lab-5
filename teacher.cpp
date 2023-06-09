#include "teacher.h"

void Teacher::add_subject(TeacherSubject predmet) {
    if(list == nullptr)
    {
        list = new TeacherSubject[size + 1];
        list[size] = predmet;
        size++;
    }
    else{
        TeacherSubject* new_list = new TeacherSubject[size + 1];
        for(int i = 0; i < size; i++)
            new_list[i] = list[i];
        new_list[size] = predmet;
        size++;
        delete[] list;
        for(int i = 0; i < size; i++)
            list[i] = new_list[i];
        delete[] new_list;
    }
}

TeacherSubject *Teacher::get_list() {
    return this->list;
}

int Teacher::get_size()
{
    return this->size;
}

Teacher::Teacher(string name): Person(name) {
    list = nullptr;
    size = 0;
}

double Teacher::get_average() {
    if(this->list != nullptr)
    {
        double sum = 0;
        for(int i = 0; i < size; i++)
            sum += this->list[i].rating;
        return sum / size;
    }
    else{
        return 0;
    }
}

Teacher::Teacher(string name, Date birth, TeacherSubject *list, int size): Person(name) {
    this->set_date(birth);
    this->size = size;
    this->list = new TeacherSubject[size];
    for(int i = 0; i < size; i++)
        this->list[i] = list[i];
}

void Teacher::show() {
    cout << "Name of teacher: " << this->get_name() << endl;
    cout << "Date of birth: " << this->get_date() << endl;
    cout << "Age: " << this->get_age() << endl;
    cout << "SUBJECTS: \n";
    for(int i = 0; i < size; i++)
        cout << list[i].name << " : " << list[i].rating << endl;
    cout << endl;
}

Teacher::Teacher(Teacher &other) {
    this->size = other.size;
    for(int i = 0; i < size; i++)
        this->list[i] = other.list[i];
    this->set_name(other.get_name());
    this->set_date(other.get_date());
}
