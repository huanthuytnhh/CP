#include <iostream>
#include<string.h>
#include<string>
using namespace std;
class List;
class Bao{
    private:
        string Bao_id;
        string TacGia_id;
        string TapChi_id;
        string Bao_ten;
        int ThoiGianCongBo;
        int ThoiGian_count=0;
    public:
        friend class List;
//-----------FILE HANDLE-------------------------
        void Bao_docfile(ifstream&);
//----------------OVERLOAD--------------------------    
        friend ostream& operator<<(ostream&,const Bao&);
        friend istream& operator>>(istream&,Bao&);
//----------------SETTER------------------------------    
        void setBao_ten();
        void setBao_tacgia();
        void setBao_tapchi();
        void setBao_thoigiancongbo();
//------------------GETTER----------------------------
        int getThoiGianCongBo();
        string getBao_ten();
};