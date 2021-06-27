// Number of days between two dates

/*

    As of C++17, the chrono standard library does not have support for working with dates,
 weeks, calendars, time zones, and other useful related features. This will change in C++20,
 as time zones and calendar support have been added to the standard at the Jacksonville
 meeting, in March 2018. The new additions are based on an open source library called
 date, built on top of chrono, developed by Howard Hinnant and available on GitHub at
 https://github.com/HowardHinnant/date. We will use this library to solve several of the
 problems in this chapter. Although in this implementation the namespace is date, in C++20
 it will be part of chrono. However, you should be able to simply replace the
 namespace without any further code changes.
 To solve this task, you could use the date::sys_days class, available in the
 date.h header. It represents a count of days since the system_clock epoch. This is
 a time_point with a resolution of a day and is implicitly convertible to
 system_clock::time_point. Basically, you have to construct two objects of this
 type and subtract them. The result is exactly the number of days between the two dates.

 The following is a simple implementation of such a function:

*/

using namespace std;

inline int number_of_days(int const y1, unsigned int const m1, unsigned int const d1, 
                          int const y2, unsigned int const m2, unsigned int const d2) {

    using namespace date;

    return (sys_days{ year{ y1 } / month{ m1 } / day{ d1 } } - sys_days{ year{ y2 } / month{ m2 } / day{ d2 } }).count();
}

inline int number_of_days(date::sys_days const & first,date::sys_days const & last) {
    return (last - first).count();
}

int main() {
    auto diff1 = number_of_days(2016, 9, 23, 2017, 5, 15);
    using namespace date::literals;
    auto diff2 = number_of_days(2016_y/sep/23, 15_d/may/2017);

    return 0;
}