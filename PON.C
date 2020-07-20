/* PON.c */

#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "PON.H"

/********************************* LIST KATEGORI ********************************/
/* Melakukan alokasi untuk elemen kategori baru */
adrsKategori alokasiKategori(string X) {
	adrsKategori P;

	P = (adrsKategori)malloc(sizeof(ElmtKategori));
	if (P != nil) {
		strcpy(kategori(P), X);
		next(P) = nil;
		firstLomba(P) = nil;
	}
	return P;
}

/* Melakukan dealokasi terhadap address dari suatu ElmtKategori */
void dealokasiKategori(adrsKategori P) {
	free(P);
}

/* Melakukan alokasi untuk elemen lomba baru */
adrsLomba alokasiLomba(string X) {
	adrsLomba P;

	P = (adrsLomba) malloc(sizeof(ElmtLomba));
	if (P != nil) {
		strcpy(lomba(P), X);
		next(P) = nil;
	}
	return P;
}

/* Melakukan dealokasi terhadap address dari suatu ElmtLomba */
void dealokasiLomba(adrsLomba P) {
	free(P);
}

/* Inisialisasi pembuatan list kategori */
void createListKategori(ListKategori *K) {
	first(*K) = nil;
}

/* Menambahakan elemen kategori yang baru ke akhir dari list */
void addKategori(ListKategori *K, string X) {
	adrsKategori P, last;

	P = alokasiKategori(X);

	if (P != nil) {
		if (first(*K) == nil) {
			first(*K) = P;
		} else {
			last = first(*K);
			while (next(last) != nil) {
				last = next(last);
			}
			next(last) = P;
		}
	} else
		printf("Error: Memori penuh.");
}

/* Menambahkan elemen lomba yang baru ke akhir dari list lomba */
void addLomba(ListKategori *K, string kategori, string lomba) {
	adrsLomba P, last;
	adrsKategori C;

	P = alokasiLomba(lomba);
	if (P != nil) {
		if (first(*K) == nil) {
			printf("Error: List Kategori kosong");
		} else {
			C = first(*K);
			while (C != nil && strcmpi(kategori(C), kategori) != 0) {
				C = next(C);
			}
			if (C != nil && strcmpi(kategori(C), kategori) == 0) {
				if (firstLomba(C) == nil) {
					firstLomba(C) = P;
				} else {
					last = firstLomba(C);
					while (next(last) != nil) {
						last = next(last);
					}
					next(last) = P;
				}
			} else
				printf("Kategori yang Anda inputkan tidak ada.");
		}
	}
}

/* Mengambil address dari suatu kategori */
adrsKategori getAddressKategori(ListKategori K, string kategori){
	adrsKategori P;
	int found;

	P = first(K);
	while (P != nil && found != 1){
		if (strcmpi(kategori(P), kategori) == 0){
			found = 1;
		} else
			P = next(P);
	}

	if (found == 1)
		return P;
	else
		return nil;
}

/* Mengambil address dari suatu lomba
 * Mengembalikan nilai nil jika lomba yang dicari tidak ditemukan
 */
adrsLomba getAddressLomba(ListKategori K, string kategori, string lomba) {
	adrsKategori C;
	adrsLomba L;
	int foundKategori, foundLomba;
	foundKategori = 0;
	foundLomba = 0;

	C = first(K);
	while (C != nil && foundKategori != 1) {
		if (strcmpi(kategori(C), kategori) == 0){
			foundKategori = 1;
			L = firstLomba(C);
		} else
			C = next(C);
	}

	if (foundKategori == 1) {
		while (L != nil && foundLomba != 1){
			if (strcmpi(lomba(L), lomba) == 0){
				foundLomba = 1;
			} else
				L = next(L);
		}
	}
	if (foundLomba == 1){
		return L;
	} else
		return nil;
}

/* Mengambil jumlah lomba yang ada */
int getSumLomba(ListKategori K) {
	adrsKategori C;
	adrsLomba L;
	int i = 0;

	if (first(K) != nil) {
		C = first(K);
		while (C != nil) {
			if (firstLomba(C) != nil) {
				L = firstLomba(C);
				while (L != nil) {
					i++;
					L = next(L);
				}
			}
			C = next(C);
		}
	}
	return i;
}

/* Mengambil string kategori dari suatu lomba */
void getKategoriOfLomba(ListKategori K, string lomba, string *out){ // BUG
	adrsKategori C;
	adrsLomba L;
	int found = 0;

	if (first(K) == nil) {
		printf("List kategori masih kosong");
	} else {
		C = first(K);
		while (C != nil && found != 1) {
			if (firstLomba(C) != nil) {
				L = firstLomba(C);
				while (L != nil && found != 1) {
					if (strcmpi(lomba(L), lomba) == 0){
						strcpy(*out, kategori(C));
						found = 1;
						printf("Kategori ditemukan");
					} else
						L = next(L);
				}
			}
			C = next(C);
		}
	}
}

/* Mengambil string lomba dari addressnya */
void getStringLomba(ListKategori K, adrsLomba Q, string *out){
	adrsKategori C;
	adrsLomba L;
	int found;
	found = 0;

	C = first(K);
	while (C != nil && found != 1){
		if (firstLomba(C) != nil){
			L = firstLomba(C);
			while (L != nil && found != 1){
				if (L == Q){
					found = 1;
					strcpy(*out, lomba(L));
				} else
					L = next(L);
			}
		}
		C = next(C);
	}
}

/* Memeriksa jika suatu kategori telah ada pada list apa belum
 * Mengembalikan nilai 1 jika ada, dan 0 jika belum ada
 */
int checkKategoriExistence(ListKategori K, string kategori){
	adrsKategori P;
	P = getAddressKategori(K, kategori);
	if (P == nil){
		return 0;
	} else
		return 1;
}

/* Memeriksa jika suatu lomba telah ada pada list apa belum */
int checkLombaExistence(ListKategori K, string kategori, string lomba){
	adrsLomba N;
	N = getAddressLomba(K, kategori, lomba);
	if (N == nil){
		return 0;
	} else
		return 1;
}

/* Mencetak seluruh kategori yang ada */
void printAllKategori(ListKategori K) {
	adrsKategori C;
	int i = 1;

	if (first(K) == nil) {
		printf("List kategori masih kosong");
	} else {
		C = first(K);
		while (C != nil) {
			printf("%d. %s \n", i, kategori(C));
			C = next(C);
			i++;
		}
	}
}

/* Mencetak seluruh lomba yang ada dalam kategori tertentu */
void printLombaInKategori(ListKategori K, string kategori, int isNumbered) {
	adrsKategori C;
	adrsLomba L;
	int i = 1;

	if (first(K) == nil) {
		printf("List kategori masih kosong");
	} else {
		C = first(K);
		while (C != nil && strcmpi(kategori(C), kategori) != 0) {
			C = next(C);
		}
		if (C != nil && strcmpi(kategori(C), kategori) == 0) {
			if (firstLomba(C) == nil) {
				printf("List lomba dari kategori %s masih kosong", kategori);
			} else {
				L = firstLomba(C);
				while (L != nil) {
					if(isNumbered == 1){
						printf("%d. %s \n", i, lomba(L));
					} else if (isNumbered == 0)
						printf("- %s \n", lomba(L));
					L = next(L);
					i++;
				}
			}
		}
	}
}

/* Mencetak seluruh lomba yang ada */
void printAllLomba(ListKategori K) {
	adrsKategori C;
	adrsLomba L;
	int i = 1;

	if (first(K) == nil) {
		printf("List kategori masih kosong");
	} else {
		C = first(K);
		while (C != nil) {
			if (firstLomba(C) != nil) {
				L = firstLomba(C);
				while (L != nil) {
					printf("%d. %s \n", i, lomba(L));
					i++;
					L = next(L);

					if (i%10 == 0){
						getch();
					}
				}
			}
			C = next(C);
		}
	}
}

/*********************************** LIST DAERAH ********************************/
/* Melakukan alokasi untuk elemen daerah baru */
adrsDaerah alokasiDaerah(string X) {
	adrsDaerah P;

	P = (adrsDaerah) malloc(sizeof(ElmtDaerah));
	if (P != NULL) {
		strcpy(daerah(P), X);
		next(P) = nil;
	}
	return P;
}

/* Melakukan dealokasi terhadap address dari suatu ElmtDaerah */
void dealokasiDaerah(adrsDaerah P) {
	free(P);
}

/* Inisialisasi pembuatan list peserta */
void createListDaerah(ListDaerah *L) {
	first(*L) = nil;
}

/* Menambahkan elemen daerah yang baru ke akhir dari list */
void addDaerah(ListDaerah *L, string X) {
	adrsDaerah P, last;

	P = alokasiDaerah(X);
	if (P != nil) {
		if (first(*L) == nil) {
			first(*L) = P;
		} else {
			last = first(*L);
			while (next(last) != nil) {
				last = next(last);
			}
			next(last) = P;
		}
	} else
		printf("Error: Memori penuh.");
}

/* Mengambil address dari suatu daerah
 * Mengembalikan nilai nil jika daerah yang dicari tidak ditemukan
 */
adrsDaerah getAddressDaerah(ListDaerah L, string daerah) {
	adrsDaerah P;
	int found;

	P = first(L);
	while (P != nil && found != 1){
		if (strcmpi(daerah(P), daerah) == 0){
			found = 1;
		} else
			P = next(P);
	}

	if (found == 1)
		return P;
	else
		return nil;
}

/* Mengambil nama Daerah dari suatu address */
void getStringDaerah(ListDaerah L, adrsDaerah P, string *out){
	int found;
	adrsDaerah N;

	found = 0;
	N = first(L);
	while (N != nil && found != 1){
		if (N == P){
			found = 1;
			strcpy(*out, daerah(N));
		}
		else
			N = next(N);
	}
}

/* Mengambil jumlah daerah yang ada */
int getSumDaerah(ListDaerah L) {
	adrsDaerah N;
	int i = 0;

	if (first(L) != nil) {
		N = first(L);
		while (N != nil) {
			i++;
			N = next(N);
		}
	}
	return i;
}

/* Mencetak seluruh daerah yang ada */
void printAllDaerah(ListDaerah L) {
	adrsDaerah N;
	int i = 1;

	if (first(L) == nil) {
		printf("List daerah masih kosong.");
	} else {
		N = first(L);
		while (N != nil) {
			printf("%d. %s \n", i, daerah(N));
			N = next(N);
			i++;
		}
	}
}

/* Memeriksa jika suatu daerah telah ada pada list apa belum
 * Mengembalikan nilai 1 jika ada, dan 0 jika belum ada
 */
int checkDaerahExistence(ListDaerah L, string daerah){
	adrsDaerah N;
	N = getAddressDaerah(L, daerah);
	if (N == nil){
		return 0;
	} else
		return 1;
}

/********************************** LIST PESERTA *********************************/
/* Melakukan alokasi untuk elemen peserta yang baru */
adrsPeserta alokasiPeserta(string X, adrsLomba lomba, adrsDaerah daerah) {
	adrsPeserta P;

	P = (adrsPeserta) malloc(sizeof(ElmtPeserta));
	if (P != nil) {
		strcpy(peserta(P), X);
		next(P) = nil;
		daerah(P) = daerah;
		lomba(P) = lomba;
	}
	return P;
}

/* Melakukan dealokasi terhadap address dari suatu ElmtPeserta */
void dealokasiPeserta(adrsPeserta P) {
	free(P);
}

/* Memeriksa jika list peserta kosong */
int isPesertaEmpty(ListPeserta L){
	if (first(L) == nil)
		return 1;
	else
		return 0;
}

/* Inisialisasi pembuatan list peserta */
void createListPeserta(ListPeserta *L) {
	first(*L) = nil;
}

/* Menambahkan elemen peserta yang baru ke akhir dari list */
void addPeserta(ListPeserta *L, string X, adrsLomba lomba, adrsDaerah daerah) {
	adrsPeserta P, last;

	P = alokasiPeserta(X, lomba, daerah);
	if (P != nil) {
		if (first(*L) == nil) {
			first(*L) = P;
		} else {
			last = first(*L);
			while (next(last) != nil) {
				last = next(last);
			}
			next(last) = P;
		}
	} else
		printf("Error: Memori penuh.");
}

/* Menghapus peserta yang telah selesai mengikuti lomba */
void deletePeserta(ListPeserta *L, string peserta, string *out) {
	adrsPeserta P, X;

	if (first(*L) == nil) {
		printf("List peserta masih kosong.\n");
	} else if (strcmpi(peserta(first(*L)), peserta) == 0){
		X = first(*L);
		strcpy( *out, peserta(first(*L)));
		first(*L) = next(first(*L));
		dealokasiPeserta(X);
	} else {
		P = first(*L);
		while (P != nil && strcmpi(peserta(next(P)), peserta) != 0) {
			P = next(P);
		}
		if (P != nil) {
			X = next(P);
			strcpy(*out, peserta(next(P)));
			next(P) = next(next(P));
			dealokasiPeserta(X);
		}
	}
}

/* Menghapus daerah yang telah selesai mengikuti lomba */
void deleteDaerah(ListDaerah *N, string daerah, string *out) {
	adrsDaerah P, X;

	if (first(*N) == nil) {
		printf("List daerah masih kosong.\n");
	} else if (strcmpi(daerah(first(*N)), daerah) == 0){
		X = first(*N);
		strcpy( *out, daerah(first(*N)));
		first(*N) = next(first(*N));
		dealokasiDaerah(X);
	} else {
		P = first(*N);
		while (P != nil && strcmpi(daerah(next(P)), daerah) != 0) {
			P = next(P);
		}
		if (P != nil) {
			X = next(P);
			strcpy(*out, daerah(next(P)));
			next(P) = next(next(P));
			dealokasiDaerah(X);
		}
	}
}

/* Mengambil jumlah peserta yang ada */
int getSumPeserta(ListPeserta L) {
	adrsPeserta P;
	int i = 0;

	if (first(L) != nil) {
		P = first(L);
		while (P != nil) {
			i++;
			P = next(P);
		}
	}
	return i;
}

/* Mengambil address dari peserta */
adrsPeserta getAddressPeserta(ListPeserta L, string peserta){
	adrsPeserta P;
	int found;

	P = first(L);
	while (P != nil && found != 1){
		if (strcmpi(peserta(P), peserta) == 0){
			found = 1;
		} else
			P = next(P);
	}

	if (found == 1)
		return P;
	else
		return nil;
}

/* Memeriksa jika seorang peserta telah ada pada list apa belum
 * Mengembalikan nilai 1 jika ada, dan 0 jika belum ada
 */
int checkPesertaExistence(ListPeserta L, string peserta){
	adrsPeserta P;
	P = getAddressPeserta(L, peserta);
	if (P == nil){
		return 0;
	} else
		return 1;
}

/* Mencetak seluruh peserta yang ada */
void printAllPeserta(ListPeserta L, ListDaerah N, ListKategori K, int isDetail) {
	adrsPeserta P;
	string daerah, lomba;
	int i = 1;

	if (first(L) == nil) {
		printf("List peserta masih kosong.\n");
	} else {
		P = first(L);
		while (P != nil) {
			if (isDetail == 1){
				getStringDaerah(N, daerah(P), &daerah);
				getStringLomba( K, lomba(P),  &lomba); // NEED TO BE FIXED
				printf("(%d)\n",i);
				printf("Nama Peserta	: %s \n", peserta(P));
				printf("Lomba	        : %s \n", lomba);
				printf("Daerah          : %s \n", daerah);
				printf("\n");
			} else if (isDetail == 0){
				printf("%d. %s\n", i, peserta(P));
			}
			P = next(P);
			i++;
		}
	}
}

/* Mencetak detil data seorang peserta berdasarkan namanya */
void printPesertaIndiv(ListKategori K, ListDaerah N, ListPeserta L, string peserta){
	adrsPeserta P;
	string lomba, daerah;

	P = getAddressPeserta( L, peserta);
	getStringLomba( K, lomba(P),  &lomba);
	getStringDaerah(N, daerah(P), &daerah);
	printf("Nama Peserta 	  : %s\n", peserta(P));
	printf("Lomba             : %s\n", lomba);
	printf("Daerah            : %s\n", daerah);
}

/* Mencetak peserta yang mengikuti lomba (adrsLomba) tertentu */
void printPesertaInLomba(ListKategori K, ListPeserta L, adrsLomba lomba) {
	adrsPeserta P;
	int i = 1;

	if (first(L) == nil) {
		printf("List peserta masih kosong.");
	} else {
		P = first(L);
		while (P != nil) {
			if (lomba(P) == lomba) {
				printf("%d. %s \n", i, peserta(P));
				i++;
			}
			P = next(P);
		}
	}
}

/* Mencetak jumlah peserta yang mengikuti lomba (adrsLomba) tertentu */
int printSumPesertaInLomba(ListPeserta L, adrsLomba lomba) {
	adrsPeserta P;
	int i = 0;

	if (first(L) != nil) {
		P = first(L);
		while (P != nil) {
			if (lomba(P) == lomba) {
				i++;
			}
			P = next(P);
		}
	}
	return i;
}

/* Mencetak peserta yang berasal dari daerah (adrsDaerah) tertentu */
void printPesertaInDaerah(ListPeserta L, adrsDaerah daerah) {
	adrsPeserta P;
	int i = 1;

	if (first(L) == nil) {
		printf("List peserta masih kosong.");
	} else {
		P = first(L);
		while (P != nil) {
			if (daerah(P) == daerah) {
				printf("%d. %s \n", i, peserta(P));
				i++;
			}
			P = next(P);
		}
	}
}

/* Mencetak jumlah peserta yang berasal dari daerah (adrsDaerah) tertentu */
int printSumPesertaInDaerah(ListPeserta L, adrsDaerah daerah) {
	adrsPeserta P;
	int i = 0;

	if (first(L) != nil) {
		P = first(L);
		while (P != nil) {
			if (daerah(P) == daerah) {
				i++;
			}
			P = next(P);
		}
	}
	return i;
}
