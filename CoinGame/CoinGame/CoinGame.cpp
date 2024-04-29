#include "CoinGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

CoinGame::CoinGame() : money(1000)  // ������, �ʱ� �ں��� 1000������ ����
{

}

CoinGame::~CoinGame()
{

}

int CoinGame::getMoney() { // ���� �ڻ� ��ȯ
    return money;
}

void CoinGame::addMoney(int amount) { // �� �߰�
    money += amount;
}

void CoinGame::playGame(int betAmount) {
    srand(time(0)); // �õ� ����

    // ���� ������
    bool isHeads = rand() % 2 == 0;

    if (isHeads) {
        cout << "�ո��� ���Խ��ϴ�! �����մϴ�! " << betAmount * 2 << "���� ȹ���ϼ̽��ϴ�." << endl;
        money += betAmount;
    }
    else {
        cout << "�޸��� ���Խ��ϴ�. �ƽ����� " << betAmount << "���� �����̽��ϴ�." << endl;
        money -= betAmount; // ������ �ݾ׸�ŭ ����
    }

    cout << "���� �ܾ�: " << money << "��" << endl;
}

bool CoinGame::hasEnoughMoney(int amount) { // ���� ���� �����ϴ� �ݾ׺��� ������� Ȯ��
    return money >= amount;
}