#include<iostream>

int main()
{
	int arr[10];
	int index = 0;


	//짝수로채우기
	for (int i = 0; index < 10; i++)
	{
		if (i % 2 == 0)
		{
			arr[index] = i;
			index++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	return 0;
}