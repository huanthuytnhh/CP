#include "NXB.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
#define getenter fflush(stdin);
void NXB::NXB_docfile(ifstream& i){
  //  string dum;
  //  getline(i,dum,'\n');
    getline(i,NXB_id,'|');
    getline(i,NXB_ten,',');
}
ostream& operator<<(ostream& o,const NXB& a){
    o << left << setw(15) << a.NXB_id
      << left << setw(30) << a.NXB_ten << endl;
}
istream& operator>>(istream& i,NXB&a){
    cout<<endl<<"-Nhap ten NXB : ";
    fflush(stdin);
    getline(i,a.NXB_ten);getenter;
    return i;
}
void NXB::setNXB_ten(){
    cout<<endl<<"-Nhap ten NXB : ";
    fflush(stdin);
    getline(cin,this->NXB_ten);
}