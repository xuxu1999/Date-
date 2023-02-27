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
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	inline bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);

	

protected:
	bool isLeapYear(int year);

private:
	int _year, _month, _day;
};

ostream& operator <<(ostream& os, const Date& d);
#endif // !DATE_H

