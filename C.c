#include <stdio.h>

enum solutiontype { 
    NONE=0,
    ONE=1,
    TWO=2,   
};

struct solution{
    enum solutiontype type;
    int x0;
    int x1;
    int x2;
};

struct equation {
    int a;
    int b;
    int c;
    struct solution solution;
};

void showsolution (struct solution sol)
{
    if (sol.type == NONE){
		printf("il n'y a pas de solution");
    }
	else if (sol.type == ONE) {
		printf( "il y'a une solution %d", sol.x0);
	}
	else if (sol.type == TWO){
		printf( "il y'a deux solution %d %d",sol.x1, sol.x2);
	}
}

void test(void) {
    int i;
    struct equation tab[6] = {
        {1, 1 ,1, {ONE, 1, 0, 0}},
        {1, 2, 1, {ONE, -1, 0, 0}},
        {1, -2, 1, {TWO, 1, 1, 0}},
        {2, -4, 2, {ONE, 1, 0, 0}},
        {1, -1, 0, {TWO, 1, 0, 0}},
        {1, 0, 1, {NONE, 0, 0, 0}},
    };
    for (i = 0; i < 6; i++) {
        printf("Pour l'équation %d :\n", i+1);
        showsolution(tab[i].solution);
        printf("\n");
        ResolveOne(tab[i].solution);
    };
    
}

void ResolveOne (struct equation one){
    
    one.solution.x0 = -one.b/one.a;
    printf("la solution est %d",one.solution.x0);
}
//commentaire
int main()
{
 test();
    return 0;
}
