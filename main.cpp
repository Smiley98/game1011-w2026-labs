#include <Windows.h>
#include <iostream>

const int SCREEN_SIZE = 16;

char world[SCREEN_SIZE][SCREEN_SIZE]
{
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', '$', '$', '$', '$', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
};

void Draw(char c, short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
	std::cout << c;
}

struct Entity
{
	int x;
	int y;
};

int main()
{
	Entity player;
	player.x = SCREEN_SIZE / 2;
	player.y = SCREEN_SIZE / 2;

	bool running = true;
	while (running)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			running = false;

		for (int row = 0; row < SCREEN_SIZE; row++)
		{
			for (int col = 0; col < SCREEN_SIZE; col++)
			{
				std::cout << world[row][col];
			}
			std::cout << std::endl;
		}

		// TODO -- Render everything to buffer instead of moving the cursor every draw call to fix flickering
		Draw('@', player.x, player.y);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}

	return 0;
}
