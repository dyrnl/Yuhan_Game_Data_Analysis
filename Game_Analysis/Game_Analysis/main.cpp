#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int chance = rand() % 100 + 1;

class Professor 
{
private:
    int money;  // ��
    int upgradeLevel;   // ��ȭ �ܰ�
    int value;  // �������� ���Ƿ�
    int cost; // �� �񱳿� ����

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
            cout << "\n������ ��ȭ ����. ���� ���Ƿ� : " << value << ", ���� �� : " << money << "��" << endl;
        }
        else 
        {
            upgradeLevel = 0;
            money -= 100;
            value = 0;
            cout << "\n������ �ı�. ���� �� : " << money << endl;
        }
    }

    void professorBreak()
    {
        chance = 0;
        upgradeLevel = 0;
        money -= 100;
        value = 0;
        cout << "\n������ �ı�. ���� �� : " << money << endl;       
    }

    void sell()
    {
        cout << "\n�������� ���Ƿ��� �Ǹ��Ͽ� " << value << "���� ������ϴ� " << endl;
        money += value;
        cout << "���� �� : " << money << "��" << endl;
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
    cout << "�������� �ְ��� ����������!" << endl;
    cout << "Y(��ȭ), S(�Ǹ�), N(���� ����)" << endl;

    char choice = ' ';

    while (choice && myProfessor.getMoney() >= 0)
    {
        cout << "��ȭ ���� : " << myProfessor.getUpgradeLevel() << endl;
        cout << "��ȭ Ȯ�� : " << (90 - myProfessor.getUpgradeLevel() * 2) << "%" << endl;
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
            
        if (myProfessor.getUpgradeLevel() == 25)
        {
            cout << "���� Ŭ����" << endl;
            break;
        }
    }
    return 0;
}