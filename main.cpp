#include <iostream>

void PrintNumbers(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "Number " << i + 1 << " is " << numbers[i] << std::endl;
	}
}

int main()
{
	const int count = 10;
	int numbers[count] = { 2, 4, 6, 8, 10, 20, 40, 60, 80, 100 };
	PrintNumbers(numbers, count);
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
