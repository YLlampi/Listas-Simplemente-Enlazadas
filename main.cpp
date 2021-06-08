#include <iostream>
using namespace std;

template <class T>
class Lista;

template <class T>
class NodoLista;

template <class T>
ostream& operator<<(ostream &o, const Lista<T> &l){
    NodoLista<T> *q = l.primero;
	while(q){
		o<<q->info<<' ';
		q = q->liga;
	}
    return o;
}

template <class T>
class NodoLista{
	private:
		NodoLista<T> *liga;
		T info;
	public:
		NodoLista(){
			this->liga = NULL;
		}
		friend class Lista<T>;
		friend ostream& operator << <>(ostream &,const Lista<T> &);

};

template <class T>
class Lista{
	private:
		NodoLista<T> *primero;
	public:
		Lista(){
			this->primero = NULL;
		}

		void insertarInicio(T dato){
			NodoLista<T> *p = new NodoLista<T>();
			p->info = dato;
			p->liga = this->primero;
			this->primero = p;
		}

		void insertarFinal(T dato){
			NodoLista<T> *p = new NodoLista<T>(), *ultimo;
			p->info = dato;
			if(this->primero){
				ultimo = this->primero;
				while(ultimo->liga){
					ultimo = ultimo->liga;
				}
				ultimo->liga = p;
			}
			else{
				this->primero = p;
			}
		}

		int insertarAntesReferencia(T dato, T ref){
			NodoLista<T> *p, *ant, *q;
			int resp = 1;
			if(this->primero){
				q = this->primero;
				while((q != NULL) and (q->info != ref)){
					ant = q;
					q = q->liga;
				}
				if(q != NULL){
					p = new NodoLista<T>();
					p->info = dato;
					if(this->primero == q){
						p->liga = this->primero;
						this->primero = p;
					}
					else{
						ant->liga = p;
						p->liga = q;
					}
				}
				else{
					resp = 0;
				}
			}
			else{
				resp = -1;
			}
			return resp;
		}
		
		int insertarDespuesReferencia(T dato, T ref){
			NodoLista<T> *q, *p;
			int resp = 1;
			if(this->primero){
				q = this->primero;
				while((q != NULL) and (q->info != ref)){
					q = q->liga;
				}
				if(q != NULL){
					p = new NodoLista<T>();
					p->info = dato;
					p->liga = q->liga;
					q->liga = p;
				}
				else{
					resp = 0;
				}
			}
			else{
				resp = -1;
			}
			return resp;
		}
		
		/* ------------------------------------------------------------ */
		void insert(T dato){
			NodoLista<T> *p = new NodoLista<T>(), *q = NULL, *ant = NULL;
			if(!this->primero or this->primero->info > dato){
				p->info = dato;
				p->liga = this->primero;
				this->primero = p;
			}
			else{
				q = this->primero;
				while(q and q->info < dato){
					ant = q;
					q = q->liga;
				}
				p->info = dato;
				ant->liga = p;
				p->liga = q;
			}
			
			/*
			NodoLista<T> *p = new NodoLista<T>(), *q, *ant =NULL;
			p->info = dato;
			if(this->primero){
				q = this->primero;
				while((q != NULL) and (q->info <= dato)){
					ant = q;
					q = q->liga;
				}
				if(this->primero == q){
					p->liga = this->primero;
					this->primero = p;
				}
				else{
					p->liga = ant->liga;
					ant->liga = p;
				}
			}
			else{
				p->liga = this->primero;
				this->primero = p;
			}
			*/
		}
		/* ------------------------------------------------------------ */

		int eliminarInicio(){
			NodoLista<T> *p = NULL;
			int resp = 1;
			if(this->primero){
				p = this->primero;
				this->primero = p->liga;
				delete (p);
			}
			else{
				resp = 0;
			}
			return resp;
		}

		int eliminarFinal(){
			NodoLista<T> *ant = NULL, *p = NULL;
			int resp = 1;
			if(this->primero){
				if(!this->primero->liga){
					delete (this->primero);
					this->primero = NULL;
				}
				else{
					p = this->primero;
					while(p->liga){
						ant = p;
						p = p->liga;
					}
					ant->liga = NULL;
					delete (p);
				}
			}
			else{
				resp = 0;
			}
			return resp;
		}

		int remove(T dato){
			NodoLista<T> *p, *ant = NULL;
			int resp = 1;
			if(this->primero){
				p = this->primero;
				while((p->liga) and (p->info != dato)){
					ant = p;
					p = p->liga;
				}
				if(p->info != dato){
					resp = 0;
				}
				else{
					if(this->primero == p){
						this->primero  = p->liga;
					}
					else{
						ant->liga = p->liga;
					}
					delete (p);
				}
			}
			else{
				resp = -1;
			}
			return resp;
		}

		friend ostream& operator << <>(ostream &,const Lista<T> &);
};

int main(){
	Lista<int> p;
	p.insert(4);
	p.insert(6);
	p.insert(3);
	p.insert(0);
	p.insert(5);
	p.insert(9);
	cout<<p<<'\n';
	p.remove(5);
	cout<<p<<'\n';
		

	return 0;
}
