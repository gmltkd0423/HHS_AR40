#include "Head.h"
#include <conio.h>
#include <list>

Head::Head()
{
}

Head::~Head() 
{
	if (!AllBody.empty())
	{
		std::list<Body*>::iterator iter = AllBody.begin();
		std::list<Body*>::iterator iterEnd = AllBody.end();

		for (; iter != iterEnd; ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		AllBody.clear();
	}
}


void Head::Update() 
{
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		// 화면바깥으로 이동하면 이동이 안되게 해주세요.
		InScreenMovement({ -1, 0 });
		break;
	case 'd':
	case 'D':
		InScreenMovement({ 1, 0 });
		break;
	case 'w':
	case 'W':
		InScreenMovement({ 0, -1 });
		break;
	case 's':
	case 'S':
		InScreenMovement({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		// 무슨일인가가 벌어져서
		// 게임이 종료된다.
		Death();
		return;
	default:
		break;
	}

	return;
}



void Head::OverLap(ConsoleObject* _Link)
{
	AllBody.push_back((Body*)_Link);
}
