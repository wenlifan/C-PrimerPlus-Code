#pragma once
#ifndef TABENN_H_
#define TABENN_H_
#include <string>

using std::string;

class TableTennisPlyaer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlyaer(const string& fn = "none", const string& ln = "none", bool ht = false);
	
	void Name() const;
	bool HasTable() const { return hasTable; };
	void ResetTable(bool v) { hasTable = v; };
};

class RatedPlayer : public TableTennisPlyaer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string& fn = "none",
		const string& ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlyaer& tp);

	unsigned int Rating() const { return rating; };
	void RestRating(unsigned int r) { rating = r; };
};

#endif
