## Problems

**15. IPv4 data type**
Write a class that represents an IPv4 address. Implement the functions required to be able to read and write such addresses from or to the console. The user should be able to input values in dotted form, such as 127.0.0.1 or 168.192.0.100. This is also the form in which IPv4 addresses should be formatted to an output stream.

**16. Enumerating IPv4 addresses in a range**
Write a program that allows the user to input two IPv4 addresses representing a range and list all the addresses in that range. Extend the structure defined for the previous problem to implement the requested functionality.

**17. Creating a 2D array with basic operations**
Write a class template that represents a two-dimensional array container with methods for element access (at() and data()), capacity querying, iterators, filling, and swapping. It should be possible to move objects of this type.

**18. Minimum function with any number of arguments**
Write a function template that can take any number of arguments and returns the
minimum value of them all, using operator *<* for comparison. Write a variant of this
function template that can be parameterized with a binary comparison function to use
instead of ```operator``` *<*.

**19. Adding a range of values to a container**
Write a general-purpose function that can add any number of elements to the end of a
container that has a method ```push_back(T&& value)```.

***20. Container any, all, none***
Write a set of general-purpose functions that enable checking whether any, all, or none of the specified arguments are present in a given container. These functions should make it possible to write code as follows:

```
	std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
	assert(contains_any(v, 0, 3, 30));

	std::array<int, 6> a{ { 1, 2, 3, 4, 5, 6 } };
	assert(contains_all(a, 1, 3, 5, 6));

	std::list<int> l{ 1, 2, 3, 4, 5, 6 };
	assert(!contains_none(l, 0, 6));

```

**21. System handle wrapper**
Consider an operating system handle, such as a file handle. Write a wrapper that handles the acquisition and release of the handle, as well as other operations such as verifying the validity of the handle and moving handle ownership from one object to another.

**22. Literals of various temperature scales**
Write a small library that enables expressing temperatures in the three most used scales, Celsius, Fahrenheit, and Kelvin, and converting between them. The library must enable you to write temperature literals in all these scales, such as ```36.5_deg``` for Celsius, ```97.7_f``` for Fahrenheit, and ```309.65_K``` for Kelvin; perform operations with these values; and convert between them.


