#include <iostream>
#include <cctype>
using namespace std;

int dataM[5][4];
string nama[5];
double nilai[5] = {0, 0, 0, 0, 0};
double tertinggi = -1, terendah = 101;
string tertinggiM, terendahM;
int lulus = 0;

int main(){
    system("cls");

    cout << "Input nilai mahasiswa: " << endl;
    
    for (int i = 0; i < 5; i ++){
        cout << "Input nama mahasiswa: ";
        cin.ignore();
        getline(cin, nama[i]);
        cout << "Input nilai mahasiswa: " << endl;
        for (int j = 0; j < 4; j++){
            if (j == 0){
                cout << "Input nilai tugas: ";
                cin >> dataM[i][j];
                nilai[i] += dataM[i][j];
            }
            else if (j == 1){
                cout << "Input nilai kuis: ";
                cin >> dataM[i][j];
                nilai[i] += dataM[i][j];
            }
            else if (j == 2){
                cout << "Input nilai UTS: ";
                cin >> dataM[i][j];
                nilai[i] += dataM[i][j];
            }
            else{
                cout << "Input nilai praktikum: ";
                cin >> dataM[i][j];
                nilai[i] += dataM[i][j];
            }
        }
        nilai[i] /= 4;
        if (nilai[i] > tertinggi){ 
            tertinggi = nilai[i];
            tertinggiM = nama[i];
        }
        if (nilai[i] < terendah){
            terendah = nilai[i];
            terendahM = nama[i];
        }
        if (nilai[i] >= 75) lulus++;
    }
    
    for (int i = 0; i < 5; i++){
        cout << "Rata-rata mahasiswa " << nama[i] << ": " << nilai[i] <<endl; 
    }

    cout << "Nilai mahasiswa tertinggi: " << tertinggiM << "dengan nilai " << tertinggi  << endl;
    cout << "Nilai mahasiswa terendah: " << terendahM << "dengan nilai " << tertinggi  << endl;
    cout << "Jumlah mahasiswa memenuhi rata-rata minimal: " << lulus << endl;
}