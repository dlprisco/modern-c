// Minimum function (any arguments)

/*

	It is possible to write function templates that can take a variable number of 
  arguments using variadic function templates. For this, we need to implement compile-time 
  recursion (which is actually just calls through a set of overloaded functions). 

  	The following snippet shows how the requested function could be implemented:

*/

template <class Compare, typename T>
T minimumc(Compare comp, T const a, T const b) { 
	return comp(a, b) ? a : b; 
}

template <class Compare, typename T1, typename... T>
T1 minimumc(Compare comp, T1 a, T... args) {
	return minimumc(comp, a, minimumc(comp, args...));
}

int main() {
	auto y = minimumc(std::less<>(), 3, 2, 1, 0);
	return 0;
}