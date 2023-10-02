# C-Project-Binary-tree-balancing-AVL-TREE-

* Project by: David Oviedo Salamanca [@fonzo004](https://github.com/fonzo004), Germán David Plazas Cayachoa [@DavPlazas](https://github.com/DavPlazas), Santiago Rodríguez Morales [@SRM1412000](https://github.com/SRM1412000)

## Index
- [Introduction.](#introduction)
  - [Abstract.](#summary)
  - [Functionality of the Computational Solution.](#funcionalidad)

- [Description of program.](#description)
- [Components](#components)
- [How it works.](#use)


## Introduction
### Abstract <a name="summary"></a>
In a binary search tree it may happen that in some of its nodes the left and right subtrees differ by more than one unit in their height. When this happens, the search speed in a binary tree is considerably affected. Consequently, when inserting or removing nodes, more time is spent.

For this reason, it is convenient to implement an algorithm that allows the heights of the subtrees of each node not to differ by more than one unit, i.e., to be a balanced tree. A possible solution to this problem is to implement binary AVL trees (AVL Tree), which is a balanced binary tree structure. 

The work that was developed to implement a binary AVL tree consisted of creating the functions left rotation, right rotation, left composite rotation, right composite rotation and balancing to balance a binary tree.
Video Explain: https://www.youtube.com/watch?v=xEOQyETtYlY&feature=youtu.be

### Functionality of the Computational Solution <a name="funcionalidad"></a>
Our AVL Tree works as follows:
- It receives keys to be placed in our binary tree.
- It creates a new node and inserts it in the tree according to the property.
- It checks the height of the subtrees of the nodes.
- In case any subtree is not balanced, a call is made to the balancing function, which balances the height of the subtrees. There, the type of rotation to be performed is checked.
- If a user wants to remove a node by its key, it is searched in the tree and removed. After this, the height of the subtrees is checked again, and in case of an imbalance, the balancing2 function is called.
- Our tool allows us to visualize an AVL tree when required.

This is how our AVL tool allows us to balance a binary tree while maintaining all its functionalities (Insert, remove, search).

## Description of program <a name="description"></a>
The basis of our tool focuses on binary trees, which are structures where information is inserted, removed or searched in an optimal and fast way. These structures are composed of nodes where they can have up to one parent node and two child nodes called left node and right node. The nodes in a tree are placed in such a way that the left child nodes are smaller than their parent node and the right child nodes are larger than their parent node. Thus, the property of binary trees is fulfilled. 

Our tool is the implementation of an AVL tree which is a special type of binary search tree where every node fulfills the AVL balancing property. This balancing property consists in that a node, the height of the left and the right subtree do not differ by more than one. That is, the balancing factor of any node is -1, 0 or +1. 


| ![image](https://github.com/SRM1412000/C-Project-Binary-tree-balancing-AVL-TREE-/assets/146349622/8733df5b-3321-4fe3-9168-26a720e7f3cc) *Balanced tree. The balancing factor is -1. Because the height of the left subtree is 2 and the right subtree is 3.* | ![image](https://github.com/SRM1412000/C-Project-Binary-tree-balancing-AVL-TREE-/assets/146349622/302ba167-8c01-460e-8cad-b18c98a34a33) *Unbalanced tree. The balancing factor is -2. Because the height of the left subtree is 1 and that of the right subtree is 3.* |
|--------------------------------------------------------|--------------------------------------------------------|


To satisfy the balancing property, at the moment the user calls the insert function to insert new keys to our binary tree our tool calls the insert_node function which creates a new node with the inserted key and places it in the tree precisely. After this process, this same function calls the function balancea, in charge of satisfying the AVL balancing property in each node of the tree. The balance function is aided by the difference function which calculates the balancing difference at each node. If the balancing difference does not satisfy the AVL balancing property, rotations are performed on the tree. There, we verify which rotation case to do to balance a tree by calling the functions BalanceRight and BalanceLeft, which perform a process of redirection of pointers and changes between child and parent nodes in the corresponding direction (Right or Left). Finally, our tree will be balanced.

There is the possibility that the user decides to remove a key from the tree by calling the remove function which allows our tool to call the removeNode function which deletes the node with the indicated key and redirects nodes in such a way as to follow the order between the parent and child nodes. In this case, the function balancing2 is called, which calls the balancing function described above and calls balancing2 on its child nodes as long as they are different from nullptr.
Finally, in case the user wants to visualize the AVL tree, he could call the function view which prints the correct order of the tree.

## Components
- We use the Struct to represent the nodes of the binary tree.
- We use a Class (class BST) to represent a binary tree.
- We use pointers to accommodate the trees and the properties parent, left, right, key and bf (balancing of a node).
- We use recursion in many of the other functions of the class. Among them one of the most useful, the FindNode function.
- Recursive function FindNode, which finds and returns the pointer to a requested node.
- Function rotaRight and its wrapper BalanceRight, which receives a value, looks for it in the tree and balances to the right.
- RotateLeft function and its wrapper BalanceLeft, which receives a value, looks it up in the tree and balances to the left.
- RotateLeftComp function which receives a node and invokes first the function BalanceLeft on the left child of the node and then BalanceRight on the node.
- RotateCompRight function, which receives a node and invokes first the function BalanceRight on the right child of the node and then BalanceLeft on the node.
- Difference function, which calculates the left and right branch balance of a node.
- ViewTree function and its wrapper View, which presents a better visualization of a binary tree.
- Balancing function: this function will be used when inserting an element to the tree. The Swing function receives a value and a node, then invokes the function SwingLeft, SwingRight, RotateLeftComp or RotateRightComp depending on the respective case. 
- Balancing2 function: we apply this function when we are going to remove an element from the tree. Balance2 receives a node and calls the Balance function. Then, it calls the Balance2 function of its child nodes as long as they are different from nullptr.

## How it works <a name="use"></a>
