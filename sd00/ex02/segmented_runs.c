#include "segmented_runs.h"

static	int		ft_is_segment(int size, const int *arr)
{
	int	pre;
	int	index;
	int	len;

	if (size < 3)
		return FALSE;
	index = 0;
	pre = arr[index];
	len = 1;
	while(++index <= size)
	{
		if (pre < arr[index])
			len++;
		else
			len = 0;
		if(len == 3)
			return TRUE;
		pre = arr[index];
	}
	return	(FALSE);
	
}

int count_segments(const int *arr, int size)
{
	int i;
	int pre_index;
	int count;
	int seq;

	pre_index = 0;
	count = 0;
	i = 0;
	while (++i < size)
	{
		if(arr[i] == -1)
		{
			if (ft_is_segment(i - pre_index - 1, &arr[pre_index + 1]) == TRUE)
				count ++;
			pre_index = i;
		}
	}
	return (count);
}


int main()
{
	int arr[] = {-1,-1,-1, 4, -1, 11, 2, 9, -1, 101, 104, 219, 222, 0, 0, -1,-1,-1};

	printf("count: %d\n",	count_segments(arr, 18));
	return 0;
}