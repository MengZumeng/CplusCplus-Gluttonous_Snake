#pragma once
#include<iostream>
#include "wall.h"
#include "food.h"
#include<windows.h>
using namespace std;

void gotoxy(HANDLE hOut, int x, int y);

class Snake
{
public:
	Snake(Wall & tempWall, Food & tempFood);

	enum { UP = 'w',DOWN = 's',LEFT = 'a',RIGHT = 'd' ,QUIT = 'q'};
	struct Point {
		//value
		int x;
		int y;
		//pointer
		Point* next;
	};

	void initSnake();

	void destoryPoint();

	void addPoint(int x, int y);

	void delPoint();

	bool moveSnake(char key);

	//get sleep time
	int getSleepTime();
	//get length of snake
	int countList();

	//get score
	int getScore();

	//head point
	Point* hPoint;

	Wall & wall;
	Food & food;
	bool isRool;
};