#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
#include <iomanip>
using namespace std;

// Converte string para minusculas (pesquisa insensivel a maiusculas)
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string lerNome(const string& msg) {
    string nome;
    while (true) {
        cout << msg;
        getline(cin, nome);
        if (nome.find_first_not_of(" \t") == string::npos || nome.empty()) {
            cout << "[ERRO] O nome nao pode estar vazio!\n";
        } else {
            return nome;
        }
    }
}

int main() {
    const int N = 20;
    string produtos[N] = {
        "Arroz",    "Feijao",   "Acucar",   "Sal",      "Oleo",
        "Farinha",  "Leite",    "Manteiga", "Ovos",     "Pao",
        "Frango",   "Carne",    "Peixe",    "Tomate",   "Cebola",
        "Alho",     "Batata",   "Cenoura",  "Macarrao", "Sabao"
    };
    float precos[N] = {
        150.0f, 120.0f,  95.0f,  30.0f, 180.0f,
         80.0f,  75.0f, 110.0f,  60.0f,  45.0f,
        320.0f, 450.0f, 280.0f,  50.0f,  40.0f,
         35.0f,  55.0f,  45.0f,  70.0f,  65.0f
    };

    char continuar;

    cout << "==============================================\n";
    cout << "    SUPERMERCADO - CONSULTA DE PRECOS\n";
    cout << "==============================================\n";
    cout << "Total de produtos disponiveis: " << N << "\n\n";

    do {
        // Menu de opcoes
        cout << "Opcoes:\n";
        cout << "  [1] Pesquisar produto por nome\n";
        cout << "  [2] Listar todos os produtos\n";
        cout << "  [0] Sair\n";
        cout << "Escolha: ";

        int opcao;
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERRO] Opcao invalida!\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcao == 0) {
            break;

        } else if (opcao == 1) {
            string busca = lerNome("\nDigite o nome do produto: ");
            string buscaLower = toLower(busca);

            // Procura exacta ou parcial
            bool encontrado = false;
            cout << "\n--- Resultados para \"" << busca << "\" ---\n";

            for (int i = 0; i < N; i++) {
                if (toLower(produtos[i]).find(buscaLower) != string::npos) {
                    cout << "  Produto : " << produtos[i] << "\n";
                    cout << "  Preco   : " << precos[i] << " MT\n";
                    cout << "  --------------------------\n";
                    encontrado = true;
                }
            }

            if (!encontrado) {
                cout << "  [INFO] Produto \"" << busca << "\" nao encontrado.\n";
                cout << "  Dica: Verifique a ortografia ou use parte do nome.\n";
            }
            cout << "\n";

        } else if (opcao == 2) {
            cout << "\n--- Lista Completa de Produtos ---\n";
            cout << "  " << left << setw(15) << "Produto" << right << setw(10) << "Preco (MT)" << "\n";
            cout << "  ---------------------------\n";
            for (int i = 0; i < N; i++) {
                cout << "  " << left << setw(15) << produtos[i]
                     << right << setw(10) << fixed << setprecision(2) << precos[i] << " MT\n";
            }
            cout << "\n";

        } else {
            cout << "[ERRO] Opcao invalida! Escolha 0, 1 ou 2.\n\n";
        }

    } while (true);

    cout << "\nObrigado por usar o sistema. Ate logo!\n";
    cout << "\nPressione ENTER para sair...";
    cin.get();
    return 0;
}
