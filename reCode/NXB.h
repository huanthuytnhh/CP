#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class List;
class NXB{
    private:
        string NXB_id;
        string NXB_ten;
        int Bao_count=0;
        int TapChi_count=0;
    public:
        friend class List;
        void NXB_docfile(ifstream &);
        
        friend ostream& operator<<(ostream&,const NXB&);
        friend istream& operator>>(istream&,NXB&);

        void setNXB_ten();       
};