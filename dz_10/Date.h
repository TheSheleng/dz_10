#pragma once

#include <exception>

#define D_DAY 0
#define D_MONTH 1
#define D_YEAR 2

#define JYNUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

using namespace std;

class Date
{
	int day;
	int month;
	int year;

	bool corrCheck(const Date& date);

	void fix();

public:
	Date();
	Date(const Date& date);
	Date(int d, int m, int y);

	//Аксесоры
	int get(int i) const;

	void set(int d, int m, int y);
	void set(int i, int val);
	void set(const Date& date);

	// -----------------
	void increase(int d);
	void decrease(int d);

	// -----------------

	void print();

	//Операторы
	Date operator++ ();
	Date operator-- ();

	Date operator+ (int d);
	Date operator- (int d);

	Date operator+= (int d);
	Date operator-= (int d);

	bool operator> (const Date& date);
	bool operator< (const Date& date);
	bool operator>= (const Date& date);
	bool operator<= (const Date& date);
	bool operator== (const Date& date);
	bool operator!= (const Date& date);
};

