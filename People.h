#pragma once
#include "Body.h"

class Food: public Body
{
public:
	Food(void);
	void draw(Graphics^ graph);
	void rand_location();
};

class People: public Body
{
public:
	People(void);
	bool eat(Food f);
	bool death();
};

