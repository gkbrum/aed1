#include "functions.h"

int main(){
    
    void *pBuffer = InitBuffer();


    do{
        ShowMenu( I );
        
        switch ( *(I) )
        {
        case 1:
            pBuffer = AddPerson( pBuffer );
            
            *(I) = 1;

            break;
        
        default:
            break;
        }
    }while( *(I) != 5 );
    
    return 0;
}
