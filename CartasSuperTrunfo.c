/****
 * PONTOS DE MELHORIA
 * Garantir que virgulas possam ser recebidas
 * Modificar a merda do codigo para que concatene a letra com o numero
 * corrigir as quebras de linha
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    int number_card;
    char state;
    char cod_card[5];
    char city[50];
    int population, tourist_attractions;
    float area, PIB, densidadePopulacional, PIB_per_capita, super_power; 
} Card;

// MENU DE SELEÇÃO DE COMPARAÇÃO
float compare_card_atribute(Card *c1, Card *c2, const char *atributo){

   float valor1, valor2;
   char city1[50];
   char city2[50];
   strcpy(city1, c1->city);
   strcpy(city2, c2->city);

   // Escolhendo os atributos a serem comparados
   if (strcmp(atributo, "population") == 0){
       valor1 = c1->population;
       valor2 = c2->population;
   } else if (strcmp(atributo, "area") == 0){
       valor1 = c1->area;
       valor2 = c2->area;
   } else if (strcmp(atributo, "PIB") == 0){
       valor1 = c1->PIB;
       valor2 = c2->PIB;
   } else if (strcmp(atributo, "densidadePopulacional") == 0){
       valor1 = c1->densidadePopulacional;
       valor2 = c2->densidadePopulacional;
   } else if (strcmp(atributo, "PIB_per_capita") == 0){
       valor1 = c1->PIB_per_capita;
       valor2 = c2->PIB_per_capita;
   } else {
       return printf("Atributo inválido!\n");
       
   }
    // Comparando os valores retornados dos atributos escolhdos
     printf("\nComparação de cartas (Atributo: %s)\n", atributo); // Adicionado \n
    // Para atributos inteiros, formatar como inteiro
    if (strcmp(atributo, "population") == 0 || strcmp(atributo, "tourist_attractions") == 0) {
         printf("Carta 1 - %s: %d\n", city1, (int)valor1);
         printf("Carta 2 - %s: %d\n", city2, (int)valor2);
    } else {
         printf("Carta 1 - %s: %.2f\n", city1, valor1);
         printf("Carta 2 - %s: %.2f\n", city2, valor2);
    }

    if (valor1 == c1->densidadePopulacional) {
        // Para densidade populacional, menor é melhor
        if (valor1 < valor2){
            printf("Resultado: Carta 1 (%s) venceu!\n", city1);
            return valor1;
        } else {  
            printf("Resultado: Carta 2 (%s) venceu!\n", city2);
            return valor2;
        }
    
    } else {
        // Comparando os valores retornados dos atributos escolhidos (maior é melhor)
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", city1);
            return valor1;
        } else if (valor2 > valor1) { // Se valor2 é maior
            printf("Resultado: Carta 2 (%s) venceu!\n", city2);
            return valor2;
        } else { // Se são iguais
            printf("Resultado: Empate!\n");
            // Em caso de empate, retorna o valor (são iguais mesmo)
            return valor1;
        }
    }
}

// MENU DE SELEÇÃO DE COMPARAÇÃO
float imprima_comparação_cartas(Card *c1, Card *c2){
    int atributo;
    float resultado = 0;
    
    printf("Escolha um atributo para comparação: \n1. População\n2. Area\n3. PIB\n4. Densidade Populacional\n5.PIB per capta\n");
    scanf("%d", &atributo);

    switch (atributo){
        case 1:
            return compare_card_atribute(c1, c2, "population");
        case 2:
            return compare_card_atribute(c1, c2, "area");
        case 3:
            return compare_card_atribute(c1, c2, "PIB");
        case 4:
            return compare_card_atribute(c1, c2, "densidadePopulacional");
        case 5:
            return compare_card_atribute(c1, c2, "PIB_per_capita");
        default:
            printf("Opção inválida! Escolhendo População como padrão.\n");
            return compare_card_atribute(c1, c2, "population");
    }
}

float people_density(int population, float area){
    return (float) population / area;
}

float pib_per_capita(int population, float PIB){
    return (float) (PIB * 1000000000) / population; 
}
float def_super_pow(Card *card){
    // RECEBE e DEFINE o super poder de cada carta
    return card->super_power += (float) card->population + (float) card->area + (float) card->PIB + (float)card->tourist_attractions + (float) card->PIB_per_capita - (float) card->densidadePopulacional;
}
// TODO: REFATORAR ESSA MERDA
// modificar para imprimir só alguns casos especificos
/* recebe ambas as cartas, compara e retorna um print com a carta vencedora*/
void compare_super_power(Card *c1, Card *c2){
    printf("Comparação das cartas\n");
    char message1[20] = "Carta 1 venceu (1)";
    char message0[20] = "Carta 2 venceu (0)";

    if (c1->population > c2->population){ 
        printf("População: %s\n", message1); 
    } else { printf("População: %s\n", message0); }

    if (c1->area > c2->area){ printf("Area: %s\n", message1); 
    } else { 
        printf("Area: %s\n", message0); 
    }
    
    if (c1->PIB > c2->PIB){ 
        printf("PIB: %s\n", message1); 
    } else { 
        printf("PIB: %s\n", message0); }
    
    if (c1->tourist_attractions > c2->tourist_attractions){ 
        printf("Atrações Turisticas: %s\n", message1); } 
    else { 
        printf("Atrações Turisticas: %s\n", message0); }
    
    if (c1->PIB_per_capita > c2->PIB_per_capita){ 
        printf("PIB per capta: %s\n", message1); } 
    else { 
        printf("PIB per capta: %s\n", message0); 
    }
    
    if (c1->densidadePopulacional > c2->densidadePopulacional){ 
        printf("Densidade Populacional: %s\n", message1); 
    } else { 
        printf("Densidade Populacional: %s\n", message0); 
    }
    
    if (c1->super_power> c2->super_power){ 
        printf("Super Power: %s\n", message1); 
    } else { 
        printf("Super Power: %s\n", message0); 
    }
}
/*RECEBE DUAS CARTAS E AS CADASTRA NO CARD STRUCT*/
void receive_card(Card *c, int number){
    c->number_card = number;

    printf("\n----------------------------------\n");
    printf("Digite uma letra de A a H (representando os estados)\n");
    scanf(" %c", &c->state);

    printf("Digite o código do carta-> O codigo é composto da letra do estado (digitada anteriormente)\n");
    scanf("%s", c->cod_card);

    // Limpa o buffer de entrada
    scanf("%*[^\n]");
    scanf("%*c");
    
    printf("Digite o nome da cidade\n");
    fgets(c->city, 50, stdin);
    c->city[strcspn(c->city, "\n")] = 0;

    printf("Digite o numero de pessoas que residem na cidade (população)\n");
    scanf("%d", &c->population);

    printf("Digite a área da cidade\n");
    scanf("%f", &c->area);

    printf("Digite o PIB da cidade\n");
    scanf("%f", &c->PIB);

    printf("Digite o numero de pontos turisticos da cidade\n");
    scanf("%d", &c->tourist_attractions);

    c->densidadePopulacional = people_density(c->population, c->area);
    c->PIB_per_capita = pib_per_capita(c->population, c->PIB);
    
    def_super_pow(c);
}

void print_card(Card *c){
    printf("\n");
    printf("Carta %d:\n", c->number_card);
    
    printf("Estado: %c\n", c->state);
    // testar o concatenar de strings do estado + a entrada do usuario para o codigo da carta
    printf("Código da carta: %s\n", c->cod_card); 
    printf("Nome da cidade: %s\n", c->city);
    printf("População: %d\n", c->population);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f bilhoes de reais\n", c->PIB);
    printf("Número de Pontos Turísticos: %d\n", c->tourist_attractions);
    printf("Densidade populacional: %.2f\n", c->densidadePopulacional);
    printf("PIB per capita?  %.2f\n", c->PIB_per_capita);
}

// CRIAR UM MENU QUE CHAME AS FUNÇÔES INDIVIDUALMENTE E TODAS AO MESMO TEMPO

int main(){
    Card card1, card2;
    int userI;
    /*VARIAVEL DE CONTROLE PARA DETERMINAR SE A CARTA EXISTE OU NÃO*/    
    int card1_exist = 1, card2_exist = 1;

    card1.number_card = 1;
    card1.state = 'S'; // Exemplo para Sudeste
    strcpy(card1.cod_card, "S01"); // Exemplo de código
    strcpy(card1.city, "São Paulo");
    card1.population = 12396372; // População estimada 2021 IBGE
    card1.tourist_attractions = 280; // Número hipotético de atrações relevantes
    card1.area = 1521.11; // km²
    card1.PIB = 747.90; // Bilhões de Reais (PIB municipal 2019 IBGE, valor aproximado para exemplo)
    card1.densidadePopulacional = people_density(card1.population, card1.area);
    card1.PIB_per_capita = pib_per_capita(card1.population, card1.PIB); // Convertendo PIB para unidades
    def_super_pow(&card1);

    // Dados para Carta 2: Manaus, AM
    card2.number_card = 2;
    card2.state = 'N'; // Exemplo para Norte
    strcpy(card2.cod_card, "N02"); // Exemplo de código
    strcpy(card2.city, "Manaus");
    card2.population = 2255903; // População estimada 2021 IBGE
    card2.tourist_attractions = 150; // Número hipotético de atrações relevantes
    card2.area = 11401.092; // km²
    card2.PIB = 91.77; // Bilhões de Reais (PIB municipal 2019 IBGE, valor aproximado para exemplo)
    card2.densidadePopulacional = people_density(card2.population, card2.area);
    card2.PIB_per_capita = pib_per_capita(card2.population, card2.PIB); // Convertendo PIB para unidades
    def_super_pow(&card2);
    
    // MENU PRINCIPAL DO SISTEMA
    do {
        printf("\nSUPER TRUNFO \n1. Cadastrar duas cartas\n2. Imprimir duas cartas\n3. Comparar o super poder das cartas\n4. Comparar um atributo individualmente\n5. Comparar dois atributos\n");
        scanf("%d", &userI);

        switch (userI){
                case 1: // CADASTRA AS DUAS CARTAS E MODIFICA UMA FLAG PARA MOSTRAR QUE ELAS FORAM CRIADAS
                    if (card1_exist != 0 || card2_exist != 0){
                        printf("Ja existem cartas no sistema, imprima e as verifique!");
                    } else {
                        receive_card(&card1, 1);
                        card1_exist = 1;
                        receive_card(&card2, 2);
                        card2_exist = 1;
                    }
                    userI = 0;
                    break;
                case 2:
                    if (card1_exist == 0 || card2_exist == 0){
                        printf("Cadastre as cartas antes de imprimi-las!");
                    } else {
                        print_card(&card1);
                        print_card(&card2);
                    }
                    userI = 0;
                    break;
                case 3: // CHAMA A FUNÇÃO DE COMPARAÇÃO DE SUPER PODER CASO AS CARTAS EXISTAM
                    (card1_exist == 0 || card2_exist == 0) ? printf("Cadastre as cartas antes de imprimi-las!") : compare_super_power(&card1, &card2);
                    userI = 0;
                    break;
                case 4: // CHAMA A FUNÇÃO DE COMPARAÇÃO DE ATRIBUTOS UNICOS
                    (card1_exist == 0 || card2_exist == 0) ? printf("Cadastre as cartas antes de imprimi-las!") : imprima_comparação_cartas(&card1, &card2);
                    userI = 0;
                    break;
                case 5:
                    if (card1_exist == 0 || card2_exist == 0) {
                        printf("Cadastre as cartas antes de compará-las!");
                    } else {
                        float result1 = 0, result2 = 0;
                        int card1_venceu = 0, card2_venceu = 0;
                        
                        printf("\n--- COMPARAÇÃO DE DOIS ATRIBUTOS ---\n");
                        
                        // Primeira comparação
                        printf("\n--- PRIMEIRA COMPARAÇÃO ---\n");
                        float valor1_antes = card1.population;
                        float valor2_antes = card2.population;
                        result1 = imprima_comparação_cartas(&card1, &card2);
                        
                        // Determina o vencedor da primeira comparação
                        if (card1.population != valor1_antes || card1.area != card1.area || 
                            card1.PIB != card1.PIB || card1.densidadePopulacional != card1.densidadePopulacional || 
                            card1.PIB_per_capita != card1.PIB_per_capita) {
                            // Se algum valor mudou, pode ter sido por causa de um erro ou retorno da função
                            // Vamos fazer uma comparação simples
                            if (result1 > 0) {
                                card1_venceu++;
                            } else {
                                card2_venceu++;
                            }
                        }
                        
                        // Segunda comparação
                        printf("\n--- SEGUNDA COMPARAÇÃO ---\n");
                        result2 = imprima_comparação_cartas(&card1, &card2);
                        
                        // Determina o vencedor da segunda comparação
                        if (result2 > 0) {
                            card1_venceu++;
                        } else {
                            card2_venceu++;
                        }
                        
                        // Somar os valores e determinar o vencedor final
                        float soma_valores = result1 + result2;
                        
                        printf("\n--- RESULTADO FINAL ---\n");
                        printf("Soma dos valores dos atributos: %.2f\n", soma_valores);
                        printf("Carta 1 (%s) venceu %d comparações\n", card1.city, card1_venceu);
                        printf("Carta 2 (%s) venceu %d comparações\n", card2.city, card2_venceu);
                        
                        if (card1_venceu > card2_venceu) {
                            printf("Resultado final: Carta 1 (%s) venceu na maioria dos atributos!\n", card1.city);
                        } else if (card2_venceu > card1_venceu) {
                            printf("Resultado final: Carta 2 (%s) venceu na maioria dos atributos!\n", card2.city);
                        } else {
                            printf("Resultado final: Empate no número de atributos vencedores!\n");
                        }
                    }
                    userI = 0;
                    break;
                default:
                    break;
            }
    } while (userI == 0);
    return 0;
}