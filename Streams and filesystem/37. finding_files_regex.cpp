// Finding files in a directory that match a regular expression

using namespace std;

namespace fs = experimental::filesystem;

vector<fs::directory_entry> find_files(fs::path const & path, string_view regex) {
	vector<fs::directory_entry> result;
	regex rx(regex.data());
	copy_if(fs::recursive_directory_iterator(path),fs::recursive_directory_iterator(),back_inserter(result),[&rx](fs::directory_entry const & entry) {return fs::is_regular_file(entry.path()) &&
		regex_match(entry.path().filename().string(), rx);
	});
	return result;
}

int main() {
	auto dir = fs::temp_directory_path();
	auto pattern = R"(wct[0-9a-zA-Z]{3}\.tmp)";
	auto result = find_files(dir, pattern);
	for (auto const & entry : result) {
		cout << entry.path().string() << endl;
	}
}