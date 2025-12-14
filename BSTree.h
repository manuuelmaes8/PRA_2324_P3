#ifndef BSTREE_H
#define BSTREE_H

#include "BSNode.h"
#include <ostream>
#include <stdexcept>

using namespace std;

template <typename T>

class BSTree {

    private:

    int nelem;
    BSNode<T>* root;

    BSNode<T>* search(BSNode<T>* n, T e) const{

        if (n==nullptr){

            throw runtime_error("Element not found");

        } else if(e < n->elem){

            return search(n->left, e);

        } else if(e > n->elem){

            return search(n->right, e);
        } else{

            return n;

        }

    }

    BSNode<T>* insert(BSNode<T>* n, T e){

        if( n == nullptr){

            return new BSNode<T>(e);

        } else if (n->elem == e){

            throw runtime_error("Elemento duplicado");

        } else if( n->elem < e){
            
            n->right = insert(n->right,e);

        } else{

            n->left = insert(n->left, e);
        }

        return n;
    }

    void print_inorder(ostream &out, BSNode<T>* n) const{
        if ( n == nullptr){return;}
        else { 
            
            print_inorder(out,n->left);

            out << n->elem << " ";

            print_inorder(out,n->right);

        }

    }

    T max(BSNode<T>* n) const{

        if (n==nullptr){
            
            throw runtime_error("Element not found");

        } else if(n->right != nullptr){

            return max(n->right);

        } else if(n->right == nullptr){

            return n->elem;

        }
    }

    BSNode<T>* remove_max(BSNode<T>* n){

        if(n->right==nullptr){

            BSNode<T>* izquierda = n->left;
            delete n;
            return izquierda;
        } else {

            n->right = remove_max(n->right);
            return n;
        }
    }

    BSNode<T>* remove(BSNode<T>* n, T e){
        if(n==nullptr){ throw runtime_error("not found");}
        
        if(e < n->elem){
            
            n->left = remove(n->left, e);

        }else if(e > n->elem){
            
            n->right = remove(n->right, e);
        }

        if(n->left != nullptr && n->right != nullptr){

            n->elem = max(n->left);
            n->left = remove_max(n->left);

        } else {


            BSNode<T>* result = (n->left != nullptr) ? n->left : n->right;
            delete n;
            return result;

        }
        return n;
    }

    void delete_cascade(BSNode<T>* n){

        if(n == nullptr){ return;}
        delete_cascade(n->left);
        delete_cascade(n->right);
        delete n;
    }


    public:

    BSTree(){
    
        nelem = 0;
        root = nullptr;
    }

    int size() const{

        return nelem;

    }

    T search(T e) const{

        return search(root, e)->elem;
    
    }

    T operator[](T e) const{

        return search(e);


    }

    void insert(T e) {

        root = insert(root, e);
        nelem++;    

    }

    friend ostream& operator<<(ostream &out, const BSTree<T> &bst){

        bst.print_inorder(out, bst.root);

        return out;
    }

    void remove(T e){

        root = remove(root, e);
        nelem--;

    }

    ~BSTree(){
        delete_cascada(root);
    }



    
};

#endif