#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;

class Professor
{
private:
    int money;  // ��
    int upgradeLevel;   // ��ȭ �ܰ�
    int value;  // �������� ���Ƿ�
    int cost;   // �� �񱳿� ����
    int chance; // ��ȭ Ȯ��

public:
    Professor() : money(10000), upgradeLevel(0), value(0), cost(0), chance(0) { }

    bool IsUpgrade() const
    {
        return (chance <= 90 - upgradeLevel * 5 && upgradeLevel <= 20 && upgradeLevel >= 0);
    }

    void upgrade()
    {
        if (IsUpgrade())
        {
            // ��ȭ ����
            if (upgradeLevel >= 0 && upgradeLevel <= 4)
            {
                cost = 10;
                money -= 10;
                value += 20;
            }
            else if (upgradeLevel >= 5 && upgradeLevel <= 9)
            {
                cost = 20;
                money -= 20;
                value += 40;
            }
            else if (upgradeLevel >= 10 && upgradeLevel <= 14)
            {
                cost = 40;
                money -= 40;
                value += 80;
            }
            else if (upgradeLevel >= 15 && upgradeLevel <= 20)
            {
                cost = 80;
                money -= 80;
                value += 160;
            }
            upgradeLevel++;
            chance -= 5; // ��ȭ ������ ������ 5%�� ����
        }
        else
        {
            // ��ȭ ����
            chance = 90; // ��ȭ ���� �� 90%�� �ʱ�ȭ
            upgradeLevel = 0;
            money -= 100;
            value = 0;
        }
    }

    void professorBreak()
    {
        chance = 90;
        upgradeLevel = 0;
        money -= 100;
        value = 0;
        stringBuffer("��ȭ ��...");
        stringBuffer("��ȭ ����!");
        stringBuffer("������ �ı�!");
    }

    void sell()
    {
        stringBuffer("������ �Ǹ�!");
        cout << "�������� ���Ƿ��� �Ǹ��Ͽ� " << value << "���� ������ϴ� " << endl;
        money += value;
        value = 0;
        upgradeLevel = 0;

        if (value == 0)
        {
            stringBuffer("������ �Ǹ� ����!");
        }
    }
    void setMoney(int newMoney)
    {
        money = newMoney;
    }
    
    int getMoney() const 
    {
        return money;
    }

    int getUpgradeLevel() const 
    {
        return upgradeLevel;
    }

    int getValue() const 
    {
        return value;
    }

    int getCost() const
    {
        return cost;
    }

    int getChance() const
    {
        return chance;
    }

    void stringBuffer(const char* string)
    {
        system("cls");
        CursorView(false, 1);
        for (int i = 0; i < strlen(string); i++)
        {
            cout << string[i];
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");
    }

    void CursorView(bool visible, DWORD size)
    {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.dwSize = size;
        cursorInfo.bVisible = visible;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    }
};

int main() 
{
    Professor myProfessor;
    cout << "�������� �ְ��� ����������!" << endl;
    cout << "Y(��ȭ), S(�Ǹ�), N(���� ����)" << endl;

    char choice = ' ';

    while (choice && myProfessor.getMoney() >= 0)
    {
        myProfessor.CursorView(true, 1);
        cout << "��ȭ ���� : " << myProfessor.getUpgradeLevel() << endl;
        cout << "��ȭ Ȯ�� : " << (90 - myProfessor.getUpgradeLevel() * 5) << "%" << endl;
        cout << "���� ���Ƿ� : " << myProfessor.getValue() << endl;
        cout << "���� �� : " << myProfessor.getMoney() << "��" << endl;
        cout << "�������� ��ȭ�Ͻðڽ��ϱ�? (Y/S/N) : ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            if (myProfessor.getMoney() >= myProfessor.getCost())
                myProfessor.upgrade();
            else
                cout << "\n���� �����մϴ�." << endl;
        }
        else if (choice == 'p' || choice == 'P')
        {
            int currentMoney = myProfessor.getMoney();
            currentMoney += 1000;
            myProfessor.setMoney(currentMoney);
            cout << "\n1000���� �߰��Ǿ����ϴ�. ���� �� : " << myProfessor.getMoney() << "��" << endl;
        }
        else if (choice == 's' || choice == 'S')
            myProfessor.sell();
        else if (choice == 'b' || choice == 'B')
            myProfessor.professorBreak();
        else if (choice == 'n' || choice == 'N')
            break;
            
        if (myProfessor.getUpgradeLevel() == 20)
        {
            cout << "���� Ŭ����" << endl;
            break;
        }
    }
    return 0;
}