#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Node.h"

class FileSystem {

private:
    Node* root;
    Node* current;

    void dfsSearch(Node* node, string name);
    void printTree(Node* node, int depth);
    int calculateSize(Node* node);

public:
    FileSystem();

    void mkdir(string name);
    void touch(string name);
    void ls();
    void cd(string name);
    void pwd();
    void rm(string name);
    void findFile(string name);
    void tree();
    void renameNode(string oldName, string newName);
    void diskUsage();
    void help();
};

#endif