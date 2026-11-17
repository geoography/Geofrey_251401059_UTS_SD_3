#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(string &nama){
    Node* temp = new Node{nama, nullptr};

    if (front == nullptr){
        front = temp;
        rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue(){
    if (front == nullptr){
        cout << "Antrean kosong!" << endl;
        return;
    }

    Node* hapus = front;
    cout << "Dequeue : " << front->nama << endl;
    front = front->next;
    delete hapus;
}

void tampilkanDB(){
    if (front == nullptr){
        cout << "Antrean kosong!" << endl;
        return;
    }

    cout << "Antrean paling depan: " << front->nama << endl;
    cout << "Antrean paling belakang: " << rear->nama << endl;
}

void jumlah(){
    Node* temp = front;
    int cnt = 0;

    while (temp->next != nullptr){
        cnt = cnt + 1;
        temp = temp->next;
    }   
    
    if (front != nullptr) cnt++;
    cout << "Jumlah pelanggan mengantre: " << cnt << " orang." << endl;
}

int main() {
    int menu;

    do{
        cout << "Menu: " << endl;
        cout << "1. Tambah antrean " << endl;
        cout << "2. Layani pelanggan paling depan " << endl;
        cout << "3. Tampilkan pelangan depan dan belakang " << endl;
        cout << "4. Jumlah pelanggan mengantre " << endl;
        cout << "5. Keluar" << endl;
        cin >> menu;
    
        switch(menu){
            case 1:{
                string nama;
                cout << "Input nama: ";
                cin.ignore();
                getline(cin, nama);
                enqueue(nama);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                tampilkanDB();
                break;
            }
            case 4:{
                jumlah();
                break;
            }
            case 5: {
                cout << "Byee..";
                break;
            }
            default: cout << "Input harus sesuai!";
        }
        cout << endl;
    } while (menu != 5);
}