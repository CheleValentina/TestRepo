#include "MyList.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

MyList createEmpty() {
  MyList rez;
  rez.lg = 0;

  //V2
  rez.cap = 2;
  rez.elems = malloc(sizeof(ElemType)*rez.cap);
  //V2 END

  return rez;
}

void destroy(MyList* l) {
  //V2
  for (int i = 0; i < l->lg; i++) {
    destroyPet(&l->elems[i]);
  }
  free(l->elems);
  l->elems = NULL;
  //V2 END
  l->lg = 0;
}

ElemType get(MyList* l, int poz) {
  return l->elems[poz];
}

ElemType set(MyList* l, int poz, Pet p) {
  ElemType rez = l->elems[poz];
  l->elems[poz] = p;
  return rez;
}


//V2
void ensureCapacity(MyList* l) {
  if (l->lg < l->cap) {
    return; //we have room
  }

  //allocate more memory
  int newCapacity = l->cap + 2;
  ElemType* nElems = malloc(sizeof(ElemType)*newCapacity);
  for (int i=0; i< l->lg; i++) {
    nElems[i] = l->elems[i];
  }

  //dealocate old vector
  free(l->elems);
  l->elems = nElems;
  l->cap = newCapacity;
}

//V2 END


int size(MyList* l) {
  return l->lg;
}

void add(MyList* l, ElemType e) {
  //V2
  ensureCapacity(l);
  //V2 END
  l->elems[l->lg] = e;
  l->lg++;
}

MyList copyList(MyList* l) {
  MyList rez = createEmpty();
  for(int i = 0; i < size(l); i++) {
    ElemType e = get(l, i);
    ElemType e_copy = copyPet(&e);
    add(&rez, e_copy);
  }
  return rez;
}

void testCreateList() {
  MyList l = createEmpty();
  assert(size(&l) == 0);
  destroy(&l);
}

void testIterateList() {
  MyList l = createEmpty();
  add(&l, createPet("a", "b", 10));
  add(&l, createPet("c", "d", 20));
  assert(size(&l) == 2);

  Pet p = get(&l, 0);

  assert(strcmp(p.type, "a") == 0);

  destroy(&l);

  assert(size(&l) == 0);
}

void testCopyList() {
  MyList l = createEmpty();
  add(&l, createPet("a", "b", 10));
  add(&l, createPet("c", "d", 20));

  MyList copy = copyList(&l);

  assert(size(&copy) == 2);

  Pet p = get(&copy, 0);

  assert(strcmp(p.type, "a") == 0);
  destroy(&copy);
}