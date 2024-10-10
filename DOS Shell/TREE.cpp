#include "TREE.h"
#include "NODE.h"
#include "LOAD_DATA.h"
#include<iostream>
#include<list>
TREE::TREE(NODE*node)
{
	root = node;
	current = node;

}
void TREE::SetCurrent(NODE* node)
{
	this->current = node;
}
void TREE::SetRoot(NODE* node)
{
	this->root = node;
}
NODE* TREE::GetCurrent () const
{
	return this->current;
}
void TREE::AddFolder(string name)
{
	NODE* newNode = new NODE(name);
	newNode->SetParent(this->current);
	this->current->AddFolder(newNode);



}


string TREE::SourcePath(string src)
{
	
	try
	{
	 return	this->current->GetFile(src);
	}
	catch(runtime_error & e)
	{
		cout << "ERROR " << e.what() << endl;
		return "";
	}

}


bool TREE::DoesFolderExists(string parentFolder,string folderName)
{
	string pFolder;
	return false;
	
}
NODE* FindDestination(list<string> path,NODE*temp)
{

	if (path.size() == 1 && path.front() == "ROOT")
	{

		return temp;
	}
	bool t = true;
	int size = 0;
	auto it = path.begin();

	for (auto it = path.begin(); it != path.end(); it++)
	{

		if (*it != temp->GetName())
		{
			t = false;
			break;
		}
		else
		{

			if (size + 1 < path.size())
			{
				
				temp = temp->GetChild(*(++it));
				--it;
				if (temp == nullptr)
				{
					return nullptr;
				}

			}
			size++;
		}
	}

	     	if (t)
	     	{
	 	    	return temp;
		     }
	return nullptr;
}
bool TREE::DestinationPath(string source,string destination)
{
	if (destination == "")
		return false;
	string dest = destination;
	size_t pos = dest.find(R"(\)");
	list<string>path;
	while (pos != string::npos )
	{
		string folder = dest.substr(0, pos);
		cout << folder << endl;
		path.push_back(folder);
		dest = dest.substr(pos+1, dest.size());
		pos = dest.find(R"(\)");
	}
	if (dest.size() > 0)
	{
		path.push_back(dest);
		cout << dest << endl;
	}
	
	NODE* temp =  FindDestination(path,this->GetRoot());
	
	if (temp != nullptr)
	{
		temp->AddFile(source);
		if (temp->GetName() != "ROOT")
		{
			LOAD_DATA::WriteChild(temp,"", source);
		}
		
		return true;
	}
	return false;
}
void TREE::PrintFolders()
{
	this->root->PrintAll();
}

NODE* TREE::GetRoot()
{
	
	return this->root;
}
void TREE::AddFile(string name)
{
	FILES S(name);
	this->current->AddFile(S);
}
void TREE::AddFile( string text,string name)
{
	FILES S(name);
	S.WriteFile(name, text);
	current->AddFile(S);

}
NODE* TREE::GetChildren(string fileName)
{
	
	return this->current->GetChild(fileName);
}
	

void TREE::PrintPath()
{

	NODE* temp = this->current;
	string path = "";

	while (temp != nullptr)
	{
		cout << endl;
		
		if (temp->GetName() == "ROOT")
		{
			path = temp->GetName() +R"(:\)"+ path;
			break;
		}
		else
		{
			path = temp->GetName()+R"(\)" + path;
			temp = temp->GetParent();
		}
	}
	cout << path;

}