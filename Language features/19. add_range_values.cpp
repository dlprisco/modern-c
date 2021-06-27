// Adding a range of values to a sequence or container

/*
	Writing functions with any number of arguments is possible using variadic function
  templates. The function should have the container as the first parameter, followed by a
  variable number of arguments representing the values to be added at the back of the
  container. However, writing such a function template can be significantly simplified using
  fold expressions. Such an implementation is shown here:

*/

template<typename C, typename... Args>
void push_back(C& c, Args&&... args) {
	(c.push_back(args), ...);
}

int main() {

	vector<int> v;
	push_back(v, 1, 2, 3, 4);
	copy(std::begin(v), std::end(v), ostream_iterator<int>(std::cout, " "));

	list<int> l;
	push_back(l, 1, 2, 3, 4);
	copy(std::begin(l), std::end(l), ostream_iterator<int>(std::cout, " "));

	return 0;
}