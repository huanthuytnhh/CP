//#include"Bao.h"
#include <iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<fstream>
#include "hamKhac.h"
using namespace std;
#define getenter fflush(stdin);
string Bao::getBao_ten(){
    return this->Bao_ten;
}
int Bao::getThoiGianCongBo(){
    return this->ThoiGianCongBo;
}

void Bao::Bao_docfile(ifstream&i){
    string dummy;
    //getline(i,dummy,'\n');
    getline(i,Bao_id,'|'); xoaSpaces(this->Bao_id);
    getline(i,Bao_ten,'|'); xoaSpaces(this->Bao_ten);
    getline(i,TacGia_id,'|');xoaSpaces(this->TacGia_id);
    getline(i,TapChi_id,'|');xoaSpaces(this->TapChi_id);
    i>>ThoiGianCongBo; getline(i,dummy,',');// ??????
}
ostream& operator<<(ostream&o,const Bao& a){
    o << left << setw(15) << a.Bao_id << "|"
             << left << setw(65) << a.Bao_ten << "|"
             << left << setw(25) << (a.TacGia_id) << "|"
             << left << setw(45) << (a.TapChi_id) << "|"
             << left << setw(10) << a.ThoiGianCongBo << ",\n";
    return o;
}
istream& operator>>(istream& i,Bao& a){
    string TacGia,TapChi,Baoten;
    cout<<"- Nhap ten bao : ";getenter;
    getline(i,Baoten); xoaSpaces(Baoten);//getenter;
    a.Bao_ten=Baoten;
    cout<<"- Nhap ma tac gia : ";
    i>> TacGia; transform(TacGia.begin(),TacGia.end(),TacGia.begin(),::toupper);
    
    a.TacGia_id=TacGia;//getenter;
    cout<<"- Nhap ma tap chi : ";
    i>>TapChi; transform(TapChi.begin(),TapChi.end(),TapChi.begin(),::toupper);
    a.TapChi_id=TapChi;//getenter;
    cout<<"- Nhap thoi gian cong bo : ";
    i>>a.ThoiGianCongBo;//getenter;
    return i;
}
void Bao::setBao_ten(){
    cout<<endl<<"-Nhap ten :";getenter;
    getline(cin,this->Bao_ten);
    xoaSpaces(Bao_ten);
}
void Bao::setBao_tacgia(){
    string TacGia_id2;
    cout<<endl<<"- Nhap ma tac gia : ";
    cin>>TacGia_id2;
    transform(TacGia_id2.begin(),TacGia_id2.end(),TacGia_id2.begin(),::toupper);
    this->TacGia_id=TacGia_id2;
}
void Bao::setBao_tapchi(){
    string TapChi_id2;
    cout<<endl<<"- Nhap ma tap chi : ";
    cin>>TapChi_id2;
    transform(TapChi_id2.begin(),TapChi_id2.end(),TapChi_id2.begin(),::toupper);
    this->TapChi_id=TapChi_id2;
}
void Bao::setBao_thoigiancongbo(){
    cout<<endl<<"-Nhap thoi gian cong bo : ";
    cin>>this->ThoiGianCongBo;
}