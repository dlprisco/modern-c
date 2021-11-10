// Monthly calendar

/*

    To work with time zones, you must use the tz.h header of the date library. However, this
  needs the IANA Time Zone Database to be downloaded and uncompressed on your machine.

*/

using namespace std;

unsigned int week_day(int const y, unsigned int const m, unsigned int const d) {
    using namespace date;
    if(m < 1 || m > 12 || d < 1 || d > 31) return 0;
    auto const dt = date::year_month_day{year{ y }, month{ m }, day{ d }};
    auto const tiso = iso_week::year_weeknum_weekday{ dt };
    return (unsigned int)tiso.weekday();
}

void print_month_calendar(int const y, unsigned int m) {
    using namespace date;
    cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;
    auto first_day_weekday = week_day(y, m, 1);
    auto last_day = (unsigned int)year_month_day_last(year{ y }, month_day_last{ month{ m } }).day();
    unsigned int index = 1;
    for (unsigned int day = 1; day < first_day_weekday; ++day, ++index) {
        cout << " ";
    }
    for (unsigned int day = 1; day <= last_day; ++day) {
        cout << right << setfill(' ') << setw(3) << day << ' ';
        if (index++ % 7 == 0) cout << endl;
    }
    cout << endl;
}

int main() {

    print_month_calendar(2017, 12);
    return 0;
}