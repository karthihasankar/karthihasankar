
#include <stdio.h>
#include "stats.h"

/*******************************************
 *
 * Constants:
 *
*********************************************/

#define DATA_SET_LENGTH (40)

/* Function to print the array of elements */
unsigned char print_array(unsigned char *data, unsigned int length)
{
	int i;

	for(i=0; i<length; i++)
	{
		printf("\t%u ", *data);
		data++;//input in current array element and move to the next element
	}
	printf("\n");
	return 0;
}

/* Function to sort the array of elements in descending order */
unsigned char sort_array(unsigned char *data, unsigned int length)
{
	int i,j,temp;
	unsigned char array[length];

	for(i=0; i<length; ++i)
	{
		for(j=i+1; j<length; ++j)
		{
			if(*(data+i) < *(data+j))//if the array of current element is lesser than the next element
				//then we swapping the element to the next location
			{
				temp = *(data+i);
				*(data+i) = *(data+j);
				*(data+j) = temp;
			}
		}
	}

	for(i=0; i<length; ++i)
	{
		printf("\t%u ", *(data+i));
	}
	printf("\n");
	return 0;
}

/* Function to calculate the mean of array of elements */
unsigned char find_mean(unsigned char *data, unsigned int length)
{
	int i;
     	unsigned int Mean = 0;

	for(i=0; i<length; i++)
	{
		Mean = Mean + *(data);
		data++;
	}
	Mean = Mean / length;
	return(Mean);
}

/* Function to calculate the median of array of elements */
unsigned char find_median(unsigned char *data, unsigned int length)
{
	int i;
	unsigned int median = 0, medianIndex = 0;

	/* if the array of elements are odd */
	if((length % 2) != 0)
	{
		medianIndex = ((length - 1)/2);
		median = *(data + medianIndex);
	}
	/* if the array of elements are even */
	else
	{
		medianIndex = length / 2;
		median = (*(data+(medianIndex-1)) + *(data+(medianIndex))) /2;
	}
	return (median);
}

/* function for calculate the maximum value of data set */
unsigned char find_maximum(unsigned char *data, unsigned int length)
{
	int i=0;
	unsigned char max=*(data+i);//Assume first element as maximum

	for(i=1; i<length; i++)
	{
		if(*(data+i) > max)//if current element greater than max
		{
			max = *(data+i);
		}
	}
	return (max);	
}

/* function for calculate the minimum value of data set */
unsigned char find_minimum(unsigned char *data, unsigned int length)
{
	int i=0;
	unsigned char min=*(data+i);//Assume first element as minimum
	
	for(i=1; i<length; i++)
	{
		if(*(data+i) < min)//if current element lesser than min
		{
			min = *(data+i);
		}
	}
	return (min);
}

/* Function that prints the statistics of an array including minimum, maximum, mean, and median. */
unsigned char print_statistics(unsigned char *data, unsigned int length)
{
	unsigned int Mean, Median, Max, Min;
	/* minimum value of the data set */
	Min = find_minimum(data, length);
	printf("\nMinimum element is: %u\n", Min);

	/* maximum value of the data set */
	Max = find_maximum(data, length);
	printf("\nMaximum element is: %u\n", Max);

	/* mean of the data */
	Mean = find_mean(data, length);
	printf("\nMean value of the data set: %u\n", Mean);
	
	/* median of the elements */
	Median = find_median(data, length);
	printf("\nMedian value of the data set: %u\n", Median);

	printf("\n");

	return 0;
} 

unsigned char main()
{
	unsigned char array[DATA_SET_LENGTH], *data;
	int i;
	unsigned int length;
        /* Input array length and element */
	printf("\nEnter the array size: ");
	scanf("%d", &length);

	printf("\nEnter the elements in array: \n");
	for(i=0; i<length; i++)
	{
		scanf("\t%u, ", (unsigned int*) &array[i]);
	}
	data = array;//name of array provides base address of array
	
	/* printing the array */
	printf("\nArray contains.... \n");
	print_array(data, length);

	/* sorted array */
	printf("\nSorted array: \n");
	sort_array(data, length);

	/*print the statistics of element */
	print_statistics(data, length);
	
	return 0;
}

