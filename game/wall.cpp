#include "Wall.h"

void Wall::initWall() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++)
		{
			//set wall
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) {
				gameArray[i][j] = '#';
			}
			else {
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::drawWall() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << gameArray[i][j] << " ";
		}
		if (i == 5) { cout << "create by zhuzhu"; }
		if (i == 6) { cout << "w: move up"; }
		if (i == 7) { cout << "s: move down"; }
		if (i == 8) { cout << "a: move left"; }
		if (i == 9) { cout << "d: move right"; }
		if (i == 10) { cout << "quit: q"; }

		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c) {
	if (0 <= x < ROW && 0 <= y < COL) {
		gameArray[x][y] = c;
	}
	else {
		cout << "index over" << endl;
	}
}


char Wall::getWall(int x, int y) {
	if (0 <= x < ROW && 0 <= y < COL) {
		return gameArray[x][y];
	}
	else {
		cout << "index over" << endl;
	}
}