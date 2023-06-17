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

char time_sym = 35; // #
char dollar_sym =36; // $
char ch0_sym =	37; // %
char ch1_sym = 38; // &
char ch2_sym = 39; // '
char ch3_sym = 40; // '

int read_products(product_t *product);
#endif