#pragma once
#ifndef MYTIME0_H_
#define MYTIME0_H_
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time Sum(const Time& t) const;
	void Show() const;

	// 重载运算符 +
	Time operator+(const Time& t) const;
	// 重载运算符 -
	Time operator-(const Time& t) const;
	// 重载运算符 *
	Time operator*(double n) const;

	// 友元 
	// 重载运算符 *
	friend Time operator*(double m, const Time& t);
	// 重载 << 
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
#endif
