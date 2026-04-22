#include <iostream>

using namespace std;

namespace Loja {
    const int TOTAL_PRODUTOS = 10;
    int codigos[TOTAL_PRODUTOS];
    int quantidades[TOTAL_PRODUTOS];
    int contadorProdutos = 0;
    
    void adicionarProduto() {
        if (contadorProdutos >= TOTAL_PRODUTOS) {
            cout << "\nErro: Capacidade maxima de " << TOTAL_PRODUTOS << " produtos atingida!" << endl;
            return;
        }
        
        cout << "\n=== ADICIONAR PRODUTO ===" << endl;
        cout << "Codigo do produto: ";
        cin >> codigos[contadorProdutos];
        
        // Verificar se codigo ja existe
        for (int i = 0; i < contadorProdutos; i++) {
            if (codigos[i] == codigos[contadorProdutos]) {
                cout << "Erro: Codigo ja cadastrado!" << endl;
                return;
            }
        }
        
        cout << "Quantidade em stock: ";
        cin >> quantidades[contadorProdutos];
        
        // Validacao de quantidade negativa
        while (quantidades[contadorProdutos] < 0) {
            cout << "Quantidade invalida! Digite um valor positivo: ";
            cin >> quantidades[contadorProdutos];
        }
        
        contadorProdutos++;
        cout << "Produto adicionado com sucesso!" << endl;
    }
    
    void procurarProduto() {
        if (contadorProdutos == 0) {
            cout << "\nNenhum produto cadastrado ainda!" << endl;
            return;
        }
        
        int codigoBusca;
        bool encontrado = false;
        
        cout << "\n=== PESQUISAR PRODUTO ===" << endl;
        cout << "Digite o codigo do produto: ";
        cin >> codigoBusca;
        
        for (int i = 0; i < contadorProdutos; i++) {
            if (codigos[i] == codigoBusca) {
                encontrado = true;
                cout << "\nProduto encontrado!" << endl;
                cout << "Codigo: " << codigos[i] << endl;
                cout << "Quantidade em stock: " << quantidades[i] << endl;
                
                if (quantidades[i] < 5) {
                    cout << "AVISO: Stock Critico!" << endl;
                }
                break;
            }
        }
        
        if (!encontrado) {
            cout << "\nProduto com codigo " << codigoBusca << " nao encontrado!" << endl;
        }
    }
    
    void executar() {
        int opcao;
        
        do {
            cout << "\n=== SISTEMA DE GESTAO DE STOCK ===" << endl;
            cout << "1 - Adicionar produto" << endl;
            cout << "2 - Procurar produto" << endl;
            cout << "3 - Sair" << endl;
            cout << "Escolha uma opcao: ";
            cin >> opcao;
            
            switch (opcao) {
                case 1:
                    adicionarProduto();
                    break;
                case 2:
                    procurarProduto();
                    break;
                case 3:
                    cout << "\nSaindo do sistema..." << endl;
                    cout << "Obrigado por usar o sistema!" << endl;
                    break;
                default:
                    cout << "\nOpcao invalida! Digite 1, 2 ou 3." << endl;
            }
        } while (opcao != 3);
    }
}

int main() {
    Loja::executar();
    return 0;
}
