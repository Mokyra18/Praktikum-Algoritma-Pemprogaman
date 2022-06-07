# Struct
## Program Struct Sederhana tentang minuman dan manusia
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
	
	printPenyakit(){
		cout << "Resiko " << nama << " terkena penyakit diabetes saat ini " << resikoPenyakit << "%\n";
	}

	minum(minuman objekManusia) {
		resikoPenyakit = kalori + kadar_gula;
		if(resikoPenyakit > 80 && resikoPenyakit >= 0 ){
			cout << "Bahaya! Kurangi hal-hal yang manis!"<<endl;
		}else {
			cout << "Bagus! Pertahankan pola hidup"<<endl;
		}
		
		printPenyakit();
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
	m1.riwayat_penyakit = 2; //jumlah riwayat penyakit yang dimiliki
	m1.hobi = "Suka makan minum mengandung manis";
	m1.kadar_gula = 60; //dalam persen perhari
	m1.kalori = 30; //kadar perhari dalam persen perhari
	m1.resikoPenyakit = 0; //dalam persen
	
	
	manusia m2;
	m2.umur = 22;
	m2.nama = "Mark";
	m2.tinggi_badan = 170;
	m2.berat_badan = 65;
	m2.jenis_kelamin = "Pria";
	m2.golongan_darah = "O";
	m2.negara = "Singapore";
	m2.riwayat_penyakit = 1; //jumlah riwayat penyakit yang dimiliki
	m2.hobi = "Berolahraga";
	m2.kadar_gula = 30; //dalam persen perhari
	m2.kalori = 30; //kadar perhari dalam persen perhari
	m2.resikoPenyakit = 0; //dalam persen
	
	cout << m1.nama << " Membeli " << minuman1.jumlah_dibeli << " " << minuman1.nama << " di " << minuman1.tempat_beli << " harganya \nRp." << minuman1.total_harga << "\n";
	cout << "Status tubuh " << m1.nama << " saat ini :\n";
	m1.minum(minuman1);
	m1.minum(minuman2);
	cout << endl;
	cout << m2.nama << " Membeli " << minuman2.jumlah_dibeli << " " << minuman2.nama << " di " << minuman2.tempat_beli << " harganya \nRp." << minuman2.total_harga << "\n";
	cout << "Status tubuh " << m2.nama << " saat ini :\n";
	m2.minum(minuman1);
	m2.minum(minuman2);

	return 0;	
}
```
## Program Struct tentang game
```cpp
```
