#include "trees.h"

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

	std::list<btn_t *> queue;
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

using namespace trees;

int main () {

  trees::key_t k = 5;
  trees::BinaryTree * tree = new BinaryTree(k); 
  k = 12;
  tree->Insert(k);

  tree->PrintTree();
  return 0;
}
