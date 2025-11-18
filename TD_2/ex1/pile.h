#ifndef PILE_H
#define PILE_H

typedef struct SPile *Pile;

Pile pile();

void push(Pile p, int v);
void pop(Pile p);
int top(Pile p);

void add(Pile p);
void mul(Pile p);
void dup(Pile p);
void prn(Pile p);

#endif

