#ifndef AVLNODE_H
#define AVLNODE_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/* AVL node */
template <class T>
class AVLnode {
public:
    T key;
    int balance;
    std::vector< std::string > m_str;
    AVLnode *left, *right, *parent;
 	

    AVLnode(T k, std::string st, AVLnode *p) : key(k), balance(0), parent(p),
                        left(NULL), right(NULL) { m_str.push_back(st); }
 
    ~AVLnode() {
        delete left;
        delete right;
    }
};
 
 #endif