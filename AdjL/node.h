/*
Student Name: Joseph Nelson
Student NetID: jgn86
Compiler Used: Visual Studio
Program Description:
Node class definition.
*/






#pragma once
#include <string>
using std::string;
class Node
{
 public:
	 int wgt;
	int initial;
  int final;
  Node *prev;
  Node *next;
 Node(int wgt,int initial, int final, Node *prev, Node *next): wgt(wgt), initial(initial), final(final), prev(prev), next(next) {}
 Node(): Node(0,0,0,nullptr,nullptr) {}
};
