typedef int val_t;

typedef struct {
	val_t value;
	struct SingleListNode * next;
} SingleListNode;


class SingleLinkedList {
	protected:
		SingleListNode * root;
	public:
		SingleLinkedList () { }
		void push (SingleListNode * n);
		val_t pop ();
		void reverse ();
};
