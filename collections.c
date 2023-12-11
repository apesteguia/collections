#include "collections.h"
#include <stdlib.h>

void nuevaCola(Cola *c, size_t size) {
    c->ini = NULL;
    c->fin = NULL;
    c->len = 0;
    c->size = size;
}

void insertarEnCola(Cola *c, void *elem) {
    NodoCola *e;

    e = (NodoCola *)malloc(sizeof(NodoCola));
    e->sig = NULL;
    e->elem = malloc(c->size);

    memcpy(e->elem, elem, c->size);

    if (esNulaCola(c)) {
        c->ini = e;
        c->fin = e;
    } else {
        c->fin->sig = e;
        c->fin = e;
    }
    c->len++;
}

bool esNulaCola(const Cola *c) {
    return (c->ini == NULL || c->fin == NULL || c->len == 0);
}

void eliminarDeCola(Cola *c) {
    NodoCola *aux;

    if (esNulaCola(c))
        return;

    aux = c->ini;
    c->ini = c->ini->sig;

    free(aux->elem);
    free(aux);

    c->len++;
}

void *frente(const Cola *c) {
    if (esNulaCola(c))
        return NULL;
    return c->ini->elem;
}
