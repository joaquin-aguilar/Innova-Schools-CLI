#ifndef FILTROS_HPP
#define FILTROS_HPP

#include <string>
#include <sstream>
#include <vector>


bool iniciaCon(const std::string& objetivo, const std::string& filtro) 
{
    if (objetivo.length() < filtro.length()) 
        return false;

    // Iterar sobre las letras del filtro
    for (int i = 0; i < filtro.length(); ++i) 
        // Verificar si cada caracter del filtro coincide
        if (objetivo[i] != filtro[i])
            return false;

    return true;
}

std::vector<std::string> dividirPalabras(const std::string& frase) 
{
    std::vector<std::string> palabras;
    std::stringstream ss(frase); // Utilizamos stringstream para dividir por espacios
    
    std::string palabra;
    while (ss >> palabra) 
        palabras.push_back(palabra);

    return palabras;
}

auto obtenerAlumno(const std::vector<std::string>& alumnos, int indice)
{
    std::string nombre;
    if(alumnos.size() < indice || indice < 0)
        return std::string("");
    
    std::vector<std::string> palabras = dividirPalabras(alumnos[indice]);
    nombre += palabras[3];
    nombre += " ";
    nombre += palabras[4];
    return nombre;
};

auto obtenerIndices = [](const std::string& frase, const std::string& objetivo) 
{
    std::vector<int> indices;
    std::vector<std::string> palabras = dividirPalabras(frase);
    for(int i = 0; i < palabras.size(); i++)
    {
        if(palabras[i] == objetivo)
            indices.push_back(i);
    }
    return indices;
};

#endif // !FILTROS_HPP