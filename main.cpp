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

std::istream& operator>>(std::istream& in, Player& player)
{
	int bonus_health;
	in >> player.name >> bonus_health;
	player.AddHealth(bonus_health);
	return in;
}

int main()
{
	Player player1, player2;
	int base_health;

	std::cout << "Please enter the base health of all players" << std::endl;
	std::cin >> base_health;
	Player::SetBaseHealth(base_health);

	std::cout << "Please enter the name and bonus health of Player 1" << std::endl;
	std::cin >> player1;
	
	std::cout << "Please enter the name and bonus health of Player 2" << std::endl;
	std::cin >> player2;

	std::cout << "Player 1 " << player1 << std::endl;
	std::cout << "Player 2 " << player2 << std::endl;

	// Test out our overloaded greater-than-comparison operator!
	if (player1 > player2)
		std::cout << player1.name << " has more health than " << player2.name << std::endl;
	else
		std::cout << player2.name << " has more health than " << player1.name << std::endl;

	return 0;
}