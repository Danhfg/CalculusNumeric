/**
 * @file	falsaPosicao.cpp
 * @brief	Contém a função método interativo da falsa posição
 * @author	Samuel Lucas de Moura Ferino
 * @version	0.0.2
 */ 

/**
 * 					**** TEOREMA DE BOLZANO **** 
 * 
 * 			Sejam f uma função contínua e [a,b] E Domínio(f). Diante disso, temos que:			
 * 		
 * 			f(a) * f(b) < 0  ==>  Existe pelo menos uma raiz nesse intervalo [a,b]
 * 
 * 
 */ 

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;

double pontoMedio(double a, double b){
	return a + ((b-a)/2);
}

double f(double x){
	return pow(x,3) - 1.7*pow(x,2) - 12.78*x -10.08;
}

tuple<double,bool> metodoFalsaPosicao(	double inicioIntervalo, 
						double fimIntervalo, 
						double erroTolerancia, 
						int numero_IteracaoMaxima){

	int numero_IteracaoAtual = 0; //-> Quantidade de iterações realizadas atualmente.
	double ponto_Medio; //-> Contém o valor do ponto médio atual.
	double FA; //-> Contém o valor de f(a) onde 'a' é o ponto inicial do intervalo usado.
    double FB; //-> Contém o valor de f(b) onde 'b' é o ponto final do intervalo usado.
	double FP; //-> Contém o valor de f(p) onde 'p' é o ponto médio do intervalo usado.
	
	numero_IteracaoAtual += 2;

	FA = f(inicioIntervalo);
    FB = f(fimIntervalo);


	while( numero_IteracaoAtual <= numero_IteracaoMaxima ){

        ponto_Medio = fimIntervalo - ( FB*(fimIntervalo - inicioIntervalo)/(FB - FA) );

		if ( fabs(ponto_Medio - fimIntervalo) < erroTolerancia )
			return make_tuple(ponto_Medio, true);

		numero_IteracaoAtual += 1;
		FP = f(ponto_Medio);

		if( FP*FB < 0 ){
			inicioIntervalo = fimIntervalo;
			FA = FB; 
		}

		fimIntervalo = ponto_Medio;
		FB = FP;

	}

	return make_tuple(ponto_Medio,false);
}

int main(){

	//if( get<1>( metodoFalsaPosicao(-1,1, 0.00001, 10) ) == true )
		cout << "A raiz eh " << fabs( get<0>( metodoFalsaPosicao(-100,100, 0.00001, 10) ) )<< endl;

	return 0;
}
