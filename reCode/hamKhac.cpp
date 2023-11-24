#include<iostream>
#include<string>

using namespace std;
#include "hamKhac.h"

void xoaSpaces(string& str){
    string str2;
    bool spaceFound=false;
    bool characterFound=false;
    for(char c:str){
        if(c==' ' ){
            if(characterFound) {if(!spaceFound){spaceFound=true;str2+=c;}}
        } else {
            str2+=c;
            spaceFound=false;
            characterFound=true;
        }
    }
    str=str2;
}
bool Bao_tangdan(Bao x,Bao y){
    if(x.getBao_ten().compare(y.getBao_ten())==1)return true;
    else return false;
}
bool Bao_giamdan(Bao x,Bao y){
    if(x.getBao_ten().compare(y.getBao_ten())!=1)return true;
    else return false;
}
bool Nam_tangdan(Bao x,Bao y){
    if(x.getThoiGianCongBo()>y.getThoiGianCongBo())return true;
    else return false;
}
bool Nam_giamdan(Bao x,Bao y){
    if(x.getThoiGianCongBo()<y.getThoiGianCongBo())return true;
    else return false;
}