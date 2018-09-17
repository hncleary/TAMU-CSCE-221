#include <iostream>
#include <vector>

using namespace std;

enum color {red, black};

template <typename T>
struct Node
{
	T value;
	Node<T>* left;
	Node<T>* right;
    Node<T>* parent;

    int search_time;
    color node_color; //don't need to worry about this for the regular BTree

    Node(T val = T(), Node<T>* l = NULL, Node<T>* r = NULL, Node<T>* p = NULL, color col = color::red)
		: value(val), left(l), right(r), parent(p), search_time(0), node_color(col) {}

	Node(const Node<T>* other)
	{
		value = other.value;
		node_color = other.node_color;
		search_time = other.search_time;
	}

	bool is_leaf(){return (left == 0 && right == 0);}
};

template <typename T>
struct BTree
{
protected:
	int size;
	
public:
	Node<T>* root;

    BTree() : root(NULL),size(0){}
	BTree(const BTree<T>& other);
	BTree<T>& operator=(const BTree<T>& other);
	BTree<T>& operator=(const BTree<T> other);

	Node<T>* get_root(){return root;}
	const Node<T>* get_root() const {return root;} 
	virtual Node<T>* insert(T obj);
	Node<T>* search(T obj);
	void update_search_times();
	float get_average_search_time();
    ostream& inorder(ostream& out);
    virtual ostream& print_level_by_level(ostream& out);

private:
	void copy_helper(Node<T>* copy_to, const Node<T>* copy_from) const;
	virtual Node<T>* insert_helper(T obj, Node<T>* node);
	Node<T>* search_helper(T obj, Node<T>* node);
	ostream& inorder_helper(ostream& out, Node<T>* node);
	void update_search_times_helper(Node<T>* node, int depth);
	T get_total_search_time(Node<T>* node);
	virtual void pretty_print_node(ostream& out,Node<T>* node);
};

template <typename T>
ostream& operator<<(ostream& out, BTree<T>& tree)
{
	return out;
}

template <typename T>
ostream& operator<<(ostream& out, Node<T> node)
{
	return out << "( " << node.value << ", " << node.search_time << ", " << node.node_color << " )";
}

template <typename T>
void BTree<T>::pretty_print_node(ostream& out,Node<T>* node)
{
	out << node->value << "["<<node->search_time<<"] ";
}

//build tree
template <typename T>
istream& operator>>(istream& in, BTree<T>& tree)
{
	/*
		take input from the in stream, and build your tree
		input will look like
		4 
		2 
		6 
		1 
		3 
		5 
		7
	*/
	while (!in.eof() && !in.fail()) {
		in >> tmp;
		tree.insert(tmp);
	}
}

template <typename T>
BTree<T>::BTree(const BTree<T>& other)
{
    /*
		complete this copy constructor
		make sure when copying nodes to copy
			the value
			the relative parent, and left and right children
			the node_color
				not important for this part but will be used later
	*/
}

template <typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>& other)
{
	/*
		complete this assignment operator
		make sure when copying nodes to copy
			the value
			the relative parent, and left and right children
			the node_color
				not important for this part but will be used later
	*/
	value = other.value;

	Node * left_orig = left;
	left = new Node(*other.left);
	delete left_orig;

	Node * right_orig = right;
	right = new Node(*other.right);
	delete right_orig;

	Node * parent_orig = parent;
	parent = new Node(*other.parent);
	delete parent_orig;

	Node * color_orig = node_color;
	node_color = new Node(*node_color);
	delete node_color;

	return *this;
}
/*
template <typename T>
BTree<T>& BTree<T>::operator=(const BTree<T> other)
{
	
		complete this assignment operator
		make sure when copying nodes to copy
			the value
			the relative parent, and left and right children
			the node_color
				not important for this part but will be used later
	
}
*/

template <typename T>
void BTree<T>::copy_helper(Node<T>* copy_to, const Node<T>* copy_from) const
{
}

template <typename T>
Node<T>* BTree<T>::insert_helper(T obj, Node<T>* curr)
{ 
    return nullptr;
}

template <typename T>
Node<T>* BTree<T>::insert(T obj)
{
    /*
		insert a node into the tree
		first find where the node should go
		then modify pointers to connect your new node 
	*/
 	Node<T>* t = new Node<T>;
	Node<T>* parent;

	t->value = obj;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	if (get_root() == NULL) {
		root = t;
	}
	else {
		Node<T>* curr;
		curr = root;
		//find parent
		while (curr) {
			parent = curr;
			if (t->value > curr->value) {
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		if (t->value < parent->value) {
			parent->left = t;
		}
		else {
			parent->right = t;
		}
	}
    return nullptr;
}

template <typename T>
Node<T>* BTree<T>::search_helper(T obj, Node<T>* node)
{
    return nullptr;
}

template <typename T>
Node<T>* search(T obj)
{
	return nullptr;
}	

template <typename T>
void BTree<T>::update_search_times_helper(Node<T>* node, int depth)
{
}

template <typename T>
void BTree<T>::update_search_times()
{
}

template <typename T>
ostream& BTree<T>::inorder_helper(ostream& out, Node<T>* node)
{
    return out;
}

template <typename T>
ostream& BTree<T>::inorder(ostream& out)
{
	/*
		print your nodes in infix order
		if our tree looks like 
		4
		2 6
		1 3 5 7
		we should get
		1 2 3 4 5 6 7 
	*/
	out << "Value \t Search Cost" << endl;
	return out;
}

template <typename T>
ostream& BTree<T>::print_level_by_level(ostream& out)
{
	/*
		print the tree using a BFS 
		output should look like this if we dont have a full tree

		4
		2 6
		1 X 5 7
		X X X X X X X 9

		it will be helpfull to do this part iterativly, 
		so do the BFS with the std stack data structure.

		it may also be helpfull to put the entire tree into a vector 
		(probably google this if you dont know how to do it)
	*/
    return out;
}

template <typename T>
T BTree<T>::get_total_search_time(Node<T>* node)
{
    return T();
}

template <typename T>
float BTree<T>::get_average_search_time()
{
    return 0;
}