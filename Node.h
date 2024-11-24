#pragma once

/// <summary>
/// Entidad que representa un nodo de un árbol binario
/// </summary>
class Node
{
private:
	
	/// <summary>
	/// Dato que contiene el nodo
	/// </summary>
	int data;
	/// <summary>
	/// Puntero al nodo hijo izquierdo
	/// </summary>
	Node* left;
	/// <summary>
	/// Puntero al nodo hijo derecho
	/// </summary>
	Node* right;

public:

	/// <summary>
	/// Constructor por defecto
	/// </summary>
	Node();
	/// <summary>
	/// Constructor de copia
	/// </summary>
	/// <param name="other">Nodo a copiar</param>
	Node(Node&);
	/// <summary>
	/// Constructor de la clase
	/// </summary>
	/// <param name="data">Dato del nodo</param>
	Node(int);
	/// <summary>
	/// Destructor de la clase
	/// </summary>
	~Node() = default;

	/// <summary>
	/// Obtiene el dato del nodo
	/// </summary>
	/// <returns>Dato del nodo</returns>
	int get_data();
	/// <summary>
	/// Obtiene el nodo hijo izquierdo
	/// </summary>
	/// <returns>Puntero con referencia al hijo izquierdo</returns>
	Node* get_left();
	/// <summary>
	/// Obtiene el nodo hijo derecho
	/// </summary>
	/// <returns>Puntero con referencia al hijo derecho</returns>
	Node* get_right();

	/// <summary>
	/// Establece el dato del nodo
	/// </summary>
	/// <param name="data">Dato a establecer</param>
	void set_data(int);
	/// <summary>
	/// Establece el nodo hijo izquierdo
	/// </summary>
	/// <param name="left">Puntero al nodo hijo izquierdo</param>
	void set_left(Node*);
	/// <summary>
	/// Establece el nodo hijo derecho
	/// </summary>
	/// <param name="right">Puntero al nodo hijo derecho</param>
	void set_right(Node*);
};