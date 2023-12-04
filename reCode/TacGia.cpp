#include "TacGia.h"
#include<fstream>
#include<string>
//#include<string.h>
#include<iomanip>
#include "hamKhac.h"
using namespace std;
#define getenter fflush(stdin);
TacGia::TacGia(const TacGia& t){
    this->TacGia_id=t.TacGia_id;
    this->TacGia_ten=t.TacGia_ten;
    this->TacGia_ho=t.TacGia_ho;
    this->TacGia_congtac=t.TacGia_congtac;
    this->TacGia_trinhdo=t.TacGia_trinhdo;
    this->TacGia_linhvuc=t.TacGia_linhvuc;
}
TacGia::~TacGia(){}
TacGia::TacGia(){
}
string TacGia ::getTacGia_ho()
{
    return this->TacGia_ho;
}

string TacGia ::getTacGia_ten()
{
    string Ho_Ten = this->TacGia_ho+ " " + this->TacGia_ten;
    return (Ho_Ten);
}
string TacGia::getTacGia_id(){
    return this->TacGia_id;
}
void TacGia::TacGia_docfile(ifstream& i){
    string dummy;
    //getline(i,dummy,'\n');
    getline(i,TacGia_id,'|'); xoaSpaces(this->TacGia_id);
    getline(i,TacGia_ho,'|');xoaSpaces(this->TacGia_ho);
    getline(i,TacGia_ten,'|');xoaSpaces(this->TacGia_ten);
    getline(i,TacGia_congtac,'|');xoaSpaces(this->TacGia_congtac);
    getline(i,TacGia_linhvuc,'|');xoaSpaces(this->TacGia_linhvuc);
    getline(i,TacGia_trinhdo,',');xoaSpaces(this->TacGia_trinhdo);
}
istream& operator>>(istream& i,TacGia& a)
{
    cout<<endl<<"- Nhap ho cua Tac Gia: ";getenter;
    getline(i,a.TacGia_ho); xoaSpaces(a.TacGia_ho);
    
    cout<<"- Nhap ten cua Tac Gia: ";
    i>>a.TacGia_ten;xoaSpaces(a.TacGia_ten);
    
    cout<<"- Nhap noi cong tac : [DH...]";
    i>>a.TacGia_congtac;
    
    cout<<"- Nhap linh vuc nghien cuu : ";getenter;
    getline(i,a.TacGia_linhvuc);
    
    cout<<"- Nhap trinh do : ";getenter;
    getline(i,a.TacGia_trinhdo);
    return i;
}
ostream& operator<<(ostream& o,const TacGia& a)
{
    o << left << setw(15) << a.TacGia_id << "|"
             << left << setw(30) << a.TacGia_ho << "|"
             << left << setw(15) << a.TacGia_ten << "|"
             << left << setw(30) << a.TacGia_congtac << "|"
             << left << setw(30) << a.TacGia_linhvuc << "|"
             << left << setw(15) << a.TacGia_trinhdo << ",\n";
    return o;
}
void TacGia::setTacGia_ten(){
    
    cout<<endl<<"- Nhap ten  : ";getenter;getline(cin,this->TacGia_ten);
    xoaSpaces(this->TacGia_ten);cout<<"\n"; 
}
void TacGia::setTacGia_ho(){
    cout<<"- Nhap ho  : ";getenter;getline(cin,this->TacGia_ho);
    xoaSpaces(this->TacGia_ho);cout<<"\n";getenter; 
}
void TacGia::setTacGia_congtac(){
    cout<<endl<<"- Nhap noi cong tac : ";getenter;
    getline(cin,this->TacGia_congtac);
}
void TacGia::setTacGia_linhvuc(){
    cout<<endl<<"-Nhap linh vuc lam viec : ";getenter;
    getline(cin,this->TacGia_linhvuc);
}
void TacGia::setTacGia_trinhdo(){
    cout<<endl<<"-Nhap trinh do cua tac gia :";getenter;
    getline(cin,this->TacGia_trinhdo);
}