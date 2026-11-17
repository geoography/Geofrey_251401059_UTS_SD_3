#include <iostream>
#include <string>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertTail(int &nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (head == nullptr) {
        head = tail = baru;
        return;
    }
    tail->next = baru;
    tail = baru;
}

void display(){
    Node* temp = head;

    while(temp->next != nullptr){
        cout << temp->nilai << " ";
        temp = temp->next;
    }
}

void delet(int &sdtarget){
    Node* temp = head;

    while(temp->next->nilai != sdtarget){
        cout << temp->nilai << " ";
        temp = temp->next;
    }

    Node* hapus = temp->next;
    temp->next = hapus->next;

    delete hapus;
}

void deleteHead() {
    if (head == nullptr) {
        cout << "List kosong kocak!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;   
    delete temp;
}

void deleteTail() {
    if (head == nullptr) {
        cout << "List kosong kocak!" << endl;
        return;
    }
    if (head == tail) {                    
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) temp = temp->next;
    delete tail;
    temp->next = nullptr;
    tail = temp;
}

int main() {
    int menu;

    do {
        system("cls");

        cout << "Pilih menu: " << endl;
        cout << "1. Insert tail" << endl;
        cout << "2. Tampilkan seluruh data" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> menu;

        switch (menu) {
            case 1: {
                int nilai;
                cout << "nilai: ";
                cin >> nilai;
                insertTail(nilai);
                break;
            }
            case 2: display(); break;
            case 3:{ 
                int sdtarget;
                cout << "Nilai node yang ingin dihapus: ";
                cin >> sdtarget;
                delet(sdtarget); 
                break;
            }
            case 4: cout << "Keluar..." << endl; break;
            default: cout << "Input tdk sesuai!" << endl;
        }

        if (menu != 4) {
            cout << "\nTekan Enter...";
            cin.ignore();
            cin.get();
        }
    } while (menu != 4);
    return 0;
}