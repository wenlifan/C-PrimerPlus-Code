#include <cstring>
#include "stringbad.h"

using std::cout;

// initializing static class member
int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	
	cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
	len = 0;
	str = new char[1];
	//std::strcpy(str, "\0");
	str[0] = '\0';
	num_strings++;

	cout << num_strings << ": \"" << str << "\" default object created\n";
}
StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);

	cout << num_strings << ": \"" << str << "\" object created\n";
};


StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deletd, ";
	--num_strings;
	cout << num_strings << " left \n";
	delete[] str;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
	{
		return *this;
	}
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
};

bool operator<(const StringBad& st1, const StringBad& st2)
{
	if (std::strcmp(st1.str, st2.str) < 0)
	{
		return true;
	}
	else {
		return false;
	}
};

bool operator>(const StringBad& st1, const StringBad& st2)
{
	return st2 < st1;
};

bool operator==(const StringBad& st1, const StringBad& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
};

char& StringBad::operator[](int i)
{
	return str[i];
};
const char& StringBad::operator[](int i) const
{
	return str[i];
};

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
};

std::istream& operator>>(std::istream& is, StringBad& st)
{
	char temp[StringBad::CINLIM];
	is.get(temp, StringBad::CINLIM);
	if (is) {
		st = temp;
	}
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
};
