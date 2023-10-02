

#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <queue>


// Estrucuctura del Nodo

template <typename T>
struct BSTNode{
  //valor
T key;
// apuntador a la derecha del nodo
BSTNode<T> *right;
// apuntador a la izquierda del nodo
BSTNode<T> *left;
// apuntador al padre del nodo
BSTNode<T> *parent;
// factor de equilibrio de un nodo
int bf;
};

// Estrucutura del árbol
template <typename T>
class BST{
private:
  BSTNode<T> *root;
  void insert_node(BSTNode<T>* &node,BSTNode<T> *p, T k);
  void destroy(BSTNode<T> *t);
  void displayNode(BSTNode<T> *t, int count);
  //void displayNode2(BSTNode<T> *t);
  BSTNode<T>* findNode(BSTNode<T> *t, T k);
  BSTNode<T>* minimum(BSTNode<T> *t);
  BSTNode<T>* maximum(BSTNode<T> *t);
  BSTNode<T>* sucesor(BSTNode<T> *t);
  BSTNode<T>* predecesor(BSTNode<T> *t);
  //Funcion que halla el factor de equilibrio de un nodo Lineas 303 a 327
  int Diferencia(BSTNode<T>* &t);
  //Funcion que rota a la derecha el árbol
  // Lineas 342 a 370
  void rotaDerecha(BSTNode<T>* &t);
  //Funcion que rota a la izquieda el árbol
  // Lineas 380 a 409
  void rotaIzquierda(BSTNode<T>* &t);
  void verArbol(BSTNode<T> *t, int n);
  void BALANCEO(BSTNode<T>* &node,T k);
  void BALANCEO2(BSTNode<T>* &node);
  //Rotacion compuesta a la Izquierda
  void RotacionCompIzquierda(BSTNode<T>* &node);
  //Rotacion compuesta a la derecha
  void RotacionCompDerecha(BSTNode<T>* &node);
  BSTNode<T>* removeNode(BSTNode<T>* &t);

public:
  BST();
  ~BST();
  void insert(T k);
  void display();
  bool find(T k);
  T min();
  T maxi();
  void remove(T k);
  T suce(T k);
  T predece(T k);
  int alto(T k);
  //void Imprime();
  void BalancearDerecha(T k);
  void BalancearIzquierda(T k);
  //void ImprimeLindo(std::vector<int> a);
  //void display2();
  void ver();
};

//constructor
template <typename T>
BST<T>::BST(){
  root = nullptr;
  void insert(int k);
}

//destructor
template <typename T>
BST<T>::~BST(){
  destroy(root);
}

//insertar nodo
template <typename T>
void BST<T>::insert_node(BSTNode<T>* &node, BSTNode<T> *p, T k){
  if(node == nullptr){
    node = new BSTNode<T>;
    node -> key = k;
    node -> right = nullptr;
    node -> left = nullptr;
    node -> parent = p;
    std::cout << "insertando " << k << std::endl;
  }
  else{
    if(k != node -> key){
      if(k < node -> key){
        insert_node(node->left,node,k);
      }
      else{
        insert_node(node->right,node,k);
      }
    }
  }
  //Balanceamos cada vez que insertamos.
  BALANCEO(node,k);
}

//Función balancear
template <typename T>
void BST<T>::BALANCEO(BSTNode<T>* &node,T k){
  //Hallamos el factor de diferencia
  Diferencia(node);
  if(node -> bf < -1 || node -> bf > 1){
    if(node -> bf < -1 && k < node->left->key){
      //rotación compuesta a la derecha
      //std::cout << "Antes" << std::endl;
      BalancearDerecha(node -> key);
    //std::cout << "Despues" << std::endl;
    }
    else if(node -> bf > 1 && k > node->right->key){
      //rotación compuesta a la izquierda
      //std::cout << "Antes" << std::endl;
      BalancearIzquierda(node-> key);
      //std::cout << "Despues" << std::endl;
    }
    else if(node -> bf < -1 && k > node->left->key){
      //rotación compuesta a la Izquierda
      // BalancearIzquierda(node -> left -> key);
      // BalancearDerecha(node ->key);
      RotacionCompIzquierda(node);
    }
    else if(node -> bf > 1 && k < node->right->key){
      //rotación compuesta a la Derecha
      // BalancearDerecha(node->right->key);
      // BalancearIzquierda(node->key);
      RotacionCompDerecha(node);
    }
  }
}

//Rotación compuesta a la izquierda
template<typename T>
void BST<T>::RotacionCompIzquierda(BSTNode<T> *& node){
  BalancearIzquierda(node->left->key);
  BalancearDerecha(node->key);
}

//Rotación compuesta a la derecha
template <typename T>
void BST<T>::RotacionCompDerecha(BSTNode<T> *&node){
  BalancearDerecha(node->right->key);
  BalancearIzquierda(node->key);
}

//Función Balanceo usada para el remove
template <typename T>
void BST<T>::BALANCEO2(BSTNode<T>* &node){
  //Se balancea sobre el nodo
  BALANCEO(node,node -> key);
  //Si es posible, se balancean los hijos.
  if(node -> left != nullptr){
    BALANCEO2(node -> left);
  }
  if(node -> right != nullptr){
    BALANCEO2(node -> right);
  }
}

//wrapper del insert
template <typename T>
void BST<T>::insert(T k){
  //lista.push_back(k);
  insert_node(root,nullptr,k);
}

//función que destruye el árbol
template <typename T>
void BST<T>::destroy(BSTNode<T> *t){
  if(t != nullptr){
    destroy(t -> right);
    destroy(t -> left);
    std::cout << "Eliminando: " << t->key << std::endl;
    delete t;
  }
}

//Imprimer un árbol. Forma sencilla
template <typename T>
void BST<T>::displayNode(BSTNode<T> *t, int count){
  if(t != nullptr){
    count++;
    displayNode(t -> left,count);
    std::cout << "(" << count -1  << ")" << t-> key << " ";
    displayNode(t -> right,count);
  }
}

//wrapper de display node
template <typename T>
void BST<T>::display(){
  displayNode(root,0);
  std::cout << std::endl;
}

//función para encontrar un nodo
template <typename T>
BSTNode<T>* BST<T>::findNode(BSTNode<T> *t, T k){
  if(t == nullptr){
    return nullptr;
  }
  if( k == t -> key){
    return t;
  }
  if( k < t -> key){
    return findNode(t -> left, k);
  }
  else{
    return findNode(t -> right, k);
  }
}

//wrapper de findNode
template <typename T>
bool BST<T>::find(T k){
  if(findNode(root,k) == nullptr){
    return false;
  }
  else{
    return true;
  }
}


template <typename T>
BSTNode<T>* BST<T>::minimum(BSTNode<T> *t){
  if(t -> left == nullptr){
    return t;
  }
  else{
    return minimum(t-> left);
  }
}

template <typename T>
T BST<T>::min(){
  T respuesta = minimum(root) -> key;
  return respuesta;
}

template <typename T>
BSTNode<T>* BST<T>::maximum(BSTNode<T> *t){
  if(t -> right == nullptr){
    return t;
  }
  else{
    return maximum(t-> right);
  }
}

template <typename T>
T BST<T>::maxi(){
  T respuesta = maximum(root) -> key;
  return respuesta;
}

//función que haya la llave sucesora de un nodo.
template <typename T>
BSTNode<T>* BST<T>::sucesor(BSTNode<T> *t){
  if(t -> right != nullptr){
    return minimum(t->right);
  }
  else{
    if(maximum(root) == t){
        throw std::runtime_error("suce: Attempting to get a sucesor from the maximum node");
        ;
    }
    else{
      while( t != (t -> parent) -> left){
        t = t -> parent;
      }
      return t -> parent;
    }
  }
}

//wrapper suce
template <typename T>
T BST<T>::suce(T k){
  BSTNode<T> *nodo;
  nodo = findNode(root,k);
  return sucesor(nodo) -> key;
}

//función que haya la llave predecesora de un nodo.
template <typename T>
BSTNode<T>* BST<T>::predecesor(BSTNode<T> *t){
  if(t -> left != nullptr){
    return maximum(t->left);
  }
  else{
    if(minimum(root) == t){
        throw std::runtime_error("predece: Attempting to get a predecesor from the minimum node");
        ;
    }
    else{
      while(t != (t -> parent) -> right){
        t = t -> parent;
      }
      return t -> parent;
    }
  }
}

//wrapper predece
template <typename T>
T BST<T>::predece(T k){
  BSTNode<T> *nodo;
  nodo = findNode(root,k);
  return predecesor(nodo) -> key;
}

//función remover un nodo
template<typename T>
BSTNode<T>* BST<T>::removeNode(BSTNode<T>* &t){
  //BSTNode<T> *node=FindNode(t,k);
  if (t != nullptr){
    BSTNode<T> *p=t->parent;
    if(t->right==nullptr && t->left==nullptr){
      if(p==nullptr){
        root=nullptr;
      }
      else if(p->left==t){
        p->left=nullptr;
      }
      else if(p->right==t){
        p->right=nullptr;
      }
      delete t;
    }
    else if(t->right==nullptr){
      if(p==nullptr){
        root=t->left;
      }
      else if(p->right==t){
        p->right=t->left;
        t->left->parent=p;
      }
      else if(p->left==t){
        p->left=t->left;
        t->left->parent=p;
      }
      delete t;
    }
    else if(t->left==nullptr){
      if(p==nullptr){
        root=t->right;
      }
      else if(p->right==t){
        p->right=t->right;
        t->right->parent=p;
      }
      else if(p->left==t){
        p->left=t->right;
        t->right->parent=p;
      }
      delete t;
    }
    else{
      BSTNode<T>*temp=sucesor(t);
      T newkey=temp->key;
      BSTNode<T>*p=removeNode(temp);
      t->key=newkey;
    }
    return p;
  }
  return nullptr;
}

//wrapper de remove
template<typename T>
void BST<T>::remove(T k){
  BSTNode<T> *t=findNode(root,k);
  if (t==nullptr){
    std::runtime_error("Remove: Element not in the tree");
  }
  else{
    removeNode(t);
    //Balancear todo el árbol después de remover
    BALANCEO2(root);
  }
}

//función que haya la diferencia de altura de los subárboles de un nodo.
template <typename T>
int BST<T>::Diferencia(BSTNode<T>* &t){
  // Caso nodo sin hijos
  if(t->right == nullptr && t -> left == nullptr){
    t -> bf = 0;
    return 0;
  }
  // Caso nodo con hijos
  else{
    //Inicializa factores(en negativo para calacular la diferencia)
    int FactorIzquierdo = -1;
    int FactorDerecho = -1;
    //Si tiene hijo izquierdo
    if(t -> left != nullptr){
      FactorIzquierdo = Diferencia(t -> left);
    }
    //Si tiene hijo derecho
    if(t -> right != nullptr){
      FactorDerecho = Diferencia(t -> right);
    }

    t -> bf = FactorDerecho - FactorIzquierdo;
    //std::cout << t -> bf << std::endl;
    //Retorna el mayor valor +1, ya que lo inicializamos en -1
    if(FactorIzquierdo < FactorDerecho){
      return FactorDerecho +1;
    }
    else{
      return FactorIzquierdo +1;
    }
  }
}

template <typename T>
int BST<T>::alto(T k){
  BSTNode<T> *nodo;
  nodo = findNode(root,k);
  return Diferencia(nodo);
}

//función que rota a la derecha
template <typename T>
void BST<T>::rotaDerecha(BSTNode<T>* &t){
  //Apuntador al hijo izquierdo
  BSTNode<T> *descendiente = t -> left;
  // Apuntamos al hijo derecho
  t -> left = descendiente -> right;
  //Caso hay un hijo izquierdo
  if(t -> left != nullptr){
    (t -> left) -> parent = t;
  }
  //Apuntamos el hijo derecho al nodo que recibimos y acomodamos el parent correctamente.
  descendiente -> right = t;
  descendiente -> parent = t -> parent;
  t -> parent = descendiente;
  //Caso no hay parent.
  if(descendiente -> parent == nullptr){
    root = descendiente;
  }
  else{
    //Caso si hay parent
    //Se averigua si acomodar a la izquierda o derecha segun el key
    if((descendiente -> parent) -> key < descendiente -> key){
      (descendiente -> parent) -> right = descendiente;
    }
    else{
      (descendiente -> parent) -> left = descendiente;
    }
  }
}

//Wrapper de rotaDerecha
template <typename T>
void BST<T>::BalancearDerecha(T k){
  BSTNode<T> *nodo;
  nodo = findNode(root,k);
  rotaDerecha(nodo);
}

//función que rota a la izquierda
template <typename T>
void BST<T>::rotaIzquierda(BSTNode<T>* &t){
  //Apuntador al hijo derecho
  BSTNode<T> *descendiente;
  // Apuntamos al hijo izquiedo
  descendiente = t -> right;
  t -> right = descendiente -> left;
  //Caso hay un hijo derecho
  if(t -> right != nullptr){
    (t -> right) -> parent = t;
  }
  //Apuntamos el hijo izquierdo al nodo que recibimos y acomodamos el parent correctamente.
  descendiente -> left = t;
  descendiente -> parent = t -> parent;
  t -> parent = descendiente;
  //Caso no hay parent.
  if(descendiente -> parent == nullptr){
    root = descendiente;
  }
  else{
    //Caso si hay parent
    //Se averigua si acomodar a la izquierda o derecha segun el key
    if((descendiente -> parent) -> key < descendiente -> key){
      (descendiente -> parent) -> right = descendiente;
    }
    else{
      (descendiente -> parent) -> left = descendiente;
    }
  }
}

//wrapper rotaIzquierda
template <typename T>
void BST<T>::BalancearIzquierda(T k){
  BSTNode<T> *nodo;
  nodo = findNode(root,k);
  rotaIzquierda(nodo);
}

/*Funcion que muestra el arbol binario.
-Si el apuntador que recibe es nullptr termina la funcion.
-Si el apuntador que recibe no es nullptr, hacemos recursion
sobre la parte derecha del arbol, con n+1 (esto para el tema de los espacios)
pues segun nuestro algoritmo es lo primero en imprimirse.
-La utilidad del for, es para imprimir los espacios y tratar
de mostrar el arbol binario.
-Luego se imprime el dato que se encuentra en t->key con un "endl",
para que los nodos en consola se vean con la forma de un arbol binario.
-Finalmente, hacemos recursion del arbol de la izquierda, con n+1, de la misma
manera como lo hicimos con el arbol de la derecha, y con el mismo objetivo del
n+1-
*/

template<typename T>
void BST<T>::verArbol(BSTNode<T> *t, int n){
  if(t==nullptr){
    return;
  }
  verArbol(t->right, n+1);
  for(int i=0; i<n; i++)
      std::cout<<"   ";
  std::cout<< t->key << std::endl;
  verArbol(t->left, n+1);
}

template<typename T>
void BST<T>::ver(){
  if(root==nullptr){
    std::runtime_error("Ver: Tree is empty");
  }
  else{
    //cout<<"pase al else";
    verArbol(root,0);
  }
}

#endif
