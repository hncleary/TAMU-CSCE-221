#include<cstddef>
using namespace std;

class BinaryNode{

private:
	friend class BinarySearchTree;
	int Key;
	int SearchCost;
	BinaryNode *left, *right;
public:
	BinaryNode(int key = 0, int cost = 0, BinaryNode *lt = NULL, BinaryNode *rt = NULL):
		Key(key),SearchCost(cost),left(lt), right(rt){}
	BinaryNode *getleft() {return left;}
	BinaryNode *getright() {return right;}
};