### Struct
```cpp
```

	#include <iostream>

using namespace std;

struct minuman{
	string nama;
	string tempat_beli;
	string rasa;
	int harga;
	int jumlah_dibeli;
};
struct manusia {
	int umur;
	int tinggi_badan;
	int berat_badan;
	int kadar_diabetes;
	string golongan_darah;
	string tempat_lahir;
	string nama;
	string jenis_kelamin;
	string sifat;
	string hobi;
	string negara;
	 
	void karakteristik(){
	cout << "Perkenalkan saya" << nama << "berumur " << umur << "berasal dari " << negara << "Berjenis Kelamin " << jenis_kelamin << "Golongan darah saya " << golongan_darah<< "Tinggi Badan " << tinggi_badan<< "Berat Badan" << berat_badan << "\n";
}
