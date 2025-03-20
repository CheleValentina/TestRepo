#include "mysort.h"



void sort(MyList* l, FunctieComparare func) {
    for(int i=0; i < size(l); i++) {
        for(int j=i+1; j < size(l); j++) {
            Pet p1 = get(l,i);
            Pet p2 = get(l,j);
            if(func(&p1, &p2) > 0)  {
              set(l,i,p2);
              set(l,j,p1);
            }
        }
    }
}