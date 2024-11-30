#include "BinaryTree.h"

Node* BinaryTree::search(Node* root, int data)
{
	if (!root || root->get_data() == data)
		return root;

	Node* left = this->search(root->get_left(), data);
	Node* right = this->search(root->get_right(), data);

	return left ? left : right;
}

void BinaryTree::preorder(Node* root, std::queue<int>* queue)
{
	if (root == nullptr)
		return;

	queue->push(root->get_data());
	this->preorder(root->get_left(), queue);
	this->preorder(root->get_right(), queue);
}

void BinaryTree::inorder(Node* root, std::queue<int>* queue)
{
	if (root == nullptr)
		return;

	this->inorder(root->get_left(), queue);
	queue->push(root->get_data());
	this->inorder(root->get_right(), queue);
}

void BinaryTree::postorder(Node* root, std::queue<int>* queue)
{
	if (root == nullptr)
		return;

	this->postorder(root->get_left(), queue);
	this->postorder(root->get_right(), queue);
	queue->push(root->get_data());
}

BinaryTree::BinaryTree()
	: root(nullptr), amount(0) {}

BinaryTree::~BinaryTree()
{
	this->remove_all();
}

void BinaryTree::add_iterative(int data)
{
	if (this->root == nullptr)
	{
		this->root = new Node(data);
		this->amount++;
		return;
	}

	int iterations = (this->amount + 1) / 2;
	std::queue<Node*> queue;
	Node* aux = this->root;
	queue.push(aux);

	for (int i = 0; i < iterations; i++)
	{
		aux = queue.front();
		queue.pop();

		if (aux->get_left())
			queue.push(aux->get_left());
		if (aux->get_right())
			queue.push(aux->get_right());
	}

	if (!aux->get_left())
		aux->set_left(new Node(data));
	else
		aux->set_right(new Node(data));

	this->amount++;
}

Node* BinaryTree::search_iterative(int data)
{
	if (this->root == nullptr)
		return nullptr;

	std::queue<Node*> queue;
	queue.push(this->root);
	Node* aux;

	while (!queue.empty())
	{
		aux = queue.front();
		queue.pop();

		if (aux->get_data() == data)
			return aux;

		if (aux->get_left())
			queue.push(aux->get_left());
		if (aux->get_right())
			queue.push(aux->get_right());
	}

	return nullptr;
}

std::queue<int>* BinaryTree::preorder_recursive()
{
	std::queue<int>* queue = new std::queue<int>();
	this->preorder(this->root, queue);
	return queue;
}

std::queue<int>* BinaryTree::inorder_recursive()
{
	std::queue<int>* queue = new std::queue<int>();
	this->inorder(this->root, queue);
	return queue;
}

std::queue<int>* BinaryTree::postorder_recursive()
{
	std::queue<int>* queue = new std::queue<int>();
	this->postorder(this->root, queue);
	return queue;
}

std::queue<int>* BinaryTree::preorder_iterative()
{
	if (!this->root)
		return nullptr;

	std::queue<int>* preorder = new std::queue<int>();
	std::stack<Node*> stack;
	stack.push(this->root);
	Node* aux;

	while (!stack.empty())
	{
		aux = stack.top();
		stack.pop();

		preorder->push(aux->get_data());

		if (aux->get_right())
			stack.push(aux->get_right());
		if (aux->get_left())
			stack.push(aux->get_left());
	}

	return preorder;
}

std::queue<int>* BinaryTree::inorder_iterative()
{
	if (!this->root)
		return nullptr;

	std::queue<int>* inorder = new std::queue<int>();
	std::stack<Node*> stack;
	Node* aux = this->root;

	while (true)
	{
		while (aux)
		{
			stack.push(aux);
			aux = aux->get_left();
		}

		if (!stack.empty())
		{
			aux = stack.top();
			stack.pop();
			inorder->push(aux->get_data());
			aux = aux->get_right();
		}
		else
			break;
	}

	return inorder;
}

std::queue<int>* BinaryTree::postorder_iterative()
{
	if (!this->root)
		return nullptr;

	std::queue<int>* postorder = new std::queue<int>();
	std::stack<Node*> aux_stack, reversed_stack;
	aux_stack.push(this->root);
	Node* aux;

	while (!aux_stack.empty())
	{
		aux = aux_stack.top();
		aux_stack.pop();
		reversed_stack.push(aux);

		if (aux->get_left())
			aux_stack.push(aux->get_left());
		if (aux->get_right())
			aux_stack.push(aux->get_right());
	}

	while (!reversed_stack.empty())
	{
		aux = reversed_stack.top();
		reversed_stack.pop();
		postorder->push(aux->get_data());
	}

	return postorder;
}