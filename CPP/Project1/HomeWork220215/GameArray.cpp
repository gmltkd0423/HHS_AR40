// GameArray.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <assert.h>
#include <crtdbg.h>

using DataType = int;

// 
class GameArray
{
private:
    int Size_;
    DataType* ArrData_;

public:
    int GetSize()
    {
        return Size_;
    }

    DataType& operator[](int _Index)
    {
        if (Size_ <= _Index)
        {
            assert(false);
        }

        return ArrData_[_Index];
    }

    inline void operator=(const GameArray& _Other)
    {

        //ReSize(_Other.Size_);

        // �̰� ���ο� ī�� 
        // Ȥ�� ���� ������ �Ѵ�.
        //this->ArrData_ = _Other.ArrData_;
        //this->Size_ = _Other.Size_;

        // �̰� �� ī��
        // Ȥ�� ���� ������ �Ѵ�.

        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = _Other.ArrData_[i];
        }
        Size_ = _Other.Size_;

        return;
    }

    inline void AllValueSetting(const DataType& Data)
    {
        for (size_t i = 0; i < this->Size_; i++)
        {
            this->ArrData_[i] = Data;
        }
    }


    inline void Release()
    {
        if (nullptr != ArrData_)
        {
            delete[] ArrData_;
            ArrData_ = nullptr;
        }
    }

    void Release(DataType* _Other)
    {
        if (nullptr != _Other)
        {
            delete[] _Other;
            _Other = nullptr;
        }
    }

    void ReSize(unsigned int _Size)
    {
        DataType* NewData = new DataType[Size_];
        for (size_t i = 0; i < Size_; i++)
        {
            NewData[i] = ArrData_[i];
        }

        Release();

        ArrData_ = new DataType[_Size];
        for (size_t i = 0; i < Size_; i++)
        {
            if (i < _Size)
            {
                ArrData_[i] = NewData[i];
            }
        }

        Release(NewData);
        Size_ = _Size;
    }

public:
    GameArray(unsigned int _Size)
        : ArrData_(nullptr)
        , Size_(0)
    {
        ReSize(_Size);
    }

    ~GameArray()
    {
        Release();
    }
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameArray NewArray = GameArray(20);
    GameArray NewArray2 = GameArray(30);

    int Size = sizeof(GameArray);

    for (size_t i = 0; i < NewArray.GetSize(); i++)
    {
        NewArray[i] = i;
    }

    //NewArray.AllValueSetting(0);

    NewArray2 = NewArray;


    NewArray2.ReSize(10);


    for (size_t i = 0; i < NewArray2.GetSize(); i++)
    {
        std::cout << NewArray2[i] << std::endl;
    }



    //int Arr[10];
    //int Arr2[10];

    //for (size_t i = 0; i < 10; i++)
    //{
    //    Arr[i] = Arr2[i];
    //}

    std::cout << "Hello World!\n";
}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
