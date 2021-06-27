// The Weasel program

/*
	The Weasel program is a thought experiment proposed by Richard Dawkins, intended to
  demonstrate how the accumulated small improvements (mutations that bring a benefit to
  the individual so that it is chosen by natural selection) produce fast results as opposed to
  the mainstream misinterpretation that evolution happens in big leaps. The algorithm for the
  Weasel simulation, as described on Wikipedia (see https:/ / en. wikipedia. org/ wiki/
  Weasel_ program), is as follows:

*/

using namespace std;

class weasel {
	string target;
	uniform_int_distribution<> chardist;
	uniform_real_distribution<> ratedist;
	mt19937 mt;
	string const allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
public:
	weasel(string_view t) : target(t), chardist(0, 26), ratedist(0, 100) {
		random_device rd;
		auto seed_data = array<int, mt19937::state_size> {};
		generate(begin(seed_data), end(seed_data),ref(rd));
		seed_seq seq(begin(seed_data), end(seed_data));
		mt.seed(seq);
	}
	void run(int const copies) {
		auto parent = make_random();
		int step = 1;
		cout << left << setw(5) << setfill(' ') << step << parent << endl;
		do {
			vector<string> children;
			generate_n(back_inserter(children), copies, [parent, this]() {return mutate(parent, 5); });
			parent = *max_element(begin(children), end(children), [this](string_view c1, string_view c2) {return fitness(c1) < fitness(c2); });
			cout << setw(5) << setfill(' ') << step << parent << endl;
			step++;
		} while (parent != target);
	}

private:
	weasel() = delete;
	double fitness(string_view candidate) const {
		int score = 0;
		for (size_t i = 0; i < candidate.size(); ++i) {
			if (candidate[i] == target[i])
				score++;
		}	
	return score;
	}

	string mutate(string_view parent, double const rate) {
		stringstream sstr;
		for (auto const c : parent)	{ 
			auto nc = ratedist(mt) > rate ? c : allowed_chars[chardist(mt)];
			sstr << nc;
		}
	return sstr.str();
	}	

	string make_random() {
		stringstream sstr;
		for (size_t i = 0; i < target.size(); ++i) {
			sstr << allowed_chars[chardist(mt)];
		}
		return sstr.str();
	}
};

int main() {
	weasel w("METHINKS IT IS LIKE A WEASEL");
	w.run(100);


	weasel w("Heeeeelllo world!!!");
	w.run(185);

	return 0;
}