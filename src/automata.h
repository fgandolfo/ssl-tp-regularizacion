#ifndef AUTOMATA_H
#define AUTOMATA_H

/* Flag variable */
static char CENTINELA = '#';

/* Enum starter*/
enum STATE {N_0, N_1, N_2, N_3, N_4}; 

/* Function definitions*/
enum STATE trans_nodo_0(char, char*);
enum STATE trans_nodo_1(char, char*);
enum STATE trans_nodo_2(char, char*);
enum STATE trans_nodo_3(char, char*);
enum STATE trans_nodo_4(char, char*);

#endif