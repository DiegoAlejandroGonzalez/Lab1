/*
Taller_1 ALSE
Creadores: Nelson Leonardo HernÃ¡ndez - Diego Alejandro Gonzalez - Diego Villalobos
Primer taller
*/


#include <stdio.h>
#include <string.h>                                                                             //librerías pedidas
#include <stdlib.h>

#define MAX_TAM 100

void Menu(char [MAX_TAM], char [MAX_TAM], int, char [MAX_TAM], char [MAX_TAM], int);
void Ingresa_vals(char [MAX_TAM], char [MAX_TAM], int, char [MAX_TAM], char [MAX_TAM], int);
void Compara(char [MAX_TAM], char [MAX_TAM], int, char [MAX_TAM], char [MAX_TAM], int);
void Suma(char [MAX_TAM], char [MAX_TAM], int, char [MAX_TAM], char [MAX_TAM], int);



int main (void)
{
	int Cant_Datos = 0;
	int Cant_Datos_1 = 0;
	char Datos[MAX_TAM];
	char Datos_1[MAX_TAM];                                                                  //Declaración de variables
	char Datos_Proc[MAX_TAM];	
	char Datos_Proc_1[MAX_TAM];
	printf("\n\n\nBienvenido");
	Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);	        //Menú, así para que el usuario pueda salir cuando lo desee
}


void Menu(char Datos[], char Datos_Proc[], int Cant_Datos, char Datos_1[], char Datos_Proc_1[], int Cant_Datos_1)
{

	int opc_menu = 0;

	printf(" \n\nElija una opciÃ³n \n \n1. Ingresar valores_1. \n2. Ingresar valores_2. \n3. Compara valores (Mayor, menor o igual). \n4. ¿La suma de los primeros valores es mayor que la suma de los segundos? \n5. Salir. \n\n");
	
	scanf("%d", &opc_menu);

	switch(opc_menu)
	{
		case 1: Ingresa_vals(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);   break;
         	case 2: Ingresa_vals(Datos_1, Datos_Proc_1, Cant_Datos_1, Datos, Datos_Proc, Cant_Datos);   break;
		case 3: Compara(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);        break;
		case 4: Suma(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);           break;
		case 5:						                                            exit(-1);
		default: 
		{
		printf("\n\nNo existe esta opción, intente nuevamente\n\n");
		Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);	
		}
	}
}


void Ingresa_vals(char Datos[], char Datos_Proc[], int Cant_Datos, char Datos_1[], char Datos_Proc_1[], int Cant_Datos_1)
{
	char Separador[] = ";";
	int Cantidad_Datos = 0, cont = 0;
	
	printf("\nIngrese valores numéricos enteros separados por punto y coma ;\n");
	scanf("%s", Datos);
	printf("\nSus valores: \n\n");
	
	char *val = strtok(Datos, Separador);	
	if(val != NULL)
	{
		while(val != NULL)
		{
			printf("Dato %d: %s\n",(Cantidad_Datos + 1), val);                                     //Se usa strtok para separar en strings pequeños el string de entrada
			Datos_Proc[Cantidad_Datos] = atoi(val);			                               //Luego se guarda en un vector para facilitar el procesamiento de los datos
			val = strtok(NULL, Separador);
			Cantidad_Datos = Cantidad_Datos + 1;
    		}
	}
	Cant_Datos = Cantidad_Datos;	

	Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
}


void Compara(char Datos[], char Datos_Proc[], int Cant_Datos, char Datos_1[], char Datos_Proc_1[], int Cant_Datos_1)
{
	int cont = 0; 
	
	if(Cant_Datos == 0 || Cant_Datos_1 == 0)
	{
		printf("\nIngrese valores primero");                                                                  //Se deben haber ingresado datos previamente para utilizar esta función
		Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
	}
	
	else
	{
	if(Cant_Datos != Cant_Datos_1)
	{
		printf("Debe ingresar el mismo número de valores");
		Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
	}
	else
	{
		for(cont = 0 ; cont < Cant_Datos ; cont ++)
		{
			if(Datos_Proc_1[cont] == Datos_Proc[cont])
				printf("\n %d es igual a %d \n", Datos_Proc_1[cont], Datos_Proc[cont]);	
			if(Datos_Proc_1[cont] < Datos_Proc[cont])
				printf("\n %d es menor que %d \n", Datos_Proc_1[cont], Datos_Proc[cont]);	       //Compara e imprime posición a posición
			if(Datos_Proc_1[cont] > Datos_Proc[cont])
				printf("\n %d es mayor que %d \n", Datos_Proc_1[cont], Datos_Proc[cont]);
			
		}
	}

	Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
	}
}


void Suma(char Datos[], char Datos_Proc[], int Cant_Datos, char Datos_1[], char Datos_Proc_1[], int Cant_Datos_1)
{
	int cont = 0;
	float suma1 = 0, suma2 = 0;
	
	if(Cant_Datos == 0 || Cant_Datos_1 == 0)
	{
		printf("\nIngrese valores primero");                                                               //Se deben haber ingresado datos previamente para utilizar esta función
		Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
	}
	else
	{
		if(Cant_Datos != Cant_Datos_1)
	{
		printf("Debe ingresar el mismo número de valores");
		Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
	}
	else
	{

	for(cont = 0 ; cont < Cant_Datos ; cont ++)
	{
		suma1 = suma1 + Datos_Proc[cont];
		suma2 = suma2 + Datos_Proc_1[cont];
	}

	printf("\n\nsuma1: %f   suma2: %f \n\n", suma1, suma2);

	if(suma1 == suma2)
		printf("\n La suma de los primeros y segundos valores es igual \n");	
	if(suma1 < suma2)
		printf("\n La suma de los primeros valores es menor a la suma de los segundos \n");
	if(suma1 > suma2)
		printf("\n La suma de los primeros valores es mayor a la suma de los segundos \n");

	
	Menu(Datos, Datos_Proc, Cant_Datos, Datos_1, Datos_Proc_1, Cant_Datos_1);
	}
	}
}

