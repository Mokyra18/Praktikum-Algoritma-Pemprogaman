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
