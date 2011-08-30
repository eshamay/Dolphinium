#include "trees.h"

node new_tree () {
	node n = new tree_t;
	n->parent = (node)NULL;
	n->left = (node)NULL;
	n->right = (node)NULL;
	return n;
}

node new_tree (val_t val) {
	node n = new_tree();
	n->value = val;
	return n;
}

void add_node (node root, node side, node n) {
	if (side == (node)NULL) {
		side = n;
		n->parent = root;
	}
	else {
		add_node (side, n);
	}
}

// adding a node means find the spot where the value goes in
// smaller or equal values go to the right, larger values to the left
void add_node (node root, node n) {
	if (n->value <= root->value) {
		if (root->right == (node)NULL) {
			root->right = n;
			n->parent = root;
		}
		else {
			add_node (root->right, n);
		}
	}
	else {
		if (root->left == (node)NULL) {
			root->left = n;
			n->parent = root;
		}
		else {
			add_node (root->left, n);
		}
	}
}


node array_to_tree (val_t * array, int size) {
	node root = new_tree (*array);
	for (int i = 1; i < size; i++) {
		add_node (root, new_tree(array[i]));
	}
	return root;
}

int print_tree_dfs (node root) {

	std::stack<node> stack;
	std::stack<int> depths;

	stack.push(root);
	depths.push(1);
	int depth = 0;
	int d;
	node n;

	while (!stack.empty()) {
		n = stack.top();
		stack.pop();
		d = depths.top();
		depths.pop();

		depth = std::max(depth, d);

		printf ("%d ", n->value);
		if (n->left != (node)NULL) {
			stack.push(n->left);
			depths.push(d+1);
		}
		if (n->right != (node)NULL) {
			stack.push(n->right);
			depths.push(d+1);
		}
	}

	return depth;
}

void print_tree_bfs (node root) {

	std::queue<node> queue;
	queue.push(root);
	node n;

	while (!queue.empty()) {
		n = queue.front();
		queue.pop();

		printf ("%d ", n->value);
		if (n->left != (node)NULL)
			queue.push(n->left);
		if (n->right != (node)NULL)
			queue.push(n->right);
	}

}




/*
	 namespace trees {

	 btn_t * BinaryTree::Search (btn_t * n, key_t& k) const {
	 btn_t * ret = (btn_t *)NULL;
	 if (n->Key() == k)
	 ret = n;
	 else if (n->Key() < k)
	 ret = BinaryTree::Search (n->Right(), k);
	 else
	 ret = BinaryTree::Search (n->Left(), k);

	 return ret;
	 }

	 btn_t * BinaryTree::Search (key_t& k) const {
	 return this->Search(root,k);
	 }

	 void BinaryTree::Insert (key_t& k) {
	 this->Insert (root, k);
	 }

	 void BinaryTree::Insert (btn_t * n, key_t& k) {
	 if (n->Key() <= k) {
	 if (n->Right() == (btn_t *)NULL) 
	 n->Right(new btn_t(k,n));
	 else
	 this->Insert(n->Right(), k);
	 }

	 else {
	 if (n->Left() == (btn_t *)NULL) 
	 n->Left(new btn_t(k,n));
	 else
	 this->Insert(n->Left(), k);
	 }
	 }


	 void BinaryTree::Delete (key_t& k) {

	 }

	 void BinaryTree::PrintTree () const {

	 std::queue<btn_t *> queue;
	 queue.push_front(root);
	 btn_t * cur;
	 while (!queue.empty()) {
	 cur = queue.back();
	 printf ("%d ->", cur->Key());

	 if (cur->Left() != (btn_t*)NULL) {
	 printf (" L-%d", cur->Left()->Key());
	 queue.push_front(cur->Left());
	 }

	 if (cur->Right() != (btn_t*)NULL) {
	 printf (" R-%d", cur->Right()->Key());
	 queue.push_front(cur->Right());
	 }

	 printf ("\n");

	 queue.pop_back();
	 }
	 }

	 }	// namespace trees
	 */




int main () {

	int array[10] = {1,6,5,3,4,2,5,4,3,8};

	node root = array_to_tree(array,10);
	printf ("\ndepth = %d\n", print_tree_dfs (root));

}
