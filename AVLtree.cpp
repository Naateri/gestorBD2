
#include "AVLtree.h"
#include <sstream>

int stringToInt2(std::string a){
	int ret;
	std::stringstream convi(a);
	convi >> ret;
	return ret;
}

/* AVL class definition */

template <class T>
void AVLtree<T>::rebalance(AVLnode<T> *n) {
    setBalance(n);
 
    if (n->balance == -2) {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2) {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }
 
    if (n->parent != NULL) {
        rebalance(n->parent);
    }
    else {
        root = n;
    }
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateLeft(AVLnode<T> *a) {
    AVLnode<T> *b = a->right;
    b->parent = a->parent;
    a->right = b->left;
 
    if (a->right != NULL)
        a->right->parent = a;
 
    b->left = a;
    a->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateRight(AVLnode<T> *a) {
    AVLnode<T> *b = a->left;
    b->parent = a->parent;
    a->left = b->right;
 
    if (a->left != NULL)
        a->left->parent = a;
 
    b->right = a;
    a->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == a) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(a);
    setBalance(b);
    return b;
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateLeftThenRight(AVLnode<T> *n) {
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}
 
template <class T>
AVLnode<T>* AVLtree<T>::rotateRightThenLeft(AVLnode<T> *n) {
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}
 
template <class T>
int AVLtree<T>::height(AVLnode<T> *n) {
    if (n == NULL)
        return -1;
    return 1 + std::max(height(n->left), height(n->right));
}
 
template <class T>
void AVLtree<T>::setBalance(AVLnode<T> *n) {
    n->balance = height(n->right) - height(n->left);
}
 
template <class T>
void AVLtree<T>::printBalance(AVLnode<T> *n) {
    if (n != NULL) {
        printBalance(n->left);
        std::cout << n->balance << " ";
        printBalance(n->right);
    }
}
 
template <class T>
AVLtree<T>::AVLtree(std::string mmi, std::string mmc, std::string mmt) : root(NULL) { 
    m_name_index = mmi;
    m_name_col = mmc; 
    m_name_table = mmt;
	root = 0;
}
 
template <class T>
AVLtree<T>::~AVLtree(void) {
    delete root;
}
 
template <class T>
bool AVLtree<T>::insert(T key, std::string st) {
    if (root == NULL) {
        root = new AVLnode<T>(key, st, NULL);
    }
    else {
        AVLnode<T>
            *n = root,
            *parent;
 
        while (true) {
            if (n->key == key)
            {
                n->m_str.push_back(st);
                return false;
            }
 
            parent = n;
 
            bool goLeft = n->key > key;
            n = goLeft ? n->left : n->right;
 
            if (n == NULL) {
                if (goLeft) {
                    parent->left = new AVLnode<T>(key, st, parent);
                }
                else {
                    parent->right = new AVLnode<T>(key, st, parent);
                }
 
                rebalance(parent);
                break;
            }
        }
    }
	if (stringToInt2(key) % 10000 == 0) std::cout << "Value " << key << " inserted.\n";
    return true;
}
 
template <class T>
void AVLtree<T>::deleteKey(const T delKey) {
    if (root == NULL)
        return;
 
    AVLnode<T>
        *n       = root,
        *parent  = root,
        *delNode = NULL,
        *child   = root;
 
    while (child != NULL) {
        parent = n;
        n = child;
        child = delKey >= n->key ? n->right : n->left;
        if (delKey == n->key)
            delNode = n;
    }
 
    if (delNode != NULL) {
        delNode->key = n->key;
 
        child = n->left != NULL ? n->left : n->right;
 
        if (root->key == delKey) {
            root = child;
        }
        else {
            if (parent->left == n) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
 
            rebalance(parent);
        }
    }
}
 
template <class T>
void AVLtree<T>::printBalance() {
    printBalance(root);
    std::cout << std::endl;
}

template <class T>
void AVLtree<T>::inOrder() 
{ 
    inOrder(root);
    std::cout << std::endl;
} 

template <class T>
void AVLtree<T>::inOrder(AVLnode<T> *n) 
{ 
    if(n != NULL) 
    { 
        inOrder(n->left); 
        std::cout << n->key << " " <<n->m_str.size() << std::endl; 
        inOrder(n->right); 
    } 
} 

template <class T>
void AVLtree<T>::writeFile(std::ofstream& file)
{
    file << m_name_table << ',' << m_name_col << '\n';
    writeFile(file, root);
}

template <class T>
void AVLtree<T>::writeFile(std::ofstream& file, AVLnode<T> *n)
{
    if(n != NULL) 
    { 
        writeFile(file, n->left); 
        //file << n->key << ',' << n->m_str << '\n'; 
        file << n->key;
        for (int i = 0; i < n->m_str.size(); i++)
        {
            file << ';' << n->m_str[i];
        }
        file << '\n'; 
        writeFile(file, n->right); 
    } 
}

template <class T>
std::vector< std::string > AVLtree<T>::find(T tem) {
    //std::cout << "root value: " << this->root->key << '\n';
    return find(tem, this->root);
}

template <class T>
std::vector< std::string > AVLtree<T>::find(T tem, AVLnode<T> *n) {
    std::vector< std::string > r;
    r.push_back("-1"); //change if wanting to cheat because stupid crap fails with small id's for some reason
	//std::cout << "cur key: " << n->key << ", looking for: " << tem << std::endl;
    while (n != NULL) {
		//std::cout << "cur key: " << n->key << ", looking for: " << tem << std::endl;
        //std::cout << n->key << std::endl;
        if (n->key == tem) {
            return n->m_str;
        }
        else if(n->key > tem) {
            n = n->left;
        }
        else
            n = n->right;
    }
	//std::cout << "column: " << r.at(0);
    return r;
}

template <class T>
AVLnode<T>* AVLtree<T>::build_from_vec(std::vector<std::string> values, AVLnode<T>*& cur){
	//std::cout << "values size: " << values.size() << std::endl;
	if (values.size() <= 0){
	//	std::cout << "null\n";
		return NULL;
	}
	if (values.size() == 1){
		return (new AVLnode<T>(values.at(0), values.at(0), 0));
	}
	//std::vector<std::string> left_values, right_values;
	
	int mid = values.size() / 2;
	//int mid = (values.size()) >> 1;
	cur = new AVLnode<T>(values.at(mid),values.at(mid), 0);
	
	//std::copy(values.begin(), values.begin() + mid, std::back_inserter(left_values));
	/*for (int i = 0; i < mid; i++){
		left_values.push_back(values.at(i));
	}*/
	
	std::vector<std::string> left_values(values.begin(), values.begin() + mid);
	cur->left = build_from_vec(left_values, cur->left);
	
	/*for (int i = mid + 1; i < values.size(); i++){
		right_values.push_back(values.at(i));
	}*/
	
	//std::copy(values.begin() + mid + 1, values.end(), std::back_inserter(right_values));
	std::vector<std::string> right_values(values.begin() + mid + 1, values.end());
	cur->right = build_from_vec(right_values, cur->right);
	
	return cur;
	
	return root; 
}

template <class T>
AVLnode<T>* AVLtree<T>::build_from_vec2(std::vector<std::string> values, int start, int end){
	if (start > end) return NULL;
	AVLnode<T>* cur;
	int mid = (start + end)/2;
	if (start == 0 && end == values.size() - 1){
		root = cur;
	}
	if (mid%10000 == 0) std::cout << "cur_mid: " << mid << std::endl;
	cur = new AVLnode<T>(values.at(mid), values.at(mid), 0);
	
	cur->left = build_from_vec2(values, start, mid-1);
	
	cur->right = build_from_vec2(values, mid+1, end);
	
	return cur;
}

template class AVLtree<std::string>;

template <class T>
void AVLtree<T>::printPreorder(AVLnode<T>* cur){
	if (cur){
		std::cout << "current node: " << cur->key << ' ';
		int a;
		std::cin >> a;
		if (cur->left) std::cout << "left: " << cur->left->key << ' ';
		if (cur->right) std::cout << "right: " << cur->right->key << ' ';
		printPreorder(cur->left);
		printPreorder(cur->right);
	}
}
