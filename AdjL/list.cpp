/*
Student Name: Joseph Nelson
Student NetID: jgn86
Compiler Used: Visual Studio
Program Description:
List class that has list of edges. Can insert, remove, and find the edges in a list.
*/







#include "list.h"
#include <string>
using std::string;

List::~List()
{
  Node *tmp = head;
  Node *curr = nullptr;
  while (tmp != nullptr)
    {
      curr = tmp;
      tmp = tmp->next;
      delete curr;
    }
}
bool List::insert(int weight, int start, int end, vector<int>vertices)
{
	int count = 0;
	for (auto i = vertices.begin(); i != vertices.end(); ++i) {
		if (*i == start || *i == end) {
			count += 1;
		}
  }
	if (count < 2) {
		return false;
	}
	
	Node *tmp = head;
  if (!tmp)
    {
      head = new Node(weight,start,end,nullptr,nullptr);
    }
  else
    {
      while (tmp->next != nullptr)
	{
	  tmp = tmp->next;
	}
      tmp->next = new Node(weight,start,end,tmp,nullptr);
    }
  return true;
}


bool List::remove(int start, int end)
{
  Node *tmp = findNode(start,end);
  if (tmp) {
    Node *prev = tmp->prev;
    Node *next = tmp->next;
    if (prev) {prev->next = next;}
    if (next) {next->prev = prev;}
    if (tmp == head) {head = next;}
    delete tmp;
    return true;
  }
  return false;
}
bool List::find(int start, int end)
{
  Node *tmp = findNode(start,end);
  return true;
}

Node * List::findNode(int initial, int final)
{
  Node *tmp = head;
  while (tmp != nullptr && !(tmp->initial == initial && tmp->final == final))
    tmp = tmp->next;

  return tmp;
}

ostream& operator<<(ostream& os, List& rhs)
{
	Node* tmp = rhs.head;
	while (tmp != nullptr)
	{
		os << tmp->initial << "->" << tmp->final << "(Weight: " << tmp->wgt << ")";
		os << std::endl;
		tmp = tmp->next;
	}

	return os;
}