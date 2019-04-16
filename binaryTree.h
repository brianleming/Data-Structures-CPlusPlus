#include <iostream>
#include "MyStack.h"
#ifndef binaryTree_H
#define binaryTree_H
using namespace std;

template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType> *llink;
	binaryTreeNode<elemType> *rlink;
};

template <class elemType>
class binaryTreeType
{
public:
	bool isEmpty() const;
	void inOrderTraversal() const;
	void preOrderTraversal() const;
	void postOrderTraversal() const;
	int treeHeight() const;
	int treeNodeCount() const;
	int treeLeavesCount() const;
	void destroyTree();
	binaryTreeType();
	~binaryTreeType();
    void nonRecursiveInTraversal() const;
    void nonRecursivePreTraversal() const;
    void nonRecursivePostTraversal() const;
    
protected:
    binaryTreeNode<elemType> *root;

private:
	void destroy(binaryTreeNode<elemType>* &p);
	void inorder(binaryTreeNode<elemType> *p) const;
	void preorder(binaryTreeNode<elemType> *p) const;
	void postorder(binaryTreeNode<elemType> *p) const;
	int height(binaryTreeNode<elemType> *p) const;
	int max(int x, int y) const;
	int nodeCount(binaryTreeNode<elemType> *p) const;
	int leavesCount(binaryTreeNode<elemType> *p) const;
};

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
	return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inOrderTraversal() const
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preOrderTraversal() const
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postOrderTraversal() const
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
	return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
	return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
	return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else if (p->llink == NULL && p->rlink == NULL)
		return 1;
	else
		return leavesCount(p->llink) + leavesCount(p->rlink);
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursiveInTraversal() const
{
    stackType<binaryTreeNode<elemType>* > stack;
    binaryTreeNode<elemType> *current;
    current = root;
    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            stack.push(current);
            current = current->llink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            cout << current->info << " ";
            current = current->rlink;
        }
    cout << endl;
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePreTraversal() const
{
    stackType<binaryTreeNode<elemType>*> stack;
    binaryTreeNode<elemType> *current;
    current = root;
    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            cout << current->info << " ";
            stack.push(current);
            current = current->llink;
        }
        else
        {
            current = stack.top();
            stack.pop();
            current = current->rlink;
        }
    cout << endl;
}

template <class elemType>
void binaryTreeType<elemType>::nonRecursivePostTraversal() const
{
    stackType<binaryTreeNode<elemType>*> stack;
    stackType<int> stack2;
    binaryTreeNode<elemType> *current;
    current = root;
    int v = 0;
    while ((current != NULL) || (!stack.isEmptyStack()))
        if (current != NULL)
        {
            stack.push(current);
            stack2.push(1);
            current = current->llink;
            while (!stack.isEmptyStack())
            {
                if (current != NULL && v == 0)
                {
                    stack.push(current);
                    stack2.push(2);
                }
                
                else
                {
                    current = stack.top();
                    stack.pop();
                    v = stack2.top();
                    stack2.pop();
                    if (v == 1)
                    {
                        stack.push(current);
                        stack2.push(2);
                        current = current->rlink;
                        v = 0;
                    }
                    
                    else
                        cout << current->info << " ";
                }
            }
        }
}
#endif
