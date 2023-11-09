DEBUT
ENUME solutiontype  
	NONE=0
	ONE=1
	TWO=2

STRUCT solution 
	PARAMETRE solutiontype.type
	PARAMETRE ENTIER x0
	PARAMETRE ENTIER x1	
	PARAMETRE ENTIER x2

STRUCT equation
	PARAMETRE ENTIER a
	PARAMETRE ENTIER b
	PARAMETRE ENTIER c
	PARAMETRE solution.solution

DEBUT showsolution
	SI solutiontype = NONE
		ECRIRE "il n'y a pas de solution"
	SINON SI solutiontype = ONE 
		ECRIRE "il y'a une solution" x
	SINON SI solutiontype =TWO
		ECRIRE "il y'a deux solution"x1 x2
FIN PROGRAMME
