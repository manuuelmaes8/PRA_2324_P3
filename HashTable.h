#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../../practica1/PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;

        ListLinked<TableEntry<V>>* table;
        
        int h(string key){
            int suma = 0;
            for(int i = 0; i < key.length(); i++){
                char c = key.at(i); //el metodo at(i) de std::string permite obtener el carácter situado en la posición i de un string
                suma = suma + int(c); //la función int(c) permite obtener el valor ASCII numérico del carácter c.
            }
            
            return suma % max;

        }


    public:

    HashTable(int size){
        n = 0;
        max = size;
        table = new ListLinked<TableEntry<V>>[size];
    }

    ~HashTable(){
        delete[] table;
    }

    int capacity(){
        return max;
    }

    void insert(string key, V value) override {

        TableEntry<V> entradaTemp(key);
        int cubeta = h(key);

        if(table[cubeta].search(entradaTemp) != -1){ // -1 signific q no esta
            throw runtime_error("La clave ya existe");
        } else {
            
            TableEntry<V> nuevaEntrada(key,value);
            table[cubeta].append(nuevaEntrada);
            n++;

        }
    }

    V search(string key) override{
        
        TableEntry<V> entradaTemp(key);
        int cubeta = h(key);

        int posicion = table[cubeta].search(entradaTemp);

        if (posicion == -1){
            throw runtime_error("No existe esta clave");
        } else {
            return table[cubeta].get(posicion).value;
        }
    }

    V remove(string key) override{
        TableEntry<V> entradaTemp(key);
        int cubeta = h(key);

        int posicion = table[cubeta].search(entradaTemp);

        if (posicion == -1) {
            throw runtime_error("Key '" + key + "' not found!");
            } else {
                V valor = table[cubeta].get(posicion).value;

                table[cubeta].remove(posicion);
                n--;
                return valor;
            }

    }

    // --- NUMERO DE ENTRADAS ---
    int entries() override {
        return n;
    }

    // --- SOBRECARGA OPERADOR [] ---
    // Permite hacer: diccionario["Uno"]
    V operator[](string key) {
        // Reutilizamos la funcion search que ya hemos programado
        return search(key);
    }

    // Sobrecarga operador << (Imprimir tabla completa)
    friend ostream& operator<<(ostream &out, const HashTable<V> &th) {
        out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << endl;
         out << "==============" << endl << endl;

        for (int i = 0; i < th.max; i++) {
            out << "== Cubeta " << i << " ==" << endl << endl;
            // Aquí imprimimos la lista entera directamente
            out << "List => " << th.table[i] << endl << endl;
        }
        return out;
    }
};

#endif