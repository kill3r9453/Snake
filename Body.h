#pragma once
#define PICTURE_WIDTH 25
#define PICTURE_HEIGHT 25
#define FIELD_WIDTH 500
#define FIELD_HEIGHT 500
#define FOOD_NUM 1

using namespace System::Drawing;

class Body
{
public:	
	int x;
	int y;
	int death;
	Body(void);
	virtual void draw(Graphics^ graph);
};

