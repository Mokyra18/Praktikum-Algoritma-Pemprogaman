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
