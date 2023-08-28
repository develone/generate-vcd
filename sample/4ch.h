#ifndef PRODUCTS_H
#define PRODUCTS_H

typedef struct {
    int ch0;
    int ch0_p;
    int ch1;
    int ch1_p;
    int ch2;
    int ch2_p;
    int ch3;
    int ch3_p;
} product_t;    

//char $
char time_sym,dollar_sym,ch0_sym,ch1_sym,ch2_sym,ch3_sym;
 
 


int read_products(product_t *product);
#endif