#ifndef DATE_H
#define DATE_H

#include <ostream>
using namespace std;
class Date {
	friend ostream& operator<<(ostream& os, const Date& d);
public:
	//ostream& operator<<(const Date& d);
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	~Date();
	int GetMonthDay(int year, int month);
	Date& operator=(const Date& d);
	// 日期+=天数
	Date& operator+=(int day);
	// 日期+天数
	Date operator+(int day);
	// 日期-天数
	Date operator-(int day);
	// 日期-=天数
	Date& operator-=(int day);
	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();
	// >运算符重载
	bool operator>(const Date& d);
	// ==运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	inline bool operator >= (const Date& d);
	// <运算符重载
	bool operator < (const Date& d);
	// <=运算符重载
	bool operator <= (const Date& d);
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);

	

protected:
	bool isLeapYear(int year);

private:
	int _year, _month, _day;
};

ostream& operator <<(ostream& os, const Date& d);
#endif // !DATE_H

