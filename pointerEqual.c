#include <stdio.h>

int main() {

    int i = 11, j = 22;

    int * pointeri = &i, * pointerj = &j;

    if (pointeri == pointerj) printf("equal\n");

}
