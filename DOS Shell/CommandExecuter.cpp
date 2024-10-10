#include "CommandExecuter.h"
#include "LOAD_DATA.h"
#include "TREE.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
CommandExecuter::CommandExecuter(LOAD_DATA load, TREE& tree, string& input)
{

	commandMap =
	{
		  {load.GetCommand(0),[&tree,input,this]() {this->Command1(tree,input); }}
		 ,{load.GetCommand(1),[ & load,&tree,input,this]() {this->Command2(load,tree,input); }}
		 ,{load.GetCommand(2),[&tree,this]() {this->Command3(tree); }}
		 ,{load.GetCommand(3),[&load,&tree,input,this]() {this->Command4(load,tree,input); }}
		 ,{load.GetCommand(4),[&tree,this]() {this->Command5(tree); }}
		 ,{load.GetCommand(5),[&tree,this]() {this->Command6(tree); }}
			 ,{load.GetCommand(6),[&tree,input,this]() {this->Command7(tree,input); }}
					  
	};
}
void CommandExecuter::Command1(TREE & t,string input)
{

	size_t position = input.find(' ');
	this->fileName = input.substr(position+1, input.size());
	NODE* temp = t.GetChildren(fileName);
	if (temp != nullptr)
	{
		t.SetCurrent(temp);

	}
	else
	{
		cout << "The system cannot find the path specified." << endl;
	}
}  

void CommandExecuter::Command2(LOAD_DATA &load,TREE &tree, string input)
{
	string folderName = input.substr(6, input.size());
	tree.AddFolder( folderName);
	LOAD_DATA::WriteChild(tree.GetCurrent(), folderName,"");
}

void CommandExecuter::Command3(TREE t)
{

	t.GetCurrent()->PrintAll();
}

void CommandExecuter::Command4(LOAD_DATA & load,TREE &tree, string input)
{
	size_t text_length_start = input.find(' ');
	size_t text_length_end = input.find('>');

	this->text = input.substr(text_length_start, text_length_end - text_length_start);


	if (text_length_start != string::npos)
	{
		
		this->fileName = input.substr(text_length_end + 2, input.length());
		tree.AddFile(text, this->fileName);
		LOAD_DATA::WriteChild(tree.GetCurrent(), "", this->fileName);

	}
}

void CommandExecuter::Command5( TREE & tree)
{
	NODE* temp = tree.GetCurrent()->GetParent();

	if (temp != nullptr)
	{
		tree.SetCurrent(temp);
	}
}
void CommandExecuter::Command6(TREE& tree)
{
	
	tree.SetCurrent(tree.GetRoot());
}

void CommandExecuter::Command7(TREE& tree, const string & input)
{
	string command = ExractCommand(input);
	string input1 = input.substr(command.size()+1, input.size());
	string src = input1.substr(0, input1.find(' '));
	string destination = input1.substr(input1.find(' ') + 1, input1.size());

	src = src.substr(0, src.find('.'));
	
	string source = tree.SourcePath(src);
	if (source != "")
	{
		bool destinationPath = tree.DestinationPath(source,destination);
		if (destinationPath == false)
			cout << "please enter valid destination" << endl;
		else
			cout << "file successly copied" << endl;
	}

}

string CommandExecuter::ExractCommand(const string& input)
{
	string command;
	size_t position = input.find(' ');
	if (position != string::npos)
	{
		command = input.substr(0, position);
		return command;
	}
	else {
		return input;
	}
}


bool CommandExecuter::IsCommandExist( LOAD_DATA &load,string&input)
{
	string command = ExractCommand(input);
	return load.DoesCommandExist(command);
}


void CommandExecuter::ExecuteCommand(const LOAD_DATA& load,const string&input ,TREE & tree)
{
	string command = ExractCommand(input);
   
        unordered_map<string, function<void()>>::iterator it = commandMap.find(command);
        if (it != commandMap.end())
        {
            it->second();
        }
}