
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int bufferOverflow(char* input)
{
    char buffer[4];
    strcpy(buffer,input);
    return 0;
}

void bufferOverflowSol(char* input){
    const int asize = 10;
    char buffer[asize];

    if(strlen(input) <= asize){
        strcpy(buffer, input);
        printf("\nÉxito: Contenido Copiado\n");
    } else{
        printf("\nError: Buffer Overflow\n");
    }
}

void concatenating(char* so) {
    char name[5];
    strcpy(name, so);
    printf("\n%s\n", name);
}

void concatenatingSol(char* input) {
    char *buff = (char *)malloc(strlen(input)+1);
    if (buff != NULL) {
        strcpy(buff, input);
        printf("\ninput = %s.\n", buff);
    }   else {
        printf("No se puede reservar el espacio de memoria");
    }
}

void memoryManagement() {
    int *array = (int*) malloc(sizeof(int) * 10);
    if (array == NULL) {
        fprintf(stderr, "Unable to allocate enough memory for array!\n");
    } else {
        printf("\n%s\n", "Memoria Reservada");
    }
}

void memoryManagementSol() {
    int *array = (int*) malloc(sizeof(int) * 10);
    if (array == NULL) {
        fprintf(stderr, "Unable to allocate enough memory for array!\n");
    } else {
        printf("\n%s\n", "Memoria Reservada");
    }
    free(array);
}

void main(int argc, char *argv[]){
    int n, opcion;
    do {
        printf( "\n   1. Buffer Overflow", 163 );
        printf( "\n   2. Buffer Overflow Solución. Imprime mensaje de Error", 163 );
        printf( "\n   3. Buffer Overflow Solución. Imprime operación realizada", 163 );
        printf( "\n   4. Validación de Entradas. Concatenación", 163 );
        printf( "\n   5. Validación de Entradas Solución. Concatenación", 163 );
        printf( "\n   6. Gestión de memoria", 163 );
        printf( "\n   7. Gestión de memoria Solución. Se libera memoria Reservada", 163 );
        printf( "\n   0. Salir.",163);

        do {
            printf( "\n   Introduzca opción (0-7): ", 162 );
            scanf( "%d", &opcion );
        } while ( opcion < 0 || opcion > 7 );

        switch (opcion){
            case 1: bufferOverflow("1234");break;
            case 2: bufferOverflowSol("123456789012");break;
            case 3: bufferOverflowSol("1234567890");break;
            case 4: concatenating("Hola!!!!");break;
            case 5: concatenatingSol("Esta es una cadena de prueba");break;
            case 6: memoryManagement();break;
            case 7: memoryManagementSol();break;
        }
    } while ( opcion != 0 );
    exit(0);
}