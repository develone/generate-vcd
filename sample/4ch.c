#include <stdio.h>
#include "4ch.h"
/*
Book,B123,The Hunt for Red October,12.99,28
Book,B124,The Hunt for Red October1,15.99,100
Book,B125,The Hunt for Red October2,17.99,30

no comma at the end of the line
*/

/*
this should be in a file products.h

#ifndef PRODUCTS_H
#define PRODUCTS_H

typedef struct {
    char ch0[5];
    char ch1[5];
    char ch2[5];
    char ch3[5];
} product_t;    

int read_products(product_t *product);
*/

/*
typedef struct {
    char productType[15];
    char productID[5];
    char productDescription[100];
    double productPrice;
    int quantityInStock;
} product_t;    

int read_products(product_t *product);
*/

FILE *inFile;
FILE *debugFile;
int lp;
char debug[10];

int main() {
	time_sym = 35; // #
	dollar_sym = 36; // $
	/*	
	ch0_sym =	37; // %
	ch1_sym = 38; // &
	*/
	ch1_sym =	37; // %
	ch0_sym = 38; // &
	ch2_sym = 39; // '
	ch3_sym = 40; // (
	debug[0]='\0';
	inFile = fopen("4ch.csv", "r");
	debugFile = fopen("debug.txt", "w");
/*
	printf("%d %c\n",time_sym,time_sym);

	printf("%d %c\n",dollar_sym,dollar_sym);

	printf("%d %c\n",ch0_sym,ch0_sym);
	printf("%d %c\n",ch1_sym,ch1_sym);
	
	printf("%d %c\n",ch2_sym,ch2_sym);
	printf("%d %c\n",ch3_sym,ch0_sym);
*/
    product_t product1;
	
	product1.ch0_p = 0;
	product1.ch1_p = 0;
	product1.ch2_p = 0;
	product1.ch3_p = 0;

	for(lp=0;lp<250000;lp++) read_products(&product1);
	fclose(inFile);
	fclose(debugFile);
	//printf("\n");
}
 
int read_products(product_t *product) {
	
    
    fscanf(inFile,"%d,%d,%d,%d", &product->ch0, &product->ch1, &product->ch2, &product->ch3);
		//sprintf(debug,"%d %d %d %d\n", product->ch0, product->ch1, product->ch2, product->ch3);
		//fwrite(debug,sizeof(debug),1,debugFile);
	if (product->ch0 != product->ch0_p) {
		printf("%c%d\n",time_sym, lp);
		sprintf(debug,"%c %d\n", time_sym, lp);
		//printf("%s %d \n",debug,sizeof(debug));
		fwrite(debug,sizeof(debug),1,debugFile);
		printf("%d%c\n", product->ch0,ch0_sym );
		sprintf(debug,"%d %c\n", product->ch0,ch0_sym);
		fwrite(debug,sizeof(debug),1,debugFile);
		product->ch0_p = product->ch0;
	}

	if (product->ch1 != product->ch1_p) {
		printf("%c%d\n",time_sym, lp);
		sprintf(debug,"%c %d\n", time_sym, lp);
		fwrite(debug,sizeof(debug),1,debugFile);
		//printf("%s %d \n",debug,sizeof(debug));
		fwrite(debug,sizeof(debug),1,debugFile);
		printf("%d%c\n", product->ch1,ch1_sym );
		sprintf(debug,"%d %c\n", product->ch1,ch1_sym);
		fwrite(debug,sizeof(debug),1,debugFile);
		product->ch1_p = product->ch1;
	}
	if (product->ch2 != product->ch2_p) {
		printf("%c %d\n",time_sym, lp);
		sprintf(debug,"%c %d\n", time_sym, lp);
		fwrite(debug,sizeof(debug),1,debugFile);
		//printf("%s %d \n",debug,sizeof(debug));
		fwrite(debug,sizeof(debug),1,debugFile);
		printf("%d\n", product->ch2 );
		sprintf(debug,"%d %c\n", product->ch2,ch2_sym);
		fwrite(debug,sizeof(debug),1,debugFile);
		product->ch2_p = product->ch2;
	} 

	if (product->ch3 != product->ch3_p) {
		printf("%c %d\n",time_sym, lp);
		sprintf(debug,"%c %d\n", time_sym, lp);
		fwrite(debug,sizeof(debug),1,debugFile);
		//printf("%s %d \n",debug,sizeof(debug));
		fwrite(debug,sizeof(debug),1,debugFile);
		printf("%d\n", product->ch3 );
		sprintf(debug,"%d %c\n", product->ch3,ch3_sym);
		fwrite(debug,sizeof(debug),1,debugFile);
		product->ch3_p = product->ch3;
	}
}
