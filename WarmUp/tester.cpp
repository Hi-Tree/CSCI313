#include "StudentRecords.hpp"
#include <iostream> 
#include <fstream>
using namespace std;

int main(){
    Student b;
    Student a;
    b.setLastName("Karen");
    a.setLastName("Kelly");
    b.setIDNo("K123456");
    a.setIDNo("K123456");
    cout<<a.equal(b)<<endl;

    // Test for importing from txt Unordered and test toString function 
    /*
    vector<StudentRecord> list;
    string line;
    ifstream students("students.txt");
    while (students.good())
    {
      getline (students,line); 
      list.push_back(StudentRecord(line));
    }
    students.close();
    cout<<list.at(1).toString();
    cout<<"############################"<<endl;
    // Test equals function:
    StudentRecord b("Meri Khurshudyan J987654 math english history");
    cout << b.toString();
    cout<<"############################"<<endl;
    //test compareTo function 
    // if positive a>b if negative b>a
    cout<<list.at(0).compareTo (list.at(1))<<endl; // expected answer is positive because K>A
    cout<<"############################"<<endl;
    //test compareTo with same last name
    cout<<list.at(2).compareTo(list.at(0))<<endl; // expected answer is positive becayse Y>M
*/
}