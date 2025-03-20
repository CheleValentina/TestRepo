#pragma once


#include "MyList.h"

int addPet(MyList* l, char* type, char* species, float price);

MyList getAllPet(MyList* l, char* typeSubstring);

void testAddPet();

void testSort();