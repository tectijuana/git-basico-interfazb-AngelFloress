//librerias auxiliares
#include <stdio.h>
#include <stack>

//separa los digitos del valor. Para simular instruccion: ldrh
unsigned int ldr_up_down(bool alta_baja, unsigned int valor)
{
    unsigned int valor_truncado = 0;
    std::stack<unsigned short> digitos_hex;

    //alta: true
    //baja: false
    if (alta_baja) //si ocupamos los digitos altos del valor hex
    {
        //truncamiento
        for(unsigned short i = 0; i<4; i++)
        {
            unsigned short digito = valor%16;
            valor /= 16;
            digitos_hex.push(digito);
        }

        unsigned int posiciones_hex_a_valor_decimal = 0x10000000; //16^7
        
        //valor de las posiciones hex a su equivalente decimal
        while (!digitos_hex.empty())
        {
            unsigned int digito_a_convertir = digitos_hex.top();
            valor_truncado += digito_a_convertir * posiciones_hex_a_valor_decimal;
            posiciones_hex_a_valor_decimal /= 16;
            digitos_hex.pop();
        }

        return valor_truncado;
    }
    else //si ocupamos los bajos...
    {
        //truncamiento
        for(unsigned short i = 0; valor>0; i++)
        {
            unsigned short digito = valor % 16;
            valor /= 16;
            
            if (i > 3)
                digitos_hex.push(digito);
        }

        unsigned int posiciones_hex_a_valor_decimal = 0x1; //16^0

        //valor de las posiciones hex a su equivalente decimal
        while(!digitos_hex.empty())
        {
            unsigned int digito_a_convertir = digitos_hex.top();
            valor_truncado += digito_a_convertir * posiciones_hex_a_valor_decimal;
            posiciones_hex_a_valor_decimal *= 16;
            digitos_hex.pop();
        }

        return valor_truncado;
    }
}

int main() {
    //variables auxiliares y valores dados
    const unsigned int var1 = 0x12345678;
    const unsigned int var2 = 0x87654321;
    const unsigned int var3 = 0x00012345;

    //registros modificables con los valores
    unsigned int r0 = var1;
    unsigned int r1 = var2;
    unsigned int r2 = var3;
    unsigned int r3 = ldr_up_down(false, r0); /* r3 <- baja(*r0)*/
    unsigned int r4 = ldr_up_down(false, r1); /* r4 <- baja(*r1)*/
    unsigned int r5 = r3 * r4;

    //despliegue de la primer multiplicacion
    printf("muls: %x\n", r5);

    //continuacion, para umull y smull
    r3 = r0;
    r4 = r1;
    unsigned long r6_r5 = (unsigned long)r3 * (unsigned long)r4; /* umull r6:r5 <- r3*r4*/

    
    //despliegue
    printf("umull: %lx\n", r6_r5);
    
    //memory adress trickery: Fast Inverse Square Root Inspired
    long sr3l = *(long*)&r3;
    long sr4l = *(long*)&r4;
    
    long sr6_r5 = sr3l * sr4l; /* smull */
    
    //despliegue
    printf("smull: %lx\n", sr6_r5);

    //continuacion para smulwb y smultt
    r3 = ldr_up_down(false, r0); /* r3 <- baja(*r0)*/
    r4 = r2;
    
    //memory adress trickery...
    int sr3i = *(int*)&r3;
    r1 = ldr_up_down(false, r4);
    int sr4i = *(int*)&r1;
    
    int sr5 = sr3i * sr4i; /* r5 <- r3*baja(r4) */ 

    //despliegue
    printf("smuwb: %x\n", sr5);
    
    //memory adress trickery...
    r0 = ldr_up_down(true, r3);
    r1 = ldr_up_down(true, r4);
    sr3i = *(int*)&r0;
    sr4i = *(int*)&r1;
    
    sr5 = sr3i * sr4i; /* smultt */

    //despliegue
    printf("smutt: %x\n", sr5);

    return 0;
}
