// Hashing elimizdeki veriyi kullanarak o veriden elden geldiði kadar benzersiz bir tamsayý elde etme iþlemidir.
// Elde edilen tamsayý dizi þeklinde tutulan verilerin indisi gibi kullanýlarak verilere tek seferde eriþmemizi saðlar.
// Özetle, bir anahtarýn tabloda bulunduðu indeks sýrasýný verir.
// Hash fonk. integer sayýlarla iþlem yaparlar. Örneðin 3455-4534 anahtarýndaki - çýkartýlýr ve 34554534 þeklinde kullanýlýr.
// Eðer anahtarlar karakterlerden oluþuyorsa ASCII kodlardan faydalanýlýr.
// Hash Fonksiyonlarý: Selecting Digits, Folding, Division(En çok tercih edilen), Mid-Square, Extraction, Tadix Transformation

// Selecting Digits: Anahtar üzerinde belirlenmiþ bazý haneleri seçip birleþtirerek tablodaki pozisyon bulunur.
// Folding: Anahtar birkaç parçaya bölünür ve bu parçalar kendi aralarýnda toplanarak tablodaki pozisyon bulunur.
// Division: Anahtar deðeri tablo boyutuna göre mod ile bölünür. 2 ve 10 un katlarý þeklindeki tablo boyutlarýnda çakýþma çok olur. Tablo boyutunu asal seçmek bu soruna çözüm getirecektir.
// Mid-Square: Anahtar deðerinin karesi alýnýr ve sonucun orta kýsmý seçilerek Tadix Transformation
// Extraction: Anahter deðerinin sadece bazý kýsýmlarý seçilerek tablodaki pozisyon deðeri bulunur.
// Tadix Transformation: Anahtar deðeri baþka bir sayý tabanýna dönüþtürülür. Dönüþtürülen deðerin tablo boyutuna göre modu alýnýr ve tablodaki pozisyon deðeri bulunur.

// Ayný pozisyona birden fazla deðer gelirse çakýþma meydana gelir.
// Çakýþma Fonksiyonlarý: Linear Probing, Double Hashing, Quadratic Probing, Chaining


#include <stdio.h>

// deðerleri tutuyoruz key leri tutmuyoruz. Key leri de tutmamýz gerekiyor çünkü aranan deðer o anahtarda mý onu kontrol edebilmemiz lazým

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
	// dizinin o alaný boþ mu dolu mu? Boþsa gelen deðeri oraya ekle
	if (a[h(d.key)].key == -1) 
	{
		// anahtarý hash leyip çýkan deðerin dizideki konumuna value deðerini atýyoruz.
		a[h(d.key)] = d;  
		return 1;
	}
	// eðer doluysa orasý
	int counter = 0;
	int indis = h(d.key);
	// hem boþ alaný bulana kadar aramaya devam edecek hemde mevcut data dan farklý bir yer var mý diye arama yapacak
	// örneðin benim anahtarým 28 ve tabloda 28 varsa bulduysa üstüne yaz onun için boþ bir yer aramaya devam etme
	while (a[indis].key != -1 && a[indis].key != d.key) {

		indis++;

		if (indis >= 27) {		// dizi dolduysa ancak baþta boþ deðer varsa sona geldim mi kontrolü
			if (counter >= 1)
			{
				printf("Hash Table dolu");
				return -1;
			}
			indis = indis % 27; // ve baþa dön ancak bunu da 1 kez yapmasý lazým yoksa süreklilik kazanýr.
			counter++;
		}
	}
	a[indis].value = d.value; // boþ bulduðumuz yere deðeri ekliyoruz.
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

	// Dizideki boþ deðerleri tanýmlamak için dizinin tamamýný -1 deðeri ile dolduruyoruz.
	// Böylece dizinin içinde herhangi bir elemana eriþtiðimde orda sayý var mý yok mu anlayacaðýz.
	for (int i = 0; i < 27; i++)
	{
		a[i].key = -1;
	}

	data d;
	d.key = 10;
	d.value = 42342;
	put(d); // anahtar, deðer: CV,resim,adress, telefon numarasý

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

	for (int i = 0; i < 30; i++)  // Tablo dolunca olacaklarý gözlemleyelim
	{
		d.key = i;
		d.value = i*23;
		put(d);
	}
	printf("%d ", get(10));
	printf("%d ", get(1));  // 1 % 27 == 1
	printf("%d ", get(28)); // 28 % 27 == 1  Çakýþma meydana geliyor. Dolu olduðunu görünce bir yana kayýp orayý kontrol edecek boþsa ekleyecek.
	printf("%d ", get(28)); // iki tane ayný anahtara sahip deðer varsa onu koymayacaðýz. Bu iþlem sýrasýnda üstüne yazma yapýlabilir. 
	// yani yukarýdaki 28 anahtarýnýn deðeri olan 99999 deðeri yerine yeni eklenecek olan 28 anahtarýnýn 23423 deðeri gelir.
	printf("%d ", get(100));
	printf("%d ", get(2));  // Hash tablosunda olmayan bir deðeri çaðýrmaya çalýþalým

	display();
}