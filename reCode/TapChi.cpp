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
    getline(i,TapChi_id,'|');xoaSpaces(this->TapChi_id);
    getline(i,TapChi_ten,'|');xoaSpaces(this->TapChi_ten);
    getline(i,TapChi_bientap,'|');xoaSpaces(this->TapChi_bientap);
    getline(i,NXB_id,',');xoaSpaces(this->NXB_id);
}
string TapChi::getTapChi_id(){
    return this->TapChi_id;
}
string TapChi::getTapChi_ten(){
    return this->TapChi_ten;
}
ostream& operator<<(ostream &o,const TapChi& a){
    o << left << setw(15) << a.TapChi_id << "|"
             << left << setw(50) << a.TapChi_ten << "|"
             << left << setw(30) << a.TapChi_bientap << "|"
             << left << setw(15) << a.NXB_id << ",\n";
    return o;
}
istream& operator>>(istream& i,TapChi& a){
    string nxb;
    cout<<endl<<"-Nhap ten tap chi : ";getenter;
    getline(i,a.TapChi_ten);xoaSpaces(a.TapChi_ten);
    cout<<"-Nhap ten bien tap : ";getenter;
    //cout<<endl
    getline(i,a.TapChi_bientap);xoaSpaces(a.TapChi_bientap);
    
    cout<<endl<<"-Nhap ma Nha xuat ban : ";getenter;
    //getline(i,a.NXB_id);
    i>>nxb;
    transform(nxb.begin(),nxb.end(),nxb.begin(),::toupper);
    a.NXB_id=nxb;
    
    return i;
    /*   string pub;
    cout << endl <<"- Nhap ten tap chi: ";
    getenter;
    getline(in,j.J_name);
    removeSpaces(j.J_name);
    cout << "- Nhap tong bien tap: ";
    getenter;
    getline(in,j.J_editor);
    cout << "- Nhap ma NXB: ";
    in >> pub;
    transform(pub.begin(), pub.end(), pub.begin(), ::toupper);
    j.Publisher_id = pub;
    return in;*/
}
void TapChi::setTapChi_ten(){
    cout<<endl<<"- Nhap ten tap chi : ";getenter;getline(cin,TapChi_ten);
}
void TapChi::setTapChi_bientap(){
    cout<<endl<<"- Nhap ten bien tap : ";getenter;getline(cin,TapChi_bientap);
}
void TapChi::setNXB_id(){ // nhung thu lien quan den Ma thi can dung ham transform
    string nxb;
    cout<<endl<<"- Nhap ma NXB : ";cin>>nxb;
    transform(nxb.begin(),nxb.end(),nxb.begin(),::toupper);
    this->NXB_id=nxb;
}