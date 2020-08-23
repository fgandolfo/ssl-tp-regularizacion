#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "automata.h"

static char lang_a[] = {'0', '1'};
static int size_lang_a = 2;

static char lang_b[] = {'.'};
static int size_lang_b = 1;

static char lang_c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static int size_lang_c = 10;

static char lang_d[] = {'B'};
static int size_lang_d = 1;

bool char_belongs(char, char*, int);
char* str_concat(char*, char);
void word_to_file(char);

enum STATE trans_nodo_0(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (char_belongs(c, lang_d, size_lang_d))
        state = N_4;

    else if (char_belongs(c, lang_a, size_lang_a))
        state = N_1;

    else
        state = N_0;
    
    return state;
}

enum STATE trans_nodo_1(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (char_belongs(c, lang_d, size_lang_d))
        state = N_4;

    else if (char_belongs(c, lang_b, size_lang_b))
        state = N_3;

    else if (char_belongs(c, lang_a, size_lang_a))
        state = N_2;

    else
        state = N_0;
    
    return state;
}

enum STATE trans_nodo_2(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (char_belongs(c, lang_d, size_lang_d))
        state = N_4;

    else if (char_belongs(c, lang_a, size_lang_a))
        state = N_2;

    else
        state = N_0;
    
    return state;
}

enum STATE trans_nodo_3(char c, char* palabra) {
    enum STATE state;
    char* aux;

    if (char_belongs(c, lang_c, size_lang_c))
        state = N_4;

    else
        state = N_0;
    
    return state;
}

enum STATE trans_nodo_4(char c, char* palabra) {
    enum STATE state;
    state = N_0;

    return state;
}

bool char_belongs(char c, char *lang_x, int size_lang_x) {
    
    for (int i=0; i<size_lang_x; i++){
        if (c == lang_x[i]){
            word_to_file(c);
            return true;
        }
    }
    return false;
}

void word_to_file(char c) {
    FILE *fptr;
    fptr = fopen("words_found.txt", "a");

    fprintf(fptr, "%c", c);
    fclose(fptr);
}