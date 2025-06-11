#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int ShowMenu( int *op ){
    printf("\n1. Adicionar Pessoa.\n");
    printf("2. Remover Pessoa.\n");
    printf("3. Buscar Pessoa.\n");
    printf("4. Listar Tudo.\n");
    printf("\nEscolha uma opcao:");
    scanf("%d", op);

    return ( *op );
}

void *InitBuffer(){
    void *pBuffer = malloc( ( sizeof( int ) * 3 ) + ( sizeof( char ) * 200 ) );

    int *numPersons = NUM_PERSONS;
    int *size = BUFFER_SIZE;
    int *i = I;

    *numPersons = 0;
    *size = 212;
    *i = 0;

    return pBuffer;
}

void *AddPessoa( void *pBuffer ){
    
    //inicializa ponteiros auxiliares
    int *numPersons = NUM_PERSONS;
    int *size = BUFFER_SIZE;
    char *tempName = TEMP_NAME;
    char *tempEmail = TEMP_EMAIL;
    char *head = HEAD;

    //le o nome e email da pessoa
    printf("\nDigite o nome:");
    fgets(tempName, 100, stdin);
    tempName[ strlen( tempName ) - 1 ] = '\0';

    printf("\nDigite o e-mail:");
    fgets(tempEmail, 100, stdin);
    tempEmail[ strlen( tempEmail ) - 1 ] = '\0';

    //realoca o ponteiro e testa
    pBuffer = realloc( pBuffer, *size +                             //tamanho atual do buffer
    ( strlen( tempName ) + 1 * sizeof( char ) ) +                   //espaço para a string nome
    ( strlen( tempEmail ) + 1 * sizeof( char ) ) +                  //espaço para a string email
    sizeof( int ) );                                                //espaço para a idade

    if( pBuffer == NULL ){
        printf("Falha ao alocar memoria.");
    }

    //atribui os dados ao espaço alocado
    char *newString = ( char * )pBuffer + *size;
    strcpy( newString, tempName );                                  //atribui novo nome

    newString = newString + strlen( tempName ) + 1;
    strcpy( newString, tempEmail );                                 //atribui novo email

    int *newAge = ( int * )( ( char * )newString + strlen( tempEmail ) + 1 );

    //le a idade da pessoa
    printf("\nDigite a idade:");
    scanf("%d", newAge);
    while( getchar() != '\n' );

    //calcula o novo tamanho do buffer e atualiza
    size = BUFFER_SIZE;
    *size = *size + strlen( tempName ) + 1 + strlen( tempEmail ) + 1 + 4;

    return pBuffer;
}