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

	//전위증가는 피연산자에 대해 증가연산을 진행한뒤 그 피연산자의 메모리를 참조하는 lvalue를 리턴
	MyInt& operator++()
	{
		Value += 1;
		return *this;
	}


	//후위증가는 피연산자에 대한 증가연산을 진행한뒤 증가연산을 진행하기 전의 값인 rvalue를 리턴
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
