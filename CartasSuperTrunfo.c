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

void compare_card_atribute(Card *c1, Card *c2){
    printf("Carta 1 %s: %d\n", c1->city, c1->population);
    printf("Carta 2 %s: %d\n", c2->city, c1->population);
}

// MENU DE SELEÇÃO DE COMPARAÇÃO
void compare_card_params(Card *c1, Card *c2){
    int atributo;
    
    printf("Escolha um atributo para comparação: \n1. População\n2. Area\n3. PIB\n4. Densidade Populacional\n5.PIB per capta");
    scanf("%s", &atributo);

    switch (atributo)
    {
    case 1:
        printf("Carta 1 %s: %d\n", c1->city, c1->population);
        printf("Carta 2 %s: %d\n", c2->city, c1->population);

        if (c1->population > c2->population){  
            printf("Resultado: Carta 1 (%s) venceu!\n", c1->city);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2->city);
        }
        break;
    case 2:
        printf("Carta 1 %s: %d\n", c1->city, c1->area);
        printf("Carta 2 %s: %d\n", c2->city, c1->area);

        if (c1->area > c2->area){  
            printf("Resultado: Carta 1 (%s) venceu!\n", c1->city);
        } else {
            printf("Resultado: Carta 2 (%s) venceu!\n", c2->city);
        }
        break;
    default:
        break;
    }
}

float people_density(int population, float area){
    return (float) population / area;
}

float pib_per_capita(int population, float PIB){
    return (float) PIB / population; 
}
float def_super_pow(Card *card){
    // RECEBE e DEFINE o super poder de cada carta
    return card->super_power += (float) card->population + (float) card->area + (float) card->PIB + (float)card->tourist_attractions + (float) card->PIB_per_capita - (float) card->densidadePopulacional;
}
// TODO: REFATORAR ESSA MERDA
// recebe ambas as cartas, compara e retorna um print com a carta vencedora
// modificar para imprimir só alguns casos especificos
float compare_super_power(Card *c1, Card *c2){
    printf("Comparação das cartas\n");
    char message1[20] = "Carta 1 venceu (1)";
    char message0[20] = "Carta 2 venceu (0)";

    if (c1->population > c2->population){ printf("População: %s\n", message1); } else { printf("População: %s\n", message0); }
    if (c1->area > c2->area){ printf("Area: %s\n", message1); } else { printf("Area: %s\n", message0); }
    if (c1->PIB > c2->PIB){ printf("PIB: %s\n", message1); }   else { printf("PIB: %s\n", message0); }
    if (c1->tourist_attractions > c2->tourist_attractions){ printf("Atrações Turisticas: %s\n", message1); } else { printf("Atrações Turisticas: %s\n", message0); }
    if (c1->PIB_per_capita > c2->PIB_per_capita){ printf("PIB per capta: %s\n", message1); } else { printf("PIB per capta: %s\n", message0); }
    if (c1->densidadePopulacional > c2->densidadePopulacional){ printf("Densidade Populacional: %s\n", message1); } else { printf("Densidade Populacional: %s\n", message0); }
    if (c1->super_power> c2->super_power){ printf("Super Power: %s\n", message1); } else { printf("Super Power: %s\n", message0); }
}

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
    c->PIB_per_capita = pib_per_capita(c->PIB, c->population);
    
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

    // Receber os valores de card 1
    receive_card(&card1, 1);
    // Receber os valores de card 2
    receive_card(&card2, 2);
    // Imprimir ambos na tela    
    //print_card(&card1);
    //print_card(&card2);
    // IMPRIME A COMPARAÇÂO NA TELA
    compare_super_power(&card1, &card2);   
    return 0;
}