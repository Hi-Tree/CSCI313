/*  
    Description: 
    This is a fully user interactive program 
    Once the course is closed students may be placed on the 
    Waiting list or simply refuse to register for the course 
    If a student chooses to wait they will automatically 
    Get enrolled in the course given a space has opened up. 
    This system has altered a linked list with a binary search tree.
    Given that most tasks are recursive all data is saved into an array before it is displayed.

    Suggested Directions:
    Please Follow Terminal Directions To Navigate Through The Process
    For The Purposes Of This Project We Will Begin With A Full Class 
    *Try Adding Another Student*
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
  int count = 0;
  vector<Student> result;
  BST* root = nullptr;
  root = new BST();
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
    cout<< "Please choose from the following options: \n   Load Students(Please Load Students to avoid manual entry)\n   Add Student\n   Delete Student\n   Search Student List\n   Display Student List\n   Display Wait List\n   Save\n   View Final Roster\n   Search Roster\n   Save Changes(You must first Save before saving changes)"<<endl;
    cin.ignore();
    std::getline(std::cin, answer);
    if(answer == "Load Students"){
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
        cout<<"Student Was Succesfully Added."<<endl;
      }
    }
    if(answer == "Delete Student"){
      cout<<"\nPlease Enter Student to be Deleted: First_Name  Last_Name  ID_No\n(Do not leave anything blank, separate fields by a single space)."<<endl;
      std::getline(std::cin,info);
      m = Student(info);
      root->deleteNode(root, m);
      result.clear();
      root->clearArray();
      root->inOrder(root);
      result = root->getInOrder();

      if(front->isEmpty(back) == false && result.size()<20){
        m = front->deQueue(back);
        root->insertBST(m, root);
        cout<<"\nA Wait-Listed Student Has Been Added To The Course In Order Of Registration.";
      }
  
      cout<<"Select display options from main menu.\n"<<endl;
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
        cout<<"WARNING: Final Roster Does NOT Contain Any Students. An Empty Roster Will Be Created."<<endl;
      }
      std::ofstream ofs("students.txt");
      for(int i=0;i<result.size();i++){
        ofs<<result.at(i).getFirstName() +" "+ result.at(i).getLastName() +" "+ result.at(i).getIDNo()<<endl;
      }
      cout<<"Final Roster Was Successfully Saved."<<endl;
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
