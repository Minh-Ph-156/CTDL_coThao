#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string Tran = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string Doi_co_so_k(int n, int k){
    string new_n = "";
    while(n > 0){
        int idx = n % k;
        if (idx == 0){
        new_n += Tran[idx];
        n /= k;
        }else{
            new_n += Tran[idx];
            n /= k;
        }
    }
    string res = "";
    for(int i = new_n.length()-1; i >= 0; i--){
        res += new_n[i];
    }
    return res;
}


int Find(char x){
    for(int i = 0; i < Tran.length(); i++){
        if(x == Tran[i]){
            return i;
        }
    }
    return -1;
}
int Hexa_to_dec(string n){
    int res = 0;
    int range = n.length();
    for(int i = range-1; i >= 0; i--){
        res += Find(n[i])*pow(16,(range-i-1));
    }
    return res;
}
int Bina_to_dec(string n){
    int res = 0;
    int range = n.length();
    for(int i = range-1; i >= 0; i--){
        if(n[i] == '1') res += pow(2,(range-i-1));
    }
    return res;
}
int menu(){
    int chucnang;
    cout << "1. Doi He Thap Phan Sang He Nhi Phan" << endl;
    cout << "2. Doi He Thap Phan Sang He Thap Luc" << endl;
    cout << "3. Doi He Nhi Phan Sang He Thap Phan" << endl;
    cout << "4. Doi He Thap Luc Sang He Thap Phan" << endl;
    cout << "0. Ket thuc chuong trinh" << endl;
    cin >> chucnang;
    return chucnang;
}
int main(){
    int chucnang;
    string s;
    int x;
    do{
        chucnang = menu();
        switch(chucnang){
            case 1:
                cout << "Nhap so thuc duong muon doi: "; cin >> x;
                cout << endl;
                cout << Doi_co_so_k(x,2) << endl;
            
            break;

            case 2:
                cout << "Nhap so thuc duong muon doi: "; cin >> x;
                cout << endl;
                cout << Doi_co_so_k(x,16) << endl;
            
            break;

            case 3:
                cout << "Nhap chuoi so nhi phan muon doi: "; cin >> s;
                cout << endl;
                cout << Bina_to_dec(s) << endl;
            break;
            
            case 4:
                cout << "Nhap chuoi so thap luc phan muon doi: "; cin >> s;
                cout << endl;
                cout << Hexa_to_dec(s) << endl;
            break;
        }

    }while(chucnang != 0);

    return 0;
}
