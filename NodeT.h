using namespace std;

struct dataCS { // Struct que guarda el nombre y la cantidad de los nodos
	int cant;
	string nombre;
	dataCS(){
		cant = 0;
		nombre = "AAA";
	}
	dataCS(int cant, string nombre){
		this->cant = cant;
		this->nombre = nombre;
	}
	bool operator==(const dataCS &otra){ // Comparar para igualdad
		return this->cant == otra.cant && this->nombre == otra.nombre;
	}
	bool operator>(const dataCS &otra){ // Operador mayor que, primero compara cantidad, si es igual, compara nombre
		if(this->cant == otra.cant){
			return this->nombre.compare(otra.nombre) < 0;
		}
		return this->cant > otra.cant;
	}
	void operator=(const dataCS &otra){ // Operador de asignación
		this->cant = otra.cant;
		this->nombre = otra.nombre;
	}
	friend ostream& operator<<(ostream& os, const dataCS &d);
};

ostream& operator<<(ostream& os, const dataCS &d){ // Impresion del dato
	os << d.nombre << " " << d.cant << endl;
}

class NodeT{
	public:
		NodeT(dataCS data);
		NodeT(dataCS data, NodeT *left, NodeT *right);
		dataCS getData();
		NodeT* getLeft();
		NodeT* getRight();
		void setData(dataCS data);
		void setLeft(NodeT *left);
		void setRight(NodeT *right);
	private:
		dataCS data;
		NodeT *left;
		NodeT *right;
};

NodeT::NodeT(dataCS data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

NodeT::NodeT(dataCS data, NodeT *left, NodeT *right){
	this->data = data;
	this->left = left;
	this->right = right;
}

dataCS NodeT::getData(){
	return this->data;
}

NodeT* NodeT::getLeft(){
	return this->left;
}

NodeT* NodeT::getRight(){
	return this->right;
}

void NodeT::setData(dataCS data){
	this->data = data;
}

void NodeT::setLeft(NodeT *left){
	this->left = left;
}

void NodeT::setRight(NodeT *right){
	this->right = right;
}
