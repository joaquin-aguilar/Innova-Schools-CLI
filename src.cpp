#include <curses.h>
#include <iostream>
#include <ctime>
#include <string>
#include "./Utilidades/Graficos.hpp"
#include "./Utilidades/Input.hpp"
#include "./Utilidades/Parsers.hpp"
#include "./Estructuras_Datos/Hashtable.hpp" 
#include "./Estructuras_Datos/Pila.hpp"
#include "./Estructuras_Datos/Cola.hpp"
#include "./Estructuras_Datos/Lista.hpp"
#include "./Estructuras_Datos/Grafo.hpp"
#include "./Modelos/Deportista.hpp"
#include "./Modelos/Alumno.hpp"
#include "./Modelos/Destacado.hpp"
#include "./Ordenamiento/OrdMerge.hpp"
#include "./Ordenamiento/Quickmin.hpp"
using namespace std; 
using namespace Datasets;

template<typename T>
void imprimir(T e)
{
	cout << " " << e;
}

// lambdas
auto rng = [](int n) {return rand() % n; }; 


int main()
{
	initscr(); // iniciar curses: ncurses o pdcurses (linux/macos o windows)
	start_color(); // iniciar estilos de curses
	noecho(); // No mostrar caracteres escritos
    keypad(stdscr, TRUE); // Habilitar teclas especiales
	initColors(); // iniciar nuesta paleta de colores
	
	// imprimir bienvenida
	logo(); 
	clear();
	refresh();

	// Semillas, declaracion de variable, inicialización de clases y estructura de datos y declaración de lambdas
	srand(time(nullptr));
	Lista<Alumno*> alumnos = Lista<Alumno*>(); 
	Pila<Deportista*> deportistas = Pila<Deportista*>(); 
	Cola<Destacado*> destacados = Cola<Destacado*>();
	GrafoDirigido<int> grafo = GrafoDirigido<int>();
	int alum_in = 0, doce_in = 0;
	
	grafo.agregarVertice(10); // Vértice 0 con valor 10
    grafo.agregarVertice(20); // Vértice 1 con valor 20
    grafo.agregarVertice(30); // Vértice 2 con valor 30
    grafo.agregarVertice(40); // Vértice 3 con valor 40
    grafo.agregarVertice(50); // Vértice 4 con valor 50

    // Agregar algunas aristas
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 4);
    grafo.agregarArista(1, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 3);
    grafo.agregarArista(3, 4);
	// obtener y procesar inputs iniciales
	do 
	{
		printw("Ingrese el numero de alumnos que desea generar (Minimo 50, Maximo 1500): "); 
		refresh();
		alum_in = inputTecladoInt();
		printw("\n");
		refresh();
	} while (alum_in < 50 || alum_in > 1500);
	
	for (int i = 0; i < alum_in * 0.5; i++)
		alumnos.AnadirFin(new Alumno());

	for (int i = 0; i < alum_in * 0.3; i++)
		deportistas.push(new Deportista());

	for (int i = 0; i < alum_in * 0.2; i++)
		destacados.push(new Destacado());

	do
	{
		printw("Ingrese numero de administradores (Minimo 1, Maximo 5): "); 
		doce_in = inputTecladoInt();
		printw("\n");
		refresh();
	} 
	while (doce_in > 5 || doce_in < 1);


	HashTable hash = HashTable(doce_in); //Declaración de Hash
	int* dod = new int[doce_in]; //Inicialización de keys

	//Generador de llaves
	for (int g = 0; g < doce_in; g++) 
	{
		dod[g] = rng(100);
	} 

	string name; 
	for (int d = 0; d < doce_in; d++) 
	{ 
		name = "";
		name += nombresArr[rng(NOMBRES_LEN)]; 
		name += " ";
		name += apellidosArr[rng(APELLIDOS_LEN)]; 
		hash.insertar(dod[d], name); 
	}

	OrdenamientoMerge(dod, doce_in); //Ordenamiento del arreglo con las llaves dod

	while (true) //Inicio del programa
	{
		clear();
		int o = 0; 
		menu(); 
		o = inputTecladoInt();
		clear();
		refresh(); 
		
		if (o == 1) 
		{
			alumnos.AnadirFin(new Alumno());
			printw("\n\n\n\n\nAlumno generado!\n");
			refresh();
			getch();
		}

		else if (o == 2)
		{
			deportistas.push(new Deportista());
			printw("\n\n\n\n\nAlumno generado!\n");	
			refresh();
			getch();
		}
		else if (o == 3) 
		{
			destacados.push(new Destacado());
			printw("\n\n\n\n\nAlumno generado!\n");	
			refresh();
			getch();
		}
		else if (o == 4) 
		{
			vector<string> alumnos_str = alumnos.Mostrar();
			mostrarFiltrar(alumnos_str);
			alumnos_str.clear();
		}
		else if (o == 5) 
		{
			vector<string> destacados_str = colaToStrings(destacados);
			mostrarFiltrar(destacados_str);
			destacados_str.clear();
		}
		else if (o == 6) 
		{
			vector<string> deportistas_str = pilaToStrings(deportistas);
			mostrarFiltrar(deportistas_str);
			deportistas_str.clear(); 
		}
		
		else if (o == 7) 
		{
			attron(A_BOLD);
			attron(COLOR_PAIR(5));
			printw("\n\n\n");
			printw("\t\t\tEstudiantes regulares: %i\n", alumnos.longitud());
			attroff(COLOR_PAIR(5));
			attron(COLOR_PAIR(3));
			printw("\t\t\tEstudiantes deportistas: %i\n", deportistas.size());
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(4));
			printw("\t\t\tEstudiantes destacados: %i\n", destacados.size());
			attroff(COLOR_PAIR(4));
			attroff(A_BOLD);
			refresh();
			getch();
		}

		else if (o == 8) 
		{

			printw("%s", hash.Imprimir(dod).c_str());
			getch();
		}
		else if (o == 9) 
		{
			for (int i = 0; i < doce_in; i++) 
				printw("%i ", dod[i]); 
			getch();
		}
		if (o == 10)
		{
			vector<string> datos;
			for (string str : grafo.toStrings())
				datos.push_back(str);
			for (string str : grafo.matrizAdyacencia())
				datos.push_back(str);
			
			mostrarFiltrar(datos);
		}
		if (o == 11) 
		{
			Nodo<Alumno*>* raiz = alumnos.raiz();
			Nodo<Alumno*>* alumnoActual;
			Deportista* deportista;
			Destacado*  destacado;
			while (raiz != nullptr)
			{
				alumnoActual = raiz;
				raiz = raiz->siguiente; 
				delete alumnoActual->dato;
			}
		
			while (!deportistas.estaVacia())
			{
				deportista = deportistas.pop();
				delete deportista;
			}
			
			while (!destacados.estaVacia())
			{
				destacado = destacados.pop();
				delete destacado;
			}

			deportista = nullptr;
			destacado = nullptr; 
			raiz = nullptr;
			alumnoActual = nullptr;
			delete[] dod; 
			break;
		}
	}
	endwin();
	return 0;
}