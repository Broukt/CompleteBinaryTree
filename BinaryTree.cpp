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