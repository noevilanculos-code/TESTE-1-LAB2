#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

float lerFloat(const string& msg, float minVal, float maxVal) {
    float valor;
    while (true) {
        cout << msg;
        if (cin >> valor) {
            if (valor < minVal || valor > maxVal) {
                cout << "[ERRO] Valor fora do intervalo (" << minVal << " a " << maxVal << "). Tente novamente.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERRO] Entrada invalida! Digite apenas numeros (ex: 150.00).\n";
        }
    }
}

int lerInteiro(const string& msg, int minVal, int maxVal) {
    int valor;
    while (true) {
        cout << msg;
        if (cin >> valor) {
            if (valor < minVal || valor > maxVal) {
                cout << "[ERRO] Valor fora do intervalo (" << minVal << " a " << maxVal << "). Tente novamente.\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERRO] Entrada invalida! Digite apenas numeros inteiros.\n";
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
    const int N = 5;
    string nome_item[N];
    float  preco_unitario[N];
    int    quantidade_comprada[N];
    float  subtotal[N];

    cout << "==============================================\n";
    cout << "         SISTEMA DE FATURACAO\n";
    cout << "==============================================\n\n";

    for (int i = 0; i < N; i++) {
        cout << "--- Item " << (i + 1) << " de " << N << " ---\n";
        nome_item[i]          = lerNome("  Nome do item      : ");
        preco_unitario[i]     = lerFloat("  Preco unitario(MT): ", 0.01f, 999999.0f);
        quantidade_comprada[i]= lerInteiro("  Quantidade        : ", 1, 9999);
        subtotal[i]           = preco_unitario[i] * quantidade_comprada[i];
        cout << "  Subtotal calculado: " << fixed << setprecision(2) << subtotal[i] << " MT\n\n";
    }

    float total = 0;
    for (int i = 0; i < N; i++) total += subtotal[i];

    // Impressao da fatura
    cout << "==============================================\n";
    cout << "                  FATURA\n";
    cout << "==============================================\n";
    cout << left << setw(18) << "Item"
         << right << setw(10) << "Preco"
         << setw(6)  << "Qtd"
         << setw(12) << "Subtotal" << "\n";
    cout << "----------------------------------------------\n";
    for (int i = 0; i < N; i++) {
        cout << left  << setw(18) << nome_item[i]
             << right << setw(10) << fixed << setprecision(2) << preco_unitario[i]
             << setw(6)  << quantidade_comprada[i]
             << setw(12) << subtotal[i] << " MT\n";
    }
    cout << "----------------------------------------------\n";
    cout << right << setw(36) << "Total bruto: " << setw(10) << total << " MT\n";

    if (total > 1000) {
        float desconto   = total * 0.10f;
        float totalFinal = total - desconto;
        cout << right << setw(36) << "Desconto (10%): -" << setw(9) << desconto << " MT\n";
        cout << "==============================================\n";
        cout << right << setw(36) << "TOTAL A PAGAR: " << setw(10) << totalFinal << " MT\n";
        cout << "  *** Desconto de 10% aplicado! ***\n";
    } else {
        cout << "==============================================\n";
        cout << right << setw(36) << "TOTAL A PAGAR: " << setw(10) << total << " MT\n";
    }
    cout << "==============================================\n";

    cout << "\nPressione ENTER para sair...";
    cin.get();
    return 0;
}
