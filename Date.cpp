#include "Date.h"
#include <cassert>
#include<iostream>
//ostream& Date::operator<<(const Date& d)
//{
//	// TODO: �ڴ˴����� return ���
//	return *this << d._year << "��" << d._month << "��" << d._day << "��" << endl;
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
		std::cerr << "����������ڲ��Ϸ�" << std::endl;
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
//ĳ��ĳ������
int Date::GetMonthDay(int year, int month)
{
	assert(year >= 0 && month > 0 && month < 13);//����
	int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeapYear(year)) {
		return 29;
	}
	return monthDayArray[month];
}

Date& Date::operator=(const Date& d) 
{
	// TODO: �ڴ˴����� return ���
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
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
	Date max = *this;//Ĭ����Ϊ��һ�� 
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
	// TODO: �ڴ˴����� return ���
	return os << d._year << "��" << d._month << "��" << d._day << "��" << endl;
}
