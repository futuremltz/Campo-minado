# 💣 Campo Minado em C
 
Projeto desenvolvido como **Trabalho do Grau B** da disciplina de **Algoritmos e Programação: Fundamentos** da [UNISINOS](https://www.unisinos.br/).
 
---
 
## 💡 Sobre o projeto
 
Implementação do clássico jogo **Campo Minado** em linguagem C, rodando diretamente no terminal. O tabuleiro é representado por uma matriz 9x9 onde o jogador escolhe posições (linha e coluna) para revelar, tentando evitar as bombas escondidas.
 
---
 
## 🎮 Como jogar
 
- O tabuleiro começa completamente oculto, com todas as posições exibidas como `X`
- A cada turno, o jogador informa uma **linha** e uma **coluna** (de 0 a 8)
- **Revelar um número** → o número aparece indicando quantas bombas existem nas 8 casas ao redor
- **Revelar um espaço vazio (0)** → todas as casas vazias conectadas são reveladas automaticamente (flood fill recursivo)
- **Revelar uma bomba** → o tabuleiro inteiro é revelado e o jogo termina com derrota
- **Revelar todas as casas sem bomba** → vitória!
---
 
## ✨ Funcionalidades implementadas
 
- ✅ Geração aleatória do tabuleiro com posicionamento de bombas via `rand()`
- ✅ Cálculo automático dos números de vizinhança para cada célula
- ✅ Exibição da visão do jogador (casas ocultas como `X`)
- ✅ Exibição da tela original completa (para debug)
- ✅ Validação de coordenadas fora do tabuleiro
- ✅ Detecção de vitória e derrota
- ⭐ **Bônus:** Revelação recursiva automática de espaços em branco (flood fill)
---
 
## 📐 Estrutura do código
 
| Função | Descrição |
|---|---|
| `inicializaTela()` | Distribui as bombas aleatoriamente e calcula os números de vizinhança |
| `imprimeTelaJogador()` | Exibe o tabuleiro com `X` nas posições ainda ocultas |
| `imprimeTelaOriginal()` | Exibe o tabuleiro completo com todos os valores |
| `posicaoEscolhida(linha, coluna)` | Processa a jogada do usuário com flood fill recursivo |
| `main()` | Controla o loop do jogo e a interação com o usuário |
 
---
 
## 🖥️ Exemplo no terminal
 
```
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 X  X  X  X  X  X  X  X  X
 
Digite a linha (0 a 8): 4
Digite a coluna (0 a 8): 4
```
 
---
 
## 🚀 Como compilar e executar
 
### Pré-requisitos
 
- Compilador C (GCC recomendado)
### Compilando
 
```bash
gcc campo_minado.c -o campo_minado
```
 
### Executando
 
```bash
./campo_minado
```
 
> No Windows, use `campo_minado.exe`
 
---
 
## 🧠 Conceitos praticados
 
- Arrays bidimensionais (matrizes)
- Variáveis globais em C
- Funções e procedimentos (`void`)
- Recursão (flood fill)
- Geração de números aleatórios (`rand` / `srand`)
- Estruturas de controle e laços de repetição
- Manipulação de bordas em matrizes
---
 
## 📚 Tecnologias
 
| Tecnologia | Detalhe |
|---|---|
| Linguagem | C (padrão C99) |
| Compilador | GCC |
| Bibliotecas | `stdio.h`, `stdlib.h`, `time.h` |
 
---
 
## 👨‍💻 Autor
 
**João Victor Militz**  
Desenvolvido para a disciplina de Algoritmos e Programação — UNISINOS, 2026.
