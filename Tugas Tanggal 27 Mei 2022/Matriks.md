# Matriks Program Membuat Game Berbasis Tile 2D
### Nama Game Menemukan Harta Karun
```cpp
#include <iostream>
using namespace std;

#define Atas 10 //tombol bergerak ke atas
#define Bawah 20 //tombol bergerak ke bawah
#define Kiri 30 //tombol bergerak ke kiri 
#define Kanan 40 //tombol bergerak ke kanan

int main() {
    
    int panjangPeta = 12; // x
    int lebarPeta = 10; // y
    
    int posisiKarakterY = 2;
    int posisiKarakterX = 6;
    
    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";
    //1 = Jalan atau rumput (bisa dilewati karakter)
    //2 = Batu (tidak bisa dilewati karakter)
    //3 = genangan air (bisa dilewati dan muncul Harta karun secara random)
    //4 = semak semak (dapat dilewati dan muncul harta karun secara random)
    //5 = pohon
    int peta[lebarPeta][panjangPeta] = {
        {5,5,5,5,5,5,1,5,5,5,5,5},
        {5,5,2,2,1,1,1,1,1,1,5,5},
        {5,5,2,1,4,4,4,4,1,1,5,5},
        {5,5,2,1,4,1,1,1,1,2,5,5},
        {1,1,1,1,4,1,1,1,1,1,1,1},
        {5,5,3,3,1,2,1,1,1,1,5,5},
        {5,5,3,3,4,4,1,1,2,1,5,5},
        {5,5,1,1,4,4,1,3,3,3,5,5},
        {5,5,1,4,4,1,1,3,3,3,5,5},
	{5,5,5,5,5,5,1,5,5,5,5,5},
		
    };
    
    int arrowKey = 0;

    
    while(1) {
        // Input Keyboard
        cout<<	"\n Keterangan :\n Bergerak Ke Atas = 10\n Bergerak Ke Bawah = 20\n Bergerak Ke Kiri = 30\n Bergerak Ke Kanan = 40\n"<<endl;
        cout << "Masukan arrow key ";
        cin >> arrowKey;
        cout << "Arrow key yang dimasukan " << arrowKey << "\n"<<endl;
        
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
        
	}
    return 0;
}
```
