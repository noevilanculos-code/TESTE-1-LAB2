# TESTE1_CPP_Logica_Estruturada

## Descrição
Resolução do Teste I da disciplina de **Laboratório II (C++)** — Licenciatura em Informática, 2º ano.

Data: 22/04/2025 | Duração: 120 minutos

---

## Exercícios

| Ficheiro | Descrição | Funcionalidades extra |
|---|---|---|
| `pergunta1.cpp` | Temperaturas de 7 dias | Valida range (-60 a 60), mostra mínimo e máximo |
| `pergunta2.cpp` | Stock da loja | Menu de repetição, aviso de produto esgotado |
| `pergunta3.cpp` | Notas de 15 alunos | Valida notas (0-20), nomes não vazios |
| `pergunta4.cpp` | Fatura com desconto 10% | Mostra fatura formatada, desconto acima de 1000 MT |
| `pergunta5.cpp` | Ranking de atletas | Detecta empates, medalhas no top 3 |
| `pergunta6.cpp` | Pesquisa de produtos | Pesquisa parcial e case-insensitive, menu completo |

---

## Melhorias de Robustez Implementadas

- **Validação de input**: nenhum programa fecha por entrada errada
- **Loop de reentrada**: ao digitar letras num campo numérico, o programa pede novamente
- **Ranges validados**: notas (0-20), temperaturas (-60 a 60), tempos (>0)
- **Nomes não vazios**: rejeita strings em branco
- **`cin.clear()` + `cin.ignore()`**: limpa o buffer após cada erro
- **`ENTER para sair`**: janela não fecha sozinha no Windows

---

## Como Compilar

```bash
g++ pergunta1.cpp -o pergunta1 && ./pergunta1
g++ pergunta2.cpp -o pergunta2 && ./pergunta2
g++ pergunta3.cpp -o pergunta3 && ./pergunta3
g++ pergunta4.cpp -o pergunta4 && ./pergunta4
g++ pergunta5.cpp -o pergunta5 && ./pergunta5
g++ pergunta6.cpp -o pergunta6 && ./pergunta6
```

---

## Integrantes do Grupo

- 

> Vamos Djimar! 🚀
