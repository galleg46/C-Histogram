#include <stdio.h>
#include <stdlib.h>
#include "histo.h"

void init_histogram(int histo[]) //set all elements of the histogram to zero
{
	for(int i = 0; i < NUM_LETTERS; ++i)
	{
		histo[i] = 0;
	}
}

void cons_histogram(const char string[], int histo[]) //construct the histogram from string
{
	for(int i = 0;string[i] != '\0' ; ++i)
	{
		if(string[i] >= 'a' && string[i] <= 'z')
		{
			histo[string[i]-'a']++;
		}
	}
}

void most_frequent(const int histo[], char* ret_val) // set *ret_val to a most occuring letter character - hence returning it
{
	int max = 0;
	for(int i = 0; i < NUM_LETTERS; ++i)
	{
		if(histo[i] > histo[max])
		{
			max = i;
		}
	}
	*ret_val = max + 'a';
}

void display_histogram(int* const histo) // display the histogram sparsely
{
	for(int i = 0; i < NUM_LETTERS; ++i)
	{
		if(histo[i] == 1)
		{
			printf("%c appeared 1 time\n", i + 'a');
		}
		else if(histo[i] > 1)
		{
			printf("%c appeared %d times\n", i + 'a', histo[i]);
		}
	}

	char most;
	most_frequent(histo, &most);
	printf("%c occured most often\n", most);
}
