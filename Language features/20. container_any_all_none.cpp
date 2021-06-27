// Container any, all, none

/*

	The requirement to be able to check the presence or absence of a variable number of
 arguments suggests that we should write variadic function templates. However, these
 functions require a helper function, a general-purpose one that checks whether an element
 is found in a container or not and returns a bool to indicate success or failure. Since all
 these functions, which we could call contains_all, contains_any, and contains_none,
 do is apply logical operators on the results returned by the helper function, we would use
 fold expressions to simplify the code. Short circuit evaluation is enabled after the expansion
 of the fold expression, which means we are evaluating only the elements that lead to a
 definitive result. So if we are looking for the presence of all 1, 2, and 3, and 2 is missing, the
 function will return after looking up value 2 in the container without checking value 3:

*/


template<class C, class T>
bool contains(C const & c, T const & value) {
	return std::end(c) != std::find(std::begin(c), std::end(c), value);
}

template<class C, class... T>
bool contains_any(C const & c, T &&... value) {
	return (... || contains(c, value));
}

template<class C, class... T>
bool contains_all(C const & c, T &&... value) {
	return (... && contains(c, value));
}

template<class C, class... T>
bool contains_none(C const & c, T &&... value) {
	return !contains_any(c, std::forward<T>(value)...);
}
