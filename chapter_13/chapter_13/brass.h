#pragma once
#ifndef BRASS_H_
#define BRASS_H_
#include <string>

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0);
	void Deposit(double amt);
	virtual void WihtDraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass();
};

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;

public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);

	virtual void ViewAcct() const;
	virtual void WihtDraw(double amt);

	void RestMax(double m) { maxLoan = m; }
	void RestRate(double r) { rate = r; }
	void ResteOwes() { owesBank = 0; }
};

#endif
