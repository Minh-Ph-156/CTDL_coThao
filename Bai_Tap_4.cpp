#include <iostream>
using namespace std;

int De_Quy_Cau_a(int n, int x){
    if(n == 0) return 1;
    if(n == 1 ) return x;
    return De_Quy_Cau_a(n-1,x) - De_Quy_Cau_a(n-2,x);
}
int Giai_De_Quy_Cau_a(int n, int x){
    if (n == 0) return 1;
    if(n == 1) return x;
    
    int p_first = 1;
    int p_second = x;
    int p_n = 0;
    for(int i = 2;i <= n;i++){
        p_n = p_second - p_first;
        p_first = p_second;
        p_second = p_n;
    }
    return p_n;
}
int De_Quy_Cau_b(int n, int x, int y){
    if(n == 0) return 1;
    if(n == 1) return (2*x)+(3*y)-8;
    return De_Quy_Cau_b(n-1,x,y) + De_Quy_Cau_b(n-2,x,y);
}
int Giai_De_Quy_Cau_b(int n, int x, int y){
    if(n == 0) return 1;
    if(n == 1) return (2*x)+(3*y)-8;
    int p_first = 1;
    int p_second = (2*x)+(3*y)-8;
    int p_n = 0;
    for(int i = 2;i <= n;i++){
        p_n = p_second + p_first;
        p_first = p_second;
        p_second = p_n;
    }
    return p_n;
}
int menu_a(){
    int chucnang;
    cout << "CHUC NANG CAU A" << endl;
    cout << "1. De Quy" << endl;
    cout << "2. Giai De Quy" << endl;
    cout << "3. Quay lai" << endl;
    cin >> chucnang;
    return chucnang;
}
int menu_b(){
    int chucnang;
    cout << "CHUC NANG CAU B" << endl;
    cout << "1. De Quy" << endl;
    cout << "2. Giai De Quy" << endl;
    cout << "3. Quay lai" << endl;
    cin >> chucnang;
    return chucnang;
}
int menu_chinh(){
    int chucnang;
    cout << "BANG CHUC NANG" << endl;
    cout << "1. Cau a" << endl;
    cout << "2. Cau b" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cin >> chucnang;
    return chucnang;
}

int main(){
    int chucnang;
    int n,x,y;
    do{
        chucnang = menu_chinh();
        switch (chucnang){
        
            case 1:    
            do{
        
                    chucnang = menu_a();
                    switch(chucnang){
                        case 1:
                        cout << "Nhap n: "; cin >> n;
                        cout << "Nhap x: "; cin >> x;
                        cout << "Ket qua: " << De_Quy_Cau_a(n,x) << endl;
                        break;

                        case 2:
                        cout << "Nhap n: "; cin >> n;
                        cout << "Nhap x: "; cin >> x;
                        cout << "Ket qua: "  << Giai_De_Quy_Cau_a(n,x) << endl;
                        break;
                        
                        default:
                            if(chucnang != 3) cout << "Khong ton tai chuc nang nay" << endl;

                        break;
                    }
                
                }while(chucnang != 3);
            
            break;
            case 2:
                do{
                    chucnang = menu_b();
                    switch(chucnang){
                        case 1:
                        cout << "Nhap n: "; cin >> n;
                        cout << "Nhap x: "; cin >> x;
                        cout << "Nhap y: "; cin >> y;
                        cout << "Ket qua: "  << De_Quy_Cau_b(n,x,y) << endl;
                        break;

                        case 2:
                        cout << "Nhap n: "; cin >> n;
                        cout << "Nhap x: "; cin >> x;
                        cout << "Nhap y: "; cin >> y;
                        cout << "Ket qua: " << Giai_De_Quy_Cau_b(n,x,y) << endl;
                        break;
                        
                        default:
                            if(chucnang != 3) cout << "Khong ton tai chuc nang nay" << endl;
                        break;
                    }
                 } while(chucnang != 3);
            break;

            default:
                if(chucnang != 0) cout << "Khong ton tai chuc nang nay" << endl;
            break;

        }   
    }
    while (chucnang != 0);
    return 0;
}