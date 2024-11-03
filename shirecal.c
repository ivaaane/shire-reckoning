#include <stdio.h>
#include <time.h>

void calculate(int yday, int isleap, int* rmonth, int* day);
void printDate(int day, int wday, int month, int year);
int checkLeap(int year);

struct Month {
    char*	name;
    int	isfull;
};

struct Month months[] = {
    { "2 Yule",         0 },
    { "Afteryule",      1 },
    { "Solmath",        1 },
    { "Rethe",          1 },
    { "Astron",         1 },
    { "Thrimidge",      1 },
    { "Forelithe",      1 },
    { "1 Lithe",        0 },
    { "Mid-year's Day", 0 },
    { "Overlithe",      0 },
    { "2 Lithe",        0 },
    { "Afterlithe",     1 },
    { "Wedmath",        1 },
    { "Halimath",       1 },
    { "Winterhash",     1 },
    { "Blomath",        1 },
    { "Anteyule",       1 },
    { "Yule 1",         0 },
};

int main() {
    time_t now = time(NULL);
    struct tm* local = localtime(&now);

    int year	= local->tm_year + 1900;
    int isleap	= checkLeap(year);
    int yday	= local->tm_yday;
    yday		= (yday + 11) % (isleap ? 366 : 365);
    int wday	= (yday - (yday < 180 ? 0 : 2)) % 7;

    int day, month;

    calculate(yday, isleap, &month, &day);
    printDate(day, wday, month, year);

    /*// test
    for(int i = 0; i < (isleap ? 366 : 365); i++) {
        yday = (i + 11) % (isleap ? 366 : 365);
        calculate(yday, isleap, &month, &day);
        printDate(day, wday, month, year);
    }
    */
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

void printDate(int day, int wday, int month, int year) {
    char week[7][10] = {"Sterday", "Sunday", "Monday", "Tewsday", "Hevensday", "Mersday", "Highday"};

    if(months[month].name != "Mid-year's Day" || months[month].name != "Overlithe")
        printf("%s ", week[wday]);
    printf("%s ", months[month].name);
    if(months[month].isfull != 0)
        printf("%i, ", day + 1);
    printf("%i ", year);
    printf("of the Seventh Age\n");
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
