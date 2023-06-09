#include "date.h"

Date::Date() {
    day = month = year = 0;
}

Date::Date(int day, int month, int year): day(day), month(month), year(year) {

}

void Date::set_day(int day) {
    this->day = day;
}
void Date::set_month(int month) {
    this->month = month;
}
void Date::set_year(int year) {
    this->year = year;
}

int Date::get_day() {
    return day;
}
int Date::get_month() {
    return month;
}
int Date::get_year() {
    return year;
}

std::ostream& operator<<(std::ostream& os, const Date& other)
{
    os << other.day << "." << other.month << "." << other.year;
    return os;
}

double Date::operator-(const Date &other) {
    int years1 = this->year;
    int years2 = other.year;

    if (this->month <= 2) {
        years1--;
    }

    if (other.month <= 2) {
        years2--;
    }

    double days1 = years1 * 365 + years1 / 4 - years1 / 100 + years1 / 400 + this->day + (153 * this->month + 8) / 5;
    double days2 = years2 * 365 + years2 / 4 - years2 / 100 + years2 / 400 + other.day + (153 * other.month + 8) / 5;

    return (days1 - days2) / 365;
}
