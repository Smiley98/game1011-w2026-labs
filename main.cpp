#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Example1();
void Example2();

int main()
{
	//Example1();
	Example2();
	return 0;
}

// Review of reading file word-by-word vs line-by-line
void Example1()
{
	std::ifstream file;
	file.open("./data/Murphy.txt");

	std::vector<std::string> contents;

	std::string word;
	while (std::getline(file, word))
	{
		contents.push_back(word);
	}

	for (int i = 0; i < contents.size(); i++)
	{
		std::cout << contents[i] << std::endl;
	}
}

void Example2()
{
	std::ifstream file;
	file.open("./data/Murphy.txt");

	std::vector<char> contents;

	char character;
	while (file.get(character))
	{
		contents.push_back(character);
	}

	for (int i = 0; i < contents.size(); i++)
	{
		std::cout << contents[i];
	}
}
