/**
 *  Implementation of class Date.
 *
 *  @author 游子霆
 *  @ID B07505051
 *  @Department Engineering Science and Ocean Engineering
 *  @Affiliation National Taiwan University
 *
 *  Date.cpp
 *  version 1.0
 */

#include <string>
#include <sstream>
#include "Date.h"

Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
}

/**
 *  Constructs a Date with the given month, day and year.   If the date is
 *  not valid, the entire program will halt with an error message.
 *  @param month is a month, numbered in the range 1...12.
 *  @param day is between 1 and the number of days in the given month.
 *  @param year is the year in question, with no digits omitted.
 *
 *  Grade: 15%
 */
Date::Date(int month, int day, int year)
{
	if (isValidDate(month, day, year))
	{ //construct a Date with the given year month and day
		this->month = month;
		this->day = day;
		this->year = year;
	}
	else
	{
		cout << "error message" << endl; //return error when it is not valid and halt program
		exit(0);
	}
}

/**
 *  Constructs a Date object corresponding to the given string.
 *  @param s should be a string of the form "month/day/year" where month must
 *  be one or two digits, day must be one or two digits, and year must be
 *  between 1 and 4 digits.  If s does not match these requirements or is not
 *  a valid date, the program halts with an error message.
 *
 *  Grade: 30%
 */
Date::Date(const string &s)
{
	string tmp_str;
	string str_list[3];
	stringstream stream(s);

	int i = 0;

	// Get strings between slashes
	while (getline(stream, tmp_str, '/'))
	{
		// Checks if the raw string is of the correct form
		if (i < 3)
		{
			str_list[i] = tmp_str;
		}
		else
		{
			cout << "[ERROR] Invalid input format." << endl;
			exit(0);
		}

		i++;
	}

	if (str_list[0].length() > 2)
	{
		cout << "[ERROR] Invalid month format." << endl;
		exit(0);
	}

	if (str_list[1].length() > 2)
	{
		cout << "[ERROR] Invalid day format." << endl;
		exit(0);
	}

	if ((str_list[2].length() > 4) || (str_list[2].length() < 1))
	{
		cout << "[ERROR] Invalid year format." << endl;
		exit(0);
	}

	if ((str_list[0].length() + str_list[1].length() + str_list[2].length()) < 1)
	{
		cout << "[ERROR] Invalid input string." << endl;
		exit(0);
	}

	try // Tries to convert string to int
	{
		month = stoi(str_list[0]);
		day = stoi(str_list[1]);
		year = stoi(str_list[2]);

		if (!isValidDate(month, day, year))
		{
			cout << "[ERROR] Invalid date supplied." << endl;
			exit(0);
		}
	}
	catch (...) // If any string is unconvertible, print error message then exit.
	{
		cout << "[ERROR] The input string must only contains integers and slashes." << endl;
		exit(0);
	}
}

/**
 *  Checks whether the given year is a leap year.
 *  @return true if and only if the input year is a leap year.
 *
 *  Grade: 10%
 */
bool Date::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0))
	{
		return true;
	}

	return false;
}

/**
 *  Returns the number of days in a given month.
 *  @param month is a month, numbered in the range 1...12.
 *  @param year is the year in question, with no digits omitted.
 *  @return the number of days in the given month.
 *
 *  Grade: 10%
 */
int Date::daysInMonth(int month, int year)
{
	// Months have 31 days
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
	{
		return 31;
	}
	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) // Months have 30 days
	{
		return 30;
	}
	else if (month == 2 && isLeapYear(year)) // February has 29 days in leap years
	{
		return 29;
	}
	else
	{
		return 28; // February has 28 days in regular years
	}
}

/**
 *  Checks whether the given date is valid.
 *  @return true if and only if month/day/year constitute a valid date.
 *
 *  Years prior to A.D. 1 are NOT valid.
 *
 *  Grade: 20%
 */
bool Date::isValidDate(int month, int day, int year)
{
	/** Limitations for date:
	 * 1 <= year
	 * 1 <= month <= 12
	 * 1 <= day <= daysInMonth
	 */

	if ((year < 1) || (month < 1) || (month > 12) || (day < 1))
	{
		return false;
	}
	else if (day > daysInMonth(month, year))
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**
 *  Returns a string representation of this Date in the form month/day/year.
 *  The month, day, and year are expressed in full as integers; for example,
 *  10/17/2010 or 5/11/258.
 *  @return a String representation of this Date.
 *
 *  Grade: 20%
 */
string Date::toString()
{
	string str_date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	return str_date;
}

/**
 *  Determines whether this Date is before the Date d.
 *  @return true if and only if this Date is before d.
 *
 *  Grade: 10%
 */
bool Date::isBefore(const Date &d)
{ //see if the Date is before d
	if (year < d.year)
	{
		return true;
	}
	else if (year == d.year)
	{
		if (month < d.month)
		{
			return true;
		}
		else if (month == d.month)
		{
			if (day < d.day)
			{
				return true;
			}
		}
	}

	return false;
}

/**
 *  Determines whether this Date is after the Date d.
 *  @return true if and only if this Date is after d.
 *
 *  Grade: 10%
 */
bool Date::isAfter(const Date &d)
{
	if (year > d.year)
	{
		return true;
	}
	else if (year == d.year)
	{
		if (month > d.month)
		{
			return true;
		}
		else if (month == d.month)
		{
			if (day > d.day)
			{
				return true;
			}
		}
	}

	return false;
}

/**
 *  Determines whether this Date is equal to the Date d.
 *  @return true if and only if this Date is the same as d.
 *
 *  Grade: 10%
 */
bool Date::isEqual(const Date &d)
{
	if ((year == d.year) && (month == d.month) && (day == d.day))
	{
		return true;
	}

	return false;
}

/**
 *  Returns the number of this Date in the year.
 *  @return a number n in the range 1...366, inclusive, such that this Date
 *  is the nth day of its year.  (366 is only used for December 31 in a leap
 *  year.)
 *
 *  Grade: 15%
 */
int Date::dayInYear()
{
	int sum = 0;

	// Sums up every day in months prior to this month.
	for (int n = 1; n < month; n++)
	{
		sum += daysInMonth(n, year);
	}

	sum += day;

	return sum;
}

/** Determines the difference in days between d and this Date.  For example,
 *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
 *  If this Date occurs before d, the result is negative.
 *  @return the difference in days between d and this Date.
 *
 *  Grade: 10%
 */
int Date::difference(const Date &d)
{
	int diff = 0;

	Date tmp_date;

	// Case when Date d is prior to this date.
	if (year > d.year)
	{
		for (int y = d.year; y < year; y++)
		{
			tmp_date = Date(12, 31, y);
			diff += tmp_date.dayInYear();
		}

		tmp_date = Date(d.month, d.day, d.year);

		diff += (this->dayInYear()) - tmp_date.dayInYear();
	}
	else if (year < d.year)
	{
		for (int y = year; y < d.year; y++)
		{
			tmp_date = Date(12, 31, y);
			diff -= tmp_date.dayInYear();
		}

		tmp_date = Date(d.month, d.day, d.year);

		diff += (this->dayInYear()) - tmp_date.dayInYear();
	}
	else
	{
		tmp_date = Date(d.month, d.day, d.year);
		diff += (this->dayInYear()) - tmp_date.dayInYear();
	}
	return diff;
}
