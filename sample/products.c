#include <stdio.h>
#include "products.h"
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
    char productType[15];
    char productID[5];
    char productDescription[100];
    double productPrice;
    int quantityInStock;
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
int lp;
int main() {
	inFile = fopen("products.csv", "r");

    product_t product1;
	for(lp=0;lp<3;lp++) read_products(&product1);
	printf("\n");
}
 
int read_products(product_t *product) {
    
    fscanf(inFile,"%[^,],%[^,],%[^,],%lf,%d", product->productType, product->productID, product->productDescription, &product->productPrice, &product->quantityInStock);
    printf("%s  |  %s  |  %s  | %lf | %d ", product->productType, product->productID, product->productDescription, product->productPrice, product->quantityInStock);
}