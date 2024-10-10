#include "LOAD_DATA.h"
#include "TREE.h"
#include<string>
#include<list>
#include <fstream>
#include<iostream>

LOAD_DATA::LOAD_DATA(TREE & tree)
{
	LoadCommands("commands.txt");
	LoadData(tree,"data.txt");
}

void LOAD_DATA::LoadCommands(const string& FilePath)
{
	ifstream ReadFile(FilePath);
	string line;
	while (getline(ReadFile, line)) 
	{
		commands.push_back(line);
		
	}
}
bool LOAD_DATA::DoesCommandExist(string cmd)
{
	for (string command : commands)
	{
		if (cmd == command)
			return true;
	}
	return false;
}

string LOAD_DATA::GetCommand(int value)
{ 
	int index = 0;
	for (auto command : commands)
	{
		if (index == value)
		{
			
			return command;
		}
		index++;
  }
	return "cd";

}

void LOAD_DATA::LoadData(TREE& tree, const string& path)
{


	list<string> data;
	ifstream myfile("data.txt");
	string line;
		
	
	while (getline(myfile, line))
	{
		data.push_back(line);
		
	}

	cout << endl;

	int index = 0;
	for (auto it : data)
	{
		int size1 = it.size();
		size_t position1 = it.find(';');
		size_t position3 = it.find('!');
		

		string parent_folder = it.substr(0, position1);
	

		string childrenFolders = "";
		string childrenFiles = "";


		 childrenFolders= it.substr(position1 + 1, position3 - position1 - 1);
		 childrenFiles = it.substr(position3 + 1, it.size() - position3 - 1);

		

	
		
		if(parent_folder!="ROOT")
		{
		
			

			NODE* temp = tree.GetChildren(parent_folder);
			if (temp == nullptr)
			{

				break;
			}
			
			tree.SetCurrent(temp);
		}

			string f1 = "";
			size_t p1 = childrenFolders.find(',');
			while (p1 != string::npos)
			{
				
				f1= childrenFolders.substr(0, p1);
				cout << endl;

				tree.AddFolder(f1);
				childrenFolders = childrenFolders.substr(p1+1, childrenFolders.size() - p1 - 1);
				p1 = childrenFolders.find(',');
			}
			if (childrenFolders != "")
			{
				tree.AddFolder(childrenFolders);
			}
			

			string f2 = childrenFiles;
			size_t p2 = childrenFiles.find(',');
			while (p2 != string::npos)
			{
				f2 = childrenFiles.substr(0, p2);
				tree.AddFile(f2);
				childrenFiles = childrenFiles.substr(p2+1, childrenFiles.size() - p2 - 1);
				p2 = childrenFiles.find(',');
			}
			if (childrenFiles != "")
			{
				tree.AddFile(childrenFiles);
			}

		

			
	  }// FOR LOOP ENDS 
	tree.SetCurrent(tree.GetRoot());
	}  


void LOAD_DATA::WriteChild( NODE*  parent, const string& folderName ,const string & fileName)
{
	
	ifstream myfile("data.txt");
	string line;
	list<string> mylist;
	while (getline(myfile, line))
	{
		mylist.push_back(line);
	}
	bool isFound = false;
	int index = 0;
	for (string& it : mylist)
	{






		size_t listSize = mylist.size();
		size_t position = it.find(';');
		size_t position1 = it.find('!');
		string folder = it.substr(0, position);
		if (parent->GetName() == folder)
		{
	
			if (folderName == "")
			{
				
				if (position1 != std::string::npos)
				{
					it += ',' + fileName;
				}
				else
				{
					it += '!' + fileName;
				}
				isFound = true;

				break;
			}

			if (position == std::string::npos)
			{
				if (fileName == "")
				{
					it = it + ',' + folderName;
				}
				else
					it = it + ';' + fileName;
				isFound = true;

				break;
			}
			else
			{
				string str = it.substr(0, position);
				string str1 = it.substr(position + 1, position1 - position - 1);
				string str2 = it.substr(position1 + 1, it.size());
				if (position1 == std::string::npos)
					str2 = "";

				if (str1.size() == 0)
				{
					str1 += folderName + '!';
				}
				else
				{
					str1 += ',' + folderName + '!';
				}

				it = str + ';' + str1 + str2;
				isFound = true;

				break;
			}
			break;
		}
		index++;
		if (index == listSize)
		{
			if (isFound == false)
			{
				if (fileName == "")
					mylist.push_back(parent->GetName() + ';' + folderName);
				else
					mylist.push_back(parent->GetName() + ";" + "!" + fileName);
			}
			break;
		}
	}// FOR LOOOP ENDING HERE
	





	myfile.close();
	ofstream writefile;
	writefile.open("data.txt",std::ios::out);
	for (auto it : mylist)
	{
		writefile << it << endl;
   }
	writefile.close();
	
	
}