#ifndef GRAFICOS_HPP
#define GRAFICOS_HPP


#include <iostream>
#include <functional>
#include <ncurses.h>
#include <string>
#include <vector>
#include "./Filtros.hpp"
#include "./Input.hpp"



// auto borrar = [](int x, int y) {std::string lol = "         "; for(int i = 0; i < 9; i++){ move(x,y); printw("%s", lol.c_str()); refresh();}};
// auto blancos = [](int veces) {std::string lol = ""; for(int i = 0; i < veces; i++){ lol += " ";} return lol;}; 
// auto pixel = [](int veces){std::string lol = ""; for(int i = 0; i < veces; i++){ lol += char(219);} return lol;};

// void cuadrado(int x, int y)
// {
// 	int d = y;
// 	move(x,y); //18,18
// 	printw("%s",pixel(10).c_str());
// 	for(int i = 0; i < 7; i++)
// 	{
// 		d = d + i;
// 		move(x,d + i);
// 		printf("%s%s%s", pixel(1).c_str(), blancos(8).c_str(), pixel(1).c_str());
// 	}
// 	//cout << pixel(1) << blancos(7) << pixel(1) << "\n"; cout << pixel(1) << blancos(7) << pixel(1) << "\n"; cout << pixel(1) << blancos(7) << pixel(1) << "\n"; cout << pixel(1) << blancos(7) << pixel(1) << "\n"; cout << pixel(1) << blancos(7) << pixel(1) << "\n"; cout << pixel(1) << blancos(7) << pixel(1) << "\n"; cout << pixel(1) << blancos(7) << pixel(1) << "\n";
// 	move(x,d + 1);
// 	printw("%s\n", pixel(10).c_str());
// 	refresh();
// }

// void mas()
// {
// 	for(int i = 0; i < 3; i++)
// 		printw("%s%s%s\n", blancos(3).c_str(), pixel(1).c_str(), blancos(3).c_str());

// 	printw("%s%s%s\n", blancos(1).c_str(), pixel(5).c_str(), blancos(1).c_str());

// 	for(int i = 0; i < 3; i++)
// 		printw("%s%s%s\n",blancos(3).c_str(), pixel(1).c_str(), blancos(3).c_str());
// 	refresh();
// }

// void lista(){
// 	move(20,20);
// 	for(int i = 0; i < 3; i++){
// 		move(20,20 + (i*2));
// 		printw("", blancos(1).c_str(), pixel(3).c_str(), blancos(1).c_str(), pixel(1).c_str());
// 	}
// 	refresh();
// }

void initColors()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);

	init_pair(6, COLOR_BLACK, COLOR_WHITE);
	init_pair(7, COLOR_BLUE, COLOR_WHITE);
}

void logo()
{
	attron(COLOR_PAIR(1));
	printw("\n\n\n\n");
	printw("			  _____                                  _____      _                 _ \n");    
	printw("			 |_   _|                                / ____|    | |               | |\n");    
	printw("			   | |  _ __  _ __   _____   ____ _    | (___   ___| |__   ___   ___ | |___ \n"); 
	printw("			   | | | '_ \\| '_ \\ / _ \\ \\ / / _` |    \\___ \\ / __| '_ \\ / _ \\ / _ \\| / __|\n"); 
	printw("			  _| |_| | | | | | | (_) \\ V / (_| |    ____) | (__| | | | (_) | (_) | \\__ \\\n"); 
	printw("	 		|_____|_| |_|_| |_|\\___/ \\_/ \\__,_|   |_____/ \\___|_| |_|\\___/ \\___/|_|___/\n"); 
	printw("\n\n\n\n");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	printw("                                                  Integrantes:                                \n\n\n");
	attroff(COLOR_PAIR(2));
	attron(COLOR_PAIR(3));
	printw("                                         -Raul Andres Cerreno Zevallos     U202314685\n");
	attroff(COLOR_PAIR(3));
	attron(COLOR_PAIR(4));
	printw("                                         -Joaquin Andre Lechuga Aguilar    U202221619\n\n\n\n");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(5));
	printw("                                     	 Pulse cualquier tecla para continuar...");
	attroff(COLOR_PAIR(5));
	refresh();
	getch();
}

// void logo2() {
// 	printw("\n\n\n\n\n\n");
// 	printw("", blancos(12), pixel(10), blancos(4), pixel(3), blancos(7), pixel(2), blancos(4), pixel(3), blancos(7), pixel(2), blancos(4), pixel(9), blancos(3),  pixel(3), blancos(10), pixel(3), blancos(2), pixel(9), "\n");
// 	printw("", blancos(12), pixel(10), blancos(4), pixel(5), blancos(5), pixel(2), blancos(4), pixel(5), blancos(5), pixel(2), blancos(4), pixel(2), blancos(5),  pixel(2), blancos(5),  pixel(2), blancos(8), pixel(2), blancos(4), pixel(3), blancos(3), pixel(3), "\n");
// 	printw("", blancos(16), pixel(2),  blancos(8), pixel(3), blancos(1), pixel(2), blancos(4), pixel(2), blancos(4), pixel(3), blancos(1), pixel(2), blancos(4),  pixel(2), blancos(4),  pixel(2), blancos(5), pixel(2), blancos(6), pixel(2), blancos(6), pixel(2), blancos(5), pixel(3), blancos(2), pixel(4), "\n");
// 	printw("", blancos(16), pixel(2),  blancos(8), pixel(3), blancos(2), pixel(2), blancos(3), pixel(2), blancos(4), pixel(3), blancos(2), pixel(2), blancos(3),  pixel(2), blancos(4),  pixel(2), blancos(5), pixel(2), blancos(7), pixel(2), blancos(4), pixel(2), blancos(6), pixel(3), blancos(1), pixel(1), blancos(1), pixel(3), "\n");
// 	printw("", blancos(16), pixel(2),  blancos(8), pixel(3), blancos(3), pixel(2), blancos(2), pixel(2), blancos(4), pixel(3), blancos(3), pixel(2), blancos(2),  pixel(2), blancos(4),  pixel(2), blancos(5), pixel(2), blancos(8), pixel(2), blancos(2), pixel(2), blancos(7), pixel(4), blancos(2), pixel(3),"\n");
// 	printw("", blancos(12), pixel(10), blancos(4), pixel(3), blancos(4), pixel(2), blancos(1), pixel(2), blancos(4), pixel(3), blancos(4), pixel(2), blancos(1),  pixel(2), blancos(4),  pixel(2), blancos(5), pixel(2), blancos(9), pixel(4), blancos(8), pixel(3), blancos(3), pixel(3), "\n");
// 	printw("", blancos(12), pixel(10), blancos(4), pixel(3), blancos(5), pixel(3), blancos(5), pixel(3), blancos(5), pixel(3), blancos(5), pixel(9), blancos(10), pixel(2), blancos(9),  pixel(3), blancos(3), pixel(3), "\n\n");
// 	printw("                                                  Integrantes:                                \n\n\n");
// 	printw("                                         -Raul Andres Cerreno Zevallos     U202314685\n");
// 	printw("                                         -Joaquin Andre Lechuga Aguilar    U202221619\n\n\n\n");
// 	printw("                                      Pulse cualquier tecla para continuar...");
// 	refresh();
//     getch();
// }

void menu() 
{
	printw("\n\n\n");
	printw("BIENVENIDO A INNOVA SCHOOLS\n\n\n");
	printw("1. Generar nuevo alumno\n");
	printw("2. Generar nuevo alumno deportista\n");
	printw("3. Generar nuevo alumno destacado\n");
	printw("4. Mostrar alumnos (lista)\n");
	printw("5. Mostrar alumnos destacados (cola)\n");
	printw("6. Mostrar alumnos deportistas (pila)\n");
	printw("7. Mostrar cantidad de alumnos registrados\n");
	printw("8. Mostrar hash con administradores\n");
	printw("9. Mostrar llaves de Hash\n");
    printw("10.Salir\n");
	printw("Tu opcion: ");
	refresh();
}

// void menu2() {
// 	printw("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",                 blancos(30), pixel(5), blancos(3), pixel(1), blancos(3),  pixel(1),   blancos(3), pixel(1),   blancos(3), pixel(1), blancos(3), pixel(5), blancos(3), pixel(2), blancos(5), pixel(2), blancos(3), pixel(4));
// 	printw("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",     blancos(31), pixel(1), blancos(5), pixel(1), pixel(1),    blancos(2), pixel(1),   blancos(3), pixel(1),   pixel(1), blancos(2), pixel(1), blancos(3), pixel(1), blancos(3), pixel(1), blancos(4), pixel(2), blancos(3), pixel(2), blancos(4), pixel(1), blancos(1), pixel(2));
// 	printw("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", blancos(30), pixel(1), blancos(5), pixel(1), blancos(1),  pixel(1),   blancos(1), pixel(1),   blancos(3), pixel(1), blancos(1), pixel(1), blancos(1), pixel(1), blancos(3), pixel(1), blancos(3), pixel(1), blancos(5), pixel(2), blancos(1), pixel(2), blancos(5), pixel(2), blancos(1), pixel(1));
// 	printw("\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",                 blancos(28), pixel(5), blancos(3), pixel(1), blancos(2),  pixel(2),   blancos(3), pixel(1),   blancos(2), pixel(2), blancos(3), pixel(5), blancos(7), pixel(1), blancos(7), pixel(1), blancos(2), pixel(1));
// 	printw("\n\n\n\n");
// 	refresh();
// 	lista();
// }

void imprimirContenido(const std::vector<std::string>& datos, int inicio) 
{
    clear();

	// Obtener tamaño de la pantalla
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x); 

	int pos = 0;
	// posicionar el cursor e imprimir cada linea que permita el tamaño de la consola
    for (int i = inicio, y = 0; i < std::min((int)datos.size(), inicio + (max_y - 1)); ++i, ++y) 
	{
		pos = 0;
		move(y, 0);
		if(i > 0)
			attron(COLOR_PAIR(3));
		for(int j = 0; j < 5; j++)
		{
			printw("%c", datos[i][j]);
		}
		if(i > 0)
			attroff(COLOR_PAIR(3));
		for (int j = 5; j < datos[i].size(); j++)
		{
			printw("%c", datos[i][j]);
		}
		refresh();
    }

    refresh();
}
void mostrarFiltrar(std::vector<std::string>& alumnos)
{
	std::vector<std::string> resultadoFilro = alumnos;
	std::string filtro = "";
	int inicio = 0;
	while (true)
	{
	// Imprimir contenido visible en la pantalla
		imprimirContenido(resultadoFilro, inicio);

	// Mostrar instrucciones de navegación
		move(LINES - 1,0);
		attron(COLOR_PAIR(4));
		printw("Usa las fechas para navegar.");
		attroff(COLOR_PAIR(4));
		attron(COLOR_PAIR(1));
		printw("'Intro' para salir.");
		attroff(COLOR_PAIR(1));
		attron(COLOR_PAIR(3));
		printw("'b' para iniciar el filtro. Filtro: %s", filtro.c_str());
		attroff(COLOR_PAIR(3));
		refresh();

		// Obtener entrada del usuario
		int ch = getch();
		if(KEY_UP == ch && inicio > 0)
			inicio--;
				
		else if(KEY_DOWN == ch && inicio < (int)(alumnos.size()) - LINES + 1)
			inicio++;

		else if ('b' == ch)
		{
			// Limpiar los caracteres escritos antes
			int retroceder = filtro.size();
			for (int i = 0; i < retroceder; i++)
				printw("\b");
			for (int i = 0; i < retroceder; i++)
				printw(" ");
			for (int i = 0; i < retroceder; i++)
				printw("\b");
			resultadoFilro.clear();
			
			// obtener el nuevo filtro y aplicarlo
			filtro = inputTecladoStr();
			for (int i = 0; i < alumnos.size(); i++)
			{
				std::vector<std::string> palabras = dividirPalabras(alumnos[i]);
				for (int j = 1; j < palabras.size(); j++)
				{
					if(iniciaCon(palabras[j], filtro))
						resultadoFilro.push_back(alumnos[i]);
				}
			}
		}
		else if('\n' == ch)
		{
			break;
		}
	}
}

#endif //! GRAFICOS_HPP