//
//  combinaciones.c
//  Abecedario Teoria
//  Created by Cristian Salomon Olmedo on 15/08/16.
//  Copyright © 2016 Cristian Salomon Olmedo. All rights reserved.
//

#include "combinaciones.h"
#include <time.h>
#include <stdlib.h>
#include <inttypes.h>

void calcularyescribir(int tope){
    
    FILE * archivo = fopen("combinaciones.txt", "a+");

	unsigned long long digits = pow(2, (tope-1)); //2 ^(n-1)  //Es el numero de digitos que se puede escribir
	unsigned long long int num, iterador, nummax, ca=0;
	nummax = pow(2, tope); 
	char* array = (char*) malloc( nummax * sizeof(char));
	int i;
	
	if(array == NULL){
		printf("Error, memoria no asignada!");
		exit(1);
	}
    
    for(num = 0; num < nummax; num++){
    ca=0;
    
    for(iterador = digits; iterador > 0; iterador >>= 1){
        
        if(iterador&num)
            array[ca] = '1';

        else
            array[ca] = '0';
            
        ca++;
   
    }
    
    array[ca] = '\0';
    fputs(array, archivo);
    fprintf(archivo, "%s", " ,");

    }
    
    fclose(archivo);
	free(array);    
}

int  randomm(){
    
    srand(time(NULL));
    
    int n = 1 + ( rand() % 100 ) ;
    
    return n;
    
}
