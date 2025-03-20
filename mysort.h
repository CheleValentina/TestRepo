#pragma once
#include "MyList.h"

/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
*/
typedef int(*FunctieComparare)(void* elem1, void* elem2);

/**
* Sorteaza in place
* func - relatia dupa care se sorteaza
*/
void sort(MyList* l, FunctieComparare func);