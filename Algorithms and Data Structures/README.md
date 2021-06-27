## Problems

**45. Priority queue**
Write a data structure that represents a priority queue that provides constant time lookup for the largest element, but has logarithmic time complexity for adding and removing elements. A queue inserts new elements at the end and removes elements from the top. By default, the queue should use operator< to compare elements, but it should be possible for the user to provide a comparison function object that returns true if the first argument is less than the second. The implementation must provide at least the following operations:


```push()```    *to add a new element*
```pop()```     *to remove the top element*
```top()```     *to provide access to the top element*
```size()```    *to indicate the number of elements in the queue*
```empty()```   *to indicate whether the queue is empty*


**46. Circular buffer**
Create a data structure that represents a circular buffer of a fixed size. A circular buffer overwrites existing elements when the buffer is being filled beyond its fixed size. The class you must write should:

* Prohibit default construction
* Support the creation of objects with a specified size
* Allow checking of the buffer capacity and status
(*empty(), full(), size(), capacity()*)
* Add a new element, an operation that could potentially overwrite the oldest element in the buffer
* Remove the oldest element from the buffer
* Support iteration through its elements

**47. Double buffer**
Write a class that represents a buffer that could be written and read at the same time
without the two operations colliding. A read operation must provide access to the old data while a write operation is in progress. Newly written data must be available for reading upon completion of the write operation.

**48. The most frequent element in a range**
Write a function that, given a range, returns the most frequent element and the number of times it appears in the range. If more than one element appears the same maximum number of times then the function should return all the elements. For instance, for the range ```{1,1,3,5,8,13,3,5,8,8,5}```, it should return ```{5, 3}``` and ```{8, 3}```.

**49. Text histogram**
Write a program that, given a text, determines and prints a histogram with the frequency of each letter of the alphabet. The frequency is the percentage of the number of appearances of each letter from the total count of letters. The program should count only the appearances of letters and ignore digits, signs, and other possible characters. The frequency must be determined based on the count of letters and not the text size.

**50. Filtering a list of phone numbers**
Write a function that, given a list of phone numbers, returns only the numbers that are from a specified country. The country is indicated by its phone country code, such as 44 for Great Britain. Phone numbers may start with the country code, a + followed by the country code, or have no country code. The ones from this last category must be ignored.

**51. Transforming a list of phone numbers**
Write a function that, given a list of phone numbers, transforms them so they all start with a specified phone country code, preceded by the + sign. Any whitespaces from a phone number should also be removed. The following is a list of input and output examples:
```

07555 123456     =>  +447555123456
07555123456      =>  +447555123456
+44 7555 123456  =>  +447555123456
44 7555 123456   =>  +447555123456
7555 123456      =>  +447555123456

```


**52. Generating all the permutations of a string**
Write a function that, prints on the console all the possible permutations of a given string. You should provide two versions of this function: one that uses recursion, and one that does not.

**53. Average rating of movies**
Write a program that calculates and prints the average rating of a list of movies. Each
movie has a list of ratings from 1 to 10 (where 1 is the lowest and 10 is the highest rating). In order to compute the rating, you must remove 5% of the highest and lowest ratings before computing their average. The result must be displayed with a single decimal point.

**54. Pairwise algorithm**
Write a general-purpose function that, given a range, returns a new range with pairs of
consecutive elements from the input range. Should the input range have an odd number of
elements, the last one must be ignored. For example, if the input range was 
```{1, 1, 3, 5, 8, 13, 21}```, the result must be ```{ {1, 1}, {3, 5}, {8, 13} }```.


**55. Zip algorithm**
Write a function that, given two ranges, returns a new range with pairs of elements from the two ranges. Should the two ranges have different sizes, the result must contain as many elements as the smallest of the input ranges. For example, if the input ranges were ```{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }``` and ```{ 1, 1, 3, 5, 8, 13, 21 }```, the result should be ```{{1,1}, {2,1}, {3,3}, {4,5}, {5,8}, {6,13}, {7,21}}```.

**56. Select algorithm**
Write a function that, given a range of values and a projection function, transforms each value into a new one and returns a new range with the selected values. For instance, if you have a type book that has an id, title, and author, and have a range of such book values, it should be possible for the function to select only the title of the books. Here is an example of how the function should be used:
```
struct book
{
    int id;
    std::string title;
    std::string author;
};

std::vector<book> books{
    {101, "The C++ Programming Language", "Bjarne Stroustrup"},
    {203, "Effective Modern C++", "Scott Meyers"},
    {404, "The Modern C++ Programming Cookbook", "Marius Bancila"}};
    auto titles = select(books, [](book const & b) {return b.title; });

```


**57. Sort algorithm**
Write a function that, given a pair of random-access iterators to define its lower and upper bounds, sorts the elements of the range using the quicksort algorithm. There should be two overloads of the sort function: one that uses ```operator<``` to compare the elements of the range and put them in ascending order, and one that uses a user-defined binary comparison function for comparing the elements.

**58. The shortest path between nodes**
Write a program that, given a network of nodes and the distances between them, computes
and displays the shortest distance from a specified node to all the others, as well as the path
between the start and end node. As input, consider the following undirected graph:
[graph]!(/utils/graph.png)

The program output for this graph should be the following:
```
A  ->  A  :  0 A
A  ->  B  :  7 A   ->  B
A  ->  C  :  9 A   ->  C
A  ->  D  :  20 A  ->  C  ->  D
A  ->  E  :  20 A  ->  C  ->  F  ->  E
A  ->  F  :  11 A  ->  C  ->  F

```

**59. The Weasel program**
Write a program that implements Richard Dawkins' weasel computer simulation, described
in Dawkins' words as follows (The Blind Watchmaker, chapter 3):

    * We again use our computer monkey, but with a crucial difference in its program. It again
    begins by choosing a random sequence of 28 letters, just as before ... it duplicates it
    repeatedly, but with a certain chance of random error – 'mutation' – in the copying. The
    computer examines the mutant nonsense phrases, the 'progeny' of the original phrase, and
    chooses the one which, however slightly, most resembles the target phrase, METHINKS IT IS LIKE A WEASEL. *

**60. The Game of Life**
Write a program that implements the Game of Life cellular automaton proposed by John
Horton Conway. The universe of this game is a grid of square cells that could have one of two states: dead or alive. Every cell interacts with its adjacent neighbors, with the following transactions occurring on every step:

* Any live cell with fewer than two live neighbors dies, as if caused by underpopulation
* Any live cell with two or three live neighbors lives on to the next generation
* Any live cell with more than three live neighbors dies, as if by overpopulation
* Any dead cell with exactly three live neighbors becomes a live cell, as if by
reproduction

The status of the game on each iteration should be displayed on the console, and for
convenience, you should pick a reasonable size, such as *20* rows x *50* columns.