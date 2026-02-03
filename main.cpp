#include <iostream>
#include <string>

struct Player
{
	int health;
	void AddHealth(int health)
	{
		this->health = base_health + health;
	}

	static int base_health;
};

int Player::base_health = 0;

int main()
{
	Player tank, assassin;
	Player::base_health = 100;	// Initial health for all players
	tank.AddHealth(150);		// Tank health = 100 base_health + 150 bonus health	
	assassin.AddHealth(25);		// Assassin health = 100 base_health + 25 bonus health
	
	return 0;
}

