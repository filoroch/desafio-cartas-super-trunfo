# Super Trunfo - Desafio de Programação C

![Last commit](https://img.shields.io/github/last-commit/filoroch/desafio-cartas-super-trunfo) 
![GitHub commit activity (main - monthly)](https://img.shields.io/github/commit-activity/m/filoroch/desafio-cartas-super-trunfo/main)
![Status](https://img.shields.io/badge/Status-Em%20Andamento-orange)


Este projeto documenta o desenvolvimento de um jogo Super Trunfo em linguagem C, proposto como desafio pelo Curso de Ciência da Computação da Faculdade Estácio.

## 1. Visão Geral do Projeto Super Trunfo

O objetivo central do desafio é construir, em etapas, um programa C que simule o jogo de cartas Super Trunfo. Os jogadores (ou o sistema) cadastram cartas com diversos atributos (representando cidades, países, etc.), e em seguida, podem comparar essas cartas com base em um atributo escolhido, seguindo regras específicas para determinar o vencedor.

## 2. Etapas do Desafio e Desenvolvimento Atual

O projeto foi dividido em níveis, cada um adicionando novas funcionalidades e complexidade.

### 2.1. Nível Inicial: Cadastro e Exibição de Cartas

*   **Requisitos Principais:**
    *   Permitir ao usuário inserir os dados de duas cartas do Super Trunfo.
    *   Para cada carta, coletar informações como: nome da cidade/país, estado (simbólico), código da carta, população, área, PIB, e número de pontos turísticos.
    *   Calcular atributos derivados automaticamente: densidade demográfica e PIB per capita.
    *   Implementar uma forma de calcular um "Super Poder" para cada carta.
    *   Exibir os dados completos das cartas cadastradas de forma organizada.

*   **Desenvolvimento Atual Referente a Este Nível:**
    *   O programa `CartasSuperTrunfo.c` atualmente possui uma estrutura `Card` para armazenar todos os atributos mencionados (Commits relevantes: [`8ed3307`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/8ed3307) - Definição inicial da struct, [`40fb699`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/40fb699) - Finalização da struct).
    *   A função `receive_card()` permite a entrada de dados para uma carta (Verificado em commits como [`e27bb1c`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/e27bb1c) - Ajuste fgets, e desenvolvimento inicial em [`5dfd972`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/5dfd972) ou anteriores).
    *   As funções `people_density()`, `pib_per_capita()`, e `def_super_pow()` calculam os atributos derivados (Implementadas principalmente em [`5dfd972`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/5dfd972) - Adição de novas funções).
    *   A função `print_card()` exibe os detalhes de uma carta (Implementada em [`5dfd972`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/5dfd972)).
    *   No `main()`, há exemplos de cartas pré-definidas e chamadas para as funções, refletindo a evolução e refatorações (Ex: [`9302cc3`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/9302cc3) - Modularidade, [`7b91c14`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/7b91c14) - Correções na exibição modular).
    *   Outras melhorias e correções na estrutura inicial e passagem de parâmetros: [`6fcc108`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/6fcc108), [`5420888`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/5420888), [`519ead3`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/519ead3).

### 2.2. Nível Aventureiro: Interatividade e Lógica de Comparação

*   **Requisitos Principais:**
    *   Criar um menu interativo no terminal (usando `switch`) que permita ao jogador escolher qual atributo será usado para comparar as duas cartas.
    *   Implementar a lógica de comparação (`if-else`) entre as duas cartas com base no atributo selecionado.
    *   Atributos disponíveis para comparação: População, Área, PIB, Número de pontos turísticos, Densidade demográfica, PIB per capita (e opcionalmente, Super Poder).
    *   **Regra de Comparação Geral:** Vence a carta com o maior valor no atributo escolhido.
    *   **Regra Específica para Densidade Demográfica:** Vence a carta com o menor valor.
    *   Exibir na tela, de forma clara, o resultado da comparação: nomes das cartas, atributo usado, valores de cada carta, e qual carta venceu ou se houve empate.

*   **Desenvolvimento Atual Referente a Este Nível:**
    *   A função `imprima_comparação_cartas()` apresenta um menu para o usuário escolher o atributo de comparação via `scanf` e `switch`. A lógica de comparação em `compare_card_atribute()` é chamada por ela (Desenvolvimento e correções principais em [`61a1a1e`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/61a1a1e) - Correção do método de comparação).
    *   A exibição dos resultados da comparação e a interface do menu foram ajustadas em commits como [`19d14d6`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/19d14d6) (Correção na impressão das informações comparadas) e [`88a1901`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/88a1901) (Correção de quebras de linha).
    *   A função `compare_super_power()` foi corrigida em [`460f7cc`](https://github.com/filoroch/desafio-cartas-super-trunfo/commit/460f7cc) (Correção de tipos no printf).
    *   O `main()` chama `imprima_comparação_cartas()` para iniciar o processo de comparação interativa, refletindo as atualizações desta fase.

*(Nota: A associação de funcionalidades a commits específicos é uma interpretação baseada nas mensagens de commit e pode não refletir todo o escopo de cada alteração. Commits de documentação como `c826ba8`, `5e0ca0b`, `affe0b3`, `c9d31a2` atualizaram o README em vários estágios.)*

## 3. Como Compilar e Executar

1.  **Pré-requisito:** É necessário ter um compilador C instalado (GCC é recomendado).
2.  **Clone o repositório (caso ainda não tenha feito):**
    ```bash
    git clone https://github.com/filoroch/desafio-cartas-super-trunfo.git
    cd desafio-cartas-super-trunfo
    ```
3.  **Compile o código-fonte:**
    Abra seu terminal, navegue até o diretório onde o arquivo `CartasSuperTrunfo.c` se encontra e execute:
    ```bash
    gcc -o CartasSuperTrunfo CartasSuperTrunfo.c -lm
    ```
    *   `gcc`: Invoca o compilador C.
    *   `-o CartasSuperTrunfo`: Especifica que o arquivo executável gerado se chamará `CartasSuperTrunfo`.
    *   `CartasSuperTrunfo.c`: É o seu arquivo de código-fonte.
    *   `-lm`: Vincula a biblioteca matemática (necessária para funções como `sqrt`, `pow`, etc., embora não explicitamente usadas nas versões atuais, é uma boa prática se houver cálculos mais complexos).

4.  **Execute o programa:**
    Após a compilação ser bem-sucedida, execute o programa no terminal com:
    ```bash
    ./CartasSuperTrunfo
    ```

## 4. Exemplo de Uso (Menu de Comparação do Nível Aventureiro)

Ao executar o programa, você será apresentado a um menu para escolher o atributo de comparação:

```
Escolha um atributo para comparação: 
1. População
2. Area
3. PIB
4. Densidade Populacional
5.PIB per capta
Opção: _
```

Digite o número correspondente ao atributo desejado e pressione Enter. O programa então mostrará os valores das cartas para esse atributo e o resultado da comparação.

## 5. Desenvolvido por

Filipe Dhunior ([@filoroch](https://github.com/filoroch))
