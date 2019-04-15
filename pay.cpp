//Areka Panwar

#include<iostream>
#include "person.h"
#include "person.cpp"
#include<string>
#include<fstream>
#include <vector>
using namespace std;

void writeData(vector<Person> filledArray, int size){
  ofstream outFile;
  outFile.open("output.txt");
  for(int i =0; i < size; i++){
    outFile << filledArray[i].fullName() << " " <<  filledArray[i].totalPay() << "\n";
   
  }

  outFile.close();
}

void readData(vector<Person> emp){

  string firstname;
  string lastname;
  double hoursworked;
  double payrate;
  
  
  
  ifstream inFile;
  inFile.open("input.txt");
  while ( inFile >> firstname >> lastname >> hoursworked >> payrate) {
    //inFile >> firstname >> lastname >> hoursworked >> payrate;
    // Person newperson(firstname, lastname, payrate, hoursworked);
    
    emp.emplace_back(firstname, lastname, payrate, hoursworked);
   
  }


  

  inFile.close();

  writeData(emp, emp.size());



}


  



int main() {

  vector<Person>  employees;
  
  readData(employees);
  



  return 0;

}
