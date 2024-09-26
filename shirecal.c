#include <stdio.h>
#include <time.h>

void calculate(int yday, int isleap, int* rmonth, int* day);
int checkLeap(int year);

struct Month {
	char*	name;
	int	isfull;
};

struct Month months[] = {
	{ "2 Yule",		0 },
	{ "Afteryule",		1 },
	{ "Solmath",		1 },
	{ "Rethe",		1 },
	{ "Astron",		1 },
	{ "Thrimidge",		1 },
	{ "Forelithe",		1 },
	{ "1 Lithe",		0 },
	{ "Mid-year's Day",	0 },
	{ "Overlithe",		0 },
	{ "2 Lithe",		0 },
	{ "Afterlithe",		1 },
	{ "Wedmath",		1 },
	{ "Halimath",		1 },
	{ "Winterhash",		1 },
	{ "Blomath",		1 },
	{ "Anteyule",		1 },
	{ "Yule 1",		0 },
};

int main() {
	time_t now = time(NULL);
	struct tm* local = localtime(&now);

	int day;
	int month;

	int year	= local->tm_year + 1900;
	int isleap	= checkLeap(year);
	int yday	= local->tm_yday + 1;
	yday		= (yday + 10) % (isleap ? 366 : 365);
	int wday	= (yday - (yday < 180 ? 0 : 2)) % 7;

	calculate(yday, isleap, &month, &day);

	char week[7][10] = {"Sterday", "Sunday", "Monday", "Tewsday",
		"Hevensday", "Mersday", "Highday"};

	printf("%s %s %i, %i of the Seventh Age\n",
		week[wday],
		months[month].name,
		day + 1,
		year);
}

void calculate(int yday, int isleap, int* rmonth, int* rday) {
	int days[ isleap ? 366 : 365 ][2];
	int day = 0;
	for(int i = 0; i < 18; i++) {
		if (i == 9 && !isleap) continue;

		int monthDays = months[i].isfull ? 30 : 1;
		for(int j = 0; j < monthDays; j++) {
			days[day][0] = i;
			days[day][1] = j;
			day++;
		}
	}

	*rmonth	= days[yday][0];
	*rday = days[yday][1];
}

int checkLeap(int year) {
	if (year % 400 == 0) {
		return 1;
	} else if (year % 100 == 0) {
		return 0;
	} else if (year % 4 == 0) {
		return 1;
	} else {
		return 0;
	}
}
