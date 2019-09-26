#include<iostream>
#include<iomanip>
using namespace std;
void calculateWeek(int, int, int, int&);
int holidayPlus(int, int, int);
int calculateTariff(int, int, bool);
void calculateFare(int, double, double&);

int year, month, day, hour, week, tariff;
double dis, fare;
bool holiday;
int temp=1;

int main() {
	while (temp != 0) {
		cout << "Taxi Fare of London" ;
		cout << '\n' << "Please enter year month day time(hour), example [2019 09 25 15]" << endl;;
		cin >> year >> month >> day >> hour;
		cout << "Please enter travel distance (mile)" <<endl ;
		cin >> dis;

		calculateWeek(year, month, day, week);
		holiday = holidayPlus(month, day, hour);
		tariff = calculateTariff(week, hour, holiday);
		calculateFare(tariff, dis, fare);

		cout << '\n' << year << "/" << month << "/" << day << " at " << hour << " o'clock, distance : " << dis << " miles, Fare : ";
		cout << fixed << setprecision(2)<< fare << "pound"<<endl;
		cout << '\n' << "There is an extra charge of 2.80 pound for journeys that start from Heathrow Airport taxi ranks." ;
		cout << '\n' << "There is an extra charge of up to 2 pound if the taxi is booked by phone or online." ;
		cout << '\n' << '\n' << "Enter 0 to quit, any number to continue" << endl;
		cin >> temp;
	}
	return 0;
}

void calculateWeek(int year, int month, int day, int& week) {
	if (month == 1 || month == 2) {
		month += 12;
		year--;
	}
	week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
}

int holidayPlus(int month, int day, int hour) {
	if ((month == 1 && day < 3 ) || (month == 12 && day == 31 )) {
		if ((day == 2 && hour > 6) || (day == 31 && hour < 20)) return 0;
		return 1;
	}
	if (month == 12 && day < 28 && day > 23 ) {
		if ((day == 24 && hour < 20) || (day == 27 && hour > 6)) return 0;
		return 1;
	}
	return 0;
}

int calculateTariff(int week, int hour, bool holiday) {
	if (hour < 5 || hour >22 || holiday == 1) return 3;
	if (week < 6 && hour > 4 && hour < 20) return 1;
	return 2;
}

void calculateFare(int tariff, double distance, double& fare) {
	if (distance > 6.00) tariff = 4;
	switch (tariff){
	case 1:
		fare = distance * 2.76;
		break;
	case 2:
		fare = distance * 3.40;
		break;
	case 3:
		fare = distance * 3.96;
		break;
	case 4:
		fare = distance * 3.70;
		break;
	}
	if (holiday != 0) fare += 4.00;
	fare += 3;
}

