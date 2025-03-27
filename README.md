# Super Trunfo
## Criando as cartas do super trunfo
### Objetivo
Criar um programa em C que permita oa usuário inserir os dados de duas cartas do Super Trunfo. Para cada carta o usuario deve fornecer:
| Tipo | Informação | Descrição |
| --- | --- | --- | 
| char | Estado | Uma letra de A a H (representando um dos oito estados).
| char[] | Código da carta |  A letra do estado seguida de um número de 01 a 04 (ex: A01, B03).
| char[] | Nome da cidade | O nome da cidade
| float | Àrea (em km²) | A area da cidade em quilometros quadrados
| float | PIB | O Produto Interno Bruto da Cidade 
| int | Número de Pontos Turisticos | A quantidade de pontos turisticos da Cidade 

O programa deve retornar uma saida parecida com essa:

````
Carta 1:
Estado: A
Código: A01
Nome da Cidade: São Paulo
População: 12325000
Área: 1521.11 km²
PIB: 699.28 bilhões de reais
Número de Pontos Turísticos: 50

Carta 2:
Estado: B
Código: B02
Nome da Cidade: Rio de Janeiro
População: 6748000
Área: 1200.25 km²
PIB: 300.50 bilhões de reais
Número de Pontos Turísticos: 30    
````