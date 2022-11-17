#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;
//declaracion de variables

int* item, * a�o, registros, desicion, n = 1;
string* nombre, * clasificacion, * caracteristicas, * genero, * descripcion;
float* precio, * iva, * total;

//funciones con void
void Alta();
void Eliminar();
void Lista();
void Modificar();
void Archivo();

int main()
{
	int opciones;
	do
	{
		printf("\t **GAME PLANET**\n");
		printf(" 1.- Alta de Videojuego\n 2.-Modificar dato de Videojuego\n  3.- Eliminar dato de Videojuego\n 4.- Lista de datos de Videojuegos Vigentes(busqueda)\n 5.- Limpiar Pantalla\n 6.- Salir\n");
		scanf_s("%d", &opciones);
		//casos de opciones
		switch (opciones)
		{
		case 1:
			Alta();
			system("pause");
			return main();
			break;

		case 2:
			Modificar();
			system("pause");
			return main();
			break;

		case 3:
			Eliminar();
			system("pause");
			return main();
			break;

		case 4:
			Lista();
			system("pause");
			return main();
			break;

		case 5:
			system("pause");
			system("cls");
			return main();
			break;

		case 6:
			Archivo();
			exit(1);
			break;

		default:
			printf(" Ingresa una de las 6 opciones disponibles\n");
			system("pause");
		}
	} while (opciones != 5);
}

void Alta()
{
	printf("cuantos registros desea dar de alta \n");
	scanf_s("%d", &registros);
	item = new int[registros];
	a�o = new int[registros];
	nombre = new string[registros];
	clasificacion = new string[registros];
	caracteristicas = new string[registros];
	genero = new string[registros];
	descripcion = new string[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	//arreglo

	for (int i = 0; i < registros; i++)
	{
		printf(" Ingrese el Numero del articulo \n");
		scanf_s("%d", &item[i]);
		do
		{
			if (item[i] != item[i - n])
			{
				n = n + 1;

			}
			else
			{
				printf(" El articulo ya existe \n");
				printf(" Ingrese el articulo \n");
				scanf_s("%d", &item[i]);
			}
		} while (n < registros);

		printf(" Escribe el a%co del articulo \n",164);
		scanf_s("%d", &a�o[i]);
		printf(" Escribe el nombre del articulo \n");
		cin.ignore();
		getline(cin, nombre[i]);
		printf(" Ingrese la clasificacion \n");
		getline(cin, clasificacion[i]);
		printf(" Ingrese las caracteristicas \n");
		getline(cin, caracteristicas[i]);
		printf(" Ingrese el genero \n");
		getline(cin, genero[i]);
		printf(" Ingrese la descripcion \n");
		getline(cin, descripcion[i]);
		printf(" Ingrese el precio unitario\n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];

	}
}

void Eliminar()
{
	int eliminar;
	printf(" Ingrese el numero del articulo a elimnar\n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registros; i++)
	{
		if (eliminar == item[i])
		{
			item[i] = 0;
		}
	}
}

void Modificar()
{
	int modificar;
	do
	{
		printf(" Ingresa el numero del Articulo que desea modificar \n");
		scanf_s("%d", &modificar);

	} while (modificar <= 0);

	for (int i = 0; i < registros; i++)
	{
		if (modificar == item[i])
		{
			
			printf(" Ingrese el a%co\n", 164);
			scanf_s("%d", &a�o[i]);

			printf(" Ingresa el nombre del articulo\n");
			cin.ignore();
			getline(cin, nombre[i]);

			printf(" Ingrese la clasificacion\n");
			getline(cin, clasificacion[i]);

			printf(" Ingresa el caracteristicas\n");
			getline(cin, caracteristicas[i]);

			printf(" Ingresa las genero\n");
			getline(cin, genero[i]);

			printf(" Ingresa la descripcion\n");
			getline(cin, descripcion[i]);

			printf(" Ingresa el precio Unitario \n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * .16;
			total[i] = precio[i] + iva[i];
			
		}
	}
}

void Lista()
{
	int opcion2;
	string busqueda;

	printf("GAME PLANET \n\n 1.- Clasificacion \n 2.- Genero \n 3.- Salir\n");
	scanf_s("%d", &opcion2);
	switch (opcion2)
	{
	case 1:
		printf(" Ingresa la clasificacion a buscar\n");
		cin.ignore();
		getline(cin, busqueda);

		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == busqueda)
			{
				if (item[i] != 0)
				{
					printf(" Nombre del videojuego: %s\n", nombre[i].c_str());
					printf(" Articulo: %d\n", item[i]);
					printf(" El a%co es: %d\n", 164, a�o[i]);

					printf(" Clasificacion: %s\n", clasificacion[i].c_str());
					printf(" El genero es : %s\n", genero[i].c_str());
					printf(" Caracteristicas : %s\n", caracteristicas[i].c_str());
					printf(" Descripcion : %s\n", descripcion[i].c_str());

					printf(" Precio : %f\n", precio[i]);
					printf(" El iva es: %f\n", iva[i]);
					printf(" El total es: %f\n", total[i]);
				}
			}
		}
		break;

	case 2:
		printf("Ingresa el genero que desea buscar\n");
		cin.ignore();
		getline(cin, busqueda);
		for (int i = 0; i < registros; i++)
		{
			if (genero[i] == busqueda)
			{
				if (item[i] != 0)
				{
					printf(" Nombre del videojuego: %s\n", nombre[i].c_str());
					printf(" Articulo: %d\n", item[i]);
					printf(" El a%co es: %d\n", 164, a�o[i]);

					printf(" Clasificacion: %s\n", clasificacion[i].c_str());
					printf(" El genero es : %s\n", genero[i].c_str());
					printf(" Caracteristicas : %s\n", caracteristicas[i].c_str());
					printf(" Descripcion : %s\n", descripcion[i].c_str());

					printf(" Precio : %f\n", precio[i]);
					printf(" El iva es: %f\n", iva[i]);
					printf(" El total es: %f\n", total[i]);
				}
			}
		}
		break;

	case 3:
		printf("saliendo...");
		system("pause");
		break;
	}
}

void Archivo()
{
	ofstream archivos;
	string nombre;

	nombre = "Almacenamiento.txt";
	archivos.open(nombre.c_str(), ios::out);

	if (archivos.fail())
	{
		printf(" Error al genrar el archivo\n");
		system("pause");
		exit(1);
	}

	archivos << "\t\t Informacion \n";
	for (int i = 0; i < registros; i++)
	{
		if (item[i] != 0)
		{
			archivos << "dato:" << i + 1 << endl;
			archivos << "articulo:" << item[i] << endl;
			archivos << "anio:" << a�o[i] << endl;
			archivos << "videojuego:" << nombre[i] << endl;
			archivos << "clasificacion:" << clasificacion[i] << endl;
			archivos << "genero:" << genero[i] << endl;
			archivos << "caracteristicas:" << caracteristicas[i] << endl;
			archivos << "descripcion:" << descripcion[i] << endl;
			archivos << "precio:" << precio[i] << endl;
			archivos << "iva:" << iva[i] << endl;
			archivos << "total:" << total[i] << endl;
		} 
	}
	system("pause");
	archivos.close();
} //manual, github y cpp
