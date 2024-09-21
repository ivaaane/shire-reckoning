#include<stdio.h>

struct Month {
	char*	name;
	int	isfull;
};

void calculate(int yday, int isleap, int* rmonth, int* rday) {
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

	int days[ isleap ? 366 : 365 ][2];
	int day = 0;
	for(int i = 0; i < 17; i++) {
		if (i == 9 && !isleap) continue;

		int monthDays = months[i].isfull ? 30 : 1;
		for(int j = 0; j < monthDays; j++) {
			days[day][0] = i;
			days[day][1] = j;
			day++;
		
			// remove this
			printf("%i %i %i\n", days[day-1][0]+1, days[day-1][1]+1, day-1);
		}
	}

	*rmonth	= days[yday][0];
	*rday = days[yday][1];
}

int main() {
	int day;
	int month;

	int yday	= 264;
	int isleap	= 1;

	calculate(yday, isleap, &month, &day);
	printf("%i %i\n", month, day);
}
