#ifndef GRAFICOS_HPP
#define GRAFICOS_HPP


#include <iostream>
#include <functional>
#include <curses.h>
#include <string>
#include <vector>
#include "./Filtros.hpp"
#include "./Input.hpp"

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

void menu() 
{
	printw("\n\n\n");
	printw("BIENVENIDO A INNOVA SCHOOLS\n\n\n");
	printw("1.  Generar nuevo alumno\n");
	printw("2.  Generar nuevo alumno deportista\n");
	printw("3.  Generar nuevo alumno destacado\n");
	printw("4.  Mostrar alumnos (lista)\n");
	printw("5.  Mostrar alumnos destacados (cola)\n");
	printw("6.  Mostrar alumnos deportistas (pila)\n");
	printw("7.  Mostrar cantidad de alumnos registrados\n");
	printw("8.  Mostrar hash con administradores\n");
	printw("9.  Mostrar llaves de Hash\n");
    printw("10. Imprimir grafos y matriz de adyacencia\n");
    printw("11. Salir\n");
	printw("Tu opcion: ");
	refresh();
}

void imprimirContenido(const std::vector<std::string>& datos, int inicio) 
{
    clear();

	// Obtener tamaño de la pantalla
    int max_y, max_x; 
    getmaxyx(stdscr, max_y, max_x);
	// posicionar el cursor e imprimir cada linea que permita el tamaño de la consola
    for (int i = inicio, y = 0; i < std::min((int)datos.size(), inicio + (max_y - 1)); ++i, ++y) 
	{
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
void imprimirGrafos(const std::vector<std::string>& grafos) 
{
    int inicio = 0;
    while (true)
    {
        // Obtener tamaño de la pantalla
        int max_y, max_x; 
        getmaxyx(stdscr, max_y, max_x); 
        std::string filtro = "Vértice";
        std::string relacionados = "1";
        std::string noRelacionados = "0";

        // posicionar el cursor e imprimir cada línea que permita el tamaño de la consola
        for (int i = inicio, y = 0; i < std::min((int)grafos.size(), inicio + (max_y - 1)); ++i, ++y) 
        {
            std::vector<std::string> palabras = dividirPalabras(grafos[i]);
            std::vector<int> indicesVertice = obtenerIndices(grafos[i], filtro);
            std::vector<int> indicesRelacionados = obtenerIndices(grafos[i], relacionados);
            std::vector<int> indicesNoRelacionados = obtenerIndices(grafos[i], noRelacionados);
            move(y, 0);
            
            // Imprimir palabras y aplicar color según las condiciones
            for (int j = 0; j < palabras.size(); ++j)
            {
                bool coloreado = false;

                // Buscar y colorear "0" en rojo
                for (int k = 0; k < indicesNoRelacionados.size(); ++k)
                {
                    if (indicesNoRelacionados[k] == j)
                    {
                        attron(COLOR_PAIR(1)); 
                        printw("%s ", palabras[j].c_str());
                        attroff(COLOR_PAIR(1));
                        coloreado = true;
                        break;
                    }
                }

                // Buscar y colorear "1" en verde
                if (!coloreado)
                {
                    for (int k = 0; k < indicesRelacionados.size(); ++k)
                    {
                        if (indicesRelacionados[k] == j)
                        {
                            attron(COLOR_PAIR(2)); 
                            printw("%s ", palabras[j].c_str());
                            attroff(COLOR_PAIR(2));
                            coloreado = true;
                            break;
                        }
                    }
                }

                // Buscar y colorear "Vértice" y su indice en azul
                if (!coloreado)
                {
                    for (int k = 0; k < indicesVertice.size(); ++k)
                    {
                        if (indicesVertice[k] == j && j + 1 < palabras.size())
                        {
                            attron(COLOR_PAIR(3)); 
                            printw("%s %s ", palabras[j].c_str(), palabras[j + 1].c_str());
                            attroff(COLOR_PAIR(3));
                            coloreado = true;
                            // Saltar la siguiente palabra para evitar duplicados
                            ++j;
                            break;
                        }
                    }
                }

                // Si ninguna condición se cumple, imprimir normalmente
                if (!coloreado)
                {
                    printw("%s ", palabras[j].c_str()); 
                }
            }
            printw("\n");
        }

        // Mostrar instrucciones de navegación
        move(max_y - 1, 0); // Mover al final de la pantalla
        attron(COLOR_PAIR(4));
        printw("Usa las flechas para navegar. 'Intro' para salir.");
        attroff(COLOR_PAIR(4));
        refresh();

        // Obtener entrada del usuario
        int ch = getch();
        if (ch == KEY_UP && inicio > 0)
            inicio--;
        else if (ch == KEY_DOWN && inicio < (int)(grafos.size()) - max_y + 1)
            inicio++;
        else if (ch == '\n')
            break;
    }

    clear(); // Limpiar pantalla al salir del bucle
}
void menuGrafos()
{
	printw("1. mostrar grafos\n");
	printw("2. añadir vértice\n");
	printw("3. modificar vértice\n");
	printw("4. añadir arista\n");
	printw("5. eliminar arista\n");
	printw("Salir pulsando intro\n");
	refresh();
}

#endif //! GRAFICOS_HPP