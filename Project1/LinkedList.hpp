#include "StudentClass.hpp"
using namespace std;

class ListNode{
    public:
        Student data;
        ListNode* next;
        ListNode(){
            this->next = nullptr;
        }
        ListNode(Student s){
            data = s;
            this->next = nullptr;
        }
        bool isEmpty(){
            if(this->next == nullptr){
                return true;
            }
            return false;
        }
        ListNode* insertSorted(Student s){
            ListNode* temp = this;
            ListNode* helper;
            ListNode* first = temp;
            ListNode* newStudent = nullptr;
            newStudent = new ListNode(s);
            if(temp->isEmpty()){
                temp->next = new ListNode();
                temp->next->data = s;
            }
            else{
            while(temp != nullptr){
                if(s.compareTo(temp->data)==-1){
                    newStudent->next = temp->next;
                    temp->next = newStudent;
                    break;
                }
                else if(s.compareTo(temp->data)==1 && temp->next == nullptr){
                    temp->next = newStudent;
                    break;
                }
                else if(s.compareTo(temp->data) == 1 && s.compareTo(temp->next->data)==-1){
                    newStudent->next = temp->next;
                    temp->next = newStudent;
                    break;
                }
                else if(s.compareTo(temp->data)==0){
                    cout<<"Error: Student Already Exists In List."<<endl;
                    break;
                }
                temp = temp->next;
            }
            }
            return first;
        }
        void toString(){
            ListNode* temp = this;
            while(temp != nullptr){
            cout<<temp->data.toString()<<endl;
            temp = temp->next;
            }
        }
        ListNode* searchList(Student s){
            ListNode* temp = this;
            while(temp != nullptr){
                if(temp->data.compareTo(s)==0){
                    cout<<"Student was found: \n" + temp->data.toString(); 
                    return temp;
                }
                temp = temp->next;
            }
            cout<<"Student was not found."<<endl;
            return nullptr;
        }
        ListNode* deleteStudent(Student s){
            ListNode* prev = this;
            ListNode* temp = prev;
            ListNode* tbd;
            ListNode* temp1 = prev->searchList(s);
            if(temp1 == nullptr){
                return nullptr;
            }
            else{
                while(prev != nullptr){
                    if(prev->next->data.compareTo(s)==0 && prev->next->next != nullptr){
                        tbd = prev->next;
                        prev->next = temp1->next;
                        delete(tbd);
                        break;
                    }
                    if(prev->next->data.compareTo(s)==0 && prev->next->next == nullptr){
                            tbd = prev->next;
                            prev->next = nullptr;
                            delete(tbd);
                            break;
                        }
                    
                    prev = prev->next;
                }
            }
            cout<<"And successfully removed."<<endl;
            return temp;
        }
        int size(){
            ListNode* temp = this;
            int i = 0;
            while(temp!=nullptr){
                i++;
                temp=temp->next;
            }
            return i-1;//because head node is counted while its empty
        }
};