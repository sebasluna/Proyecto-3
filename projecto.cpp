/*
Nombre: Metodo de Ordenamiento y Busqueda
Autores: Richard Ramirez & Sebastian Luna
Fecha: 08/06/2017
Resumen: Programa que Utiliza los metodos de ordenamiento mas
comunes y dos metodos de busqueda.
*/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include<ctime>

//Funciones
void menu();
void generar_datos(int []);
void cargar_datos();
void ord_burbuja(int []);
void ord_inserccion(int []);
int quicksort(int [], int , int);
void ord_montones(int []);
void busq_secuencial(int []);
void busq_binaria(int []);
void descendente(int []);
void imprimir(int []);

//Sub menus
void menu_ordenamiento();
void menu_busqueda();
void menu_imprimir();

//Variables Globales
int l;
FILE *archivo;

//Funcion Princial
int main(){
	menu();
}
//Funcion Menu
void menu(){
	int opcion;
	int A[l];
	system("cls");
	do{
		printf("    ARREGLOS\n");
		printf("\n");
		printf("  1. Generar Datos.\n");
		printf("  2. Cargar Datos\n");
		printf("  3. Ordenar Datos\n");
		printf("  4. Buscar Datos\n");
		printf("  5. Imprimir Datos\n");
		printf("  0. Salir\n");
		printf("\nQue deceas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:generar_datos(A);
				break;
			case 2:cargar_datos();
				break;
			case 3:menu_ordenamiento();
				break;
			case 4:menu_busqueda();
				break;
			case 5:menu_imprimir();
				break;
			case 0:exit(0);
				break;
			default:printf("Numero Incorrecto");
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
//Funciones De Datos
void generar_datos(int A[]){
	int opcion;
	printf("Cuantos datos quieres generar \n");
	printf("\t(100000)\n");
	printf("\t(250000)\n");
	printf("\t(500000)\n");
	printf("\t(1000000)\n");
	printf("\t(2000000)\n");
	printf("Digite el valor: ");
	scanf("%d",&l);
    system("cls");
    printf("Como quieres guardar tu arreglo\n");
    printf("\n1. En orden");
    printf("\n2. Desorden");
    printf("\nQue deceas hacer: ");
    scanf("%d",&opcion);
    system("cls");
    switch(opcion){
    	case 1:quicksort(A,0,l);
			printf("Ordenacion con Exito\n");
			printf("\n");
    		break;
    	case 2:
    		printf("Guardado con exito\n\n");
    		break;
    	default:printf("Numero equivocado\n");
	}
}
void cargar_datos(){
	int opcion;
	printf("Cuantos datos quieres generar \n");
	printf("\t1.(100000)\n");
	printf("\t2.(250000)\n");
	printf("\t3.(500000)\n");
	printf("\t4.(1000000)\n");
	printf("\t5.(2000000)\n");
	printf("Que quieres hacer: ");
	scanf("%d",&opcion);
    system("cls");
    switch(opcion){
    	case 1:archivo = fopen("100Mil.txt", "r");
    		break;
    	case 2:archivo = fopen("200Mil.txt", "r");
    		break;
    	case 3:archivo = fopen("500Mil.txt", "r");
    		break;
    	case 4:archivo = fopen("1Millon.txt", "r");
    		break;
    	case 5:archivo = fopen("2Millones.txt", "r");
    		break;
    	default:printf("Numero equivocado\n");
    		break;
	}
}
//Menu Ordenamiento
void menu_ordenamiento(){
	int A[l];
	int opcion,x,y;
	printf("\nOrdenamiento Por:\n");
	printf("\t\t1. Burbuja.\n");
	printf("\t\t2. Inserccion.\n");
	printf("\t\t3. Rapida.\n");
	printf("\t\t4. Montones.\n");
	printf("\nQue quieres hacer: ");
	scanf("%d",&opcion);
	system("cls");
	switch(opcion){
		case 1:ord_burbuja(A);
			break;
		case 2:ord_inserccion(A);
			break;
		case 3:quicksort(A,0,l);
			printf("Ordenacion con Exito\n");
			printf("\n");
			break;
		case 4:ord_montones(A);
			break;
		default:printf("Numero equivocado\n");
	}
}
//Funciones Ordenamiento
void ord_burbuja(int A[]){
	int  i, j, aux;
	for(i=0; i<l; i++){
		for(j = 0; j<l-1; j++){
			if(A[j] > A[j+1]){
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
			}
		}
	}
	printf("ordenado con exito\n");
	printf("\n");
}
void ord_inserccion(int A[]){
	int  i, j, aux;
	for(i=1; i<l; i++){
		aux = A[i];
		j = i-1;
		while(j>=0 && A[j]>aux){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = aux;
	}
	printf("ordenado con exito\n");
	printf("\n");
}
int quicksort(int A[], int primero, int ultimo){
    int central,i,j,pivote;
    central=(primero+ultimo)/2;
    pivote = A[central];
    i = primero;
    j = ultimo;
    do{
        while(A[i] < pivote)i++;
        while(A[j] > pivote)j--;
        if(i <= j){
            int temp;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);
    if(primero < j){
        quicksort(A,primero,j);
    }
    if(i < ultimo){
        quicksort(A,i,ultimo);
    }
}
void ord_montones(int A[]){
	int inter=(l/2),i=0,j=0,k=0,aux;
	srand(time(NULL));
	for (i=0; i<l; i++){
		A[i] = (rand () % (1999998 + 1)) - 999999;
	}
	while(inter>0){
		for(i=inter; i<l; i++){
			j = i-inter;
			while(j>=0) {
				k=j+inter;
				if(A[j]<=A[k]){
					j--;
				}else{
					aux=A[j];
					A[j]=A[k];
					A[k]=aux;
					j=j-inter;
				}
			}
		}
		inter=inter/2;
	}
	printf("ordenado con exito\n");
}
//Menu Busqueda
void menu_busqueda(){
	int A[l];
	int opcion;
	printf("\nBusquedad Por:\n");
	printf("\t\t1. Secuencial.\n");
	printf("\t\t2. Binaria.\n");
	printf("\nQue deceas hacer: ");
	scanf("%d",&opcion);
	system("cls");
	switch(opcion){
		case 1:busq_secuencial(A);
			break;
		case 2:busq_binaria(A);
			break;
		default:printf("Numero equivocado\n");
			break;
	}
}
//Funciones Busqueda
void busq_secuencial(int A[]){
	int i, dato;
	bool estado = false;
	printf("Que dato quiere buscar: ");
	scanf("%d", &dato);
	for(i=0; i<l; i++){
		if(A[i]==dato){
			estado = true;
			break;
		}
	}
	if(estado==true){
		printf("Dato encontrado\n");
	}else{
		printf("Dato no encontrado\n");
	}
}
void busq_binaria(int A[]){
	int sup, inf, mitad, dato;
	bool estado = false;
	int i = 0;
	inf = 0;
	sup = l;
	printf("Que dato quiere buscar: ");
	scanf("%d",&dato);
	while(inf <= sup && i <= l){
		mitad = (inf+sup)/2;
		if(A[mitad] == dato){
			estado = true;
			break;
		}
		if(A[mitad] > dato){
			sup = mitad;
		}
		if(A[mitad] < dato){
			inf = mitad;
		}
		i++;
	}
	if(estado == true){
		printf("Dato encontrado\n");
	}else{
		printf("Dato no encontrado\n");
	}
}
//Menu Imprimir
void menu_imprimir(){
	int A[l];
	int opcion;
	printf("\nImprimir de Manera:\n");
	printf("\t\t1. Ascendente.\n");
	printf("\t\t2. Descendente.\n");
	printf("\t\t3. Original.\n");
	printf("\nQue deceas hacer: ");
	scanf("%d",&opcion);
	system("cls");
	switch(opcion){
		case 1:ord_burbuja(A);
			for(int i = 0; i < l; i++){
				printf("Arreglo posicion[%d]: %d", i, A[i]);
				printf("\n");
			}
			break;
		case 2:descendente(A);
			break;
		case 3:imprimir(A);
			break;
		default:printf("NUMERO INCORRECTO\n");
	}
}
//Impresion
void imprimir(int A[]){
	for(int i=0; i<l; i++){
		printf("Posicion [%d]: %d", i, A[i]);
		printf("\n");
	}
}
void descendente(int A[]){
	int i;
	for (i= l; i>= 0; i--) {
		printf("Posicion[%d]: %d\n",i,A[i]);
  }
}
