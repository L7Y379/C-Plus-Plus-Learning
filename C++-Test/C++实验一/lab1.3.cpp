#include<iostream>
using namespace std;
class Date;             	//对Date类的提前引用声明

class Time				//定义Time类
{
	public:
		Time(int, int, int);		//构造函数
		friend void display(Date &, Time &); //display是成员函数，形参是Date类对象的引用
	private:
		int hour;
		int minute;
		int sec;
};
class Date                       //声明Date类
{
	public:
		Date(int, int, int);
		friend void display(Date &, Time &); //声明Time中的display函数为友元成员函数
	private:
		int month;
		int day;
		int year;
};
Time::Time(int h, int m, int s)     //类Time的构造函数
{
	hour=h;
	minute=m;
	sec=s; 
}
void display(Date &d,Time &e)    //display的作用是输出年，月，日和时，分，秒
{
	cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
    cout<<e.hour<<":"<<e.minute<<":"<<e.sec<<endl;      
} 
Date::Date(int m,int d,int y)     //类Date的构造函数
{
	month=m;
	day=d; 
	year=y; 
}
int main()
{
	Time t1(10,13,56);           //定义Time类对象t1
	Date d1(12,25,2004);          //定义Date类对象d1
	display(d1,t1);     //调用t1中的display函数，实参是Date类对象d1
	return 0;
}