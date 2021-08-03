/*  
    Description: 
    This is a fully user interactive program 
    Once the course is closed students may be placed on the 
    Waiting list or simply refuse to register for the course 
    If a student chooses to wait they will automatically 
    Get enrolled in the course given a space has opened up.

    Suggested Directions:
    Please Follow Terminal Directions To Navigate Through The Process
    For The Purposes Of This Project We Will Begin With A Full Class 
    *Try Adding Another Student*
*/
#include "StudentRecords.hpp"
#include <iostream> 
#include <fstream>
#include "LinkedList.hpp"
using namespace std;

int main(){
  ListNode* head = nullptr;
  head = new ListNode();
  ListNode* temp = head;
  Student m;
  Student array[10];
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
          head->insertSorted(m);
        }
      }
      cout<<"Load Complete, select display options from main menu."<<endl;
    }
    if(answer == "Display Student List"){
      temp->toString();
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
      if(temp->size()==10){
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
        temp->insertSorted(m);
        cout<<"Student Was Succesfully Added."<<endl;
      }
    }
    if(answer == "Delete Student"){
      cout<<"\nPlease Enter Student to be Deleted: First_Name  Last_Name  ID_No\n(Do not leave anything blank, separate fields by a single space)."<<endl;
      std::getline(std::cin,info);
      m = Student(info);
      temp->deleteStudent(m);
      
      if(front->isEmpty(back) == false && temp->size()<10){
        m = front->deQueue(back);
        temp->insertSorted(m);
        cout<<"\nA Wait-Listed Student Has Been Added To The Course In Order Of Registration.";
      }

      cout<<"Select display options from main menu.\n"<<endl;
    }
    if(answer == "Save"){
      int i = 0;
      ListNode* ittr = temp;
      ittr = ittr->next;//skip head node
      while(ittr != nullptr){
        array[i] = ittr->data;
        ittr = ittr->next;
        i++;
      }
      cout<<"Save Complete. Select veiwing options from main menu."<<endl;
    }
    if(answer == "View Final Roster"){
      for(int i =0;i<temp->size();i++){
      cout<<array[i].toString()<<endl;
      }
    }
    if(answer == "Search Student List"){
      cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
      getline(cin,info);
      m = Student(info);
      temp->searchList(m);
    }
    if(answer=="Save Changes"){
      if(array[0].getFirstName()==""){
        cout<<"WARNING: Final Roster Does NOT Contain Any Students. An Empty Roster Will Be Created."<<endl;
      }
      std::ofstream ofs("students.txt");
      for(int i=0;i<temp->size();i++){
        ofs<<array[i].getFirstName() +" "+ array[i].getLastName() +" "+ array[i].getIDNo()<<endl;
      }
      cout<<"Final Roster Was Successfully Saved."<<endl;
    }
    if(answer == "Search Roster"){
      cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
      getline(cin,info);
      Student key = Student(info);
      int mid;
      int low = 0;
      int high = temp->size()-1;//3,3,
      while(high>=low){
        mid = (high+low)/2;
        if(array[mid].compareTo(key)==-1){
          low = mid+1;
        }
        if(array[mid].compareTo(key)==1){
          high = mid-1;
        }
        if(array[mid].compareTo(key)==0){
          cout<<"\n";
          cout<<"\nStudent was found:\n"+key.toString()<<endl;
          break;
        }
        if(low == high && array[high].compareTo(key) != 0){
          cout<<"Student Not Found."<<endl;
        }
      }  
    }
      cout<<"Would you like to continue? (Y/N)"<<endl;
      cin>>x;
  }
}
