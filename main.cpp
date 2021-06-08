#include <iostream>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node;

template <class T>
ostream& operator<<(ostream &o, const LinkedList<T> &l){
    Node<T> *q = l.head;
	while(q){
		o<<q->info<<' ';
		q = q->next;
	}
    return o;
}

template <class T>
class Node{
	private:
		Node<T> *next;
		T info;
	public:
		Node(){
			this->next = NULL;
		}
		friend class LinkedList<T>;
		friend ostream& operator << <>(ostream &,const LinkedList<T> &);

};

template <class T>
class LinkedList{
	private:
		Node<T> *head;
	public:
		LinkedList(){
			this->head = NULL;
		}

		void insertarInicio(T dato){
			Node<T> *p = new Node<T>();
			p->info = dato;
			p->next = this->head;
			this->head = p;
		}

		void insertarFinal(T dato){
			Node<T> *p = new Node<T>(), *ultimo;
			p->info = dato;
			if(this->head){
				ultimo = this->head;
				while(ultimo->next){
					ultimo = ultimo->next;
				}
				ultimo->next = p;
			}
			else{
				this->head = p;
			}
		}

		int insertarAntesReferencia(T dato, T ref){
			Node<T> *p, *ant, *q;
			int resp = 1;
			if(this->head){
				q = this->head;
				while((q != NULL) and (q->info != ref)){
					ant = q;
					q = q->next;
				}
				if(q != NULL){
					p = new Node<T>();
					p->info = dato;
					if(this->head == q){
						p->next = this->head;
						this->head = p;
					}
					else{
						ant->next = p;
						p->next = q;
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
			Node<T> *q, *p;
			int resp = 1;
			if(this->head){
				q = this->head;
				while((q != NULL) and (q->info != ref)){
					q = q->next;
				}
				if(q != NULL){
					p = new Node<T>();
					p->info = dato;
					p->next = q->next;
					q->next = p;
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
			Node<T> *p = new Node<T>(), *q = NULL, *ant = NULL;
			if(!this->head or this->head->info > dato){
				p->info = dato;
				p->next = this->head;
				this->head = p;
			}
			else{
				q = this->head;
				while(q and q->info < dato){
					ant = q;
					q = q->next;
				}
				p->info = dato;
				ant->next = p;
				p->next = q;
			}
			
			/*
			Node<T> *p = new Node<T>(), *q, *ant =NULL;
			p->info = dato;
			if(this->head){
				q = this->head;
				while((q != NULL) and (q->info <= dato)){
					ant = q;
					q = q->next;
				}
				if(this->head == q){
					p->next = this->head;
					this->head = p;
				}
				else{
					p->next = ant->next;
					ant->next = p;
				}
			}
			else{
				p->next = this->head;
				this->head = p;
			}
			*/
		}
		/* ------------------------------------------------------------ */

		int eliminarInicio(){
			Node<T> *p = NULL;
			int resp = 1;
			if(this->head){
				p = this->head;
				this->head = p->next;
				delete (p);
			}
			else{
				resp = 0;
			}
			return resp;
		}

		int eliminarFinal(){
			Node<T> *ant = NULL, *p = NULL;
			int resp = 1;
			if(this->head){
				if(!this->head->next){
					delete (this->head);
					this->head = NULL;
				}
				else{
					p = this->head;
					while(p->next){
						ant = p;
						p = p->next;
					}
					ant->next = NULL;
					delete (p);
				}
			}
			else{
				resp = 0;
			}
			return resp;
		}
		
		/* ------------------------------------------------------------ */
		int remove(T dato){
			Node<T> *p, *ant = NULL;
			int resp = 1;
			if(this->head){
				p = this->head;
				while((p->next) and (p->info != dato)){
					ant = p;
					p = p->next;
				}
				if(p->info != dato){
					resp = 0;
				}
				else{
					if(this->head == p){
						this->head  = p->next;
					}
					else{
						ant->next = p->next;
					}
					delete (p);
				}
			}
			else{
				resp = -1;
			}
			return resp;
		}
		/* ------------------------------------------------------------ */

		friend ostream& operator << <>(ostream &,const LinkedList<T> &);
};

int main(){
	LinkedList<int> p;
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