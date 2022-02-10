#include "Player.h"
#include <conio.h>
#include "ConsoleGlobalInst.h"

Player::Player(TextScreen* _Screen, const char* _Text)
	: ConsoleObject(_Screen, _Text, _Screen->GetSize().GetHalfVector()),
		flag(false)
{
}

Player::~Player()
{
}


void Player::Update()
{
	// GlobalValue::AllMonsters

	// AllMonsters[2];

	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		// 화면바깥으로 이동하면 이동이 안되게 해주세요.
		SetMove({ -1, 0 });
		CheckPos();
		break;
	case 'd':
	case 'D':
		SetMove({ 1, 0 });
		CheckPos();
		break;
	case 'w':
	case 'W':
		SetMove({ 0, -1 });
		CheckPos();
		break;
	case 's':
	case 'S':
		SetMove({ 0, 1 });
		CheckPos();
		break;
	case 'q':
	case 'Q':
		// 무슨일인가가 벌어져서
		// 게임이 종료된다.
		flag = true;
		break;
	default:
		break;
	}


}

