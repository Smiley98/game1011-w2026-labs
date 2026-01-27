#include <string>

struct Player
{
	void EquipWeapon() { can_attack = true; }

	std::string name;
	bool can_attack;

	float health;
	float speed;
};

struct Weapon
{
	int Ammo() { return clip_size * clip_count; }
	bool Reload()
	{
		bool reloaded = clip_count > 0;
		clip_count--;
		bullets = clip_size;
		return reloaded;
	}

	int clip_count;
	int clip_size;
	int damage;
	int bullets;
};

struct Attachment
{
	std::string name;
	std::string type;
	std::string color;
	std::string manufacturer;
	int durability;
};

int main()
{
	Player* players = new Player[4];
	players[0].name = "Connor";
	players[0].can_attack = false;
	
	players[1].name = "Enemy 1";
	players[1].can_attack = true;
	delete[] players;


	return 0;
}
