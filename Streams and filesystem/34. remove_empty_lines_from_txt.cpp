// Removing empty lines from a text file

using namespace std;

namespace fs = experimental::filesystem;

void remove_empty_lines(fs::path filepath) {
	ifstream filein(filepath.native(), ios::in);
	if (!filein.is_open())
		throw runtime_error("cannot open input file");
	auto temppath = fs::temp_directory_path() / "temp.txt";
	ofstream fileout(temppath.native(),
	ios::out | ios::trunc);
	if (!fileout.is_open())
		throw runtime_error("cannot create temporary file");
	string line;
	
	while (getline(filein, line)) {
		if (line.length() > 0 && line.find_first_not_of(' ') != line.npos) {
			fileout << line << '\n';
		}
	}
	filein.close();
	fileout.close();
	fs::remove(filepath);
	fs::rename(temppath, filepath);
}