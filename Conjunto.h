// Conjunto por Ignacio Rueda
// (c) 2020

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class Conjunto {
private:
	std::vector<T> _elementos;
	
public:
	
	Conjunto(){};

	Conjunto(std::initializer_list<T> elementos) :
		_elementos(elementos.begin(), elementos.end()){};
	
	void agregar(T elemento);
	void extraer(T elemento);
	void escribe(std::ostream& o) const;
	
	bool incluye(Conjunto<T> otro) const;
	bool estaVacio() const;
	bool pertenece(T elemento) const;
	
	int nroElementos() const;
	
	Conjunto<T> unir(const Conjunto<T> &otro) const;
	Conjunto<T> intersectar(const Conjunto<T> &otro) const; 
	Conjunto<T> diferencia(const Conjunto<T> &otro) const;
	Conjunto<T> diferenciaSimetrica(const Conjunto<T> &otro) const;
	Conjunto<T> complemento(const Conjunto<T> &universo) const;

};

template <typename T>
void Conjunto<T>::agregar(T elemento) {
	
	if(!this->pertenece(elemento)){
		_elementos.push_back(elemento);
	}

}

template <typename T>
void Conjunto<T>::extraer(T elemento) {

	typename std::vector<T>::iterator it;
	
	for(it = _elementos.begin();
		it != _elementos.end();
		++it){
			if(elemento == *it){
				_elementos.erase(it);
				return;
			}
		}
	
}

template <typename T>
void Conjunto<T>::escribe(std::ostream& o) const {
	typename std::vector<T>::const_iterator it;
	
	for(it = _elementos.begin();
		it != _elementos.end();
		it++){
			
			if(it == _elementos.begin()) o << " { ";
			
			o << *it;
			
			// Si es el último elemento
			if((it != _elementos.end()) && (it + 1 == _elementos.end())){
				o << " }";
			} else {
				o << ", ";
			}
		}
}

template<typename T>
bool Conjunto<T>::incluye(Conjunto<T> otro) const {
	
	typename std::vector<T>::const_iterator it;
	
	for(it = otro._elementos.begin();
		it != otro._elementos.end();
		++it){
			if(!this->pertenece(*it)){
				return false;
			}
		}
	
	return true;
}

template <typename T>
bool Conjunto<T>::estaVacio() const {
	return _elementos.empty();
}

template<typename T>
int Conjunto<T>::nroElementos() const {
	return _elementos.size();
}

template <typename T>
bool Conjunto<T>::pertenece(T elemento) const {
	
	typename std::vector<T>::const_iterator it;
	
	for(it = _elementos.begin();
		it != _elementos.end();
		++it){
			if(*it == elemento){
				return true;
			}
		}
		
	return false;
}

template <typename T>
Conjunto<T> Conjunto<T>::unir(const Conjunto<T> &otro) const {
	
	Conjunto<T> nuevo;
	nuevo._elementos = this->_elementos;
	
	typename std::vector<T>::const_iterator it;
	
	for(it = otro._elementos.begin();
		it != otro._elementos.end();
		++it){
			if(!nuevo.pertenece(*it)){
				nuevo.agregar(*it);
			}
		}
		
	return nuevo;
	
}

template <typename T>
Conjunto<T> Conjunto<T>::intersectar(const Conjunto<T> &otro) const {
	
	Conjunto<T> nuevo;
	
	typename std::vector<T>::const_iterator it;
	
	for(it = otro._elementos.begin();
		it != otro._elementos.end();
		++it){
			if(this->pertenece(*it)){
				nuevo.agregar(*it);
			}
		}
		
	return nuevo;
	
}

template <typename T>
Conjunto<T> Conjunto<T>::diferencia(const Conjunto<T> &otro) const {
	
	Conjunto<T> nuevo;
	
	typename std::vector<T>::const_iterator it;
	
	for(it = _elementos.begin();
		it != _elementos.end();
		++it){
			if(!otro.pertenece(*it)){
				nuevo.agregar(*it);
			}
		}
	
	return nuevo;
}

template <typename T>
Conjunto<T> Conjunto<T>::diferenciaSimetrica(const Conjunto<T> &otro) const {
	
	Conjunto<T> interseccion = this->intersectar(otro);
	
	Conjunto<T> unido = this->unir(otro);
	
	Conjunto<T> nuevo = unido.diferencia(interseccion);
	
	return nuevo;
	
}

template <typename T>
Conjunto<T> Conjunto<T>::complemento(const Conjunto<T> &universo) const {
	
	Conjunto<T> nuevo = universo.diferencia(*this);
	return nuevo;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Conjunto<T>& obj) {

	obj.escribe(os);

	return os;
}

template <typename T>
bool operator==(Conjunto<T>& a, Conjunto<T>& b) {
	if( a.incluye(b) && b.incluye(a) ){
		return true;
	}
	return false;
}

#endif

