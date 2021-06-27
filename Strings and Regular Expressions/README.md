## Problems

**23. Binary to string conversion**
Write a function that, given a range of 8-bit integers (such as an array or vector), returns a string that contains a hexadecimal representation of the input data. The function should be able to produce both uppercase and lowercase content. Here are some input and output
examples:
```

Input: { 0xBA, 0xAD, 0xF0, 0x0D }, output: "BAADF00D" or "baadf00d"
Input: { 1,2,3,4,5,6 }, output: "010203040506"

```
**24. String to binary conversion**
Write a function that, given a string containing hexadecimal digits as the input argument, returns a vector of 8-bit integers that represent the numerical deserialization of the string content. The following are examples:
```

Input: "BAADF00D" or "baadF00D", output: {0xBA, 0xAD, 0xF0, 0x0D}
Input "010203040506", output: {1, 2, 3, 4, 5, 6}

```

**25. Capitalizing an article title**
Write a function that transforms an input text into a capitalized version, where every word starts with an uppercase letter and has all the other letters in lowercase. For instance, the text ```the c++ challenger``` should be transformed to *The C++ Challenger*.

**26. Joining strings together separated by a delimiter**
Write a function that, given a list of strings and a delimiter, creates a new string by
concatenating all the input strings separated with the specified delimiter. The delimiter must not appear after the last string, and when no input string is provided, the function must return an empty string.

Example: 

``` 

input { "this","is","an","example" } and delimiter ' ' (space), output: "this is an example".

```
**27. Splitting a string into tokens with a list of possible delimiters**
Write a function that, given a string and a list of possible delimiter characters, splits the string into tokens separated by any of the delimiters and returns them in an *std::vector*.

```

Example: input: "this,is.a sample!!" with delimiters ",.! ", output: {"this",
"is", "a", "sample"}.

```

**28. Longest palindromic substring**
Write a function that, given an input string, locates and returns the longest sequence in the string that is a palindrome. If multiple palindromes of the same length exist, the first one should be returned.

**29. License plate validation**
Considering license plates with the format *LLL-LL DDD* or *LLL-LL DDDD* (where **L** is an uppercase letter from A to Z and D is a digit), write:

		* One function that validates that a license plate number is of the correct format.

		* One function that, given an input text, extracts and returns all the license plate numbers found in the text

**30. Extracting URL parts**
Write a function that, given a string that represents a *URL*, parses and extracts the parts of the URL (protocol, domain, port, path, query, and fragment).

**31. Transforming dates in strings**
Write a function that, given a text containing dates in the format *dd.mm.yyyy* or *dd-mmyyyy*, transforms the text so that it contains dates in the format *yyyy-mm-dd*


