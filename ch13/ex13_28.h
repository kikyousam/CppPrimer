#ifndef EX13_28_H
#define EX13_28_H

#include <iostream>
#include <string>

using namespace std;

class TreeNode{
public:
    TreeNode(){
        value=string();
        count=new int(1);
        left=NULL;
        right=NULL;
    };
    TreeNode(const TreeNode& TN):value(TN.value),count(TN.count),left(TN.left),right(TN.right){*count++;}
    TreeNode& operator=(const TreeNode& rhs){
        ++*rhs.count;
        if(--*count==0){
            if(left){
                delete left;
                left =NULL;
            }
            if(right){
                delete right;
                right= NULL;
            }
            delete count;
            count=nullptr;
        }
        left=rhs.left;
        right=rhs.right;
        value=rhs.value;
        count=rhs.count;
        return *this;
    }
    ~TreeNode(){
        if(--*count==0){
            if(left){
                delete left;
                left =NULL;
            }
            if(right){
                delete right;
                right= NULL;
            }
            delete count;
            count=nullptr;
        }
    }
private:
    string value;
    int* count;
    TreeNode *left;
    TreeNode* right;
};

class BinStrTree{
public:
    BinStrTree(){
        root =new TreeNode();
    }
    BinStrTree(const BinStrTree& bst):root(new TreeNode(*bst.root)){

    }
    BinStrTree& operator=(const BinStrTree& rval){
        auto nptr=new TreeNode(*rval.root);
        delete root;
        root=nptr;
        return *this;
    }
    ~BinStrTree(){
        delete root;
    }
private:
    TreeNode* root;
};

#endif