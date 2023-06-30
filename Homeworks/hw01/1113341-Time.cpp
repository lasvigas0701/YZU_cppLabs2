#include <iostream>
#include <string>
using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int hour, int minute, int second);
	int getHour();
	void setHour(int hour);
	int getMinute();
	void setMinute(int minute);
	int getSecond();
	void setSecond(int Second);
	void add(int second);
	void sub(int second);
	string getTime();
	int compare(Time another);
};

Time::Time() 
{
};

Time::Time(int hour, int minute, int second)
{
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

int Time::getHour() 
{
	return hour;
}

void Time::setHour(int hour) 
{
	this->hour = hour;

	while (this->hour < 0)
		this->hour += 24;

	while (this->hour > 23)
		this->hour -= 24;
}

int Time::getMinute()
{
	return minute;
}

void Time::setMinute(int minute) 
{
	this->minute = minute;
	while (this->minute < 0)
	{
		this->minute += 60;
		setHour(--this->hour);
	}
	while (this->minute > 59)
	{
		this->minute -= 60;
		setHour(++this->hour);
	}
}

int Time::getSecond() 
{
	return second;
}

void Time::setSecond(int second) 
{
	this->second = second;

	while (this->second < 0)
	{
		this->second += 60;
		setMinute(--this->minute);
	}
	while(this->second > 59)
	{
		this->second -= 60;
		setMinute(++this->minute);
	}
}

void Time::add(int second) 
{
	setSecond(this->second += second);
}

void Time::sub(int second) 
{
	setSecond(this->second -= second);
}

string Time::getTime() 
{
	if (hour < 10 && minute < 10 && second < 10) /*0H:0M:0S*/
		return '0' + to_string(hour) + ":" + '0' + to_string(minute) + ":" + '0' + to_string(second);

	else if (hour < 10 && minute < 10 && second >= 10) /*0H:0M:SS*/
		return '0' + to_string(hour) + ":" + '0' + to_string(minute) + ":" + to_string(second);

	else if (hour < 10 && minute >= 10 && second >= 10) /*0H:MM:SS*/
		return '0' + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);

	else if (hour >= 10 && minute < 10 && second < 10) /*HH:0M:0S*/
		return to_string(hour) + ":" + '0' + to_string(minute) + ":" + '0' + to_string(second);

	else if (hour >= 10 && minute >= 10 && second < 10) /*HH:MM:0S*/
		return  to_string(hour) + ":" + to_string(minute) + ":" + '0' + to_string(second);

	else if (hour >= 10 && minute < 10 && second >= 10) /*HH:0M:SS*/
		return to_string(hour) + ":" + '0' + to_string(minute) + ":" + to_string(second);

	else if (hour < 10 && minute < 10 && second < 10) /*0H:MM:0S*/
		return '0' + to_string(hour) + ":" + to_string(minute) + ":" + '0' + to_string(second);

	return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
}

int Time::compare(Time another) 
{
	if (hour < another.hour)
		return -1;
	else if (hour > another.hour)
		return 1;

	if (minute < another.minute)
		return -1;
	else if (minute > another.minute)
		return 1;

	if (second < another.second)
		return -1;
	else if (second > another.second)
		return 1;

	return 0;
}