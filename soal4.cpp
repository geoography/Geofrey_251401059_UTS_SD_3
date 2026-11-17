#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* kiri;
    Node* kanan;
};

Node* root = NULL;
int n, atas, bawah, target;

Node* tambah(Node* root, int angka){
    if(root == NULL){
        root = new Node();
        root->data = angka;
        root->kiri = NULL;
        root->kanan = NULL;

        return root;
    }

    if(angka > root->data) root->kanan = tambah(root->kanan, angka);  
    else if(angka < root->data) root->kiri = tambah(root->kiri, angka);  

    return root;    
}

void inOrder(Node* root){
    if (root == NULL) return;

    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

void sela(Node* root){
    if (root == NULL) return;

    inOrder(root->kiri);
    if ((root->data > bawah) && (root->data < atas))cout << root->data << " ";
    inOrder(root->kanan);
}

int cari(Node* root, int target){
    int ret = -1;


}


int main(){

    cout << "Masukkan angka (-1 = stop): ";
    cin >> n;

    while(n != -1){
        root = tambah(root, n);
        cin >> n;
    }

    inOrder(root);

    cout << "Batas bawah: ";
    cin >> bawah;
    cout << "Batas atas: ";
    cin >> atas;

    cout << endl;

    cout << "Masukkan angka yang ingin dicari ";
    cin >> target;

    cari(root, target);
    cout << "dah ga tau :)";

    

    return 0;
}