#include <curses.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename V>
class GrafoDirigido 
{
    // Vector de listas de adyacencia
    vector<vector<int>> listaAdyacencia;

    // Vector para almacenar los valores de cada vértice
    vector<V> valores;

public:
    GrafoDirigido() {}

    void agregarVertice(V valor) 
    {
        listaAdyacencia.push_back(vector<int>());
        valores.push_back(valor);
    }

    void modificarVertice(int vertice, V nuevoValor)
    {
        // Verificar que fuente y destino son válidos
        if (vertice >= 0 && vertice < valores.size())
            valores[vertice] = nuevoValor;
        else
        {
            printw("Error: Vértice no válido.\n");
            refresh();
        }
    }

    void agregarArista(int fuente, int destino)
    {
        // Verificar que fuente y destino son válidos
        if (fuente >= 0 && fuente < listaAdyacencia.size() && 
            destino >= 0 && destino < listaAdyacencia.size())
            listaAdyacencia[fuente].push_back(destino);
        else
        {
            printw("Error: Vértices no válidos.\n");
            refresh();
        }
    }

    void eliminarArista(int fuente, int destino)
    {
        // Verificar que fuente y destino son válidos
        if (fuente >= 0 && fuente < listaAdyacencia.size() && 
            destino >= 0 && destino < listaAdyacencia.size())
        {
            // Buscar la arista y eliminarla
            auto it = std::find(listaAdyacencia[fuente].begin(), listaAdyacencia[fuente].end(), destino);
            if (it != listaAdyacencia[fuente].end())
                listaAdyacencia[fuente].erase(it);
            else
            {
                printw("Error: La arista especificada no existe.\n");
                refresh();
            }
        }
        else
        {
            printw("Error: Vértices no válidos.\n");
            refresh();
        }
    }

    // Método para obtener el valor de un vértice dado
    V obtenerValor(int vertice) 
    {
        // Verificar que el vértice es válido
        if (vertice >= 0 && vertice < valores.size())
            return valores[vertice];
        else 
        {
            printw("Error: Vértice no válido.\n");
            refresh();
            return V();
        }
    }

    vector<string> matrizAdyacencia() 
    {
        vector<string> res;
        string str;
        int _v = listaAdyacencia.size();
    
        vector<vector<int>> matrizAdy(_v, vector<int>(_v, 0));

        for (int i = 0; i < _v; ++i) 
        {
            for (int j : listaAdyacencia[i])
                matrizAdy[i][j] = 1; 
        }

        // Mostrar la matriz de adyacencia
        res.push_back(string("Matriz de adyacencia del grafo dirigido:\n"));
        for (int i = 0; i < _v; ++i) 
        {
            for (int j = 0; j < _v; ++j) 
            {
                str += to_string(matrizAdy[i][j]);
                str += " ";
            }
            str += "\n";
            res.push_back(str);
            str.clear();
        }
        return res;
    }

    // Método para imprimir el grafo dirigido con los valores de los vértices
    vector<string> toStrings()
    {
        vector<string> strings;
        int _v = listaAdyacencia.size(); // Obtener el número de vértices
        

        strings.push_back(string("Grafos:\n"));
        for (int i = 0; i < _v; ++i) 
        {
            ostringstream ss;
            ss << "Vértice " << i << " (Valor: " << valores[i] << ") tiene aristas dirigidas a:";

            for (int j : listaAdyacencia[i])
                ss << " -> Vértice " << j << " (Valor: " << valores[j] << ")";
            strings.push_back(ss.str());
        }
        return strings;
    }
};