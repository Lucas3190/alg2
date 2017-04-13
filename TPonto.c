#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TPonto.h"

struct TPonto criaPonto(){
	struct TPonto ponto;
	srand(time(NULL));	// Não repete o número ja gerado.
	ponto.x = (float)(rand())/(float)(RAND_MAX)*100.0; // Gera o numero aleatorio entre 0..100.
	srand(time(NULL));
	ponto.y = (float)(rand())/(float)(RAND_MAX)*100.0;
	return ponto;
}

struct TPonto lerPonto(){
	struct TPonto ponto;
	system("clear");
	printf("Entre com o numero desejado de x: "); scanf("%f",&ponto.x);
	printf("Entre com o número desejado de y: "); scanf("%f",&ponto.y);
	return ponto;
}
