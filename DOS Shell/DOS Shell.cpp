#include <iostream>
#include<string>
#include<unordered_map>
#include<functional>
// Including classes 
#include "LOAD_DATA.h"
#include "CommandExecuter.h"
#include "TREE.h"

using namespace std;

int main()
{
    
    NODE* node = new NODE("ROOT");
    TREE tree(node);
    LOAD_DATA load(tree);
    while (true)
    {
        tree.PrintPath();
        string input;
        getline(cin, input);
        CommandExecuter commandExecuter(load, tree, input);

        //echo variables
        if (commandExecuter.IsCommandExist(load, input))
        {
            commandExecuter.ExecuteCommand(load, input, tree);
        }
        else
        {
            cout << "sorry do not exist";
        }
    }
}
