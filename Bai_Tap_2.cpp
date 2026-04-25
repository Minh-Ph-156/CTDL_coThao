#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Sinhvien{
    string hoten;
    string masv;
    char namsinh[5];
    char lop[4];
};
Sinhvien Fill_in(){
    Sinhvien i;
    cin.ignore();
    cout << "Nhap ten sinh vien: " ;    getline(cin, i.hoten);
    cout << endl;
    cout << "Nhap ma sinh vien: ";  cin >> i.masv;
    cout << endl;
    cout << "Nhap nam sinh cua sinh vien: ";  cin >> i.namsinh;
    cout << endl;
    cout << "Nhap lop cua sinh vien: "; cin >> i.lop;
    cout << endl;
    return i;
}


struct node_S{      //node of single link list
    Sinhvien SV;
    node_S* next;
};

typedef node_S* PTR_S;
void Init_S(PTR_S &First){
    First = NULL;
}
PTR_S Newnode_S(){
    PTR_S p = new node_S;
    return p;
}

int Insert_S(PTR_S &First, Sinhvien x){
    PTR_S p = Newnode_S();
    p->SV = x;
    if(First == NULL){
        p->next = NULL;
        First = p;
        return 1;
    }else{
        PTR_S q;
        for(q = First; q->next != NULL; q = q->next);
        p->next = q->next;
        q->next = p;
        return 1;
    }
    return 0;
}
int Traverse_S(PTR_S First){
    if(First == NULL) return 0;
    cout << left << setw(30) << "Ho ten" << setw(25) << "Ma sv"  << setw(15) << "Nam sinh" << setw(10) << "Lop" <<  endl;  
    for(PTR_S p = First; p != NULL; p=p->next){
        cout << left << setw(30) << p->SV.hoten << setw(25) << p->SV.masv  << setw(15) << p->SV.namsinh << setw(10) << p->SV.lop << endl;
    }
    return 1;
}

struct node_C{      //node of circle link list
    Sinhvien SV;
    node_C* next;
};
typedef node_C* PTR_C;
void Init_C(PTR_C &Last){
    Last = NULL;
}
PTR_C Newnode_C(){
    PTR_C p = new node_C;
    return p;
}
int Insert_C(PTR_C &Last, Sinhvien x){
    PTR_C p = Newnode_C();
    p->SV = x;
    if(Last == NULL){
        p->next = p;
        Last = p;
        return 1;
    }else{
        p->next = Last->next;
        Last->next = p;
        Last = p;
        return 1;
    }
    return 0;
}
int Traverse_C(PTR_C Last){
    if(Last == NULL) return 0;
    cout << left << setw(30) << "Ho ten" << setw(25) << "Ma sv"  << setw(15) << "Nam sinh" << setw(10) << "Lop" <<  endl;  
	PTR_C p;
    for(p = Last->next; p != Last; p = p->next ){
        cout << left << setw(30) << p->SV.hoten << setw(25) << p->SV.masv  << setw(15) << p->SV.namsinh << setw(10) << p->SV.lop << endl;    
    }
        cout << left << setw(30) << p->SV.hoten << setw(25) << p->SV.masv  << setw(15) << p->SV.namsinh << setw(10) << p->SV.lop << endl;    
    return 1;
}

struct node_D{
    Sinhvien SV;
    node_D *prev, *next;
};
typedef node_D* PTR_D;
PTR_D Newnode_D(){
    PTR_D p = new node_D;
    return p;
}
void Init_D(PTR_D &First, PTR_D &Last){
    First = Last = NULL;
}
int Insert_D(PTR_D &First, PTR_D &Last, Sinhvien x){
    PTR_D p = Newnode_D();
    p->SV = x;
    if(First == NULL){
        p->prev = NULL;
        p->next = NULL;
        First = p;
        Last = p;
        return 1;
    }
    else{
        p->next = NULL;
        
        p->prev = Last;
        Last->next = p;
        Last = p;
        return 1;
    }
    return 0;
}
int Traverse_D(PTR_D First){
    if(First == NULL) return 0;
    cout << left << setw(30) << "Ho ten" << setw(25) << "Ma sv"  << setw(15) << "Nam sinh" << setw(10) << "Lop" <<  endl;  

    for(PTR_D p = First; p != NULL; p = p->next ){
        cout << left << setw(30) << p->SV.hoten << setw(25) << p->SV.masv  << setw(15) << p->SV.namsinh << setw(10) << p->SV.lop << endl;    
    }
    return 1;
}
int menu(){
    int chucnang;
    cout << "--BANG CHUC NANG--" << endl;
    cout << "1. Nhap Thong Tin Sinh Vien" << endl;
    cout << "2. Xem Danh Sach Sinh Vien" << endl;
    cout << "0. Ket thuc chuong trinh" << endl;
    cin >> chucnang;
    return chucnang; 
}
int table(){
    int tmp;
    cout << "--KIEU LUU TRU--" << endl;
    cout << "1. Danh Sach Lien Ket Don" << endl;
    cout << "2. Danh Sach Lien Ket Vong" << endl;
    cout << "3. Danh Sach Lien Ket Kep" << endl;
    cin >> tmp;
    return tmp;
}


int main(){
    int ds;
    ds = table();
    char c;
    if(ds == 1){
        PTR_S Head;
        Init_S(Head);
        int chucnang;
        int check;
        do{
            chucnang = menu();
            switch(chucnang){
                case 1:
                    do{
                    check = Insert_S(Head,Fill_in());
                    if(check == 1) cout << "Nhap thanh cong" << endl; 
                    else cout << "Nhap that bai" << endl;
                    cout << "Ban muon nhap tiep hay khong (c/k)" << endl;
                    cin >> c;
                    if(c == 'k' || c == 'K'){
                        Traverse_S(Head);
                        break;
                    }  
                    }while(true);
                        
                break;
            
                case 2:
                    check = Traverse_S(Head);
                    if(check == 0) cout << "Danh sach rong" << endl;
                break;
            }
        }while(chucnang != 0); 
    }else if(ds == 2){
        PTR_C Tail;
        Init_C(Tail);
        int chucnang;
        int check;
        do{
            chucnang = menu();
            switch(chucnang){
                case 1:
                    do{
                    check = Insert_C(Tail,Fill_in());
                    if(check == 1) cout << "Nhap thanh cong" << endl; 
                    else cout << "Nhap that bai" << endl;
                    cout << "Ban muon nhap tiep hay khong (c/k)" << endl;
                    cin >> c;
                    if(c == 'k' || c == 'K'){
                        Traverse_C(Tail);
                        break;
                    }  
                    }while(true);
                break;
            
                case 2:
                    check = Traverse_C(Tail);
                    if(check == 0) cout << "Danh sach rong" << endl;
                break;
            }
        }while(chucnang != 0); 
    }
    else if(ds == 3){
        PTR_D Head,Tail;
        Init_D(Head,Tail);
        int chucnang;
        int check;
        do{
            chucnang = menu();
            switch(chucnang){
                case 1:
                do{
                    check = Insert_D(Head,Tail,Fill_in());
                    if(check == 1) cout << "Nhap thanh cong" << endl; 
                    else cout << "Nhap that bai" << endl;
                    cout << "Ban muon nhap tiep hay khong (c/k)" << endl;
                    cin >> c;
                    if(c == 'k' || c == 'K') {
                        Traverse_D(Head);
                        break;
                    }  
                    }while(true);
                break;
            
                case 2:
                    check = Traverse_D(Head);
                    if(check == 0) cout << "Danh sach rong" << endl;
                break;
            }
        }while(chucnang != 0); 
    }
    
    return 0;
}
