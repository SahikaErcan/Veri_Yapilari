// Hashing elimizdeki veriyi kullanarak o veriden elden geldi�i kadar benzersiz bir tamsay� elde etme i�lemidir.
// Elde edilen tamsay� dizi �eklinde tutulan verilerin indisi gibi kullan�larak verilere tek seferde eri�memizi sa�lar.
// �zetle, bir anahtar�n tabloda bulundu�u indeks s�ras�n� verir.
// Hash fonk. integer say�larla i�lem yaparlar. �rne�in 3455-4534 anahtar�ndaki - ��kart�l�r ve 34554534 �eklinde kullan�l�r.
// E�er anahtarlar karakterlerden olu�uyorsa ASCII kodlardan faydalan�l�r.
// Hash Fonksiyonlar�: Selecting Digits, Folding, Division(En �ok tercih edilen), Mid-Square, Extraction, Tadix Transformation

// Selecting Digits: Anahtar �zerinde belirlenmi� baz� haneleri se�ip birle�tirerek tablodaki pozisyon bulunur.
// Folding: Anahtar birka� par�aya b�l�n�r ve bu par�alar kendi aralar�nda toplanarak tablodaki pozisyon bulunur.
// Division: Anahtar de�eri tablo boyutuna g�re mod ile b�l�n�r. 2 ve 10 un katlar� �eklindeki tablo boyutlar�nda �ak��ma �ok olur. Tablo boyutunu asal se�mek bu soruna ��z�m getirecektir.
// Mid-Square: Anahtar de�erinin karesi al�n�r ve sonucun orta k�sm� se�ilerek Tadix Transformation
// Extraction: Anahter de�erinin sadece baz� k�s�mlar� se�ilerek tablodaki pozisyon de�eri bulunur.
// Tadix Transformation: Anahtar de�eri ba�ka bir say� taban�na d�n��t�r�l�r. D�n��t�r�len de�erin tablo boyutuna g�re modu al�n�r ve tablodaki pozisyon de�eri bulunur.

// Ayn� pozisyona birden fazla de�er gelirse �ak��ma meydana gelir.
// �ak��ma Fonksiyonlar�: Linear Probing, Double Hashing, Quadratic Probing, Chaining


#include <stdio.h>

// de�erleri tutuyoruz key leri tutmuyoruz. Key leri de tutmam�z gerekiyor ��nk� aranan de�er o anahtarda m� onu kontrol edebilmemiz laz�m

typedef struct data
{
	int key, value;
};

data a[27];
// HASH
int h(int key) {
	return key % 27;
}

// hash tablosuna veri ekleyen fonksiyon
int put(data d) {
	// dizinin o alan� bo� mu dolu mu? Bo�sa gelen de�eri oraya ekle
	if (a[h(d.key)].key == -1) 
	{
		// anahtar� hash leyip ��kan de�erin dizideki konumuna value de�erini at�yoruz.
		a[h(d.key)] = d;  
		return 1;
	}
	// e�er doluysa oras�
	int counter = 0;
	int indis = h(d.key);
	// hem bo� alan� bulana kadar aramaya devam edecek hemde mevcut data dan farkl� bir yer var m� diye arama yapacak
	// �rne�in benim anahtar�m 28 ve tabloda 28 varsa bulduysa �st�ne yaz onun i�in bo� bir yer aramaya devam etme
	while (a[indis].key != -1 && a[indis].key != d.key) {

		indis++;

		if (indis >= 27) {		// dizi dolduysa ancak ba�ta bo� de�er varsa sona geldim mi kontrol�
			if (counter >= 1)
			{
				printf("Hash Table dolu");
				return -1;
			}
			indis = indis % 27; // ve ba�a d�n ancak bunu da 1 kez yapmas� laz�m yoksa s�reklilik kazan�r.
			counter++;
		}
	}
	a[indis].value = d.value; // bo� buldu�umuz yere de�eri ekliyoruz.
	a[indis].key = d.key;
	return 1;
}

int get(int key) {
	if (a[h(key)].key == key) 
	{ 
		return a[h(key)].value;
	}
	int counter = 0;
	int indis = h(key);
	while (a[indis].key != key && a[indis].key != key) {   
		indis++;

		if (indis >= 27) {		
			if (counter >= 1)
			{
				printf("Hash Table da kayit yok.");
				return -1;
			}
			indis = indis % 27; 
			counter++;
		}
	}
	return a[indis].value;
}

void display() {

	printf("\n\nDIZI:");

	for (int i = 0; i < 27; i++)
	{
		printf("\nKey: %d   Value: %d", a[i].key, a[i].value);
	}
	printf("\n");
}

int main() {

	// Dizideki bo� de�erleri tan�mlamak i�in dizinin tamam�n� -1 de�eri ile dolduruyoruz.
	// B�ylece dizinin i�inde herhangi bir elemana eri�ti�imde orda say� var m� yok mu anlayaca��z.
	for (int i = 0; i < 27; i++)
	{
		a[i].key = -1;
	}

	data d;
	d.key = 10;
	d.value = 42342;
	put(d); // anahtar, de�er: CV,resim,adress, telefon numaras�

	d.key = 1;
	d.value = 66666;
	put(d);

	d.key = 28;
	d.value = 99999;
	put(d);

	d.key = 28;
	d.value = 23423;
	put(d);

	d.key = 100;
	d.value = 77777;
	put(d);

	for (int i = 0; i < 30; i++)  // Tablo dolunca olacaklar� g�zlemleyelim
	{
		d.key = i;
		d.value = i*23;
		put(d);
	}
	printf("%d ", get(10));
	printf("%d ", get(1));  // 1 % 27 == 1
	printf("%d ", get(28)); // 28 % 27 == 1  �ak��ma meydana geliyor. Dolu oldu�unu g�r�nce bir yana kay�p oray� kontrol edecek bo�sa ekleyecek.
	printf("%d ", get(28)); // iki tane ayn� anahtara sahip de�er varsa onu koymayaca��z. Bu i�lem s�ras�nda �st�ne yazma yap�labilir. 
	// yani yukar�daki 28 anahtar�n�n de�eri olan 99999 de�eri yerine yeni eklenecek olan 28 anahtar�n�n 23423 de�eri gelir.
	printf("%d ", get(100));
	printf("%d ", get(2));  // Hash tablosunda olmayan bir de�eri �a��rmaya �al��al�m

	display();
}