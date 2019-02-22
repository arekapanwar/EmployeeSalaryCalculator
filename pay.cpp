#include<iostream>
#include "person.h"
#include "person.cpp"
#include<string>
#include<fstream>
using namespace std;


int readData(Person emparray[], int size){

  string firstname;
  string lastname;
  double hoursworked;
  double payrate;
  int i = 0;
  
  
  ifstream inFile;
  inFile.open("input.txt");
  while (inFile && i < size) {
    inFile >> firstname >> lastname >> hoursworked >> payrate;
    emparray[i].setFirstName(firstname);
    emparray[i].setLastName(lastname);
    emparray[i].setHoursWorked(hoursworked);
    emparray[i].setPayRate(payrate);
    i++;
  }

  i--;
  

  inFile.close();


  return i;
}

void writeData(Person filledArray[], int size){
  ofstream outFile;
  outFile.open("output.txt");
  for(int i =0; i < size; i++){
    outFile << filledArray[i].fullName() << " " <<  filledArray[i].totalPay() << "\n";
   
  }

  outFile.close();
}
  



int main() {

  Person employees[20];

  int arraysize = readData(employees, 20);
  writeData(employees, arraysize);


  return 0;

}
