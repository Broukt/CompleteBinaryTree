#pragma once
#include "Node.h"
#include <stack>
#include <queue>

/// <summary>
/// Entidad que representa un �rbol binario
/// </summary>
class BinaryTree
{
private:

	/// <summary>
	/// Puntero a la ra�z del �rbol
	/// </summary>
	Node* root;
	/// <summary>
	/// Cantidad de nodos en el �rbol
	/// </summary>
	int amount;

	/// <summary>
	/// Agrega un nodo al �rbol de manera recursiva
	/// </summary>
	/// <param name="root">Nodo ra�z</param>
	/// <param name="data">Dato del nodo a agregar</param>
	/// <returns>Nodo ra�z</returns>
	Node* add(Node*, int);
	/// <summary>
	/// Busca un nodo en el �rbol de manera recursiva
	/// </summary>
	/// <param name="root">Nodo ra�z</param>
	/// <param name="data">Dato del nodo a buscar</param>
	/// <returns>Nodo encontrado</returns>
	Node* search(Node*, int);

	/// <summary>
	/// Realiza el recorrido en preorden de manera recursiva
	/// </summary>
	/// <param name="root">Nodo ra�z</param>
	/// <param name="queue">Cola con el recorrido</param>
	void preorder(Node*, std::queue<int>*);
	/// <summary>
	/// Realiza el recorrido en inorden de manera recursiva
	/// </summary>
	/// <param name="root">Nodo ra�z</param>
	/// <param name="queue">Cola con el recorrido</param>
	void inorder(Node*, std::queue<int>*);
	/// <summary>
	/// Realiza el recorrido en postorden de manera recursiva
	/// </summary>
	/// <param name="root">Nodo ra�z</param>
	/// <param name="queue">Cola con el recorrido</param>
	void postorder(Node*, std::queue<int>*);

public:

	/// <summary>
	/// Constructor de la clase
	/// </summary>
	BinaryTree();
	/// <summary>
	/// Destructor de la clase
	/// </summary>
	~BinaryTree();

	/// <summary>
	/// Agrega un nodo al �rbol de manera iterativa
	/// </summary>
	/// <param name="data">Dato del nodo a agregar</param>
	void add_iterative(int);
	/// <summary>
	/// Busca un nodo en el �rbol de manera iterativa
	/// </summary>
	/// <param name="data">Dato del nodo a buscar</param>
	/// <returns>Nodo encontrado</returns>
	Node* search_iterative(int);
	/// <summary>
	/// Elimina un nodo del �rbol de manera iterativa
	/// </summary>
	/// <param name="data">Dato del nodo a eliminar</param>
	void remove_iterative(int);

	/// <summary>
	/// Agrega un nodo al �rbol de manera recursiva
	/// </summary>
	/// <param name="data">Dato del nodo a agregar</param>
	void add_recursive(int);
	/// <summary>
	/// Busca un nodo en el �rbol de manera recursiva
	/// </summary>
	/// <param name="data">Dato del nodo a buscar</param>
	Node* search_recursive(int);

	/// <summary>
	/// Realiza el recorrido en preorden de manera recursiva
	/// </summary>
	/// <returns>Cola con el recorrido</returns>
	std::queue<int>* preorder_recursive();
	/// <summary>
	/// Realiza el recorrido en inorden de manera recursiva
	/// </summary>
	/// <returns>Cola con el recorrido</returns>
	std::queue<int>* inorder_recursive();
	/// <summary>
	/// Realiza el recorrido en postorden de manera recursiva
	/// </summary>
	/// <returns>Cola con el recorrido</returns>
	std::queue<int>* postorder_recursive();

	/// <summary>
	/// Realiza el recorrido en preorden de manera iterativa
	/// </summary>
	/// <returns>Cola con el recorrido</returns>
	std::queue<int>* preorder_iterative();
	/// <summary>
	/// Realiza el recorrido en inorden de manera iterativa
	/// </summary>
	/// <returns>Cola con el recorrido</returns>
	std::queue<int>* inorder_iterative();
	/// <summary>
	/// Realiza el recorrido en postorden de manera iterativa
	/// </summary>
	/// <returns>Cola con el recorrido</returns>
	std::queue<int>* postorder_iterative();

	/// <summary>
	/// Elimina todos los nodos del �rbol
	/// </summary>
	void remove_all();
	/// <summary>
	/// Identifica si el �rbol es perfecto
	/// </summary>
	/// <returns>Verdadero si es perfecto, falso en caso contrario</returns>
	bool is_perfect();

	/// <summary>
	/// Obtiene la cantidad de nodos en el �rbol
	/// </summary>
	/// <returns>Cantidad de nodos en el �rbol</returns>
	int get_amount();
	/// <summary>
	/// Obtiene la ra�z del �rbol
	/// </summary>
	/// <returns>Puntero a la ra�z del �rbol</returns>
	Node* get_root();
};