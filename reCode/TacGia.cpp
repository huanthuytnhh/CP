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
    getline(i,TacGia_id,'|');
    getline(i,TacGia_ho,'|');
    getline(i,TacGia_ten,'|');
    getline(i,TacGia_congtac,'|');
    getline(i,TacGia_linhvuc,'|');
    getline(i,TacGia_trinhdo,',');
}
istream& operator>>(istream& i,TacGia& a)
{
    cout<<endl<<"- Nhap ho : ";
    getline(i,a.TacGia_ho); xoaSpaces(a.TacGia_ho);
    getenter;
    cout<<"- Nhap ten : ";
    i>>a.TacGia_ten;xoaSpaces(a.TacGia_ten);
    getenter;
    cout<<"- Nhap noi cong tac : [DH...]";
    i>>a.TacGia_congtac;
    getenter;
    cout<<"- Nhap linh vuc nghien cuu : ";
    getline(i,a.TacGia_linhvuc);
    getenter;
    cout<<"- Nhap trinh do : ";
    getline(i,a.TacGia_trinhdo);
    return i;
}
ostream& operator<<(ostream& o,const TacGia& a)
{
    o<<(ios::left)<<setw(15)<<a.TacGia_id
    <<(ios::left)<<setw(20)<<a.TacGia_ho
    <<(ios::left)<<setw(15)<<a.TacGia_ten
    <<(ios::left)<<setw(15)<<a.TacGia_congtac
    <<(ios::left)<<setw(30)<<a.TacGia_linhvuc
    <<(ios::left)<<setw(10)<<a.TacGia_trinhdo<<endl;
    return o;
}
void TacGia::setTacGia_ten(){
    cout<<endl<<"- Nhap ho  : ";
    getline(cin,this->TacGia_ho);
    xoaSpaces(this->TacGia_ho);
    cout<<endl<<"- Nhap ten  : ";
    getline(cin,this->TacGia_ten);
    xoaSpaces(this->TacGia_ten);
}
void TacGia::setTacGia_congtac(){
    cout<<endl<<"- Nhap noi cong tac : ";
    getline(cin,this->TacGia_congtac);
}
void TacGia::setTacGia_linhvuc(){
    cout<<endl<<"-Nhap linh vuc lam viec : ";
    getline(cin,this->TacGia_linhvuc);
}
void TacGia::setTacGia_trinhdo(){
    cout<<endl<<"-Nhap trinh do cua tac gia :";
    getline(cin,this->TacGia_trinhdo);
}