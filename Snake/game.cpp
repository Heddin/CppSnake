#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;

const int width = 40;
const int height = 20;

int x, y, fruit_x, fruit_y, score;

int tail_x[100], tail_y[100];
int n_tail = 0;

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

	system("cls"); 

	cout << "**** GAME OVER ****" << endl;
	cout << "Final Score: " << score << endl;
	cout << "press any key..." << endl;

	_getch();
	
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
				bool print = false;
				for (int k = 0; k < n_tail; k++) {
					if (tail_x[k] == j && tail_y[k] == i) {
						print = true;
						cout << 'o';
					}
				}
				if(!print) cout << ' ';
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


	int prev_x = tail_x[0];
	int prev_y = tail_y[0];

	int prev_x2, prev_y2;

	tail_x[0] = x;
	tail_y[0] = y;

	for (int i = 1; i < n_tail; i++) {
		prev_x2 = tail_x[i];
		prev_y2 = tail_y[i];
		
		tail_x[i] = prev_x;
		tail_y[i] = prev_y;

		prev_x = prev_x2;
		prev_y = prev_y2;
	}

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


	if (x >= width - 1) {
		x = 0;
	}
	else if (x < 0) {
		x = width - 2;
	}

	if (y >= height) {
		y = 0;
	}else if (y < 0) {
		y = height - 2;
	}

	for (int i = 0; i < n_tail; i++) {
		if (tail_x[i] == x && tail_y[i] == y) {
			gameOver = true;
		}
	}

	if (x == fruit_x && y == fruit_y) {
		score += 10;
		fruit_x = rand() % width;
		fruit_y = rand() % height;
		n_tail++;
	}

}