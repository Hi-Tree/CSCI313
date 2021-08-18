/*  
    Description: 
    This is a fully user interactive program 
    In this project the addition of a hash table has been made where students
    May be searched by their ID number.
    Adding or deleting a student will both add and delete from both the BST and
    The hash table.
    The user may use the hash table to delete a student by ID number but may NOT use 
    ID number alone to add a new student. 
*/
#include "StudentRecords.hpp"
#include "LinkedQueue.hpp"
#include <iostream> 
#include <fstream>
#include <vector>
#include "BST.hpp"
#include <string>
using namespace std;

int main(){
  int pos;//position where student record will be stored in hash table
  vector<Student> studentRec[100];
  vector<Student> result;
  BST* root = nullptr;
  root = new BST();
  int count = 0;
  Student m;
  QueueClass* front = nullptr;
  QueueClass* back = nullptr;
  front = new QueueClass();
  back = new QueueClass();
  front->setNext(back);
  back->setPrev(front);

  cout<<"Course title: CSCI 313 \nWould you like to continue to course actions? (Y/N)\n";
  string x, answer, info;
  cin>>x;
  while(x == "Y"){
    cout<< "Please choose from the following options: \n   Load Students (Please Load Students to avoid manual entry)\n   Add Student\n   Delete Student\n   Search By ID Number\n   Delete By ID Number\n   Search Student List\n   Display Student List\n   Display Wait List\n   Save\n   View Final Roster\n   Search Roster\n   Save Changes(You must first Save before saving changes)"<<endl;
    cin.ignore();
    std::getline(std::cin, answer);
    if(answer == "Load Students"){
      //result.clear();
      string line;
      ifstream students("students.txt");
      while (students.good())
      {
        getline(students,line);
        if(line == ""){
          break;
        }
        else{
          m = Student(line);
          pos = stoi(m.getIDNo().substr(5)); //where addition to hash happens
          studentRec[pos].push_back(m);
          if(count == 0){
            root->setData(m);
            count++;
          }
          else{
            root->insertBST(m, root);
          }
        }
      }
      cout<<"Load Complete, select display options from main menu."<<endl;
      root->inOrder(root);
      result = root->getInOrder();
      cout<<"Class Size: "+ to_string(result.size())<<endl;
    }
    if(answer == "Search By ID Number"){
      if(root->getData().getFirstName()==""){
        cout<<"Student List Is Empty Pleas Load Students."<<endl;
      }
      else{
        string temp3;
        cout<<"Please Enter ID Number:"<<endl;
        cin>>temp3;
        pos = stoi(temp3.substr(5));
        for(int i = 0; i<studentRec[pos].size();i++){
          if(temp3 == studentRec[pos].at(i).getIDNo()){
            cout<<"Student Found:\n\n" + studentRec[pos].at(i).toString()<<endl;
          }
        }
      }
    }
    if(answer == "Display Student List"){
      root->clearArray();
      root->inOrder(root);
      result.clear();
      result = root->getInOrder();
      for(int i = 0; i<result.size(); i++){
        cout<<result.at(i).toString()<<endl;
      }
    }
    if(answer == "Display Wait List"){
      if(front->isEmpty(back)){
        cout<<"\nThere are no Students in the Wait List"<<endl;
      }
      else{
        front->display();
      }
    }
    if(answer == "Add Student"){
      if(root->getData().getFirstName()==""){
        cout<<"Student List Is Empty Pleas Load Students."<<endl;
      }
      else{
        if(result.size()==20){
          cout<<"\nYou have reached maximum class capacity."<<endl;
          cout<<"Student Will Be Wait-Listed.\nPlease enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
          getline(cin,info);
          m = Student(info);
          front->enQueue(front, back, m);
          cout<<"\nStudent Successfully Wait-Listed. \nIf space becomes available students will be automatically enrolled in order of registration.\n"<<endl;
        }
        else{
          cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
          getline(cin,info);
          m = Student(info);
          root->insertBST(m, root);
          pos = stoi(m.getIDNo().substr(5));
          studentRec[pos].push_back(m);
          cout<<"Student Was Succesfully Added."<<endl;
        }
    }
    }
    if(answer == "Delete Student"){
      if(root->getData().getFirstName() == ""){
        cout<<"Student List Is Empty Please Load Students"<<endl;
      }
      else{
      cout<<"\nPlease Enter Student to be Deleted: First_Name  Last_Name  ID_No\n(Do not leave anything blank, separate fields by a single space)."<<endl;
      std::getline(std::cin,info);
      m = Student(info);
      pos = stoi(m.getIDNo().substr(5));
      for(int i =0; i<studentRec[pos].size(); i++){
        if(studentRec[pos].at(i).compareTo(m) == 0){
          studentRec[pos].erase(studentRec[pos].begin()+i);
        }
      }
      root->deleteNode(root, m);
      result.clear();
      root->clearArray();
      root->inOrder(root);
      result = root->getInOrder();

      if(front->isEmpty(back) == false && result.size()<20){
        m = front->deQueue(back);
        root->insertBST(m, root);
        pos = stoi(m.getIDNo().substr(5));
        studentRec[pos].push_back(m);
        cout<<"\nA Wait-Listed Student Has Been Added To The Course In Order Of Registration.";
      }
      cout<<"\nThis Student Has Been Removed:\n" + m.toString()<<endl;
      cout<<"Select display options from main menu.\n"<<endl;
      }
    }
    if(answer == "Delete By ID Number"){
      if(root->getData().getFirstName() == ""){
        cout<<"Student List Is Empty Please Load Students"<<endl;
      }
      else{
      Student temp5;
      string IDnum;
      cout<<"Please Enter ID Number: "<<endl;
      cin>>IDnum;
      pos = stoi(IDnum.substr(5));
      for(int i = 0; i<studentRec[pos].size();i++){
        if(IDnum == studentRec[pos].at(i).getIDNo()){
          temp5 = studentRec[pos].at(i);
          studentRec[pos].erase(studentRec[pos].begin()+i);
        }
      }
      root->deleteNode(root, temp5);
      result.clear();
      root->clearArray();
      root->inOrder(root);
      result = root->getInOrder();

      if(front->isEmpty(back) == false && result.size()<20){
        cout<<"\nA Wait-Listed Student Has Been Added To The Course In Order Of Registration.";
        m = front->deQueue(back);
        root->insertBST(m, root);
        pos = stoi(m.getIDNo().substr(5));
        studentRec[pos].push_back(m);
      }
      
      cout<<"\nThis Student Has Been Removed:\n" + temp5.toString()<<endl;
      cout<<"Select display options from main menu.\n"<<endl;
      }
    }

    if(answer == "Save"){
      root->clearArray();
      root->inOrder(root);
      result.clear(); 
      result = root->getInOrder();
      cout<<"Save Complete. Select veiwing options from main menu."<<endl;
    }
    if(answer == "View Final Roster"){
      for(int i =0;i<result.size();i++){
      cout<<result.at(i).toString()<<endl;
      }
    }
    if(answer == "Search Student List"){
      cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
      getline(cin,info);
      m = Student(info);
      root->search(m,root);
    }
    if(answer=="Save Changes"){
      if(result.at(0).getFirstName()==""){
        string a;
        cout<<"WARNING: Final Roster Does NOT Contain Any Students. Is that Correct?(Y/N)"<<endl;
        cin>>a;
        if(a=="Y"){
        std::ofstream ofs("students.txt");
        for(int i=0;i<result.size();i++){
          ofs<<result.at(i).getFirstName() +" "+ result.at(i).getLastName() +" "+ result.at(i).getIDNo()<<endl;
        }
        cout<<"Final Roster Was Successfully Saved."<<endl;
        
        }
        else{
            cout<<"Make Sure To Save Before Saving Changes."<<endl;
        }
      
    }
      else{
        std::ofstream ofs("students.txt");
        for(int i=0;i<result.size();i++){
          ofs<<result.at(i).getFirstName() +" "+ result.at(i).getLastName() +" "+ result.at(i).getIDNo()<<endl;
        }
        cout<<"Final Roster Was Successfully Saved."<<endl;
      }
    }
    if(answer == "Search Roster"){
      cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
      getline(cin,info);
      Student key = Student(info);
      int mid;
      int low = 0;
      int high = result.size()-1;//3,3,
      while(high>=low){
        mid = (high+low)/2;
        if(result[mid].compareTo(key)==-1){
          low = mid+1;
        }
        if(result[mid].compareTo(key)==1){
          high = mid-1;
        }
        if(result[mid].compareTo(key)==0){
          cout<<"\n";
          cout<<"\nStudent was found:\n"+key.toString()<<endl;
          break;
        }
        if(low == high && result[high].compareTo(key) != 0){
          cout<<"Student Not Found."<<endl;
        }
      }  
    }
      cout<<"Would you like to continue? (Y/N)"<<endl;
      cin>>x;
  }
}
