#include <stdio.h>
#include "TPonto.h"
#include "TPoligono.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



int escolhePoligono(){
	int opcao2;
	system("clear");
	printf("-----------------------------------------------\n");
	printf("Escolha o poligono que deseja usar para a operação\n");
	printf("1 - Poligono A.\n");
	printf("2 - Poligono B.\n");
	printf("-----------------------------------------------\n");
	printf("Entre com a opção desejada: "); scanf("%d",&opcao2);
	return opcao2;
}

int menu2(){
	int opcao2;
	system("clear");
	printf("----------------------------------------\n");
	printf("1 - Criar ponto aleatório.\n");
	printf("2 - Ler ponto.\n");
	printf("----------------------------------------\n");
	printf("Entre com a opção desejada: "); scanf("%d",&opcao2);
	return opcao2;
}


void mainMenu(struct TPoligono A, struct TPoligono B,struct TPoligono C){
	int opcao,escolha,opcao2=0,temp; 
	system("clear");
	printf("----------------------------------------\n");
	printf("1 - Cria poligono novo.\n");
	printf("2 - Insere ponto no poligono desejado.\n");
	printf("3 - Remove ponto do poligono desejado.\n");
	printf("4 - Calcula o perimetro do poligono desejado.\n");
	printf("5 - Calcula a àrea do poligono desejado.\n");
	printf("6 - Calcula a intersecao entre A e B.\n");
	printf("7 - Calcula a uniao entre A e B.\n");
	printf("8 - Imprime o poligono desejado.\n");
	printf("----------------------------------------\n");
	printf("Entre com a opção desejada: "); scanf("%d",&opcao);
	switch (opcao){
		case 1:{  
			opcao2=menu2(); 
			temp=opcao2;
			escolha=escolhePoligono();
			opcao2=opcao2+escolha;
				switch (opcao2){
					case 2:{
						A=criaPoligono(A,B,temp);
						break;
						}	
					case 3:{
						if (escolha == 1){
							A=criaPoligono(A,B,temp);
						}	
						else
							if (escolha == 2){
								B=criaPoligono(B,A,temp);
							}
						break;	
						}	
					case 4:{
						B=criaPoligono(B,A,temp);
						break;
					}
				}
			mainMenu(A,B,C);
			}
		case 2:{
			opcao2=menu2(); 
			temp=opcao2;
			escolha=escolhePoligono();
			opcao2=opcao2+escolha;
				switch (opcao2){
					case 2:
						A=inserePontoPoligono(A,temp);
						break;
					case 3:
						if (escolha == 1){
							A=inserePontoPoligono(A,temp);
							break;
						}	
						else
							if (escolha == 2){
								B=inserePontoPoligono(B,temp);			
								break;
							}	
					case 4: 
						B=inserePontoPoligono(B,temp);
						break;
				}
		mainMenu(A,B,C);
		}	
		case 3:{
			escolha=escolhePoligono();
				switch (escolha){
					case 1:
						A=removePontoPoligono(A);
					break;
					case 2:
					 	B=removePontoPoligono(B);
					break;
				}	
			mainMenu(A,B,C);
			}
		case 4:{
			escolha=escolhePoligono();
			switch (escolha){
				case 1: 
					A=calcularPerimetro(A);
				break;
				case 2:
					B=calcularPerimetro(B);
				break;
				default:
						printf("OPCAO INEXISTE -- \n");
				break;
			}
			mainMenu(A,B,C);
		}
		case 5:{
			escolha=escolhePoligono();
			switch (escolha){
				case 1:
					A=calcularArea(A);
				break;
				case 2:
					B=calcularArea(B);
				break;
				default:
						printf("OPCAO INEXISTE -- \n");
				break;
			}
		mainMenu(A,B,C);
		}
		case 6:{
			C=intersecaoPoligonoAeB(A,B,C);
			C=imprimePoligono(C);
			mainMenu(A,B,C);
		}
		case 7:{
			C=uniaoPoligonoAeB(A,B,C);
			C=imprimePoligono(C);
			mainMenu(A,B,C);
		}
		case 8:{
			escolha=escolhePoligono();
				switch (escolha){
					case 1:
						A=imprimePoligono(A);
						sleep(4);
					break;
					case 2:
						B=imprimePoligono(B);
						sleep(4);
					break;
				}
			mainMenu(A,B,C);
			}
		default:
			printf("ERRO: -----------------------");	
			break;
	break;
	}
}

int main(){
	struct TPoligono A,B,C;
	A.total_pontos=0,B.total_pontos=0; C.total_pontos=0;
	A.pontos =(struct TPonto * )malloc(sizeof(float));
	B.pontos =(struct TPonto * )malloc(sizeof(float));
	C.pontos=(struct TPonto *)malloc(sizeof(float)); 
	mainMenu(A,B,C);
	free(A.pontos);
	free(B.pontos);
	free(C.pontos);
	return 0;
}
