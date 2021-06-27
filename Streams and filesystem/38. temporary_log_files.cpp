// Temporary log files

/*

	In order to create unique names for the file, you could use a UUID (also known as GUID).
  
  	The C++ standard does not support any functionality related to that, but there are thirdparty
  libraries, such as boost::uuid, CrossGuid, or stduuid, which is actually a library
  that I created. For this implementation, I will use the last one. You can find it at 
  https://github.com/mariusbancila/stduuid

*/

using namespace std;

namespace fs = std::experimental::filesystem;

class logger {
	fs::path logpath;
	std::ofstream logfile;
public:
	logger() {
		auto name = uuids::to_string(uuids::uuid_random_generator{}());
		logpath = fs::temp_directory_path() / (name + ".tmp");
		logfile.open(logpath.c_str(), std::ios::out|std::ios::trunc);
	}
	~logger() noexcept {
		try {
			if(logfile.is_open()) logfile.close();
			if (!logpath.empty()) fs::remove(logpath);
		}
		catch (...) {}
	}

	void persist(fs::path const & path) {
		logfile.close();
		fs::rename(logpath, path);
		logpath.clear();
	}

	logger& operator<<(std::string_view message) {
		logfile << message.data() << '\n';
		return *this;
	}
};	

int main() {
	logger log;
	try {
		log << "this is a line" << "and this is another one";
		throw std::runtime_error("error");
	}
	catch (...) {
		log.persist(R"(lastlog.txt)");
	}
}