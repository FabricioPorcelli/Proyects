//----------LIBRERIAS----------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcion_cartas.h"

//-----------------------------

//------------MACRO------------
#define LIMPIAR system("cls")
//-----------------------------

// Prototipo funciones en el mismo archivo.
void matrizCartas0 ();
void verCartas(int,int);
void linea(int);

// Matriz Cartas repartidas
int cartasRepartidas[6][28];

int main (){

    //--------------VARIABLES--------------
    int cantJug, cantRondas, a;
    char confirm;
    int valor, palo, aux;
    int sigPos;
    float apuestas[6][6];
    int apuestaAux, apuestaMax, jug, montoInv, b;
    float pozoAux, pozoBanca;
    float sumaCartas[6][2];
    int contPasados;
    int contValores[10][3];
    int contMax, contMaxVal;
    int cantCartas[6]; 
    int col;
    int cont7Figura[5];
    int sumaCont7Figura;
    int contGanada[6][2];
    int opcion;
    char repetir;
    //-------------------------------------

    do // hacer mientras para repetir el programa
    {
        //-----INICIALIZACION DE VARIABLES-----
        cantJug = 1; cantRondas = 2;
        confirm = 'S';
        repetir = 'S';
        sigPos = 3;
        apuestaAux = 100;
        pozoBanca = 100000;
        contPasados = 0;
        col = 1;
        sumaCont7Figura = 0;
        pozoAux = 0;
        montoInv = 0;
        //-------------------------------------

        //-----INICIALIZACION DE MATRICES------
        //-------------Y ARREGLOS--------------
        for (int i = 0; i < 6; i++){ // Resetea variables
            for (int j = 0; j < 5; j++)
            {
                cont7Figura[j] = 0; // reseteo el cont
            }
            for (int j = 0; j < 6; j++)
            {
                if (j == 0) { // osea en la primer columna
                    apuestas[i][j] = i+1; // escribo el numero de fila, osea de jugador
                }
                else if (j == 1){
                    apuestas[i][j] = 5000;
                }
                else{
                    apuestas[i][j] = 0;
                }
            }
            
            for (int j = 0; j < 2; j++)
            {
                if (j == 0){
                    contGanada[i][j] = i+1; // cantidad de rondas ganadas
                    sumaCartas[i][j] = i+1;
                }
                else{
                    contGanada[i][j] = 0;
                }
            }
            //printf("\n");
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0) { // osea en la primer columna
                    contValores[i][j] = i+1;
                }else{
                    contValores[i][j] = 0;
                }
                
            }
            
        }
        LIMPIAR;
        linea(2);
        //-------------------------------------

        //-------------BIENVENIDA--------------
        {
            printf("-- JUEGO 7 Y MEDIO --\n");
            printf("Enter para comenzar...");
            getch();
            LIMPIAR;
        }
        //-------------------------------------

        //-----------INGRESO VALORES-----------
        do
        {
            do
            {
                if ((cantJug < 1) || (cantJug > 5))
                {
                    printf("Valor invalido. Por favor ingrese un valor entre 1 y 5. \n");
                }

                printf("Ingrese la cantidad de jugadores: ");
                scanf("%d", &cantJug);

            } while ((cantJug < 1) || (cantJug > 5)); // rango a verificar 1 a 5 jugadores

            do
            {
                if ((cantRondas < 2) || (cantRondas > 4))
                {
                    printf("Valor invalido. Por favor ingrese un valor entre 2 y 4. \n");
                }
                printf("Ingrese la cantidad de rondas a jugar: ");
                scanf("%d", &cantRondas);

            } while ((cantRondas < 2) || (cantRondas > 4)); // rango a verificar 2 a 4 rondas

            printf("Jugadores --> %d\n", cantJug);
            printf("Rondas --> %d\n", cantRondas);

            do
            {
                printf("Confirmar valores... (S / N)\n");
                confirm = getch();
                if ((confirm == 'S') || (confirm == 's'))
                {
                    a = 1;
                }
                else if ((confirm == 'N') || (confirm == 'n'))
                {
                    a = 0;
                }
            } while ((confirm != 'N') && (confirm != 'n') && (confirm != 'S') && (confirm != 's'));
            LIMPIAR;
        } while (a != 1);
        //-------------------------------------

        //----------------RONDAS---------------
        for (int k = 1; k <= cantRondas; k++)
        {
            LIMPIAR;
            printf("RONDA n%c%d\n",167,k);
            linea(2);

            //-----------REINICIO CARTAS-----------
            inicioCartas();
            barajar(); // matriz con las cartas mezcladas
            matrizCartas0(); // reinicia matriz de cartas
            reinicio_cartas();    // reiniciar la variable carta del otro programa
            for (int i = 0; i < 6; i++){ // Reinicio valores en la matriz de apuestas
                apuestas[i][2] = 0;
                sumaCartas[i][1] = 0; //reseteo a 0 el acumulador de cartas por jugador y banca
                
                cantCartas[i] = 0; // arreglo para la cantidad de cartas por jugador
            }
            //-------------------------------------
            
            //----------REPARTO 1RA CARTA----------
            for (int i = 0; i < cantJug + 1; i++)
            {
                if (apuestas[i][1] > 0)
                {
                    cantCartas[i]++;
                    aux = mazoCartas(); // aux = 309
                    palo = (aux / 100); // 3 = 309 / 100
                    valor = aux - (palo*100) + 1; // 9 = 309 - (3*100)
                    palo = palo + 1;
                    cartasRepartidas[i][1] = valor;
                    cartasRepartidas[i][2] = palo;
                    if ((valor >= 8 )&&(valor <= 10)){
                        sumaCartas[i][1] = sumaCartas[i][1] + 0.5; // de 8 a 10 sumo 0,5
                    } else {
                        sumaCartas[i][1] = sumaCartas[i][1] + valor; // de 1 a 7 sumo el valor
                    }
                }
            }
            //-------------------------------------
            printf("Se repartieron las primeras cartas.\n");
            printf("Estamos...?\n");
            getch();
            LIMPIAR;
            //--------------APUESTAS---------------
            for (int i = 0; i < cantJug; i++)
            {
                col = 1;
                printf("RONDA n%c%d\n",167,k);
                linea(2);
                printf("JUGADOR n%c%d",167,i+1);
                verCartas(i,col); 
                do
                {
                    if ((apuestaAux < 100) || (apuestaAux > 1500))
                    {
                        printf("Monto invalido. Por favor ingrese una apuesta entre $100 y $1500. \n");
                    }
                    if (montoInv == 1)
                    {
                        printf("Monto invalido. No tenes ese dinero en el pozo. \n");
                        montoInv = 0;
                    }
                    
                    printf("\nQue monto quiere apostar? $");
                    scanf("%d", &apuestaAux);
                    if ((apuestas[i][1] - apuestaAux) < 0){
                        montoInv = 1;
                    }
                } while (((apuestaAux < 100) || (apuestaAux > 1500)) || (montoInv == 1)); // rango a verificar 2 a 4 rondas
                
                if (apuestas[i][1] > 0)
                {
                    apuestas[i][2] = apuestaAux;
                    if ((apuestas[i][2]) > (apuestas[i][3])){
                        apuestas[i][3] = apuestas[i][2];
                        apuestas[i][4] = k; // ronda en la que se realizo la apuesta maxima
                    }
                    LIMPIAR;
                }
                else
                {
                    printf("mono no tene un sope\n");
                }
                
            }
            LIMPIAR;
            //-------------------------------------

            //----------REPARTO 2DA CARTA----------
            for (int i = 0; i < cantJug; i++)
            {
                if (apuestas[i][1] > 0)
                {
                    col = 1;
                    sigPos = 3;
                    printf("RONDA n%c%d\n",167,k);
                    linea(2);
                    printf("JUGADOR n%c%d \t\t",167,i+1);
                    verCartas(i,col);    // VER CARTAS QUE VA TENIENDO EL JUGADOR
                    do
                    {
                        do
                        {
                            printf("\nQueres carta? (S / N)\t");
                            confirm = getch();
                            //scanf(" %c", &confirm);
                            if ((confirm == 'S') || (confirm == 's')) { a = 0; }
                            else if ((confirm == 'N') || (confirm == 'n')) { a = 1; }
                        } while ((confirm != 'N') && (confirm != 'n') && (confirm != 'S') && (confirm != 's'));
                        if (a == 0){
                            cantCartas[i]++;
                            aux = mazoCartas();             // aux = 309
                            palo = (aux / 100);             // 3 = 309 / 100
                            valor = aux - (palo * 100) + 1; // 9 = 309 - (3*100)
                            palo = palo + 1;
                            cartasRepartidas[i][sigPos] = valor;
                            cartasRepartidas[i][sigPos + 1] = palo;
                            col = col + 2;
                            verCartas(i,col);
                            sigPos = sigPos + 2;
                            if ((valor >= 8 )&&(valor <= 10)){
                                sumaCartas[i][1] = sumaCartas[i][1] + 0.5; // de 8 a 10 sumo 0,5
                            } else {
                                sumaCartas[i][1] = sumaCartas[i][1] + valor; // de 1 a 7 sumo el valor
                            }
                        }
                        if (sumaCartas[i][1] > 7.5){
                            printf("\nLlevas acumulado %.1f\n", sumaCartas[i][1]);
                            printf("Te pasaste de 7,5. PERDISTE. \n");
                            a = 1;
                            contPasados++;
                        }
                        else if (sumaCartas[i][1] == 7.5){
                            printf("\nLlegaste a 7,5. Plantate mostro. \n");
                            a = 1;
                        }
                        else if (a == 1){
                            printf("\nLlegaste a %.1f\n", sumaCartas[i][1]);
                        }
                        else if (a == 0){
                            printf("\nLlevas acumulado %.1f\n", sumaCartas[i][1]);
                        }
                    } while (a != 1);
                    getch();
                    LIMPIAR;
                }
            }
            //-------------------------------------
            
            //------------JUEGA LA BANCA-----------
            {
                col = 1;
                sigPos = 3;
                printf("RONDA n%c%d\n",167,k);
                linea(2);
                printf("BANCA \t\t");
                verCartas(cantJug,col);    // VER CARTAS QUE VA TENIENDO LA BANCA
                do
                {
                    
                    if (sumaCartas[cantJug][1] <= 5.5){
                        a = 0; printf("\nQuiero carta.\t");
                    }
                    else if (sumaCartas[cantJug][1] >= 6){
                        a = 1; printf("\nMe planto rey.\t");
                    }
                    if (a == 0){
                        cantCartas[cantJug]++;
                        aux = mazoCartas();             // aux = 309
                        palo = (aux / 100);             // 3 = 309 / 100
                        valor = aux - (palo * 100) + 1; // 9 = 309 - (3*100)
                        palo = palo + 1;
                        cartasRepartidas[cantJug][sigPos] = valor;
                        cartasRepartidas[cantJug][sigPos + 1] = palo;
                        col = col + 2;
                        verCartas(cantJug,col);
                        sigPos = sigPos + 2;
                        if ((valor >= 8 )&&(valor <= 10)){
                            sumaCartas[cantJug][1] = sumaCartas[cantJug][1] + 0.5; // de 8 a 10 sumo 0,5
                        } else {
                            sumaCartas[cantJug][1] = sumaCartas[cantJug][1] + valor; // de 1 a 7 sumo el valor
                        }
                    }
                    
                    if (sumaCartas[cantJug][1] > 7.5){
                        printf("Me pase de 7,5. PERDI. \n");
                        a = 1;
                    }
                    else if (sumaCartas[cantJug][1] == 7.5){
                        printf("\nLlegue a 7,5. A casa. \n");
                        a = 1; 
                    }
                    else if (a == 1){
                        printf("\nLlegue a %.1f\n", sumaCartas[cantJug][1]);
                    }
                    else if (a == 0){
                        printf("\nLlevo acumulado %.1f\n", sumaCartas[cantJug][1]);
                    }
                } while (a != 1);
                getch();
                LIMPIAR;
            }
            //-------------------------------------
            for (int i = 0; i < 6; i++) // contadores por cartas
            {
                for (int j = 1; j <= 27; j = j+2)
                {
                    switch (cartasRepartidas[i][j])
                    {
                    case 1:
                        contValores[0][1]++;
                        break;
                    case 2:
                        contValores[1][1]++;
                        break;
                    case 3:
                        contValores[2][1]++;
                        break;
                    case 4:
                        contValores[3][1]++;
                        break;
                    case 5:
                        contValores[4][1]++;
                        break;
                    case 6:
                        contValores[5][1]++;
                        break;
                    case 7:
                        contValores[6][1]++;
                        break;
                    case 8:
                        contValores[7][1]++;
                        break;
                    case 9:
                        contValores[8][1]++;
                        break;
                    case 10:
                        contValores[9][1]++;
                        break;
                    }
                }
            }

            //-----------COMPARO J CON B-----------
            if (sumaCartas[cantJug][1] > 7.5) // SI LA BANCA SE PASO
            {
                /* GANAN TODOS LOS JUGADORES QUE NO SE HAYAN PASADO */
                for (int i = 0; i < cantJug; i++)
                {
                    if (sumaCartas[i][1] > 7.5) // LOS JUGADORES QUE SE PASARON
                    {
                        //nada xd
                    }
                    else{
                        contGanada[i][1] = contGanada[i][1] + 1;
                        if (cantCartas[i] == 2)
                        {
                            if (sumaCartas[i][1] == 7.5)
                            {
                                cont7Figura[i] = 1;
                                if ((cartasRepartidas[i][2] == cartasRepartidas[i][4]) && (cartasRepartidas[i][2] == 1) && ((cartasRepartidas[i][1]==12) || (cartasRepartidas[i][3]==12))){
                                    //  Si ganó con un par de cartas: 7 + figura (palo oro y figura rey), premio 75%
                                    apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.75);   
                                    pozoBanca = pozoBanca - (apuestas[i][2] * 0.75);
                                    apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.75); // acumulador ganancias
                                }
                                else if ((cartasRepartidas[i][2] != cartasRepartidas[i][4])){
                                    // Si ganó con un par de cartas: 7 + figura, el premio es 30%
                                    apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.3); 
                                    pozoBanca = pozoBanca - (apuestas[i][2] * 0.3);
                                    apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.3); // acumulador ganancias
                                }
                                if ((cartasRepartidas[i][2] == cartasRepartidas[i][4])){
                                    // Si ganó con un par de cartas: 7 + figura, del mismo palo, premio 50%
                                    apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.5);
                                    pozoBanca = pozoBanca - (apuestas[i][2] * 0.5);
                                    apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.5); // acumulador ganancias
                                }
                            }
                            else if(sumaCartas[i][1] != 7.5){
                                // Si ganó con tres o más cartas: premio 15%
                                apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.15);
                                pozoBanca = pozoBanca - (apuestas[i][2] * 0.15);
                                apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.15); // acumulador ganancias
                            }
                        }
                        else if((cantCartas[i] >= 3) || (cantCartas[i] == 1)){
                            // Si ganó con tres o más cartas: premio 15%
                            apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.15);
                            pozoBanca = pozoBanca - (apuestas[i][2] * 0.15);
                            apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.15); // acumulador ganancias
                        }
                    }
                }
            }
            else if (sumaCartas[cantJug][1] <= 7.5) // SI LA BANCA NO SE PASO
            {   
                // COMPARO CADA JUGADOR
                for (int i = 0; i < cantJug; i++) 
                {
                    if (sumaCartas[i][1] > 7.5) // si jugador se pasa
                    {
                        apuestas[i][1] = apuestas[i][1] - apuestas[i][2]; // resto la apuesta del jugador 
                        pozoBanca = pozoBanca + apuestas[i][2]; // la banca se queda con la apuesta del jugador
                    }
                    else{
                        if (sumaCartas[cantJug][1] > sumaCartas[i][1]) // banca suma mas
                        {
                            apuestas[i][1] = apuestas[i][1] - apuestas[i][2]; // resto la apuesta del jugador 
                            pozoBanca = pozoBanca + apuestas[i][2]; // la banca se queda con la apuesta del jugador
                        }
                        else if (sumaCartas[cantJug][1] < sumaCartas[i][1]) // jug suma mas
                        {
                            contGanada[i][1] = contGanada[i][1] + 1;
                            if (cantCartas[i] == 2)
                            {
                                if (sumaCartas[i][1] == 7.5)
                                {
                                    cont7Figura[i] = 1;
                                    if ((cartasRepartidas[i][2] == cartasRepartidas[i][4]) && (cartasRepartidas[i][2] == 1) && ((cartasRepartidas[i][1]==12) || (cartasRepartidas[i][3]==12))){
                                        //  Si ganó con un par de cartas: 7 + figura (palo oro y figura rey), premio 75%
                                        apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.75); 
                                        pozoBanca = pozoBanca - (apuestas[i][2] * 0.75);  
                                        apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.75); // acumulador ganancias
                                    }
                                    else if ((cartasRepartidas[i][2] != cartasRepartidas[i][4])){
                                        // Si ganó con un par de cartas: 7 + figura, el premio es 30%
                                        apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.3);   
                                        pozoBanca = pozoBanca - (apuestas[i][2] * 0.3);  
                                        apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.3); // acumulador ganancias    
                                    }
                                    if ((cartasRepartidas[i][2] == cartasRepartidas[i][4])){
                                        // Si ganó con un par de cartas: 7 + figura, del mismo palo, premio 50%
                                        apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.5);
                                        pozoBanca = pozoBanca - (apuestas[i][2] * 0.5);
                                        apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.5); // acumulador ganancias
                                    }
                                }
                                else if(sumaCartas[i][1] != 7.5){
                                    // Si ganó con tres o más cartas: premio 15%
                                    apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.15);
                                    pozoBanca = pozoBanca - (apuestas[i][2] * 0.15);
                                    apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.15); // acumulador ganancias
                                }
                            }
                            else if((cantCartas[i] >= 3) || (cantCartas[i] == 1)){
                                // Si ganó con tres o más cartas: premio 15%
                                apuestas[i][1] = apuestas[i][1] + (apuestas[i][2] * 0.15);
                                pozoBanca = pozoBanca - (apuestas[i][2] * 0.15);
                                apuestas[i][5] = apuestas[i][5] + (apuestas[i][2] * 0.15); // acumulador ganancias
                            }
                        }
                        else if (sumaCartas[cantJug][1] == sumaCartas[i][1]) // empatan
                        {
                            if (cantCartas[i] == 2){
                                if (sumaCartas[i][1] == 7.5){
                                    cont7Figura[i] = 1; // por mas que hayan empatado, anoto que saco un par 7.5
                                }
                            }
                            /* SE MANTIENEN LOS POZOS no se toca nada xd*/
                        }
                    }
                }
            }
            
            linea(2);
            printf("ESTADISTICAS:\n\n");
            printf("     POZO    GANADAS\n");
            for (int i = 0; i < cantJug; i++)
            {
                for (int j = 0; j < 1; j++)
                {
                    printf("J%.0f ", apuestas[i][0]);
                    printf(" %.2f \t%d", apuestas[i][1], contGanada[i][1]);
                }
                printf("\n");
            }
            printf(" B %.2f \n",pozoBanca);
            linea(2);
            getch();
            
            //-------------------------------------
        }
        //-------------------------------------

        /* Para imprimir matrices, quitar comentario
        LIMPIAR;
        printf("MATRIZ cartasRepartidas\n");
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                printf("%d ", cartasRepartidas[i][j]);
            }
            printf("\n");
        }
        getch();

        printf("MATRIZ apuestas\n");
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("%.1f ", apuestas[i][j]);
            }
            printf("\n");
        }
        getch();

        printf("MATRIZ sumaCartas\n");
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%.1f ", sumaCartas[i][j]);
            }
            printf("\n");
        }
        getch();

        printf("MATRIZ contValores\n");
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", contValores[i][j]);
            }
            printf("\n");
        }
        getch();

        printf("MATRIZ contGanadas\n");
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                printf("%d ", contGanada[i][j]);
            }
            printf("\n");
        }
        getch();
        */
        
        //----------------MENU-----------------
        //--------CONSIGNAS ADICIONALES--------
        do
        {
            LIMPIAR;
            printf("MENU DE CONSIGNAS ADICIONALES\n");
            printf("1- Determinar cual es el participante (jugador o Banca) que mas gano\n");
            printf("2- Comentar cual fue la apuesta maxima, que jugador y en que ronda\n");
            printf("3- Indicar si para los jugadores en conjunto fueron mas las ganancias que las perdidas\n");
            printf("4- Indicar cuantos jugadores sacaron un par '7 + figura'\n");
            printf("5- Mostrar un top 5 de las cartas numericas que mas salieron sin importar el palo\n");
            printf("6- Determinar cuantos participantes perdieron por pasarse durante toda la partida\n");
            printf("0- SALIR\n\n");
            printf("Opcion: ");
            scanf("%d",&opcion); // 1 al 6 o 0
            linea(2);
            switch (opcion)
            {
            case 1:
                printf("CONSIGNA adicional n%c1\n",167);
                contMax = 0;
                contMaxVal = 0;
                for (int j = 0; j < 5; j++){
                    if (contMax < contGanada[j][1]){
                        contMax = contGanada[j][1]; // cuantas veces se repitio
                        contMaxVal = contGanada[j][0]; // que numero
                    }
                }
                printf("El jugador n%c%d fue el que mas rondas gano.\n", 167, contMaxVal);
                getch();
                break;
            case 2:
                apuestaMax = apuestas[0][3];
                jug = apuestas[0][0];
                for (int i = 0; i < cantJug; i++){
                    if (apuestaMax < apuestas[i][3]){
                        apuestaMax = apuestas[i][3];
                        jug = apuestas[i][0];
                    }
                }
                printf("CONSIGNA adicional n%c2\n",167);
                printf("La apuesta maxima fue de $%d por el jugador n%c%d en la ronda %.0f.\n", apuestaMax, 167, jug, apuestas[jug-1][4]);
                getch();
                break;
            case 3:
                printf("CONSIGNA adicional n%c3\n",167);
                pozoAux = pozoBanca - 100000;
                if (pozoAux > 0){
                    /* MAS PERDIDAS QUE GANANCIAS */
                    printf("Fueron mas las perdidas de los jugadores.\n");
                }
                else if (pozoAux < 0){
                    /* MAS GANANCIAS QUE PERDIDAS */
                    printf("Fueron mas las ganancias de los jugadores.\n");
                }
                else if (pozoAux == 0){
                    /* ni ganaron ni perdieron al pedo vinieron */
                    printf("Ni ganaron ni perdieron los jugadores.\n");
                }
                getch();
                break;
            case 4:
                printf("CONSIGNA adicional n%c4\n",167);
                sumaCont7Figura = 0;
                for (int i = 0; i < 5 ; i++){
                    sumaCont7Figura = sumaCont7Figura + cont7Figura[i];
                }
                printf("%d jugador/es sacaron un par '7 + figura' \n", sumaCont7Figura);
                getch();
                break;
            case 5:
                printf("CONSIGNA adicional n%c5\n",167);
                printf("Los 5 valores de cartas que mas salieron son "); 
                contMaxVal = 0;  
                for (int i = 0; i < 10; i++){ // copio la columna 1 en la 2
                    contValores[i][2] = contValores[i][1];
                }
                for (int i = 0; i < 5; i++) // top 5 numeros
                {
                    contMax = 0;
                    for (int j = 0; j < 9; j++){
                        if (contMax < contValores[j][2]){
                            contMax = contValores[j][2]; // cuantas veces se repitio
                            contMaxVal = contValores[j][0]; // que numero
                        }
                    }
                    contValores[contMaxVal-1][2] = 0; // borro el dato, en la siguiente vuelta ya no lo tengo
                    // para evitar esto tengo que guardar en otro lado la columna que voy a ir borrando
                    if ((contMaxVal >= 8) && (contMaxVal <= 10)){
                        printf("%d ",contMaxVal + 2);
                    }
                    else{
                        printf("%d ",contMaxVal);
                    }
                }
                printf("\n");
                getch();
                break;
            case 6:
                printf("CONSIGNA adicional n%c6\n",167);
                printf("La cantidad de veces que algun jugador se paso fue de %d vez/veces.\n", contPasados);
                getch();
                break;
            default:
                break;
            }

        } while (opcion != 0);
        //-------------------------------------

        //----------------FINAL----------------
        // EL PROGRAMA YA TERMINO 
        // está la posibilidad de repetirlo
        LIMPIAR; linea(2);
        do
        {
            printf("Desea iniciar otra partida (S/N) ");
            repetir = getch();
            if ((repetir == 'S') || (repetir == 's')){
                b = 1;
            }
            else if ((repetir == 'N') || (repetir == 'n')){
                b = 0;
            }
        } while ((repetir != 'N') && (repetir != 'n') && (repetir != 'S') && (repetir != 's'));
        //-------------------------------------
    } while (b != 0);

    return 0;
}

//----INICIALIZO LA MATRIZ DE CARTAS---
void matrizCartas0(){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 28; j++){
            cartasRepartidas[i][j] = 0;
            if (j == 0) {
                cartasRepartidas[i][j] = i+1; // escribo el numero de fila + 1, osea de jugador
            }
        }
    }
}
//-------------------------------------

//-----FUNCION PARA IMPRIMIR CARTAS----
void verCartas(int jugador_actual, int col){ 
    // inicializa palo como - [const char *] -> puntero a constante cadenas de caracteres
    const char *palo[4] = {"Oro", "Copa", "Espada", "Basto"};
    // inicializa valor como - [const char *] -> puntero a constante cadenas de caracteres
    const char *valor[10] = {"Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Sota", "Caballo", "Rey"};

    int valor1, palo1;
    valor1 = cartasRepartidas[jugador_actual][col];    // VALOR DE LA CARTA
    palo1 = cartasRepartidas[jugador_actual][col + 1]; // PALO DE LA CARTA

    printf("\t\t%s de %s\n", valor[valor1 - 1], palo[palo1 - 1]); // e imprime donde está esa carta
}
//-------------------------------------

//-------FUNCION PARA REPETIR \n-------
void linea(int count){
    int i;
    for (i = 0; i < count; i++){
        printf("\n");
    }
}
//-------------------------------------