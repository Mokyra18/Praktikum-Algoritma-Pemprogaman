# Matriks Program Membuat Game Berbasis Tile 2D
## Nama Game Berburu Harta Karun
### Keterangan :
1 = Jalan atau rumput (bisa dilewati karakter)

2 = Batu (tidak bisa dilewati karakter)

3 = genangan air (bisa dilewati dan muncul harta karun secara random)

4 = semak semak (dapat dilewati dan muncul harta karun secara random)

5 = pohon (tidak bisa dilewati karakter)
```cpp
#include <iostream>
#include <stdlib.h>
using namespace std;

#define Atas  10 //tombol bergerak ke atas
#define Bawah 20 //tombol bergerak ke bawah
#define Kiri  30 //tombol bergerak ke kiri 
#define Kanan 40 //tombol bergerak ke kanan

int main() {
    
    int panjangPeta = 12; // x
    int lebarPeta = 10; // y
    
    int posisiKarakterY = 2;
    int posisiKarakterX = 6;
    
    cout<<"============================================="<<endl;
    cout << "Selamat Datang di Game Berburu Harta Karun!"<<endl;
    cout<<"============================================="<<endl;
    cout <<"\nKarakter Anda Berada di Y: " << posisiKarakterY << " dan X: " << posisiKarakterX << "\n";

    int peta[lebarPeta][panjangPeta] = {
        {5,5,5,5,5,5,1,5,5,5,5,5},
        {5,5,2,2,1,1,1,1,1,4,5,5},
        {5,5,2,1,4,1,1,4,1,1,5,5},
        {5,5,2,1,1,2,2,1,1,1,5,5},
        {1,1,1,1,1,1,1,1,4,1,1,1},
        {5,5,3,1,1,2,1,1,1,1,5,5},
        {5,5,1,1,4,2,1,1,2,3,5,5},
        {5,5,1,1,2,1,1,1,1,2,5,5},
        {5,5,3,2,2,1,1,1,3,2,5,5},
	{5,5,5,5,5,5,1,5,5,5,5,5},
		
    };
    
    int arrowKey = 0;

    
    while(1) {
        // Input Keyboard
        cout<< "\nKeterangan =\n";
		cout<< "Bergerak Ke Atas  = 10\n";
		cout<< "Bergerak Ke Bawah = 20\n";
		cout<< "Bergerak Ke Kiri  = 30\n";
		cout<< "Bergerak Ke Kanan = 40\n";
        cout << "\nMasukan arrow key = ";
        cin >> arrowKey;
        cout << "\nArrow key yang dimasukan " << arrowKey << "\n"<<endl;
        cout <<"\nKarakter Anda Berada di Y: " << posisiKarakterY << " dan X: " << posisiKarakterX << "\n";
        
        // Aturan menggerakkan karakter ke atas
        if(arrowKey == 10 && (peta[posisiKarakterY-1][posisiKarakterX] == 1 || peta[posisiKarakterY-1][posisiKarakterX] == 3 || peta[posisiKarakterY-1][posisiKarakterX] == 4 ) && posisiKarakterY >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY-1;
        }
        
        // Aturan menggerakkan karakter ke bawah
        if(arrowKey == 20 && (peta[posisiKarakterY+1][posisiKarakterX] == 1 ||  peta[posisiKarakterY+1][posisiKarakterX] == 3 || peta[posisiKarakterY+1][posisiKarakterX] == 4 ) && posisiKarakterY < lebarPeta) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY+1;
        }
        
        // Aturan menggerakkan karakter ke kiri
        if(arrowKey == 30 && (peta[posisiKarakterY][posisiKarakterX-1] == 1 ||  peta[posisiKarakterY][posisiKarakterX-1] == 3 || peta[posisiKarakterY][posisiKarakterX-1] == 4 ) && posisiKarakterX >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX-1;
        }
        
        // Aturan menggerakkan karakter ke kanan
        if(arrowKey == 40 && (peta[posisiKarakterY][posisiKarakterX+1] == 1 ||  peta[posisiKarakterY][posisiKarakterX+1] == 3 || peta[posisiKarakterY][posisiKarakterX+1] == 4 ) && posisiKarakterX < panjangPeta) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX+1;
        
        }
        
        
        // Render grafik
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {
                
                if(posisiKarakterX == x && posisiKarakterY == y) {
                    cout << 0 << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
        if (peta[posisiKarakterY][posisiKarakterX] == 3 || peta[posisiKarakterY][posisiKarakterX] == 4 ){
        	cout<<"\nHarta Karun Berada Diantara Semak dan Genangan Air Carilah!"<<endl;	
		}
		int random;
		if (peta[posisiKarakterY][posisiKarakterX] == 3 || peta[posisiKarakterY][posisiKarakterX] == 4){
		random = (rand()%5);
		cout<< "Kamu Mendapatkan " << random<< " Harta Karun!"<<endl;
		}
	}
    return 0;
}
```
