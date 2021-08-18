#include "StudentClass.hpp"
using namespace std;
#ifndef __LINKEDQUEUE__H__
#define __LINKEDQUEUE__H__


class QueueClass{
    protected:
        Student data;
        QueueClass* next;
        QueueClass* prev; 
    public:
        QueueClass(){
            next = nullptr;
            prev = nullptr;
        }
        QueueClass(Student s){
            data = s;
            next = nullptr;
            prev = nullptr;
        }
        QueueClass* enQueue(QueueClass* fron, QueueClass* &bac, Student s){
            QueueClass* n = new QueueClass(s);
            n->prev = fron;
            
            if(fron->next == nullptr){
                fron->next = n;
                bac->prev = n;
            }
            else{
                n->next = fron->next;
                fron->next = n; 
                fron->next->next->prev = n;
            }
            return fron;
        }
        void display(){
            QueueClass* temp = this;
            while(temp != nullptr){
                cout<<temp->data.toString()<<endl;
                temp=temp->next;
            }
        }
        void getTail(){
            cout<<this->prev->data.toString()<<endl;
        }
        Student deQueue(QueueClass* &bac){//we will never enter here if list is empty, no need to check for empty here!
           
            QueueClass* temp = bac->prev;//get the node to delete
            Student deleted = temp->data;
            //cout<<bac->prev->prev->data.toString()<<endl;
            
            
            bac->prev->prev->next = nullptr;
            bac->prev = bac->prev->prev;//in case of empty this should point to head!
            delete(temp);
            //cout<<bac->data.toString()<<endl;
            return deleted;
        }
        bool isEmpty(QueueClass* bac){
            if(this->next == bac || this->next == nullptr){
                return true;
            }
            return false;
        }
        void setNext(QueueClass* n){
            this->next = n;
        }
        void setPrev(QueueClass* p){
            this->prev = p;
        }
        QueueClass* getPrev(){
            return this->prev;
        }
        Student getData(){
            return this->data;
        }

};
#endif  //!__LINKEDQUEUE__H__