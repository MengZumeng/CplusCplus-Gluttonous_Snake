#include "snake.h"


//cmd output index relocal
void gotoxy(HANDLE hOut, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

Snake::Snake(Wall & tempWall,Food & tempFood) :wall(tempWall),food(tempFood)
{
	hPoint = NULL;
	isRool = false;
}

void Snake::initSnake() {
	destoryPoint();

	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
	addPoint(5, 6);
}


//Destory all node 
void Snake::destoryPoint() {
	Point *cPoint = hPoint;

	while (hPoint != NULL) {
		cPoint = hPoint->next;
		delete hPoint;

		hPoint = cPoint;
	}
}

void Snake::addPoint(int x,int y) {
	//create new node
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	if (hPoint != NULL) {
		wall.setWall(hPoint->x, hPoint->y, '=');
		gotoxy(hOut, hPoint->y * 2, hPoint->x);
		cout << '=';
	}

	newPoint->next = hPoint;
	hPoint = newPoint;
	wall.setWall(hPoint->x, hPoint->y, '@');
	gotoxy(hOut, hPoint->y * 2, hPoint->x);
	cout << '@';
}

void Snake::delPoint() {
	if (hPoint == NULL || hPoint-> next == NULL) {
		return;
	}
	Point* curP = hPoint->next;
	Point* preP = hPoint;

	while (curP->next != NULL) {
		preP = preP->next;
		curP = curP->next;
	}
	wall.setWall(curP->x, curP->y, ' ');
	gotoxy(hOut, curP->y * 2, curP->x);
	cout << ' ';

	delete curP;

	curP = NULL;
	preP->next = NULL;
}

bool Snake::moveSnake(char key) {
	int x = hPoint->x;
	int y = hPoint->y;

	switch (key) {
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	}

	Point* curP = hPoint->next;
	Point* preP = hPoint;

	while (curP->next != NULL) {
		preP = preP->next;
		curP = curP->next;
	}
	if (curP->x == x && curP->y == y) {
		//crash the end of sanke
		isRool = true;
	}
	else {
		if (wall.getWall(x, y) == '#' || wall.getWall(x, y) == '=') {
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "score:" <<getScore() << endl;
			cout << "GAME OVER" << endl;
			return false;
		}
	}

	if (wall.getWall(x, y) == '*') {
		addPoint(x, y);
		food.setFood();
		return true;
	}
	else {
		addPoint(x, y);
		delPoint();
		if (isRool == true) {
			wall.setWall(x, y, '@');
			gotoxy(hOut, y * 2, x);
			cout << '@';
		}
		return true;
	}
}

int Snake::getSleepTime() {
	int sleepTime = 0;
	int size = countList();
	if (size < 20) {
		sleepTime = 300;
	}
	else if (size >= 20 && size <= 40) {
		sleepTime = 100;
	}
	else {
		sleepTime = 50;
	}
	return sleepTime;
}

int Snake::countList() {
	int size = 0;
	Point *curPoint = hPoint;
	while (curPoint != NULL) {
		size++;
		curPoint = curPoint->next;
	}
	return size;
}

int Snake::getScore() {
	int size = countList();
	int score = (size-4) * 100;

	return score;

}



