#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

using namespace std;



template <typename T>

class BSNode {
    public:

    //atributos del nodo

    T elem;
    BSNode<T>* left;
    BSNode<T>* right;

    //constructor

    BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr){

        this->elem = elem;
        this->left = left;
        this->right = right;
    }

    //sobrecarga operador <<

    friend ostream& operator<<(ostream &out, const BSNode<T> &bsn){

        out << bsn.elem;
        return out;
    }

};


#endif