# Fluxograma do Super Trunfo (Em Partes)

Este documento apresenta o fluxograma do programa `CartasSuperTrunfo.c` dividido em seções menores para facilitar a visualização e compreensão.

## Parte 1: Inicialização do Programa

```mermaid
graph TD
    A[Início] --> B[Declarar variáveis]
    B --> C[Flags não inicializadas]
    C --> D[Inicializar cards]
    D --> E[Calcular atributos derivados]
    E --> F[Calcular super_power]
    F --> G[Comparação inicial]
    G --> H[Exibir Menu Principal]
    H --> I[Ler opção userI]
    I --> J[Início do Loop while]
```

## Parte 2: Case 1 - Cadastrar Cartas

```mermaid
graph TD
    A[Switch userI] --> B[Case 1: Cadastrar cartas]
    B --> C{Verificar flags}
    C -->|Cartas existem| D[Mostrar aviso]
    C -->|Cartas não existem| E[Cadastrar card1]
    E --> F[card1_exist = 1]
    F --> G[Cadastrar card2]
    G --> H[card1_exist = 2]
    H --> I[break]
    D --> I
```

## Parte 3: Case 2 - Imprimir Cartas

```mermaid
graph TD
    A[Switch userI] --> B[Case 2: Imprimir cartas]
    B --> C{Verificar flags}
    C -->|Cartas incompletas| D[Mostrar aviso]
    C -->|Cartas completas| E[Imprimir card1]
    E --> F[Imprimir card2]
    F --> G[break]
    D --> G
```

## Parte 4: Case 3 - Comparar Super Poder

```mermaid
graph TD
    A[Switch userI] --> B[Case 3: Super poder]
    B --> C{Verificar flags}
    C -->|Cartas incompletas| D[Mostrar aviso]
    C -->|Cartas completas| E[Comparar poderes]
    E --> F[break]
    D --> F
```

## Parte 5: Case 4 - Comparar Atributos

```mermaid
graph TD
    A[Switch userI] --> B[Case 4: Atributos]
    B --> C{Verificar flags}
    C -->|Cartas incompletas| D[Mostrar aviso]
    C -->|Cartas completas| E[Comparar atributos]
    E --> F[break]
    D --> F
```

## Parte 6: Default e Final do Loop

```mermaid
graph TD
    A[Switch userI] --> B[Default]
    B --> C[userI == 0]
    C --> D[break]
    
    E[Final dos cases] --> F[Sem nova leitura]
    F --> G[Voltar ao while]
    G -->|userI não é 0| H[Loop infinito]
    G -->|userI se tornou 0| I[Sai do loop]
    I --> J[Fim do programa]
```

## Problemas Identificados no Código

1. **Inicialização de Variáveis**
   - `card1_exist` e `card2_exist` são declaradas mas não inicializadas com 0, o que pode levar a comportamento indefinido nas primeiras verificações.

2. **Atribuição Incorreta**
   - Após cadastrar `card2`, o código atribui `card1_exist = 2;` em vez de `card2_exist = 1;` (ou 2).

3. **Loop Infinito Potencial**
   - `userI` é lido apenas uma vez, antes do loop `while (userI != 0)`. Como não há leitura de `userI` dentro do loop, o programa pode entrar em um loop infinito.

4. **Comparação vs. Atribuição no Default**
   - O código usa `userI == 0;` (comparação) no default, em vez de `userI = 0;` (atribuição), o que não altera o valor de `userI`.

5. **Comparação de Cartas Antes do Menu**
   - `imprima_comparação_cartas(&card1, &card2);` é chamada antes do menu principal, forçando o usuário a comparar cartas antes mesmo de ver o menu.

6. **Design de Menu Inadequado**
   - Para um menu interativo funcional, o `printf` do menu e o `scanf` para atualizar `userI` deveriam estar dentro do loop `while`.
