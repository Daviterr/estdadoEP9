#include "teamvec.h"
#include <stdlib.h>

// TODO: defina aqui os campos de "struct teamvec" -- pense no que o TAD
// precisa guardar para saber quantos times tem e quanto espaço ainda sobra
 struct teamvec {
     Team **data;
     int size;
     int capacity;
 };

TeamVec *tv_create(void) {

    TeamVec *tv = malloc(sizeof(TeamVec));
    if (tv == NULL)
        return NULL;
    tv->size = 0;
    tv->capacity = 10;
    tv->data = malloc(tv->capacity * sizeof(Team *));
    if (tv->data == NULL) {
        free(tv);
        return NULL;
    }
    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {

    if (tv->size == tv->capacity) {
        tv->capacity *= 2;
        tv->data = realloc(tv->data, tv->capacity * sizeof(Team *));
    }
    tv->data[tv->size] = t;
    tv->size++;}

int tv_size(TeamVec *tv) {

    return tv->size;
}

Team *tv_get(TeamVec *tv, int i) {

    if (i >= 0 && i < tv->size)
    return tv->data[i];
    else
        return NULL;
}

void tv_free(TeamVec *tv) {

    for (int i = 0; i < tv->size; i++)
        team_free(tv->data[i]);
    free(tv->data);
    free(tv);
}
