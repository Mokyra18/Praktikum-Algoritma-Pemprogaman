
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <MMsystem.h>
using namespace std;

#define KEY_UP 72 //tombol bergerak ke atas
#define KEY_DOWN 75 //tombol bergerak ke bawah
#define KEY_LEFT 77 //tombol bergerak ke kiri 
#define KEY RIGHT 80 //tombol bergerak ke kanan
#define KEY_EXIT 27 //tombol exit

void judul_game() 
{	

	cout << "||------------------------------------------------------||\n";
	cout << "||                  Welcome to The Maze                 ||\n";
	cout << "||                    a game made by                    ||\n";
	cout << "||                   M Rizky Ramadhani                  ||\n";
	cout << "||------------------------------------------------------||\n";
	cout << endl;
	cout << "The Maze adalah game yang berlatar tempat disebuah labirin.\n";
	cout << "Dimana setiap karakter diharuskan mengeksplor labirin.\n";
	cout << "Karakter akan menghadapi berbagai rintangan di dalam\n";
	cout << "labirin seperti melawan musuh dan mencari item-item.\n";
	cout << "Ayo mainkan The Maze dan Bantu Karakter agar dapat survive dari labirin!\n";
}

void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

struct treasureInfo {
	string nama;
	int hp;
	int def;
	int damage;
	

};

struct monsterInfo {
	string nama;
	int Hp;
	int damage;
	int def;

	void AtkMonster(int *player_hp, int *player_def)
	{
		*player_hp = *player_hp - (damage - *player_def);
	}
};

struct playerInfo {
	string nama;
	int Hp;
	int damage;
	int def; 
	
	void AtkPlayer(int *monster_hp, int *monster_def)
	{
		*monster_hp = *monster_hp - (damage - *monster_def);
	}	
};


	
int main() {
    
    //treasure info
    treasureInfo bonus[] = {
	{"Pedang Legenda", 0, 100, 1000},
	{"Dragon Armor", 1000, 1000, 20},
	};
	
	//player info 
	playerInfo player;
		player.nama = "Berandalan Terpelajar";
		player.Hp = 1000;
		player.damage = 200;
		player.def = 100;
	
	//monster info
		monsterInfo monster1;
		monster1.nama =	"Zombie Kelaparan";
		monster1.Hp = 2000;
		monster1.damage = 100;
		monster1.def = 30;
		
		monsterInfo monster2;
		monster2.nama =	"Buaya Ganas";
		monster2.Hp = 3000;
		monster2.damage = 120;
		monster2.def = 40;
	
    //ukuran peta
    int panjangPeta = 15; // x
    int lebarPeta = 12; // y
    
    //posisi karakter dalam peta
    int posisiKarakterY = 3;
    int posisiKarakterX = 3;
    int randomTreasure;
    int randomMonster;
    int pilihan;
	int serang; 
	char keputusan;
    
    /*1 = Jalan berbatu (bisa dilewati karakter)
    3 = sungai (bisa dilewati dan muncul Harta karun secara random)
    4 = tanah (dapat dilewati dan muncul harta karun secara random)
    5 = dinding batu (tidak dapat dilewati karakter)
    */
	
     int peta[lebarPeta][panjangPeta] = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 1, 3, 1, 5, 5, 3, 3, 3, 3, 3, 3, 5, 5 ,5},
        {5, 1, 3, 1, 1, 1, 1, 5, 1, 1, 1, 1, 3, 5, 5},
        {5, 5, 3, 3, 3, 5, 5, 5, 1, 5, 3, 3, 3, 5, 5},
        {5, 1, 5, 5, 1, 1, 1, 1, 1, 3, 1, 1, 5, 5, 5},
        {5, 1, 5, 1, 1, 3, 3, 1, 1, 3, 3, 5, 5, 5, 5},
        {5, 1, 1, 1, 1, 5, 3, 1, 5, 5, 1, 1, 5, 5, 5},
        {5, 1, 5, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 5, 5},
        {5, 1, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 5},
        {5, 5, 5, 1, 3, 3, 3, 3, 3, 3, 1, 5, 1, 5, 5},
        {5, 1, 1, 1, 3, 5, 5, 5, 3, 3, 3, 3, 3, 5, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5},
    };
    setcolor (15);
    judul_game();
    cout << endl;
    setcolor (12);
    cout <<"\nKarakter Anda Berada di Y: " << posisiKarakterY << " dan X: " << posisiKarakterX << "\n";
	int arrowKey = 0;
	//int move_Random = rand() %2 +1  ;  // random number between 1 and 2 
    
    while(true) {
	randomTreasure = rand() % 30;
    	randomMonster = rand () % 30;
        // Input Keyboard
        cout << "\nMasukan Arah = ";
        arrowKey = getch();
        cout << "\nArah yang dimasukan " << arrowKey << "\n"<<endl;
		
		system("cls");
        
        // Aturan menggerakkan karakter ke atas
        if(arrowKey == 72 && posisiKarakterY > 0){
			if(peta[posisiKarakterY-1][posisiKarakterX] == 1 || peta[posisiKarakterY-1][posisiKarakterX] == 3){
            // Gerakkan karakter ke atas
            posisiKarakterY--;
        	}
    
        // Aturan menggerakkan karakter ke bawah
        }else if(arrowKey == 80 && posisiKarakterY < panjangPeta){
        	if(peta[posisiKarakterY+1][posisiKarakterX] == 1 ||  peta[posisiKarakterY+1][posisiKarakterX] == 3){
            // Gerakkan karakter ke atas
            posisiKarakterY++;
        	}
        
        // Aturan menggerakkan karakter ke kiri
        }else if(arrowKey == 75 && posisiKarakterX > 0){
        	if(peta[posisiKarakterY][posisiKarakterX-1] == 1 ||  peta[posisiKarakterY][posisiKarakterX-1] == 3){
            // Gerakkan karakter ke atas
            posisiKarakterX--;
        	}
        
        // Aturan menggerakkan karakter ke kanan
        }else if(arrowKey == 77 && posisiKarakterX < lebarPeta){
			if(peta[posisiKarakterY][posisiKarakterX+1] == 1 ||  peta[posisiKarakterY][posisiKarakterX+1] == 3){
            // Gerakkan karakter ke atas
            posisiKarakterX++;
        	}
		
		//aturan tombol exit
		}else if (arrowKey == 27){
			setcolor (12);
			cout << "Terima Kasih telah Memainkan Program Ini";
			exit(0);
		}
		
        //render grafik
	    for (int y = 0; y < lebarPeta; y++)
		{
		  for (int x = 0; x < panjangPeta; x++)
		    {
					if (posisiKarakterX == x && posisiKarakterY == y)
				{
					setcolor (12);
					cout << 'P';	
				}
					else if (peta[y][x] == 1)
				{
			  		setcolor (15);		//white
			  		cout << '.';		//jalan
				}
					else if (peta[y][x] == 3)
				{
			  		setcolor (9);		//Blue
			  		cout << '~' ;		//sungai
				}
		      		else if (peta[y][x] == 5)
				{
			  		setcolor (8);		//grey
			  		cout << '#';		//dinding tembok
				}
		     		else
		     	{
				}
		    }
		  cout << endl;
		}
		
		//Random treasure 
		if(peta[posisiKarakterX][posisiKarakterY] == 1){
			cout << endl;
			cout << "Karakter Sedang Berada di Jalan"<<endl;
			if (randomTreasure == 1){
				setcolor (12);
				cout << "Anda menemukan tresure " << bonus[0].nama << " Stats Hp = " << bonus[0].hp << " Damage = " << bonus[0].damage << " Defense = " << bonus[0].def << endl;
				cout << "Ambil atau Tingalkan? (y/t)";
				cin >> keputusan;
				
				if (keputusan == 'y' || keputusan == 'Y'){
					
					//Hp
					cout << "Menambahkan stats Hp dari " << player.Hp << " Menjadi ";
					player.Hp = player.Hp + bonus[0].hp;
					int updateHp;
					updateHp = player.Hp;
					cout << updateHp << endl;
					
					//damage
					cout << "Menambahkan stats damage dari " << player.damage << " Menjadi ";
					player.damage = player.damage + bonus[0].damage;
					int updatedmg;
					updatedmg = player.damage;
					cout << updatedmg << endl;
					
					//defense
					cout << "Menambahkan stats defense dari " << player.def<< " Menjadi ";
					player.def = player.def + bonus[0].def;
					int updatedef;
					updatedef = player.def;
					cout << updatedef << endl;
					
					setcolor (6);
					cout << "total status akhir: \n";
					cout << "Hp = " << updateHp <<endl;
					cout << "Damage = " << updatedmg <<endl;
					cout << "Defense = "<< updatedef << endl;
					
				}else if (keputusan == 2 || keputusan >= 2){
					setcolor (6);
					cout << "treasure ditinggalkan ";
				}
				
			}else if (randomTreasure == 2){
				setcolor (12);
				cout << "Anda menemukan tresure " << bonus[1].nama << " Stats Hp = " << bonus[1].hp << " Damage = " << bonus[1].damage << " Defense = " << bonus[0].def << endl;
				cout << "Ambil atau Tingalkan? (y/t)";
				char keputusan;
				cin >> keputusan;
				
				if (keputusan == 'y' || keputusan == 'Y'){
					
					//Hp
					cout << "Menambahkan stats Hp awal = " << player.Hp << endl;
					player.Hp = player.Hp + bonus[1].hp;
					int updateHp;
					updateHp = player.Hp;
					
				
					//damage
					cout << "Menambahkan stats damage dari " << player.damage << endl;
					player.damage = player.damage + bonus[1].damage;
					int updatedmg;
					updatedmg = player.damage;
					
					
					//defense
					cout << "Menambahkan stats defense dari " << player.def<< endl ;
					player.def = player.def + bonus[1].def;
					int updatedef;
					updatedef = player.def;
					
					setcolor (6);
					cout << "total status akhir: \n";
					cout << "Hp = " << updateHp <<endl;
					cout << "Damage = " << updatedmg <<endl;
					cout << "Defense = "<< updatedef << endl;
				}else if (keputusan == 2 || keputusan >= 2){
					setcolor (6);
					cout << "treasure ditinggalkan ";
				}
			}
		}
		
		//random monster 1
		if(peta[posisiKarakterX][posisiKarakterY] == 1){
        	cout<<"Karakter berada di jalan!\n";
            if (randomMonster == 1) {
            	setcolor (6);
                cout << "Anda Menemukan " << monster1.nama;
				cout << "Status Monster : \n";
				cout << "Hp = " << monster1.Hp << endl; 
				cout << "Damage = "<< monster1.damage <<endl; 
				cout << "Defense = " << monster1.def <<endl;
                
                cout <<"Anda Ingin bertarung ? (1/0)\n";
                cout << "1. lawan\n";
                cout << "0. kabur\n";
                cin>>serang;
                
                if(serang == 0){
                		cout<<"Anda memilih kabur.."<<endl;
				}else if(serang == 1){
						cout<<"Bersiap bertarung!" <<endl;
						
				}else{
					cout << endl;
				}
				 while(serang != 0 && serang == 1)
				{

				char input_battle = ' ';
				cout << " ========== Arena Bertarung  ==========\n"<< endl;
				cout << "Karakter Anda " << player.nama << " Hp : " << player.Hp << " damage " << player.damage << " defend " << player.def << endl;
				cout << monster1.nama << " Hp : " << monster1.Hp << " damage " << monster1.damage << " defend " << monster1.def  << endl;
				cout << "Tekan q untuk menyerang!" << endl;
				input_battle = getch();

				if (input_battle == 'q' || input_battle == 'Q')
				{
					player.AtkPlayer(&monster1.Hp, &monster1.def);
					monster1.AtkMonster(&player.Hp, &player.def);
				}

				if (monster1.Hp <= 0)
				{
					peta[posisiKarakterY][posisiKarakterX] = 1;
					setcolor(11);
					cout << "Karakter berhasil mengalahkan " << monster1.nama << endl;
					setcolor(7);
						
					break;
				}
				
			}
		}else if (randomMonster == 2) {
            	setcolor (6);
                cout << "Anda Menemukan " << monster2.nama<<endl;
				cout << "Status Monster : \n";
				cout << "Hp = " << monster2.Hp << endl; 
				cout << "Damage = "<< monster2.damage <<endl; 
				cout << "Defense = " << monster2.def <<endl;
                
                cout <<"Anda Ingin bertarung ? (1/0)\n";
                cout << "1. lawan\n";
                cout << "0. kabur\n";
                cin>>serang;
                
                if(serang == 0){
                		cout<<"Anda memilih kabur.."<<endl;
				}else if(serang == 1){
						cout<<"Bersiap bertarung!" <<endl;
						
				}else{
					cout << endl;
				}
				 while(serang != 0 && serang == 1)
				{

				char input_battle = ' ';
				cout << " ========== Arena Bertarung  ==========\n"<< endl;
				cout << "Karakter Anda " << player.nama << " Hp : " << player.Hp << " damage " << player.damage << " defend " << player.def << endl;
				cout << monster2.nama << " Hp : " << monster2.Hp << " damage " << monster2.damage << " defend " << monster2.def  << endl;
				cout << "Tekan q untuk menyerang!" << endl;
				input_battle = getch();

				if (input_battle == 'q' || input_battle == 'Q')
				{
					player.AtkPlayer(&monster2.Hp, &monster2.def);
					monster2.AtkMonster(&player.Hp, &player.def);
				}

				if (monster2.Hp <= 0)
				{
					peta[posisiKarakterY][posisiKarakterX] = 1;
					setcolor(11);
					cout << "Karakter berhasil mengalahkan " << monster2.nama << endl;
					setcolor(7);
						
					break;
				}
				
				}
			}
	}
	
	//random monster 2
		if(peta[posisiKarakterX][posisiKarakterY] == 3){
        	cout<<"Karakter berada di sungai!\n";
            if (randomMonster == 2) {
            	setcolor (6);
                cout << "Anda Menemukan " << monster2.nama<<endl;
				cout << "Status Monster : \n";
				cout << "Hp = " << monster2.Hp << endl; 
				cout << "Damage = "<< monster2.damage <<endl; 
				cout << "Defense = " << monster2.def <<endl;
                
                cout <<"Anda Ingin bertarung ? (1/0)\n";
                cout << "1. lawan\n";
                cout << "0. kabur\n";
                cin>>serang;
                
                if(serang == 0){
                		cout<<"Anda memilih kabur.."<<endl;
				}else if(serang == 1){
						cout<<"Bersiap bertarung!" <<endl;
						
				}else{
					cout << endl;
				}
				 while(serang != 0 && serang == 1)
				{
					
				char input_battle = ' ';
				cout << " ========== Arena Bertarung  ==========\n"<< endl;
				cout << "Karakter Anda " << player.nama << " Hp : " << player.Hp << " damage " << player.damage << " defend " << player.def << endl;
				cout << monster2.nama << " Hp : " << monster2.Hp << " damage " << monster2.damage << " defend " << monster2.def  << endl;
				cout << "Tekan q untuk menyerang!" << endl;
				input_battle = getch();

				if (input_battle == 'q' || input_battle == 'Q')
				{
					player.AtkPlayer(&monster2.Hp, &monster2.def);
					monster2.AtkMonster(&player.Hp, &player.def);
				}

				if (monster2.Hp <= 0)
				{
					peta[posisiKarakterY][posisiKarakterX] = 1;
					setcolor(11);
					cout << "Karakter berhasil mengalahkan " << monster2.nama << endl;
					setcolor(7);
						
					break;
				}
				}
			}else if (randomMonster == 1) {
            	setcolor (6);
                cout << "Anda Menemukan " << monster1.nama;
				cout << "Status Monster : \n";
				cout << "Hp = " << monster1.Hp << endl; 
				cout << "Damage = "<< monster1.damage <<endl; 
				cout << "Defense = " << monster1.def <<endl;
                
                cout <<"Anda Ingin bertarung ? (1/0)\n";
                cout << "1. lawan\n";
                cout << "0. kabur\n";
                cin>>serang;
                
                if(serang == 0){
                		cout<<"Anda memilih kabur.."<<endl;
				}else if(serang == 1){
						cout<<"Bersiap bertarung!" <<endl;
						
				}else{
					cout << endl;
				}
				 while(serang != 0 && serang == 1)
				{

				char input_battle = ' ';
				cout << " ========== Arena Bertarung  ==========\n"<< endl;
				cout << "Karakter Anda " << player.nama << " Hp : " << player.Hp << " damage " << player.damage << " defend " << player.def << endl;
				cout << monster1.nama << " Hp : " << monster1.Hp << " damage " << monster1.damage << " defend " << monster1.def  << endl;
				cout << "Tekan q untuk menyerang!" << endl;
				input_battle = getch();

				if (input_battle == 'q' || input_battle == 'Q')
				{
					player.AtkPlayer(&monster1.Hp, &monster1.def);
					monster1.AtkMonster(&player.Hp, &player.def);
				}

				if (monster1.Hp <= 0)
				{
					peta[posisiKarakterY][posisiKarakterX] = 1;
					setcolor(11);
					cout << "Karakter berhasil mengalahkan " << monster1.nama << endl;
					setcolor(7);
						
					break;
				}
				
				}
			}
		}
	}
}

