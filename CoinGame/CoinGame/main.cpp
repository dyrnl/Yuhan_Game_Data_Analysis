#include "main.h"

int main() {
    char start;
    CoinGame game;

    while (true) {
        cout << "코인 게임을 시작하시겠습니까? (y/n): ";
        cin >> start;

        if (start == 'y' || start == 'Y') {
            cout << "현재 가진 돈: " << game.getMoney() << "원" << endl;

            // 배팅할 금액 입력
            int betAmount;
            cout << "배팅할 금액을 입력하세요: ";
            cin >> betAmount;

            // 배팅할 금액이 가진 돈보다 많은지 확인
            if (!game.hasEnoughMoney(betAmount)) {
                cout << "가진 돈이 부족합니다." << endl;
                continue;
            }

            // 게임 실행
            game.playGame(betAmount);
        }

        if (start == 'n' || start == 'N') {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        if (start == 'p' || start == 'P') {
            game.addMoney(1000);
            cout << "1000원을 추가했습니다. 현재 가진 돈: " << game.getMoney() << "원" << endl;
        }
    }

    return 0;
}
