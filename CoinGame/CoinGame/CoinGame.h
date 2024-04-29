#pragma once
class CoinGame
{
private:
    int money;

public:
    CoinGame();
    ~CoinGame();
    int getMoney(); // 현재 자산
    void addMoney(int amount); // 돈 추가
    void playGame(int betAmount); // 게임 실행
    bool hasEnoughMoney(int amount); // 가진 돈이 배팅하는 금액보다 충분한지 확인
};
