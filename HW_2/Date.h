/**
 *  Date class declaration
 *
 *  @author 游子霆
 *  @ID B07505051
 *  @Department Engineering Science and Ocean Engineering
 *  @Affiliation National Taiwan University
 *
 * Date.h
 * version 1.0
 */

#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int month, int day, int year);
	Date(const string &s);
	bool isLeapYear(int year);
	int daysInMonth(int month, int year);
	bool isValidDate(int month, int day, int year);
	string toString();
	bool isBefore(const Date &d);
	bool isAfter(const Date &d);
	bool isEqual(const Date &d);
	int dayInYear();
	int difference(const Date &d);
};

#endif
