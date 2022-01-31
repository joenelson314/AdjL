/*
Student Name: Joseph Nelson
Student NetID: jgn86
Compiler Used: Visual Studio
Program Description:
Class definition for the list class.
*/







#pragma once
#include "node.h"
#include <iostream>
using namespace std;
#include <vector>
#include <iterator>

class List
{
 private:
  Node *head;
  Node *findNode(int initial, int final);
 public:
 List(): head(nullptr) {}
  ~List();
  bool insert(int weight, int start, int end, vector<int>vertices);
  bool remove(int start, int end);
  bool find(int start, int end);

  friend ostream& operator<<(ostream& os, List& rhs);
  
};
