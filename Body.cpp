#include "StdAfx.h"
#include "Body.h"


Body::Body(void)
{
}

void Body::draw(Graphics^ graph)
{
	Brush^ brush_b = gcnew SolidBrush(Color::Black);
	graph->FillRectangle(brush_b,x - PICTURE_WIDTH/2, y - PICTURE_HEIGHT/2, PICTURE_WIDTH, PICTURE_HEIGHT);
}