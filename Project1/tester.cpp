/*  This is a fully user interactive program 
    Please do not modify code in the main file
    Follow instructions from the terminal to navigate.
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

  cout<<"Course title: CSCI 313 \nWould you like to continue to course actions? (Y/N)\n";
  string x, answer, info;
  cin>>x;
  while(x == "Y"){
    cout<< "Please choose from the following options: \n   Load Students\n   Add Student\n   Delete Student\n   Search Student List\n   Display Student List\n   Save\n   View Final Roster\n   Search Roster\n   Save Changes"<<endl;
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
    if(answer == "Add Student"){
      if(temp->size()==10){
        cout<<"You have reached maximum class capacity."<<endl;
      }
      else{
        cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
        getline(cin,info);
        m = Student(info);
        temp->insertSorted(m);
      }
    }
    if(answer == "Delete Student"){
      cout<<"Please enter: First_Name  Last_Name  ID_No  (Do not leave anything blank, separate fields by a single space)."<<endl;
      std::getline(std::cin,info);
      m = Student(info);
      cout<< m.toString()<<endl;
      temp->deleteStudent(m);
      cout<<"\nSelect display options from main menu.\n"<<endl;
    }
    if(answer == "Save"){
      //Student array[temp->size()];
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
    if(answer=="Save Changes"){
      if(array[0].getFirstName()==""){
        cout<<"WARNING: Final Roster Does NOT Contain Any Students. An Empty Roster Will Be Created."<<endl;
      }
      std::ofstream ofs("students.txt");
      for(int i=0;i<temp->size();i++){
        ofs<<array[i].getFirstName() +" "+ array[i].getLastName() +" "+ array[i].getIDNo()<<endl;
      }
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
          cout<<"\nStudent was found:\n"+key.toString()<<endl;
          break;
        }
        if(low == high && array[high].compareTo(key) != 0){
          cout<<"Student Not Found."<<endl;
        }
      }  
    }
    else{
      cout<<"Did you mean you select a different action?"<<endl;
    }
      cout<<"Would you like to continue? (Y/N)"<<endl;
      cin>>x;
  }
}