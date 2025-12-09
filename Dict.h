#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept>

template <typename V> 
class Dict {
    public:
        // Inserta el par key->value. Lanza excepción si ya existe.
        virtual void insert(std::string key, V value) = 0;

        // Busca el valor asociado a key. Lanza excepción si no se encuentra.
        virtual V search(std::string key) = 0;

        // Elimina el par key->value. Lanza excepción si no se encuentra.
        virtual V remove(std::string key) = 0;

        // Devuelve el número de elementos en el diccionario.
        virtual int entries() = 0;

        // Destructor virtual: Importante en clases abstractas para evitar fugas de memoria
        virtual ~Dict() {}
};

#endif
