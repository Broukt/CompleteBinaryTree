#pragma once
#include "Node.h"
#include <stack>
#include <queue>

class BinaryTree
{
private:

	Node* root;
	int amount;

	Node* add(Node*, int);
	Node* search(Node*, int);

	void preorder(Node*, std::queue<int>*);
	void inorder(Node*, std::queue<int>*);
	void postorder(Node*, std::queue<int>*);

public:

	BinaryTree();
	~BinaryTree();

	void add_iterative(int);
	Node* search_iterative(int);
	void remove_iterative(int);

	void add_recursive(int);
	Node* search_recursive(int);

	std::queue<int>* preorder_recursive();
	std::queue<int>* inorder_recursive();
	std::queue<int>* postorder_recursive();

	std::queue<int>* preorder_iterative();
	std::queue<int>* inorder_iterative();
	std::queue<int>* postorder_iterative();

	void remove_all();
	bool is_perfect();

	int get_amount();
	Node* get_root();
};