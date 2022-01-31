/*
Student Name: Joseph Nelson
Student NetID: jgn86
Compiler Used: Visual Studio
Program Description:
Parses user input to use the list class. Also sets up vector for vertices.
*/




#include "list.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using std::ifstream;

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::istream;

bool getWord(stringstream &ss, string &word)
{
  while (getline(ss,word,' '))
    {
      if (word != "") return true;
    }
  return false;
}

bool getInt(stringstream &ss, int &val)
{
  string word;
  while (getline(ss,word,' '))
    {
      if (word == "") continue;
      try {
	val = stoi(word);
      } catch (...)
	{
	  return false;
	}
      return true;
    }
  return false;
}


void processInput(istream& is, List& x, vector<int> vert, bool silent = false)
{

	string cmd = "", initial = "", final = "";
	int init = 0, fina = 0, wei = 0;
	ifstream fin;
	bool flag;
	while (1) // loop forever
	{
		flag = false;
		if (!silent) cout << ">> ";

		if (!getline(is, cmd)) return;

		stringstream cmd_to_proc(cmd);

		getWord(cmd_to_proc, cmd);

		if (cmd == "exit")
		{
			exit(0);
		}
		if (cmd == "display")
		{
			cout << "This list contains the following: " << endl;
			cout << x << endl;
			continue;
		}
		if (cmd == "load")
		{
			if (getWord(cmd_to_proc, cmd))
			{
				fin.open(cmd);
				if (fin.is_open())
				{
					processInput(fin, x, vert, true);
				}
				else
				{
					cout << "failed to open file!" << endl;
				}
				fin.close();
			}
			continue;
		}
		if (cmd == "find")
		{
			if (!getInt(cmd_to_proc, init)) continue;
			if (!getInt(cmd_to_proc, fina)) continue;

			if (x.find(init, fina))
			{
				cout << "Found! " << endl;
			}
			else
			{
				cout << "Not found!" << endl;
			}
			continue;
		}

		if (cmd == "insert")
		{
			if (!getInt(cmd_to_proc, init)) continue;
			if (getInt(cmd_to_proc, fina))
			{
				if (!getInt(cmd_to_proc, wei)) continue;
				flag = x.insert(wei, init, fina, vert);
			}
			else {

				vert.push_back(init);
			}
			if (!flag) cout << "Failed! ";
			cout << cmd << " inserted into list!" << endl;
			continue;

		}

		if (cmd == "remove")
		{
			if (!getInt(cmd_to_proc, init)) continue;
			if (getInt(cmd_to_proc, fina))
			{
				flag = x.remove(init, fina);
			}
			else {
				for (auto i = vert.begin(); i != vert.end(); ++i) {
					if (*i == init) {
						vert.erase(vert.begin() + *i);
					}
				}
			}


			if (!flag) cout << "Failed! ";
			cout << cmd << " inserted into list!" << endl;
			continue;
		}


	}
}



	  int main()
	  {
		  vector<int> vert;

		  List x;

		  processInput(cin, x, vert);
		  return 0;





	  };
