#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int chance = rand() % 100 + 1;

class Professor 
{
private:
    int money;  // 돈
    int upgradeLevel;   // 강화 단계
    int value;  // 교수님의 강의력
    int cost; // 돈 비교용 변수

public:
    Professor() : money(300), upgradeLevel(0), value(0), cost(0) {}

    void upgrade()
    {
        srand(time(0));

        if (chance <= (90 - upgradeLevel * 2) && upgradeLevel <= 25 && upgradeLevel >= 0)
        {
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
            else if (upgradeLevel >= 15 && upgradeLevel <= 19) 
            {
                cost = 80;
                money -= 80;
                value += 160;
            }
            else if (upgradeLevel >= 20 && upgradeLevel <= 25) 
            {
                cost = 160;
                money -= 160;
                value += 320;
            }
            upgradeLevel++;
            cout << "\n교수님 강화 성공. 현재 강의력 : " << value << ", 현재 돈 : " << money << "원" << endl;
        }
        else 
        {
            upgradeLevel = 0;
            money -= 100;
            value = 0;
            cout << "\n교수님 파괴. 남은 돈 : " << money << endl;
        }
    }

    void professorBreak()
    {
        chance = 0;
        upgradeLevel = 0;
        money -= 100;
        value = 0;
        cout << "\n교수님 파괴. 남은 돈 : " << money << endl;       
    }

    void sell()
    {
        cout << "\n교수님의 강의력을 판매하여 " << value << "원을 얻었습니다 " << endl;
        money += value;
        cout << "현재 돈 : " << money << "원" << endl;
        value = 0;
        upgradeLevel = 0;
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
};

int main() 
{
    Professor myProfessor;
    cout << "교수님을 최강의 교수님으로!" << endl;
    cout << "Y(강화), S(판매), N(게임 종료)" << endl;

    char choice = ' ';

    while (choice && myProfessor.getMoney() >= 0)
    {
        cout << "강화 레벨 : " << myProfessor.getUpgradeLevel() << endl;
        cout << "강화 확률 : " << (90 - myProfessor.getUpgradeLevel() * 2) << "%" << endl;
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
            
        if (myProfessor.getUpgradeLevel() == 25)
        {
            cout << "게임 클리어" << endl;
            break;
        }
    }
    return 0;
}