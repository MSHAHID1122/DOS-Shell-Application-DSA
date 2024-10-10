#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
#include "FILES.h"

using namespace std;

class NODE {
private:
    string Nname;
    NODE* parent;
    list<NODE*> Folders;
    list<FILES> Files;

public:
    NODE(string name);
    string GetName();
    void AddFolder(NODE* node);
    void AddFile(FILES node);
    NODE* GetFolder(string name);
    string GetFile(string fileName);
    void PrintAll();
    void SetParent(NODE* node);
    NODE* GetParent() const;
    NODE* GetChild(string fileName);
};

#endif // NODE_H
