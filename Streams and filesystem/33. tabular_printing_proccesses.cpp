// Tabular printing of a list of processes

/*
	To solve this problem, we will consider the following class representing information about
  a process:

*/

enum class procstatus {
	suspended, 
	running
};

enum class platforms {
	p32bit, 
	p64bit
};

struct procinfo {
	int id;
	string name;
	procstatus status;
	string account;
	size_t memory;
	platforms platform;
};

string status_to_string(procstatus const status) {
	if (status == procstatus::suspended) return "suspended";
	else return "running";
}

string platform_to_string(platforms const platform) {
	if (platform == platforms::p32bit) return "32-bit";
	else return "64-bit";
}

void print_processes(vector<procinfo> processes)  {
	sort(begin(processes), end(processes), [](procinfo const & p1, procinfo const & p2) {return p1.name < p2.name; });

	for (auto const & pi : processes) {
		cout << left << setw(25) << setfill(' ') << pi.name;
		cout << left << setw(8) << setfill(' ') << pi.id;
		cout << left << setw(12) << setfill(' ') << status_to_string(pi.status);
		cout << left << setw(15) << setfill(' ') << pi.account;
		cout << right << setw(10) << setfill(' ') << (int)(pi.memory/1024);
		cout << left << ' ' << platform_to_string(pi.platform);
		cout << endl;
	}
}

/*

	The following program defines a list of processes (you can actually retrieve the list of
  running processes using operating system-specific APIs) and prints it to the console in the
  requested format:

*/

int main() {
	using namespace string_literals;
	vector<procinfo> processes {
		{512, "cmd.exe"s, procstatus::running, "SYSTEM"s,148293, platforms::p64bit },
		{1044, "chrome.exe"s, procstatus::running, "marius.bancila"s, 25180454, platforms::p32bit},
		{7108, "explorer.exe"s, procstatus::running, "marius.bancila"s, 2952943, platforms::p64bit },
		{10100, "chrome.exe"s, procstatus::running, "marius.bancila"s, 227756123, platforms::p32bit},
		{22456, "skype.exe"s, procstatus::suspended, "marius.bancila"s, 16870123, platforms::p64bit },
	};

	print_processes(processes);

	return 0;
}