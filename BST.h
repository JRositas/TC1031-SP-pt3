#include "NodeT.h"

class BST{
	public:
		BST();
		~BST();

		void add(dataCS data);
		void print();

	private:
		NodeT *root;
		void inOrdenC(NodeT *r);
		void destruye_Helper(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye_Helper(root);
}

void BST::destruye_Helper(NodeT *r){
	if (r != nullptr){
		destruye_Helper(r->getLeft());
		destruye_Helper(r->getRight());
		delete r;
	}
}

// Complejidad: O(height)
void BST::add(dataCS data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		while (curr != nullptr){
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		(parent->getData() > data) ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}


// Complejidad: O(n)
void BST::print(){
	inOrdenC(root);
	cout << endl;
}

// Imprime los nodos desde el valor mas grande al menor
// Complejidad: O(n)
void BST::inOrdenC(NodeT *r){
	if (r != nullptr){
		inOrdenC(r->getRight());
		cout << r->getData();
		inOrdenC(r->getLeft());
	}
}
