#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

void Example1();	// Save single object to file
void Example2();	// Save multiple objects to file (save array to file)
void Example3();

struct Game
{
	int lives_count;
	int achievements_count;

	int health;
	int mana;
};

struct Achievement
{
	int points;
	bool unlocked;
};

int main()
{
	Example1();
	Example2();
	return 0;
}

void Example1()
{
	const std::string file_name = "./data/File.bin";

	{
		Game game;
		game.achievements_count = 10;
		game.lives_count = 3;
		game.health = 100;
		game.mana = 50;

		std::ofstream file;
		file.open(file_name, std::ios::binary);
		file.write((char*)&game, sizeof(Game));
		file.close();
	}

	{
		Game game;

		std::ifstream file;
		file.open(file_name, std::ios::binary);
		file.read((char*)&game, sizeof(Game));
		file.close();
	}
}

void Example2()
{
	const std::string file_name = "./data/Objects.bin";

	{
		std::vector<Achievement> achievements;
		achievements.resize(10);
		for (int i = 0; i < achievements.size(); i++)
		{
			achievements[i].points = (i + 1) * 10;
			achievements[i].unlocked = i % 2 == 0;
		}

		std::ofstream file;
		file.open(file_name, std::ios::binary);
		file.write((char*)achievements.data(), sizeof(Achievement) * achievements.size());
		file.close();
	}

	{
		std::vector<Achievement> achievements;
		achievements.resize(10);

		std::ifstream file;
		file.open(file_name, std::ios::binary);
		file.read((char*)achievements.data(), sizeof(Achievement) * achievements.size());
		file.close();
	}
}

void Example3()
{

}
