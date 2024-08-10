// Practica de punteros

#include<stdio.h>

int main(){
    int a = 13;
    int *ptr = NULL;

    printf("\nEl valor de 'a' es: %i\n", a);
    printf("La direccion en memoria de 'a' es: %p\n", &a);

    ptr = &a;

    printf("\nEl valor que contiene ptr es: %p\n", ptr);
    printf("El valor al cual apunta ptr es: %i\n", *ptr);

    a = 7;

    printf("\nEl nuevo valor de 'a': %i\n", a);
    printf("La direccion en memoria de 'a' es: %p\n", &a);
    printf("El valor que contiene ptr es: %p\n", ptr);
    printf("El valor al cual apunta ptr es: %i\n", *ptr);

    (*ptr)++;

    printf("\nEl valor que contiene ptr es: %p\n", ptr);
    printf("El valor al cual apunta ptr es: %i\n", *ptr);
    printf("El valor de 'a' es: %i\n", a);

    ptr++;

    printf("\nEl valor que contiene ptr es: %p\n", ptr);
    printf("El valor al cual apunta ptr es: %i\n", *ptr);
    printf("El valor de 'a' es: %i\n", a);
    printf("La direccion en memoria de 'a' es: %p\n", &a);

    return 0;
}