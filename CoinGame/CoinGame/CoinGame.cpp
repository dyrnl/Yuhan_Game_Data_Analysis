#include "CoinGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

CoinGame::CoinGame() : money(1000)  // 생성자, 초기 자본은 1000원으로 설정
{

}

CoinGame::~CoinGame()
{

}

int CoinGame::getMoney() { // 현재 자산 반환
    return money;
}

void CoinGame::addMoney(int amount) { // 돈 추가
    money += amount;
}

void CoinGame::playGame(int betAmount) {
    srand(time(0)); // 시드 설정

    // 동전 던지기
    bool isHeads = rand() % 2 == 0;

    if (isHeads) {
        cout << "앞면이 나왔습니다! 축하합니다! " << betAmount * 2 << "원을 획득하셨습니다." << endl;
        money += betAmount;
    }
    else {
        cout << "뒷면이 나왔습니다. 아쉽지만 " << betAmount << "원을 잃으셨습니다." << endl;
        money -= betAmount; // 배팅한 금액만큼 잃음
    }

    cout << "현재 잔액: " << money << "원" << endl;
}

bool CoinGame::hasEnoughMoney(int amount) { // 가진 돈이 배팅하는 금액보다 충분한지 확인
    return money >= amount;
}