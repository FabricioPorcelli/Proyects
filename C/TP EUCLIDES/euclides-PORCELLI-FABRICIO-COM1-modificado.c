// euclides.c
// NOMBRE Y APELLIDO: PORCELLI FABRICIO
// DNI: 43167635
// COMISION: 1

#include <stdio.h>

typedef struct{
    int numerador, denominador;
} fraccion;

int mcd(fraccion *fr); // calcula el minimo comun divisor y lo retorna

fraccion reduce(fraccion *fr); // retorna la fraccion reducida

void muestraFraccion(fraccion frFinal); // imprime por pantalla los valores

void linea(int count);

int main(){

    fraccion f1 = {140, 26};
    fraccion f2 = {380, 44};
    fraccion f3 = {830, 675};

    muestraFraccion(reduce(&f1));

    muestraFraccion(reduce(&f2));

    muestraFraccion(reduce(&f3));

    return 0;
}

// calcula el minimo comun divisor y lo retorna
int mcd(fraccion *fr){
    int a, b, q, r;
    int minimoDivisor;
    linea(2);
    // 1. Sea a el mayor y b el menor entre numerador y denominador.
    a = fr->numerador;
    b = fr->denominador;
    printf(" A\t%c\tB\t%c\tQ\t%c\tR\t\n",179,179,179);
    for (int i = 1; i <= 52; i++){
        if ((i == 9)||(i == 25)||(i == 41)){
            printf("%c",197);
        }
        else{
            printf("%c",196);
        }
    }
    printf("\n");
    do
    {
        // 2. Dividase a entre b y sea q el cociente y r el residuo.
        q = a / b;
        r = a % b;
        printf(" %d\t%c\t%d\t%c\t%d\t%c\t%d\t\n",a,179,b,179,q,179,r);
        // 3. Hagase a = b y b = r
        a = b;
        b = r;
        // 4. Repitase desde el paso 2 hasta que b sea 0.
    } while (b != 0);
    printf(" %d\t%c\t%d\t%c\t \t%c\t \t \n",a,179,b,179,179);
    minimoDivisor = a;
    linea(2);
    return minimoDivisor;
}

// retorna la fraccion reducida
fraccion reduce(fraccion *fr){
    int minimoDivisor = mcd(fr);
    printf("Fraccion ingresada: \nNumerador = %d , Denominador = %d\n",fr->numerador,fr->denominador);
    printf("Maximo denominador de la fraccion ingresada: %d\n",minimoDivisor);
    fraccion fraccionReducida;
    // 5. Dividase numerador y denominador entre a, siendo a el minimoDivisor encontrado.
    fraccionReducida.numerador = fr->numerador / minimoDivisor;
    fraccionReducida.denominador = fr->denominador / minimoDivisor;
    return fraccionReducida;
}

// imprime por pantalla los valores
void muestraFraccion(fraccion frFinal){
    linea(2);
    printf("Fraccion reducida\n");
    printf("Numerador   ->   %d\n",frFinal.numerador);
    //***************** IGNORAR.. es codigo para acomodar la fraccion *****************
    printf("                ");
    if (frFinal.numerador>9999) printf("%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196);
    else if (frFinal.numerador>999) printf("%c%c%c%c%c%c\n",196,196,196,196,196,196);
    else if (frFinal.numerador>99) printf("%c%c%c%c%c\n",196,196,196,196,196);
    else if (frFinal.numerador>9) printf("%c%c%c%c\n",196,196,196,196);
    else if (frFinal.numerador<10) printf("%c%c%c\n",196,196,196);
    //*********************************************************************************
    printf("Denominador ->   %d\n",frFinal.denominador);
    linea(1);
}

// IGNORAR: Funcion para repetir \n prolijamente
void linea(int count){
    int i;
    for (i = 0; i < count; i++){
        printf("\n");
    }
}