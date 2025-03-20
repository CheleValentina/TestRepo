#include "pet.h"

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


Pet createPet(char* type, char* species, float price) {
  Pet rez;
  // strcpy(rez.type, type);
  // strcpy(rez.species, species);

  // V2
  size_t nrC = strlen(type) + 1;
  rez.type = malloc(sizeof(char) * nrC);
  strncpy(rez.type, type, nrC);

  nrC = strlen(species) + 1;
  rez.species = malloc(sizeof(char) * nrC);
  strncpy(rez.species, species, nrC);
  // V2 END

  rez.price = price;
  return rez;
}

void destroyPet(Pet* pet) {
  // pet->type[0] = '\0';
  // pet->species[0] = '\0';
  // pet->price = -1;

  // V2
  free(pet->type);
  free(pet->species);

  // mark that pet is destroyed; avoid accidental use after destroy
  pet->type = NULL;
  pet->species = NULL;
  pet->price = -1;
  // V2 END
}

int valideaza(Pet pet) {
  if (strlen(pet.species) == 0) {
    return 1;
  };
  if (strlen(pet.type) == 0) {
    return 2;
  }
  if(pet.price < 0) {
    return 3;
  }
  return 0;
}


//V2
Pet copyPet(Pet* pet) {
  return createPet(pet->type, pet->species, pet->price);
}
//V2 END

void testCreateDestroy() {
  Pet pet = createPet("dog", "buldog", 100);
  printf("%s", pet.type);
  printf("%s", pet.species);
  assert(strcmp(pet.type, "dog") == 0);
  assert(strcmp(pet.species, "buldog") == 0);
  assert(pet.price == 100);

  destroyPet(&pet);


  // assert(strlen(pet.type) == 0);
  // assert(strlen(pet.species) == 0);
  // assert(pet.price == -1);

  //V2
  assert(pet.type == NULL);
  assert(pet.species == NULL);
  assert(pet.price == -1);
  //V2 END
}