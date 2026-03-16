#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    string name;
    bool isFile;
    int size;

    Node* parent;
    unordered_map<string, Node*> children;

    Node(string name, bool isFile=false) {
        this->name = name;
        this->isFile = isFile;
        size = isFile ? 1 : 0;
        parent = nullptr;
    }
};

#endif