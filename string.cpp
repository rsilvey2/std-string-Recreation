#include <iostream>
#include <ostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "string.hpp"

String::String() {                                         //Empty string
	stringSize = 1;
	str = new char[stringSize];
	str[0] = '\0';
}

String::String(const char ch) {					           //String('x')
	stringSize = 2;
	str = new char[stringSize];
	str[0] = ch;
	str[1] = '\0';
}

String::String(const char ch[]) {				           //String("abcd")
	int i = 0;
	while (ch[i] != '\0') {
		i++;
	}
	stringSize = i + 1;
	str = new char[stringSize];
	for (int j = 0; j < stringSize - 1; j++) {
		str[j] = ch[j];
	}
	str[i] = '\0';
}

String::String(const String& str2) {                       //Copy Constructor
	stringSize = str2.stringSize;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; i++) {
		str[i] = str2.str[i];
	}
}

String::String(int n) {                                    //String(10) - capacity 10, empty string
	stringSize = n + 1;
	str = new char[stringSize];
	str[n] = '\0';
}

String::String(int n, const char ch[]) : String(n) {       //String(10, "abc") - capacity 10 with "abc"
	int ch_leng = 0;
	while (ch[ch_leng] != '\0')
		++ch_leng;
	for (int i = 0; i <= ch_leng; ++i)
		str[i] = ch[i];
}

String::~String() {                                        //Destructor
	delete[] str;
}

void String::swap(String& str2) {                          //Constant time swap
	char* swapper = str;
	int swapperSize = stringSize;

	str = str2.str;
	stringSize = str2.stringSize;

	str2.str = swapper;
	str2.stringSize = swapperSize;
}

String& String::operator=(String rhs) {                    //Assignment Copy
	swap(rhs);
	return *this;
}

char& String::operator[](int i) {					       //Accessor/Modifier
	return str[i];
}

char String::operator[](int i) const {				       //Accessor
	return str[i];
}

int String::capacity() const {					           //Max chars that can be stored (not including null terminator)
	return stringSize - 1;
}

int String::length() const {						       //Number of char in string
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

String String::substr(int start, int end) const {          //returns the sub string from start to end position (inclusive)
	if (start < 0) {
		start = 0;
	}
	if (end > length()) {
		end = length() - 1;
	}
	String substr(end - start + 1);
	int i = start;
	for (i; i <= end; i++) {
		substr[i - start] = str[i];
	}
	substr[i - start] = '\0';
	return substr;
}

int String::findch(int pos, char ch) const {               //returns location of ch at or after pos, returns - 1 if not found
	if (pos < 0) {
		pos = 0;
	}
	for (pos; pos <= length(); pos++) {
		if (str[pos] == ch) {
			return pos;
		}
	}
	return -1;
}

int String::findstr(int pos, const String& str) const {    //returns the location of str at or after pos, returns - 1 if not found.
	if (pos < 0) {
		pos = 0;
	}
	for (pos; pos <= length(); pos++) {
		if (substr(pos, pos + str.length() - 1) == str) {
			return pos;
		}
	}
	return -1;
}

int String::strToInt() const {
	if (str[0] == '-') {
		return 0;
	}
	int result = 0, start = length() - 1;
	char temp;
	for (int i = 0; i < length(); ++i) {
		temp = str[i];
		result += ((temp - '0') * pow(10, (start - i)));
	}
	return result;
}

String String::operator+(const String& rhs) const {        //operator for addition String and String
	String result(capacity() + rhs.capacity(), str);
	int offset = length();
	for (int i = 0; i <= rhs.length(); ++i) {
		result[offset + i] = rhs.str[i];
	}
	return result;
}


String operator+(const char ch[], const String& rhs) {     //operator for addition charArray and String
	String result(ch);
	return (result + rhs);
}

String operator+(char ch, const String& rhs) {             //operator for addition char and String
	String result(ch);
	return (result + rhs);
}

String& String::operator+=(const String& rhs) {            //operator += String and String
	*this = *this + rhs;
	return *this;
}

bool String::operator==(const String& rhs) const {         //operator == String and String
	if (length() != rhs.length()) {
		return false;
	}
	for (int i = 0; i < length(); ++i) {
		if (str[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}

bool operator==(const char ch[], const String& rhs) {      //operator == charArray and String
	return(String(ch) == rhs);
}

bool operator==(char ch, const String& rhs) {              //operator == char and String
	return(String(ch) == rhs);
}

bool String::operator<(const String& rhs) const {          //operator less than String and String
	if (length() < rhs.length()) { 
		for (int i = 0; i < length(); ++i) {
			if (str[i] > rhs[i])
				return false;
		}
		return true;
	}
	else {
		for (int i = 0; i < rhs.length(); ++i) {
			if (str[i] < rhs[i])
				return true;
		}
		return false;
	}
}

bool operator<(const char ch[], const String& rhs) {       //operator less than charArray and String
	return(String(ch) < rhs);
}

bool operator<(char ch, const String& rhs) {               //operator less than char and String
	return(String(ch) < rhs);
}

bool operator<=(const String& lhs, const String& rhs) {    //operator less than or equal to String and String
	return((lhs < rhs) || (lhs == rhs));
}


bool operator!=(const String& lhs, const String& rhs) {    //operator does not equal String and String
	if (lhs.length() != rhs.length()) {
		return true;
	}
	for (int i = 0; i < lhs.length(); ++i) {
		if (lhs[i] != rhs[i]) {
			return true;
		}
	}
	return false;
}

bool operator>=(const String& lhs, const String& rhs) {    //operator greater than or equal to String and String
	return ((rhs < lhs) || (lhs == rhs));
}

bool operator>(const String& lhs, const String& rhs) {     //operator greater than String and String
	return (rhs < lhs);
}

void String::resetCapacity(int N) {                        //Resets capacity to N, keeps string intact
	char* tempArr = new char[N + 1];
	int i = 0;
	while (str[i] != 0) {
		tempArr[i] = str[i];
		i++;
	}
	tempArr[i] = '\0';
	stringSize = N + 1;
	delete[] str;
	str = tempArr;
}

std::istream& operator>>(std::istream& in, String& rhs) {          //Input function
	char ch;
	in.get(ch);

	rhs = String();

	while (ch != '\0' && !in.eof() && ch != '\n' && ch != ' ') {
		rhs += ch;
		in.get(ch);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {     //Output function
	out << rhs.str;
	return out;
}

std::vector<String> String::split(char ch) const {         //This method will return a vector of String split up based on a supplied character.
	int i = 0;
	int back = 0;
	std::vector<String> result;
	if (str[0] == ch) {
		result.push_back(String());
	}
	else {
		back = 0;
	}
	while (i < length() - 1) {
		if (str[i] == ch && str[i + 1] != ch) {
			back = i + 1;
		}
		if (str[i] != ch && str[i + 1] == ch) {
			result.push_back(substr(back,i));
		}
		if (str[i] == ch && str[i + 1] == ch) {
			result.push_back(String());
		}
		i++;
	}
	if (str[i] == ch) {
		result.push_back(String());
	}
	else {
		result.push_back(substr(back, i));
	}
	return result;
}

String toString(const int val) {
	char ch = val + '0';
	return String(ch);
}
