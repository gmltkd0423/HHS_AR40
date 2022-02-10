// ConsoleScreen.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // ���ÿ� n����Ʈ�� �Ҵ�Ǿ������̴�
    TextScreen NewScreen(10, 10, "��");

    Player NewPlayer(&NewScreen, "��");

    NewScreen.SettingScreen();

    // ������
    // ���ڤ�
    // ������

    while (true)
    {
        NewScreen.SettingScreen();
        NewPlayer.Render();
        NewScreen.PrintScreen();
        NewPlayer.Update();

        if (NewPlayer.flag == true)
        {
            std::cout << "������ �����մϴ�" << std::endl;
            return 0;
        }
    }
}