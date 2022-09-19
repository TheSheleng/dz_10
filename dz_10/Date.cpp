#include "Date.h"
#include <iostream>

bool Date::corrCheck(const Date& date)
{
	switch (date.month)
	{
	case JYNUARY:   
	case MARCH:    
	case MAY:      
	case JULY:     
	case AUGUST:   
	case OCTOBER:
	case DECEMBER:
		if (date.day > 0 && date.day <= 31) return true;
		else false;

	case APRIL:     
	case JUNE:      
	case SEPTEMBER:
	case NOVEMBER:  
		if (date.day > 0 && date.day <= 30) return true;
		else false;

	case FEBRUARY:
		//Високосные года (29 дней)
		if ((NULL == date.year % 100 && NULL == date.year % 400 || NULL == date.year % 4) && date.day > 0 && date.day <= 29) return true;
		//Невисокосные года (28 дней)
		else if (date.day > 0 && date.day <= 28) return true;

	default: return false;
	}
}

void Date::fix()
{
	while (!corrCheck(*this))
	{
		int offset = 0;

		if (day <= 0) month--;

		//Фикс по дням
		switch (month)
		{
		case DECEMBER:
			month = 0;
			year++;

		case JYNUARY:
		case MARCH:
		case MAY:
		case JULY:
		case AUGUST:
		case OCTOBER:
			offset = 31;
			break;

		case APRIL:
		case JUNE:
		case SEPTEMBER:
		case NOVEMBER:
			offset = 30;
			break;

		case FEBRUARY:
			//Високосные года (29 дней)
			if (NULL == year % 100 && NULL == year % 400 || NULL == year % 4) offset = 29;
			//Невисокосные года (28 дней)
			else offset = 28;
			break;

			//Смена года в обратную сторону
		case NULL:
			year--;
			month = 12;
			offset = 31;
			break;

			//Фикс по месяцам
		default:
			year += month / 12;
			month = month % 12;
			
		}

		if (day <= 0) day += offset;

		else
		{
			day -= offset;
			month++;
		}
	}
}

Date::Date() : Date(1, 1, 1) {}

Date::Date(const Date& date) { set(date); }

Date::Date(int d, int m, int y) { set(d, m, y); }

int Date::get(int i) const
{
	if (i == D_DAY) return day;
	else if (i == D_MONTH) return month;
	else if (i == D_YEAR) return year;
	else throw exception("Incorrect get method index");
}

void Date::set(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;

	if (!corrCheck(*this)) fix();
}

void Date::set(int i, int val)
{
	if (i == D_DAY) day = val;
	else if (i == D_MONTH) month = val;
	else if (i == D_YEAR) year = val;

	if (!corrCheck(*this)) fix();
}

void Date::set(const Date& date)
{
	day = date.day;
	month = date.month;
	year = date.year;

	if (!corrCheck(*this)) fix();
}

void Date::increase(int d)
{
	day += d;
	fix();
}

void Date::decrease(int d)
{
	day -= d;
	fix();
}

void Date::print()
{
	cout << "Day: " << day << endl;
	cout << "Month: " << month << endl;
	cout << "Year: " << year << endl;
}

//Date Date::operator++ ()
//{
//	Date date(*this);
//	date.increase(1);
//	return date;
//}
//
//Date Date::operator-- ()
//{
//	Date date(*this);
//	date.decrease(1);
//	return date;
//}
//
//Date Date::operator+ (int d)
//{
//	Date date(*this);
//	date.increase(d);
//	return date;
//}
//
//Date Date::operator- (int d)
//{
//	Date date(*this);
//	date.decrease(d);
//	return date;
//}
//
//Date Date::operator+= (int d)
//{
//	this->increase(d);
//	return *this;
//}
//
//Date Date::operator-= (int d)
//{
//	this->decrease(d);
//	return *this;
//}
//
//bool Date::operator> (const Date& date)
//{
//	if (year > date.get(D_YEAR)) return true;
//	else if (month > date.get(D_MONTH)) return true;
//	else if (day > date.get(D_DAY)) return true;
//	else return false;
//}
//
//bool Date::operator< (const Date& date)
//{
//	if (year < date.get(D_YEAR)) return true;
//	else if (month < date.get(D_MONTH)) return true;
//	else if (day < date.get(D_DAY)) return true;
//	else return false;
//}
//
//bool Date::operator>= (const Date& date)
//{
//	if (year >= date.get(D_YEAR) &&
//		month >= date.get(D_MONTH) &&
//		day >= date.get(D_DAY))
//		return true;
//
//	else return false;
//}
//
//bool Date::operator<= (const Date& date)
//{
//	if (year <= date.get(D_YEAR) &&
//		month <= date.get(D_MONTH) &&
//		day <= date.get(D_DAY))
//		return true;
//
//	else return false;
//}
//
//bool Date::operator== (const Date& date)
//{
//	if (year == date.get(D_YEAR) &&
//		month == date.get(D_MONTH) &&
//		day == date.get(D_DAY)) 
//		return true;
//
//	else return false;
//}
//
//bool Date::operator!= (const Date& date)
//{
//	if (year != date.get(D_YEAR) ||
//		month != date.get(D_MONTH) ||
//		day != date.get(D_DAY))
//		return true;
//
//	else return false;
//}

//Дз №11

Date operator++ (const Date& _date)
{
	Date date(_date);
	date.increase(1);
	return date;
}

Date operator-- (const Date& _date)
{
	Date date(_date);
	date.decrease(1);
	return date;
}

Date operator+ (const Date& _date, int d)
{
	Date date(_date);
	date.increase(d);
	return date;
}

Date operator- (const Date& _date, int d)
{
	Date date(_date);
	date.decrease(d);
	return date;
}

Date operator+ (int d, const Date& _date)
{
	Date date(_date);
	date.increase(d);
	return date;
}

Date operator- (int d, const Date& _date)
{
	Date date(_date);
	date.decrease(d);
	return date;
}

Date operator+= (Date& _date, int d)
{
	_date.increase(d);
	return _date;
}

Date operator-= (Date& _date, int d)
{
	_date.decrease(d);
	return _date;
}

Date operator+= (int d, Date& _date)
{
	_date.increase(d);
	return _date;
}

Date operator-= (int d, Date& _date)
{
	_date.decrease(d);
	return _date;
}

bool operator> (const Date& date_1, const Date& date_2)
{
	if (date_1.get(D_YEAR) > date_2.get(D_YEAR)) return true;
	else if (date_1.get(D_MONTH) > date_2.get(D_MONTH)) return true;
	else if (date_1.get(D_DAY) > date_2.get(D_DAY)) return true;
	else return false;
}

bool operator< (const Date& date_1, const Date& date_2)
{
	if (date_1.get(D_YEAR) < date_2.get(D_YEAR)) return true;
	else if (date_1.get(D_MONTH) < date_2.get(D_MONTH)) return true;
	else if (date_1.get(D_DAY) < date_2.get(D_DAY)) return true;
	else return false;
}

bool operator>= (const Date& date_1, const Date& date_2)
{
	if (date_1.get(D_YEAR) >= date_2.get(D_YEAR) &&
		date_1.get(D_MONTH) >= date_2.get(D_MONTH) &&
		date_1.get(D_DAY) >= date_2.get(D_DAY))
		return true;

	else return false;
}

bool operator<= (const Date& date_1, const Date& date_2)
{
	if (date_1.get(D_YEAR) <= date_2.get(D_YEAR) &&
		date_1.get(D_MONTH) <= date_2.get(D_MONTH) &&
		date_1.get(D_DAY) <= date_2.get(D_DAY))
		return true;

	else return false;
}

bool operator== (const Date& date_1, const Date& date_2)
{
	if (date_1.get(D_YEAR) == date_2.get(D_YEAR) &&
		date_1.get(D_MONTH) == date_2.get(D_MONTH) &&
		date_1.get(D_DAY) == date_2.get(D_DAY))
		return true;

	else return false;
}

bool operator!= (const Date& date_1, const Date& date_2)
{
	if (date_1.get(D_YEAR) != date_2.get(D_YEAR) ||
		date_1.get(D_MONTH) != date_2.get(D_MONTH) ||
		date_1.get(D_DAY) != date_2.get(D_DAY))
		return true;

	else return false;
}
