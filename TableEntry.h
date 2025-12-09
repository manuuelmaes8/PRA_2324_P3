#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <iostream>

using namespace std;

template <typename V>
class TableEntry {
    public:
        string key; // La clave
        V value;    // El valor

        //constructor par clave-valor
        TableEntry(string key, V value) {
            this->key = key;
            this->value = value;
        }
        //Constructor SOLO CLAVE (para las busquedas)
        TableEntry(string key) {
            this->key = key;
        }

        TableEntry(){
            this->key = "";
        }

        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) { //significa: "pasame la entrada original (&) (no una copia), pero solo para mirar,no modificar(const)"
            return te1.key == te2.key;
        }

        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            return te1.key != te2.key;
        }

        friend ostream& operator<<(ostream &out, const TableEntry<V> &te) {
            out << "{" << te.key << " : " << te.value << "}";
            return out;
        }
    };

    #endif