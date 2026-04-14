#include <Windows.h>
#include <iostream>
#include <vector>

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
char world[SCREEN_SIZE][SCREEN_SIZE];

char map[SCREEN_SIZE][SCREEN_SIZE]
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

const char win[SCREEN_SIZE][SCREEN_SIZE]
{
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '#' },
	{ '#', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '#' },
	{ '#', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '#' },
	{ '#', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '#' },
	{ '#', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '#' },
	{ '#', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
};

const char loss[SCREEN_SIZE][SCREEN_SIZE]
{
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '|', '-', '-', '-', '-', '-', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
};

// Render pipeline:
// 1. Update world buffer (map, player and enemy values)
// 2. Draw world buffer

void DrawChar(char c, short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
	std::cout << c;
}

void DrawScreen(const char screen[SCREEN_SIZE][SCREEN_SIZE])
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	for (int row = 0; row < SCREEN_SIZE; row++)
	{
		for (int col = 0; col < SCREEN_SIZE; col++)
		{
			std::cout << screen[row][col];
		}
		std::cout << std::endl;
	}
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

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

struct Entity
{
	int x = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	Direction facing = UP;
	char sprite = '!';
	bool destroy = false;
};

bool Overlap(const Entity& a, const Entity& b)
{
	return a.x == b.x && a.y == b.y;
}

bool CanMove(Entity entity, const char screen[SCREEN_SIZE][SCREEN_SIZE])
{
	char tile = screen[entity.y + entity.dy][entity.x + entity.dx];
	return tile != '#' && tile != '$';
}

void Move(Entity& entity, char screen[SCREEN_SIZE][SCREEN_SIZE])
{
	entity.x += entity.dx;
	entity.y += entity.dy;
	entity.x = Clamp(entity.x, 0, SCREEN_SIZE - 1);
	entity.y = Clamp(entity.y, 0, SCREEN_SIZE - 1);
}

void Draw(Entity entity, char screen[SCREEN_SIZE][SCREEN_SIZE])
{
	screen[entity.y][entity.x] = entity.sprite;
}

struct EnemyState
{
	int x_min, x_max;
	//int y_min, y_max;
};

void InitEnemyState(Entity enemy, EnemyState* state, int length)
{
	state->x_min = enemy.x - length / 2;
	state->x_max = enemy.x + length / 2;
}

enum GameState
{
	GAME_PLAY,
	GAME_WIN,
	GAME_LOSS
};

int main()
{
	float player_move_time_current = 0.0f;
	float player_move_time_total = 0.25f;

	float player_shoot_time_current = 0.0f;
	float player_shoot_time_total = 0.75f;

	float enemy_move_time_current = 0.0f;
	float enemy_move_time_total = 0.5f;

	float bullet_move_time_current = 0.0f;
	float bullet_move_time_total = 0.1f;

	Entity player;
	player.x = SCREEN_SIZE / 2;
	player.y = SCREEN_SIZE / 2;
	player.dx = 0;
	player.dy = 0;
	player.sprite = '@';

	Entity enemy;
	enemy.x = SCREEN_SIZE / 4;
	enemy.y = SCREEN_SIZE / 2;
	enemy.dx = 1;
	enemy.dy = 0;
	enemy.sprite = '^';

	std::vector<Entity> bullets;

	EnemyState enemy_state;
	InitEnemyState(enemy, &enemy_state, 6);

	GameState game_state = GAME_PLAY;

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

		// Add map to world (must happen first so entities can do collision correctly)
		for (int row = 0; row < SCREEN_SIZE; row++)
		{
			for (int col = 0; col < SCREEN_SIZE; col++)
			{
				world[row][col] = map[row][col];
			}
		}
		
		player_move_time_current += dt;
		player_shoot_time_current += dt;
		enemy_move_time_current += dt;
		bullet_move_time_current += dt;

		if (player_move_time_current >= player_move_time_total)
		{
			player_move_time_current = 0.0f;

			player.dy = 0;
			player.dx = 0;
			if (GetAsyncKeyState(KEY_W))
			{
				player.dy--;
				player.facing = UP;
			}
			else if (GetAsyncKeyState(KEY_S))
			{
				player.dy++;
				player.facing = DOWN;
			}
			else if (GetAsyncKeyState(KEY_A))
			{
				player.dx--;
				player.facing = LEFT;
			}
			else if (GetAsyncKeyState(KEY_D))
			{
				player.dx++;
				player.facing = RIGHT;
			}

			if (CanMove(player, world))
			{
				Move(player, world);
			}
		}
		
		if (GetAsyncKeyState(VK_SPACE) && player_shoot_time_current >= player_shoot_time_total)
		{
			player_shoot_time_current = 0.0f;

			int dx = 0;
			int dy = 0;
			switch (player.facing)
			{
			case LEFT:
				dx = -1;
				dy = 0;
				break;

			case RIGHT:
				dx = 1;
				dy = 0;
				break;

			case UP:
				dx = 0;
				dy = -1;
				break;

			case DOWN:
				dx = 0;
				dy = 1;
				break;
			}

			Entity bullet;
			bullet.x = player.x + dx;
			bullet.y = player.y + dy;
			bullet.dx = dx;
			bullet.dy = dy;
			bullet.sprite = 'o';

			bullets.push_back(bullet);
		}

		if (bullet_move_time_current >= bullet_move_time_total)
		{
			bullet_move_time_current = 0.0f;
			for (Entity& bullet : bullets)
			{
				if (CanMove(bullet, world))
					Move(bullet, world);
				else
					bullet.destroy = true;
			}
		}

		if (enemy_move_time_current >= enemy_move_time_total)
		{
			enemy_move_time_current = 0.0f;

			int x = enemy.x + enemy.dx;
			if (x > enemy_state.x_max || x < enemy_state.x_min)
				enemy.dx *= -1;

			Move(enemy, world);
		}

		Draw(player, world);
		Draw(enemy, world);
		for (Entity& bullet : bullets)
			Draw(bullet, world);

		if (Overlap(player, enemy))
		{
			game_state = GAME_LOSS;
		}

		// Render world
		switch (game_state)
		{
		case GAME_PLAY:
			DrawScreen(world);
			break;

		case GAME_WIN:
			DrawScreen(win);
			break;

		case GAME_LOSS:
			DrawScreen(loss);
			break;
		}

		DWORD frame_end = timeGetTime();
		dt = (frame_end - frame_start) / 1000.0f;
	}

	return 0;
}
