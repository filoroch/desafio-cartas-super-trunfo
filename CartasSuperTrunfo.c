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
float compare_super_power(Card *c1, Card *c2){
    printf("Comparação das cartas\n");
    char message1[20] = "Carta 1";
    char message0[20] = "Carta 2 venceu (0)";

    c1->population > c2->population ? printf("População: %s\n", message1) : printf("População: %s\n", message0);
    c1->area > c2->area ? printf("Area: %s\n", message1) : printf("Area: %s\n", message0);
    c1->PIB > c2->PIB ? printf("PIB: %s\n", message1) : printf("PIB: %s\n", message0);
    c1->tourist_attractions > c2->tourist_attractions ? printf("Pontos Turisticos: %s", message1) : printf("Pontos Turisticos: %s\n", message0);
    c1->PIB_per_capita > c2->PIB_per_capita ? printf("PIB PER CAPITA: %s\n", message1) : printf("PIB PER CAPITA: %s", message0);   
    c1->densidadePopulacional > c2->densidadePopulacional ? printf("Densidade Populacional: %s\n", message1) : printf("Densidade Populacional: %s\n", message0);   
    c1->super_power > c2->super_power ? printf("Super poder: Carta %s\n", message1) : printf("Super poder: %s\n", message0);   
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