#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "list.h"

int letter_value(char c);
int text_equal(int val1[52], int val2[52]);

int main(){
    //Creamos las listas
    LIST lista1 = list_create();
    LIST lista2 = list_create();

    //Cremos contadores para cada letra
    int Valores1[52] = {0}; //a-z 0-25 y A-Z 26-51
    int Valores2[52] = {0};

    //Abrimos el primer txt
    FILE *texto1 = fopen("texto1.txt","r");

    //Leemos el texto del txt
    char c;
    while((c=fgetc(texto1))!=EOF){
        //Si es una letra mayuscula o minuscula la añadimos a la lista
        if((c>='A' && c<='Z') || (c>='a' && c<='z')){
            list_add(lista1,char_create(c));
            //Incrementamos el contador de la letra
            Valores1[letter_value(c)]++;
        }
    }
    //Cerramos el txt
    fclose(texto1);

    //Abrimos el segundo txt
    FILE *texto2 = fopen("texto2.txt","r");

    //Leemos el texto del txt
    while((c=fgetc(texto2))!=EOF){
        //Si es una letra mayuscula o minuscula la añadimos a la lista
        if((c>='A' && c<='Z') || (c>='a' && c<='z')){
            list_add(lista2,char_create(c));
            //Incrementamos el contador de la letra
            Valores2[letter_value(c)]++;
        }
    }
    //Cerramos el txt
    fclose(texto2);

    /*
    //Mostramos letras
    printf("Letras tomadas en cuenta del archivo 1 en el orden encontrado: \n");
    while(list_size(lista1)>0){
        printf("%c",char_val(list_pop(lista1)));
    }

    //Mostramos letras
    printf("Letras tomadas en cuenta del archivo 2 en el orden encontrado: \n");
    while(list_size(lista2)>0){
        printf("%c",char_val(list_pop(lista2)));
    }
    */
    
    //Borramos listas
    list_destroy(lista1);
    list_destroy(lista2);
    

    printf("\n\n");

    //Mostramos respuesta de igualdad
    printf("Los archivos son iguales?\n");
    if(text_equal(Valores1,Valores2)){
        printf("Si\n");
    }else{
        printf("No\n");
    }
}

int letter_value(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z')){
        return c -'A';
    }
    else{
        return -1;
    }
}

int text_equal(int val1[52], int val2[52]){
    int i;
    int bandera = 0;

    for(i=0;i<52;i++){
        if(val1[i]!=val2[i]){
            bandera = 1;
        }
    }
    if(bandera==0){
        return 1;
    }
    else{
        return 0;
    }
}