#include <stdio.h>
#include <math.h>

int main( ) {

    int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
    double media = 0, desvioPadrao, somatorio = 0;

    for ( int i = 0 ; i < 10 ; i++ ){
        media += v[i];
    }

    media /= 10;

    for ( int i = 0 ; i < 10 ; i++ ){
        somatorio += ( v[i] - media ) * ( v[i] - media );
    }

    desvioPadrao = sqrt( (1.0 / ( 10 - 1 )) * somatorio );

    printf( "Desvio padrao do vetor: %f", desvioPadrao );
}