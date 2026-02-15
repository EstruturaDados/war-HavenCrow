// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO NOVATO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Criar uma `struct` chamada `Territorio`.
// - Usar um **vetor estático de 5 elementos** para armazenar os territórios.
// - Cadastrar os dados de cada território: **Nome**, **Cor do Exército**, e **Número de Tropas**.
// - Exibir o estado atual do mapa.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios e tamanho máximo de strings, facilitando a manutenção.
#define MAX_TERRITORIO 5
#define MAX_NOME 30
#define MAX_COR 10

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio{ 
    char nome [MAX_NOME];
    char cor [MAX_COR];
    int tropas;    
};

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa.
// Função utilitária:
void LimparBufferEntrada(); 

// --- Função Principal (main) ---

int main() {
    struct Territorio Paises[MAX_TERRITORIO];
    int i;

    printf("============================================\n");
    printf("        WAR ESTRUTURADO - DESAFIO NOVATO\n");
    printf("============================================\n");
    printf("            CADASTRO DE 5 PAÍSES\n");
    printf("============================================\n\n");    

    // Realizando cadastro de 5 países
    for (i=0; i < MAX_TERRITORIO; i++){
        printf("Digite o nome do território %d: ", i + 1);
        fgets(Paises[i].nome,MAX_NOME,stdin);
        Paises[i].nome[strcspn(Paises[i].nome, "\r\n")]=0; //remover o enter

        printf("Digite a cor do território: ");
        fgets(Paises[i].cor,MAX_COR,stdin);
        Paises[i].cor[strcspn(Paises[i].cor, "\r\n")]=0; //remover o enter

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &Paises[i].tropas);
        printf("\n");
        LimparBufferEntrada();
      
    }

    // Exibindo países cadastrados
    printf("============================================\n");
    printf("        WAR ESTRUTURADO - DESAFIO NOVATO\n");
    printf("============================================\n");
    printf("            PAÍSES CADASTRADOS\n");

    // Loop para paises cadastrados
    for(i=0; i < MAX_TERRITORIO; i++){
        printf("============================================\n");
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", Paises[i].nome);
        printf("Cor: %s\n", Paises[i].cor);
        printf("Tropas: %d\n\n", Paises[i].tropas);
        
    }

    // encerramento.
    printf("Aperte Enter para encerrar.");
    getchar();
    return 0;

 };
    
// --- Implementação das Funções ---

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void LimparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
