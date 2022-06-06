### Struct
## Program Struct Sederhana
```cpp
#include <iostream>
using namespace std;

struct minuman{
	string nama;
	string tempat_beli;
	string rasa;
	int total_harga;
	int jumlah_dibeli;
};

struct manusia {
	int umur;
	int tinggi_badan;
	int berat_badan;
	int riwayat_penyakit;
	int kalori;
	int kadar_gula;
	int resikoPenyakit;
	string golongan_darah;
	string nama;
	string jenis_kelamin;
	string hobi;
	string negara;


	sakit(manusia objekpenyakit) {
		resikoPenyakit = kalori + kadar_gula + riwayat_penyakit;
		if(resikoPenyakit > 80 && resikoPenyakit >= 0 ){
			cout << " Sebaiknya ada mengatur pola hidup anda sekarang! \n";
		}else {
			cout << " Bagus! Pertahankan pola hidup anda \n";
		}
		
	}
};

int main(){
	
	minuman minuman1;
	minuman1.nama = "Boba with Extra Sweet";
	minuman1.tempat_beli = "Gerai Uncle Muthu";
	minuman1.jumlah_dibeli = 3 ;
	minuman1.rasa = "Extra Sugar";
	minuman1.total_harga = 20000;
	
	minuman minuman2;
	minuman2.nama = "Es Capucino ";
	minuman2.tempat_beli = "Starbucks";
	minuman2.jumlah_dibeli = 1;
	minuman2.rasa = "Less Sugar";
	minuman2.total_harga = 15000;
	
	manusia m1;
	m1.umur = 20;
	m1.nama = "Stephen";
	m1.tinggi_badan = 175;
	m1.berat_badan = 60;
	m1.jenis_kelamin = "Pria";
	m1.golongan_darah = "A";
	m1.negara = "Australia";
	m1.riwayat_penyakit = 0;
	m1.hobi = "Suka makan minum mengandung manis";
	m1.riwayat_penyakit = 1;
	m1.kadar_gula = 70;
	m1.kalori = 2000; //kadar perhari
	m1.resikoPenyakit = 60;
	

	
}
```
