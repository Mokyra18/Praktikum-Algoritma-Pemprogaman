# Praktikum Algoritma Pemprogaman
## Tugas Praktikum Algoritma Tanggal 20 Mei 2022

### While

```cpp
//Program while menurunkan nilai deret dengan batas

#include <iostream>
using namespace std;
int main(){
     int deret;
     cout<<"============================="<<endl;
     cout<<" Program Deret Angka (While) "<<endl;
     cout<<"=============================\n\n";
     cout<<"Masukan deret Angka yang akan ditampilkan : ";
     cin>>deret;
     cout<<endl;

     while(deret>0 && deret<100){
          cout<<deret<<"  ";
          deret--; 
     }

     cout<<"\n\n== Deret Selesai Ditampilkan ==\n";

     return 0;
}
```


### Do While

```cpp
// program untuk menemukan jumlah angka positif dengan do while
// jika pengguna menginputkan angka negatif, loop berakhir

#include <iostream>
using namespace std;
 
int main() {
    int angka =0;
    int i = 0;
    
    cout << " == Program Menjumlahkan Angka Positif == \n";
    do {
    cout << " Masukan Angka = ";
    cin >> angka;
    i += angka;
    
    } 
    while (angka >= 0); {
        cout << "\nJumlah akhirnya = " << i << endl;
    }
    return 0;
}
```

### Struct & Break

```cpp
//Program Struct dan break
#include <iostream>

using namespace std;

struct aplikasi_x {
  int no;
  string nama;
  string pendiri;
  string negara;
};

int main() {

  aplikasi_x apk[] = {
    {
      1,
      "Instagram",
      "Kevin Systrom",
      "Amerika"
    },
    {
      2,
      "WhatsApp",
      "Brian Acton & jan koum",
      "Amerika"
    },
    {
      3,
      "Facebook",
      "Mark Zuckerberg",
      "Amerika"
    },
    {
      4,
      "Tiktok",
      "Zhang Yiming",
      "China"
    },
    {
      5,
      "Telegram",
      "Pavel Durov & Nikolai Durov",
      "Rusia"
    }
  };

  int ApkTerlaris = 4;

  for (int i = 0; i < 5; i++) {

    if (apk[i].no == ApkTerlaris) {
      cout << "Aplikasi " << apk[i].nama << " merupakan aplikasi terlaris tahun 2021, diunduh 656 juta!\n";

      break;
    }

    cout << "Aplikasi " << apk[i].nama << " pendirinya " << apk[i].pendiri << " dari negara " << apk[i].negara << "." << endl;
  }

}
```

### Struct & Continue

```cpp
//Program Struct dengan Continue memilih makanan dan minuman yang kadaluarsa 
#include <iostream>
using namespace std;

struct Produk_t {
    int no;
    string nama;
    int harga;
    int expired;
};

int main() {
    
    int expired_maksimal = 2021;
    //jika expired barang kurang dari sama dengan tahun 2021 harus dibuang
    
    Produk_t produk[] = {
        {1, "Kaki 3 Larutan 200ml", 3900, 2023},
        {2, "Lemon Tea 330ml", 4000, 2022},
        {3, "Buahvita Apple 500ml", 15400, 2018},
        {4, "Teh Pucuk Harum", 6600, 2022},
        {5, "Mayo Sarden Tomato 425g", 24000, 2019},
        {6, "Sarimie Mie Goreng 100g", 3000, 2022},
        {7, "Tropical Minyak Goreng 2L", 50000, 2025},
        {8, "Abon Sapi 100g", 11300, 2021},
        {9, "Energen Sereal 10x32g", 21600, 2023},
        {10, "Chocolate meises 90g", 5000, 2015},
    };
    
    for(int i = 0; i < 10; i++) {
        
        if(produk[i].expired > expired_maksimal) {
            cout<< produk[i].nama << " Belum Expired " << endl;
            continue;
        }
        
        cout << "Produk " << produk[i].nama << " Sudah Expired! Silahkan Buang" << endl;
    }
    
}
```

### Matriks
```cpp
#include <iostream>

using namespace std;

#define Atas 72 //tombol bergerak ke atas
#define Bawah 80 //tombol bergerak ke bawah
#define Kiri 75 //tombol bergerak ke kiri 
#define Kanan 77 //tombol bergerak ke kanan

int main() {
    
    int panjangPeta = 10; // x
    int lebarPeta = 8; // y
    
    int posisiKarakterY = 4;
    int posisiKarakterX = 4;
    
    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";
    //1 = Jalan
    //2 = Batu
    //3 = genangan air
    //4 = gedung
    //5 = pohon
    int peta[lebarPeta][panjangPeta] = {
        {2,2,1,1,1,1,1,1,5,5},
        {3,3,3,1,1,1,1,1,2,2},
        {3,3,3,1,1,1,1,1,1,8},
        {3,3,3,1,1,1,1,1,1,8},
        {3,1,1,1,1,1,1,1,1,8},
        {3,8,8,8,8,8,1,1,1,1},
        {1,1,4,4,4,4,1,1,1,1},
        {2,2,1,5,5,1,1,1,1,1},
        
    };
    
    
    int arrowKey = 0;
    
    /*
    #define Tombol_Atas 72
    #define Tombol_Bawah 80
    #define Tombol_Kiri 75
    #define Tombol_Kanan 77
    */
    
    while(1) {
        // Input Keyboard
        cout << "Masukan arrow key ";
        cin >> arrowKey;
        cout << "Arrow key yang dimasukan " << arrowKey << "\n";
        
        // Aturan menggerakkan karakter ke atas
        if(arrowKey == 72 && (peta[posisiKarakterY-1][posisiKarakterX] == 1 || peta[posisiKarakterY-1][posisiKarakterX] == 4) && posisiKarakterY >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY-1;
        }
        
        // Aturan menggerakkan karakter ke bawah
        if(arrowKey == 80 && (peta[posisiKarakterY+1][posisiKarakterX] == 1 || peta[posisiKarakterY+1][posisiKarakterX] == 4) && posisiKarakterY < lebarPeta) {
            // Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY+1;
        }
        
        // Aturan menggerakkan karakter ke kiri
        if(arrowKey == 75 && (peta[posisiKarakterY][posisiKarakterX-1] == 1 || peta[posisiKarakterY][posisiKarakterX-1] == 4) && posisiKarakterX >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX-1;
        }
        
        // Aturan menggerakkan karakter ke kanan
        if(arrowKey == 77 && (peta[posisiKarakterY][posisiKarakterX+1] == 1 || peta[posisiKarakterY][posisiKarakterX+1] == 4) && posisiKarakterX < panjangPeta) {
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
