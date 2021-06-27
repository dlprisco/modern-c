// Computing directory size

/*

   To compute the size of a directory, we have to iterate through all the files and sum the size
  of individual files.
  
  	filesystem::recursive_directory_iterator is an iterator from the filesystem
 	library that allows iterating all the entries of a directory in a recursive manner. It has
  	various constructors, some of them taking a value of the type
  
  	filesystem::directory_options that indicates whether symbolic links should be
  	followed or not. The general purpose accumulate() algorithm can be used to sum
  	together the file sizes. Since the total size of a directory could exceed 2 GB, you should not
  	use int or long, but unsigned long long for the sum type. The following function
  	shows a possible implementation for the required task

*/

using namespace std;

namespace fs = experimental::filesystem;

uintmax_t get_directory_size(fs::path const & dir, bool const follow_symlinks = false) {
	auto iterator = fs::recursive_directory_iterator(dir, follow_symlinks ? fs::directory_options::follow_directory_symlink : fs::directory_options::none);
	return accumulate(fs::begin(iterator), fs::end(iterator), 0ull, 
		[](uintmax_t const total, fs::directory_entry const & entry) { 
			return total + (fs::is_regular_file(entry) ? fs::file_size(entry.path()) : 0); 
	})
}


int main() {
	string path;
	cout << "Path: ";

	cin >> path;
	cout << "Size: " << get_directory_size(path) << endl;

	return 0;
}