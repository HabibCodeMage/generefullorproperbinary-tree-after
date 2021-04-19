#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include"deque.h"
#include<string>
using namespace std;
template<typename T>
class binarytree
{
private:
	struct Node
	{
		T element;
		Node* parent;
		Node* left;
		Node* right;
	};
public:
	class position {
	private:
		Node* u;
	public:
		position( Node* v=NULL) :u(v)
		{}
		friend bool operator==(const position& left, const position& right)
		{
			return left.u->element == right.u->element;
		}
		T& operator*()
		{
			return u->element;
		}
		position left() const
		{
			if (isexternal())
				throw"EXTERNAL NODE HAVE NO LEFT CHILD";
			 return position (u->left);
		}
		position right() const
		{
			if (isexternal())
				throw"EXTERNAL NODE HAVE NO RIGHT CHILD";
			 return position (u->right);
		}
		bool isroot()
		{
			return u->parent == NULL;
		}
		bool isexternal() const
		{
			if (u->left == NULL && u->right == NULL)
				return 1;
			else
				return 0;
		}
		friend ostream& operator<<( ostream& strn,const position& obj)
		{
			strn << obj.u->element << endl;
			return strn;
		}
		friend class binarytree;
	};
private:
	deque<binarytree<T>::position> positionlist;
private:
	Node* root;
	int no_of_nodes;
public:
	binarytree():root(NULL),no_of_nodes(0)
	{}
	int size() const
	{
		return no_of_nodes;
	}
	bool empty()
	{
		return no_of_nodes == 0;
	}
	void addroot(const T& object) throw(const char *)
	{
		if (empty())
		{

			root = new Node{ object };
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
			positionlist.insertback(position(root));
			++no_of_nodes;
		}	
		else
			throw"ALREADY ROOTED";
	}
	void expandexternal(const position & object,const T& leftobj,const T& rightobj)
	{
		
		if (!(object.isexternal()))
		{
			throw"IT IS AN INTERNAL NODE";
		}
		else
		{
			Node * temp=object.u;
			temp->left = new Node{leftobj};
			temp->left->parent = temp;
			temp->right = new Node{rightobj};
			temp->right->parent = temp;
			this->no_of_nodes += 2;
			positionlist.insertback(position(temp->left));
			positionlist.insertback(position(temp->right));
		}
	}
	void removeaboveexternal(const binarytree<T>::position& object)
	{
		Node* w = object.u;
		Node* v = w->parent;
		Node* sib = (v->left == w ? v->right : v->left);
		if (v == root)
		{
			root = sib;
			sib->parent = NULL;
		}
		else
		{
			Node* grandpar = v->parent;
			if (grandpar->left == v)
			{
				grandpar->left = sib;
			}
			else
			{
				grandpar->right = sib;
			}
			sib->parent = grandpar;
		}
		positionlist.eraseatnode(position{w->parent});
		positionlist.eraseatnode(position{w});
		delete w;
		delete v;
		no_of_nodes -= 2;
	}
    position Root() const
	{
		 position obj(this->root);
		 return obj;
	}
	deque<position> getpositionlist()
	{
		return this->positionlist;
	}
	deque<position> getpositionlistinpreorder()
	{
		deque<position> object;
		preorder(root, object);
		return object;
	}
	deque<position> getpositionlistinpostorder()
	{
		deque<position> object;
		postorder(root, object);
		return object;
	}
	deque<position> getpositionlistinorder()
	{
		deque<position> object;
		inorder(root, object);
		return object;
	}
	void preorder(Node *v,deque<position>&object)
	{
		object.insertback(position{v});
		if (v->left != NULL)
			preorder(v->left, object);
		if (v->right != NULL)
			preorder(v->right, object);
	}
	void postorder(Node* v, deque<position>& object)
	{
		if (v)
		{
			postorder(v->left, object);
			postorder(v->right, object);
			object.insertback(position{v});
		}
	}
	void inorder(Node* v, deque<position>& object)
	{
		if (v)
		{
			inorder(v->left, object);
			object.insertback(v);
			inorder(v->right, object);

		}
	}
};
#endif // !BINARY_TREEH


