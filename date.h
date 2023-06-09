#ifndef LAB5_DATE_H
#define LAB5_DATE_H

#include <ostream>

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int, int, int);
    void set_day(int);
    void set_month(int);
    void set_year(int);
    int get_day();
    int get_month();
    int get_year();
    friend std::ostream& operator<<(std::ostream& os, const Date& other);
    double operator-(const Date& other);
};

std::ostream& operator<<(std::ostream& os, const Date& other);

#endif