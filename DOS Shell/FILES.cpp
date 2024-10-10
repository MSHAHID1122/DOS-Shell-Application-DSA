#include "FILES.h"
#include<fstream>

FILES::FILES(string name)
{
	FILES::CreateFile(name);
	Fname = name;
}
void FILES::CreateFile(const string& file_name)
{
	ofstream newFile(file_name);
	newFile.close();
}

bool FILES::WriteFile(const string& file_name,const string &data)
{
	ofstream File(file_name,ios::app);
	File << data << endl;
	File.close();
	return true;
}
string FILES::GetName()
{
	return Fname;
}
void FILES::SetName(string name)
{
	Fname = name;
}