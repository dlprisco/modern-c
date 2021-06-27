// Meeting time for multiple time zones

/*

    To work with time zones, you must use the tz.h header of the date library. However, this
  needs the IANA Time Zone Database to be downloaded and uncompressed on your machine.

*/

using namespace std;
struct user {
    string Name;
    date::time_zone const * Zone;
    explicit user(string_view name, string_view zone) : Name{name.data()}, Zone(date::locate_zone(zone.data())) {}
};


template <class Duration, class TimeZonePtr>
void print_meeting_times(date::zoned_time<Duration, TimeZonePtr> const & time, vector<user> const & users) {
    cout << left << setw(15) << setfill(' ') << "Local time: " << time << endl;

    for (auto const & user : users) {
        cout << left << setw(15) << setfill(' ') << user.Name << date::zoned_time<Duration, TimeZonePtr>(user.Zone, time) << endl;
    }
}

int main() {
    vector<user> users{
        user{ "Ildiko", "Europe/Budapest" },
        user{ "Jens", "Europe/Berlin" },
        user{ "Jane", "America/New_York" }
    };
    unsigned int h, m;
    
    cout << "Hour:"; cin >> h;
    cout << "Minutes:"; cin >> m;
    
    date::year_month_day today =
    date::floor<date::days>(ch::system_clock::now());
    
    auto localtime = date::zoned_time<chrono::minutes>(date::current_zone(), static_cast<date::local_days>(today)+ch::hours{h}+ch::minutes{m});
    print_meeting_times(localtime, users);

    return 0;
}    