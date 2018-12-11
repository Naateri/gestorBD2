#ifndef AVLTREE_H
#define AVLTREE_H

#include <fstream>
#include "AVLnode.h"

template <class T>
class AVLtree {
public:
    AVLtree(std::string mmi, std::string mmc, std::string mmt);
    ~AVLtree(void);
	AVLnode<T> *root;

    std::string m_name_index;
    std::string m_name_col;
    std::string m_name_table;
    bool insert(T key, std::string st);
    void deleteKey(const T key);
    void printBalance();
    void inOrder() ;    
    void writeFile                  (std::ofstream& file);
    std::vector< std::string > find (T tem);
	AVLnode<T>* build_from_vec(std::vector<std::string> values, AVLnode<T>*& cur);

private:
 
    AVLnode<T>* rotateLeft          ( AVLnode<T> *a );
    AVLnode<T>* rotateRight         ( AVLnode<T> *a );
    AVLnode<T>* rotateLeftThenRight ( AVLnode<T> *n );
    AVLnode<T>* rotateRightThenLeft ( AVLnode<T> *n );
    void rebalance                  ( AVLnode<T> *n );
    int height                      ( AVLnode<T> *n );
    void setBalance                 ( AVLnode<T> *n );
    void printBalance               ( AVLnode<T> *n );
    void clearNode                  ( AVLnode<T> *n );
    void inOrder                    ( AVLnode<T> *n );
    void writeFile                  (std::ofstream& file, AVLnode<T> *n);
    std::vector< std::string > find (T tem, AVLnode<T> *n);
};

#endif
