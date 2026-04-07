#include <Windows.h>
#include <iostream>

#pragma comment(lib, "Winmm.lib")

enum Key
{
	KEY_0 = 0x30,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,

	KEY_A = 0x41,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z
};

const int SCREEN_SIZE = 16;

char screen_buffer[SCREEN_SIZE][SCREEN_SIZE];

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

template<typename T>
T Clamp(T value, T min, T max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return value;
}

struct Entity
{
	int x;
	int y;
};

int main()
{
	float player_time_current = 0.0f;
	float player_time_total = 0.25f;

	Entity player;
	player.x = SCREEN_SIZE / 2;
	player.y = SCREEN_SIZE / 2;

	float dt = 0.0f;
	bool running = true;

	// Use Win32 API to make cursor invisible so we don't see it jumping all over the place 
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursor;
		GetConsoleCursorInfo(out, &cursor);
		cursor.bVisible = FALSE;
		SetConsoleCursorInfo(out, &cursor);
	}

	while (running)
	{
		DWORD frame_start = timeGetTime();

		if (GetAsyncKeyState(VK_ESCAPE))
			running = false;
		
		// Update the player based on ticks rather than frames (so it doesn't fly off the screen)
		player_time_current += dt;
		if (player_time_current >= player_time_total)
		{
			player_time_current = 0.0f;
			if (GetAsyncKeyState(KEY_W))
			{
				player.y--;
			}
			if (GetAsyncKeyState(KEY_S))
			{
				player.y++;
			}
			if (GetAsyncKeyState(KEY_A))
			{
				player.x--;
			}
			if (GetAsyncKeyState(KEY_D))
			{
				player.x++;
			}

			player.x = Clamp(player.x, 0, SCREEN_SIZE - 1);
			player.y = Clamp(player.y, 0, SCREEN_SIZE - 1);
		}

		for (int row = 0; row < SCREEN_SIZE; row++)
		{
			for (int col = 0; col < SCREEN_SIZE; col++)
			{
				screen_buffer[row][col] = world[row][col];
			}
		}

		screen_buffer[player.y][player.x] = '@';

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
		for (int row = 0; row < SCREEN_SIZE; row++)
		{
			for (int col = 0; col < SCREEN_SIZE; col++)
			{
				std::cout << screen_buffer[row][col];
			}
			std::cout << std::endl;
		}
		
		// TODO -- Render everything to buffer instead of moving the cursor every draw call to fix flickering
		//Draw('@', player.x, player.y);

		DWORD frame_end = timeGetTime();
		dt = (frame_end - frame_start) / 1000.0f;
	}

	return 0;
}
