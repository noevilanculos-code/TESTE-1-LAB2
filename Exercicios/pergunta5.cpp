#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

float lerTempo(const string& msg) {
    float valor;
    while (true) {
        cout << msg;
        if (cin >> valor) {
            if (valor <= 0 || valor > 36000) {  // max 10 horas em segundos
                cout << "[ERRO] Tempo invalido! Deve ser positivo e ate 36000 segundos. Tente novamente.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERRO] Entrada invalida! Digite apenas numeros (ex: 45.3).\n";
        }
    }
}

string lerNome(const string& msg) {
    string nome;
    while (true) {
        cout << msg;
        getline(cin, nome);
        if (nome.find_first_not_of(" \t") == string::npos || nome.empty()) {
            cout << "[ERRO] Nome nao pode estar vazio!\n";
        } else {
            return nome;
        }
    }
}

int main() {
    const int N = 8;
    string nomes[N];
    float  tempos[N];

    cout << "==============================================\n";
    cout << "       CLUBE DE ATLETISMO - RANKING\n";
    cout << "==============================================\n";
    cout << "Registe o nome e o tempo de corrida de cada atleta.\n\n";

    for (int i = 0; i < N; i++) {
        cout << "--- Atleta " << (i + 1) << " de " << N << " ---\n";
        nomes[i]  = lerNome("  Nome             : ");
        tempos[i] = lerTempo("  Tempo (segundos) : ");
        cout << "\n";
    }

    // Verifica tempos duplicados (aviso, nao erro)
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (tempos[i] == tempos[j]) {
                cout << "[AVISO] " << nomes[i] << " e " << nomes[j]
                     << " tem o mesmo tempo (" << tempos[i] << "s). Empate registado.\n";
            }
        }
    }

    // Bubble Sort (do mais rapido para o mais lento = menor para maior tempo)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (tempos[j] > tempos[j + 1]) {
                float  tempT = tempos[j]; tempos[j] = tempos[j+1]; tempos[j+1] = tempT;
                string tempN = nomes[j];  nomes[j]  = nomes[j+1];  nomes[j+1]  = tempN;
            }
        }
    }

    cout << "\n==============================================\n";
    cout << "   CLASSIFICACAO FINAL (mais rapido ao mais lento)\n";
    cout << "==============================================\n";
    cout << setw(5) << "Pos."
         << "  " << left << setw(22) << "Nome"
         << right << setw(12) << "Tempo (s)" << "\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < N; i++) {
        string medalha = "";
        if      (i == 0) medalha = " [OURO]  ";
        else if (i == 1) medalha = " [PRATA] ";
        else if (i == 2) medalha = " [BRONZE]";

        cout << setw(4) << (i + 1) << "."
             << "  " << left << setw(22) << nomes[i]
             << right << setw(10) << fixed << setprecision(2) << tempos[i] << " s"
             << medalha << "\n";
    }
    cout << "==============================================\n";

    cout << "\nPressione ENTER para sair...";
    cin.get();
    return 0;
}
