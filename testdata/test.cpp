#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	std::ifstream infile("d.pdf");
	string s = "hi";
	enum TOKEN {NONE, BEGIN_MAP, END_MAP};
	TOKEN token = NONE;
	map<string, char> u_map; //unicode map


	while(getline(infile, s))
	{
		if(s.find("beginbfchar")!=std::string::npos)
		{
			cout<<"Found";
			token = BEGIN_MAP;
		}
		if(s.find("endbfchar")!=std::string::npos)
		{
			cout<<"Found";
			token = END_MAP;
		}
		
		if(BEGIN_MAP)
		{
			
		}
	
	}
	infile.close();
}
