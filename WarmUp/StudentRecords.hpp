#include <iostream>
#include <stdexcept>
#include <vector>
#include "StudentClass.hpp"
using namespace std;

class StudentRecord : public Student{
    private:
        vector<string> courses;
    public:
        StudentRecord(){}
        void setCourses(string course){
            courses.push_back(course);
        }
        string getCourses(){
            string Courses = "";
            for(int i = 0; i<courses.size();i++){
                if(i == courses.size()-1){
                    Courses = Courses + courses.at(i) + ".";
                }
                else{
                    Courses = Courses + courses.at(i) + ", ";
                }
            }
            return Courses;
        }
        StudentRecord(string info){
            vector<string> infor;
            string temp = "";

            for(int i = 0; i<=info.size(); i++){
                if(info[i] == ' ' || i == info.size()){
                    infor.push_back(temp);
                    temp = "";
                }
                else{
                    temp+=info[i];
                }
            }
            this->setFirstName(infor[0]);
            this->setLastName(infor[1]);
            if(checkID(infor[2]) == true){
                this->setIDNo(infor[2]); 
            } 
            else{
                try{
                throw 20;
                }
                catch (int e){
                    cout<<"Invalid ID encountered for Student: "<< this->getFirstName()<<" "<<this->getLastName()<<endl;
                }
            }
            for(int j = 3; j < infor.size(); j++){
                this->setCourses(infor[j]);
            }  
        }
        string toString(){
            return "First Name: " + this->getFirstName() + "\n" + "Last Name: " + this->getLastName() + "\n" + "ID No: " + this->getIDNo() + "\n" +"Courses: " + this->getCourses() + "\n";
        }

};
