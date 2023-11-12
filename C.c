#include <stdio.h>
#include <math.h>

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

void ResolveOne (struct equation one){
    
    if (one.solution.type == NONE || one.solution.type == TWO){
        printf("ce n'est pas une équation du premier ordre!\n");
    }
    else{
        one.solution.x0 = -one.b/one.a;
        printf("la solution est %d",one.solution.x0);
        printf("\n");
    }
}

int Delta (struct equation delt)
{
    int delta;
    delta = (delt.b*delt.b)-4*delt.a*delt.c;
    return delta;
};

void ResolveTwo (struct equation two)
{
    if (two.solution.type == NONE || two.solution.type == ONE){
        printf("ce n'est pas une équation du deuxième ordre!\n");
    }
    else{
        int delta = Delta(two);
        if (delta > 0) {
            two.solution.x1 = (-two.b-sqrt(delta))/(2*two.a);
            two.solution.x2 = (-two.b+sqrt(delta))/(2*two.a);
            printf("les solutions sont %d et %d \n",two.solution.x1, two.solution.x2);
        } 
        if (delta = 0) {
            two.solution.x2 = (-two.b)/(2*two.a);
            printf("l'unique solution est %d \n",two.solution.x2);
        } 
        else{
            printf("Il n y'a pas de solution réelle!");
        }
    }
};

void test(void) {
    int i;
    struct equation tab[6] = {
        {1, 1 ,1, {ONE, 1, 0, 0}},
        {1, 2, 1, {ONE, -1, 0, 0}},
        {1, 15, 1, {TWO, 1, 1, 0}},
        {2, -4, 2, {ONE, 1, 0, 0}},
        {1, -1, 0, {TWO, 1, 0, 0}},
        {1, 0, 1, {NONE, 0, 0, 0}},
    };
    for (i = 0; i < 6; i++) {
        printf("Pour l'équation %d :\n", i+1);
        //showsolution(tab[i].solution); //phase de tste showsolution
        printf("\n");
        //ResolveOne(tab[i]); //phase de test ResolveOne
        ResolveTwo(tab[i]); //phase de test ResolveTwo
    };
    
}

//commentaire
int main()
{
    test();
    return 0;
}
