#include <iostream>
using namespace std;

struct node{
    int info;
    node* next;
};
typedef node* PTR;

void Init(PTR &First){
    First = NULL;
}
PTR Newnode(){
    PTR p = new node;
    return p;
}

int Insert(PTR &First, int x){
    PTR p = Newnode();
    p->info = x;
    if(First == NULL){
        p->next = NULL;
        First = p;
        return 1;
    }else{
        PTR q;
        for(q = First; q->next != NULL; q = q->next){}
        p->next = q->next;    
        q->next = p;
        return 1;
    }
    return 0;

}
int Traverse(PTR First){
    if(First == NULL) return 0;
    for(PTR q = First; q != NULL; q = q->next){
        cout << q->info << " ";
    }
    cout << endl;
    return 1;
}
int sort_value(PTR &First){
    if(First == NULL) return 0;
    for(PTR p = First; p->next != NULL; p = p->next){
        for(PTR q = p->next; q != NULL; q = q->next){
            if(p->info > q->info){
                int tmp = p->info;
                p->info = q->info;
                q->info = tmp;
            }
        }
    }
    return 1;
}
int sort_link(PTR &First){
    if(First == NULL)return 0;
    PTR res;
    Init(res);
    int min;
    while(First != NULL){
        PTR min_node = First;
        PTR min_bf = NULL;

        PTR p;
        PTR p_bf = NULL;
        for(p = First; p != NULL; p=p->next){
            if(min_node->info > p->info){
                min_bf = p_bf;
                min_node = p;
            }
            p_bf = p;
        }
        if(min_bf == NULL){
            First = First->next;
        }else{
            min_bf->next = min_node->next;
        }
        
        min_node->next = NULL;
        if(res == NULL){
            res = min_node; 
        }else{
            PTR q;
            for(q = res; q->next != NULL; q = q->next){}
            q->next = min_node;
        }
    }
    First = res;
    return 1;
}
int menu(){
    int chucnang;
    cout << "1. Nhap thong tin" << endl;
    cout << "2. In thong tin" << endl;
    cout << "3. Sap xep thay doi lien ket" << endl;
    cout << "4. Sap xep thay doi gia tri" << endl;
    cout << "0. Ket thuc chuong trinh" << endl; 
    cin >> chucnang;
    return chucnang;
}


int main(){
    PTR Head;
    Init(Head);
    int chucnang;
    int x, check;

    do{
        chucnang = menu();
        switch (chucnang){
            case 1:
            do{
            cout << "Gia tri muon them la(nhap -1 de dung qua trinh nhap): "; cin >> x;
            cout << endl;
            if(x == -1) break;
            check = Insert(Head, x);
            if(check == 1) cout << "Them thanh cong" << endl;
            else cout << "Them that bai" << endl;
            }while(true);

            break;

            case 2:
            check = Traverse(Head);
            if(check == 0) cout << "Danh sach rong" << endl;
            break;
            
            case 3:
            check = sort_link(Head);
            if(check == 1)cout << "Sap xep thanh cong" << endl;
            else cout << "Danh sach rong" << endl;
            break; 

            case 4:
            check = sort_value(Head);
            if(check == 1)cout << "Sap xep thanh cong" << endl;
            else cout << "Danh sach rong" << endl;
            break;
            
        
        }
    }while(chucnang != 0);

    return 0;
}