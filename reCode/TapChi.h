#include <iostream>
#include <string.h>

using namespace std;
class TapChi{
    private:
        string TapChi_ten;
        string TapChi_id;
        string TapChi_bientap;
        string NXB_id;int Bao_count=0;
    public:
    friend class List;
//---------------file handle-------------------
    void TapChi_docfile(ifstream& i);
//---------------OVERLOAD----------------------
    friend istream& operator>>(istream&,TapChi&);
    friend ostream& operator<<(ostream&,const TapChi&);
//-------------GETTER/SETTER---------------------
    string getTapChi_id();
    string getTapChi_ten();

    void setTapChi_ten();
    void setTapChi_bientap();
    void setNXB_id();
};
