#include <iostream>

using namespace std;

namespace Turma {
    const int TOTAL_ALUNOS = 15;
    
    void executar() {
        string nomes[TOTAL_ALUNOS];
        float medias[TOTAL_ALUNOS];
        
        // Entrada dos dados dos alunos
        cout << "=== GESTAO DE NOTAS DA TURMA ===" << endl;
        for (int i = 0; i < TOTAL_ALUNOS; i++) {
            cout << "\nAluno " << i + 1 << ":" << endl;
            cout << "  Nome: ";
            cin >> nomes[i];
            cout << "  Media final (0-20): ";
            cin >> medias[i];
            
            // Validação da nota
            while (medias[i] < 0 || medias[i] > 20) {
                cout << "  Nota invalida! Digite um valor entre 0 e 20: ";
                cin >> medias[i];
            }
        }
        
        // Listar alunos aprovados (nota >= 10)
        int aprovados = 0;
        cout << "\n=== ALUNOS APROVADOS (Media >= 10) ===" << endl;
        
        for (int i = 0; i < TOTAL_ALUNOS; i++) {
            if (medias[i] >= 10) {
                cout << "- " << nomes[i] << " (Media: " << medias[i] << ")" << endl;
                aprovados++;
            }
        }
        
        // Calcular e exibir percentagem de aprovação
        float percentagem = (aprovados * 100.0) / TOTAL_ALUNOS;
        
        cout << "\n=== RESUMO DA TURMA ===" << endl;
        cout << "Total de alunos: " << TOTAL_ALUNOS << endl;
        cout << "Alunos aprovados: " << aprovados << endl;
        cout << "Percentagem de aprovacao: " << percentagem << "%" << endl;
        
        if (percentagem >= 50) {
            cout << "Situacao: Turma com bom desempenho!" << endl;
        } else {
            cout << "Situacao: Turma precisa melhorar!" << endl;
        }
    }
}

int main() {
    Turma::executar();
    return 0;
}