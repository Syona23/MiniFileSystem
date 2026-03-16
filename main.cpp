#include "FileSystem.h"

int main() {

    FileSystem fs;

    string command;

    cout<<"Mini File System Simulator\n";
    cout<<"Type 'help' to see commands\n";

    while(true) {

        cout<<"fs> ";
        cin>>command;

        if(command=="mkdir") {

            string name;
            cin>>name;
            fs.mkdir(name);
        }

        else if(command=="touch") {

            string name;
            cin>>name;
            fs.touch(name);
        }

        else if(command=="ls") {

            fs.ls();
        }

        else if(command=="cd") {

            string name;
            cin>>name;
            fs.cd(name);
        }

        else if(command=="pwd") {

            fs.pwd();
        }

        else if(command=="rm") {

            string name;
            cin>>name;
            fs.rm(name);
        }

        else if(command=="tree") {

            fs.tree();
        }

        else if(command=="find") {

            string name;
            cin>>name;
            fs.findFile(name);
        }

        else if(command=="rename") {

            string a,b;
            cin>>a>>b;
            fs.renameNode(a,b);
        }

        else if(command=="du") {

            fs.diskUsage();
        }

        else if(command=="help") {

            fs.help();
        }

        else if(command=="exit") {

            break;
        }

        else {

            cout<<"Unknown command\n";
        }
    }

    return 0;
}