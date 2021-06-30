## Problems

**61. Parallel transform algorithm**
Write a general-purpose algorithm that applies a given unary function to transform the
elements of a range in parallel. The unary operation used to transform the range must not
invalidate range iterators or modify the elements of the range. The level of parallelism, that
is, the number of execution threads and the way it is achieved, is an implementation detail.

**62. Parallel min and max element algorithms
using threads**
Implement general-purpose parallel algorithms that find the minimum value
and, respectively, the maximum value in a given range. The parallelism should be
implemented using threads, although the number of concurrent threads is an
implementation detail.

**63. Parallel min and max element algorithms using asynchronous functions**
Implement general-purpose parallel algorithms that find the minimum value and,
respectively, the maximum value in a given range. The parallelism should be implemented
using asynchronous functions, although the number of concurrent functions is an
implementation detail.

**64. Parallel sort algorithm**
Write a parallel version of the sort algorithm as defined for problem 53. Sort Algorithm,
in Chapter 6, Algorithms and Data Structures, which, given a pair of random access iterators
to define its lower and upper bounds, sorts the elements of the range using the quicksort
algorithm. The function should use the comparison operators for comparing the elements
of the range. The level of parallelism and the way to achieve it is an implementation detail.

**65. Thread-safe logging to the console**
Write a class that enables components running in different threads to safely print log
messages to the console by synchronizing access to the standard output stream to
guarantee the integrity of the output. This logging component should have a method called
log() with a string argument representing the message to be printed to the console.

**66. Customer service system**
Write a program that simulates the way customers are served in an office. The office has
three desks where customers can be served at the same time. Customers can enter the office
at any time. They take a ticket with a service number from a ticketing machine and wait
until their number is next for service at one of the desks. Customers are served in the order
they entered the office, or more precisely, in the order given by their ticket. Every time a
service desk finishes serving a customer, the next customer in order is served. The
simulation should stop after a particular number of customers have been issued tickets and
served.