#include <iostream>
#include <cmath>

using namespace std;

namespace Temperaturas {
    const int DIAS_SEMANA = 7;
    
    bool validarTemperatura(float temp) {
        return temp >= 0;
    }
    
    void executar() {
        float tempMin[DIAS_SEMANA];
        float tempMax[DIAS_SEMANA];
        string dias[] = {"Domingo", "Segunda", "Terca", "Quarta", 
                        "Quinta", "Sexta", "Sabado"};
        
        // Entrada das temperaturas
        cout << "=== REGISTRO DE TEMPERATURAS (Celsius) ===" << endl;
        for (int i = 0; i < DIAS_SEMANA; i++) {
            cout << "\n" << dias[i] << ":" << endl;
            
            // Leitura da temperatura minima
            do {
                cout << "  Temperatura minima: ";
                cin >> tempMin[i];
                
                if (!validarTemperatura(tempMin[i])) {
                    cout << "  Erro: Temperatura nao pode ser negativa! Digite novamente." << endl;
                }
            } while (!validarTemperatura(tempMin[i]));
            
            // Leitura da temperatura maxima
            do {
                cout << "  Temperatura maxima: ";
                cin >> tempMax[i];
                
                if (!validarTemperatura(tempMax[i])) {
                    cout << "  Erro: Temperatura nao pode ser negativa! Digite novamente." << endl;
                } else if (tempMax[i] < tempMin[i]) {
                    cout << "  Erro: Temperatura maxima nao pode ser menor que a minima! Digite novamente." << endl;
                }
            } while (!validarTemperatura(tempMax[i]) || tempMax[i] < tempMin[i]);
        }
        
        // Calculo das medias
        float somaMin = 0;
        float somaMax = 0;
        
        for (int i = 0; i < DIAS_SEMANA; i++) {
            somaMin += tempMin[i];
            somaMax += tempMax[i];
        }
        
        float mediaMin = somaMin / DIAS_SEMANA;
        float mediaMax = somaMax / DIAS_SEMANA;
        
        // Arredondamento das medias
        int mediaMinArredondada = round(mediaMin);
        int mediaMaxArredondada = round(mediaMax);
        
        // Encontrar temperatura mais alta e o dia (entre as maximas)
        float maisAlta = tempMax[0];
        int diaMaisAlta = 0;
        
        for (int i = 1; i < DIAS_SEMANA; i++) {
            if (tempMax[i] > maisAlta) {
                maisAlta = tempMax[i];
                diaMaisAlta = i;
            }
        }
        
        // Encontrar temperatura mais baixa e o dia (entre as minimas)
        float maisBaixa = tempMin[0];
        int diaMaisBaixa = 0;
        
        for (int i = 1; i < DIAS_SEMANA; i++) {
            if (tempMin[i] < maisBaixa) {
                maisBaixa = tempMin[i];
                diaMaisBaixa = i;
            }
        }
        
        // Exibicao dos resultados com medias arredondadas
        cout << "\n=== RESULTADOS SEMANAIS ===" << endl;
        cout << "Media das temperaturas minimas: " << mediaMinArredondada << "°C" << endl;
        cout << "Media das temperaturas maximas: " << mediaMaxArredondada << "°C" << endl;
        cout << "\nTemperatura mais alta da semana: " << maisAlta << "°C" << endl;
        cout << "Dia da temperatura mais alta: " << dias[diaMaisAlta] << endl;
        cout << "\nTemperatura mais baixa da semana: " << maisBaixa << "°C" << endl;
        cout << "Dia da temperatura mais baixa: " << dias[diaMaisBaixa] << endl;
        
        // Tabela resumo
        cout << "\n=== TABELA RESUMO ===" << endl;
        cout << "Dia         | Minima | Maxima" << endl;
        cout << "------------|--------|-------" << endl;
        for (int i = 0; i < DIAS_SEMANA; i++) {
            cout << dias[i];
            for (int j = dias[i].length(); j < 10; j++) {
                cout << " ";
            }
            cout << " |   " << tempMin[i] << "   |   " << tempMax[i] << endl;
        }
    }
}

int main() {
    Temperaturas::executar();
    return 0;
}
