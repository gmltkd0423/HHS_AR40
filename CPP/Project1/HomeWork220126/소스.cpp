#include<iostream>

class MyInt
{
public:
	int Value;

public:
	MyInt(int _Value)
		:Value(_Value)
	{

	}

	//���������� �ǿ����ڿ� ���� ���������� �����ѵ� �� �ǿ������� �޸𸮸� �����ϴ� lvalue�� ����
	MyInt& operator++()
	{
		Value += 1;
		return *this;
	}


	//���������� �ǿ����ڿ� ���� ���������� �����ѵ� ���������� �����ϱ� ���� ���� rvalue�� ����
	const MyInt operator++(int)
	{
		MyInt temp(Value);
		Value += 1;
		return temp;
	}

	friend std::ostream& operator << (std::ostream& out, const MyInt& myint)
	{
		out << myint.Value;
		return out;
	}

};


int main()
{
	MyInt Result = 4;

	std::cout << Result << std::endl;
	std::cout << ++Result << std::endl;
	std::cout << Result++ << std::endl;
	std::cout << ++(++Result) << std::endl;
	//std::cout << (Result++)++ << std::endl;
	std::cout << Result << std::endl;
}
