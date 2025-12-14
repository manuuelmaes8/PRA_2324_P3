#ifndef BSTREEDICT_H
#define BSTREEDICT_H


#include <ostream>
#include <string>

#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

using namespace std;




template <typename V>

class BSTreeDict: public Dict <V> {

    private:

    BSTree<TableEntry<V>>* tree;



    public:

    BSTreeDict(){
        tree = new BSTree<TableEntry<V>>;
    }

    ~BSTreeDict(){
        delete tree;
    }

    void insert(string key, V value) override{

        TableEntry<V> entrada(key,value);
        tree->insert(entrada);

    }

    V search(string key) override{

        TableEntry<V> temp(key);
        TableEntry<V> resultado = tree->search(temp);

        return resultado.value;

    }

    V remove(string key) override{

        TableEntry<V> temp(key);

        V valor = tree->search(temp).value;

        tree->remove(temp);

        return valor;

    }


    int entries() override {
        return tree->size();
    }

    V operator[](string key){
        return search(key);
    }

    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){

        out << *(bs.tree);
        return out;
    }
};
#endif