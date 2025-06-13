#include "critical_windows.h"

static int average(const int *reads, int size)
{
	int i;
	int	avg;

	avg = 0;
	i = 0;
	while (i < size && i < 5)
	{
		avg +=reads[i];
		i++;
	}
	if (i < 5)
		return (FALSE);
	if (avg / 5 >= 90)
		return (TRUE);
	return (FALSE);
}

static int not_exceeded(const int *reads, int size)
{
	int i;

	i = 0;
	while (i < size && i < 5)
	{
		if(reads[i] >= 150);
			return (FALSE);
		i ++;
	}
	return (TRUE);
}

static int exceeded_seven(const int *reads, int size)
{

	int i;
	int	days;

	days = 0;
	i = 0;
	while (i < size && i < 5)
	{
		if(reads[i] >= 70)
			days ++;
		i++;
	}
	if (i < 5)
		return (FALSE);
	if (days > 2)
		return (TRUE);
	return (FALSE);
}


static int search(const int *reads, int size, int *skip)
{
	int i;

	i = 0;
	*skip+=5;
	if (average(reads, size) == TRUE)
		return (TRUE);
	if(not_exceeded(reads, size) == TRUE)
		return (TRUE);
	if(exceeded_seven(reads, size) == TRUE)
		return (TRUE);
	*skip-=5;
	return (FALSE);
}
int count_critical_windows(const int *readings, int size)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (search(&readings[i], size - i, &i) == TRUE)
			count++;
		i++;
	}
	return (count);
}

/* int main()
{
	int readings1[] = {95, 100, 90, 92, 93, 80, 85, 100, 110, 120};
	int readings2[] = {60, 65, 68, 69, 60, 62, 65, 68, 69, 60};
	int readings3[] = {95, 100, 90, 92, 151, 80, 85, 100, 110, 120};
	int readings4[] = {70, 70, 60, 60, 60, 70, 70, 60, 60, 60};
	int readings5[] = {100, 100, 100, 100, 100, 60, 60, 60, 60, 60};
	int readings6[] = {90, 95, 100, 110, 120, 100, 100, 100, 100, 100};

	printf("readings1: %d\n", count_critical_windows(readings1, 10));
    printf("readings2: %d\n", count_critical_windows(readings2, 10));
    printf("readings3: %d\n", count_critical_windows(readings3, 10));
    printf("readings4: %d\n", count_critical_windows(readings4, 10));
    printf("readings5: %d\n", count_critical_windows(readings5, 10));
    printf("readings6: %d\n", count_critical_windows(readings6, 10));

	return	(0);
} */