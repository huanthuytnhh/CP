#include"TacGia.h"
//#include"Bao.h"
#include "TapChi.h"
#include "NXB.h"
#include "hamKhac.h"
#include "menu.h"
#include<fstream>
#include<iostream>
using namespace std;
class TacGia;
class TapChi;
class Bao;
class NXB;

class List{
    private :
        TacGia *tg;
        TapChi *tc;
        Bao *b;
        NXB *nxb;
    public:
        friend class TacGia;
        friend class Bao;
        friend class TapChi;
         static int TacGia_count;
         static int Bao_count;
         static int TapChi_count;
         static int NXB_count;
        // QUY TAC DAT TEN : phần đầu là nơi chứa , tiếp theo là tên hàm chữ đầu không viết hoa
        ~List();
        void get_initialNum(ifstream &);
//          getter
        void List_getTacGia(ifstream&);
        void List_getTapChi(ifstream&);
        void List_getBao(ifstream&);
        void List_getNXB(ifstream&);
    //  Chinh sua thong tin
        void List_setTacGia(menu); // set thu cong
        void List_setTacGia_general(menu,TacGia&);// set tu mot doi tuong Tac Gia
        void List_setTapChi(menu);
        void List_setTapChi_general(menu,TapChi&);
        void List_setNXB(menu);
        void List_setBao(menu);
        void List_setBao_general(menu,Bao&);
        // hien thi thong tin
        void List_displayTacGia();
        void List_displayTapChi();
        void List_displayBao();
        void List_displayNXB();
        // Thong Ke so luong bao
        void List_soLuongBaoTheoTacGia();
        void List_soLuongBaoTheoTapChi();
        void List_soLuongBaoTheoNXB();
        void List_soLuongBaoTheoNam();
        //Tim kiem bao
        bool List_timBaoTheoTacGia_id();
        bool List_timBaoTheoTapChi_id();
        bool List_timBaoTheoNXB_id();
        bool List_timBaoTheoBao_id();
        bool List_timBaoTheoNam();
        bool List_timBaoTheoBao_ten(string);
        bool List_timBaoTheoTacGia_ten();
        //Sap xep bao
        void List_sapXepBaoTheoTacGia_ten();
        void List_sapXepBaoTheoBao_ten(bool(*compare)(Bao,Bao));
        void List_sapXepBaoTheoNam(bool(*compare)(Bao,Bao)); 
        // cac ham dung khi muon in cac thong tin ra man hinh
        string List_getTacGia_tenTheoTacGia_id(string);
        string List_getTacGia_hoTheoTacGia_id(string);
        string List_getTapChi_tenTheoTapChi_id(string);
        string List_getNXB_idTheoTapChi_id(string);
        //check valid thong tin
        bool List_isNewTacGia(string);
        bool List_isNewTapChi(string);
        bool List_isNewNXB(string);
        bool List_isNewBao(string);// string khong ton tai trong data
        friend int getTacGiaCount();
        //them mac dinh
        void List_addTacGia(string);
        void List_addTapChi(string);
        void List_addBao(string);
        void List_addNXB(string);
        //them vao vi tri tuy chinh
        void List_insertTacGia(string);
        void List_insertTapChi(string);
        void List_insertBao(string);
        void List_insertNXB(string);
        //Xuat ra file
        void List_outTacGia();
        void List_outTapChi();
        void List_outNXB();
        void List_outBao();
        void List_outInitialNum();
        // Xoa
        void List_deleteBaoTheoBao_id(string);
        void List_deleteBaoTheoViTri(int);
        void List_deleteTacGiaTheoTacGia_id(string);
        void List_deleteTapChiTheoTapChi_id(string);
        void List_deleteNXBTheoNXB_id(string);
        // cap nhat so luong bai bao trong cac List TacGia,TapChi,NXB
        void List_updateCount();// update Bao_count ;
};