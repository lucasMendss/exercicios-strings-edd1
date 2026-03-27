#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
	setlocale(LC_ALL, "pt_BR.UTF-8");
	
    string msg;

    cout << "Digite uma mensagem: ";
    cin >> msg;

    int larguraTela = 80;
    int linhaInicial = 5;
    int linhaFinal = 20;

    // calcular posição inicial para centralizar
    int xInicial = (larguraTela - msg.length()) / 2;

    // mostrar mensagem na linha 5
    gotoxy(xInicial, linhaInicial);
    cout << msg;

    Sleep(500);

    // efeito cascata
    for (int i = 0; i < msg.length(); i++) {
        for (int y = linhaInicial; y <= linhaFinal; y++) {

            // apagar posição anterior
            if (y > linhaInicial) {
                gotoxy(xInicial + i, y - 1);
                cout << " ";
            }

            // desenhar letra na nova posição
            gotoxy(xInicial + i, y);
            cout << msg[i];

            Sleep(50); // velocidade da queda
        }
    }

    gotoxy(0, linhaFinal + 2);
    return 0;
}