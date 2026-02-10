#include <iostream>
#include <string>

int main()
{
	int health;
	float damage;
	std::string name;

	std::cout << "Please input a value between 1 and 100 for health." << std::endl;
	std::cin >> health;
	std::cout << "Your character has " << health << " health." << std::endl;

	std::cout << "Please input a value between 10 and 250 for damage." << std::endl;
	std::cin >> damage;
	std::cout << "Your character has " << damage << " damage." << std::endl;

	// Note: cin can only read one word at a time, so no need to store more than 1-word answers for stuff like character or weapon names
	// Optionally, feel free to investigate how to read multiple words from the user (different command than cin)!
	std::cout << "Please input your character's name." << std::endl;
	std::cin >> name;
	std::cout << "Your character is named " << name << std::endl;

	return 0;
}
