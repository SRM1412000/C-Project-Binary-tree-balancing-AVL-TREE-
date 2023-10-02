#include "binarytree.hpp"
using namespace std;

int main(){
  BST<int> my_tree;
  BST<int> my_tree2;
  BST<string> enanitos;
  cout<<endl;
  cout<<"Proyecto Arbol AVL: "<<endl;
  cout<<endl;
  cout<<endl;
  my_tree.insert(100);
  my_tree.insert(29);
  my_tree.insert(71);
  my_tree.insert(82);
  my_tree.insert(48);
  my_tree.insert(39);
  my_tree.insert(101);
  my_tree.insert(22);
  my_tree.insert(46);
  my_tree.insert(17);
  my_tree.insert(3);
  my_tree.insert(20);
  my_tree.insert(25);
  my_tree.insert(10);
  cout<<"\n\nArbol: "<<endl;
  cout <<"\n";
  my_tree.ver();
  cout <<"\n";
  cout<<"Despues de insertar los elementos, podemos notar que el arbol esta balanceado!"<<endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout<<"Vamos a eliminar el 29 y el 39: "<<endl;
  cout <<"\n";
  my_tree.remove(29);
  my_tree.remove(39);
  cout<<"\n\nArbol: "<<endl;
  cout <<"\n";
  my_tree.ver();
  cout <<"\n";
  cout<<"Como vemos, el arbol elimino las llaves que le pedimos y se mantiene balanceado: "<<endl;
  cout <<"\n";
  cout<<"Destruyendo arbol..."<<endl;
  return 0;
}
