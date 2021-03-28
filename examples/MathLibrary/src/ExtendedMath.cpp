
#include "SimpleMath.h"

int fact(int n)
{
    if (n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    return mul(n, fact(n-1));
}