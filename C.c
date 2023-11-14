#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
    
    if (one.solution.type == NONE || one.solution.type == TWO){//cette vérification n'est plus utile avec la fonction resolve
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
    if (two.solution.type == NONE || two.solution.type == ONE){ //cette vérification n'est plus utile avec la fonction resolve
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
        /*else{
            printf("Il n y'a pas de solution réelle!\n"); // afiche même quand il y'a des solutions reelles donc je laisse de coté
        }*/
    }
};

void resolve (struct equation poly){

    if (poly.solution.type == NONE){
        printf("Il n'y a pas de solution dans R\n");
    }
    if(poly.solution.type == ONE){
        ResolveOne(poly);
    }
    if(poly.solution.type == TWO){
        ResolveTwo(poly);
    }
};
void supprimerCaractere(char chaine[], int position) {
    int longueur = strlen(chaine);
    
    if (position < 0 || position >= longueur) {
        printf("Position invalide.\n");
        return;
    }
    for (int i = position; i < longueur - 1; ++i) {
        chaine[i] = chaine[i + 1];
    }

    chaine[longueur - 1] = '\0';
}

void Decode(char *chaine) {
    int i = 0;
    int j = 0;
    int k = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int r = 0;
    int signe_a = 0;
    int signe_b = 0;
    int signe_c = 0;
    int signe_r = 0;
    int longeur = 0;

    //suppr les espaces 
    longeur = strlen(chaine);
    for (j=0;j<longeur;j++){
        if (chaine[j] == ' '){
            supprimerCaractere(chaine,j);
            while (chaine[j] == ' '){
                supprimerCaractere(chaine,j);
            }
        }
    }
    
    if (chaine[0] == '-'){
        signe_a = 1; //signe passe à 1 pour les negatifs
        supprimerCaractere(chaine,0);
    }

    while (chaine[i] != 'x' && chaine[i] != '\0') {
        a = a * 10 + (chaine[i] - '0');
        printf("%c\n",chaine[i]);
        i++;
    }


    if (chaine[i] == 'x') {
        i++; 
    }
    if (chaine[i] == '^' && chaine[i + 1] == '2'){
        if (chaine[i+2] == '-'){
            i = i + 2;
        }
        else{
            i = i+3;
        }
    }

    while (chaine[i] != 'x' && chaine[i] != '\0') {
        if (chaine[i] == '-'){
            signe_b = 1; //signe passe à 1 pour les negatifs
            supprimerCaractere(chaine,i);
        }
        b = b * 10 + (chaine[i] - '0');
        printf("%c\n",chaine[i]);
        i++;
    }

    if (chaine[i] == 'x') {
        if (chaine[i+1] == '-'){
            i = i + 1;
        }
        else{
            i = i+2;
        } 
    }

    while (chaine[i] != '\0' && chaine[i] != '=') {
        if (chaine[i] == '-'){
            signe_c = 1; //signe passe à 1 pour les negatifs
            supprimerCaractere(chaine,i);
        }
        c = c * 10 + (chaine[i] - '0');
        //printf("%c\n",chaine[i]);
        i++;
    }
    if (chaine[i] == "="){
        i++;
        while (chaine[i] != '\0'){
            if (chaine[i] == '-'){
                signe_r = 1; //signe passe à 1 pour les negatifs
                supprimerCaractere(chaine,i);
        }
        r = r * 10 + (chaine[i] - '0');
        //printf("%c\n",chaine[i]);
        i++;
        }
    }
    
    if (signe_a == 1){
        a = a*(-1);
    }
    if(signe_b == 1){
        b =b*(-1);
    }
    if (signe_c == 1){
        c = c*(-1);
    }
    if (signe_r == 1){
        r = r*(-1);
    }
    c = c - r;
    printf("a=%d\n", a);
    printf("b=%d\n", b);
    printf("c=%d\n", c);
    printf("i=%d\n", i);

    if (c!=0){
        struct equation coef = {a,b,c,{TWO}};
        resolve(coef);
    }
    if (c==0){
        struct equation coef ={a,b,c,{ONE}};
        resolve(coef);
    }
} 

void test(void) {
    int i;
    int a,b,c;
    char chaine[] = "1    x ^  2+  1 0 x +5=5";
    struct equation tab[6] = {
        {1, 1 ,1, {ONE, 1, 0, 0}},
        {1, 2, 1, {ONE, -1, 0, 0}},
        {1, 15, 1, {TWO, 1, 1, 0}},
        {2, -4, 2, {ONE, 1, 0, 0}},
        {1, -1, 0, {TWO, 1, 0, 0}},
        {1, 0, 1, {NONE, 0, 0, 0}},
    };
    for (i = 0; i < 6; i++) {
       // printf("Pour l'équation %d :\n", i+1);
        //showsolution(tab[i].solution); //phase de test showsolution
       // printf("\n");
        //ResolveOne(tab[i]); //phase de test ResolveOne
        //ResolveTwo(tab[i]); //phase de test ResolveTwo
        //resolve(tab[i]); //phase de test fonction central resolve
    };
    Decode(chaine);
}

//commentaire
int main()
{
    test();
    return 0;
}
