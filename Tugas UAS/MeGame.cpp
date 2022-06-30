#include <iostream> //library in or ouput
#include <conio.h> //library movement karakter
#include <stdlib.h> //library rand
#include <windows.h> //library color
using namespace std;

#define KEY_UP 72 //tombol bergerak ke atas
#define KEY_DOWN 75 //tombol bergerak ke bawah
#define KEY_LEFT 77 //tombol bergerak ke kiri 
#define KEY RIGHT 80 //tombol bergerak ke kanan
#define KEY_EXIT 27 //tombol exit

//define structure player
struct player {
	string nama;
	int hp;
	int dmg;
	string jurus[3];
	string role;
};

//function color set
void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}

//ukuran map
const int panjangPeta = 18; //y
const int lebarPeta = 16; //x

int arrowKey = 0;
//posisi karakter di awal game
int posisiKarakterY = 1;
int posisiKarakterX = 1;

//tampilan maps
string peta[lebarPeta][panjangPeta] = {
        {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
        {"#"," "," "," "," "," "," "," "," "," ","^"," "," "," ","!"," "," ","#"},
        {"#"," "," ","#","#"," ","^","^","^","^","^"," ","^","^","^","^","^","#"},
        {"#"," ","#","^","^"," ","^","!"," "," ","#"," ","^"," "," "," ","#","#"},
        {"#"," "," "," "," ","^","^"," ","#","#","#"," ","^"," ","#","#"," ","#"},
        {"#","^","^"," "," "," "," "," "," "," ","#"," "," "," ","#"," ","E","#"},
        {"#"," ","^"," "," "," ","#","#","#"," ","^"," ","#","#","#","!","B","#"},
        {"#","E","^","^","^"," "," "," "," "," ","^"," "," "," ","#","!","E","#"},
        {"#"," ","^"," "," "," ","#","#","#","#","^"," "," "," "," ","#","#","#"},
        {"#","^"," "," ","^"," ","#"," "," ","#"," "," "," "," ","#"," ","E","#"},
        {"#"," "," "," ","^","!","#","#"," ","#"," ","^"," ","#","#","!"," ","#"},
        {"#"," ","^","E","^","#"," "," "," "," "," ","^"," "," ","^"," "," ","#"},
        {"#"," ","^","^"," "," "," "," "," ","^","^","^"," ","^","^"," "," ","#"},
        {"#"," "," ","^"," ","#","#"," "," "," "," ","E"," "," ","!"," ","^","#"},
        {"#"," "," "," "," ","#"," "," "," ","#"," "," "," ","^","^"," ","|","#"},
        {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
        };

//define judul
void judul();
//define tombol gerak karakter
void movement();
//define musuh tingkatan easy
void bertarung();
//define musuh tingkatan medium
void enemy();
//define musuh tingkatan hard
void bos();
//define gerbang bos
void tombol();


int main (){
	judul();

	
	while (1){
	    // Render grafik
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {  
				setcolor(7);     
                if(posisiKarakterX == x && posisiKarakterY == y) {
                	setcolor(12);
                    cout << "Y" << " ";
                } 
                else{
                cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
            }
			if (peta[posisiKarakterY][posisiKarakterX] == "!"){
                bertarung(); //easy
            	peta[posisiKarakterY][posisiKarakterX] = " ";
            }
            
            if (peta[posisiKarakterY][posisiKarakterX] == "E"){
                enemy(); //medium 
                peta[posisiKarakterY][posisiKarakterX] = " ";
        	}
            if (peta[posisiKarakterY][posisiKarakterX] == "B"){
                bos(); //hard
                peta[posisiKarakterY][posisiKarakterX] = " ";
        	}
        	if (peta[posisiKarakterY][posisiKarakterX] == "|"){
                tombol(); //tombol gerbang
            }
        	
	        //Input Arah karakter	
	        cout << "Masukkan Arrowkey :";
	        arrowKey = _getch();
	        movement();
	        system("cls");
        
			}	
}
//function enemy (eazy)
void bertarung(){
    int hp;
    int dmg;
    int dmgemy;
    int att;
    int hpemy1 = 300;
    
	
	//player info
	player player1;
	player1.nama = "tork";
	player1.hp = 500;
	player1.role = "Fighter";
	player1.jurus [0] = "tinju maut";
	player1.jurus [1] = "tendangan memutar";
	player1.jurus [2] = "sundulan besi";
	
	player player2;
	player2.nama = "syan";
	player2.hp =200;
	player2.role = "assasin";
	player2.jurus [0] = "pedang tajam";
	player2.jurus [1] = "sabitan sabuk";
	player2.jurus [2] = "tendangan roket";
   
   	player player3;
	player3.nama = "Jonta";
	player3.hp = 400;
	player3.role = "penembak";
	player3.jurus [0] = "pistol api";
	player3.jurus [1] = "granat sembur";
	player3.jurus [2] = "sniper";
		
    system("cls");
    	int pilih;
    	setcolor (9); //light blue
        cout << "Pilih Petarunx\n";
        cout << "1. Tork\n";
        cout << "2. Syan \n";
        cout << "3.jonta \n";
        cout << "petarunx pilihanmu = ";
        cin >> pilih;
        
        system("cls");
        kalah:
        if (pilih == 1){
            cout << "Memilih " << player1.nama << "\nMulai bertarung" << endl;
            
            while((hpemy1 > 0 ) && (player1.hp > 0)){
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player1.jurus[0] << endl;
                cout << "2." << player1.jurus[1] <<endl;
                cout << "3." << player1.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 10 + 5;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 12 + 4;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 20 + 7;
                    hpemy1 = hpemy1 - dmg;
                    break;
                    
                    }

                dmgemy = rand() % 18 + 2;
                player1.hp = player1.hp - dmgemy;  
                    
                if(hpemy1 >0 && player1.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy1 << "%" << endl;
                    cout << "Darah Karakter = " << player1.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy1 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player1.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
                    cout <<endl;
                }
                if(player1.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy1 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout <<endl;
                }
            }
        }
        if (pilih == 2){
            cout << "Memilih " << player2.nama << "\nMulai bertarung" << endl;
            
            while((hpemy1 > 0 ) && (player2.hp > 0)){
            	setcolor (14); //light yellow
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player2.jurus[0] << endl;
                cout << "2." << player2.jurus[1] <<endl;
                cout << "3." << player2.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 15 + 5;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 16 + 4;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 20 + 9;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    }

                dmgemy = rand() % 16 + 9;
                player2.hp = player2.hp - dmgemy;  
                    
                if(hpemy1 >0 && player2.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy1 << "%" << endl;
                    cout << "Darah Karakter = " << player2.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy1 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player2.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
                    cout <<endl;
                }
                if(player2.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy1 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout <<endl;
                }
            }
        }
        if (pilih == 3){
            cout << "Memilih " << player3.nama << "\nMulai bertarung" << endl;
            
            while((hpemy1 > 0 ) && (player3.hp > 0)){
            	setcolor (9); //light blue
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player3.jurus[0] << endl;
                cout << "2." << player3.jurus[1] <<endl;
                cout << "3." << player3.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 25 + 2;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 20 + 4;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 50 + 2;
                    hpemy1 = hpemy1 - dmg;
                    break;

                    }

                dmgemy = rand() % 18 + 6;
                player3.hp = player3.hp - dmgemy;  
                    
                if(hpemy1 >0 && player3.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy1 << "%" << endl;
                    cout << "Darah Karakter = " << player3.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy1 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player3.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
                    cout << endl;
                }
                if(player3.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy1 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout << endl;
                }
            }
        }
        menang:
        setcolor (12); //light red
        cout << "\nKembali ke map"<< endl;
}
	
//function enemy (medium)
void enemy(){
	int hp;
    int dmg;
    int dmgemy;
    int att;
    int hpemy2 = 1000;
	
	player player1;
	player1.nama = "vrus";
	player1.hp = 850;
	player1.role = "Ninja";
	player1.jurus [0] = "Shuriken";
	player1.jurus [1] = "Sushi Bashi";
	player1.jurus [2] = "Katana emas";
	
	player player2;
	player2.nama = "Penebas";
	player2.hp = 600;
	player2.role = "Damage";
	player2.jurus [0] = "Sontoryu";
	player2.jurus [1] = "Kepasan Pedang";
	player2.jurus [2] = "Ayunan Kapak ";
   
   	player player3;
	player3.nama = "kyon";
	player3.hp = 700;
	player3.role = "spy";
	player3.jurus [0] = "ranjau granat";
	player3.jurus [1] = "pistol angin";
	player3.jurus [2] = "upper kick";
	
    system("cls");
    	int pilih;
    	setcolor (11); //light aqua
        cout << "Pilih Petarunx\n";
        cout << "1. vrus\n";
        cout << "2. penebas \n";
        cout << "3. kyon \n";
        cout << "petarunx pilihanmu = ";
        cin >> pilih;
        
        system("cls");
        kalah:
        if (pilih == 1){
            cout << "Memilih " << player1.nama << "\nMulai bertarung" << endl;
            
            while((hpemy2 > 0 ) && (player1.hp > 0)){
            	setcolor (1); //blue
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player1.jurus[0] << endl;
                cout << "2." << player1.jurus[1] <<endl;
                cout << "3." << player1.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 22 + 5;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 15 + 4;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 29 + 7;
                    hpemy2 = hpemy2 - dmg;
                    break;
                    
                    }

                dmgemy = rand() % 10 + 10;
                player1.hp = player1.hp - dmgemy;  
                    
                if(hpemy2 >0 && player1.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy2 << "%" << endl;
                    cout << "Darah Karakter =" << player1.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy2 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player1.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
					cout << endl;
                }
                if(player1.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy2 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout << endl;
                }
            }
        }
        if (pilih == 2){
            cout << "Memilih " << player2.nama << "\nMulai bertarung" << endl;
            
            while((hpemy2 > 0 ) && (player2.hp > 0)){
            	setcolor (1);//blue
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player2.jurus[0] << endl;
                cout << "2." << player2.jurus[1] <<endl;
                cout << "3." << player2.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 25 + 5;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 16 + 9;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 37 + 9;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    }

                dmgemy = rand() % 15 + 9;
                player2.hp = player2.hp - dmgemy;  
                    
                if(hpemy2 >0 && player2.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy2 << "%" << endl;
                    cout << "Darah Karakter =" << player2.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy2 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player2.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
                    cout << endl;
                    
                }
                if(player2.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy2 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
					cout << endl;
                   
                }
            }
        }
        if (pilih == 3){
            cout << "Memilih " << player3.nama << "\nMulai bertarung" << endl;
            
            while((hpemy2 > 0 ) && (player3.hp > 0)){
            	setcolor (1);//blue
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player3.jurus[0] << endl;
                cout << "2." << player3.jurus[1] <<endl;
                cout << "3." << player3.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 30 + 2;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 29 + 7;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 32 + 2;
                    hpemy2 = hpemy2 - dmg;
                    break;

                    }

                dmgemy = rand() % 23 + 6;
                player3.hp = player3.hp - dmgemy;  
                    
                if(hpemy2 >0 && player3.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy2 << "%" << endl;
                    cout << "Darah Karakter =" << player3.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy2 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter" << player3.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
					cout << endl;
                    
                }
                if(player3.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy2 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout << endl;
                }
            }
        }
        menang:
        setcolor (12); //light red
        cout << "\nKembali ke map"<< endl;
}	
//function enemy bos (hard)
void bos(){
	int hp;
    int dmg;
    int dmgemy;
    int att;
    int hpemy3 = 2000;
    
    player player1;
	player1.nama = "Killer";
	player1.hp = 1700;
	player1.role = "Pemburu";
	player1.jurus [0] = "Snap";
	player1.jurus [1] = "Laser";
	player1.jurus [2] = "kamehameha";
	
	player player2;
	player2.nama = "Murderer";
	player2.hp = 1600;
	player2.role = "Damage";
	player2.jurus [0] = "clink";
	player2.jurus [1] = "hypno";
	player2.jurus [2] = "The Ultimate";
    
    system("cls");
    	int pilih;
    	setcolor (6); //yellow 
        cout << "Pilih Petarunx\n";
        cout << "1. Killer\n";
        cout << "2. Murderer \n";
        cout << "petarunx pilihanmu = ";
        cin >> pilih;
        
        system("cls");
        kalah:
        if (pilih == 1){
            cout << "Memilih " << player1.nama << "\nMulai bertarung" << endl;
            
            while((hpemy3 > 0 ) && (player1.hp > 0)){
            	setcolor (12); //light red
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player1.jurus[0] << endl;
                cout << "2." << player1.jurus[1] <<endl;
                cout << "3." << player1.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 30 + 5;
                    hpemy3 = hpemy3 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 25 + 10;
                    hpemy3 = hpemy3 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 30 + 20;
                    hpemy3 = hpemy3 - dmg;
                    break;
                    
                    }

                dmgemy = rand() % 20 + 10;
                player1.hp = player1.hp - dmgemy;  
                    
                if(hpemy3 >0 && player1.hp >0){
                	setcolor (6);//yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy3 << "%" << endl;
                    cout << "Darah Karakter =" << player1.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy3 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player1.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
                    cout << endl;
                    
                }
                if(player1.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy3 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout << endl;
                }
            }
        }
        if (pilih == 2){
            cout << "Memilih " << player2.nama << "\nMulai bertarung" << endl;
            
            while((hpemy3 > 0 ) && (player2.hp > 0)){
            	setcolor (12); //light red
                cout << " ========== Arena Bertarung  ==========\n"<< endl;
                cout << "Pilih Serangan: " <<endl;
                cout << "1." << player2.jurus[0] << endl;
                cout << "2." << player2.jurus[1] <<endl;
                cout << "3." << player2.jurus[2] << endl;
                cout << "jurus yang dipilih : ";
                cin >> att; 
                cout << endl;
                system("cls");

                switch(att){
                    case 1 :
                    dmg = rand() % 25 + 15;
                    hpemy3 = hpemy3 - dmg;
                    break;

                    case 2 :
                    dmg = rand() % 20 + 25;
                    hpemy3 = hpemy3 - dmg;
                    break;

                    case 3 : 
                    dmg = rand() % 35 + 15;
                    hpemy3 = hpemy3 - dmg;
                    break;

                    }

                dmgemy = rand() % 20 + 10;
                player2.hp = player2.hp - dmgemy;  
                    
                if(hpemy3 >0 && player2.hp >0){
                	setcolor (6); //yellow
                	cout << "================" << endl ;
                    cout << "Darah Musuh = " << hpemy3 << "%" << endl;
                    cout << "Darah Karakter =" << player2.hp << "%" << endl;
                    cout << "================" << endl;
                    cout << endl;
                    }
                if (hpemy3 < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh Habis" << endl;
                    cout << "Darah Karakter " << player2.hp << "%" << endl;
                    cout << "Kamu telah menang!!"<< endl;
                    cout << "================" << endl;
                    goto menang;
                    cout << endl;
                    
                }
                if(player2.hp < 0){
                	setcolor (6); //yellow
                	cout << "================" << endl;
                    cout << "Darah Musuh = " << hpemy3 << "%" << endl;
                    cout << "Darah Karakter Habis" << endl;
                    system("cls");
                    cout <<"Kamu kalah, Lakukan tanding ulang" <<endl;
                    cout << "================" << endl;
                    goto kalah;
                    cout << endl;
                }
            }
        }
		menang:
		setcolor (2); //green
		cout << "==============================================="<<endl;
        cout << "SELAMAT KAMU TELAH MENAMATKAN GAME THE ATTACKER"<< endl;
        cout << "==============================================="<<endl;
		exit(0);
}
//function membuka gerbang
void tombol(){
	int tombol;
    peta[posisiKarakterY][posisiKarakterX] == "#";
    system("cls");
    setcolor (12); //light red
    cout << "WARNING!!! DIBALIK GERBANG TERDAPAT BOS"<< endl;
    cout << "Yakin membuka gerbang? \n1.yakin\n2.tidak ";
    cin >> tombol;
    if (tombol == 1){
    	setcolor (6); //light blue
        cout << "======================\n" << endl; 
        cout << "!!!!!!!GATE OPEN!!!!!!\n" << endl;
        cout << "======================\n" << endl;
        
        setcolor(2);
        cout << "===Karakter dipindahkan ke gerbang pertama====\n";

        peta[posisiKarakterY = 8][posisiKarakterX = 15] = " ";
        
        }
    if(tombol == 2){
    	setcolor (14); //light yellow
        cout << "Gerbang masih tertutup!\n";
    }
}
//function tombol untuk gerak
void movement(){
       // Aturan menggerakkan karakter ke atas
        if(arrowKey == 72 && posisiKarakterY > 0){
			if(peta[posisiKarakterY-1][posisiKarakterX] == " " || peta[posisiKarakterY-1][posisiKarakterX] == "!" || peta[posisiKarakterY-1][posisiKarakterX] == "E"  || peta[posisiKarakterY-1][posisiKarakterX] == "B"  || peta[posisiKarakterY-1][posisiKarakterX] == "|"){
            // Gerakkan karakter ke atas
            posisiKarakterY--;
        	}
    
        // Aturan menggerakkan karakter ke bawah
        }else if(arrowKey == 80 && posisiKarakterY < panjangPeta){
        	if(peta[posisiKarakterY+1][posisiKarakterX] == " " || peta[posisiKarakterY+1][posisiKarakterX] == "!" || peta[posisiKarakterY+1][posisiKarakterX] == "E" || peta[posisiKarakterY+1][posisiKarakterX] == "B" || peta[posisiKarakterY+1][posisiKarakterX] == "|"){
            // Gerakkan karakter ke atas
            posisiKarakterY++;
        	}
        
        // Aturan menggerakkan karakter ke kiri
        }else if(arrowKey == 75 && posisiKarakterX > 0){
        	if(peta[posisiKarakterY][posisiKarakterX-1] == " " || peta[posisiKarakterY][posisiKarakterX-1] == "!" || peta[posisiKarakterY][posisiKarakterX-1] == "E" || peta[posisiKarakterY][posisiKarakterX-1] == "B" || peta[posisiKarakterY][posisiKarakterX-1] == "|" ){
            // Gerakkan karakter ke atas
            posisiKarakterX--;
        	}
        
        // Aturan menggerakkan karakter ke kanan
        }else if(arrowKey == 77 && posisiKarakterX < lebarPeta){
			if(peta[posisiKarakterY][posisiKarakterX+1] == " " || peta[posisiKarakterY][posisiKarakterX+1] == "!" || peta[posisiKarakterY][posisiKarakterX+1] == "E" || peta[posisiKarakterY][posisiKarakterX+1] == "B" || peta[posisiKarakterY][posisiKarakterX+1] == "|"){
            // Gerakkan karakter ke atas
            posisiKarakterX++;
        	}
		
		//aturan tombol exit
		}else if (arrowKey == 27){
			setcolor (12); //red
			cout << "\nTerima Kasih telah Memainkan Program Ini";
			exit(0);
		}
}
//funtion judul game
void judul() 
{	
	string lanjut;
	setcolor (6); //yellow
	cout << "||------------------------------------------------------||\n";
	cout << "||                 Welcome to The Attacker              ||\n";
	cout << "||                    a game made by                    ||\n";
	cout << "||                   M Rizky Ramadhani                  ||\n";
	cout << "||------------------------------------------------------||\n";
	cout << endl;
	cout << "The Attacker adalah game yang berlatar tempat disebuah tempat.\n";
	cout << "Dimana setiap karakter diharuskan bertarung di tempat tersebut.\n";
	cout << "Karakter akan menghadapi berbagai musuh dari easy sampai bos. \n";
	cout << "Ayo mainkan The Attacker dan Bantu Karakter agar dapat mengalahkan Bos!!\n";
	
	cout << "\nMasukkan M untuk melanjutkan" << endl;
    cin >> lanjut;
    system("cls");	
    
    cout << "Aturan di dalam game : \n";
    cout << "Kalahkan Musuh dan Bos Untuk Memenangkan GAME ";
    cout << "symbol Y = player\n ";
    cout << "symbol ^ = pohon, tidak dapat dilewati player\n ";
    cout << "symbol # = batu atau gedung, tidak dapat dilewati player\n ";
    cout << "symbol ! = musuh easy, dapat dilawan player\n ";
    cout << "symbol E = musuh medium, dapat dilawan player\n ";
    cout << "symbol B = bos hard, dapat dilawan player\n ";
    
    cout << "\nMasukkan M untuk melanjutkan" << endl;
    cin >> lanjut;
    system("cls");
    
    
}
