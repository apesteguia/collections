#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#ifndef MAG_COLA_H
#define MAG_COLA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodoCola {
    struct nodoCola *sig;
    void *elem;
} NodoCola;

typedef struct cola {
    NodoCola *ini;
    NodoCola *fin;
    size_t size;
    size_t len;
} Cola;

void nuevaCola(Cola *, size_t);
bool esNulaCola(const Cola *);
void insertarEnCola(Cola *, void *);
void eliminarDeCola(Cola *);
void *frente(const Cola *);

#endif // MAG_COLA_H

#endif // COLLECTIONS_H
