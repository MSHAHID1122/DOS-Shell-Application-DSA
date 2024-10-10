#ifndef FILES_H
#define FILES_H

#include <string>
using namespace std;
class FILES
{
private:
    string Fname;

public:
    FILES(string name);
    void CreateFile(const string& file_name);
    bool WriteFile(const string& file_name, const std::string& data);
    string GetName();
    void SetName(string name);
};

#endif // FILES_H
