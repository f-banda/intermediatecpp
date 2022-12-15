/********************************************************************
CSCI 241 - Assignment 11 - Fall 2020

Name: Francisco Banda
Section:   2
TA:        Abhinay Gattu & Farnaz Tabrizi Miandoab

Purpose:   Implement the map ADT using a binary search tree. Using
template structure to represent a tree node, and a template class
to represent the tree. 
*********************************************************************/

#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

// node structure
// describes a "node" in a tree
template <class K, class V>
struct node
{
	K key;
	V value;
	node<K, V>* left_child;
	node<K, V>* right_child;

	node(K _key, V _value, node<K, V>* left = nullptr, node<K, V>* right = nullptr)
	{
		key = _key;
		value = _value;
		left_child = left;
		right_child = right;
	}
};


template <class K, class V>
class bstree
{
private:
	node<K, V>* root_node;
	size_t tree_size;

	// copy_tree(node<K, V>* root_node) method: recursive routine that starting from a root node allocates and copies each of its node contents into a new tree
	// returns the root node of the new tree
	node<K, V>* copy_tree(node<K, V>* root_node)
	{
		if (root_node == nullptr)
			return nullptr;

		return new node<K, V>(root_node->key, root_node->value,
			copy_tree(root_node->left_child),
			copy_tree(root_node->right_child)
			);
	}

	// free_tree(node<K, V>* root_node) method: recursive routine that starting from a root node free all the allocated nodes in the tree
	void free_tree(node<K, V>* root_node)
	{
		if (root_node == nullptr)
			return;

		free_tree(root_node->left_child);
		free_tree(root_node->right_child);

		delete root_node;
	}

	// find_min_in_tree(node<K, V>* root_node) method: recursive routine that traverse a tree starting from a root node and find the node with the minimum key value
	// returns the node describing the minimum key value
	node<K, V>* find_min_in_tree(node<K, V>* root_node)
	{
		if (root_node == nullptr)
			return nullptr;

		node<K, V>* curr_node = root_node;
		node<K, V>* left_node_min = find_min_in_tree(root_node->left_child);
		node<K, V>* right_node_min = find_min_in_tree(root_node->right_child);

		if (left_node_min &&
			left_node_min->key < curr_node->key)
			curr_node = left_node_min;

		if (right_node_min &&
			right_node_min->key < curr_node->key)
			curr_node = right_node_min;

		return curr_node;
	}

	// find_max_in_tree(node<K, V>* check_node) method: recursive routine that traverse a tree starting from a root node and find the maximum key value
	// returns the node describing the maximum key value
	node<K, V>* find_max_in_tree(node<K, V>* root_node)
	{
		if (root_node == nullptr)
			return nullptr;

		node<K, V>* curr_node = root_node;
		node<K, V>* left_node_max = find_max_in_tree(root_node->left_child);
		node<K, V>* right_node_max = find_max_in_tree(root_node->right_child);

		if (left_node_max &&
			left_node_max->key > curr_node->key)
			curr_node = left_node_max;

		if (right_node_max &&
			right_node_max->key > curr_node->key)
			curr_node = right_node_max;

		return curr_node;
	}

	// insert_node_in_tree(node<K, V>* root_node, K key, V value) method: recursive routine that starting from a given root node finds the appropiate parent of the new node to insert
	// returns the root node of the tree after the operation
	node<K, V>* insert_node_in_tree(node<K, V>* root_node, K key, V value)
	{
		if (root_node == nullptr)
			return new node<K, V>(key, value);

		if (key < root_node->key)
			root_node->left_child = insert_node_in_tree(root_node->left_child, key, value);
		else
			root_node->right_child = insert_node_in_tree(root_node->right_child, key, value);

		return root_node;
	}

	// delete_node_in_tree(node<K, V>* root_node, K key) method: recursive routine that starting from a given root node, search the node to be deleted by the given "key" parameter and delete it from the tree; then, re-balance the nodes of the tree
	// returns the root node of the tree after the operation
	node<K, V>* delete_node_in_tree(node<K, V>* root_node, K key)
	{
		if (root_node == nullptr)
			return nullptr;

		// binary search in the tree
		if (key < root_node->key)
			root_node->left_child = delete_node_in_tree(root_node->left_child, key);

		else if (key > root_node->key)
			root_node->right_child = delete_node_in_tree(root_node->right_child, key);

		else
		{
			// node found
			
			// if both left child and right child are null, the parent node pointing to this node must be null, so we return nullptr
			if (root_node->left_child == nullptr &&
				root_node->right_child == nullptr)
			{
				delete root_node;
				return nullptr;
			}

           
			else if (root_node->left_child == nullptr)
			{
				node<K, V>* temp_node = root_node->right_child;
				delete root_node;
				return temp_node;
			}

			else if (root_node->right_child == nullptr)
			{
				node<K, V>* temp_node = root_node->left_child;
				delete root_node;
				return temp_node;
			}

            // both nodes are valid (left & right)
			
			// find the outer-right node starting from the left node of the found one to be deleted
			node<K, V>* most_right_node = root_node->left_child;
			while (most_right_node &&
				   most_right_node->right_child != NULL)
				   most_right_node = most_right_node->right_child;

			// copy the content of the just found outer-right node into the found node to be deleted
			root_node->key = most_right_node->key;
			root_node->value = most_right_node->value;

			// find and delete (using as new root node the inorder successor) the outer-right node that now this node is describing
			root_node->left_child = delete_node_in_tree(root_node->left_child, most_right_node->key);
		}

		return root_node;
	}

	// get_height_tree(node<K, V>* root_node) method: starting from a given root node, calculates the height of its tree
	// returns the height of the tree
	size_t get_height_tree(node<K, V>* root_node) const
	{
		if (root_node == nullptr)
			return 0;

		size_t left_height = get_height_tree(root_node->left_child);
		size_t right_height = get_height_tree(root_node->right_child);

		if (left_height > right_height)
			return left_height + 1;

		return right_height + 1;
	}

	// print_tree_inorder(node<K, V>* root_node) method: starting from a given root node, print out its content while being traversed with the inorder algorithm
	void print_tree_inorder(node<K, V>* root_node) const
	{
		if (root_node == nullptr)
			return;

		print_tree_inorder(root_node->left_child);

		std::cout << root_node->key << ": " << root_node->value << std::endl;

		print_tree_inorder(root_node->right_child);
	}

	// print_tree_preorder(node<K, V>* root_node) method: starting from a given root node, print out its content while being traversed with the preorder algorithm
	void print_tree_preorder(node<K, V>* root_node) const
	{
		if (root_node == nullptr)
			return;

		std::cout << root_node->key << ": " << root_node->value << std::endl;

		print_tree_preorder(root_node->left_child);
		print_tree_preorder(root_node->right_child);
	}

	// print_tree_postorder(node<K, V>* root_node) method: starting from a given root node, print out its content while being traversed with the postorder algorithm
	void print_tree_postorder(node<K, V>* root_node) const
	{
		if (root_node == nullptr)
			return;

		print_tree_postorder(root_node->left_child);
		print_tree_postorder(root_node->right_child);

		std::cout << root_node->key << ": " << root_node->value << std::endl;
	}

	// print_tree_postorder(node<K, V>* root_node, size_t level) method: starting from a given root node, print out the content present at the level specified by variable "level"
	void print_tree_level(node<K, V>* root_node, size_t level) const
	{
		if (root_node == nullptr)
			return;

		if (level == 1)
		{
			std::cout << root_node->key << ": " << root_node->value << std::endl;
			return;
		}

		print_tree_level(root_node->left_child, level - 1);
		print_tree_level(root_node->right_child, level - 1);
	}

public:
	// standard constructor
	bstree()
	{
		root_node = nullptr;
		tree_size = 0;
	};

	// copy constructor
	bstree(const bstree<K, V>& x)
	{
		this->root_node = copy_tree(x.root_node);
		this->tree_size = x.tree_size;
	};

	// destructor
	// wrapper to clear() method
	~bstree()
	{
		clear();
	};

	// assign overload operator
	// skip the assign if it's a self assignment
	// otherwise, make a copy of the tree described by the "x" parameter
	bstree<K, V>& operator=(const bstree<K, V>& x)
	{
		if (this != &x)
		{
			clear();
			this->root_node = copy_tree(x.root_node);
			this->tree_size = x.tree_size;
		}
		return *this;
	};

	// clear() method 
	void clear()
	{
		free_tree(root_node);
		root_node = nullptr;
		tree_size = 0;
	};

	// size() method: returns the number of elements described by the tree
	size_t size() const
	{
		return tree_size;
	}

	// height() method: returns the height of the tree
	size_t height() const
	{
		return get_height_tree(root_node);
	}

	// empty() method: returns true if the tree is empty, false otherwise
	bool empty() const
	{
		return tree_size == 0;
	}

	// min() method: returns a reference to the node's minimum key value in the tree described by the root_node data member
	const K& min()
	{
		return find_min_in_tree(root_node)->key;
	}

	// max() method: returns a reference to the node's maximum key value in the tree described by the root_node data member
	const K& max()
	{
		return find_max_in_tree(root_node)->key;
	}

	// insert(const K& key, const V& value) method: search in the tree described by the root_node data member an element that match the value described by the "key" parameter and deletes it
	bool insert(const K& key, const V& value)
	{
		if (find(key))
			return false;

		root_node = insert_node_in_tree(root_node, key, value);
		tree_size++;

		return true;
	}

	// remove(const K& key) method: search in the tree described by the root_node data member an element that match the value described by the "key" parameter and deletes it
	// returns false if not found, deletes the found node and return true if otherwise
	bool remove(const K& key)
	{
		// preliminary check for existence
		const node<K, V>* node_in_tree = find(key);
		if (node_in_tree == nullptr)
			return false;

		// remove the node from the tree and calculate the new root node
		root_node = delete_node_in_tree(root_node, key);

		// decrease the tree size
		tree_size--;

		return true;
	}

	// find(const K& key) method: search in the tree described by the root_node data member an element that match the value described by the "key" parameter
	// returns the found node, or nullptr if not
	const node<K, V>* find(const K& key)
	{
		node<K, V>* curr_node = root_node;

		while (curr_node != nullptr)
		{
			if (curr_node->key == key)
				return curr_node;

			else if (key < curr_node->key)
				curr_node = curr_node->left_child;
			else
				curr_node = curr_node->right_child;
		}

		return nullptr;
	}

	// preorder() method: wrapper to print_tree_preorder() private recursive method
	void preorder() const
	{
		print_tree_preorder(root_node);
	}

	// inorder() method: wrapper to print_tree_inorder() private recursive method
	void inorder() const
	{
		print_tree_inorder(root_node);
	}

	// postorder() method: wrapper to print_tree_inorder() private recursive method
	void postorder() const
	{
		print_tree_postorder(root_node);
	}

	// level_order() method: calculates the height of the tree described by the root_node data member and for each level, print the content of the nodes
	void level_order() const
	{
		size_t tree_height = height();

		for(size_t i = 1; 
			i<= tree_height;
			i++)
			print_tree_level(root_node, i);
	}
};

#endif