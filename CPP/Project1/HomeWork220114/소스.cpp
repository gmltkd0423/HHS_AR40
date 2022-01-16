#include<iostream>

int Toint(const char* _Left)
{
	int value = 0;
	while (*_Left)
	{
		if (*_Left >= '0' && *_Left <= '9')
		{
			value = (value * 10) + *_Left - '0';   //value*10 = 기존값을 한자리씩 앞으로 옮기는역할
		}                                          //*_Left - '0'  *_Left가 1이면 1의 아스키코드값은 49 0은 48이므로 49 - 48 = 1

		_Left++;
	}

	return value;
}

int main()
{
	int Value = Toint("158915");

	printf_s("%d", Value);

	return 0;
}