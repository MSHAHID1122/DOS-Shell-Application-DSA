#ifndef TREE_H
#define TREE_H

#include "NODE.h"
#include "FILES.h"

using namespace std;

class TREE {
private:
    NODE* root;
    NODE* current;

public:
    TREE(NODE* node);
    void AddFolder(string name);
    void PrintFolders();
    void AddFile(string name);
    void AddFile(string text, string name);
    void SetRoot(NODE* node);
    NODE* GetCurrent() const;
    string SourcePath(string src);
    bool DoesFolderExists(string parentFolder, string folderName);
    bool DestinationPath(string source, string destination);
    FILES getFile(string fileName);
    void SetCurrent(NODE* node);
    NODE* GetChildren(string fileName);
    void PrintPath();
    NODE* GetRoot();
};

#endif // TREE_H
