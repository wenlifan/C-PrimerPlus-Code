#include <iostream>
#include "brass.h"

using std::endl;
using std::cout;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();

void restore(format f, precis p);

Brass::Brass(const string& s, long an, double bal) 
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowd;"
		<< "deposti is cancelled.\n";
	else
		balance += amt;
}

Brass::~Brass() {}

void Brass::WihtDraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 2)
		cout << "Withdrawal amount must be position; "
		<< "withdrawal canceled. \n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance.\n"
		<< "Withdrawal canceled.\n";
	restore(initialState, prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	cout << "Clinet: " << fullName << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);
}

BrassPlus::BrassPlus(const std::string& s /* = "Nullbody" */, long an /* = -1 */, double bal /* = 0.0 */, double ml /* = 500 */, double r /* = 0.11125 */)
	: Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml /* = 500 */, double r /* = 0.11125 */)
	: Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;	
}

void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate:" << 100 * rate << "%\n";
	restore(initialState, prec);
}

void BrassPlus::WihtDraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::WihtDraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		Brass::WihtDraw(amt);
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";

	restore(initialState, prec);
}

format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}






















