#ifndef COMMANDEXECUTER_H
#define COMMANDEXECUTER_H

#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>
#include "LOAD_DATA.h" // Include for LOAD_DATA class (replace with actual header filename)
#include "TREE.h"      // Include for TREE class (replace with actual header filename)

using namespace std; // Using directive to avoid std:: prefixes
class CommandExecuter
{
private:

	string fileName = "";
	string text = "";
	unordered_map<string, function<void()>>commandMap;
public:
	CommandExecuter(LOAD_DATA load_data,TREE &tree,string &input);
	void Command1(TREE & t, string input);
	void Command2( LOAD_DATA  &load,TREE& tree, string input);
	void Command3(TREE t);
	void Command4(LOAD_DATA & load,TREE&tree, string input);
	void Command5(TREE& tree);
	void Command6(TREE & tree);
	void Command7(TREE& tree,const string& input);

	string ExractCommand(const string& input);
	bool IsCommandExist(LOAD_DATA& load, string& command);
	void ExecuteCommand(const LOAD_DATA & load, const string& input, TREE& tree);
	void ExecuteCD(TREE &t, const string& input);

};

#endif // COMMANDEXECUTER_H
