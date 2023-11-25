#include <iostream>
#include<fstream>
#include<algorithm>
#include "List.h"
//#include "hamKhac.h"
#include<string>
using namespace std;
menu m;
#define getenter fflush(stdin);
void MENU(List L)
{
    string Tenbaibao;
    string chon;
    string Mabaibao;
    string Matacgia;
    string Matapchi;
    string MaNXB;
    int pos;
    int temp;
    do
    {
        m.mainMenu();
        cin>>temp;
        switch (temp)
        {
        case 0:
            temp =0;
            cout<<"Chuc ban mot ngay moi tot lanh!"<<endl;
            break;
        case 1:
            int temp1;
            system("cls");
            do
            {
                m.Menu_Display();
                cin>>temp1;
                switch (temp1)
                    {
                    case 0:
                        temp1 =0;
                        system("cls");
                        break;
                    case 1:
                        L.List_displayBao();
                        cout << endl;
                        system("pause");
                        system("cls");
                        temp1 =0;
                        break;
                    case 2:
                        L.List_displayTacGia();
                        cout << endl;
                        system("pause");
                        system("cls");
                        temp1 =0;
                        break;
                    case 3:
                        L.List_displayTapChi();
                        cout << endl;
                        system("pause");
                        system("cls");
                        temp1 =0;
                        break;
                    case 4:
                        L.List_displayNXB();
                        cout << endl;
                        system("pause");
                        system("cls");
                        temp1 =0;
                        break;
                    default:
                        cout<<"Ban da nhap sai!!! Vui long nhap [1/2/3/...]"<<endl;
                        cout << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
            } 
            while(temp1!=0);
            break;
        case 2: 
            system("cls");
            int temp2;
            do
            {
                m.Menu_ChinhSua();
                cin>>temp2;
                switch (temp2)
                {
                case 0:
                    temp2 =0; 
                    system("cls");
                    break;
                case 1:
                    L.List_setBao(m);
                    L.List_outBao();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp2 =0;
                    break;
                case 2:
                    L.List_setTacGia(m);
                    L.List_outTacGia();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp2 =0;
                    break;
                case 3:
                    L.List_setTapChi(m);
                    L.List_outTapChi();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp2 =0;
                    break;
                case 4:
                    L.List_setNXB(m);
                    L.List_outNXB();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp2 =0;
                    break;
                default:
                    cout<< endl << "Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (temp2);
            break;
        case 3:
            system("cls");
            int temp3;
            do
            {
                m.Menu_Them();
                cin>>temp3;
                switch (temp3)
                {
                case 0:
                    temp3 =0;
                    system("cls");
                    break;
                case 1:
                    system("cls");
                    int case1;
                    do 
                    {   
                        m.Menu2_ThemBao();
                        cin >> case1;
                        switch (case1)
                        {
                            case 1:
                                cout << endl << "- Nhap ma bai bao: ";
                                cin >> Mabaibao;
                                xoaSpaces(Mabaibao);
                                L.List_addBao(Mabaibao);
                                L.List_updateCount();
                                cout << endl;
                                system("pause");
                                system("cls");
                                case1 = 0;
                                break;
                            case 2:
                                cout << endl << "- Nhap ma bai bao: ";
                                cin >> Mabaibao;
                                xoaSpaces(Mabaibao);
                                L.List_insertBao(Mabaibao);
                                L.List_updateCount();
                                cout << endl;
                                system("pause");
                                system("cls");
                                case1 = 0;
                                break;
                            case 0:
                                case1 = 0;
                                cout << endl;
                                system("pause");
                                system("cls");
                                break;
                        }
                    } while(case1);
                    system("cls");
                    temp3 =0;
                    break;
                case 2:
                    cout << endl << "- Nhap ma tac gia: ";
                    cin >> Matacgia;
                    xoaSpaces(Matacgia);
                    L.List_addTacGia(Matacgia);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp3 =0;
                    break;
                case 3:
                    cout<< endl << "- Nhap ma tap chi: ";
                    cin >> Matapchi;
                    xoaSpaces(Matapchi);
                    L.List_addTapChi(Matapchi);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp3 =0;
                    break;
                case 4:
                    cout << endl << "- Nhap ma NXB: ";
                    cin >> MaNXB;
                    xoaSpaces(MaNXB);
                    L.List_addNXB(MaNXB);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp3 =0;
                    break;
                default:
                    cout<< endl <<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (temp3);
            break;
        case 4:
            system("cls");
            int temp4;
            do
            {
                m.Menu_Xoa();
                cin>>temp4;
                switch (temp4)
                {
                case 0:
                    temp4 =0;
                    system("cls");
                    break;
                case 1:
                    cout<<endl << "- Nhap ma bai bao can xoa: ";
                    cin>>Mabaibao;
                    xoaSpaces(Mabaibao);
                    L.List_deleteBaoTheoBao_id(Mabaibao);
                    L.List_updateCount();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                case 2:
                    cout << endl << "- Nhap vi tri bai bao can xoa: ";
                    cin >> pos;
                    L.List_deleteBaoTheoViTri(pos-1);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                case 3:
                    cout <<endl << "- Nhap ma tac gia can xoa: ";
                    cin >>Matacgia;
                    xoaSpaces(Matacgia);
                    L.List_deleteTacGiaTheoTacGia_id(Matacgia);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                case 4:
                    cout <<endl << "- Nhap ma tap chi can xoa: ";
                    cin >>Matapchi;
                    xoaSpaces(Matapchi);
                    L.List_deleteTapChiTheoTapChi_id(Matapchi);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                case 5:
                    cout <<endl << "- Nhap ma NXB can xoa: ";
                    cin >>MaNXB;
                    xoaSpaces(MaNXB);
                    L.List_deleteNXBTheoNXB_id(MaNXB);
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                default:
                    cout<<endl<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (temp4);
            break;
        case 5:
            int temp5;
            system("cls");
            do
            {
                m.Menu_SoLuongBao();
                cin>>temp5;
                switch (temp5)
                {
                case 0:
                    temp5 = 0;
                    system("cls");
                    break;
                case 1:
                    L.List_soLuongBaoTheoTacGia();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp5 = 0;
                    break;
                case 2:
                    L.List_soLuongBaoTheoTapChi();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp5 = 0;
                    break;
                case 3:
                    L.List_soLuongBaoTheoNXB();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp5 = 0;
                    break;
                case 4:
                    L.List_soLuongBaoTheoNam();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp5 = 0;
                    break;
                
                default:
                    cout<<endl<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(temp5);
            break;   
        case 6:
            system("cls");
            int temp6;
            do
            {
                m.Menu_TimBao();
                cin>>temp6;
                switch (temp6)
                {
                case 0:
                    temp6 =0;
                    system("cls");
                    break;
                case 1:
                    cout<<endl << "- Nhap ten bai bao can tim kiem: ";
                    getenter;
                    getline(cin,Tenbaibao);
                    xoaSpaces(Tenbaibao);
                    if(!L.List_timBaoTheoBao_ten(Tenbaibao)) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 2:
                    if(!L.List_timBaoTheoBao_id()) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 3:
                    if(!L.List_timBaoTheoTacGia_ten()) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 4:
                    if(!L.List_timBaoTheoTacGia_id()) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 5:
                    if(!L.List_timBaoTheoTapChi_id()) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 6:
                    if(!L.List_timBaoTheoNXB_id()) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 7:
                    if(!L.List_timBaoTheoNam()) cout << endl << "Khong tim thay bai bao!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                default:
                    cout<<endl<<"Ban da nhap sai!!!"<<endl;
                    system("cls");
                    break;
                }       
            } while (temp6);
            break;
        case 7:
            system("cls");
            int temp7;
            do
            {   
                m.Menu_SapXepBao();
                cin>>temp7;
                switch (temp7)
                {
                case 0:
                    temp7 =0;
                    system("cls");
                    break;
                case 1:
                    L.List_sapXepBaoTheoTacGia_ten();
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                case 2:
                    cout<<endl << "- Ban muon sap xep tang dan hay giam dan?(T/G): ";
                    cin>>chon;
                    transform(chon.begin(), chon.end(), chon.begin(), ::toupper);
                    if(chon == "T")
                    {
                        L.List_sapXepBaoTheoBao_ten(Bao_tangdan);
                    }
                    else if (chon == "G") 
                    {
                        L.List_sapXepBaoTheoBao_ten(Bao_giamdan);
                    }
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                case 3:
                    cout<<endl << "- Ban muon sap xep tang dan hay giam dan?(T/G): ";
                    cin>>chon;
                    transform(chon.begin(), chon.end(), chon.begin(), ::toupper);
                    if(chon == "T")
                    {
                        L.List_sapXepBaoTheoNam(Nam_tangdan);
                    }
                    else if(chon == "G" ) 
                    {
                        L.List_sapXepBaoTheoNam(Nam_giamdan);
                    }
                    cout << endl;
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                default:
                    cout<<endl<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } 
            while (temp7);
            break;
        default:
            cout<<endl<<"Ban da nhap sai!!!"<<endl;
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (temp);
    
}

/////////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////////
int main() 
{

    List L{};
    // Lay so luong
    ifstream inFileNum("../Data/InitialNum.txt");
    List::get_initialNum(inFileNum);
    //cout<<"check "<<List::TacGia_count<<" "<<List::TapChi_count<<" "<<List::Bao_count<<" "<<List::NXB_count<<endl;
    // Get data NXB
    ifstream inFilePub("../Data/Publisher.txt");
    if (inFilePub.fail()) cout << "Failed to open file";
    else L.List_getNXB(inFilePub);

    // Get data Article
    ifstream inFileArt("../Data/Article.txt");
    if (inFileArt.fail()) cout << "Failed to open file";
    else L.List_getBao(inFileArt);

    // Get data Journal
    ifstream inFileJou("../Data/Journal.txt");
    if (inFileJou.fail()) cout << "Failed to open file";
    else L.List_getTapChi(inFileJou);

    //Get data Author
    ifstream inFileAuth("../Data/Author.txt");
    if (inFileAuth.fail()) cout << "Failed to open file";
    else L.List_getTacGia(inFileAuth);
   // cout<<List::tg[0].TacGia_ma;
    //Get number of article for author/journal/NXB list
    L.List_updateCount();

    //PBL2 Information
    m.info();

    //Main menu
    MENU(L);
   
    //Close file, end program
    inFileArt.close();
    inFileJou.close();
    inFileAuth.close();
    inFilePub.close();

    return 0;
}
