#include"menu.h"
#include<iostream>
#include<iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#define HEADER_COLOR 9 // Blue
#define FOOTER_COLOR 10 // Green
#define DEFAULT_COLOR 7 // White
#define intrang setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#define inDo setConsoleColor(FOREGROUND_RED);
#define inDo setConsoleColor(FOREGROUND_GREEN);
using namespace std;
void gotoxy(short x, short y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

const int menuWidth = 40;

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void handleArrowKey(int keyCode, int& selectedOption, int totalOptions) {
    switch (keyCode) {
        case 72: // Up arrow key
            selectedOption = (selectedOption - 1 + totalOptions) % totalOptions;
            break;
        case 80: // Down arrow key
            selectedOption = (selectedOption + 1) % totalOptions;
            break;
    }
}
void displayMenu(int selectedOption, const string menuOptions[],const int totalOptions,string s) {
    system("cls");
    cout<<"\t\t\t\t"<<s<<endl<<endl;
    cout<<"\t\t\t\t";
    cout << char(201);
    for (int column = 0; column < menuWidth; ++column) cout << char(205);
    cout << char(187) << "\n";


    for (int i = 0; i < totalOptions; ++i) {
             cout<<"\t\t\t\t";
            cout << char(186) << setw(menuWidth) << left;
            if (i == selectedOption) {
                setConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Change to highlighted color
            }
             cout<< (i == selectedOption ? (">>  " + menuOptions[i]) : ("   " + menuOptions[i]));
            if (i == selectedOption) {
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset to default color
            }
            cout << char(186) << "\n";
        }
     cout<<"\t\t\t\t";
    cout << char(200);
    for (int column = 0; column < menuWidth; ++column) cout << char(205);
    cout << char(188) << "\n";
}
pair<string, string> acc[10];
bool ok=false;
const int acc_count=2;
void readTaiKhoan(ifstream& i,string tk,string mk) {
    string s;
    int count = 0;

    while (count < acc_count && getline(i, acc[count].first, '|') && getline(i, acc[count].second, '\n')) {
        count++;
    }

    i.close();
    //bool ok = false;
    for (int j = 0; j < count; j++) {
        if (acc[j].first==tk&&acc[j].second==mk){
            ok=true;
            gotoxy(24,13);cout<<"Ban da dang nhap thanh cong . Xin chao "<<tk<<"!"<<endl;
            system("pause");
        }
        
    }
    
}
string error=R"(
  ______ _____  _____   ____  _____  
 |  ____|  __ \|  __ \ / __ \|  __ \ 
 | |__  | |__) | |__) | |  | | |__) |
 |  __| |  _  /|  _  /| |  | |  _  / 
 | |____| | \ \| | \ \| |__| | | \ \ 
 |______|_|  \_\_|  \_\\____/|_|  \_\
                                     
               
)";
string getPasswordInput() {
    const char BACKSPACE = 8;
    const char ENTER = 13;

    string password;
    char ch = 0;

    while ((ch = _getch()) != ENTER) {
        if (ch == BACKSPACE) {
            if (!password.empty()) {
                cout << "\b \b"; // Erase the last character from the console
                password.pop_back();
            }
        } else {
            cout << '*';
            password += ch;
        }
    }

    cout << endl;

    return password;
}
int attempt=0;
void displayLogin () {
    system("cls");

    cout <<"\t\t\t"<< char(201);
    for (int column = 0; column < menuWidth; ++column) cout << char(205);
    cout << char(187) << "\n";
    cout <<"\t\t\t"<< char(186) << setw(menuWidth) << left<<"              DANG NHAP      ";cout<<char(186)<< "\n";
    cout <<"\t\t\t"<< char(186) << setw(menuWidth) << left<<"Ten Dang Nhap       ";cout<<char(186)<< "\n";
    cout <<"\t\t\t"<< char(186) << setw(menuWidth) << left<<" --------------------";cout<<char(186)<< "\n";
    cout << "\t\t\t"<<char(186) << setw(menuWidth) << left<<"|                    |";cout<<char(186)<< "\n";
    cout <<"\t\t\t"<< char(186) << setw(menuWidth) << left<<" --------------------";cout<<char(186)<< "\n";
   //  cout << char(187) << "\n";
     cout <<"\t\t\t"<< char(186) << setw(menuWidth) << left<<"                   ";cout<<char(186)<< "\n";
    cout << "\t\t\t"<<char(186) << setw(menuWidth) << left<<" Mat Khau           ";cout<<char(186)<< "\n";
    cout << "\t\t\t"<<char(186) << setw(menuWidth) << left<<" --------------------";cout<<char(186)<< "\n";
    cout << "\t\t\t"<<char(186) << setw(menuWidth) << left<<"|                    |";cout<<char(186)<< "\n";
    cout << "\t\t\t"<<char(186) << setw(menuWidth) << left<<" --------------------";cout<<char(186)<< "\n";
     cout << "\t\t\t"<<char(200);
    for (int column = 0; column < menuWidth; ++column) cout << char(205);
    cout << char(188) << "\n";
    string user,pass;
    
    
    if (attempt>=3){
        cout<<endl<<endl;
        cout<<"Ban da nhap sai qua nhieu !"<<endl;
        setConsoleColor(FOREGROUND_RED);
        cout<<error;exit(0);
    }
    attempt++;
    gotoxy(26,4);cin>>user;
    gotoxy(26,9);pass=getPasswordInput();

    ifstream inputFile("../Data/Account.txt");
    readTaiKhoan(inputFile,user,pass);
    if (ok) { return;}
    else  {system("cls" );displayLogin();}
    system("pause");
    system("cls");
}
int menuSelectionLoop(const string menuOptions[],const int totalOptions,string s ) {
    char key;
    int selectedOption = 0;

    do {
        displayMenu(selectedOption, menuOptions,totalOptions,s);

        key = getch();
        if (key == 72 || key == 80) {
            handleArrowKey(key, selectedOption, totalOptions);
        }
    } while (key != 13);

    char t[1] = {menuOptions[selectedOption][0]};
    //cout<<t;
    int choice = atoi(t);
    return choice;
}


const int box_length = 50;

// The characters for the box
char horizontal = char(205); // ═
char vertical = char(186); // ║
char top_left = char(201); // ╔
char top_right = char(187); // ╗
char bottom_left = char(200); // ╚
char bottom_right = char(188); // ╝

string header_lines[8] = {
    top_left + string(box_length, horizontal) + top_right,
  //  vertical + string((box_length-a.size())/2, ' ')+a+string((box_length-a.size())/2, ' ') + vertical,
   //  vertical + string((box_length-b.size())/2, ' ')+b+string((box_length-b.size())/2, ' ') + vertical,
    vertical + string(box_length, ' ') + vertical,
    vertical + string(box_length, ' ') + vertical,
    vertical + string(box_length, ' ') + vertical,
    vertical + string(box_length, ' ') + vertical,
    vertical + string(box_length, ' ') + vertical,
     vertical + string(box_length, ' ') + vertical,
    bottom_left + string(box_length, horizontal) + bottom_right
};

// The initial position of the box
int x = 0;
int y = 0;

// The initial direction of the box
int dx = 1;
int dy = 0;

// The initial color of the box
int color = HEADER_COLOR;

// The number of options for the direction
const int options = 4;

// The selected option for the direction
int selectedOption = 0;

// The function to print the box
void printBox(int x,int y)
{
    // Set the text color
    setConsoleColor(color);

    // Print the header lines
    for (int i = 0; i < 8; i++)
    {
        // Move the cursor to the position
        gotoxy(x, y + i);

        // Print the current line
        cout << header_lines[i];
    }
    gotoxy(x+6,y+1);cout<<" PBL 2: DO AN CO SO LAP TRINH";
    gotoxy(x+5,y+2);cout<<" DE TAI: QUAN LY BAI BAO NGHIEN CUU";
    gotoxy(x+5,y+3);cout<<"SINH VIEN:       GIAO VIEN HUONG DAN:";
    gotoxy(x+5,y+4);cout<<"LE NGOC THANH    THAY TRUONG NGOC CHAU";
    gotoxy(x+5,y+5);cout<<"NGO XUAN NINH";
    gotoxy(20,20);
    setConsoleColor(DEFAULT_COLOR);
}

void eraseBox(int x,int y)
{
    for (int i = 0; i < 12; i++)
    {
        gotoxy(x, y + i);
        cout << string(box_length + 2, ' ');
    }
}

// The function to update the box
void updateBox(int &x,int &y)
{
    eraseBox(x,y);
    x += dx;
    y += dy;
    if(x>50)x %=50;
    if(y>50)y%=50;
    if(x<0)x+=50;
    if(y<0)y+=50;
    color = (color + 1) % 16;
    printBox(x,y);
}
bool stop=false;
void handleInput()
{
    // Check if a key is pressed
    if (kbhit())
    {
        int x=_getch();
 
            switch (x)
            {
                case 13:
                    stop=true;
                    break;
                case 80: // Up
                    dx = 0;
                    dy = 1;
                    break;
                case 72: // down
                    dx = 0;
                    dy = -1;
                    break;
                case 77: // right
                    dx = 1;
                    dy = 0;
                    break;
                case 75: // Left
                    dx = -1;
                    dy = 0;
                    break;
               

        }
    }
}
void menu::info(){
    // cout<<endl;
    // cout<<"\t\t\t -------------------------------------------------------------\n";
    // cout<<"\t\t\t|                                                             |\n";
    // cout<<"\t\t\t|               PBL 2: DO AN CO SO LAP TRINH                  |\n";
    // cout<<"\t\t\t|      DE TAI: CHUONG TRINH QUAN LY CAC BAI BAO NGHIEN CUU    |\n";
    // cout<<"\t\t\t|                                                             |\n";
    // cout<<"\t\t\t|     Sinh vien thuc hien :            Giao vien huong dan :  |\n";
    // cout<<"\t\t\t|     Le Ngoc Thanh                    Thay Truong Ngoc Chau  |\n";
    // cout<<"\t\t\t|     Ngo Xuan Ninh                                           |\n";
    // cout<<"\t\t\t -------------------------------------------------------------\n";
    // system("pause");
     int x=0,y=0;
    printBox(x,y);

    // Start the animation loop
    while (!stop)
    {
        // Handle the user input
        handleInput();

        // Update the box
        updateBox(x,y);

        // Sleep for a while
        Sleep(100);
    }
    system("pause");
}
int menu::mainMenu(){
    cout<<endl;
    if(!ok)displayLogin();
    const string menuOptions[] = { "1. Hien thi thong tin", "2. Chinh sua thong tin", "3. Them thong tin", "4. Xoa thong tin", "5. Thong ke so luong bai bao", "6. Tim kiem bai bao", "7. Sap xep bai bao","0. Thoat" };
    const int totalOptions = 8;
    string s = R"(
                             __  __       _         __  __                  
                            |  \/  |     (_)       |  \/  |                 
                            | \  / | __ _ _ _ __   | \  / | ___ _ __  _   _ 
                            | |\/| |/ _` | | '_ \  | |\/| |/ _ \ '_ \| | | |
                            | |  | | (_| | | | | | | |  | |  __/ | | | |_| |
                            |_|  |_|\__,_|_|_| |_| |_|  |_|\___|_| |_|\__,_|
)";
    return menuSelectionLoop(menuOptions,totalOptions,s);
 //   cout<<"\t\t\t Luc chon cua ban la [0/1/2/3/..] : ";
}
int menu::Menu_Display(){
    
    cout<<endl;
    const string menuOptions[] = { "1. Bai bao", "2. Tac gia", "3. Tap chi", "4. Nha xuat ban", "0. Thoat" };
    const int totalOptions = 5;
    string s=R"(
                             _____  _           _               __  __                  
                            |  __ \(_)         | |             |  \/  |                 
                            | |  | |_ ___ _ __ | | __ _ _   _  | \  / | ___ _ __  _   _ 
                            | |  | | / __| '_ \| |/ _` | | | | | |\/| |/ _ \ '_ \| | | |
                            | |__| | \__ \ |_) | | (_| | |_| | | |  | |  __/ | | | |_| |
                            |_____/|_|___/ .__/|_|\__,_|\__, | |_|  |_|\___|_| |_|\__,_|
                                        | |             __/ |                          
                                        |_|            |___/                                                                     
    )";
    return menuSelectionLoop(menuOptions,totalOptions,s); 
}
int menu::Menu_ChinhSua(){
    cout<<endl;
    const string menuOptions[] = { "1. Bai bao", "2. Tac gia", "3. Tap chi", "4. Nha xuat ban", "0. Thoat" };
    string s=R"(
                             ______ _____ _____ _______   __  __ ______ _   _ _    _ 
                            |  ____|  __ \_   _|__   __| |  \/  |  ____| \ | | |  | |
                            | |__  | |  | || |    | |    | \  / | |__  |  \| | |  | |
                            |  __| | |  | || |    | |    | |\/| |  __| | . ` | |  | |
                            | |____| |__| || |_   | |    | |  | | |____| |\  | |__| |
                            |______|_____/_____|  |_|    |_|  |_|______|_| \_|\____/ 
                                                        
    )";
    const int totalOptions = 5;
    return menuSelectionLoop(menuOptions,totalOptions,s); 
}
int menu::Menu2_ChinhSuaBao(string Bao_id){

    cout<<endl;//cout<<"\t\t\t\t\tCHINH SUA THONG TIN BAI BAO "<<Bao_id<<"\n";system("pause");cout<<endl;
    string s= "CHINH SUA THONG TIN BAI BAO " ;
    const string menuOptions[] = { "1. Ten bai bao", "2. Ten tac gia", "3. Ten tap chi", "4. Nam cong bo", "0. Thoat" };
    const int totalOptions = 5;
    return menuSelectionLoop(menuOptions,totalOptions,s); 
}
int menu::Menu2_ChinhSuaTacGia(string TacGia_id){
    
     cout<<endl;//cout<<"\t\t\t\t\tCHINH SUA THONG TIN TAC GIA "<<TacGia_id<<"\n";system("pause");cout<<endl;
     string s= "CHINH SUA THONG TIN TAC GIA " ;//+ TacGia_id;
    const string menuOptions[] = { "1. Ten tac gia", "2. Noi cong tac", "3. Linh vuc", "4. Trinh do", "0. Thoat" };
    const int totalOptions = 5;
    return menuSelectionLoop(menuOptions,totalOptions,s); 
}
int menu::Menu2_ChinhSuaTapChi(string TapChi_id){
    cout<<endl;//cout<<"\t\t\t\t\tCHINH SUA THONG TIN TAC GIA "<<TapChi_id<<"\n";system("pause");cout<<endl;
    string s= "CHINH SUA THONG TIN TAP CHI " ;//+ TapChi_id;
    const string menuOptions[] = { "1. Ten tap chi", "2. Tong bien tap", "3. Nha xuat ban", "0. Thoat" };
    const int totalOptions = 4;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}
int menu::Menu_Them(){
   
    cout<<endl;//cout<<"\t\t\t\t\tMENU THEM THONG TIN"<<"\n";system("pause");cout<<endl;
    string s=R"(
                                    /\      | |   | | |  \/  |                 
                                   /  \   __| | __| | | \  / | ___ _ __  _   _ 
                                  / /\ \ / _` |/ _` | | |\/| |/ _ \ '_ \| | | |
                                 / ____ \ (_| | (_| | | |  | |  __/ | | | |_| |
                                /_/    \_\__,_|\__,_| |_|  |_|\___|_| |_|\__,_|
                                                                    
    )";
    const string menuOptions[] = { "1. Bai bao", "2. Tac gia", "3. Tap chi", "4. Nha xuat ban","0. Thoat" };
    const int totalOptions = 5;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}
int menu::Menu2_ThemBao(){
    cout<<endl;//cout<<"\t\t\t\t\tMENU THEM BAI BAO"<<"\n";system("pause");cout<<endl;
    string s=R"(
                                                _     _                 _   _      _      
                                       /\      | |   | |     /\        | | (_)    | |     
                                      /  \   __| | __| |    /  \   _ __| |_ _  ___| | ___ 
                                     / /\ \ / _` |/ _` |   / /\ \ | '__| __| |/ __| |/ _ \
                                    / ____ \ (_| | (_| |  / ____ \| |  | |_| | (__| |  __/
                                   /_/    \_\__,_|\__,_| /_/    \_\_|   \__|_|\___|_|\___|
                                                                                                
    )";
    const string menuOptions[] = { "1. Vao vi tri mac dinh", "2. Vao vi tri tuy chon","0. Thoat" };
    const int totalOptions = 3;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}
int menu::Menu_Xoa(){
      cout<<endl;//cout<<"\t\t\t\t\tXOA THONG TIN"<<"\n";system("pause");cout<<endl;
      string s=R"(
                                     _____       _      _         __  __                  
                                    |  __ \     | |    | |       |  \/  |                 
                                    | |  | | ___| | ___| |_ ___  | \  / | ___ _ __  _   _ 
                                    | |  | |/ _ \ |/ _ \ __/ _ \ | |\/| |/ _ \ '_ \| | | |
                                    | |__| |  __/ |  __/ ||  __/ | |  | |  __/ | | | |_| |
                                    |_____/ \___|_|\___|\__\___| |_|  |_|\___|_| |_|\__,_|
                                                      
      )";
    const string menuOptions[] = { "1. Bai bao", "2. Tac gia","3. Tap chi","4. Nha xuat ban","0. Thoat" };
    const int totalOptions = 5;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}

int menu::Menu_SoLuongBao(){

         cout<<endl;//cout<<"\t\t\t\t\tTHONG KE SO LUONG BAI BAO"<<"\n";system("pause");cout<<endl;
      string s=R"(
                                      _______ _                         _  __    
                                     |__   __| |                       | |/ /    
                                        | |  | |__   ___  _ __   __ _  | ' / ___ 
                                        | |  | '_ \ / _ \| '_ \ / _` | |  < / _ \
                                        | |  | | | | (_) | | | | (_| | | . \  __/
                                        |_|  |_| |_|\___/|_| |_|\__, | |_|\_\___|
                                                                 __/ |           
                                                                |___/           
      )";   
    const string menuOptions[] = { "1. Theo tac gia", "2. Theo tap chi","3. Theo nha xuat ban","4. Theo nam xuat ban","0. Thoat" };
    const int totalOptions = 5;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}
int menu::Menu_TimBao(){

    cout<<endl;//cout<<"\t\t\t\t\tTHONG KE SO LUONG BAI BAO"<<"\n";system("pause");cout<<endl;
          string s=R"(
                                          _____                     _       __  __                  
                                         / ____|                   | |     |  \/  |                 
                                        | (___   ___  __ _ _ __ ___| |__   | \  / | ___ _ __  _   _ 
                                         \___ \ / _ \/ _` | '__/ __| '_ \  | |\/| |/ _ \ '_ \| | | |
                                         ____) |  __/ (_| | | | (__| | | | | |  | |  __/ | | | |_| |
                                        |_____/ \___|\__,_|_|  \___|_| |_| |_|  |_|\___|_| |_|\__,_|
                                                                                
      )";
    const string menuOptions[] = { "1. Theo ten bai bao", "2. Theo ma bai bao","3. Theo ten tac gia","4. Theo ma tac gia","5. Theo ma tap chi","6. Theo ma nha xuat ban", "7. Theo nam xuat ban","0. Thoat" };
    const int totalOptions = 8;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}
int menu::Menu_SapXepBao(){

    cout<<endl;//cout<<"\t\t\t\t\tSAP XEP BAI BAO"<<"\n";system("pause");cout<<endl;
    string s=R"(
                                       
                                          _____            _     __  __                  
                                         / ____|          | |   |  \/  |                 
                                        | (___   ___  _ __| |_  | \  / | ___ _ __  _   _ 
                                         \___ \ / _ \| '__| __| | |\/| |/ _ \ '_ \| | | |
                                         ____) | (_) | |  | |_  | |  | |  __/ | | | |_| |
                                        |_____/ \___/|_|   \__| |_|  |_|\___|_| |_|\__,_|
                                                                        
    )";
    const string menuOptions[] = { "1. Theo ten tac gia", "2. Theo ten bai bao","3. Theo nam","0. Thoat" };
    const int totalOptions = 4;
    return menuSelectionLoop(menuOptions,totalOptions,s);
}
