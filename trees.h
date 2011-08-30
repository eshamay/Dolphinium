#include <cstdio>
#include <list>

namespace trees {

  class BinaryTreeNode;

	class BinaryTree;


  typedef BinaryTreeNode btn_t;
  typedef int key_t; 

  class BinaryTreeNode {
	protected:
	  key_t key;
	  btn_t * parent;
	  btn_t * left;
	  btn_t * right;

	public:
	  BinaryTreeNode () : 
		parent((btn_t *)NULL), 
		left((btn_t *)NULL), 
		right((btn_t *)NULL) { }

	  BinaryTreeNode (key_t k) :
		key(k), 
		parent((btn_t *)NULL), 
		left((btn_t *)NULL), 
		right((btn_t *)NULL) { }

	  BinaryTreeNode (key_t k, btn_t * n) : 
		key(k), parent(n),
		left((btn_t *)NULL), 
		right((btn_t *)NULL) { }

	  BinaryTreeNode (key_t k, btn_t * n, btn_t * l, btn_t * r) : 
		key(k), parent(n), left(l), right(r) { }

	  key_t Key () const { return key; }

	  btn_t * Left () const { return left; }
	  btn_t * Left (btn_t * l) { left = l; }

	  btn_t * Right () const { return right; }
	  btn_t * Right (btn_t * r) { right = r; }

	  btn_t * Parent () const { return parent; }
	  btn_t * Parent (btn_t * p) { parent = p; }
  };



  class BinaryTree {
	protected:
	  btn_t * root;

	  virtual btn_t * Search (btn_t * n, key_t& k) const;
	  virtual void Insert (btn_t * n, key_t& k);

	public:
	  BinaryTree () : root(new btn_t()) { }
	  BinaryTree (key_t k) : root(new btn_t(k)) { }

	  virtual btn_t * Search (key_t& k) const;
	  virtual void Insert (key_t& k);
	  virtual void Delete (key_t& k);

	  virtual void PrintTree () const;
  };

}
