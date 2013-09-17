/* 
	Author: Cesar Murillas
	ID: 0438950
	Application Security Fall 2013
	Assignment #1: Turing Complete Sandbox
	
	
	The Blacklist.txt file contains all of the keywords that will be filtered out by this sandbox.
	There will be no file operations allowed.
	There will be no pointers allowed as well as other keywords dealing with memory management.
	To use the multiplication operation: use the following example:
	
						int s = 10;
						int n = 3;
						int res = s;
						for(size_t i = 1; i < n; i++)
						{
							res+=s;
							
						}
*/

#include<iostream>
#include<string>
#include <fstream>
#include <vector>

using namespace std;
vector<string> fillBlackList(vector<string>& v, char* c)
{
	string stringy;
	ifstream ifs;
	ifs.open(c);
	while(!ifs.eof())
	{
		getline(ifs,stringy);
		v.push_back(stringy);
		
	}
	
	return v;

}

int main(int argc, char* argv[])
{

		vector<string> checkme, blackList;
		// Get the name of the program to run, and the name of the output file, and path to blacklist
		if ( argc != 4 ) 
		{
	    	cout<<"Usage: "<< argv[0] <<" <Input Filename> " << "<Output Filename>" << " <Blacklist Filename>" << endl;
	    	exit(-1);
	    }
		
		// Fill up the blackList with specific keywords from a file
		blackList = fillBlackList(blackList, argv[3]);
	
		// Making all of the necessary strings for system calls
		char prgm[256] = "g++ ";
		char output [256] = "./";
		strcat (prgm,argv[1]);
		strcat(prgm, " -o ");
		strcat(prgm, argv[2]);
		strcat(output, argv[2]);
		
		
		// This guy will tell us whether to run our code or not.
		int run = 0; 		
		string stringy;
		
		ifstream ifs;
		ifs.open (argv[1]);
		if(!ifs.is_open())
		{
			cerr << "FILE NOT FOUND, Please try again"<< endl;
			exit(-1);
		}
	    while(!ifs.eof())
	    {
			getline(ifs,stringy);
			checkme.push_back(stringy);
	    }
	    
		ifs.close();
		size_t pos;
		
		// Check for keywords that we do not want to allow!
		for(int j  = 0; j < blackList.size(); j++)
		{
			for(int i =0; i< checkme.size();i++)
			{
				pos = checkme[i].find(blackList[j]);
				if (pos != string::npos)
				{
					run = 1;
				}
			}
		}	
		if (run == 0)
		{ 
			system(prgm);
			system(output);
		}
		else cout << "You have tried to execute code that is not allowed, Please try again" << endl;


}