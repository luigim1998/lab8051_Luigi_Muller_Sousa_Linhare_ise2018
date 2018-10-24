/*Codigo da maquina de cafe*/

#include <at89x52.h>
#define ENTRADA P3_2
#define BOTAOCHA P3_0
#define BOTAOCAFE P3_1
#define VALVULACAFE P2_0
#define VALVULACHA P2_1

int contador = 0;

void ligar_valvula(unsigned int seg){
	int i, j;
	for(i = 0; i < seg; i++){
		for(j = 0; j < 12750; j++){}
	}
}

void moedaInserida() interrupt 0{//a moeda foi inserida
	while(BOTAOCHA == BOTAOCAFE){} // esperasse que somente um dos botoes sejam apertados, entao um os estados dos dois ficam diferentes
	if(BOTAOCHA == 1){ //se o botao do cha for apertado ele liga a valvula por um tempo e depois desliga junto com o botao
		VALVULACHA = 1;
		ligar_valvula(10);
		BOTAOCHA = 0;
		VALVULACHA = 0;
	} else { //se o botao do cafe for apertado ele liga a valvula por um tempo e depois desliga junto com o botao
		VALVULACAFE = 1;
		ligar_valvula(10);
		BOTAOCAFE = 0;
		VALVULACAFE = 0;
	}
}

void main(){
	P2 = 0;//zera os pinos
	P3 = 0;//zeras os pinos
	EA = 1;//habilita as interrupções
	EX0 = 1;//habilita a interrupção zero
}