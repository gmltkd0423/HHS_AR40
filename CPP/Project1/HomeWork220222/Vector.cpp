// Vector.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "GameVector.h"

GameVector<int> ReturnVector()
{
    GameVector<int> NewArr;

    NewArr.resize(20);

    return NewArr;
}

int main()
{
    ////std::list<int> NewList;
    ////NewList.remove(1);

    //// vector��
    //// ������ �迭 �ڷᱸ��

    //// �ڷḦ �ִ� �Լ�
    //// �ڷḦ �����ϴ� �Լ�
    //// �ڷḦ �����ϴ� �Լ�

    //// [3][2][1][10][20]

    //// �̶� ���ο���
    //// ���� �迭�� �������ϴ�.
    //std::vector<int> Vector;

    //for (size_t i = 0; i < 20; i++)
    //{
    //    Vector.push_back(i);
    //    std::cout << "Capa" << Vector.capacity() << std::endl;
    //    std::cout << "Size" << Vector.size() << std::endl;
    //    std::cout << "-----------------------------------" << std::endl;
    //}

    //for (size_t i = 0; i < 20; i++)
    //{
    //    std::cout << Vector[i] << std::endl;
    //}

    //
    //Vector.push_back(2); 
    //Vector.push_back(1); 
    //Vector.push_back(10);
    //Vector.push_back(20);


    //// [][][][][]
    //// vector 

    //std::cout << Vector[2] << std::endl;

    //{
    //    GameVector<int> MyVector = ReturnVector();

    //}

    //{
    //    std::vector<int> Arr;
    //    Arr.resize(20);

    //    // Arr.reserve(20);

    //    GameVector<int> MyVector;
    //    MyVector.resize(20);
    //    MyVector.reserve(20);


    //    // unsigned __int64
    //    for (size_t i = 0; i < 40; i++)
    //    {
    //        MyVector.push_back((int)i);
    //        std::cout << "Capa" << MyVector.capacity() << std::endl;
    //        std::cout << "Size" << MyVector.size() << std::endl;
    //        std::cout << "-----------------------------------" << std::endl;
    //    }


    //    for (size_t i = 0; i < 40; i++)
    //    {
    //        std::cout << MyVector[i] << std::endl;
    //    }
    //}

    GameVector<int> Vector;
    Vector.push_back(1);
    Vector.push_back(9);
    Vector.push_back(8);
    Vector.push_back(7);
    Vector.push_back(5);
    Vector.push_back(3);
    Vector.push_back(2);
    Vector.push_back(11);
    Vector.push_back(19);
    Vector.push_back(14);
    Vector.push_back(7);
    Vector.push_back(4);

    //�������� ����
    Vector.Sort();

    for (size_t i = 0; i < Vector.size(); i++)
    {
        std::cout << Vector[i] << std::endl;
    }
}
