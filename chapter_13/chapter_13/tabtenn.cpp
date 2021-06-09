#include "tabtenn.h"
#include <iostream>

TableTennisPlyaer::TableTennisPlyaer(const string& fn, const string& ln, bool ht) 
		:firstname(fn), lastname(ln), hasTable(ht) {}

void TableTennisPlyaer::Name()const
{
	std::cout << lastname << ", " << firstname;
}

// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r /* = 0 */, const string& fn /* = "none" */, const string& ln /* = "none" */, bool ht /* = false */)
	: TableTennisPlyaer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlyaer& tp) 
	: TableTennisPlyaer(tp), rating(r){}