#include "Date.h"
#include <cassert>
#include<iostream>
//ostream& Date::operator<<(const Date& d)
//{
//	// TODO: 在此处插入 return 语句
//	return *this << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//}
Date::Date(int year, int month, int day)
{
	if (year >= 1 && month <= 12 && month >= 1 && day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		std::cerr << "您输入的日期不合法" << std::endl;
		exit(-1);
	}

}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date::~Date()
{
}
//某年某月天数
int Date::GetMonthDay(int year, int month)
{
	assert(year >= 0 && month > 0 && month < 13);//断言
	int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeapYear(year)) {
		return 29;
	}
	return monthDayArray[month];
}

Date& Date::operator=(const Date& d) 
{
	// TODO: 在此处插入 return 语句
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	// TODO: 在此处插入 return 语句
	if (day < 0)
		return *this -= -day;
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;

}

Date Date::operator+(int day)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;

	return ret;
}

Date& Date::operator-=(int day)
{
	// TODO: 在此处插入 return 语句
	if (day < 0)
		return *this += -day;
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator++()
{
	// TODO: 在此处插入 return 语句
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
	
}

Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}








bool Date::isLeapYear(int year)
{
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

Date& Date::operator--()
{
	// TODO: 在此处插入 return 语句
	*this -= 1;
	return *this;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator==(const Date& d)
{
	return (_year == d._year && _month == d._month && _day == d._day);
}

inline bool Date::operator>=(const Date& d)
{
	return !(*this<d);
}

bool Date::operator<(const Date& d)
{
	if (_year > d._year
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day))
	{
		return false;
	}
	else
	{
		return true;
	}

}

inline
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}

inline
bool Date::operator!=(const Date& d)
{
	//return (_year != d._year || _month != d._month || _day != d._day);
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;//默认认为第一大 
	Date min = d;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++n;
		++min;
	}
	return n * flag;
}

ostream& operator<<(ostream& os, const Date& d)
{
	// TODO: 在此处插入 return 语句
	return os << d._year << "年" << d._month << "月" << d._day << "日" << endl;
}
