#include <stdio.h>
#include <conio.h>

#include "PON.C"

ListKategori K;
ListPeserta P;
ListDaerah N;
adrsKategori aK;
adrsLomba aL;
adrsDaerah aN;
adrsPeserta aP;

int choice, mChoice, pass, passAttempt;

string KAT1, KAT2, KAT3, KAT4, KAT5, nama, lomba, daerah, kategori, tmp;

void initializeList() {
	strcpy(KAT1, "Aerosport");
	strcpy(KAT2, "Games");
	strcpy(KAT3, "Martial");
	strcpy(KAT4, "Concentration");
	strcpy(KAT5, "Akuatik");

	createListKategori(&K);
	createListPeserta(&P);
	createListDaerah(&N);

	addKategori(&K, KAT1);
	addKategori(&K, KAT2);
	addKategori(&K, KAT3);
	addKategori(&K, KAT4);
	addKategori(&K, KAT5);

	/* Menambahkan data pada kategori lomba Aerosports */
	addLomba(&K, KAT1, "Aeromodelling");
	addLomba(&K, KAT1, "Gantolle");
	addLomba(&K, KAT1, "Paralayang");
	addLomba(&K, KAT1, "TerbangLayang");
	addLomba(&K, KAT1, "TerjunPayung");

	/* Menambahkan data pada kategori lomba Games Sports */
	addLomba(&K, KAT2, "Badminton");
	addLomba(&K, KAT2, "Tennis");
	addLomba(&K, KAT2, "TableTennis");
	addLomba(&K, KAT2, "Football");
	addLomba(&K, KAT2, "SepakTakraw");
	addLomba(&K, KAT2, "Futsal");
	addLomba(&K, KAT2, "Basketball");
	addLomba(&K, KAT2, "Volleyball");
	addLomba(&K, KAT2, "Baseball");
	addLomba(&K, KAT2, "Softball");

	/* Menambahkan data pada kategori lomba Martial Art */
	addLomba(&K, KAT3, "Wushu");
	addLomba(&K, KAT3, "Silat");
	addLomba(&K, KAT3, "Karate");
	addLomba(&K, KAT3, "Taekwondo");
	addLomba(&K, KAT3, "Silat");
	addLomba(&K, KAT3, "Judo");
	addLomba(&K, KAT3, "Gulat");
	addLomba(&K, KAT3, "Tinju");
	addLomba(&K, KAT3, "Binaraga");

	/* Menambahkan data pada kategori lomba Concentration Sports */
	addLomba(&K, KAT4, "Golf");
	addLomba(&K, KAT4, "Bowling");
	addLomba(&K, KAT4, "Menembak");
	addLomba(&K, KAT4, "Panahan");
	addLomba(&K, KAT4, "Billiard");
	addLomba(&K, KAT4, "Catur");

	/* Menambahkan data pada kategori lomba Akuatik Sports */
	addLomba(&K, KAT5, "Renang");
	addLomba(&K, KAT5, "RenangIndah");
	addLomba(&K, KAT5, "LoncatIndah");
	addLomba(&K, KAT5, "PoloAir");
	addLomba(&K, KAT5, "Dayung");
}

void printHeader(){
    system("cls");
	printf("============================\n");
	printf("          PON 2016          \n");
	printf("============================\n");
	printf("Total Peserta 	   : %d\n", getSumPeserta(P));
	printf("Total Daerah       : %d\n", getSumDaerah(N));
	printf("Total Lomba        : %d\n", getSumLomba(K));
	printf("============================\n");
}

void tambahPeserta(){

		do{
		system("cls");
		printHeader();
		printf("Nama Peserta    : ");
		scanf("%s", &nama);
		if (checkPesertaExistence(P, nama) == 1){
			printf("Nama tersebut telah terdaftar sebelumnya.");
			getch();
		}
	} while (checkPesertaExistence(P, nama) == 1);
	do{
		system("cls");
		printHeader();
		printf("KATEGORI LOMBA\n");
		printf("- Aerosport\n");
		printf("- Games\n");
		printf("- Martial\n");
		printf("- Concentration\n");
		printf("- Akuatik\n");
		printf("============================\n");
		printf("Nama Peserta    : %s\n", nama);
		printf("Kategori        : ");
		scanf("%s", &kategori);
		if (checkKategoriExistence(K, kategori) == 0){
			printf("Kategori yang Anda inputkan tidak ada.");
			getch();
		}
	} while (checkKategoriExistence(K, kategori) == 0);
	do{
		system("cls");
		printHeader();
		printf("Kategori %s      :            \n", kategori);
		printLombaInKategori(K, kategori, 0);
		printf("============================\n");
		printf("Nama Peserta     : %s\n", nama);
		printf("Kategori         : %s\n", kategori);
		printf("Lomba            : ");
		scanf("%s", &lomba);
		if (checkLombaExistence(K, kategori, lomba) == 0){
			printf("Lomba yang Anda inputkan tidak ada.");
			getch();
		}
	} while (checkLombaExistence(K, kategori, lomba) == 0);
	system("cls");
	printHeader();
	printf("Nama Peserta         : %s\n", nama);
	printf("Kategori             : %s\n", kategori);
	printf("Lomba                : %s\n", lomba);
	printf("Daerah               : ");
	scanf("%s", &daerah);
	if (checkDaerahExistence(N, daerah) == 0){
		addDaerah(&N, daerah);
	}
	aN = getAddressDaerah(N, daerah);
	aL = getAddressLomba(K, kategori, lomba);
	addPeserta(&P, nama, aL, aN);
	system("cls");
	printHeader();
	printf("Data berhasil diinputkan.");
	getch();
}
void tambahLomba(){

        system("cls");
		printHeader();
		printf("============================\n");
		printf("         KATEGORI LOMBA     \n");
		printf("         - Aerosport        \n");
		printf("         - Games            \n");
		printf("         - Martial          \n");
		printf("         - Concentration    \n");
		printf("         - Akuatik          \n");
		printf("============================\n");
		printf("Kategori : ");
		scanf("%s", &kategori);
		if (checkKategoriExistence(K, kategori) == 0){
			printf("Kategori yang Anda inputkan tidak ada.\n");
			getch();
		}else{
	while(checkKategoriExistence(K, kategori)!= 0){
        system("cls");
		printHeader();
		printLombaInKategori(K, kategori, 0);
		printf("============================\n");
		printf("Kategori : %s\n", kategori);
		printf("Lomba    : ");
		scanf("%s", &lomba);
		if (checkLombaExistence( K, kategori, lomba) == 1){
			printf("Lomba yang Anda inputkan sudah ada.\n");
			getch();
		}else{
        while (checkLombaExistence(K, kategori, lomba) != 1){
        addLomba(&K, kategori, lomba);
        system("cls");
        printHeader();
        printf("Data lomba berhasil diinputkan\n");
        getch();
        break;
}
        break;
		}
		break;
	}
		}
}
void lihatPeserta(){

    system("cls");
	printHeader();
	printf("DAFTAR PESERTA\n");
	printAllPeserta(P, N, K, 1);
	getch();
}


void hapusPeserta(){

    system("cls");
	printHeader();
	printf("DAFTAR PESERTA\n");
	printAllPeserta(P, N, K, 0);
	printf("\n");
	printf("============================\n");
	printf("Nama Peserta : ");
	scanf("%s", &nama);
	deletePeserta(&P, nama, &tmp);
    system("cls");
	printHeader();
	printAllPeserta(P, N, K, 0);
	printf("============================\n");
	printf("\"%s\" telah dihapus dari daftar peserta.", tmp);
	getch();
}

void hapusDaerah(){

    system("cls");
	printHeader();
	printf("DAFTAR Daerah\n");
	printAllDaerah(N);
	printf("\n");
	printf("============================\n");
	printf("Nama Daerah : ");
	scanf("%s", &daerah);
	deleteDaerah(&N, daerah, &tmp);
    system("cls");
	printHeader();
	printAllDaerah(N);
	printf("============================\n");
	printf("\"%s\" telah dihapus dari daftar daerah.", tmp);
	getch();
}


void lihatLomba(){

    system("cls");
	printHeader();
	printf("DAFTAR LOMBA\n");
	printAllLomba(K);
	getch();
}

void lihatKategori(){

    system("cls");
	printHeader();
	printf("DAFTAR KATEGORI\n");
	printf("- Aerosport\n");
	printf("- Games\n");
	printf("- Martial\n");
	printf("- Concentration\n");
	printf("- Akuatik\n");
	printf("============================\n");
	printf("Kategori : ");scanf("%s", &kategori);

	printHeader();
	printLombaInKategori(K, kategori, 1);
	getch();
}

void lihatDaerah(){

    system("cls");
	printHeader();
	printf("DAFTAR DAERAH\n");
	printAllDaerah(N);
	getch();
}

void logout(){
	choice = 0;
	mChoice = 10;
}

void lihatPesertaIndiv(){
        do{
        system("cls");
		printf("===========================\n");
		printf("||       PON 2016        ||\n");
		printf("===========================\n");
		printf("Nama Peserta : ");
		scanf("%s", &nama);
		if (checkPesertaExistence(P, nama) == 0){
			printf("Data peserta yang Anda inputkan tidak ada.\n");
			getch();
		}
	} while (checkPesertaExistence(P, nama) == 0);
    system("cls");
	printf("===========================\n");
	printf("||       PON 2016        ||\n");
	printf("===========================\n");
	printPesertaIndiv(K, N, P, nama);
	getch();
}

void lihatSeluruhPeserta(){
system("cls");
	printf("===========================\n");
	printf("||       PON 2016        ||\n");
	printf("===========================\n");
	printHeader();
	printf("\tDAFTAR PESERTA PON 2016\n");
	printAllPeserta(P, N, K, 1);
	getch();
}

void login(){
	pass = 0;
	passAttempt = 0;
	while (pass != 310597 && passAttempt != 3){
        system("cls");
		printf("=====================\n");
		printf("||      LOGIN      ||\n");
		printf("=====================\n");
		printf("\n");
		printf("Password: ");
		scanf("%d", &pass);
		passAttempt++;
		if (passAttempt == 3){

			printf("\n \n");
			printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			printf("x                                                       x\n");
			printf("x  Maaf, Anda salah memasukkan password selama 3 kali.  x\n");
			printf("x                                                       x\n");
			printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
			getch();
		}
	}
	if (pass == 310597){
		while (choice != 0) {
            system("cls");
			mChoice = 0;
			printHeader();
			printf("MENU\n");
			printf("1. Tambah peserta\n");
			printf("2. Tambah lomba\n");
			printf("3. Hapus peserta\n");
			printf("4. Hapus daerah\n");
			printf("\n");
			printf("5. Lihat data peserta\n");
			printf("6. Lihat daftar lomba\n");
			printf("7. Lihat data kategori\n");
			printf("8. Lihat daftar daerah\n");
			printf("\n");
			printf("9. Logout\n");
			printf("0. Exit\n");
			printf("\n");
			printf("Inputkan pilihan Anda: ");
			scanf("%d", &choice);
			switch(choice){
				case 1: tambahPeserta();
						break;
				case 2: tambahLomba();
						break;
				case 3: hapusPeserta();
						break;
                case 4: hapusDaerah();
						break;
				case 5: lihatPeserta();
						break;
				case 6: lihatLomba();
						break;
				case 7: lihatKategori();
						break;
				case 8: lihatDaerah();
						break;
				case 9: logout();
						break;
				case 0: break;
				default: printf("Input yang Anda masukkan salah.");
			}
		}
	}
}

int main() {
    char a[]={"\n\n\n\n\n\n\t\t\t    *** Kelas IK-38-02 ***\n\n\t\t\t Dwi Wahyu Akbar Sadewo \n\n\t\t\t\t Radika Rafif Gibran\n\n\t\t\t Riyan Nursyalim Latief_"};
    int i,k,l;
    double j;
    for(i=0;a[i]!='_';i++){
        printf("%c",a[i]);
        for(j=0;j<=9990000;j++){
        }
    }
    puts("\n\n\t\t---------------------------------------------\n\n\n");
    printf("\t\t       ");
    system("pause");
    for (k=1;k<=100;k++){
        printf("\n\n\n\n\n\n\n\n\n\n\n                            Program PON 2016  ");
        printf("%i %%",k);
        system("cls");
    }
    system("cls");
	choice = 10;
	mChoice = 10;
	initializeList();
	while(mChoice != 0){
        system("cls");
		printf("===============================\n");
		printf("||         PON 2016          ||\n");
		printf("===============================\n");
		printf("||        MENU UTAMA         ||\n");
		printf("===============================\n");
		printf("|| 1. Daftar sebagai Peserta ||\n");
        printf("||                           ||\n");
		if (isPesertaEmpty(P) == 0){
        printf("|| 2. Lihat Data Anda        ||\n");
		}
        printf("||                           ||\n");
		printf("|| 3. Login Panitia          ||\n");
        printf("||                           ||\n");
		printf("|| 4. Lihat Seluruh Peserta  ||\n");
        printf("||                           ||\n");
		printf("|| 0. Exit                   ||\n");
		printf("===============================\n");
		printf("\n");
		printf("Input pilihan: ");
		scanf("%d", &mChoice);
		switch(mChoice){
			case 1: tambahPeserta();
					break;
			case 2: if (isPesertaEmpty(P) == 0)
						lihatPesertaIndiv();
					break;
			case 3: login();
					break;
			case 4: lihatSeluruhPeserta();
					break;
			case 0: break;
			default: printf("Input yang Anda masukkan salah");
					getch();
					break;
		}
	}
	return 0;
}
