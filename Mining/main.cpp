#include "vld.h"
#include "World.h"
#include "iItem.h"
#include <ctime>
#include <iostream>
#include <conio.h>

int main()
{
	srand(unsigned int(time(0)));

	World::Get().Update();

	return 0;
}