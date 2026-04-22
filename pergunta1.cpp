#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Funcao auxiliar: le um float com validacao de range
float lerFloat(const string& mensagem, float minVal, float maxVal) {
    float valor;
    while (true) {
        cout << mensagem;
        if (cin >> valor) {
            if (valor < minVal || valor > maxVal) {
                cout << "[ERRO] Valor fora do intervalo permitido ("
                     << minVal << " a " << maxVal << "). Tente novamente.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERRO] Entrada invalida! Digite apenas numeros (ex: 25.5).\n";
        }
    }
}

int main() {
    float temperaturas[7];
    string dias[] = {"Segunda-feira", "Terca-feira", "Quarta-feira",
                     "Quinta-feira",  "Sexta-feira", "Sabado",       "Domingo"};

    cout << "============================================\n";
    cout << "    REGISTO DE TEMPERATURAS SEMANAIS\n";
    cout << "============================================\n";
    cout << "Intervalo valido: -60 a 60 graus Celsius\n\n";

    for (int i = 0; i < 7; i++) {
        temperaturas[i] = lerFloat("Temperatura de " + dias[i] + " (C): ", -60.0f, 60.0f);
    }

    float soma = 0, maxTemp = temperaturas[0], minTemp = temperaturas[0];
    int diaMaisQuente = 0, diaMaisFrio = 0;

    for (int i = 0; i < 7; i++) {
        soma += temperaturas[i];
        if (temperaturas[i] > maxTemp) { maxTemp = temperaturas[i]; diaMaisQuente = i; }
        if (temperaturas[i] < minTemp) { minTemp = temperaturas[i]; diaMaisFrio   = i; }
    }

    float media = soma / 7;

    cout << "\n============================================\n";
    cout << "                RESULTADOS\n";
    cout << "============================================\n";
    cout << "Media semanal        : " << media   << " C\n";
    cout << "Temperatura mais alta: " << maxTemp << " C  (" << dias[diaMaisQuente] << ")\n";
    cout << "Temperatura mais baixa: "<< minTemp << " C  (" << dias[diaMaisFrio]   << ")\n";
    cout << "============================================\n";

    cout << "\nPressione ENTER para sair...";
    cin.get();
    return 0;
}
