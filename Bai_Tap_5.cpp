#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Sinhvien{
    string hoten;
    string masv;        // neu string ta so sanh truc tiep 2 chuoi
                        // con neu la mang char thi ta dung strcmp trong thu vien cstring
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
PTR_S sortedInsert_S(PTR_S p, PTR_S q){
    if(p == NULL || q->SV.masv < p->SV.masv ){ 
        q->next = p;
        p = q;
        return p;
    }
    PTR_S current = p;
    while(current->next != NULL && current->next->SV.masv < q->SV.masv){
        current = current->next;
    }
    q->next = current->next;
    current->next = q;
    return p;
}

void Insertion_sort_S(PTR_S &First){
    if(First == NULL) return;     //danh sach rong
    PTR_S list_sorted = NULL;
    PTR_S current = First;
    while(current != NULL){
        PTR_S next = current->next;
        list_sorted = sortedInsert_S(list_sorted, current);
        current = next;
    }
    First = list_sorted;
}
PTR_S Find_Mid(PTR_S First){
    if(First == NULL or First->next == NULL) return First;
    PTR_S Slow = First;
    PTR_S Fast = First->next;
    while(Fast != NULL && Fast->next != NULL){
        Slow = Slow->next;
        Fast = Fast->next->next;
    }
    
    return Slow;
}
PTR_S Merge_node(PTR_S p, PTR_S q){
    if(p == NULL) return q;                 
    if(q == NULL) return p;
    
    if(p->SV.masv < q->SV.masv){            //gia tri node nao nho hon thi node do la node can gan, node lon hon la node bi gan
        p->next = Merge_node(p->next,q);
        return p;
    }else{
        q->next = Merge_node(p, q->next);
        return q;
    }
}

PTR_S Merge_Sort_S(PTR_S First){
    if(First == NULL || First->next == NULL) {
        return First;
    }
    
    PTR_S mid = Find_Mid(First);
    PTR_S right = mid->next;
    mid->next = NULL;
    
    PTR_S left = Merge_Sort_S(First);
    right = Merge_Sort_S(right);

    return Merge_node(left,right);
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
PTR_C sortedInsert_C(PTR_C p, PTR_C q){
    if(p == NULL){
        q->next = q;
        return q;
    }
    PTR_C current = p;
    if( q->SV.masv < p->SV.masv ){
        while(current->next != p){
            current = current->next;
        }

        current->next = q;
        q->next = p;
        return q;
    }

    while(current->next != p && current->next->SV.masv < q->SV.masv){
        current = current->next;
    }

    q->next = current->next;
    current->next = q;

    return p;
}

void Insertion_Sort_C(PTR_C &Last){
    if(Last == NULL || Last->next == Last){
        return;
    }

    PTR_C start = Last;
    PTR_C current = Last;
    PTR_C list_sorted = NULL;

    do{
        PTR_C next = current->next;
        current->next = current;
        list_sorted = sortedInsert_C(list_sorted, current);
        current = next;

    } while(current != start);
    
    Last = list_sorted;
    while (Last->next != list_sorted) {
        Last = Last->next;
    }
    return ;
}
void Break_C(PTR_C &Last){
    if(Last == NULL) return;
    PTR_C tmp = Last;
    while(tmp->next != Last){
        tmp = tmp->next;
    }
    tmp->next = NULL;
}
void Make_C(PTR_C &Last, PTR_C head){
    if(head == NULL) return;

    PTR_C tail = head;        // nối lại vòng
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = head;
    Last = tail;
    
}
PTR_C Find_Mid(PTR_C First){
    if(First == NULL or First->next == NULL) return First;
    PTR_C Slow = First;
    PTR_C Fast = First->next;
    while(Fast != NULL && Fast->next != NULL){
        Slow = Slow->next;
        Fast = Fast->next->next;
    }
    
    return Slow;
}
PTR_C Merge_node(PTR_C p, PTR_C q){
    if(p == NULL) return q;                 
    if(q == NULL) return p;
    
    if(p->SV.masv < q->SV.masv ){            //gia tri node nao nho hon thi node do la node can gan, node lon hon la node bi gan
        p->next = Merge_node(p->next,q);
        return p;
    }else{
        q->next = Merge_node(p, q->next);
        return q;
    }
}

PTR_C Merge_Sort_C(PTR_C Last){
    if(Last == NULL || Last->next == NULL) {
        return Last;
    } 
    
    PTR_C mid = Find_Mid(Last);
    PTR_C right = mid->next;
    mid->next = NULL;
    
    PTR_C left = Merge_Sort_C(Last);
    right = Merge_Sort_C(right);

    return Merge_node(left,right);
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
void Pause(){
    cout << endl << "Nhan phim bat ky de tiep tuc...";
    getch();
}
void Clear(){
    system("cls");
}
int menu_chinh(){
    int chucnang;
    cout << "--BANG CHUC NANG--" << endl;
    cout << "1. Nhap Thong Tin Sinh Vien" << endl;
    cout << "2. Xem Danh Sach Sinh Vien" << endl;
    cout << "3. Sap Xep Danh Sach Sinh Vien" << endl;
    cout << "0. Thoat chuc nang luu tru nay" << endl;
    cin >> chucnang;
    return chucnang; 
}
int menu_phu(){
    int chucnang;
    cout << "--CHON THUAT TOAN SAP XEP--" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "0. Thoat chuc nang nay" << endl;
    cin >> chucnang;
    return chucnang;
}
int bang_chuc_nang(){
    int tmp;
    cout << "--KIEU LUU TRU--" << endl;
    cout << "1. Danh Sach Lien Ket Don" << endl;
    cout << "2. Danh Sach Lien Ket Vong" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cin >> tmp;
    return tmp;
}


int main(){
    int BCN;
    char c;
    while(true){
        Clear();
        BCN = bang_chuc_nang();
        
        if(BCN == 1){
            PTR_S Head;
            Init_S(Head);
            int chuc_nang_chinh_1;
            int kiem_tra_1;
            do{
                Clear();
                chuc_nang_chinh_1 = menu_chinh();
                switch(chuc_nang_chinh_1){
                    case 1:
                        do{
                        kiem_tra_1 = Insert_S(Head,Fill_in());
                        if(kiem_tra_1 == 1) cout << "Nhap thanh cong" << endl; 
                        else cout << "Nhap that bai" << endl;
                        cout << endl;
                        cout << "Ban muon nhap tiep hay khong (c/k)" << endl;
                        cin >> c;
                        if(c == 'k' || c == 'K'){
                            Traverse_S(Head);
                            break;
                            }  
                    }while(true);
                        Pause();
                    break;
            
                    case 2:
                        kiem_tra_1 = Traverse_S(Head);
                        if(kiem_tra_1 == 0) cout << "Danh sach rong" << endl;
                        cout << endl;
                        Pause();
                    break;

                    case 3:{
                    
                        int chuc_nang_phu_1;
                        do{
                            Clear();
                            chuc_nang_phu_1 = menu_phu();
                            if(chuc_nang_phu_1 == 1){
                                if(Head == NULL){  
                                    cout << "Danh sach rong" << endl;
                                    Pause();
                                    break;
                                }
                            Insertion_sort_S(Head);
                            cout << "Sap xep thanh cong" << endl;
                            Pause();
                            break;
                            }
                                
                        else if(chuc_nang_phu_1 == 2){
                            if(Head == NULL){
                            cout << "Danh sach rong" << endl;
                            Pause();
                            break;
                            }
                            Head = Merge_Sort_S(Head);    
                            cout << "Sap xep thanh cong" << endl;
                            Pause();
                            break;
                        }
                        else if(chuc_nang_phu_1 != 0){
                                cout << "Khong ton tai chuc nang nay, vui long chon lai1" << endl;
                                Pause();
                                }
                            } while(chuc_nang_phu_1 != 0);
                        }   
                    break;
                    
                    default:
                        
                        if(chuc_nang_chinh_1 != 0){
                            cout << "Khong ton tai chuc nang nay, vui long chon lai" << endl;
                            Pause();
                        }
                    break;
                        
                    }                        
                }while(chuc_nang_chinh_1 != 0);
            }
        else if(BCN == 2){

            PTR_C Tail;
            Init_C(Tail);
            int chuc_nang_chinh_2;
            int kiem_tra_2;
            do{
                Clear();
                chuc_nang_chinh_2 = menu_chinh();
                switch(chuc_nang_chinh_2){
                    case 1:
                    
                    do{    
                       kiem_tra_2 = Insert_C(Tail,Fill_in());
                        if(kiem_tra_2 == 1) cout << "Nhap thanh cong" << endl; 
                        else cout << "Nhap that bai" << endl;
                        cout << "Ban muon nhap tiep hay khong (c/k)" << endl;
                        cin >> c;
                        if(c == 'k' || c == 'K'){
                            Traverse_C(Tail);
                            break;
                        } 
                    }while(true);
                    
                    Pause();    
                break;
            
                case 2:
    
                    kiem_tra_2 = Traverse_C(Tail);
                    if(kiem_tra_2 == 0) cout << "Danh sach rong" << endl;
                    Pause();

                break;                        

                case 3:
                    int chuc_nang_phu_2;
                    do{
                        Clear();
                        chuc_nang_phu_2 = menu_phu();
                        if(chuc_nang_phu_2 == 1){
                            if(Tail == NULL){
                            cout << "Danh sach rong" << endl;
                            Pause();
                            break;
                            }
                        Insertion_Sort_C(Tail);
                        cout << "Sap xep thanh cong" << endl;
                        Pause();
                        break;
                    } else if(chuc_nang_phu_2 == 2){
                            if(Tail == NULL){
                                cout << "Danh sach rong" << endl;
                                Pause();
                                break;
                            }

                            PTR_C head = Tail->next; 
                            Break_C(head);              // phá vòng
                            head = Merge_Sort_C(head);
                            Make_C(Tail, head); 
                            cout << "Sap xep thanh cong" << endl;
                            Pause();

                            break;
                        }else if(chuc_nang_phu_2 != 0){ 
                            cout << "Khong ton tai chuc nang nay, vui long chon lai" << endl;
                            Pause();
                        }
                    }while(chuc_nang_phu_2 != 0);
                
                break;

                    default:
                        if(chuc_nang_chinh_2 != 0){
                            cout << "Khong ton tai chuc nang nay, vui long chon lai" << endl;
                            Pause();
                        }
                    break;
                }  
            }while(chuc_nang_chinh_2 != 0);
        }
        else if(BCN == 0){
            break;
        }
        else{
            cout << "Khong ton tai chuc nang nay, vui long chon lai" << endl;
            Pause();
        }
    }
    
    return 0;
}
