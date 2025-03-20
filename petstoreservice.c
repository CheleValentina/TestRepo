#include "petstoreservice.h"

#include "MyList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysort.h"

int addPet(MyList* l, char* type, char* species, float price) {
  Pet p = createPet(type, species, price);
  int succ = valideaza(p);
  if (succ != 0) return succ;

  add(l, p);
  return 0;
}

/*
Filter pets in the store
typeSubstring - cstring
return all pets where typeSubstring is a substring of the type
*/
MyList getAllPet(MyList* l, char* typeSubstring) {
  if (typeSubstring == NULL || strlen(typeSubstring) == 0) {
    return copyList(l);
  }

  MyList rez = createEmpty();
  for (int i = 0 ; i < size(l); i ++ ) {
    Pet p = get(l, i);
    if (strstr(p.type, typeSubstring) != NULL) {
      add(&rez, p);
    }
  }

  return rez;
}


int cmpByType(void* p1, void* p2) {
   return strcmp(((Pet*)p1)->type, ((Pet*)p2)->type);
}


MyList sortByType(MyList* l) {
  MyList copy = copyList(l);
  sort(&copy, cmpByType);
  return copy;
}


void testSort() {
  MyList l = createEmpty();
  addPet(&l, "Pet1", "cat", 1.0);
  addPet(&l, "Pet3", "cat", 1.0);
  addPet(&l, "Pet2", "cat", 2.0);

  MyList sorted = sortByType(&l);

  assert(strcmp(get(&sorted, 0).type,"Pet1") == 0);
  assert(strcmp(get(&sorted, 1).type,"Pet2") == 0);
  assert(strcmp(get(&sorted, 2).type,"Pet3") == 0);

  destroy(&sorted);
  destroy(&l);
}


void testAddPet() {
  MyList l = createEmpty();
  int error = addPet(&l, "", "b", 0);
  assert(error != 0);
  assert(size(&l) == 0);

  error = addPet(&l, "a", "", 1);
  assert(error != 0);
  assert(size(&l) == 0);

  error = addPet(&l, "a", "b", -1);
  assert(error != 0);
  assert(size(&l) == 0);

  addPet(&l, "a", "b", 1);
  addPet(&l, "a2", "d", 1);

  MyList filtered = getAllPet(&l, "");
  assert(size(&filtered) == 2);

  filtered = getAllPet(&l, "b");
  assert(size(&filtered) == 0);

  filtered = getAllPet(&l, "a");
  assert(size(&filtered) == 2);
}