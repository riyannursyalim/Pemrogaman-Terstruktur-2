#include <stdio.h>
#include <stdlib.h>

#ifndef PON_
#define PON_

#define nil NULL
#define kategori(P) (P)->kategori
#define next(P) (P)->next
#define firstLomba(P) (P)->firstLomba
#define lomba(P) (P)->lomba
#define first(P) ((P).first)
#define daerah(P) (P)->daerah
#define peserta(P) (P)->peserta

typedef char string[60];

/* Definisi List Lomba */
typedef struct tElmtKategori *adrsKategori;
typedef struct tElmtLomba *adrsLomba;

typedef struct tElmtKategori {
	string kategori;
	adrsKategori next;
	adrsLomba firstLomba;
} ElmtKategori;

typedef struct tElmtLomba {
	adrsLomba next;
	string lomba;
} ElmtLomba;

typedef struct {
	adrsKategori first;
} ListKategori;

/* Definisi List Daerah */
typedef struct tElmtDaerah *adrsDaerah;
typedef struct tElmtDaerah {
	string daerah;
	adrsDaerah next;
} ElmtDaerah;
typedef struct {
	adrsDaerah first;
} ListDaerah;

/* Definisi List Peserta */
typedef struct tElmtPeserta *adrsPeserta;
typedef struct tElmtPeserta {
	adrsPeserta next;
	adrsDaerah daerah; // Daerah peserta tersebut
	adrsLomba lomba; // Lomba yang diikuti peserta tersebut
	string peserta;
} ElmtPeserta;

typedef struct {
	adrsPeserta first;
} ListPeserta;

/* LIST KATEGORI */
/* Melakukan alokasi untuk elemen kategori baru */
adrsKategori alokasiKategori(string X);

/* Melakukan dealokasi terhadap address dari suatu ElmtKategori */
void dealokasiKategori(adrsKategori P);

/* Melakukan alokasi untuk elemen lomba baru */
adrsLomba alokasiLomba(string X);

/* Melakukan dealokasi terhadap address dari suatu ElmtLomba */
void dealokasiLomba(adrsLomba P);

/* Inisialisasi pembuatan list kategori */
void createListKategori(ListKategori *K);

/* Menambahakan elemen kategori yang baru ke akhir dari list */
void addKategori(ListKategori *K, string X);

/* Menambahkan elemen lomba yang baru ke akhir dari list lomba */
void addLomba(ListKategori *K, string kategori, string lomba);

/* Mengambil address dari suatu kategori */
adrsKategori getAddressKategori(ListKategori K, string kategori);

/* Mengambil address dari suatu lomba */
adrsLomba getAddressLomba(ListKategori K, string kategori, string lomba);

/* Mengambil jumlah lomba yang ada */
int getSumLomba(ListKategori K);

/* Mengambil string kategori dari suatu lomba */
void getKategoriOfLomba(ListKategori K, string lomba, string *out);

/* Mengambil string lomba dari addressnya */
void getStringLomba(ListKategori K, adrsLomba Q, string *out);

/* Memeriksa jika suatu kategori telah ada pada list apa belum
 * Mengembalikan nilai 1 jika ada, dan 0 jika belum ada
 */
int checkKategoriExistence(ListKategori K, string kategori);

/* Memeriksa jika suatu lomba telah ada pada list apa belum */
int checkLombaExistence(ListKategori K, string kategori, string lomba);

/* Mencetak seluruh kategori yang ada */
void printAllKategori(ListKategori K);

/* Mencetak seluruh lomba yang ada dalam kategori tertentu */
void printLombaInKategori(ListKategori K, string kategori, int isNumbered);

/* Mencetak seluruh lomba yang ada */
void printAllLomba(ListKategori K);

/* LIST DAERAH */
/* Melakukan alokasi untuk elemen daerah baru */
adrsDaerah alokasiDaerah(string X);

/* Melakukan dealokasi terhadap address dari suatu ElmtDaerah */
void dealokasiDaerah(adrsDaerah P);

/* Inisialisasi pembuatan list peserta */
void createListDaerah(ListDaerah *L);

/* Menambahkan elemen daerah yang baru ke akhir dari list */
void addDaerah(ListDaerah *L, string X);

/* Mengambil address dari suatu daerah */
adrsDaerah getAddressDaerah(ListDaerah L, string daerah);

/* Mengambil nama Daerah dari suatu address */
void getStringDaerah(ListDaerah L, adrsDaerah P, string *out);

/* Mengambil jumlah daerah yang ada */
int getSumDaerah(ListDaerah L);

/* Mencetak seluruh daerah yang ada */
void printAllDaerah(ListDaerah L);

/* Memeriksa jika suatu daerah telah ada pada list apa belum */
int checkDaerahExistence(ListDaerah L, string daerah);

/* LIST PESERTA */
/* Melakukan alokasi untuk elemen peserta yang baru */
adrsPeserta alokasiPeserta(string X, adrsLomba lomba, adrsDaerah daerah);

/* Melakukan dealokasi terhadap address dari suatu ElmtPeserta */
void dealokasiPeserta(adrsPeserta P);

/* Memeriksa jika list peserta kosong */
int isPesertaEmpty(ListPeserta L);

/* Menambahkan elemen peserta yang baru ke akhir dari list */
void addPeserta(ListPeserta *L, string X, adrsLomba lomba, adrsDaerah daerah);

/* Menghapus peserta yang telah selesai mengikuti lomba */
void deletePeserta(ListPeserta *L, string peserta, string *out);

/* Menghapus daerah peserta yang telah selesai mengikuti lomba */
void deleteDaerah(ListDaerah *N, string daerah, string *out);

/* Mengambil jumlah peserta yang ada */
int getSumPeserta(ListPeserta L);

/* Mengambil address dari peserta */
adrsPeserta getAddressPeserta(ListPeserta L, string peserta);

/* Memeriksa jika seorang peserta telah ada pada list apa belum
 * Mengembalikan nilai 1 jika ada, dan 0 jika belum ada
 */
int checkPesertaExistence(ListPeserta L, string peserta);

/* Mencetak seluruh peserta yang ada */
void printAllPeserta(ListPeserta L, ListDaerah N, ListKategori K, int isDetail);

/* Mencetak detil data seorang peserta berdasarkan namanya */
void printPesertaIndiv(ListKategori K, ListDaerah N, ListPeserta L, string peserta);

/* Mencetak peserta yang mengikuti lomba (adrsLomba) tertentu */
void printPesertaInLomba(ListKategori K, ListPeserta L, adrsLomba lomba);

/* Mencetak jumlah peserta yang mengikuti lomba (adrsLomba) tertentu */
int printSumPesertaInLomba(ListPeserta L, adrsLomba lomba);

/* Mencetak peserta yang berasal dari daerah (adrsDaerah) tertentu */
void printPesertaInDaerah(ListPeserta L, adrsDaerah daerah);

/* Mencetak jumlah peserta yang berasal dari daerah (adrsDaerah) tertentu */
int printSumPesertaInDaerah(ListPeserta L, adrsDaerah daerah);

#endif /* LIST_ */
