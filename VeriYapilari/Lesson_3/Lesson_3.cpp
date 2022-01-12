#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

void bastir(node* r) {
	while (r != NULL)
	{
		printf("%d ", r->x);
		r = r->next;
	}
}
node* siraliEkle(node* r, int x) {
	if (r == NULL) // kutu oluþtur // baþ
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	if (r->x > x)  // yeni kutu ile oluþturduðun kutuyu karþýlaþtýr. // sol
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = r;
		temp->x = x;
		r = temp;
		return r;
	}

	node* iter = r;

	while (iter->next != NULL && iter->next->x < x) { // sað ve son
		iter = iter->next;
	}

	node* temp = (node*)malloc(sizeof(node));
	temp->x = x;
	temp->next = iter->next;
	iter->next = temp;
	return r;
}

int main() {

	node* root = NULL;
	root = siraliEkle(root, 400);
	root = siraliEkle(root, 40);
	root = siraliEkle(root, 50);
	root = siraliEkle(root, 450);
	root = siraliEkle(root, 200);

	bastir(root);
}








/*
*
* 
* 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int x;
	node* next;
};

void bastir(node* r) {
	while (r != NULL)
	{
		printf("%d ", r->x);
		r = r->next;
	}
}

void ekle(node* r, int x) {
	while (r->next != NULL) {
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

// ana fonks çaðýrýrken rootun point ettiði deðeri geçiriyoruz. Böylece hem r hem de root ayný yeri point ediyor ancak r baþka yerleri gösterdiði zaman root sabit kalýyor deðiþmiyor.
// dolayýsýyla rootu deðiþtirdiysem bunu ana fonk da döndürüp ana fonks daki linklistin deðerini deðiþtirmemiz lazým bu nedenle void þeklinde tanýmlamýyoruz. ve ana fonks root = siraliEkle() yapammýz lazým.
node* siraliEkle(node* r, int x) { // ana fonks root unda deðiþmesi için node* tipinde tanýmlýyoruz.
	if (r == NULL)   // root yoksa // linklist boþsa
	{
		r = (node*)malloc(sizeof(node));  // kutu yap
		r->next = NULL;
		r->x = x;
		return r;  // Göstericinin deðeri (gösterdiði adres deðeri) fonksiyon içerisinde deðiþtiði için artýk iki gösterici ayný yeri göstermemekte ve bu bað kýrýlmaktadýr, o yüzden geri deðer döndürmek gerekir.
	}
	if (r->x > x)  // linklist boþ deðilse, eklenecek eleman ilk elemandan küçükse // root un göstediði x deðeri > yeni eklenecek kutunun x deðerinden  --> yeni kutu sola eklenir
	{
		// root deðiþiyor. Yeni kutu  artýk root oluyor.
		node* temp = (node*)malloc(sizeof(node)); 
		temp->x = x;
		temp->next = r; // yeni kutunun next rootun x ini
		r = temp;   //  root da tempi göstersin
		return r; // yeni rootu döndürüyoruz.
	}

	//	LÝNKLÝST BOÞ DEÐÝLSE VE BAÞA BÝR ELEMAN EKLEMEYECEKSEK

	node* iter = r; // r deðerini saklamak için yeni bir node deðiþken üretim onun üzerinde iþlem yapacaðýz.

	// iki deðer olsun. örneði 400 ve 450 i elimdeki deðer 120 olsun. dolayýsý ile yer ararken 400 de durmasý lazým ki ikisinin arasýna koyabilelim.

	while (iter->next != NULL && iter->next->x < x)   // listenin sonuna gelmediysem  &&  listenin içinde þuanda baktýðým deðerin x deðeri yani baktýðýmýn gösterdiði kutunun x deðeri ekleyeceðim deðerden küçükse
	{ // yani elindeki kutu 300 olsun gösterdiði kutu 400 olsun eklemek istediðim 420 olsun
		iter = iter->next;   // o zaman bir sonrakine gitmemiz lazým.
	} // iter olarak next next next þeklinde devam ettiysem linklist de bir kaç durum var. 1) linklistin sonuna geldim durdum demek, 2) benden daha büyük bir sayý buldum durdum demek

	// ULAÞTIÐIN YERDE DE YENÝ KUTUYU EKLE	
	// araya ekleme kodu
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next; // yeni kutunun nextine 400 ün (iter) nextinin gösterdiði yeri baðla
	iter->next = temp;  // iterin (400) nextine yeni kutuyu baðladýk
	temp->x = x;
	return r;
}

int main() {

	node* root;
	root = NULL;
	//root = (node*)malloc(sizeof(node));
	//root->next = NULL;

	// sirakiEkle fonk ekledikten sonra root deðiþebilir. Deðiþmiþ rootu main fonks alacak.
	root = siraliEkle(root, 400);
	root = siraliEkle(root, 40);
	root = siraliEkle(root, 4);
	root = siraliEkle(root, 450);
	root = siraliEkle(root, 50);
	
	//for (int i = 0; i < 5; i++)
	//{
	//	ekle(root, i * 10);
	//}
	//bastir(root);

	//// ÇIKTI : 500   0    10	20	  30
	//// 20 ile 30 arasýna yeni bir eleman ekleyelim.

	//node* iter;  // iter tanýmlayýp
	//iter = root; // root ile ayný yerden baþlamasýný istiyoruz.

	//// iterater ýn 3 kere hareket etmesini istiyoruz. 20 deðerine ulaþmak için

	//for (int i = 0; i < 3; i++)
	//{
	//	iter = iter->next;
	//}

	//// geçici bir düðüm oluþturuyoruz. Hafýzada kaybetmemek için temp deðiþkenine atadýk.
	//node* temp = (node*)malloc(sizeof(node));

	//// SIRA ÖNEMLÝ !!!  önce tempe eþitlersem iterin nextini kaybedeceðimiz için eþitleyemeyiz. Bu nedenle önce nextler sonra iter
	//temp->next = iter->next; // oluþturduðumuz geçici kutunun nexti 20 deðerinin olduðu kutunun nextinin gösterdiði deðeri-kutuyu gösteriyor.
	//iter->next = temp; // iterin nextini tempe eþitliyoruz.
	//temp->x = 100; // 20 ile 30 arasýna eklemek istediðimiz deðeri temp kutusuna atýyoruz.
	
	bastir(root);

}
*
* 
* 
*/