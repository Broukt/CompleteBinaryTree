#include "BinaryTree.h"

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