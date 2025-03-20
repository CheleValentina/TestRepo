#include <stdio.h>
#include "pet.h"
#include "MyList.h"
#include "petstoreservice.h"

void testAll() {
    testCreateDestroy();
    testCreateList();
    testSort();
    // testIterateList();
    // testCopyList();
    // testAddPet();
}

void readPet(MyList* all_pets) {
    printf("Type: ");
    char type[30];
    scanf("%29s", type);

    printf("Species: ");
    char species[30];
    scanf("%29s", species);

    printf("Price: ");
    float price;
    scanf("%f", &price);

    int error = addPet(all_pets, type, species, price);
    if (error != 0) {
        printf("Invalid pet. \n");
    }
    else {
        printf("Pet added. \n");
    }

}

void printAllPets(MyList * all_pets) {
    printf("Pets: ");
    for (int i=0; i<size(all_pets); i++) {
        Pet p = get(all_pets, i);
        printf("Type:%s Species:%s Price:%f\n", p.type, p.species, p.price);
    }

}

void filterPets(MyList * all_pets) {
    printf("Filter substring: ");
    char substring[30];
    scanf("%29s", substring);

    MyList filtered_pets = getAllPet(all_pets, substring);
    printAllPets(&filtered_pets);
}



void run() {
    MyList allPets = createEmpty();
    int ruleaza = 1;
    while (ruleaza) {
        printf("1. Add\n2. Filter\n3. All\n0. Exit\nCommand:");
        int cmd = 0;
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                readPet(&allPets);
            break;
            case 2:
                filterPets(&allPets);
            break;
            case 3:
                printAllPets(&allPets);
            break;
            case 0:
                ruleaza = 0;
            break;
            default:
                printf("Comanda invalida!");
        }
    }
}


int main(void) {
    int x;

    testAll();
    // run();
    return 0;
}