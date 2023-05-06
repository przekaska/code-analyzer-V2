#ifndef _SIMPLE_TREE_CPP
#define _SIMPLE_TREE_CPP

#include <list>
#include <string>


class Node{
    public:
    Node *parent;
    std::list <Node*> children;

    Node addchild(Node &child){
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