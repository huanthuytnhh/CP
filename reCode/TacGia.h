#include <iostream>
#include<string.h>
//#include<fstream>
using namespace std;
class List;
class TacGia{
    private:
        string TacGia_id;
        string TacGia_ho;
        string TacGia_ten;
        string TacGia_congtac;
        string TacGia_linhvuc;
        string TacGia_trinhdo;
        int Bao_count=0;
        float xep_hang;
    public:
        friend class List;
//----------CONSTRUCTOR-----------------
        TacGia();
        TacGia(const TacGia&);
        ~TacGia();
//-------------FILE HANDLE------------------
        void TacGia_docfile(ifstream&);
//--------------GETTER----------------        
        string getTacGia_ten();
        string getTacGia_ho();
        string getTacGia_id();
//-------------OVERLOAD---------------------
        friend istream &operator>>(istream&,TacGia&);
        friend ostream &operator<<(ostream&,const TacGia&);
//--------------SETTER-------------------------
        void setTacGia_ten();
        void setTacGia_ho();
        void setTacGia_congtac();
        void setTacGia_linhvuc();
        void setTacGia_trinhdo();
};