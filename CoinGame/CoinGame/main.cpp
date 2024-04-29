#include "main.h"

int main() {
    char start;
    CoinGame game;

    while (true) {
        cout << "���� ������ �����Ͻðڽ��ϱ�? (y/n): ";
        cin >> start;

        if (start == 'y' || start == 'Y') {
            cout << "���� ���� ��: " << game.getMoney() << "��" << endl;

            // ������ �ݾ� �Է�
            int betAmount;
            cout << "������ �ݾ��� �Է��ϼ���: ";
            cin >> betAmount;

            // ������ �ݾ��� ���� ������ ������ Ȯ��
            if (!game.hasEnoughMoney(betAmount)) {
                cout << "���� ���� �����մϴ�." << endl;
                continue;
            }

            // ���� ����
            game.playGame(betAmount);
        }

        if (start == 'n' || start == 'N') {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }

        if (start == 'p' || start == 'P') {
            game.addMoney(1000);
            cout << "1000���� �߰��߽��ϴ�. ���� ���� ��: " << game.getMoney() << "��" << endl;
        }
    }

    return 0;
}
