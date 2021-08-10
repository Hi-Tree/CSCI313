#include<iostream>
#include<vector>
#include "StudentClass.hpp"
using namespace std;

class BST{
    private:
        Student data;
        BST* left;
        BST* right;
        vector<Student> inorderData;

    public:

        BST(){
            left = nullptr;
            right = nullptr;
        }
        BST(Student n){
            data = n;
            left = nullptr;
            right = nullptr;
        }
        BST* getRight(){
            return this->right;
        }
        BST* getLeft(){
            return this->left;
        }
        Student getData(){
            return this->data;
        }
        void setData(Student m){
            this->data = m;
        }
        BST* insertBST(Student n,BST* root){
            if(root == nullptr){
                BST* node = new BST(n);
                return node;
            }
            if(n.compareTo(root->data)==1){
                root->right = insertBST(n, root->right);
            }
            else if(n.compareTo(root->data)==-1){
                root->left=insertBST(n,root->left);
            }
            return root;
        }
        BST* min(BST* node){
            BST* cur = node;
            while(cur != nullptr && cur->left != nullptr){
                cur = cur->left;
            }
            return cur;
        }
         void inOrder(BST* root){
            if(root != nullptr){
            inOrder(root->left);
            inorderData.push_back(root->data);
            inOrder(root->right);
            }
         }
         void clearArray(){
             inorderData.clear();
         }
         BST* deleteNode(BST* root, Student n){
             if(root == nullptr){
                 return root;
             }
             if(n.compareTo(root->data)==-1){
                 root->left = deleteNode(root->left, n);
             }
             else if(n.compareTo(root->data)==1){
                 root->right = deleteNode(root->right, n);
             }
             else{
                 if(root->left == nullptr && root->right == nullptr){
                     return nullptr;
                 }
                 else if(root->left == nullptr){
                     BST* temp = root->right;
                     delete(root);
                     cout<<"Student Successfully Deleted"<<endl;
                     return temp;
                 }
                 else if(root->right == nullptr){
                     BST* temp = root->left;
                     delete(root);
                     cout<<"Student Successfully Deleted"<<endl;
                     return temp;
                 }
                 BST* temp = min(root->right);
                 root->data = temp->data;
                 root->right = deleteNode(root->right,temp->data);
             }
             return root;
         }
         vector<Student> getInOrder(){
            return inorderData;
        }
        BST* search(Student m, BST* root){
            if(root == nullptr){
                cout<<"List Is Empty!"<<endl;
                return root;
            }
            if(m.compareTo(root->data)==0){
                cout<< "Student Was Found:\n" + m.toString()<<endl;
                return root;
            }
            if(m.compareTo(root->data)== 1){
                return search(m, root->right);
            }
            return search(m,root->left);
        }

};
