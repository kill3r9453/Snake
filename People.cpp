#include "StdAfx.h"
#include "People.h"
#include "stdlib.h"
#include <math.h>
#include <time.h>


People::People(void)
{
}

bool People::eat(Food f)
{
	float x_err = (f.x - this->x);
	float y_err = (f.y - this->y);
	int r_sq = (int)sqrt(x_err*x_err + y_err*y_err);
	if (r_sq > PICTURE_WIDTH - 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Food::Food(void)
{
}

//���s�w�qdraw�禡
void Food::draw(Graphics^ graph)
{
	Brush^ brush_r = gcnew SolidBrush(Color::Red); //�w�q�����C��
	graph->FillRectangle(brush_r,this->x - PICTURE_WIDTH/2, this->y - PICTURE_HEIGHT/2,
		PICTURE_WIDTH,PICTURE_HEIGHT);
}

//�����H����m
void Food::rand_location()
{
	static int k = 0;
	this->y = (int)(rand()%FIELD_HEIGHT);
	this->x = (int)(rand()%FIELD_WIDTH);
}