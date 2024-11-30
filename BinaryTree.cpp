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

Node* BinaryTree::search_recursive(int data)
{
	return this->search(this->root, data);
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

void BinaryTree::remove_iterative(int data)
{
	if (this->root == nullptr)
		return;

	if (this->root->get_data() == data && this->amount == 1)
	{
		delete this->root;
		this->root = nullptr;
		this->amount--;
		return;
	}
	
	std::queue<Node*> queue;
	queue.push(this->root);
	Node* last = this->root, * last_parent = nullptr, * node_to_remove = nullptr;
	int iterations = this->amount / 2;
	int iterator = 0;

	while (!queue.empty())
	{
		iterator++;
		last = queue.front();
		queue.pop();
		if (iterator == iterations)
			last_parent = last;
		if (last->get_data() == data)
			node_to_remove = last;
		if (last->get_left())
			queue.push(last->get_left());
		if (last->get_right())
			queue.push(last->get_right());
	}

	if (!node_to_remove)
		return;

	node_to_remove->set_data(last->get_data());
	if (last_parent->get_left() == last)
		last_parent->set_left(nullptr);
	else
		last_parent->set_right(nullptr);

	delete last;
	this->amount--;
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

void BinaryTree::remove_all()
{
	if (!this->root)
		return;
	std::queue<Node*> queue;
	queue.push(this->root);
	Node* aux;
	while (!queue.empty())
	{
		aux = queue.front();
		queue.pop();
		if (aux->get_left())
			queue.push(aux->get_left());
		if (aux->get_right())
			queue.push(aux->get_right());
		delete aux;
	}
	this->root = nullptr;
	this->amount = 0;
}

bool BinaryTree::is_perfect()
{
	if (!this->root)
		return false;
	if (!this->root->get_left() && !this->root->get_right())
		return true;
	std::queue<Node*> queue;
	queue.push(this->root);
	Node* aux;
	int level = 0, expected_nodes_per_level, expected_nodes_added, nodes_added;

	while (!queue.empty())
	{
		expected_nodes_per_level = 1 << level;
		expected_nodes_added = 1 << (level + 1);
		nodes_added = 0;
		for (int i = 0; i < expected_nodes_per_level; i++)
		{
			aux = queue.front();
			queue.pop();
			if (aux->get_left())
			{
				queue.push(aux->get_left());
				nodes_added++;
			}
			if (aux->get_right())
			{
				queue.push(aux->get_right());
				nodes_added++;
			}
		}
		if (nodes_added != expected_nodes_added)
			return false;
		level++;
	}
	return true;
}

int BinaryTree::get_amount() { return this->amount; }

Node* BinaryTree::get_root() { return this->root; }