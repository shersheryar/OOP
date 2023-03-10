#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

//declaring a class named Time
class Time{
	int hour;
	int minute;
	int second;
	
	public://declaring construtor functions
		Time();
		Time(int hour, int minute, int second);
		Time operator + (const Time& t);
		
		//declaring member funtions
		void display();
		void addTime(Time x, Time y);
};
//initilizing consturtor fuctions
Time::Time(){
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}
Time::Time(int hour, int minute, int second){
	this->hour = hour;
	this->minute = minute;
	this->second = second;
}

//initializing member functions
void Time::display(){
	cout<<"time: "<<this->hour<<":"<<this->minute<<":"<<this->second<<endl;
}
//adding two time objects and storing new time in third object
void Time::addTime(Time x ,Time y){
	int totalTimeX = ((x.hour*3600)+(x.minute*60) + x.second);
	int totalTimeY =  ((y.hour*3600)+(y.minute*60) + y.second);
	int totalTime = totalTimeX + totalTimeY;
	this->hour = totalTime / 3600;
	this->minute = (totalTime % 3600) / 60;
	this->second = (totalTime % 3600)%60;
}	
Time Time::operator + (const Time& t){
	Time temp;
	int totalTimeX = ((this->hour*3600)+(this->minute*60) + this->second);
	int totalTimeY =  ((t.hour*3600)+(t.minute*60) + t.second);
	int totalTime = totalTimeX + totalTimeY;
	temp.hour = totalTime / 3600;
	temp.minute = (totalTime % 3600) / 60;
	temp.second = (totalTime % 3600)%60;
	return temp;
}
int main(){
	//declaring time objects
	Time t1(1,3,20),t2(2,61,70),t3;
	//adding two time objects
	t3 = t1+t2;
	//displaing the values
	t3.display();
}
