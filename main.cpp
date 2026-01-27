#include <string>

struct Attachment
{
	std::string name;
	std::string type;
	std::string color;
	std::string manufacturer;
	int durability;
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
	int bullets;
	int damage;
	std::string name;

	Attachment attachments[2];
};

struct Player
{
	void EquipWeapon() { can_attack = true; }

	std::string name;
	bool can_attack;

	float health;
	float speed;

	Weapon weapons[3];
};

// Extra practice: modify this program so Player stores 3 pointers to weapons, and Weapon stores 2 pointers to attachments (to save memory)!
int main()
{
	Attachment attachments[2];
	attachments[0].name = "Scope";
	attachments[1].name = "Suppressor";
	
	Weapon weapons[3];
	weapons[0].name = "Rifle";
	weapons[0].clip_size = 30;
	weapons[0].clip_count = 5;

	weapons[1].name = "Shotgun";
	weapons[1].clip_size = 10;
	weapons[1].clip_count = 2;

	weapons[2].name = "Grenade";
	weapons[2].clip_size = 1;
	weapons[2].clip_count = 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			weapons[i].attachments[j] = attachments[j];
		}
	}

	Player* players = new Player[4];
	players[0].name = "Connor";
	players[0].can_attack = false;
	
	players[1].name = "Enemy 1";
	players[1].can_attack = true;
	
	// Assign the 1st player (player[0])'s weapons to be those we just made!
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			players[i].weapons[j] = weapons[j];
	}

	delete[] players;
	return 0;
}
