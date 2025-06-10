#include "average.h"

float average(const int *arr, int size)
{
	float   avg;
	int     i;

	avg = 0;
	i = 0;
	while(size  > i)
	{
		if(!(arr[i] > 100 || arr[i] < 0))
			avg +=arr[i];
		i++;
	}
	return (avg / size);
}
/* 
int main()
{
	int arr[] = {4, -1, 2, 9, 101, 100};

	printf("%f\n", average(arr, 7));
	return 0;
} */