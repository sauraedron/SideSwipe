#include <iostream>
#include <map>
#include <string>
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
	enum TOKEN {NONE, BEGIN_u_map, END_u_map};
	TOKEN token = NONE;
	map<string, char> u_map; //unicode u_map
	u_map["<00020>"] = ' ';
	u_map["<00021>"] = '!';
//	u_map["<00022>"] = '';
	u_map["<00023>"] = '#';
	u_map["<00024>"] = '$';
	u_map["<00025>"] = '%';
	u_map["<00026>"] = '&';
	u_map["<00027>"] = '\'';
	u_map["<00028>"] = '(';
	u_map["<00029>"] = ')';
	u_map["<0002A>"] = '*';
	u_map["<0002B>"] = '+';
	u_map["<0002C>"] = ',';
	u_map["<0002D>"] = '-';
	u_map["<0002E>"] = '.';
	u_map["<0002F>"] = '/';
		u_map["<0002F>"] = 'T';
	
	


	while(getline(infile, s))
	{
		if(s.find("beginbfchar")!=std::string::npos)
		{

			token = BEGIN_u_map;
			continue;
		}
		if(s.find("endbfchar")!=std::string::npos)
		{
			token = END_u_map;
			continue;
		}
		
		if(token==BEGIN_u_map)
		{
			/*
			 * http://stackoverflow.com/questions/236129/split-a-string-in-c
			 */
		    istringstream tmp(s);
			vector<string> tok;
			copy(istream_iterator<string>(tmp), istream_iterator<string>(), back_inserter(tok));
			//{istream_iterator<string>{s}, istream_iterator<string>{}};
			cout<<tok[0]<<"\t"<<tok[1]<<endl;
			cout<<tok[0]<<"\t"<<u_map[tok[1]]<<endl;				
				  
		}
	
	}
	infile.close();
}
