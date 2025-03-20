#pragma once

typedef struct {
    // char type[30];
    // char species[30];
    // V2
    char* type;
    char* species;
    float price;
    // V2 END
}Pet;

/*
Create a new pet.

@param type: A string representing the pet's type (e.g., "dog", "cat").
@param species: A string representing the species (e.g., "bulldog", "persian").
@param price: A floating-point value representing the pet's price.

@return A new Pet struct instance.
*/
Pet createPet(char* type, char* species, float price);

/*
 Dealocate memory occupied by pet
*/
void destroyPet(Pet* pet);

/*
 Validate pet
*/
int valideaza(Pet pet);

//V2
/*
Create a copy for the pet
Deep copy - copy all the sub-parts
*/
Pet copyPet(Pet* pet);
//V2 END


void testCreateDestroy();