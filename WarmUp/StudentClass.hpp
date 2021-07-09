#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef __STUDENTCLASS__H__
#define __STUDENTCLASS__H__


class Student{
    protected:
        string lastName;
        string firstName;
        string IDNo;
    public:
        Student(){}
        Student(string fName, string lName){
            firstName = fName;
            lastName = lName;
        }
        void setLastName(string lName){
            lastName = lName;
        }
        void setFirstName(string fName){
            firstName = fName;
        }
        void setIDNo(string ID){
            if(equal(ID) == true){
                IDNo = ID;
            }
            else{
                try{
                    throw 20;
                }
                catch(int e){
                    cout<<"Invalid ID encountered for Student: "<< this->getFirstName()<<" "<<this->getLastName()<<endl;
                }
            }
        }
        string getFirstName(){
            return firstName;
        }
        string getLastName(){
            return lastName;
        }
        string getIDNo(){
            return IDNo;
        }
        int compareTo(Student student1){
            if(this->getLastName() > student1.getLastName()){
                return 1;
            }
            else if(this->getLastName() < student1.getLastName()){
                return -1;
            }
            else if(this->getLastName() == student1.getLastName()){
                if(this->getFirstName() > student1.getFirstName()){
                    return 1;
                }
                else if(this->getFirstName() < student1.getFirstName()){
                    return -1;
                }
                else if(this->getFirstName() == student1.getFirstName()){
                    return 0;
                }
            }
            return 0;
        }
        string toString(){
            return "First Name: " + this->getFirstName() + "\n" + "Last Name: " + this->getLastName() + "\n" + "ID No: " + this->getIDNo() + "\n";
        }
        bool equal(string ID){
            if(this->getLastName()[0] == ID[0] && stoi(ID.substr(1,6)) && ID.size() == 7){
                return true;
            }
            return false;
        }

};
#endif  //!__STUDENTCLASS__H__