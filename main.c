//
//  main.c
//  Abecedario Teoria
//
//  Created by Cristian Salomon Olmedo on 15/08/16.
//  Copyright © 2016 Cristian Salomon Olmedo. All rights reserved.
//

#include <stdio.h>
#include "combinaciones.h"
#include <string.h>


int main(){
    
    int tope, f=1, w=1, i;
    char opc;
   
    FILE * archivo = fopen("combinaciones.txt", "w");
    fprintf(archivo, "%s", "€ = {€, 0, 1, ");
    fclose(archivo);
    
    
 	while(w){
    printf("¿Qué desea hacer?\n1)Calcular con un número aleatorio\n2)Ingresar número\n\n-->");
    scanf("%c", &opc);
         
    switch (opc) {
       
        case '1':
			system("cls");       
			tope = random();
            printf("\nNúmero generado: %d", tope);

            for(i=1; i <= tope; i++)
                calcularyescribir(i);
            
            fprintf(archivo, "%s", "}");
            printf("\nListo\n\n");
        break;
            
        case '2':
            while(f){
                printf("\n\nIngrese el tope de las combinaciones que desee obtener: ");
                scanf("%d", &tope);
                
                if(tope > 0 && tope <= 1000)
                    f=0;
                else{
                    printf("\nError! Numero no valido. Reintente de nuevo\n\n");
                	system("cls");
					}
            }
        
            for(i = 1; i <= tope; i++){
                calcularyescribir(tope);
            }
            
            fprintf(archivo, "%c", '}');
            printf("\n¡Listo!\n\n");
        break;
            
        default:
            printf("\n\n¡Opcion no valida!, intentalo de nuevo\n\n");
        break;
            
    	}
    
    if(opc == '1' || opc == '2')
    	w=0;
	
	}
	
	printf(archivo, "%s","}");   
    
    return 0;
}


