#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"wall.h"
#include"snake.h"
#include "food.h"
#include<ctime>
#include<conio.h>
#include<windows.h>

using namespace std;

//cmd output index relocal

HANDLE hOut_main = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {

	srand((unsigned int)time(NULL));

	bool isDead = false;

	char preKey = NULL;

	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.initSnake();



	//customer input
	while (!isDead) {
		char key = _getch();
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}
		if ( key == snake.QUIT) {
			isDead = true;
			break;
		}
		do {
			if (key == snake.LEFT || key == snake.RIGHT || key == snake.UP || key == snake.DOWN) {
				if (key == snake.LEFT && preKey == snake.RIGHT ||
					key == snake.DOWN && preKey == snake.UP ||
					key == snake.RIGHT && preKey == snake.LEFT ||
					key == snake.UP && preKey == snake.DOWN
					) {
					key = preKey;
				}
				else {
					preKey = key;
					if (snake.moveSnake(key) == true) {
						//system("cls");
						//wall.drawWall();
						gotoxy(hOut_main, 0, Wall::ROW );
						cout << "score:" << snake.getScore() << endl;
						Sleep(snake.getSleepTime());
					}
					else {
						isDead = true;
						break;
					}
				}
			}
			else {
				key = preKey;
			}
		} while (!_kbhit());

	}
	system("pause");
	return EXIT_SUCCESS;
}