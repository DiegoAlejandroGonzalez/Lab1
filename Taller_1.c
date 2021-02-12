/*
Taller_1 ALSE
Creadores: Nelson Leonardo HernÃ¡ndez - Diego Alejandro Gonzalez - Diego Villalobos
Primer taller
*/


#include <stdio.h>
#include <string.h>                                                                                             //librerías pedidas
#include <stdlib.h>

#define MAX_TAM 100

void Menu(char [MAX_TAM], char [MAX_TAM], int);
void Ingresa_vals(char [MAX_TAM], char [MAX_TAM], int);
void Promedio(char [MAX_TAM], char [MAX_TAM], int, int);
void Desv_Est(char [MAX_TAM], char [MAX_TAM], int, int);
void Max_Min(char [MAX_TAM], char [MAX_TAM], int, int);
void Todo(char [MAX_TAM], char [MAX_TAM], int, int);
void Valida(char [MAX_TAM], char [MAX_TAM], int);


int main (void)
{
	int Cant_Datos = 0;
	char Datos[MAX_TAM];
	char Datos_Proc[MAX_TAM];
	printf("\n\n\nBienvenido");
	Menu(Datos, Datos_Proc, Cant_Datos);	                                                               //Menú, así para que el usuario pueda salir cuando lo desee
}


void Menu(char Datos[], char Datos_Proc[], int Cant_Datos)
{

	int opc_menu = 0;

	printf(" \n\nElija una opciÃ³n \n \n1. Ingresar valores. \n2. Mostrar promedio. \n3. Mostrar desviaciÃ³n estÃ¡ndar. \n4. Mostrar valores mÃ¡ximo y mÃ­nimo. \n5. Mostrar todo. \n6. Salir. \n\n");
	
	scanf("%d", &opc_menu);

	switch(opc_menu)
	{
		case 1: Ingresa_vals(Datos, Datos_Proc, Cant_Datos);           break;
		case 2: Promedio(Datos, Datos_Proc, Cant_Datos, opc_menu);     break;
		case 3: Desv_Est(Datos, Datos_Proc, Cant_Datos, opc_menu);     break;                          //Menú, opciones definidas, si no es coorecta la opción se vuelve a menú
		case 4: Max_Min(Datos, Datos_Proc, Cant_Datos, opc_menu);      break;
		case 5: Todo(Datos, Datos_Proc, Cant_Datos, opc_menu);         break;	
		case 6: exit(-1) ;
		default: 
		{
		printf("\n\nNo existe esta opción, intente nuevamente\n\n");
		Menu(Datos, Datos_Proc, Cant_Datos);	
		}
	}
}


void Ingresa_vals(char Datos[], char Datos_Proc[], int Cant_Datos)
{
	char Separador[] = ";";
	//char temp[MAX_TAM];
	int Cantidad_Datos = 0, cont = 0;
	
	printf("\nIngrese valores numéricos enteros separados por punto y coma ;\n");
	scanf("%s", Datos);
	printf("\nSus valores: \n\n");
	
	char *val = strtok(Datos, Separador);	
	if(val != NULL)
	{
		while(val != NULL)
		{
			printf("Dato %d: %s\n",(Cantidad_Datos + 1), val);                                     
			Datos_Proc[Cantidad_Datos] = atoi(val);			                                //Se usa strtok para separar en strings pequeños el string de entrada
			val = strtok(NULL, Separador);                                                          //Luego se guarda en un vector para facilitar el procesamiento de los datos
			Cantidad_Datos = Cantidad_Datos + 1;
    		}
	}
	Cant_Datos = Cantidad_Datos;	                                                                        //La cantidad de pequeños string es la cantidad de datos ingresados por el usuario

	Menu(Datos, Datos_Proc, Cant_Datos);                                       
}


void Promedio(char Datos[], char Datos_Proc[], int Cant_Datos, int opc_menu)
{
	int cont = 0;
	float prom = 0, suma = 0;
	
	Valida(Datos, Datos_Proc, Cant_Datos);
	
	for(cont = 0 ; cont < Cant_Datos ; cont ++)
	{                                                                                                       //Suma y divide
		suma = suma + Datos_Proc[cont];
	}	

	prom = suma/Cant_Datos;

	printf("\n*********************************************************\n\nEl promedio de los valores ingresados es: %.3f \n\n*********************************************************\n", prom);
	
	if(opc_menu != 5)
	Menu(Datos, Datos_Proc, Cant_Datos);

	else
	return;	
}


void Desv_Est(char Datos[], char Datos_Proc[], int Cant_Datos, int opc_menu)
{
	int cont = 0;
	float prom = 0, suma = 0, temp = 0, desv = 0, pdesv = 0, res = 0, i = 0;

	Valida(Datos, Datos_Proc, Cant_Datos);

	for(cont = 0 ; cont < Cant_Datos ; cont ++)
	{
		suma = suma + Datos_Proc[cont];
	}	

	prom = suma/Cant_Datos;

	for(cont = 0 ; cont < Cant_Datos ; cont ++)
	{
		temp = ((Datos_Proc[cont] - prom)*(Datos_Proc[cont] - prom)) + temp;                            //Se aplica la fórmula 
	}
	
	pdesv = temp/(Cant_Datos-1);

	do
	{
		desv = desv + 0.00001;
		res = desv * desv;                                                                              //Para calcular la raíz cuadrada se inicializa una variable en 
	}while(pdesv >= res);                                                                                   //cero, se va sumando 0.00001 y se multiplica por si misma hasta
                                                                                                                //llegar al valor deseado
	printf("\n*********************************************************\n\nLa desviación estándar es: %.3f\n\n*********************************************************\n", desv);
	
	if(opc_menu != 5)
	Menu(Datos, Datos_Proc, Cant_Datos);
                         
	else
	return;
}

void Max_Min(char Datos[], char Datos_Proc[], int Cant_Datos, int opc_menu)
{
	int mayor = 0, menor = 0, cont =0;

	Valida(Datos, Datos_Proc, Cant_Datos);
	
	mayor = Datos_Proc[0];
	menor = Datos_Proc[0];

	for(cont = 0 ; cont < Cant_Datos ; cont ++)
	{
		if(Datos_Proc[cont] < menor)
		menor =	Datos_Proc[cont];
		if(Datos_Proc[cont] > mayor)
		mayor =	Datos_Proc[cont];		
	}
	printf("\n*********************************************************\n\nEl mayor valor que ingresó es: %d\n", mayor);
	printf("El menor valor que ingresó es: %d\n\n*********************************************************\n", menor);

	if(opc_menu != 5)
	Menu(Datos, Datos_Proc, Cant_Datos);

	else
	return;
}	

void Todo(char Datos[], char Datos_Proc[], int Cant_Datos, int opc_menu)
{
	Valida(Datos, Datos_Proc, Cant_Datos);
	printf("\n\nSe muestra todo:\n\n");
	
	Promedio(Datos, Datos_Proc, Cant_Datos, opc_menu);     
	Desv_Est(Datos, Datos_Proc, Cant_Datos, opc_menu);     
	Max_Min(Datos, Datos_Proc, Cant_Datos, opc_menu); 

	Menu(Datos, Datos_Proc, Cant_Datos);
}

void Valida(char Datos[], char Datos_Proc[], int Cant_Datos)
{ 
	if(Cant_Datos == 0)
	{
		printf("\nNo ha ingresado valores, inténtelo de nuevo\n");
		Menu(Datos, Datos_Proc, Cant_Datos);
	}
	else
	return;
}
