// The difference between "class" vs "struct" is all attributes of a struct
// are public by default, whereas all attrubtes of a class are private by default.
// (I use structs for everything because I'm lazy and don't believe in encapsulation).
#include <string>

// Player must have 5 attributes (attributes are members & methods)
struct Player
{
	void EquipWeapon() { can_attack = true; }

	std::string name;
	bool can_attack;

	// TODO -- Add two more attributes of your choice
};

struct Weapon
{
	// TODO -- Add 5 attributes of your choice
};

struct Attachment
{
	// TODO -- Add 5 attributes of your choice
};

int main()
{
	// This allocated 4 players on the stack (compiler-managed memory)
	//Player players[4];

	// In order to allocate on the heap, we must use the new operator
	Player* players = new Player[4];
	players[0].name = "Connor";
	players[0].can_attack = false; // I don't want to attack you, I'm a nice professor :)
	
	players[1].name = "Enemy 1";
	players[1].can_attack = true; // This guy is not as nice
	// TODO -- make the other two players

	// TODO -- make a heap-allocated array of 3 weapons
	// TODO -- make a heap-allocated array of 2 attachments

	// Since the heap is managed by the programmer rather than the compiler,
	// we must remember to call delete in order to avoid leaking memory!
	delete[] players;
	return 0;
}
