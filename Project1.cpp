/*	Jason Harmon 01/27/2024
	CS-210 Programming languages
	Professor Thoma,
	Mod 3 | Project 1: Clock
*/

#include <iostream>
#include <string>
using namespace std;

int hour12 = 00; // these are global variables which keep track of the time as it changes.
int hour24 = 00;
int min12 = 00;
int min24 = 00;
int sec12 = 00;
int sec24 = 00;

void Clock12(int user ) {			 // clock 12 gets the time for the 12 hour clock
	string hours;					 // strings so that the numbers can be double digits at all time
	string min;
	string sec;
	bool time = false;				 // to depect if its Am or PM
	if (user == 1 && hour12 <= 12) { // makes sure that the hours stay less than 13
		hour12 += 1;
	} 
	if(user == 2 && min12 < 60){	 // makes sure the minutes stay less than 60
		min12 += 1;
	}
	if (user == 3 && sec12 < 60) {	// makes sure the seconds stay less than 60
		sec12 += 1;
	}
	if (user == 1 && hour12 > 12){	// if the hours go above 12 then it sets the 
		hour12 = 1;					// time to pm and if they go over on "pm" the switch to "AM"
		time = true;			    // then it switches the time back to hour 1
	}
	if (user == 2 && min12 >= 60) { // if the minutes go over 59 it adds a hour to the clock 
		min12 = 0;					// and goes back to zero
		hour12 += 1;
	}
	if (user == 3 && sec12 >= 60) { // if the seconds go over 59 it adds a minute to the clock
		sec12 = 0;					// then sets seconds back to zero
		min12 += 1;
	}
	if (hour12 <= 9) {				// if hours are single digit it will assign it to a hours 
		hours = to_string(hour12);  // then it will add a zero infront
		hours = "0" + hours;
	}
	else {
		hours = to_string(hour12);  // if hours are double digit it will assign it to a hours
	}
	if (min12 <= 9) {				// if minutes are single digit it will assign it to min
		min = to_string(min12);		// then it will add a zero infront
		min = "0" + min;
	}
	else {
		min = to_string(min12);		// if minutes are double digit it will assign to min
	}
	if (sec12 <= 9) {				// if seconds are single digit it will assign to sec
		sec = to_string(sec12);		// then it will add a zero infront 
		sec = "0" + sec;
	}
	else {
		sec = to_string(sec12);		// if seconds are double digit it will assign to sec
	}
	if (!time) {					// prints the time if its "AM"
		cout << "*    " << hours << ":" << min << ":" << sec << " AM    *    ";
	}
	if (time) {						// prints the timr if its "PM"
		cout << "*    " << hours << ":" << min << ":" << sec << " PM    *    ";
	}
}

void Clock24(int user) {			// Clock for the 24 hour time	
	string hours;					// strings so the numbers are double digit
	string min;
	string sec;

	if (user == 1 && hour24 < 24) { // makes it so the clock stays under 24 hours before reseting 
		hour24 += 1;
	}
	if (user == 2 && min24 < 60) {  // makes sure the minutes are under 60
		min24 += 1;
	}
	if (user == 3 && sec24 < 60) {  // makes sure the seconds are under 60
		sec24 += 1;
	}
	if (user == 1 && hour24 >= 24) {// if hours are 24 it sets back to zero
		hour24 = 0;
	}
	if (user == 2 && min24 >= 60) { // if minutes are 60 it turns to zero and adds one to hours
		min24 = 0;
		hour24 += 1;
	}
	if (user == 3 && sec24 >= 60) { // if seconds are 60 it turns to zero and adds one to minutes
		sec24 = 0;
		min24 += 1;
	}
	if (hour24 <= 9) {				// if hours are single digit it assigns to hours then adds zero infront
		hours = to_string(hour24);
		hours = "0" + hours;
	}
	else {
		hours = to_string(hour24);  // if hours are double digit it assigns to hours
	}
	if (min24 <= 9) {				// if minutes are single digit it assigns to min then adds zero infront
		min = to_string(min24);
		min = "0" + min;
	}
	else {
		min = to_string(min24);		// if minutes are double digit it assigns to min
	}
	if (sec24 <= 9) {				// if seconds are single digit it assigns to sec then adds zero infront
		sec = to_string(sec24);
		sec = "0" + sec;
	}
	else {
		sec = to_string(sec24);     // if seconds are double digit it assigns to sec
	}
	cout << "*      " << hours << ":" << min << ":" << sec << "     * " << endl; // prints the 24 hour clock
}

void prompt() {						// prints out the time change options
	cout << "            **********************" << endl;
	cout << "            * 1 - Add One Hour   *" << endl;
	cout << "            * 2 - Add One Minute *" << endl;
	cout << "            * 3 - Add One Second *" << endl;
	cout << "            * 4 - Exit Program   *" << endl;
	cout << "            **********************" << endl;
}

int main() {						// main function that ties everything together 
	int user = 0;					// user input
	bool stop = false;				// stops the code from running

	cout << "*********************    *********************" << endl; // so the starting clock is displayed 
	cout << "*   12-Hour Clock   *    *   24-Hour Clock   *" << endl;
	cout << "*    00:00:00 AM    *    *      00:00:00     *" << endl;
	cout << "*********************    *********************" << endl;
	
	while (!stop) {					// will stop running the program if stop is true
		prompt();					// calls the time prompt function
		cin >> user;				// gets input from user
		if (user == 4){				// will end program if user types 4
			break;
		}
		cout << "*********************    *********************" << endl; // prints the updated clock
		cout << "*   12-Hour Clock   *    *   24-Hour Clock   *" << endl;
		Clock12(user);													  // calls Clock12 and gives it user input
		Clock24(user);													  // calls Clock24 and gives it user input
		cout << "*********************    *********************" << endl;
		
	}
}