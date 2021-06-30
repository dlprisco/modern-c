// Average rating of movies

/* 

    The problem requires the computing of a movie rating using a truncated mean. This is a
  statistical measure of a central tendency where the mean is calculated after discarding parts
  of a probability distribution or sample at the high and low ends. Typically, this is done by
  removing an equal amount of points at the two ends. For this problem, you are required to
  remove 5% of both the highest and lowest user ratings.

*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

double truncated_mean(vector<int> values, double const percentage) {
	sort(begin(values), end(values));
	auto remove_count = static_cast<size_t>(values.size() * percentage + 0.5);
	values.erase(begin(values), begin(values) + remove_count);
	values.erase(end(values) - remove_count, end(values));
	auto total = accumulate(cbegin(values), cend(values),0ull,
		[](auto const sum, auto const e) {return sum + e; });
	return static_cast<double>(total) / values.size();
}

struct movie {
	int id;
	string title;
	vector<int> ratings;
};

void print_movie_ratings(vector<movie> const & movies) {
	for (auto const & m : movies) {
		cout << m.title << " : " << fixed << setprecision(1) << truncated_mean(m.ratings, 0.05) << endl;
	}
}

int main() {
    
	vector<movie> movies{
		{ 101, "The Matrix", {10, 9, 10, 9, 9, 8, 7, 10, 5, 9, 9, 8} },
		{ 102, "Gladiator", {10, 5, 7, 8, 9, 8, 9, 10, 10, 5, 9, 8, 10} },
		{ 103, "Interstellar", {10, 10, 10, 9, 3, 8, 8, 9, 6, 4, 7, 10} }
	};

	print_movie_ratings(movies);

	return 0;
}
