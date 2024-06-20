#ifndef COLA_HPP
#define COLA_HPP

#include <string>
#include "Nodo.hpp"

template<class T>
class Cola
{
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    Cola() 
    {
        primero = nullptr;
        ultimo = nullptr;
    }

    ~Cola() 
    {
        while (!estaVacia())
        {
            pop();
        }
    }

    int size() 
    {
        int indice = 0;
        if (estaVacia())
            return indice;

        Nodo<T>* actual = primero;
        while (actual != nullptr)
        {
            indice++;
            actual = actual->siguiente;
        }

        return indice;
    }

    bool estaVacia() 
    {
        return primero == nullptr;
    }

    // Big O #3
    void push(T dato) 
    { 
        Nodo<T>* nuevo = new Nodo<T>(dato); 

        if (ultimo == nullptr) 
        {
            ultimo = nuevo; 
            primero = nuevo; 
        }
        else
        {
            ultimo->siguiente = nuevo; 
            ultimo = nuevo; 
        }
    }

    T pop() 
    {
        if (estaVacia())
            throw std::out_of_range("La cola est� vacia");

        Nodo<T>* actual = primero;
        T dato = actual->dato;

        primero = primero->siguiente;
        delete actual;

        if (primero == nullptr)
            ultimo = nullptr;

        return dato;
    }

    T& front() 
    {
        if (primero == nullptr)
            throw std::out_of_range("No existe el primer elemento");

        return primero->dato;
    }
    T& back() 
    {
        if (ultimo == nullptr)
            throw std::out_of_range("No existe el ultimo elemento");

        return ultimo->dato;
    }
    Cola<T> copiarCola() 
    {
        Cola<T> nuevaCola;

        Nodo<T>* actual = primero;
        while (actual != nullptr)
        {
            nuevaCola.push(actual->dato);
            actual = actual->siguiente;
        }

        return nuevaCola;
    }
};
#endif // !COLA_HPP