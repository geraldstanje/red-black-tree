#include "redblacktree.h"
#define RED true;
#define BLACK false;

RedBlackTree::RedBlackTree()
{
	node *root = NULL;
}

RedBlackTree::~RedBlackTree()
{
	cleanNode(root);
}

void RedBlackTree::add(K key,V value)
{
	root = insertHelper(key, value, root);
	root->color = BLACK;
}

V RedBlackTree::find(K key) {
	node *curr = root;
	while(curr != NULL) {
		if(key == curr->key) return curr->value;
		else if(key < curr->key) curr = curr->left;
		else curr = curr->right;
	}
	return NULL;
}

void RedBlackTree::remove(K key)
{
}

node *insertHelper(const K &key, const V &value, node *n) {
	if(n == NULL) {
		n = new node;
		n->key = key;
		n->value = value;
		n->color = RED;
		n->left = n->right = NULL;
		return n;
	}

	if(key == n->key) {
		n->value = value;
	} else if (key < n->key) {
		n->left = insertHelper(key, value, n->left);
	} else {
		n->right = insertHelper(key, value, n->right);
	}
/*
	if(n->right->color == RED && n->left->color != RED) {
		n = rotateLeft(n);
	}

	if(n->left->color == RED && n->right->color != RED) { 
		n = rotateRight(n);
	}

	if(n->left->color == RED && n->right->color == RED) {
		colorFlip(n);
	}	
*/
	return n;
}

void cleanNode(node *n) {
	if(n != NULL) {
		cleanNode(n->left);
		cleanNode(n->right);
		delete n;
	}
}