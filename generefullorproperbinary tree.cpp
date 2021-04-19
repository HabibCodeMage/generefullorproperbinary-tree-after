// generefullorproperbinary tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include"binarytree.h"
#include"deque.h"
#include<iostream>
using namespace std;
#include"stackarray.h"
bool isitdigit(string value);
int evaluationofposfix(deque<binarytree<string>::position>& object);
int main()
{
	binarytree<string>object;
	object.addroot("/");
	object.expandexternal(object.Root(),"+", "-");
	object.expandexternal(object.Root().left(),"89", "5");
	object.expandexternal(object.Root().right(), "9", "6");
	object.removeaboveexternal(object.Root().left().right());
	deque<binarytree<string>::position> all = object.getpositionlistinpostorder();
	cout<<evaluationofposfix(all);
}
bool isitdigit(string value)
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] < '0' || value[i]>'9')
			return false;
	}
	return true;
}
int evaluationofposfix(deque<binarytree<string>::position> &object)
{
	stackarray<string>obj;
	for (auto it:object)
	{
		if (isitdigit(*it))
		{
			obj.push(*it);
		}
		else if (*it == "+")
		{
			int value1 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			int value2 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			value1 = value2 + value1;
			obj.push(std::to_string(value1));
		}
		else if (*it == "-")
		{
			int value1 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			int value2 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			value1 = value2 - value1;
			obj.push(std::to_string(value1));
		}
		else if (*it == "*")
		{
			int value1 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			int value2 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			value1 = value2 * value1;
			obj.push(std::to_string(value1));
		}
		else if (*it == "/")
		{
			int value1 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			int value2 = stoi(obj.top(), nullptr, 10);
			obj.pop();
			value1 = value2 / value1;
			obj.push(std::to_string(value1));
		}

	}
	return  stoi(obj.top(), nullptr, 10);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
