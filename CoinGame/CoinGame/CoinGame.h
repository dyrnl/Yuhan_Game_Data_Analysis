#pragma once
class CoinGame
{
private:
    int money;

public:
    CoinGame();
    ~CoinGame();
    int getMoney(); // ���� �ڻ�
    void addMoney(int amount); // �� �߰�
    void playGame(int betAmount); // ���� ����
    bool hasEnoughMoney(int amount); // ���� ���� �����ϴ� �ݾ׺��� ������� Ȯ��
};
