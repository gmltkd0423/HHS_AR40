#include<iostream>

int Toint(const char* _Left)
{
	int value = 0;
	while (*_Left)
	{
		if (*_Left >= '0' && *_Left <= '9')
		{
			value = (value * 10) + *_Left - '0';   //value*10 = �������� ���ڸ��� ������ �ű�¿���
		}                                          //*_Left - '0'  *_Left�� 1�̸� 1�� �ƽ�Ű�ڵ尪�� 49 0�� 48�̹Ƿ� 49 - 48 = 1

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