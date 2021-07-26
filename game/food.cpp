#include "food.h"
#include<windows.h>

//cmd output index relocal
void gotoxy_food(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

HANDLE hOut_food = GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall &tempwall) :wall(tempwall) {

}

void Food::setFood() {
	while (true) {
		foodx = rand() % (Wall::ROW - 2) + 1;
		foody = rand() % (Wall::COL - 2) + 1;

		if (wall.getWall(foodx, foody) == ' ') {
			wall.setWall(foodx, foody,'*');
			gotoxy_food(hOut_food, foody * 2, foodx);
			cout << '*';
			break;
		}
	}

	
}