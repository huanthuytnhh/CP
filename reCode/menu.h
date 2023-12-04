#include<iostream>
#include <string.h>
#include<string>
using namespace std;
class menu{
    public:
        void info(); // Thong tin nguoi lam 
        int mainMenu();
        int Menu_Display();
        int Menu_ChinhSua();
        int Menu_Them();  
        int Menu_Xoa();
        int Menu_SoLuongBao();
        int Menu_TimBao();
        int Menu_SapXepBao();
        
        int Menu2_ThemBao();

        int Menu2_ChinhSuaBao(string);
        int Menu2_ChinhSuaTapChi(string);
        int Menu2_ChinhSuaTacGia(string);
        
};