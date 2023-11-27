#include "List.h"
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
int List::Bao_count = 0;
int List::TacGia_count = 0;
int List::TapChi_count = 0;
int List::NXB_count = 0;
List::~List()
{
    delete[] tg;
    delete[] tc;
    delete[] b;
    delete[] nxb;
}
void List::get_initialNum(ifstream &i)
{
    string temp; //string temp2;
    getline(i, temp, '|');
    i >> Bao_count;
    getline(i, temp, '\n');
    getline(i, temp, '|');
    i >> TacGia_count;
    getline(i, temp, '\n');
    getline(i, temp, '|');
    i >> TapChi_count;
    getline(i, temp, '\n');
    getline(i, temp, '|');
    i >> NXB_count;
}
//     GETTER
void List::List_getNXB(ifstream &in)
{
    string temp;
    getline(in, temp, '\n');  // read panel
  //  cout<<" check getNXB :"<<temp;
    this->nxb = new NXB[List::NXB_count]; // cap phat dong mang nxb[NXB_count];
    for (int i = 0; i < List::NXB_count; i++)
    {
         string temp2;
        this->nxb[i].NXB_docfile(in);
       // cout<<"check "<<nxb[i].NXB_id<<" "<<nxb[i].NXB_ten<<endl;
        getline(in, temp2, '\n');
    }
}
void List::List_getBao(ifstream &in)
{
    string temp;
    getline(in, temp, '\n');
    b = new Bao[Bao_count];
    for (int i = 0; i < Bao_count; i++)
    {
         string temp2;
        b[i].Bao_docfile(in);
        getline(in, temp2, '\n');
    }
}
void List::List_getTacGia(ifstream &in)
{
    string temp;
    getline(in, temp, '\n');
    tg = new TacGia[TacGia_count];
    for (int i = 0; i < TacGia_count; i++)
    {
        string temp2;
        tg[i].TacGia_docfile(in);
        getline(in, temp2, '\n');
    }
}
void List::List_getTapChi(ifstream &in)
{
    string temp;
    getline(in, temp, '\n');
    tc = new TapChi[TapChi_count];
    for (int i = 0; i < TapChi_count; i++)
    {
         string temp2;
        tc[i].TapChi_docfile(in);
        getline(in, temp2, '\n');
    }
}
//      HIEN THI THONG TIN
void List::List_displayBao()
{
    cout << endl
         << left << setw(15) << "Ma bao"
         << left << setw(65) << "Ten bai bao"
         << left << setw(25) << "Tac Gia"
         << left << setw(45) << "Tap Chi"
         << left << setw(10) << "Thoi Gian" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < Bao_count; i++)
    {
        cout << left << setw(15) << b[i].Bao_id
             << left << setw(65) << b[i].Bao_ten
             << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].TacGia_id)
             << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
             << left << setw(10) << b[i].ThoiGianCongBo << endl;
    }
}
void List::List_displayTapChi()
{
    cout << endl
         << left << setw(15) << "Ma tap chi"
         << left << setw(50) << "Ten tap chi"
         << left << setw(30) << "Ten tong bien tap"
         << left << setw(15) << "Ma NXB"<<endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < TapChi_count; i++)
    {
        cout << left << setw(15) << tc[i].TapChi_id
             << left << setw(50) << tc[i].TapChi_ten
             << left << setw(30) << tc[i].TapChi_bientap
             //      <<left<<setw(45)<<List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
             << left << setw(15) << tc[i].NXB_id << endl;
    }
}
void List::List_displayTacGia()
{
    cout<<"check "<<tg[0].TacGia_id<<endl;
    cout << endl
         << left << setw(15) << "Ma tac gia"
         << left << setw(30) << "Ho"
         << left << setw(15) << "Ten"
         << left << setw(30) << "Noi cong tac"
         << left << setw(30) << "Linh vuc"
         << left << setw(15) << "Trinh do" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < TacGia_count; i++)
    {
        cout << left << setw(15) << tg[i].TacGia_id
             << left << setw(30) << tg[i].TacGia_ho
             << left << setw(15) << tg[i].TacGia_ten
             << left << setw(30) << tg[i].TacGia_congtac
             << left << setw(30) << tg[i].TacGia_linhvuc
             << left << setw(15) << tg[i].TacGia_trinhdo << endl;
    }
}
void List::List_displayNXB()
{
    cout << endl
         << left << setw(15) << "Ma NXB"
         << left << setw(30) << "Ten NXB" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < List::NXB_count; i++)
    {
        cout << left << setw(15) << nxb[i].NXB_id
          << left << setw(30) << nxb[i].NXB_ten << endl;
    }
}
string List::List_getTacGia_hoTheoTacGia_id(const string& TacGia_id)
{
    for (int i = 0; i < TacGia_count; i++)
    {
        if (tg[i].TacGia_id == TacGia_id)
            return tg[i].getTacGia_ho();
    }
    return "NULL";
}
string List::List_getTacGia_tenTheoTacGia_id(const string& TacGia_id)
{
    for (int i = 0; i < TacGia_count; i++)
    {
        if (tg[i].TacGia_id == TacGia_id)
            return tg[i].getTacGia_ten();
    }
    return "NULL";
}
string List::List_getTapChi_tenTheoTapChi_id(const string& TapChi_id)
{
    for (int i = 0; i < TapChi_count; i++)
    {
        if (tc[i].TapChi_id == TapChi_id)
            return tc[i].getTapChi_ten();
    }
    return "NULL";
}
string List::List_getNXB_idTheoTapChi_id(const string& TapChi_id)
{
    for (int i = 0; i < TapChi_count; i++)
    {
        if (tc[i].TapChi_id == TapChi_id)
            return tc[i].NXB_id;
    }
    return "NULL";
}
// ---------SETTER------------------
void List::List_setBao(menu m)
{
    int i = 0;
    string Baoid;
    cout << endl
         << "-Nhap ma bai bao can sua doi thong tin";
    cin >> Baoid;
    transform(Baoid.begin(), Baoid.end(), Baoid.begin(), ::toupper);
    if (List_isNewBao(Baoid))
        cout << endl
             << "Nhap sai ma bai " << endl;
    else
    {
        for (i = 0; i < Bao_count; i++)
        {
            if (b[i].Bao_id == Baoid)
            {
                break;
            }
        }
        m.Menu2_ChinhSuaBao(b[i].Bao_id);
        List_setBao_general(m, b[i]);
    }
}
void List::List_setBao_general(menu m, Bao &a)
{
    int choice = 100;
    do
    {
        cout << "Nhap lua chon :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.setBao_ten();
            cout << endl
                 << "Da chinh sua thanh cong " << endl;
            List_setBao_general(m, a);
            break;
        case 2:
        {
            string tempTacGia_id = a.TacGia_id;
            a.setBao_tacgia();
            if (List_isNewTacGia(a.TacGia_id))
            {
                cout << endl
                     << "Tac gia chua ton tai " << endl
                     << "Ban co muon them tac gia moi [Y/N]";
                char choice2;
                cin >> choice2;
                choice2 = toupper(choice2);
                if (choice2 == 'Y')
                    List_addTacGia(a.TacGia_id);
                else
                    a.TacGia_id = tempTacGia_id;
            }
            cout << endl
                 << "Da chinh sua xong " << endl;
            List_setBao_general(m, a);
            break;
        }
        case 3:
        {
            string tempTapChi_id = a.TapChi_id;
            a.setBao_tapchi();
            if (List_isNewTapChi(a.TapChi_id))
            {
                cout << endl
                     << "Tap Chi khong ton tai " << endl
                     << "ban co muon them moi [Y/N]";
                char choice2;
                cin >> choice2;
                toupper(choice2);
                if (choice2 == 'Y')
                    List_addTapChi(a.TapChi_id);
                else
                    a.TapChi_id = tempTapChi_id;
            }
            cout << "Da chinh sua thanh cong " << endl;
            List_setBao_general(m, a);
            break;
        }
        case 4:
        {
            a.setBao_thoigiancongbo();
            cout << "Da chinh sua thanh cong " << endl;
            List_setBao_general(m, a);
        }
        default:
            cout << "Lenh khong kha dung ,vui long nhap lai";
            List_setBao_general(m, a);
            break;
        }
    } while (choice != 0);
}
void List::List_setTacGia(menu m)
{
    int i = 0;
    string TacGiaid;
    cout << endl
         << "Nhap ma tac gia can sua thong tin";
    cin >> TacGiaid;
    transform(TacGiaid.begin(), TacGiaid.end(), TacGiaid.begin(), ::toupper); // chuan Hoa Id ve in hoa
    if (List_isNewTacGia(TacGiaid))
        cout << "nhap sai ma tac gia" << endl;
    else
    {
        for (i = 0; i < TacGia_count; i++)
        {
            if (tg[i].TacGia_id == TacGiaid)
                break;
        }
        m.Menu2_ChinhSuaTacGia(tg[i].TacGia_id);
        List_setTacGia_general(m, tg[i]);
    }
}
void List::List_setTacGia_general(menu m, TacGia &a)
{
    int choice = 100;
    do
    {
        cout << "Nhap luc chon cua ban";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            a.setTacGia_ten();
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTacGia_general(m, a);
            break;
        case 2:
            a.setTacGia_congtac();
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTacGia_general(m, a);
            break;
        case 3:
            a.setTacGia_linhvuc();
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTacGia_general(m, a);
            break;
        case 4:
            a.setTacGia_trinhdo();
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTacGia_general(m, a);
            break;
        default:
            cout << "Cu phap khong hop le , moi nhap lai ";
            List_setTacGia_general(m, a);
            break;
        }

    } while (choice != 0);
}
void List::List_setTapChi(menu m)
{
    string TapChiid;
    int i = 0;
    cout << "Nhap ma tap chi muon chinh sua";
    cin >> TapChiid;
    if (List_isNewTapChi(TapChiid))
    {
        cout << "Tap chi khong ton tai ";
    }
    else
    {
        for (i = 0; i < TapChi_count; i++)
        {
            if (tc[i].TapChi_id == TapChiid)
                break;
        }
        m.Menu2_ChinhSuaTapChi(tc[i].TapChi_id);
        List_setTapChi_general(m, tc[i]);
    }
}
void List :: List_setNXB(menu m) 
{
    int i = 0; //Biến lấy phần tử bài báo trong list
    string PubID;
    cout << endl << "- Nhap ma NXB can sua thong tin: ";
    cin >> PubID;
    transform(PubID.begin(), PubID.end(), PubID.begin(), ::toupper);
    if (List_isNewNXB(PubID)) cout << endl<< "Nhap sai ma NXB!" << endl;
    else 
    {
        for (i=0; i<NXB_count; i++)
        {
            if (nxb[i].NXB_id == PubID) break;
        }
        cout << endl << "=== CHINH SUA NHA XUAT BAN : " << nxb[i].NXB_id << " ===" << endl;
        cout << endl << "Da chinh sua thanh cong!"<<endl << endl;
        nxb[i].setNXB_ten();
    }
}
void List::List_setTapChi_general(menu m, TapChi &a)
{
    int choice = 100;
    do
    {
        cout << "Nhap luc chon cua ban";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            a.setTapChi_ten();
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTapChi_general(m, a);
            break;
        case 2:
            a.setTapChi_bientap();
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTapChi_general(m, a);
            break;
        case 3:
        {
            string tempNXB_id = a.NXB_id;
            a.setNXB_id();
            if (List_isNewNXB(a.NXB_id))
            {
                cout << "Nha xuat ban chua ton tai " << endl
                     << "Ban co muon them nxb khong [Y/N]";
                char choice2;
                cin >> choice2;
                choice2 = toupper(choice2);
                if (choice2 == 'Y')
                    List_addNXB(a.NXB_id);
                else
                    a.NXB_id = tempNXB_id;
            }
            cout << endl
                 << "Da chinh sua thanh cong" << endl;
            List_setTapChi_general(m, a);
            break;
        }
        default:
            cout << "Cu phap khong hop le , moi nhap lai ";
            List_setTapChi_general(m, a);
            break;
        }

    } while (choice != 0);
}
bool List::List_isNewTacGia(const string& TacGiaID)
{
    for (int i = 0; i < TacGia_count; i++)
    {
        if (tg[i].TacGia_id == TacGiaID)
            return false;
    }
    return true;
}
bool List::List_isNewTapChi(const string& TapChiID)
{
    for (int i = 0; i < TapChi_count; i++)
    {
        if (tc[i].TapChi_id == TapChiID)
            return false;
    }
    return true;
}
bool List::List_isNewNXB(const string& NXBID)
{
    for (int i = 0; i < NXB_count; i++)
    {
        if (nxb[i].NXB_id == NXBID)
            return false;
    }
    return true;
}
bool List::List_isNewBao(const string& BaoID)
{
    for (int i = 0; i < Bao_count; i++)
    {
        if (b[i].Bao_id == BaoID)
            return false;
    }
    return true;
}
void List::List_addTacGia(string TacGiaID)
{
    transform(TacGiaID.begin(), TacGiaID.end(), TacGiaID.begin(), ::toupper);
    if (List_isNewTacGia(TacGiaID))
    {
        List::TacGia_count++;
        int n = List::TacGia_count;
        TacGia a;
        a.TacGia_id = TacGiaID;
        cin >> a;
        auto *tg2=new TacGia[n - 1];
        for (int i = 0; i < n - 1; i++)
            tg2[i] = this->tg[i];
        delete[] this->tg;
        this->tg = new TacGia[n];
        for (int i = 0; i < n; i++)
            this->tg[i] = tg2[i];
       this->tg[n - 1] = a;
        this->List_outTacGia();
        List::List_outInitialNum();
        cout << endl
             << "Da them thanh cong" << endl;
    }
    else
    {
        cout << endl
             << "Tac gia da ton tai" << endl;
    }
}
void List::List_addNXB(string NXBID)
{
    transform(NXBID.begin(), NXBID.end(), NXBID.begin(), ::toupper);
    if (List_isNewNXB(NXBID))
    {
        NXB a;
        a.NXB_id = NXBID;
        cin >> a;
        List::NXB_count++;
        int n = List::NXB_count;
        NXB *nxb2=new NXB[n - 1];
        for (int i = 0; i < n - 1; i++)
            nxb2[i] = this->nxb[i];
        delete[] this->nxb;
        this->nxb = new NXB[n];
        for (int i = 0; i < n - 1; i++)
            this->nxb[i] = nxb2[i];
        this->nxb[n - 1] = a;
        this->List_outNXB();
        List::List_outInitialNum();
        cout << "Da them thanh cong" << endl;
    }
    else
    {
        cout << "Nha xuat ban da ton tai" << endl;
    }
}
void List::List_addTapChi(const string& TapChiID)
{
    if (List_isNewTapChi(TapChiID))
    {
        List::TapChi_count++;
        TapChi a;
        a.TapChi_id = TapChiID;
        cin >> a;
        if (List_isNewNXB(a.NXB_id))
        {
            cout << "Nha xuat ban ban vua nhap chua ton tai,va da duoc them " << endl;
            List_addNXB(a.NXB_id);
        }
        int n = List::TacGia_count;
        auto *tc2=new TapChi[n - 1];
        for (int i = 0; i < n - 1; i++)
            tc2[i] = tc[i];
        delete[] this->tc;
        for (int i = 0; i < n - 1; i++)
            this->tc[i] = tc2[i];
        this->tc[n - 1] = a;
        List_outTapChi();
        List_outInitialNum();
        cout << "Da them thanh cong" << endl;
    }
    else
    {
        cout << "Tap chi da ton tai" << endl;
    }
}
void List::List_addBao(string BaoID)
{
    transform(BaoID.begin(), BaoID.end(), BaoID.begin(), ::toupper);
    if (this->List_isNewBao(BaoID)) // Nếu là bài báo mới
    {
        List::Bao_count++; // Tăng số lượng bài báo lên 1
        Bao a;       // New TacGia
        a.Bao_id = BaoID;
        cin >> a;
        // a.T_id = TacGiaID;
        if (List_isNewTacGia(a.TacGia_id))
        {
            cout << endl<< "Nhap thong tin tac gia:" << endl;
            List_addTacGia(a.TacGia_id); // nếu tác giả nhập vào là tác giả mới thì thêm thông tin tác giả mới vào
        }
        if (List_isNewTapChi(a.TapChi_id))
        {
            cout << endl<< "- Nhap thong tin tap chi:" << endl;
            List_addTapChi(a.TapChi_id); // nếu tạp chí nhập vào là tạp chí mới thì thêm thông tin tạp chí mới vào
        }
        int n = List::Bao_count;
        Bao *b2=new Bao[List::Bao_count - 1];               // Mảng tĩnh sao chép tạm danh sách bài báo khi chưa thêm
        for (int i = 0; i < List::Bao_count - 1; i++) // Sao chép bài báo từ List sang mảng tĩnh
        {
            b2[i] = this->b[i];
        }
        delete[] this->b;     // Xóa danh sách bài báo cũ
        this->b = new Bao[List::Bao_count]; // Tạo mảng động danh sách bài báo mới cho list
        this->b[List::Bao_count - 1] = a;   // Cho bài báo mới thêm vào cuối danh sách
        for (int i = 0; i < List::Bao_count - 1; i++)
        {
            this->b[i] = b2[i]; // Chép từ mảng tạm sang danh sách chính
        }
        this->List_outTacGia();     // Update vào file dữ liệu bài báo
        List::List_outInitialNum(); // Update file số lượng
        cout << endl<< "Da them thanh cong!" << endl<< endl;
    }
    else
        cout << endl<< "Bai bao da ton tai!" << endl;
}
void List::List_insertBao(string BaoID)
{
    transform(BaoID.begin(), BaoID.end(), BaoID.begin(), ::toupper);
    if (this->List_isNewBao(BaoID)) // Nếu là bài báo mới
    {
        List::Bao_count++;
        int pos;
        cout << "Moi nhap vi tri muon them" << endl;
        cin >> pos; // Tăng số lượng bài báo lên 1
        Bao a;      // New TacGia
        a.Bao_id = BaoID;
        cin >> a;
        // a.T_id = TacGiaID;
        if (List_isNewTacGia(a.TacGia_id))
        {
            cout << endl
                 << "Nhap thong tin tac gia:" << endl;
            List_addTacGia(a.TacGia_id); // nếu tác giả nhập vào là tác giả mới thì thêm thông tin tác giả mới vào
        }
        if (List_isNewTapChi(a.TapChi_id))
        {
            cout << endl
                 << "- Nhap thong tin tap chi:" << endl;
            List_addTapChi(a.TapChi_id); // nếu tạp chí nhập vào là tạp chí mới thì thêm thông tin tạp chí mới vào
        }
        int n = List::Bao_count;
        Bao *b2=new Bao[n - 1];               // Mảng tĩnh sao chép tạm danh sách bài báo khi chưa thêm
        for (int i = 0; i < n - 1; i++) // Sao chép bài báo từ List sang mảng tĩnh
        {
            b2[i] = this->b[i];
        }
        delete []this->b; // Xóa danh sách bài báo cũ
        this->b = new Bao[n];
        for (int i = 0; i < pos - 1; i++)
        {
            this->b[i] = b2[i];
        }               // Tạo mảng động danh sách bài báo mới cho list
        b[pos - 1] = a; // b[n] = a;                  //Cho bài báo mới thêm vào cuối danh sách
        for (int i = pos - 1; i < n - 1; i++)
        {
            this->b[i + 1] = b2[i]; // Chép từ mảng tạm sang danh sách chính
        }
        this->List_outTacGia();     // Update vào file dữ liệu bài báo
        List::List_outInitialNum(); // Update file số lượng
        cout << endl<< "Da them thanh cong!" << endl<< endl;
    }
    else
        cout << endl<< "Bai bao da ton tai!" << endl;
}
void List::List_updateCount()
{
    for (int i = 0; i < TacGia_count; i++)
    {
        tg[i].Bao_count = 0;
        for (int j = 0; j < Bao_count; j++)
        {
            if (tg[i].TacGia_id == b[j].TacGia_id)
                tg[i].Bao_count++;
        }
    }
    for (int i = 0; i < TapChi_count; i++)
    {
        tc[i].Bao_count = 0;
        for (int j = 0; j < Bao_count; j++)
        {
            if (tc[i].TapChi_id == b[j].TapChi_id)
                tc[i].Bao_count++;
        }
    }
    for (int i = 0; i < NXB_count; i++)
    {
        nxb[i].Bao_count = 0;
        for (int j = 0; j < Bao_count; j++)
        {
            if (nxb[i].NXB_id == List_getNXB_idTheoTapChi_id(b[i].TapChi_id))
                nxb[i].Bao_count++;
        }
    }
}
void List::List_soLuongBaoTheoTacGia()
{
    cout << left << setw(20) << "Ho" << left << setw(10) << "Ten" << left << setw(10) << "So bai bao" << endl;
    for (int i = 0; i < TacGia_count; i++)
    {
        cout << left << setw(20) << tg[i].getTacGia_ho() << left << setw(10) << tg[i].getTacGia_ten() << left << setw(10) << tg[i].Bao_count << endl;
    }
}
void List::List_soLuongBaoTheoTapChi()
{
    cout << left << setw(30) << "Tap Chi" << left << setw(10) << "So bai bao" << endl;
    for (int i = 0; i < TapChi_count; i++)
    {
        cout << left << setw(30) << tc[i].getTapChi_ten() << left << setw(10) << tc[i].Bao_count << endl;
    }
}
void List::List_soLuongBaoTheoNXB()
{
    cout << left << setw(30) << "Ten NXB" << left << setw(10) << "So bai bao" << endl;
    for (int i = 0; i < NXB_count; i++)
    {
        cout << left << setw(30) << nxb[i].NXB_ten << left << setw(10) << nxb[i].Bao_count;
    }
}
void List::List_soLuongBaoTheoNam()
{
    map<int, int> a;
    for (int i = 0; i < Bao_count; i++)
    {
        a[b[i].ThoiGianCongBo]++;
    }
    cout << left << setw(30) << "Nam xuat ban" << left << setw(10) << "So bai bao" << endl;
    for (auto i : a)
    {
        cout << left << setw(30) << i.first << left << setw(10) << i.second << endl;
    }
}
void List::List_outTacGia()
{
    fstream data;
    data.open("../Data/Author.txt", ios::app | ios::out);
    data << "Ma TG|Ho |Ten|Noi cong tac|Linh vuc nghien cuu|Trinh do\n";
    for (int i = 0; i < TacGia_count; i++)
    {
        data << tg[i].TacGia_id << "|";
        data << tg[i].TacGia_ho << "|";
        data << tg[i].TacGia_ten << "|";
        data << tg[i].TacGia_congtac << "|";
        data << tg[i].TacGia_linhvuc << "|";
        data << tg[i].TacGia_trinhdo << ",\n";
    }
    data.close();
}
void List::List_outTapChi()
{
    fstream data;
    data.open("../Data/TapChi.txt", ios::app | ios::out);
    data << "Ma tap chi|Ten tap chi|Ten tong bien tap|Ma NXB\n";
    for (int i = 0; i < TapChi_count; i++)
    {
        data << tc[i].TapChi_id << "|";
        data << tc[i].TapChi_ten << "|";
        data << tc[i].TapChi_bientap << "|";
        data << tc[i].NXB_id << ",\n";
    }
    data.close();
}
void List::List_outNXB()
{
    fstream data;
    data.open("../Data/Publisher.txt", ios::app | ios::out);
    data << "Ma NXB|Ten NXB\n";
    for (int i = 0; i < NXB_count; i++)
    {
        data << nxb[i].NXB_id << "|";
        data << nxb[i].NXB_ten << ",\n";
    }
    data.close();
}

void List::List_outBao()
{
    fstream data;
    data.open("../Data/Bao.txt", ios::app | ios::out);
    data << "Ma bao|Ten cong bo|Tac gia|Tap chi|Thoi gian\n";
    for (int i = 0; i < Bao_count; i++)
    {
        data << b[i].Bao_id << "|";

        data << b[i].Bao_ten << "|";
        data << b[i].TacGia_id << "|";
        data << b[i].TapChi_id << "|";
        data << b[i].ThoiGianCongBo << ",\n";
       // data <<  b[i].TacGia_trinhdo << ",\n";
    }
    data.close();
}
void List::List_outInitialNum()
{
    ofstream outFile("../Data/InitialNum.txt", ofstream::trunc);
    outFile << "Bao|";
    outFile <<  Bao_count << "\n";
    outFile << "TacGia|";
    outFile <<  TacGia_count << "\n";
    outFile << "TapChi|";
    outFile <<  TapChi_count << "\n";
    outFile << "NXB|";
    outFile <<  NXB_count;
    outFile.close();
}
void List::List_deleteBaoTheoBao_id(string id)
{
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    if (List_isNewBao(id))
        cout << endl
             << "Bai bao khong ton tai" << endl;
    else
    {
        int pos = 0;
        for (int i = 0; i < Bao_count; i++)
        {
            if (b[i].Bao_id == id)
            {
                pos = i;
                break;
            }
        }
        int n = Bao_count;
        Bao *b2=new Bao[n - 1];
        for (int i = 0; i < pos; i++)
        {
            b2[i] = b[i];
        }
        for (int i = pos + 1; i < n; i++)
        {
            b2[i - 1] = b[i];
        }
        Bao_count--;
        delete[] b;
        for (int i = 0; i < n - 1; i++)
        {
            b[i] = b2[i];
        }
        cout << endl
             << "Xoa thanh cong" << endl;
        List_outBao();
        List_outInitialNum();
    }
}
void List::List_deleteBaoTheoViTri(int pos)
{
    int n = Bao_count;
    if (pos < 0 || pos > n - 1)
    {
        cout << endl
             << "Xoa khong thanh cong!" << endl
             << endl;
        return;
    }
    else
    {
        Bao *b2=new Bao[n];                       // Mảng tĩnh sao chép tạm danh sách bài báo khi chưa xóa
        for (int i = 0; i <= n - 1; i++) // Sao chép bài báo từ List sang mảng tĩnh
        {
            b2[i] = b[i];
        }
        delete[] b;         // Xóa danh sách bài báo cũ
        Bao_count--;        // Giảm SL bài báo đi 1
        b = new Bao[n - 1]; // Tạo mảng động danh sách bài báo mới cho list
        for (int i = 0; i <= pos - 1; i++)
        {
            b[i] = b2[i]; // Chép bài báo từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
        }
        for (int i = pos; i < n - 1; i++)
        {
            b[i] = b2[i + 1]; // Chép bài báo từ vị trí pos->bcount-1 từ mảng tạm sang danh sách chính
        }
        cout << endl
             << "Xoa thanh cong!" << endl
             << endl;
        List_outBao();        // Update vào file dữ liệu bài báo
        List_outInitialNum(); // Update file số lượng
    }
}
void List::List_deleteTacGiaTheoTacGia_id(string id)
{
    char choice = 0;
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    if (List_isNewTacGia(id))
    {
        cout << "Tac gia chua ton lai " << endl;
    }
    else
    {
        int pos = 0;
        int n = TacGia_count;
        for (int i = 0; i < n; i++)
        {
            if (tg[i].TacGia_id == id)
            {
                pos = i;
                break;
            }
        }
        if (tg[pos].Bao_count > 0)
        {
            cout << endl
                 << " Tac gia " << tg[pos].TacGia_ten << "co :'" << tg[pos].Bao_count << "' bai bao"
                 << ". Ban co muon xoa [Y/N] " << endl;
            cin >> choice;
            choice = toupper(choice);
        }
        if (choice == 'Y')
        {
            auto *tg2=new TacGia[n - 1];
            for (int i = 0; i < pos; i++)
            {
                tg2[i] = tg[i];
            }

            for (int i = pos; i < n - 1; i++)
            {
                tg2[i] = tg[i + 1];
            }
            List::TacGia_count--;
            delete[] tg;
            tg = new TacGia[n - 1];
            for (int i = 0; i < n - 1; i++)
            {
                tg[i] = tg2[i];
            }
            cout << endl
                 << "Xoa thanh cong " << endl;
            List_outTacGia();
            List_outInitialNum();
        }
    }
}
void List::List_deleteTapChiTheoTapChi_id(string id)
{
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    if (this->List_isNewTapChi(id))
        cout << endl
             << "Tap chi chua ton tai!" << endl;
    else
    {
        int pos = 0;
        char c = 'C';
        for (int i = 0; i < TapChi_count; i++)
        {
            if (tc[i].TapChi_id == id)
            {
                pos = i;
                break;
            }
        }
        if (tc[pos].Bao_count > 0)
        {
            cout << endl
                 << "- Tap chi da co " << tc[pos].Bao_count << " bai bao. Ban co muon xoa tap chi? (c/k) ";
            cin >> c;
            c = toupper(c);
        }
        if (c == 'C')
        {
            auto *newTapChi=new TapChi[List::TapChi_count];        // Mảng tĩnh sao chép tạm danh sách TẠP CHÍ khi chưa xóa
            for (int i = 0; i < List::TapChi_count; i++) // Sao chép TẠP CHÍ từ List sang mảng tĩnh
            {
                newTapChi[i] = this->tc[i];
            }
            delete[] this->tc;                         // Xóa danh sách TẠP CHÍ cũ
            List::TapChi_count--;                      // Giảm SL TẠP CHÍ đi 1
            this->tc = new TapChi[List::TapChi_count]; // Tạo mảng động danh sách TẠP CHÍ mới cho list
            for (int i = 0; i < pos; i++)
            {
                this->tc[i] = newTapChi[i]; // Chép TẠP CHÍ từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
            }
            for (int i = pos; i < TapChi_count; i++)
            {
                this->tc[i] = newTapChi[i + 1]; // Chép TẠP CHÍ từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
            }
            cout << endl
                 << "Xoa thanh cong!" << endl
                 << endl;
            this->List_outTapChi();     // Update vào file dữ liệu TẠP CHÍ
            this->List_outInitialNum(); // Update file số lượng
        }
    }
}
void List::List_deleteNXBTheoNXB_id(string id)
{
    transform(id.begin(), id.end(), id.begin(), ::toupper);
    if (this->List_isNewNXB(id))
        cout << endl
             << "NXB chua ton tai!" << endl;
    else
    {
        int pos = 0;
        char c = 'C';
        for (int i = 0; i < NXB_count; i++)
        {
            if (nxb[i].NXB_id == id)
            {
                pos = i;
                break;
            }
        }
        if (nxb[pos].Bao_count > 0)
        {
            cout << endl
                 << "- NXB da co " << nxb[pos].Bao_count << " bai bao. Ban co muon xoa NXB? (c/k) ";
            cin >> c;
            c = toupper(c);
        }
        if (c == 'C')
        {
            NXB *newNXB=new NXB[List::NXB_count];              // Mảng tĩnh sao chép tạm danh sách NXB khi chưa xóa
            for (int i = 0; i < List::NXB_count; i++) // Sao chép NXB từ List sang mảng tĩnh
            {
                newNXB[i] = this->nxb[i];
            }
            delete[] this->nxb;                   // Xóa danh sách NXB cũ
            List::NXB_count--;                    // Giảm SL NXB đi 1
            this->nxb = new NXB[List::NXB_count]; // Tạo mảng động danh sách NXB mới cho list
            for (int i = 0; i < pos; i++)
            {
                this->nxb[i] = newNXB[i]; // Chép NXB từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
            }
            for (int i = pos; i < NXB_count; i++)
            {
                this->nxb[i] = newNXB[i + 1]; // Chép NXB từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
            }
            cout << endl
                 << "Xoa thanh cong!" << endl
                 << endl;
            this->List_outNXB();        // Update vào file dữ liệu NXB
            this->List_outInitialNum(); // Update file số lượng
        }
    }
}
void SWAP(Bao &x, Bao &y)
{
    Bao temp;
    temp = x;
    x = y;
    y = temp;
}
void List::List_sapXepBaoTheoTacGia_ten()
{
    for (int i = 0; i <= Bao_count - 2; i++)
    {
        for (int j = i + 1; j <= Bao_count - 1; j++)
        {
            if (b[i].Bao_ten.compare(b[j].Bao_ten) == 1)
            {
                SWAP(b[i], b[j]);
            }
        }
    }
    List_displayBao();
}
void List::List_sapXepBaoTheoNam(bool (*compare)(Bao, Bao))
{
    for (int i = 0; i <= Bao_count - 2; i++)
    {
        for (int j = i + 1; j <= Bao_count - 1; j++)
        {
            if ((*compare)(b[i], b[j]))
            {
                SWAP(b[i], b[j]);
            }
        }
    }
    List_displayBao();
}
void List::List_sapXepBaoTheoBao_ten(bool (*compare)(Bao, Bao))
{
    for (int i = 0; i <= Bao_count - 2; i++)
    {
        for (int j = i + 1; j <= Bao_count - 1; j++)
        {
            if ((*compare)(b[i], b[j]))
            {
                SWAP(b[i], b[j]);
            }
        }
    }
    List_displayBao();
}

bool List::List_timBaoTheoBao_ten(string ten)
{ // vi du ten khoa , nhap 'kho' van tim ra duoc
    bool appeared = false;
    transform(ten.begin(), ten.end(), ten.begin(), ::toupper);
    for (int i = 0; i < Bao_count; i++)
    {
        string temp = b[i].Bao_ten;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp.find(ten) != string::npos)
        {
            if (!appeared)
            {
                appeared = true;
                cout << endl
                     << left << setw(15) << "Ma bao"
                     << left << setw(65) << "Ten bai bao"
                     << left << setw(25) << "Tac Gia"
                     << left << setw(45) << "Tap Chi"
                     << left << setw(10) << "Thoi Gian" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }
    return appeared;
}
bool List::List_timBaoTheoTacGia_ten()
{
    bool appeared = false;
    cout << endl
         << "Nhap ten tac gia :";
    string ten;
    cin >> ten;
    xoaSpaces(ten);
    transform(ten.begin(), ten.end(), ten.begin(), ::toupper);
    for (int i = 0; i < Bao_count; i++)
    {
        string temp = List_getTacGia_tenTheoTacGia_id(b[i].TacGia_id);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp.find(ten) != string::npos)
        {
            if (!appeared)
            {
                appeared = true;
                cout << endl
                     << left << setw(15) << "Ma bao"
                     << left << setw(65) << "Ten bai bao"
                     << left << setw(25) << "Tac Gia"
                     << left << setw(45) << "Tap Chi"
                     << left << setw(10) << "Thoi Gian" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }
    return appeared;
}
bool List::List_timBaoTheoBao_id()
{
    bool appeared = false;
    string id;
    do
    {
        cout << "Nhap ma bai bao: " << endl;
        cin >> id;
        xoaSpaces(id);
        transform(id.begin(), id.end(), id.begin(), ::toupper);
    } while (List_isNewBao(id));
    for (int i = 0; i < Bao_count; i++)
    {
        string temp = (b[i].TacGia_id);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if ((id) == temp)
        {
            if (!appeared)
            {
                appeared = true;
                cout << endl
                     << left << setw(15) << "Ma bao"
                     << left << setw(65) << "Ten bai bao"
                     << left << setw(25) << "Tac Gia"
                     << left << setw(45) << "Tap Chi"
                     << left << setw(10) << "Thoi Gian" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }

    return appeared;
}
bool List::List_timBaoTheoTapChi_id()
{
    bool appeared = false;
    string id;
    do
    {
        cout << "Nhap ma tap chi : " << endl;
        cin >> id;
        xoaSpaces(id);
        transform(id.begin(), id.end(), id.begin(), ::toupper);
    } while (List_isNewTapChi(id));
    for (int i = 0; i < Bao_count; i++)
    {
        string temp = (b[i].TapChi_id);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if ((id) == temp)
        {
            if (!appeared)
            {
                appeared = true;
                cout << endl
                     << left << setw(15) << "Ma bao"
                     << left << setw(65) << "Ten bai bao"
                     << left << setw(25) << "Tac Gia"
                     << left << setw(45) << "Tap Chi"
                     << left << setw(10) << "Thoi Gian" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }

    return appeared;
}
bool List::List_timBaoTheoTacGia_id()
{
    string temp; bool flag = false;
    do
    {
        cout<<endl << "- Nhap ma tac gia can tim kiem: ";
        cin>>temp;
        xoaSpaces(temp);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    }
    while(this->List_isNewTacGia(temp));
    for(int i=0;i< Bao_count;i++)
    {
        if(b[i].TacGia_id == temp)
        {
            if (!flag)
            {
                cout <<endl<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;
            }
             cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }
    return flag;
}
bool List::List_timBaoTheoNXB_id()
{
    bool appeared = false;
    string id;
    do
    {
        cout << "Nhap ma NXB : " << endl;
        cin >> id;
        xoaSpaces(id);
        transform(id.begin(), id.end(), id.begin(), ::toupper);
    } while (List_isNewNXB(id));
    for (int i = 0; i < Bao_count; i++)
    {
        string temp = List_getNXB_idTheoTapChi_id(b[i].TapChi_id);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if ((id) == temp)
        {
            if (!appeared)
            {
                appeared = true;
                cout << endl
                     << left << setw(15) << "Ma bao"
                     << left << setw(65) << "Ten bai bao"
                     << left << setw(25) << "Tac Gia"
                     << left << setw(45) << "Tap Chi"
                     << left << setw(10) << "Thoi Gian" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }

    return appeared;
}
bool List::List_timBaoTheoNam()
{
    bool appeared = false;
    cout << endl
         << "Nhap nam :";
    int ten;
    cin >> ten;
    //xoaSpaces(ten);
    //transform(ten.begin(), ten.end(), ten.begin(), ::toupper);
    for (int i = 0; i < Bao_count; i++)
    {
        int temp = b[i].ThoiGianCongBo;
       // transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (ten==temp)
        {
            if (!appeared)
            {
                appeared = true;
                cout << endl
                     << left << setw(15) << "Ma bao"
                     << left << setw(65) << "Ten bai bao"
                     << left << setw(25) << "Tac Gia"
                     << left << setw(45) << "Tap Chi"
                     << left << setw(10) << "Thoi Gian" << endl;
                cout << "---------------------------------------------------------------------------" << endl;
            }
            cout << left << setw(15) << b[i].Bao_id
                 << left << setw(65) << b[i].Bao_ten
                 << left << setw(25) << List_getTacGia_tenTheoTacGia_id(b[i].Bao_id)
                 << left << setw(45) << List_getTapChi_tenTheoTapChi_id(b[i].TapChi_id)
                 << left << setw(10) << b[i].ThoiGianCongBo << endl;
        }
    }
    return appeared;
}