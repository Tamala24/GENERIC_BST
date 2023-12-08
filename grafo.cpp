#include <iostream>

template<typename T>
class Nodo {
	public:
	T data; 
	Nodo* d; // Nodo de la derecha
	Nodo* i; // Nodo de la izquierda
	Nodo(T d) : d(nullptr), i(nullptr) {
		data = d;
	}
	~Nodo() {
		//delete[] d;
		//delete[] i;
		delete this;
	}
};

template<typename T>
class Grafo {
	public:
	Nodo<T>* raiz;
	int size;
	Grafo(T d) {
		raiz = new Nodo<T>(d);
		size = 1;
	} 
	/*void insert(T d, Nodo<T>* k) {
		if(k == nullptr) {
			k = new Nodo<T>(d);
		} else if(d > (k->data)) {
			insert(d, k->d);
		} else
			insert(d, k->i);
		size++;
	}*/ // Insertamos mayores a la derecha y menores a la izquierda
	Nodo<T>* insert(T d, Nodo<T>* k) {
		if(k == nullptr) {	
			size++;
			return new Nodo<T>(d);
		} else if(d > (k->data)) {
			k->d = insert(d, k->d);
		} else
			k->i = insert(d, k->i);	
		return k;
	} // Insertamos mayores a la derecha y menores a la izquierda

	Nodo<T>* search(T d, Nodo<T>* k) {
		if(k == nullptr) {
			return nullptr;
		} else if(d == (k->data)) {
			return k;
		} else if(d > (k->data)) {
			return search(d, k->d);
		} else
			return search(d, k->i);
	} // Buscamos en funcion de la insercion d->mayor i->menor
	Nodo<T>* max(Nodo<T>* k) {	
		if((k->d) != nullptr) {
			max(k->d);	
		} else
			return k;	
	}
	Nodo<T>* min(Nodo<T>* k) {	
		if((k->i) != nullptr) {
			min(k->i);	
		} else
			return k;	
	}
	void preorden(Nodo<T>* k) {
		if(k != nullptr) {
			preorden(k->i);
			preorden(k->d);
			std::cout << k->data << " ";
		}	
	}
	void postorden(Nodo<T>* k) {
		if(k != nullptr) {
			postorden(k->d);
			postorden(k->i);
			std::cout << k->data << " ";
		}	
	}
	void inorden(Nodo<T>* k) {
		if(k != nullptr) {
			inorden(k->i);
			std::cout << k->data << " ";
			inorden(k->d);
		}	
	}
};

int main() {
	char d;
	std::cin >> d;
	Grafo g(d);
	std::cin >> d;
	g.insert(d, g.raiz);	
	std::cin >> d;
	g.insert(d, g.raiz);	
	std::cin >> d;
	g.insert(d, g.raiz);	
	std::cin >> d;
	g.insert(d, g.raiz);	
	std::cin >> d;
	g.insert(d, g.raiz);	
	std::cout << "Preorden: ";
	g.preorden(g.raiz); std::cout << std::endl;
	std::cout << "Postorden: ";
	g.postorden(g.raiz); std::cout << std::endl;
	std::cout << "Inorden: ";
	g.inorden(g.raiz); std::cout << std::endl;
	std::cout << "Tamaño del gráfo: " << g.size << std::endl;
	std::cout << "Buscar: " << g.search(d, g.raiz)->data << std::endl;
	return 0;
}

