#include<stdio.h>

#define TRUE    1
#define FALSE   0

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void)
{
	int year, k;

	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	if(validate_year(year))
	{
		return (year);
	}
	else
		printf("Invalid Year\nYear should be 4 digits from 1400 - 2050");
	return(1);
}


/**
 * validate_year - A function that checks if @year is valid
 *
 * @year: The year to check
 * return: Boolean value
 */
int validate_year(int year)
{
	if (year >= 1400 && year <= 2050)
	{
		return TRUE;
	}
	else
	{
		return FALSE;   //Year should be 4 digits from 1400 - 2050
	}
}


int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return (daycode);
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return (TRUE);
	}
	else
	{
		days_in_month[2] = 28;
		return (FALSE);
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

		/* Correct the position for the first date*/
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}

		/*Print all the dates in one month*/
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			/* Is day before Sat? Else start next line Sun.*/
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			/*Setting the position for next month*/
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}


int main(void)
{
	int year, daycode, leapyear;

	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");

	return(0);
}
