#include "main.h"
int main(){
    int i = 1000000;

    PDCFG3 = 0x01FFFFFF;
    while (1)
    {
        
        PDDAT  = (1<<22) ;
        while (i--){}
        i = 1000000;
        PDDAT  = (0<<22) ;
        while (i--){}
        i = 1000000;
    }
    return 0;
}