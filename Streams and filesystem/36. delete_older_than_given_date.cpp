// Deleting files older than a given date

using namespace std;

namespace fs = experimental::filesystem;
namespace ch = chrono;

template <typename Duration>
bool is_older_than(fs::path const & path, Duration const duration) {
	auto ftimeduration = fs::last_write_time(path).time_since_epoch();
	auto nowduration = (ch::system_clock::now() - duration).time_since_epoch();
	return ch::duration_cast<Duration>(nowduration - ftimeduration).count() > 0;
}

template <typename Duration>
void remove_files_older_than(fs::path const & path, Duration const duration) {
	try {
		if (fs::exists(path)) {
			if (is_older_than(path, duration)) {
				fs::remove(path);
			}
			else if(fs::is_directory(path)) {
				for (auto const & entry : fs::directory_iterator(path)) {
					remove_files_older_than(entry.path(), duration);
				}
			}
		}
	}
	catch (exception const & ex) {
		cerr << ex.what() << endl;
	}
}

int main()
{
	using namespace chrono_literals;
	#ifdef _WIN32
	auto path = R"(..\Test\)";

	#else
	auto path = R"(../Test/)";
	#endif

	remove_files_older_than(path, 1h + 20min);
}