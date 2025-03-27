#include <stdio.h>
#include <string.h>

typedef struct{
    int number_card;
    char state;
    char cod_card[5];
    char city[50];
    int population, tourist_attractions;
    float area, PIB;
} Card;

void print_card(Card){
    
}

/*int create_card
(char state, char cod_card[5], char city[50], int populacao, float area, float PIB, int pontosTuristicos){

    printf("--------------------------------------------\n");
    printf("Carta %d:\n", card++);
    
    printf("Estado: %c\n", state);
    // testar o concatenar de strings do estado + a entrada do usuario para o codigo da carta
    printf("Código da carta: %s\n", cod_card); 
    printf("Nome da cidade: %s\n", city);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhoes de reais\n", PIB);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);

    return card;
}
*/

void recebe_dados (){
    
    char estado;
    int populacao, pontosTuristicos;
    char cod_Carta[5];
    char cidade[50];
    float area, PIB;

    printf("Digite uma letra de A a H (representando os estados)\n");
    scanf(" %c", &estado);

    printf("Digite o código do carta. O codigo é composto da letra do estado (digitada anteriormente)\n");
    scanf("%s", cod_Carta);

    // Limpa o buffer de entrada
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Digite o nome da cidade\n");
    fgets(cidade, 50, stdin);
    cidade[strcspn(cidade, "\n")] = 0;

    printf("Digite o numero de pessoas que residem na cidade (população)\n");
    scanf("%d", &populacao);

    printf("Digite a área da cidade\n");
    scanf("%f", &area);
    
    printf("Digite o PIB da cidade\n");
    scanf("%f", &PIB);
    
    printf("Digite o numero de pontos turisticos da cidade\n");
    scanf("%d\n", &pontosTuristicos);

    create_card(estado, cod_Carta, cidade, populacao, area, PIB, pontosTuristicos);
}

int main(){
    Card card1, card2;

    // Receber os valores de card 1
    card1.number_card = 1;

    printf("Digite uma letra de A a H (representando os estados)\n");
    scanf(" %c", &card1.state);

    printf("Digite o código do carta. O codigo é composto da letra do estado (digitada anteriormente)\n");
    scanf("%s", card1.cod_card);

    // Limpa o buffer de entrada
    scanf("%*[^\n]");
    scanf("%*c");
    
    printf("Digite o nome da cidade\n");
    fgets(card1.city, 50, stdin);
    card1.city[strcspn(card1.city, "\n")] = 0;

    printf("Digite o numero de pessoas que residem na cidade (população)\n");
    scanf("%d", &card1.population);

    printf("Digite a área da cidade\n");
    scanf("%f", &card1.area);

    printf("Digite o PIB da cidade\n");
    scanf("%f", &card1.PIB);

    printf("Digite o numero de pontos turisticos da cidade\n");
    scanf("%d\n", &card1.tourist_attractions);


    // Receber os valores de card 2
    // Imprimir ambos na tela

    return 0;
}