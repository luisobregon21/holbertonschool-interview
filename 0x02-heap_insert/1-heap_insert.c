#include "binary_trees.h"
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *insert_n_ordered(binary_tree_t *tree, int value, int idx, int n_leaf);

/**
 * heap_insert - Insert a node into a Max binary heap
 * @root: Type heap_t pointer of the parent node
 * @value: Type int of value inserted into node
 * Return: Node inserted
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	int tree_size = 0;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	tree_size = binary_tree_size(*root) + 1;
	node = insert_n_ordered(*root, value, 0, tree_size);
	while (node->parent && node->n > node->parent->n)
	{
		node->n = node->parent->n;
		node->parent->n = value;
		node = node->parent;
	}
	return (node);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of th tree to measure the size
 * Return: Size of Tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * insert_n_ordered - Inserts order node
 * @tree: pointer of the parent node of the node to create
 * @value: value to put in the inserted node
 * @idx: index of the node
 * @n_leaf: postion of node array (parent formula: idx / 2)
 * Return: Node inserted
 */
heap_t *insert_n_ordered(binary_tree_t *tree, int value, int idx, int n_leaf)
{
	heap_t *node;

	if (tree == NULL)
	{
		return (NULL);
	}

	if (idx + 1 == n_leaf / 2)
	{
		if (n_leaf & 1)
		{
			tree->right = binary_tree_node(tree, value);
			return (tree->right);
		}
		else
		{
			tree->left = binary_tree_node(tree, value);
			return (tree->left);
		}
	}
	node = insert_n_ordered(tree->left, value, 2 * idx + 1, n_leaf);

	if (node != 0)
	{
		return (node);
	}
	return (insert_n_ordered(tree->right, value, 2 * idx + 2, n_leaf));
}
