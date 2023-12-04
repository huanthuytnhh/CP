#include "NXB.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include "hamKhac.h"
using namespace std;
#define getenter fflush(stdin);
void NXB::NXB_docfile(ifstream& i){
    string dum;
   // getline(i,dum,'\n');
    getline(i,NXB_id,'|'); 
    getline(i,NXB_ten,',');xoaSpaces(this->NXB_ten);xoaSpaces(this->NXB_id);

}
ostream& operator<<(ostream& o,const NXB& a){
    o << left << setw(15) << a.NXB_id << "|"
             << left << setw(40) << a.NXB_ten << ",\n";
             return o;
}
istream& operator>>(istream& i,NXB&a){
    cout<<endl<<"-Nhap ten NXB : ";getenter;
    //fflush(stdin);
    getline(i,a.NXB_ten);
    return i;
}
void NXB::setNXB_ten(){
    cout<<endl<<"-Nhap ten NXB : ";getenter;
    //fflush(stdin);
    getline(cin,this->NXB_ten);
}