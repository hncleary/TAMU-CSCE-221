#ifndef MY_MAP_H
#define MY_MAP_H

#include "BTree.h"
#include "key_value.h"
#include <iterator> 
#include <vector>
using namespace std;

template <typename T, typename E>
struct my_map
{

    class map_iter : public iterator<input_iterator_tag, key_value<T,E>>
    {   
    private:
        vector<Node<key_value<T,E>>*> prev_nodes;

    public:
        Node<key_value<T,E>>* node;

        map_iter(Node<key_value<T,E>>* x) :node(x){}
        map_iter(const map_iter& iter) : node(iter.node){}
        map_iter& operator++()
        {
            //FINISH THIS FUNCTION
            //should go to the next node in the inorder traversal
            return *this;
        }
        map_iter operator++(int) {map_iter tmp(*this); operator++(); return tmp;}
        bool operator==(const map_iter& rhs) const {return node == rhs.node;}
        bool operator!=(const map_iter& rhs) const {return node != rhs.node;}
        key_value<T,E>& operator*() {return node->value;}

    private:
        void go_to_begining();
        Node<key_value<T,E>>* find_next(Node<key_value<T,E>>* curr);
        Node<key_value<T,E>>* find_smallest_child(Node<key_value<T,E>>* curr);
        bool is_node_in_prev_nodes(Node<key_value<T,E>>* curr);
    };


    BTree<key_value<T, E>> container;

    my_map() : container() { }
    my_map(const my_map<T, E>& other);
    my_map<T, E>& operator=( const my_map<T, E>& other );

    E& operator[](T search_key);

    map_iter begin()
    {
        //FINISH THIS FUNCTION
        //should return the first node in the inorder traversal
        return map_iter(NULL);
    }

    map_iter end()
    {
        return map_iter(NULL);
    }
};

template <typename T, typename E>
ostream& operator<<(ostream& out, const my_map<T, E>& map)
{
    return out;
}

template <typename T, typename E>
my_map<T,E>::my_map(const my_map<T, E>& other)
    :   container(other.container)   
{}

template <typename T, typename E>
my_map<T, E>& my_map<T,E>::operator=( const my_map<T, E>& other )
{
    container(other.container);
}

template <typename T, typename E>
E& my_map<T,E>::operator[](T search_key)
{
    //FINISH THIS FUNCTION
    //this should search for search_key
    //if it doesent find it, then insert a new key_value into the tree
    return *(new E());
}

template <typename T, typename E>
Node<key_value<T,E>>* my_map<T,E>::map_iter::find_next(Node<key_value<T,E>>* curr)
{
    //this should find the next node in the inorder traversal
}

template <typename T, typename E>
bool my_map<T,E>::map_iter::is_node_in_prev_nodes(Node<key_value<T,E>>* curr)
{
    //this should check if a node has already been visited
    //you can do this with the prev nodes vector, or find a faster way
}

template <typename T, typename E>
void my_map<T,E>::map_iter::go_to_begining()
{
    //this will go to the beginning of the inorder traversal
}

template <typename T, typename E>
Node<key_value<T,E>>* my_map<T,E>::map_iter::find_smallest_child(Node<key_value<T,E>>* curr)
{
    //this function finds the smallest child of curr
    return NULL;
}

#endif