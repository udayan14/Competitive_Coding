#include<iostream>

using namespace std;

struct Node
{
	int val;
	int pos;
	Node* left;
	Node* right;
};

Node* min_finder(Node*);
Node* remove_helper(Node*,int);

struct BST
{
	Node* head;
	BST()
	{
		head = NULL;
	}

	void insert(int n)
	{
		int pos_temp = 1;
		Node* temp = new Node();
		temp->val = n;
		temp->pos = pos_temp;
		temp->left = NULL;
		temp->right = NULL;
		if(head==NULL)
		{
			head = temp;
			cout << pos_temp << "\n";
		}
		else
		{
			Node* itr = head;
			while(itr!=NULL)
			{
				if(itr->val<n)
				{
					pos_temp = 2*pos_temp+1;
					if(itr->right==NULL)
					{
						temp->pos = pos_temp;
						itr->right = temp;
						cout << pos_temp << "\n";
						break;
					}
					else
					{
						itr = itr->right;
					}
				}
				else
				{
					pos_temp = 2*pos_temp;
					if(itr->left==NULL)
					{
						temp->pos = pos_temp;
						itr->left = temp;
						cout << pos_temp << "\n";
						break;
					}
					else
					{
						itr = itr->left;
					}
				}
			}
		}
	}

	void remove(int n)
	{
		head = remove_helper(head,n);
	}
};

Node* min_finder(Node* head)
{
	Node* curr = head;
	while(curr->left!=NULL)
		curr = curr->left;
	return curr;
}


Node* remove_helper(Node* head, int n)
{
	if(head==NULL)
		return head;
	if(n<head->val)
		head->left = remove_helper(head->left,n);
	else if(n>head->val)
		head->right = remove_helper(head->right,n);
	else
	{
		cout << head->pos << "\n";
		if(head->left==NULL)
		{
			Node* temp = head->right;
			delete head;
			return temp;
		}
		if(head->right==NULL)
		{
			Node* temp = head->left;
			delete head;
			return temp;
		}
		Node* temp = min_finder(head->right);
		head->val = temp->val;
		head->right = remove_helper(head->right,temp->val);
	}
	return head;
}



int main()
{
	int q;
	cin >> q;
	BST tree;
	while(q--)
	{
		char c;
		int val;
		cin >> c;
		cin >> val;
		if(c=='i')
			tree.insert(val);
		else if(c=='d')
			tree.remove(val);
	}
}
