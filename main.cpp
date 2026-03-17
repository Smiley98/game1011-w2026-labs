#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool CheckFile(std::ifstream& file)
{
	int state = file.rdstate();
	bool is_good = state == std::ifstream::goodbit;		// No errors (zero value iostate)
	bool is_eof = state & std::ifstream::eofbit;		// End-of-File reached on input operation
	bool is_failed = state & std::ifstream::failbit;	// Logical error on I/O operation
	bool is_bad = state & std::ifstream::badbit;		// Read or write error on I/O operation

	if (is_good)
	{
		std::cout << "File good" << std::endl;
	}
	else
	{
		if (is_eof)
		{
			std::cout << "File eof" << std::endl;
		}
		if (is_failed)
		{
			std::cout << "File failed" << std::endl;
		}
		if (is_bad)
		{
			std::cout << "File bad" << std::endl;
		}
	}

	return is_good;
}

std::vector<char> ReadFile(std::ifstream& file)
{
	std::vector<char> contents;
	char character;
	while (file.get(character))
	{
		contents.push_back(character);
	}
	return contents;
}

void Example1();
void Example2();
void Example3();

int main()
{
	Example1();
	//Example2();
	//Example3();
	return 0;
}

// Review of reading file word-by-word vs line-by-line
void Example1()
{
	std::ifstream file;
	file.open("./data/Murphy.txt");

	std::vector<std::string> contents;

	while (!file.eof())
	{
		std::string word = "Test value";
		std::getline(file, word);
		if (!CheckFile(file))
			std::cout << "Bad";
		contents.push_back(word);
	}

	for (int i = 0; i < contents.size(); i++)
	{
		std::cout << contents[i] << std::endl;
	}

	file.close();
}

void Example2()
{
	std::vector<char> contents;
	{
		std::ifstream file;
		file.open("./data/Murphy.txt");

		char character;
		while (file.get(character))
		{
			contents.push_back(character);
		}

		file.close();
	}
	
	{
		std::ofstream file;
		file.open("./data/Murphy2.txt");

		for (int i = 0; i < contents.size(); i++)
		{
			file.put(contents[i]);
		}

		file.close();
	}
}

void Example3()
{
	std::ifstream file;
	file.open("./data/Murphy.txt");

	std::vector<char> contents = ReadFile(file);
	for (int i = 0; i < contents.size(); i++)
	{
		std::cout << contents[i];
	}

	//file.close();

	//static constexpr int eofbit = 0x1;
	//static constexpr int failbit = 0x2;

	std::cout << "Begin" << std::endl;
	contents.clear();
	file.seekg(0, std::ios::beg);

	int state_b = file.rdstate();
	file.close();
	//file.open("./data/Murphy.txt");
	//contents = ReadFile(file);
	//for (int i = 0; i < contents.size(); i++)
	//{
	//	std::cout << contents[i];
	//}
	//file.close();
	//std::cout << "End" << std::endl;
}
