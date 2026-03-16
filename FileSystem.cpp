#include "FileSystem.h"

FileSystem::FileSystem() {
    root = new Node("root");
    current = root;
}

void FileSystem::mkdir(string name) {

    if(current->children.count(name)) {
        cout<<"Directory already exists\n";
        return;
    }

    Node* folder = new Node(name,false);
    folder->parent = current;

    current->children[name] = folder;
}

void FileSystem::touch(string name) {

    if(current->children.count(name)) {
        cout<<"File already exists\n";
        return;
    }

    Node* file = new Node(name,true);
    file->parent = current;

    current->children[name] = file;
}

void FileSystem::ls() {

    for(auto &child : current->children) {

        if(child.second->isFile)
            cout<<"[FILE] ";
        else
            cout<<"[DIR] ";

        cout<<child.first<<endl;
    }
}

void FileSystem::cd(string name) {

    if(name=="..") {
        if(current->parent!=nullptr)
            current = current->parent;
        return;
    }

    if(!current->children.count(name)) {
        cout<<"Directory not found\n";
        return;
    }

    Node* next = current->children[name];

    if(next->isFile) {
        cout<<"Cannot cd into file\n";
        return;
    }

    current = next;
}

void FileSystem::pwd() {

    vector<string> path;

    Node* temp = current;

    while(temp!=nullptr) {
        path.push_back(temp->name);
        temp = temp->parent;
    }

    for(int i=path.size()-1;i>=0;i--) {
        cout<<path[i];
        if(i!=0)
            cout<<"/";
    }

    cout<<endl;
}

void FileSystem::rm(string name) {

    if(!current->children.count(name)) {
        cout<<"File or directory not found\n";
        return;
    }

    Node* node = current->children[name];

    current->children.erase(name);

    delete node;

    cout<<"Deleted "<<name<<endl;
}

void FileSystem::dfsSearch(Node* node,string name) {

    if(node->name==name)
        cout<<"Found: "<<name<<endl;

    for(auto &child:node->children)
        dfsSearch(child.second,name);
}

void FileSystem::findFile(string name) {

    dfsSearch(root,name);
}

void FileSystem::printTree(Node* node,int depth) {

    for(int i=0;i<depth;i++)
        cout<<"  ";

    cout<<node->name<<endl;

    for(auto &child:node->children)
        printTree(child.second,depth+1);
}

void FileSystem::tree() {

    printTree(root,0);
}

void FileSystem::renameNode(string oldName,string newName) {

    if(!current->children.count(oldName)) {
        cout<<"File not found\n";
        return;
    }

    Node* node = current->children[oldName];

    current->children.erase(oldName);

    node->name = newName;

    current->children[newName] = node;

    cout<<"Renamed successfully\n";
}

int FileSystem::calculateSize(Node* node) {

    int total = node->size;

    for(auto &child:node->children)
        total += calculateSize(child.second);

    return total;
}

void FileSystem::diskUsage() {

    cout<<"Disk Usage: "<<calculateSize(current)<<" units"<<endl;
}

void FileSystem::help() {

    cout<<"Available commands:\n";
    cout<<"mkdir <name>\n";
    cout<<"touch <file>\n";
    cout<<"ls\n";
    cout<<"cd <dir>\n";
    cout<<"cd ..\n";
    cout<<"pwd\n";
    cout<<"rm <name>\n";
    cout<<"tree\n";
    cout<<"find <name>\n";
    cout<<"rename <old> <new>\n";
    cout<<"du\n";
    cout<<"help\n";
    cout<<"exit\n";
}