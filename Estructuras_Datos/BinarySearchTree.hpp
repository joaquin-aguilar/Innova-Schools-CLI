#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <vector>
#include <string>
#include "Rama.hpp"

template <typename T>
class BynarySearchTree
{
private:
    Rama<T>* raiz;
    int(* obtenerGrado)(T);
    std::string(* obtenerString)(T);
    void destruirRecursivamente(Rama<T>* nodo);
    void _inOrder(Rama<T>* nodo, std::vector<std::string>& salida);
    void _push(T dato, Rama<T>*& nodo);
    Rama<T>* minimoValor(Rama<T>* nodo);
    Rama<T>* buscarElemento(Rama<T>* nodo, T dato);
    Rama<T>* eliminarRecursivamente(Rama<T>* nodo, T valor);
    public:
    BynarySearchTree(int(*grado)(T), std::string(*str)(T));
    ~BynarySearchTree();
    void push(T dato);
    std::vector<std::string> inOrder();
    Rama<T>* buscarElemento(T dato);
    void eliminar(T elemento);
};

template <typename T>
BynarySearchTree<T>::BynarySearchTree(int(*grado)(T), std::string(*str)(T))
{
    obtenerString = str;
    obtenerGrado = grado;
    raiz = nullptr;
}

template <typename T>
BynarySearchTree<T>::~BynarySearchTree()
{
    destruirRecursivamente(raiz);
}

template <typename T>
void BynarySearchTree<T>::destruirRecursivamente(Rama<T>* nodo)
{
    if (nodo != nullptr)
    {
        destruirRecursivamente(nodo->izquierda);
        destruirRecursivamente(nodo->derecha);
        
        delete nodo;
    }
}

template <typename T>
void BynarySearchTree<T>::_push(T dato, Rama<T>*& nodo)
{
    if (nodo == nullptr)
    {
        nodo = new Rama<T>(dato);
        return;
    }
    if (obtenerGrado(nodo->valor) > dato)
    {
        _push(dato, nodo->izquierda);
    }
    else
    {
        _push(dato, nodo->derecha);
    }
}

template <typename T>
void BynarySearchTree<T>::push(T dato)
{
    _push(dato, raiz);
}

template <typename T>
void BynarySearchTree<T>::_inOrder(Rama<T>* nodo, std::vector<std::string>& salida)
{
    if (nodo != nullptr)
    {
        _inOrder(nodo->izquierda, salida);
        salida.push_back(obtenerString(nodo->valor));
        _inOrder(nodo->derecha, salida);
    }
}

template<typename T>
Rama<T>* BynarySearchTree<T>::buscarElemento(T valor)
{
    return buscarElemento(raiz, valor);
}

template <typename T>
std::vector<std::string> BynarySearchTree<T>::inOrder()
{
    std::vector<std::string> conversion;
    _inOrder(raiz, conversion);
    return conversion;
}



template <typename T>
void BynarySearchTree<T>::eliminar(T valor)
{
    raiz = eliminarRecursivamente(raiz, valor);
}

template <typename T>
Rama<T>* BynarySearchTree<T>::eliminarRecursivamente(Rama<T>* nodo, T valor)
{
    if (nodo == nullptr)
        return nodo;

    if (valor < nodo->valor)
        nodo->izquierda = eliminarRecursivamente(nodo->izquierda, valor);
    else if (valor > nodo->valor)
        nodo->derecha = eliminarRecursivamente(nodo->derecha, valor);
    else
    {
        if (nodo->izquierda == nullptr)
        {
            Rama<T>* temp = nodo->derecha;
            delete nodo;
            return temp;
        }
        else if (nodo->derecha == nullptr)
        {
            Rama<T>* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        Rama<T>* temp = minimoValor(nodo->derecha);
        nodo->valor = temp->valor;
        nodo->derecha = eliminarRecursivamente(nodo->derecha, temp->valor);
    }
    return nodo;
}

template<typename T>
Rama<T>* BynarySearchTree<T>::buscarElemento(Rama<T>* nodo, T valor) 
{
    if (nodo == nullptr || nodo->valor == valor) 
        return nodo;

    if (nodo->valor < valor)
        return buscarElemento(nodo->derecha, valor);

    return buscarElemento(nodo->izquierda, valor);
}

template <typename T>
Rama<T>* BynarySearchTree<T>::minimoValor(Rama<T>* nodo)
{
    Rama<T>* actual = nodo;
    while (actual->izquierda != nullptr)
        actual = actual->izquierda;
    return actual;
}
#endif // !BINARY_SEARCH_TREE_HPP