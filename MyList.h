#pragma once
#include "pet.h"

typedef Pet ElemType;

typedef struct {
  // ElemType elems[50];
    int lg;
    //V2
    ElemType* elems;
    int cap;
    //V2 END
} MyList;

/*
Create an empty list
 */
MyList createEmpty();

/*
Destroy list
 */
void destroy(MyList* l);

/*
Get an element from the list
 */
ElemType get(MyList* l, int poz);

ElemType set(MyList* l, int poz, Pet p);

int size(MyList* l);

void add(MyList* l, ElemType e);

MyList copyList(MyList* l);

void testCreateList();

void testIterateList();

void testCopyList();



