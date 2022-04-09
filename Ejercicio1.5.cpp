#include <stdio.h>

int main ()
{
    unsigned int var1 = 0b00110010;
    unsigned int var2 = 0b11000000;
    int r0 = (int)var1 + (int)var2;

    //banderas
    unsigned short n = 0b0000;
    unsigned short z = n;
    unsigned short c = z;
    unsigned short v = c;

    printf("%d", r0);
    
    if (r0<0)
        n = 1;
    if (r0==0)
        z = 1;
    if (r0 > 0xFFFFFFFF)
        c = 1;
    if (r0 >  2,147,483,647 | tst < -2,147,483,648)
        v = 1;

    return 0;
}
