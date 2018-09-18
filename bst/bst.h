//TODO: change search parameter from NODE& to int key
//TODO: change pre/postorder_traversal parameter from NODE& to int key or overload
#ifndef _BST_
#define _BST_
struct NODE
{
	int key;
	NODE *p,*r,*l; //pointers to parent, right child and left child respectively
};
class BST
{
	private:
		NODE* ROOT;
	public:
		BST();
		NODE* bst_search(const NODE& n) const; //returns pointer to node n
		NODE* bst_min(const int k) const; //returns node with minimum key in sutree rooted at node with key k
		NODE* bst_max(const int k) const; //returns node with maximum key in sutree rooted at node with key k
		NODE* bst_min(NODE&) const; //returns node with 
		NODE* bst_max(NODE&) const;
		NODE* bst_successor(const int k) const;
		NODE* bst_predecessor(const int k) const;
		bool bst_insert(const NODE&);
		bool bst_delete(const int k);
		void preorder_traversal(NODE& n) const;
		void postorder_traversal(NODE& n) const;
		void inorder_traversal(NODE& n) const;
		void preorder_traversal(int k) const;
		void postorder_traversal(int k) const;
		void inorder_traversal(int k) const;
};
#endif
