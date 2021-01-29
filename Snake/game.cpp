#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;

const int width = 40;
const int height = 20;

int x, y, fruit_x, fruit_y, score;

enum eDirection  {
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};


eDirection dir;


void Setup();
void Draw();
void Input();
void Logic();

int main() {
	Setup();

	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}


	return 0;
}


void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;

	fruit_x = rand() % width;
	fruit_y = rand() % height;

	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width+1; i++) {
		cout << '#';
	}
	cout << endl;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				cout << '#';
			}
			if (i == y && j == x) {
				cout << '0';
			}
			else if (i == fruit_y && j == fruit_x)
			{
				cout << 'F';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++) {
		cout << '#';
	}
	cout << endl;

	cout << "Score: " << score << "\n";
}
void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;

		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Logic() {

	switch (dir)
	{
	case LEFT: x--;
		break;
	case RIGHT: x++;
		break;
	case UP: y--;
		break;
	case DOWN: y++;
		break;
	}


	if (x > width || x < 0) {
		gameOver = true;
	}

	if (y > height || y < 0) {
		gameOver = true;
	}

	if (x == fruit_x && y == fruit_y) {
		score += 10;
		fruit_x = rand() % width;
		fruit_y = rand() % height;
	}

}