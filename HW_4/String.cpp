/**
 *  A class that stores a string and generates a hash code for it.
 *
 **/

#include "String.h"
#include<iostream>
using namespace std;
/**
 *  Construct a new String with the given variable.
 *  @param str the string by which the String stores.
 */
String::String(const string& str) {
	this->str = str;
}

/**
 *  Get the value of the string variable.
 *  @return the stored value.
 */
string String::getvalue() const {
	return str;
}

/**
 *  Returns true if "this" String and "strg" have identical values.
 *  @param strg is the second String.
 *  @return true if the string values are equal, false otherwise.
 */
bool String::equals(const String& strg) {
	for (int i = 0; (size_t)i < str.length(); i++)
	{
		string str1;
		str1 = strg.getvalue();
		if (str[i] != str1[i])
		{
			return false;
		}
	}
	return true;
}

/**
 *  Returns a hash code for this String.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int String::hashCode() {
	int value = 0;
	for (int i = 0; (size_t)i < str.length(); i++)
	{
		value = (127 * value + str[i]) % 16908799;       //hashcode
	}
	return value;
}
