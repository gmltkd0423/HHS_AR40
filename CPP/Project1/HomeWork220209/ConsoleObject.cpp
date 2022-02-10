#include "ConsoleObject.h"

ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
)
	: Screen_(_Screen)
	, Pos_(_Pos)
{
	//if (nullptr == _Screen)
	//{
	//	assert(false);
	//}

	if (nullptr == _Text)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		Text_[i] = _Text[i];
	}
}

ConsoleObject::~ConsoleObject()
{
}

void ConsoleObject::CheckPos()
{
	if (0 > Pos_.x_)
	{
		SetMove({ 1, 0 });
	}

	if (0 > Pos_.y_)
	{
		SetMove({ 0, 1 });
	}

	if (Screen_->GetXSize() <= Pos_.x_)
	{
		SetMove({ -1, 0 });
	}

	if (Screen_->GetYSize() <= Pos_.y_)
	{
		SetMove({ 0, -1 });
	}
}

void ConsoleObject::Render()
{
	if (nullptr == Screen_)
	{
		assert(false);
	}

	Screen_->SetPixel(Pos_, Text_);
}
