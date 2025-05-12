#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 30

int BuscaNome( char **lista, int tam );
void TrocaNome( char **lista, int pos );
void CriaLista( char **lista );
void AddNome( char ***lista, int num );
void RemNome( char **lista, int tam, int pos );
int Menu();
void LerString( char *string );
void LimparBuffer();

int main(){
    int op, tamLista = 1, numElementos = 0, pos;
    char **lista = NULL;

    do{
        op = Menu();
        pos = -1;

        switch ( op ){
        case 1:
            printf( "\nDigite o nome a ser adicionado:" );
            AddNome( &lista, numElementos );
            numElementos++;
            tamLista++;
            break;
        
        case 2:
            if( numElementos == 0 ){
                printf( "\nLista vazia." );
            } else {
                printf( "\nDigite a posição do nome a ser excluido (1 ~ %d): ", tamLista );
                scanf( "%d", &pos );
                LimparBuffer();

                
                RemNome( lista, tamLista, pos );
                numElementos--;
                tamLista--;
            }
            break;

        case 3:
            if( numElementos == 0 ){
                printf( "\nLista vazia." );
            } else {
                printf( "\nDigite a posição a ser alterada (1 ~ %d): ", tamLista );
                scanf( "%d", &pos );
                LimparBuffer();

                TrocaNome( lista, pos );
            }
            break;

        case 4:
            if( numElementos == 0 ){
                printf( "\nLista vazia." );
            } else {
                printf( "\nDigite o nome a ser removido: " );
                pos = BuscaNome( lista, tamLista );
                if( pos == -1 ){
                    printf( "\nEsse nome não esta na lista. " );
                } else {
                    RemNome( lista, tamLista, pos );
                    numElementos--;
                    tamLista--;
                }
            }
            break;

        case 5:
            if( numElementos == 0 ){
                printf( "\nLista vazia." );
            } else {
                printf( "\nDigite a posição a ser mostrada na tela (1 ~ %d): ", tamLista );
                scanf( "%d", &pos );
                LimparBuffer();

                printf( "\n%d. %s.", pos + 1, lista[ pos ] );
            }
            break;

        case 6:
            if( numElementos == 0 ){
                printf( "\nLista vazia." );
            } else {
                for( int i = 0; i < tamLista; i++ ){
                    printf( "\n%d. %s", i + 1, lista[ i ] );
                }
            } 
            break;
            
        default:
            break;
        }

    }while( op != 0 );

    return 0;
}

int BuscaNome( char **lista, int tam ){
    char nome[30];
    LerString( nome );

    for (int i = 0; i <= tam; i++){
        if ( i == tam ){
            return -1;
        } else if ( strcmp( lista[i], nome ) ){ 
            return i;
        }
    }
    return -1;
}

void TrocaNome( char **lista, int pos ){
    printf( "\nDigite um novo nome para a posicao %d:", pos );
    LerString( lista[ pos ] );
}

void CriaLista( char **lista ){
    lista = ( char ** )malloc( sizeof( char * ) );
    lista[0] = ( char * )malloc( sizeof( char ) * TAM );
}

void AddNome( char ***lista, int num ){
    if( lista ){
        *lista = ( char *** )realloc( lista, (sizeof( lista )) + sizeof( char * ) );
        *lista[ num + 1] = ( char ** )malloc( sizeof( char ) * TAM );
        LerString( *lista[ num ] );
    } else {
        CriaLista( *lista );
        LerString( *lista[ num ] );
    }
}

void RemNome( char **lista, int tam, int pos ){ 
    for( int i = pos; i != tam; i++ ){
        strcpy( lista[ i ], lista[ i + 1 ] );
    }

    lista = ( char ** )realloc( lista, (sizeof( lista )) - sizeof( char * ) );
}

int Menu(){
    int op;
    
    printf( "\n\n1. Adicionar nome.\n" );
    printf( "2. Apagar nome em linha especifica.\n" );
    printf( "3. Substituir nome.\n" );
    printf( "4. Buscar e apagar nome.\n" );
    printf( "5. Imprimir nome de linha especifica.\n" );
    printf( "6. Listar tudo.\n" );
    printf( "0. Sair.\n\n" );
    
    printf( "Escolha uma opcao: " );
    scanf( "%d", &op );
    LimparBuffer();

    return op;
}

void LerString( char *string ){
    fgets( string, TAM, stdin );
    string[ strlen( string ) ] = '\0';
}

void LimparBuffer(){
    int c;
    while ( ( c = getchar() ) != '\n' && c != EOF );
}