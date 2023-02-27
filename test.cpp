#include<iostream>
#include"Date.h"
using namespace std;
void test01() {//日期加减天数
	Date d(2023, 2, 27);
	d -= 30;
	--d;
	cout << d << endl;
	Date d2(2023, 2, 27);
	d2 += -2;
	cout << "d2 += -2:" << d2<<endl;
	//cout << "d2-(-2):" << endl;
}

void test02() {
	Date d1(2023, 1, 1);
	Date d2(2023, 2, 27);
	cout << d2 - d1;
}
int main() {
	test01();
	cout << "------\n";
	test02();
	return 0;
}