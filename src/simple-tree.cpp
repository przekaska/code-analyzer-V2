#ifndef _SIMPLE_TREE_CPP
#define _SIMPLE_TREE_CPP

#include <list>
#include <iostream>


class Node{
    public:
    std::string name;
    Node *parent;
    std::list <Node*> children;

    Node(std::string new_name){
        name = new_name;
    }

    Node addchild(Node &child){
        child.parent = this;
        children.push_back(&child);
        return child;
    }

    Node createchild(std::string name){
        Node child(name);
        child.parent = this;
        children.push_back(&child);
        return child;
    }

    Node setparent(Node &new_parent){
        parent = &new_parent;
        new_parent.children.push_back(this);
        return new_parent;
    }
};




#endif