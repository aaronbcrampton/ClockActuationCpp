/*
 * ChadaClock.h
 *
 *  Created on: Jan 24, 2021
 *      Author: Aaron Crampton
 */

#ifndef CLOCKACTUATION_H_
#define CLOCKACTUATION_H_

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

	const string CurrentTime();
	int SysHourTwelve();
	int SysHourTwentyFour();
	int SysMinute();
	int SysSecond();
	int TotHourTwelve();
	int TotHourTwentyFour ();
	int TotMinute();
	int TotSecond();
	char TimeConvertAmPm (char PmAm, int hourTwentyFour);
	void PrintClock(int hourTwelve, int minute, int second, char pOa, int hourTwentyFour);
	void PrintMenu();
	void WipeScrn();
	int MenuSelect (int menuSelect);






#endif /* CLOCKACTUATION_H_ */
