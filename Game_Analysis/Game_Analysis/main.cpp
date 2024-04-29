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
    int money;  // 돈
    int upgradeLevel;   // 강화 단계
    int value;  // 교수님의 강의력
    int cost;   // 돈 비교용 변수
    int chance; // 강화 확률

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
            // 강화 성공
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
            chance -= 5; // 강화 성공할 때마다 5%씩 감소
        }
        else
        {
            // 강화 실패
            chance = 90; // 강화 실패 시 90%로 초기화
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
        stringBuffer("강화 중...");
        stringBuffer("강화 실패!");
        stringBuffer("교수님 파괴!");
    }

    void sell()
    {
        stringBuffer("교수님 판매!");
        cout << "교수님의 강의력을 판매하여 " << value << "원을 얻었습니다 " << endl;
        money += value;
        value = 0;
        upgradeLevel = 0;

        if (value == 0)
        {
            stringBuffer("교수님 판매 실패!");
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
    cout << "교수님을 최강의 교수님으로!" << endl;
    cout << "Y(강화), S(판매), N(게임 종료)" << endl;

    char choice = ' ';

    while (choice && myProfessor.getMoney() >= 0)
    {
        myProfessor.CursorView(true, 1);
        cout << "강화 레벨 : " << myProfessor.getUpgradeLevel() << endl;
        cout << "강화 확률 : " << (90 - myProfessor.getUpgradeLevel() * 5) << "%" << endl;
        cout << "현재 강의력 : " << myProfessor.getValue() << endl;
        cout << "현재 돈 : " << myProfessor.getMoney() << "원" << endl;
        cout << "교수님을 강화하시겠습니까? (Y/S/N) : ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            if (myProfessor.getMoney() >= myProfessor.getCost())
                myProfessor.upgrade();
            else
                cout << "\n돈이 부족합니다." << endl;
        }
        else if (choice == 'p' || choice == 'P')
        {
            int currentMoney = myProfessor.getMoney();
            currentMoney += 1000;
            myProfessor.setMoney(currentMoney);
            cout << "\n1000원이 추가되었습니다. 현재 돈 : " << myProfessor.getMoney() << "원" << endl;
        }
        else if (choice == 's' || choice == 'S')
            myProfessor.sell();
        else if (choice == 'b' || choice == 'B')
            myProfessor.professorBreak();
        else if (choice == 'n' || choice == 'N')
            break;
            
        if (myProfessor.getUpgradeLevel() == 20)
        {
            cout << "게임 클리어" << endl;
            break;
        }
    }
    return 0;
}