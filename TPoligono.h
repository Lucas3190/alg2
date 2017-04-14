#ifndef	TPOLIGONO_H
#define TPOLIGONO_H

#include <stdio.h>
#include "TPonto.h"

struct TPoligono{
	struct TPonto *pontos;
	int total_pontos;
	float perimetro,area;
};
 
struct TPoligono criaPoligono(struct TPoligono A,struct TPoligono B,int opcao);

struct TPoligono inserePontoPoligono(struct TPoligono A,int opcao);

struct TPoligono removePontoPoligono(struct TPoligono A);

struct TPoligono calcularPerimetro(struct TPoligono A);

struct TPoligono calcularArea(struct TPoligono A);

struct TPoligono intersecaoPoligonoAeB(struct TPoligono A, struct TPoligono B,struct TPoligono C);

struct TPoligono uniaoPoligonoAeB(struct TPoligono A, struct TPoligono B,struct TPoligono C);

struct TPoligono imprimePoligono(struct TPoligono A);

int escolhePoligono();


#endif
