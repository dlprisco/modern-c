// Day and week of the year

using namespace std;

int day_of_year(int const y, unsigned int const m, unsigned int const d) {
    using namespace date;
    if(m < 1 || m > 12 || d < 1 || d > 31) return 0;
    return (sys_days{ year{ y } / month{ m } / day{ d } } - sys_days{ year{ y } / jan / 0 }).count();
}

unsigned int calendar_week(int const y, unsigned int const m, unsigned int const d) {
    using namespace date;
    if(m < 1 || m > 12 || d < 1 || d > 31) return 0;
    auto const dt = date::year_month_day{year{ y }, month{ m }, day{ d }};
    auto const tiso = iso_week::year_weeknum_weekday{ dt };
    return (unsigned int)tiso.weeknum();
}