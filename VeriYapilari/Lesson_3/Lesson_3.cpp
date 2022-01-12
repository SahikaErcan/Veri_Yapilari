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
	if (r == NULL) // kutu olu�tur // ba�
	{
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->x = x;
		return r;
	}
	if (r->x > x)  // yeni kutu ile olu�turdu�un kutuyu kar��la�t�r. // sol
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->next = r;
		temp->x = x;
		r = temp;
		return r;
	}

	node* iter = r;

	while (iter->next != NULL && iter->next->x < x) { // sa� ve son
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

// ana fonks �a��r�rken rootun point etti�i de�eri ge�iriyoruz. B�ylece hem r hem de root ayn� yeri point ediyor ancak r ba�ka yerleri g�sterdi�i zaman root sabit kal�yor de�i�miyor.
// dolay�s�yla rootu de�i�tirdiysem bunu ana fonk da d�nd�r�p ana fonks daki linklistin de�erini de�i�tirmemiz laz�m bu nedenle void �eklinde tan�mlam�yoruz. ve ana fonks root = siraliEkle() yapamm�z laz�m.
node* siraliEkle(node* r, int x) { // ana fonks root unda de�i�mesi i�in node* tipinde tan�ml�yoruz.
	if (r == NULL)   // root yoksa // linklist bo�sa
	{
		r = (node*)malloc(sizeof(node));  // kutu yap
		r->next = NULL;
		r->x = x;
		return r;  // G�stericinin de�eri (g�sterdi�i adres de�eri) fonksiyon i�erisinde de�i�ti�i i�in art�k iki g�sterici ayn� yeri g�stermemekte ve bu ba� k�r�lmaktad�r, o y�zden geri de�er d�nd�rmek gerekir.
	}
	if (r->x > x)  // linklist bo� de�ilse, eklenecek eleman ilk elemandan k���kse // root un g�stedi�i x de�eri > yeni eklenecek kutunun x de�erinden  --> yeni kutu sola eklenir
	{
		// root de�i�iyor. Yeni kutu  art�k root oluyor.
		node* temp = (node*)malloc(sizeof(node)); 
		temp->x = x;
		temp->next = r; // yeni kutunun next rootun x ini
		r = temp;   //  root da tempi g�stersin
		return r; // yeni rootu d�nd�r�yoruz.
	}

	//	L�NKL�ST BO� DE��LSE VE BA�A B�R ELEMAN EKLEMEYECEKSEK

	node* iter = r; // r de�erini saklamak i�in yeni bir node de�i�ken �retim onun �zerinde i�lem yapaca��z.

	// iki de�er olsun. �rne�i 400 ve 450 i elimdeki de�er 120 olsun. dolay�s� ile yer ararken 400 de durmas� laz�m ki ikisinin aras�na koyabilelim.

	while (iter->next != NULL && iter->next->x < x)   // listenin sonuna gelmediysem  &&  listenin i�inde �uanda bakt���m de�erin x de�eri yani bakt���m�n g�sterdi�i kutunun x de�eri ekleyece�im de�erden k���kse
	{ // yani elindeki kutu 300 olsun g�sterdi�i kutu 400 olsun eklemek istedi�im 420 olsun
		iter = iter->next;   // o zaman bir sonrakine gitmemiz laz�m.
	} // iter olarak next next next �eklinde devam ettiysem linklist de bir ka� durum var. 1) linklistin sonuna geldim durdum demek, 2) benden daha b�y�k bir say� buldum durdum demek

	// ULA�TI�IN YERDE DE YEN� KUTUYU EKLE	
	// araya ekleme kodu
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next; // yeni kutunun nextine 400 �n (iter) nextinin g�sterdi�i yeri ba�la
	iter->next = temp;  // iterin (400) nextine yeni kutuyu ba�lad�k
	temp->x = x;
	return r;
}

int main() {

	node* root;
	root = NULL;
	//root = (node*)malloc(sizeof(node));
	//root->next = NULL;

	// sirakiEkle fonk ekledikten sonra root de�i�ebilir. De�i�mi� rootu main fonks alacak.
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

	//// �IKTI : 500   0    10	20	  30
	//// 20 ile 30 aras�na yeni bir eleman ekleyelim.

	//node* iter;  // iter tan�mlay�p
	//iter = root; // root ile ayn� yerden ba�lamas�n� istiyoruz.

	//// iterater �n 3 kere hareket etmesini istiyoruz. 20 de�erine ula�mak i�in

	//for (int i = 0; i < 3; i++)
	//{
	//	iter = iter->next;
	//}

	//// ge�ici bir d���m olu�turuyoruz. Haf�zada kaybetmemek i�in temp de�i�kenine atad�k.
	//node* temp = (node*)malloc(sizeof(node));

	//// SIRA �NEML� !!!  �nce tempe e�itlersem iterin nextini kaybedece�imiz i�in e�itleyemeyiz. Bu nedenle �nce nextler sonra iter
	//temp->next = iter->next; // olu�turdu�umuz ge�ici kutunun nexti 20 de�erinin oldu�u kutunun nextinin g�sterdi�i de�eri-kutuyu g�steriyor.
	//iter->next = temp; // iterin nextini tempe e�itliyoruz.
	//temp->x = 100; // 20 ile 30 aras�na eklemek istedi�imiz de�eri temp kutusuna at�yoruz.
	
	bastir(root);

}
*
* 
* 
*/