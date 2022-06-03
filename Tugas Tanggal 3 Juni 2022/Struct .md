### Struct
#include <iostream>

using namespace std;

struct skill {
	int level;
	string namaskill;
	string elemen;
	int damage;
	float kemungkinancritical;
	string kelemahan;
	int mana;
};

int main()
{
	skill skill1;
	skill1.level = 18;
	skill1.namaskill = "Fire_Ball";
	skill1.elemen = "Fire";
	skill1.kemungkinancritical =5.7;
	skill1.kelemahan = "Water";
	skill1.mana = 120;
	
	cout << "Skill " << skill1.namaskill << " memiliki level " << skill1.level 
	<< ", skill tersebut termasuk kedalam kategori elemen " << skill1.elemen 
	<< " dan memiliki kemungkinan critical sebesar " << skill1.kemungkinancritical << "%, skill ini lemah jika dihadapkan kepada lawan ber elemen " 
	<< skill1.kelemahan << "mana yang dibutuhkan untuk mengeluarkan skill ini sebesar "<< skill1.mana<< endl;
	

}

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

}; int main(){
	
}
	
	
	
struct hero{
	string nama;
	int basic attack;
	
}
	

	
void attack(hero *heroObject

	h1.attack(&h2);
	h2.attack(&h1);
	h2.attack(&h1);
	h2.attack($h1);
