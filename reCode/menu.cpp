#include"menu.h"
#include<iostream>
#include<iomanip>
using namespace std;
void menu::info(){
    cout<<endl;
    cout<<"\t\t\t -------------------------------------------------------------\n";
    cout<<"\t\t\t|                                                             |\n";
    cout<<"\t\t\t|               PBL 2: DO AN CO SO LAP TRINH                  |\n";
    cout<<"\t\t\t|      DE TAI: CHUONG TRINH QUAN LY CAC BAI BAO NGHIEN CUU    |\n";
    cout<<"\t\t\t|                                                             |\n";
    cout<<"\t\t\t|     Sinh vien thuc hien :            Giao vien huong dan :  |\n";
    cout<<"\t\t\t|     Le Ngoc Thanh                    Thay Chau              |\n";
    cout<<"\t\t\t|     Ngo Xuan Ninh                                           |\n";
    cout<<"\t\t\t -------------------------------------------------------------\n";
}
void menu::mainMenu(){
    cout<<endl;
    cout<<"\t\t\t -------------------------------------------------------------\n";
    cout<<"\t\t\t|                         MENU                                |\n";
    cout<<"\t\t\t|     1. Hien thi thong tin                                   |\n";
    cout<<"\t\t\t|     2. Chinh sua thong tin                                  |\n";
    cout<<"\t\t\t|     3. Them thong tin                                       |\n";
    cout<<"\t\t\t|     4. Xoa thong tin                                        |\n";
    cout<<"\t\t\t|     5. Thong ke so luong bai bao                            |\n";
    cout<<"\t\t\t|     6. Tim kiem bai bao                                     |\n";
    cout<<"\t\t\t|     7. Sap xep bai bao                                      |\n";
    cout<<"\t\t\t|     0. Thoat                                                |\n";
    cout<<"\t\t\t -------------------------------------------------------------\n";
    cout<<"\t\t\t Luc chon cua ban la [0/1/2/3/..] : ";
}
void menu::Menu_Display(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  HIEN THI THONG TIN                       |\n";
    cout<<"\t\t\t|     1. Bai bao                                            |\n";
    cout<<"\t\t\t|     2. Tac gia                                            |\n";
    cout<<"\t\t\t|     3. Tap chi                                            |\n";
    cout<<"\t\t\t|     4. Nha xuat ban                                       |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
  //  cout<<"\t\t\t|                                                           |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
     cout<<"\t\t\t Luc chon cua ban la [0/1/2/3/..] : ";
}
void menu::Menu_ChinhSua(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  CHINH SUA THONG TIN                      |\n";
    cout<<"\t\t\t|     1. Bai bao                                            |\n";
    cout<<"\t\t\t|     2. Tac gia                                            |\n";
    cout<<"\t\t\t|     3. Tap chi                                            |\n";
    cout<<"\t\t\t|     4. Nha xuat ban                                       |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
  //  cout<<"\t\t\t|                                                           |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
     cout<<"\t\t\t Luc chon cua ban la [0/1/2/3/..] : ";
}
void menu::Menu2_ChinhSuaBao(string Bao_id){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  CHINH SUA THONG TIN BAI BAO "<<Bao_id<<left<<setw(20)<<"|\n";
    cout<<"\t\t\t|     1. Ten bai bao                                        |\n";
    cout<<"\t\t\t|     2. Ten tac gia                                        |\n";
    cout<<"\t\t\t|     3. Ten tap chi                                        |\n";
    cout<<"\t\t\t|     4. Nam cong bo                                        |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu2_ChinhSuaTacGia(string TacGia_id){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  CHINH SUA THONG TIN TAC GIA "<<TacGia_id<<left<<setw(20)<<"|\n";
    cout<<"\t\t\t|     1. Ten tac gia                                        |\n";
    cout<<"\t\t\t|     2. Noi cong tac                                       |\n";
    cout<<"\t\t\t|     3. Linh vuc                                           |\n";
    cout<<"\t\t\t|     4. Trinh do                                           |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu2_ChinhSuaTapChi(string TapChi_id){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  CHINH SUA THONG TIN TAP CHI "<<TapChi_id<<left<<setw(20)<<"|\n";
    cout<<"\t\t\t|     1. Ten tap chi                                        |\n";
    cout<<"\t\t\t|     2. Tong bien tap                                      |\n";
    cout<<"\t\t\t|     3. Nha xuat ban                                       |\n";
//    cout<<"\t\t\t|     4. Trinh do                                           |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu_Them(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  THEM THONG TIN                           |\n";
    cout<<"\t\t\t|     1. Bai bao                                            |\n";
    cout<<"\t\t\t|     2. Tac gia                                            |\n";
    cout<<"\t\t\t|     3. Tap chi                                            |\n";
    cout<<"\t\t\t|     4. Nha xuat ban                                       |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
  //  cout<<"\t\t\t|                                                           |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu2_ThemBao(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  THEM BAI BAO                             |\n";
    cout<<"\t\t\t|     1. Vao vi tri mac dinh                                |\n";
    cout<<"\t\t\t|     2. Vao vi tri tuy chon                                |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu_Xoa(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  HIEN THI THONG TIN                       |\n";
    cout<<"\t\t\t|     1. Bai bao                                            |\n";
    cout<<"\t\t\t|     2. Tac gia                                            |\n";
    cout<<"\t\t\t|     3. Tap chi                                            |\n";
    cout<<"\t\t\t|     4. Nha xuat ban                                       |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
  //  cout<<"\t\t\t|                                                           |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}

void menu::Menu_SoLuongBao(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  THONG KE SO LUONG BAI BAO                |\n";
    cout<<"\t\t\t|     1. Theo tac gia                                       |\n";
    cout<<"\t\t\t|     2. Theo tap chi                                       |\n";
    cout<<"\t\t\t|     3. Theo nha xuat ban                                  |\n";
    cout<<"\t\t\t|     4. Theo nam xuat ban                                  |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu_TimBao(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  TIM KIEM BAI BAO                         |\n";
    cout<<"\t\t\t|     1. Theo ten bai bao                                   |\n";
    cout<<"\t\t\t|     2. Theo ma bai bao                                    |\n";
    cout<<"\t\t\t|     3. Theo ten tac gia                                   |\n";
    cout<<"\t\t\t|     4. Theo ma tac gia                                    |\n";
    cout<<"\t\t\t|     5. Theo ma tac gia                                    |\n";
    cout<<"\t\t\t|     6. Theo ma nha xuat ban                               |\n";
    cout<<"\t\t\t|     7. Theo nam xuat ban                                  |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
  //  cout<<"\t\t\t|                                                           |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
void menu::Menu_SapXepBao(){
    cout<<endl;
    cout<<"\t\t\t -----------------------------------------------------------\n";
    cout<<"\t\t\t|                  SAP XEP BAI BAO                          |\n";
    cout<<"\t\t\t|     1. Theo ten tac gia                                   |\n";
    cout<<"\t\t\t|     2. Theo ten bai bao                                   |\n";
    cout<<"\t\t\t|     3. Theo nam                                           |\n";
    cout<<"\t\t\t|     0. Thoat                                              |\n";
  //  cout<<"\t\t\t|                                                           |\n";
    cout<<"\t\t\t -----------------------------------------------------------\n";
}
