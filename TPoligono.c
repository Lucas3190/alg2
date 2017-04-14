#include "TPoligono.h"
#include "TPonto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

struct TPoligono criaPoligono(struct TPoligono A ,struct TPoligono B,int opcao){ // selecionar antes o poligono que deseja criar
	int i; 
	system("clear");
	if (A.total_pontos != 0){
		printf("O poligono já foi criado -- apenas pode ser inserido na opcao 2.\n");
		sleep(4);
	}
	else		
		switch (opcao){
			case 1:
				for (i=0;i<3;i++){
					*A.pontos=criaPonto();
					A.pontos=A.pontos+1;
					A.total_pontos=A.total_pontos+1;
				}
				A.pontos=A.pontos-i;
			return A;
			break;
			case 2:
				for (i=0;i<3;i++){
					*A.pontos=lerPonto();
					A.pontos=A.pontos+1;
					A.total_pontos=A.total_pontos+1;
				}
				A.pontos=A.pontos-i;
			return A;
			break;
				}
	return A;
}


struct TPoligono inserePontoPoligono(struct TPoligono A,int opcao){  //------------- seleciona o poligono antes e o modo que sera inserido 
	A.perimetro=0;
	printf("total de pontos: %d \n",A.total_pontos);
	sleep(2);
	if (A.total_pontos == 0){
		printf("\n ERRO: NÃO HÁ NENHUM POLIGONO!!");
		sleep(3);
		system("clear");
	}
	else
		if (A.total_pontos >= 3){
			switch (opcao){
				case 1:
					A.total_pontos=A.total_pontos+1;
					A.pontos=A.pontos+A.total_pontos;
					*A.pontos=criaPonto();
					A.pontos=A.pontos-A.total_pontos;
				break;
				case 2:
					A.total_pontos=A.total_pontos+1;
					A.pontos=A.pontos+A.total_pontos;
					*A.pontos=lerPonto();
					A.pontos=A.pontos-A.total_pontos;
				break;
				default:
					printf("ERRO: OPCAO NAO EXISTE");		
				break;
			}	
		}	
	return A;	
}	

struct TPoligono removePontoPoligono(struct TPoligono A){
	if (A.total_pontos > 3){
		A.total_pontos = A.total_pontos-1;
	}
	else 
		if (A.total_pontos == 3)
			printf("NAO PODE TIRAR PONTO");
	return A;	
}


struct TPoligono calcularPerimetro(struct TPoligono A){	// seleciona qual o poligono antes de entrar.
	float tempx,tempy,perimetro=0; int i;
	if (A.total_pontos != 0){
		for (i=1;i<=A.total_pontos;i++){
			if (i!=A.total_pontos){
				tempx=A.pontos->x; tempy=A.pontos->y;
				A.pontos=A.pontos + 1;
				perimetro=perimetro+sqrt(pow((A.pontos->x-tempx),2)+pow((A.pontos->y-tempy),2));
			}
			else{
				tempx=A.pontos->x; tempy=A.pontos->y;
				A.pontos=A.pontos - i;
				perimetro=perimetro+sqrt(pow((A.pontos->x-tempx),2)+pow((A.pontos->y-tempy),2));
			}
		}
		printf("O calculo do perimetro é %.2f\n",perimetro);
		A.perimetro=perimetro;
		sleep(8);
		return A;	
	}
	else 
	{
		printf("\n ERROO POLIGONO NAO ENCONTRADO");
	}
	return A;
}


struct TPoligono imprimePoligono (struct TPoligono A){
	int i;
	system("clear");
	printf("total de pontos = %d\n",A.total_pontos);
	if (A.total_pontos == 0){
		printf("ERRO: NENHUM POLIGONO EXISTENTE\n\n");
		sleep(8);
	}
	else 
		if ((A.total_pontos >= 3)){
			for (i=0;i<A.total_pontos;i++){
				printf("Ponto %d = (%.2f,%.2f) \n",i+1,A.pontos->x,A.pontos->y);
				A.pontos = A.pontos+1;
			}
		}
	A.pontos = A.pontos-i;
	return A;
}				

struct TPoligono calcularArea(struct TPoligono A){
	int i; float soma1=0,soma2=0,tempx,tempy;
	if (A.total_pontos != 0){
	for (i=1;i<=A.total_pontos;i++){ // FORMULA DE GAUSS
		tempx = A.pontos->x; tempy = A.pontos->y;
		A.pontos = A.pontos + 1;
		soma1= (A.pontos->x*tempy)+soma1;
		soma2= (A.pontos->y*tempx)+soma2;
	}
	A.area=(soma1+soma2)/2;
	printf("A area é %.2f \n",A.area);
	sleep(8);
	return A;
	}
	else{
		printf("\n Não existem nenhum ponto !!\n");
	}
	return A;
}

struct TPoligono intersecaoPoligonoAeB(struct TPoligono A, struct TPoligono B, struct TPoligono C){
	int i;
	if ((A.total_pontos != 0) && (B.total_pontos != 0)){
	for (i=1;i<=A.total_pontos;i++){
		C.pontos->x=A.pontos->x;
		C.pontos->y=A.pontos->y;
		C.total_pontos=C.total_pontos+1;
		C.pontos=C.pontos+1;
		A.pontos=A.pontos+1;
	}
	for (i=1;i<=A.total_pontos;i++){
		C.pontos->x=B.pontos->x;
		C.pontos->y=B.pontos->y;
		C.total_pontos=C.total_pontos+1;
		C.pontos=C.pontos+1;
		B.pontos=B.pontos+1;		
	}
	C.pontos=C.pontos-C.total_pontos;
	return C;
	}
	else{
		printf("\n Não existem dois poligonos !!\n");
	}
	return C;
}

struct TPoligono uniaoPoligonoAeB(struct TPoligono A, struct TPoligono B, struct TPoligono C){
	float tempAx,tempAy,tempBx,tempBy; int i,j;
	if ((A.total_pontos != 0) && (B.total_pontos != 0)){		
	for (i=1; i<=A.total_pontos;i++){
		tempAx=A.pontos->x; 
		tempAy=A.pontos->y;
		for(j=1;j<=B.total_pontos;j++){
			tempBx=B.pontos->x; 
			tempBy=B.pontos->y;
			if ((tempAx==tempBx) && (tempAy==tempBy)){
				C.pontos->x=tempAx; 
				C.pontos->y=tempAy; 
				C.total_pontos=C.total_pontos+1;	
				C.pontos=C.pontos+1;
			}
		} 
	}
	C.pontos=C.pontos - C.total_pontos;
	return C;
	}
	else{
		printf("\n Não existem dois poligonos !!\n");
	}
	return C;
}
