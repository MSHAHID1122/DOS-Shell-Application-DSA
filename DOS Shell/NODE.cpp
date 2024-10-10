#include "NODE.h"
#include<iostream>
NODE::NODE(string name)
{
	Nname = name;
	this->parent = nullptr;

}

string NODE::GetName()
{
	return this-> Nname;
}
void NODE::AddFolder(NODE* node)
{
	Folders.push_back(node);
}

void NODE::AddFile(FILES node)
{
	Files.push_back(node);
}

string NODE::GetFile(string fileName)
{
	for (FILES it : Files)
	{
		if(it.GetName()==fileName)
		return it.GetName();
	}
	throw runtime_error("SOURCE FILE NOT FOUND");

}
NODE* NODE::GetFolder(string name)
{
	
	for (auto folder : Folders)
	{
		if (folder->GetName() == name)
		{
			return folder;
		}
	}
	return NULL;
}
void NODE::PrintAll ()
{
	if (Folders.empty()&& Files.empty())
	{
		cout << "NO FILES FOUND" << endl;
	}
	for (auto folder : Folders)
	{
		cout << folder->GetName() << "  DIR" << endl;
	}
	for (auto files : Files)
	{
		cout << files.GetName() << "   .txt" << endl;
	}
}
NODE* NODE::GetChild( string fileName)
{

	for (auto child : Folders)
	{
		if(child->GetName()==fileName)
		{
			
			return child;
		}
	}
	return nullptr;
}

void NODE::SetParent(NODE* node)
{
	this->parent = node;
}
NODE* NODE::GetParent()const {
	return this->parent;
}