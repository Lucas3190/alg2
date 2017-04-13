#include "TPoligono.h"
#include "TPonto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

struct TPoligono criaPoligono(struct TPoligono A ,struct TPoligono B,int opcao){ // selecionar antes o poligono que deseja criar
	int i; 
	system("clear");
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
	if (A.total_pontos == 0){
		printf("\n ERRO: NÃO HÁ NENHUM POLIGONO!!");
		sleep(3);
		system("clear");
	}
	else
		if (A.total_pontos >= 3){
			switch (opcao){
				case 1:
					A.pontos=A.pontos+1;
					*A.pontos=criaPonto();
					A.total_pontos=A.total_pontos+1;
				break;
				case 2:
					A.pontos=A.pontos+1;
					*A.pontos=lerPonto();
					A.total_pontos=A.total_pontos+1;
				
				break;
				default:
					printf("ERRO: OPCAO NAO EXISTE");		
			}	
		}
	A.pontos=A.pontos-A.total_pontos;	
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


void calcularPerimetro(struct TPoligono A,struct TPoligono B){	// seleciona qual o poligono antes de entrar.
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

		printf("O calculo do perimetro é %f\n",perimetro);
		sleep(8);
		}	
	}
	else 
	{
		printf("\n ERROO POLIGONO NAO ENCONTRADO");
		sleep(8);
	}
	
}


struct TPoligono imprimePoligono (struct TPoligono A){
	int i;
	system("clear");
	printf("olha o total = %d\n",A.total_pontos);
	if (A.total_pontos == 0){
		printf("ERRO: NENHUM POLIGONO EXISTENTE\n\n");
		sleep(8);
	}
	else 
		if ((A.total_pontos >= 3)){
			for (i=0;i<A.total_pontos;i++){
				printf("\nPonto %d em x é = %f \nPonto %d em y é = %f \n",i,A.pontos->x,i,A.pontos->y);
				A.pontos = A.pontos+1;
			}
		}
	A.pontos = A.pontos-i;
	return A;
}				

void calcularArea(struct TPoligono A, struct TPoligono B){
	int i; float soma1=0,soma2=0,tempx,tempy;
	for (i=1;i<=A.total_pontos;i++){ // FORMULA DE GAUSS
		tempx = A.pontos->x; tempy = A.pontos->y;
		A.pontos = A.pontos + 1;
		soma1= (A.pontos->x*tempy)+soma1;
		soma2= (A.pontos->y*tempx)+soma2;
	}
//	area=(soma1+soma2)/2;
}

