#include <iostream>
#include <climits>

void PrintNumbers(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "Number " << i + 1 << " is " << numbers[i] << std::endl;
	}
}

int FindLowest(int numbers[], int count)
{
	int lowest = INT_MAX;
	for (int i = 0; i < count; i++)
	{
		int current = numbers[i];
		if (current < lowest)
		{
			lowest = current;
		}
	}
	return lowest;
}

int FindHighest(int numbers[], int count)
{
	int highest = INT_MIN;
	for (int i = 0; i < count; i++)
	{
		int current = numbers[i];
		if (current > highest)
		{
			highest = current;
		}
	}
	return highest;
}

// "A function that does something cool and almost broke Professor Smiley's brain ;)"
void PrintCircle(int radius)
{
	for (int y = -radius; y < radius; y++)
	{
		for (int x = -radius; x < radius; x++)
		{
			// c ^ 2 = a ^ 2 + b ^ 2
			// c = sqrt(a ^ 2 + b ^ 2)
			float length = sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
			if (length < radius)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	//const int count = 10;
	//int numbers[count] = { 2, 4, 6, 8, 999, 20, -5, 60, 80, 1 };
	//PrintNumbers(numbers, count);
	//int lowest = FindLowest(numbers, count);
	//int highest = FindHighest(numbers, count);
	PrintCircle(20);
	return 0;
}

/*
	Complete the following (ungraded):
	• Make an array of 10 integers. They can be any numbers you like.
	• Make a function that finds the lowest number in your array.
	• Make a function that finds the highest number in your array.
	• Make a function that summates all the numbers in your array.
	• Make a function of your choice that does something cool ;)
*/
