#pragma once
#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	StringBad(const char* s);
	StringBad();

	// 复制构造
	StringBad(const StringBad& st);
	// 赋值
	StringBad& operator=(const StringBad& st);
	~StringBad();
public:
	int length() const { return len; };
	char& operator[](int i);
	const char& operator[](int i) const;

	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
	friend bool operator<(const StringBad& st1, const StringBad& st2);
	friend bool operator>(const StringBad& st1, const StringBad& st2);
	friend bool operator==(const StringBad& st1, const StringBad& st2);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
	friend std::istream& operator>>(std::istream& is, StringBad& st);
public:
	static int HowMany() { return num_strings; }
};

#endif // !STRINGBAD_H_
