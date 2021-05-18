/*
 *  Created on: Jan 17, 2021
 *      Author: 1841769_snhu
 */

#include "ClockActuation.h"

#include <iostream>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <limits>


using namespace std;


int sysHrTwelve;
int sysMin;
int sysSec;
int sysHrTwentyFour;
int totHour;
int totHrTwelve = SysHourTwelve();
int totHrTwentyFour =SysHourTwentyFour();
int totMinute = SysMinute();
int totSecond = SysSecond();
char amOrPm;


// Time code courtesy of: https://stackoverflow.com/questions/997946/
// how-to-get-current-time-and-date-in-c, Author TrungTN
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const string CurrentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

int SysHourTwelve () {
	sysHrTwelve = stoi((CurrentTime().substr(11,2)), nullptr);
	if (sysHrTwelve > 12) {
		sysHrTwelve = sysHrTwelve - 12;
	}
	return sysHrTwelve;
}

int SysHourTwentyFour () {
	sysHrTwentyFour = 	sysHrTwelve = stoi((CurrentTime().substr(11,2)), nullptr);
	return sysHrTwentyFour;
}

int SysMinute () {
	sysMin = stoi((CurrentTime().substr(14,2)), nullptr);
	return sysMin;
}

int SysSecond () {
	sysSec = stoi((CurrentTime().substr(17,2)), nullptr);
	return sysSec;
}

int TotHourTwelve() {
	totHrTwelve++;
	if (totHrTwelve > 12) {
		totHrTwelve = 1;
	}
	return totHrTwelve;
}

int TotHourTwentyFour () {
	totHrTwentyFour++;
	if (totHrTwentyFour > 23) {
		totHrTwentyFour = 0;
	}
	return totHrTwentyFour;
}

int TotMinute() {
	totMinute++;
	if (totMinute >= 60) {
		totMinute = totMinute - 60;
		TotHourTwelve();
		TotHourTwentyFour();
	}
	return totMinute;
}

int TotSecond() {
	totSecond++;
	if (totSecond >= 60) {
		totSecond = 0;
		TotMinute();
	}
	return totSecond;
}

char TimeConvertAmPm (char PmAm, int hourTwentyFour) {
	if ((hourTwentyFour) >= 12) {
	   PmAm = 'P';
	}
	else {
	   PmAm = 'A';
	}
	return PmAm;
	cout << "";
}

void PrintClock(int hourTwelve, int minute, int second, char pOa, int hourTwentyFour) {


	cout << "**************************       **************************" << endl;
	cout << "*      12-Hour Clock     *       *      24-Hour Clock     *" << endl;
	cout  << "*      ";
	cout.fill('0');
	cout << setw(2);
	cout << hourTwelve;
	cout << ":";
	cout << setw(2);
	cout << minute;
	cout << ":";
	cout << setw(2);
	cout << second;
	cout << " " << pOa << "M" << "       *       *        ";
	cout << setw(2);
	cout << hourTwentyFour;
	cout << ":";
	cout << setw(2);
	cout << minute;
	cout << ":";
	cout << setw(2);
	cout << second;
	cout << "        *" << endl;
	cout << "**************************       **************************";
}

void PrintMenu() {
	cout << "**************************" << endl;
	cout << "* 1-Add One Hour         *" << endl;
	cout << "* 2-Add One Minute       *" << endl;
	cout << "* 3-Add One Second       *" << endl;
	cout << "* 4-Exit Program         *" << endl;
	cout << "**************************" << endl;
}

//Function for clearing the screen.
void WipeScrn() {
    system("CLS");
}

//Method to handle non-digit entry into menu.
int MenuSelect (int menuSelect) {
while (1) {
	if (cin.fail() || menuSelect <= 0 || menuSelect >= 9) {
		cin.clear();
		//ignores the rest of the entry line, i.e. endl
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid entry, Re-enter Selection: ";
		cin >> menuSelect;
	}
	if (!cin.fail()) {
		cin.ignore();
		break;
	}
}
return menuSelect;
}



int main () {

	int menuSelection = 0;
	char pmOrAm = 'A';
	int initialCounter = 0;

	//loads initial screen before making the first selection
    WipeScrn();
	pmOrAm = TimeConvertAmPm(pmOrAm, SysHourTwentyFour());
    PrintClock (SysHourTwelve(), SysMinute(), SysSecond(), pmOrAm, SysHourTwentyFour());
    cout << endl;
    cout << endl;
	PrintMenu();

	//Entry for Menu Selection
	cout << "Enter Selection: ";
	cin >> menuSelection;

	//Evaluates entry for valid input.
	MenuSelect(menuSelection);

	while (menuSelection != 4) {
		try {

			// Selection 1 hours, both 12 and 24
			if (menuSelection == 1) {
				TotHourTwelve();
				TotHourTwentyFour();
				pmOrAm = TimeConvertAmPm(pmOrAm, totHrTwentyFour);
			}

			//Selection 2: Add Minutes
			else if (menuSelection == 2) {
				TotMinute();
					if (totMinute == 60) {
						totMinute = 0;
						TotHourTwelve();
						TotHourTwentyFour();
					}
					if (totMinute > 60) {
						throw runtime_error ("Minutes > 60");
					}
			}

			//Selection 3: Add Seconds
			else if (menuSelection == 3) {
				TotSecond();
				if (totSecond == 60) {
					totSecond = 0;
					TotMinute();
				}
				if (totSecond > 60) {
					throw runtime_error ("Seconds > 60");
				}
			}
			else if (menuSelection == 4) {
				continue;
			}
			else {
				cout << "Invalid Selection " << menuSelection<< endl;
			}
		    if (initialCounter > 99999999) {
			   initialCounter = 2;
		    }

			WipeScrn();
		    PrintClock (totHrTwelve, totMinute, totSecond, pmOrAm, totHrTwentyFour);
		    cout << endl;
		    cout << endl;
			PrintMenu();
			menuSelection = 0;
			cout << "Enter Selection: ";
			cin >> menuSelection;
			//Evaluates entry for valid input.
			MenuSelect(menuSelection);
			}
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Critical Error" << endl;
			break;
		}
	}
	cout << "Exiting." << endl;

}
