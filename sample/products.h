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
#endif