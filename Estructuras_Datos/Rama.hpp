#ifndef RAMA_HPP
#define RAMA_HPP

template <typename T>
struct Rama
{
    T valor;
    Rama<T>* izquierda;
    Rama<T>* derecha;
    Rama(T _valor, Rama<T>* _izquierda = nullptr, Rama<T>* _derecha = nullptr)
    {
        valor = _valor;
        izquierda = _izquierda;
        derecha = _derecha;
    }
};


#endif // !RAMA_HPP