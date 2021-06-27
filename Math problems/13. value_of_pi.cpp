// Computing the value of Pi.

/*
	A suitable solution for approximately determining the value of Pi is using a Monte Carlo
  simulation. This is a method that uses random samples of inputs to explore the behavior of
  complex processes or systems. The method is used in a large variety of applications and
  domains, including physics, engineering, computing, finance, business, and others.

    To do this we will rely on the following idea: the area of a circle with diameter d is PI *
  d^2 / 4. The area of a square that has the length of its sides equal to d is d^2. If we divide
  the two we get PI/4. If we put the circle inside the square and generate random numbers
  uniformly distributed within the square, then the count of numbers in the circle should be
  directly proportional to the circle area, and the count of numbers inside the square should
  be directly proportional to the square’s area. That means that dividing the total number of
  hits in the square and circle should give PI/4. The more points generated, the more
  accurate the result shall be.

	For generating pseudo-random numbers we will use a Mersenne twister and a uniform
  statistical distribution

*/

using namespace std;

template <typename E = std::mt19937, typename D = std::uniform_real_distribution<>> double compute_pi(E& engine, D& dist, int const samples = 1000000) {
    auto hit = 0;
    for (auto i = 0; i < samples; i++) {
    	
    	auto x = dist(engine);
    	auto y = dist(engine);
    	if (y <= std::sqrt(1 - std::pow(x, 2))) hit += 1;
    }

    return 4.0 * hit / samples;
}


int main() {

	random_decive rd;
	auto seed_data = array<int, mt19937::state_size> {};
	generate(begin(seed_data), end(seed_data), ref(rd));

	seed_seq seq(begin(seed_data), end(seed_data));
	auto eng = mt19937{ seq };
	auto dist = uniform_real_distribution<>{ 0, 1 };

	for (auto j = 0; j < 10; j++) {
		cout << compute_pi(eng, dist) << endl;
	}

	return 0;
}
