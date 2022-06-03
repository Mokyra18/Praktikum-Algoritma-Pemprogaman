# Matriks Program Membuat Game Berbasis Tile 2D
## Nama Game Berburu Harta Karun
### Keterangan :
1 = Jalan atau rumput (bisa dilewati karakter)

2 = Batu (tidak bisa dilewati karakter)

3 = genangan air (bisa dilewati dan muncul harta karun secara random)

4 = semak semak (dapat dilewati dan muncul harta karun secara random)

5 = pohon (tidak bisa dilewati karakter)

## Versi Pertama 
```cpp
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

#define KEY_UP 72 //tombol bergerak ke atas
#define KEY_DOWN 75 //tombol bergerak ke bawah
#define KEY_LEFT 77 //tombol bergerak ke kiri 
#define KEY RIGHT 80 //tombol bergerak ke kanan

struct treasureInfo {
	string nama;
	string kelangkaan;
	int reward;
};

int main() {
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    int panjangPeta = 12; // x
    int lebarPeta = 10; // y
    
    int posisiKarakterY = 2;
    int posisiKarakterX = 6;
    int randomTreasure;
    
    /*1 = Jalan atau rumput (bisa dilewati karakter)
    2 = Batu (tidak bisa dilewati karakter)
    3 = sungai (bisa dilewati dan muncul Harta karun secara random)
    4 = semak semak (dapat dilewati dan muncul harta karun secara random)
    5 = pohon (tidak dapat dilewati karakter)
    */
    treasureInfo treasure[]{
		{
			"Harta eazy boz!",
			"Biasa aja",
			1000000
		},
		{
			"Harta Normal!",
			"Agak lumayan sih",
			2000000
		},
		{
			"Harta Epic!",
			"Bisalah buat pulang ke kampung",
			50000000
		},
		{
			"Harta Legendary!",
			"Susah Banget woy",
			1000000000
		},
		{
			"Buset Harta ONE PIECE!!!",
			"Berasa mimpi dapet harta ginian woy!",
			10000000000
		},
	};

    
    int peta[lebarPeta][panjangPeta] = {
        {5,5,5,5,5,1,1,3,5,5,5,5},
        {5,4,4,4,1,1,1,3,3,3,3,5},
        {5,4,2,1,1,1,1,5,2,2,3,5},
        {1,4,5,1,1,2,2,1,1,2,3,3},
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {3,3,1,1,1,4,4,1,1,1,1,5},
        {5,3,2,1,1,5,5,1,1,1,1,5},
        {5,3,2,2,1,4,4,1,2,2,4,5},
        {5,3,3,3,3,3,1,1,4,4,4,5},
		{5,5,5,5,5,3,1,5,5,5,5,5},
		
    };
    SetConsoleTextAttribute(h, 11);
    cout << "\nKeterangan Bergerak\n";
	cout << "Bergerak Ke Atas\n";
	cout << "Bergerak Ke Bawah\n";
	cout << "Bergerak Ke Kiri\n";
	cout << "Bergerak Ke Kanan\n";
	cout << "\n";
	cout << "======================\n";
	cout << "Selamat Berburu Harta!\n";
	cout << "======================\n";
    cout <<"\nKarakter Anda Berada di Y: " << posisiKarakterY << " dan X: " << posisiKarakterX << "\n";
	int arrowKey = 0;

    
    while(1) {
    	randomTreasure= rand()%50;
        // Input Keyboard
        SetConsoleTextAttribute(h, 10);
        cout << "\nMasukan Arah = ";
        arrowKey = getch();
        cout << "\nArah yang dimasukan " << arrowKey << "\n"<<endl;
        
		system("cls");
        
        // Aturan menggerakkan karakter ke atas
        if(arrowKey == 72 && posisiKarakterY > 0){
			if(peta[posisiKarakterY-1][posisiKarakterX] == 1 || peta[posisiKarakterY-1][posisiKarakterX] == 3 || peta[posisiKarakterY-1][posisiKarakterX] == 4 ){
            // Gerakkan karakter ke atas
            posisiKarakterY--;
        	}
        
        // Aturan menggerakkan karakter ke bawah
        }else if(arrowKey == 80 && posisiKarakterY < panjangPeta){
        	if(peta[posisiKarakterY+1][posisiKarakterX] == 1 ||  peta[posisiKarakterY+1][posisiKarakterX] == 3 || peta[posisiKarakterY+1][posisiKarakterX] == 4 ){
            // Gerakkan karakter ke atas
            posisiKarakterY++;
        	}
        
        // Aturan menggerakkan karakter ke kiri
        }else if(arrowKey == 75 && posisiKarakterX > 0){
        	if(peta[posisiKarakterY][posisiKarakterX-1] == 1 ||  peta[posisiKarakterY][posisiKarakterX-1] == 3 || peta[posisiKarakterY][posisiKarakterX-1] == 4 ){
            // Gerakkan karakter ke atas
            posisiKarakterX--;
        	}
        
        // Aturan menggerakkan karakter ke kanan
        }else if(arrowKey == 77 && posisiKarakterX < lebarPeta){
			if(peta[posisiKarakterY][posisiKarakterX+1] == 1 ||  peta[posisiKarakterY][posisiKarakterX+1] == 3 || peta[posisiKarakterY][posisiKarakterX+1] == 4 ){
            // Gerakkan karakter ke atas
            posisiKarakterX++;
        }
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
    
	    
    
    //Lokasi player berada && hadiahnya
    if(peta[posisiKarakterX][posisiKarakterY] == 1){
    SetConsoleTextAttribute(h, 12);
    cout<<" \nKarakter Sedang ada di Jalan Bos!\n";
        if (randomTreasure == 1) {
            cout << " Berhasil Mendapatkan " << treasure[0].nama << "  " << treasure[0].kelangkaan << "\n Isinya = " << treasure[0].reward << endl;
                
        }else if (randomTreasure == 2) {
            cout << " Berhasil Mendapatkan " << treasure[1].nama << " " << treasure[1].kelangkaan << "\n Isinya = " << treasure[1].reward << endl;
                
        }else if (randomTreasure == 3) {
            cout << " Beruntung Mendapatkan " << treasure[2].nama << " " << treasure[2].kelangkaan << "\n Isinya = " << treasure[2].reward << endl;
                
        }else if (randomTreasure == 4) {
            cout << " Lumayan Beruntung Mendapatkan " << treasure[3].nama << " " << treasure[3].kelangkaan << "\n Isinya = " << treasure[3].reward << endl;
                
        }else if (randomTreasure == 5) {
        	SetConsoleTextAttribute(h, 14);
            cout << " Sangat Beruntung Mendapatkan " << treasure[4].nama << " " << treasure[4].kelangkaan << "\n isinya = " << treasure[4].reward << endl;    
        }
	randomTreasure = 0;
        	
	}else if(peta[posisiKarakterX][posisiKarakterY] == 3){
	SetConsoleTextAttribute(h, 12);
	cout<<" \nKarakter Lagi Ada di Sungai Brody!\n";
		 if (randomTreasure == 1) {
            cout << " Berhasil Mendapatkan " << treasure[0].nama << "  " << treasure[0].kelangkaan << "\n Isinya = " << treasure[0].reward << endl;
                
        }else if (randomTreasure == 2) {
            cout << " Berhasil Mendapatkan " << treasure[1].nama << " " << treasure[1].kelangkaan << "\n Isinya = " << treasure[1].reward << endl;
                
        }else if (randomTreasure == 3) {
            cout << " Beruntung Mendapatkan " << treasure[2].nama << " " << treasure[2].kelangkaan << "\n Isinya = " << treasure[2].reward << endl;
                
        }else if (randomTreasure == 4) {
            cout << " Lumayan Beruntung Mendapatkan " << treasure[3].nama << " " << treasure[3].kelangkaan << "\n Isinya = " << treasure[3].reward << endl;
                
        }else if (randomTreasure == 5) {
        	SetConsoleTextAttribute(h, 14);
            cout << " Sangat Beruntung Mendapatkan " << treasure[4].nama << " " << treasure[4].kelangkaan << "\n isinya = " << treasure[4].reward << endl;    
        }
              
    randomTreasure = 0;
            
	}else if(peta[posisiKarakterX][posisiKarakterY] == 4){
	SetConsoleTextAttribute(h, 12);
	cout<<" \nKarakter Sedang di Semak Lagi Sembunyi!";
	 if (randomTreasure == 1) {
            cout << " Berhasil Mendapatkan " << treasure[0].nama << "  " << treasure[0].kelangkaan << "\n Isinya = " << treasure[0].reward << endl;
                
        }else if (randomTreasure == 2) {
            cout << " Berhasil Mendapatkan " << treasure[1].nama << " " << treasure[1].kelangkaan << "\n Isinya = " << treasure[1].reward << endl;
                
        }else if (randomTreasure == 3) {
            cout << " Beruntung Mendapatkan " << treasure[2].nama << " " << treasure[2].kelangkaan << "\n Isinya = " << treasure[2].reward << endl;
                
        }else if (randomTreasure == 4) {
            cout << " Lumayan Beruntung Mendapatkan " << treasure[3].nama << " " << treasure[3].kelangkaan << "\n Isinya = " << treasure[3].reward << endl;
                
        }else if (randomTreasure == 5) {
        	SetConsoleTextAttribute(h, 14);
            cout << " Sangat Beruntung Mendapatkan " << treasure[4].nama << " " << treasure[4].kelangkaan << "\n isinya = " << treasure[4].reward << endl;    
        }
	}
    randomTreasure = 0;
	}
    return 0;
}
```

## Versi Sederhana
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
