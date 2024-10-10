#ifndef LOAD_DATA_H
#define LOAD_DATA_H

#include <string>
#include <list>
#include "TREE.h" // Include for TREE class (replace with actual header filename)
#include "NODE.h"
using namespace std;

class LOAD_DATA {
private:
    list<string> commands;

public:
    LOAD_DATA(TREE& t);
    void LoadCommands(const string& filePath);
    void LoadData(TREE& tree, const string& path);
    bool DoesCommandExist(string cmd);
    string GetCommand(int value);
  static  void WriteChild(NODE* parent, const string& folderName, const string& fileName);
};

#endif // LOAD_DATA_H
