#include <stdio.h>

struct X {int * p;};


struct X processX(struct X x) {

    int a = 1;

    x.p = &a;

    return x;

}


int main() {

    int b = 2;
    struct X x;

    x.p = &b;

    x = processX(x);

    printf("%d\n", * x.p);

}
