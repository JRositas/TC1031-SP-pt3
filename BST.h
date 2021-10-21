/*
El presente programa tiene el propósito que con las diversas funciones nos van a regresar un entero con el maxima anchura BST de enteros, así como regresar el ancestro más cercano de dos datos, de la misma manera que se crea un copy constructor de la clase BST que esta basada en un BST que se llega como entrada, y por ultimo se haría la comparación de dos BST, sobrecargando el operador "==".
*/


// Matrícula: A00829821
// Nombre: Ángela Felicia Guajardo Olveda
// Fecha de creación: 16 Octubre 2021
#include "NodeT.h"

class BST
{
	public:
		BST();
		~BST();
		void add(dataCS data);
		void print(int tipo);	

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
void BST::add(dataCS data);{
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
		// if (parent->getData() > data){
		// 	parent->setLeft(new NodeT(data));
		// }
		// else{
		// 	parent->setRight(new NodeT(data));
		// }
		(parent->getData() > data) ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}



// Tipo:
// 1 : InOrdenC
void BST::print(int tipo){
	switch (tipo){
		case 1: inOrdenC(root);
				break;
	}
	cout << endl;
}


// Complejidad: O(n)
void BST::inOrdenC(NodeT *r){
	if (r != nullptr){
		inOrdenC(r->getRight());
		cout << r->getData() << " ";
		inOrdenC(r->getLeft());
	}
}


