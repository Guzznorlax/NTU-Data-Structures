# NTU-Data-Structures

##### Table of Contents
**[Assignment_1](#hw_1)**<br>
**[Assignment_2](#hw_2)**<br>


## HW 1  <a name="hw_1"/>
NOTE: please save the source code of each problem in individual cpp files (as
specified) WITHOUT the function `main()`. All testing files that have the function
`main()` MUST be in separated files.

### CA1Prob1

1. (Save as `CA1Prob1.cpp`.) Write a short C++ program that takes two arrays a
and b of length n storing `integer` values, and returns the dot product of a and b.
That is, it computes an array c of length n such that `c[i] = a[i]·b[i]`, for `i = 0, …, n-1` and returns a scalar representing the dot product. The specification of the
function is as follows: `int dotProduct (int a[], int b[], int n);`
Please consider any possible inputs that causes errors and try to survive them.
A simple test with `a = [-1 0 2 15 7 6 -4 8 21 -13]` and `b = [5 9 -18 16 0 1 -4 18 -2 12]`
can be used to test your program initially. (20%)


### CA1Prob2

2. (Save as `CA1Prob2.cpp`.) Write a C++ function which takes a single integer
parameter p, and (a) outputs "p" if and only if the integer is a prime OR (b)
outputs its nearest prime numbers both smaller and larger than p: "ps and pl",
where ps and pl are p’s nearest primes smaller and larger than p, respectively.
To simplify the grading process, please follow exactly the specification as:
int* showPrime (int p);
In the returned integer array, set the array length equal to two. If p is actually a
prime, return it in the first element and set the second element 0. If p is not a
prime, return `[ps pl]` in the array. You may test your program with 5869, 3053
and 104395302. (20%)


### CA1Prob3

3. (Save as `CA1Prob3.cpp`.) Write a function that takes two positive long
integers, n and m, and returns true if and only if n is a multiple of m, that is, n=mi
for some integer i. (20%)
Please design the function using the following specification:
`bool isMultiple (long n, long m);`


### CA1Prob4

4. (Save as `CA1Prob4.cpp`.) Write a C++ class, `flower`, that has three member
variables of type `string`, `int`, and `double`, which respectively represent the `name`
of the flower, its number of `petals`, and `price`. Your class must include a
constructor method that initializes each variable to an appropriate value, and
your class should include functions for setting the value of each type, and getting
the value of each type. Here is the specification of this class:

```c++
class flower
{
private:
	string name;
	int petal;
	double price;

public:
	// Constructor.
	flower(string n, int pt, double pr);

	// Set the name of the flower.
	void setName(string n);

	// Set the petal number of the flower.
	void setPetal(int pt);

	// Set the price of the flower.
	void setPrice(double pr);

	// Return the name of the flower.
	string getName();

	// Return the petal number of the flower.
	int getPetal();

	// Return the price of the flower.
	double getPrice();
};
```

Please use the following flower data to test your program. (20%)

| Flower           | Petal | Price |
| ---------------- | :---: | ----: |
| Nodding Trillium |   3   |  75.0 |
| Nodding Trillium |   5   | 100.0 |
| Bluebell         |   6   |  85.0 |


### CA1Prob5

5. (Save as `CA1Prob5.cpp`.) Write a C++ class, `rectangle`, that has four member
variables of the same type double, which respectively represent the `width`, `length`,
`perimeter`, and `area`. Again, your class must include a constructor method that
initializes the width and length of the rectangle and computes the corresponding
perimeter and area subsequently. The specification of this class is described in
the following: (20%)

```c++
class rectangle
{
private:
	double width;
	double length;
	double perimeter;
	double area;

public:
	// Constructor, automatically compute the perimeter and area once it is OK.
	rectangle(double wd, double lg);

	// Set the dimension and automatically update the perimeter and area.
	void setDimension(double wd, double lg);

	// Set the width and automatically update the perimeter and area.
	void setWidth(double wd);

	// Set the length and automatically update the perimeter and area.
	void setLength(double lg);

	// Return the width of the rectangle.
	double getWidth();

	// Return the length of the rectangle.
	double getLength();

	// Return the perimeter of the rectangle.
	double getPerimeter();

	// Return the area of the rectangle.
	double getArea();

	// True, if width = length.
	bool isSquare();
};
```

## HW 2  <a name="hw_2"/>

This computer homework assignment is designed to help you to learn about building C++ classes and to observe the decomposition of a complicated task into simple subtasks. You have learned how to write some functions in CA1. Now, your task is to fill in the implementation of a class that manipulates dates, which is defined in a header file called “Date.h”. DO NOT use any of the built-in operations on dates provided in any C++ library in your solution. Fill in the private variables in “Date.h” and write your functional answers in a separate file called “Date.cpp”. The overall task is broken down into subtasks as stated as follows:

1. Implement the basic helper methods listed below.

```c++
/** Checks whether the given year is a leap year.
* @return true if and only if the input year is a leap year. * Grade: 10%
*/
public bool isLeapYear(int year) { ...
}

/** Returns the number of days in a given month.
* @param month is a month, numbered in the range 1...12.
* @param year is the year in question, with no digits omitted. * @return the number of days in the given month.
* Grade: 10%
*/
public int daysInMonth(int month, int year) { ...
}

/** Checks whether the given date is valid.
* @return true if and only if month/day/year constitute a valid date. *
* Years prior to A.D. 1 are NOT valid.
* Grade: 20%
*/
public bool isValidDate(int month, int day, int year) { ...
}
```

These methods are declared as `public` so we can test them from another class. Note that February contains 28 days most years, but 29 days during a leap year. A leap year is any year divisible by 4, except that a year divisible by 100 is not a leap year, except that a year divisible by 400 is a leap year after all. Hence, 1800 and 1900 are not leap years, but 1600 and 2000 are.

2. Define the internal state that a `Date` object needs to have by declaring some data fields (all `private`) within the Date class. Define the basic constructor specified below. A Date should be constructed only if the date is valid. If a caller attempts to construct an invalid date, the program should halt after printing an error message of your choosing. To halt the program, include the line: `exit(0)`;

```c++
/** Constructs a Date with the given month, day and year. If the date is
* not valid, the entire program will halt with an error message.
* @param month is a month, numbered in the range 1...12.
* @param day is between 1 and the number of days in the given month. * @param year is the year in question, with no digits omitted.
* Grade: 15%
*/
public Date(int month, int day, int year) {
...
}

/** Returns a string representation of this date in the form month/day/year. * The month, day, and year are printed in full as integers; for example,
* 10/17/2010 or 5/11/258.
* @return a string representation of this date.
* Grade: 20%
*/
public string toString() {
...
}
```

3. Implement the following methods.

```c++
/** Determines whether this Date is before the Date d. * @return true if and only if this Date is before d.
* Grade: 10%
*/
public bool isBefore(const Date& d) { ...
}

/** Determines whether this Date is after the Date d. * @return true if and only if this Date is after d.
* Grade: 10%
*/
public bool isAfter(const Date& d) { ...
}

/** Determines whether this Date is equal to the Date d. * @return true if and only if this Date is the same as d. * Grade: 10%
*/
public bool isEqual(const Date& d) { ...
}

/** Returns the number of this Date in the year.
* @return a number n in the range 1...366, inclusive, such that this Date * is the nth day of its year. (366 is only used for December 31 in a leap * year.)
* Grade: 15%
*/
public int dayInYear() { ...
}

/** Determines the difference in days between d and this Date. For example, * if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
* If this Date occurs before d, the result is negative.
* @return the difference in days between d and this Date.
* Grade: 10%
*/
public int difference(const Date& d) {
...
}
```

Hint: all the methods in the `Date` class can read all the `private` fields in `any` Date object (not just "this" `Date` object).


4. Implement the final missing piece of your class, a second constructor that takes a `string` argument.

```c++
/** Constructs a Date object corresponding to the given string.
* @param s should be a string of the form "month/day/year" where month must * be one or two digits, day must be one or two digits, and year must be
* between 1 and 4 digits. If s does not match these requirements or is not
* a valid date, the program halts with an error message of your choice.
* Grade: 30%
*/
public Date(const string& s) { ...
}
```

Your Date constructor definitely should not accept `11/31/2005` or `12/4` or `hey Jude`.
Hint: use the STL to familiarize yourself with all the methods available to you in the string class.


The files `Date.h` and `Date.cpp` contain a skeleton and `TestDate.cpp` provides some test code, for a `Date` class, respectively. We have included a `main` method in the `TestDate.cpp` that tests some of your methods. You are welcome to modify the main method as you please, perhaps to add further tests of your own. We will not grade the `main` method in this assignment. DO NOT change the prototype (interface) of any method. However, you may want to add some utilities to some functions to facilitate the coding.
