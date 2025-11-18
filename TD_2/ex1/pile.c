#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pile.h"

struct SPile {
    int valeurs[20];
    int index;
};

Pile pile() {         
    Pile p = malloc(sizeof(struct SPile));
    p->index = 0;
    return p;
}

void push(Pile p, int v) {
    p->valeurs[p->index] = v;
    p->index++;
}

void pop(Pile p) {
    if (p->index > 0)
        p->index--;
}

int top(Pile p) {
    return p->valeurs[p->index - 1];
}

void add(Pile p) {
    int v = top(p); pop(p);
    int w = top(p); pop(p);
    push(p, v + w);
}

void mul(Pile p) {
    int v = top(p); pop(p);
    int w = top(p); pop(p);
    push(p, v * w);
}

void dup(Pile p) {
    push(p, top(p));
}

void prn(Pile p) {
    printf("%i\n", top(p));
}
