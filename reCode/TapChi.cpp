#include "TapChi.h"
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<fstream>
#include"hamKhac.h"
#include<string>
#define getenter fflush(stdin);
using namespace std;

void TapChi::TapChi_docfile(ifstream& i){
    string dummy;
    //getline(i,dummy,'\n');
    getline(i,TapChi_id,'|');
    getline(i,TapChi_ten,'|');
    getline(i,TapChi_bientap,'|');
    getline(i,NXB_id,',');
}
string TapChi::getTapChi_id(){
    return this->TapChi_id;
}
string TapChi::getTapChi_ten(){
    return this->TapChi_ten;
}
ostream& operator<<(ostream &o,const TapChi& a){
    o<<left<<setw(15)<<a.TapChi_id
    <<left<<setw(50)<<a.TapChi_ten
    <<left<<setw(30)<<a.TapChi_bientap
    <<left<<setw(10)<<a.NXB_id<<endl;
    return o;
}
istream& operator>>(istream& i,TapChi& a){
    string nxb;
    cout<<endl<<"-Nhap ten tap chi : ";
    getline(i,a.TapChi_ten);xoaSpaces(a.TapChi_ten);
    getenter;
    cout<<endl<<"-Nhap ten bien tap : ";
    getline(i,a.TapChi_bientap);xoaSpaces(a.TapChi_bientap);
    getenter;
    cout<<endl<<"-Nhap ma Nha xuat ban : ";
    //getline(i,a.NXB_id);
    i>>nxb;
    transform(nxb.begin(),nxb.end(),nxb.begin(),::toupper);
    a.NXB_id=nxb;
    getenter;
    return i;
}
void TapChi::setTapChi_ten(){
    cout<<endl<<"- Nhap ten tap chi : ";getline(cin,TapChi_ten);
}
void TapChi::setTapChi_bientap(){
    cout<<endl<<"- Nhap ten bien tap : ";getline(cin,TapChi_bientap);
}
void TapChi::setNXB_id(){ // nhung thu lien quan den Ma thi can dung ham transform
    string nxb;
    cout<<endl<<"- Nhap ma NXB : ";cin>>nxb;
    transform(nxb.begin(),nxb.end(),nxb.begin(),::toupper);
    this->NXB_id=nxb;
}