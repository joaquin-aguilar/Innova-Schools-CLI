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

	GrafoDirigido<string> grafo = GrafoDirigido<string>();

	int vertCount = 0, arisCount = 0;
	int alum_in = 0, doce_in = 0;
	

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
	// todo inicializacion del BST

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
		else if (o == 10)
		{
			// todo: operaciones con BST
		}
		
		else if (o == 11)
		{
			
			char input;
			while (true)
			{
				menuGrafos();
				input = getch();
				clear();
				if (input == '1')
				{
					vector<string> datos;
					for (string str : grafo.toStrings())
						datos.push_back(str);
					for (string str : grafo.matrizAdyacencia())
						datos.push_back(str);

					imprimirGrafos(datos);
				}
				else if (input == '2')
				{
					std::string buscar;
					int opcion;
					while (true)
					{
						printw("Ingresa el tipo de alumno (1: regular, 2: deportista, 3: destacado): ");
						opcion = inputTecladoInt();
						printw("\n");
						if (opcion >= 1 && opcion <= 3)
							break;
					}
					printw("Ingresa el indice del alumno (si no existe se saltara): ");
					int alumIndice = inputTecladoInt();
					printw("\n");
					std::string res;
					if(opcion == 1)
						res = obtenerAlumno(alumnos.Mostrar(), alumIndice);
					else if(opcion == 2)
						res = obtenerAlumno(pilaToStrings(deportistas), alumIndice);
					else if(opcion == 3)
						res = obtenerAlumno(colaToStrings(destacados), alumIndice);
					if(res != "" || res.size() != 0)
					{
						grafo.agregarVertice(res);
						vertCount++;
					}
				}
				else if (input == '3')
				{
					std::string buscar;
					int opcion;
					while (true)
					{
						printw("Ingresa el tipo de alumno (1: regular, 2: deportista, 3: destacado): ");
						opcion = inputTecladoInt();
						printw("\n");
						if (opcion >= 1 && opcion <= 3)
							break;
					}
					printw("Ingresa el indice del alumno (si no existe se saltara): ");
					int alumIndice = inputTecladoInt();
					printw("\n");
					std::string res;
					if(opcion == 1)
						res = obtenerAlumno(alumnos.Mostrar(), alumIndice);
					else if(opcion == 2)
						res = obtenerAlumno(pilaToStrings(deportistas), alumIndice);
					else if(opcion == 3)
						res = obtenerAlumno(colaToStrings(destacados), alumIndice);
					printw("Ingresa el indice del veritice a modificar (si no existe se saltara): ");
					printw("\n");
					opcion = inputTecladoInt();
					if (opcion >= 1 && opcion <= vertCount)
					{
						grafo.modificarVertice(opcion, res);
					}
					
				}
				else if (input == '4')
				{
					int origen , llegada;
					printw("ingresa el indice del vertice de origen: ");
					origen = inputTecladoInt();
					printw("\n");

					printw("ingresa el indice del vertice de llegada: ");
					llegada = inputTecladoInt();
					printw("\n");
					
					if (vertCount != 0 && vertCount >= origen && vertCount >= llegada)
					{
						grafo.agregarArista(origen, llegada);
					}
					else
					{
						printw("No se pudo procesar el cambio!");
						refresh();
						getch();
					}
				}
				else if (input == '5')
				{
					int origen , llegada;
					printw("ingresa el indice del vertice de origen: ");
					origen = inputTecladoInt();
					printw("\n");

					printw("ingresa el indice del vertice de llegada: ");
					llegada = inputTecladoInt();
					printw("\n");
					
					if (vertCount != 0 && vertCount >= origen && vertCount >= llegada)
					{
						grafo.eliminarArista(origen, llegada);
					}
					else
					{
						printw("No se pudo procesar el cambio!");
						refresh();
						getch();
					}
				}
				
				else if (input == '\n')
				{
					break;
				}
				refresh();
			}
		}
		if (o == 12) 
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