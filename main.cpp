#include <iostream>
#include <string>

class Player
{
public:
	std::string name;

	static void SetBaseHealth(int base_health) { Player::base_health = base_health; }

	void AddHealth(int health)
	{
		this->health = base_health + health;
	}

	int GetHealth() { return health; }

private:
	static int base_health;
	int health;
};

int Player::base_health = 0;

bool operator>(Player a, Player b)
{
	return a.GetHealth() > b.GetHealth();
}

std::ostream& operator<<(std::ostream& out, Player player)
{
	out << player.name << " has " << player.GetHealth() << " health.";
	return out;
}

int main()
{
	Player tank, assassin;
	tank.name = "Tank";
	assassin.name = "Assassin";

	int base_health, tank_bonus_health, assassin_bonus_health;

	std::cout << "Please enter the base health of all players" << std::endl;
	std::cin >> base_health;

	std::cout << "Please enter the bonus health of " << tank.name << std::endl;
	std::cin >> tank_bonus_health;
	
	std::cout << "Please enter the bonus health of " << assassin.name << std::endl;
	std::cin >> assassin_bonus_health;

	Player::SetBaseHealth(base_health);
	tank.AddHealth(tank_bonus_health);
	assassin.AddHealth(assassin_bonus_health);

	std::cout << tank << std::endl;
	std::cout << assassin << std::endl;

	return 0;
}

