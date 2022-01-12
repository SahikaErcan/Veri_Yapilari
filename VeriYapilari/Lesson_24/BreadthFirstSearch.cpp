
// BFS Algoritmas� Graflar �zerinde arama algoritmas�d�r. Bir noktadan ba�layarak di�er t�m d���mleri ziyaret etmeyi hedefler.
// Mant�k olarak en yak�ndaki d���mleri ziyaret eder, giderek uzakla��r. 

#pragma warning(disable : 4996)  // uyar�y� kapatt�k
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	node* next;
};

node* front = NULL;
node* rear = NULL;

int arr[6][6];
bool visit[6];

node* createNode(int data) {
	node* root = (node*)malloc(sizeof(node));
	root->data = data;
	root->next = NULL;
	return root;
}

void enQueue(int data) {
	struct node* newNode = createNode(data);

	if (front == NULL)  // Eleman yoksa
	{
		// kuyrukta bir ki�i varsa o hem birincidir hem sonuncudur.
		front = newNode;
		rear = newNode;
	}
	else  // eleman varsa 
	{
		rear->next = newNode;
		rear = newNode;
	}
}

void deQueue() {
	if (front == NULL)
	{
		printf("Kuyrukta eleman yok.");
		return;
	}
	if (front->next == NULL) // bir tane eleman varsa
	{
		front = NULL;
		rear = NULL;
	}
	else // �ok�a eleman varsa
	{
		struct node* temp = front->next;
		free(front);
		front = temp;
	}
}

bool _empty() {  // Kuyruk yap�m bo� mu?
	if (front == NULL)
		return true;
	else
		return false;
}

void bfs(int root)  // ba�lang�� noktas�n� parametre olarak g�nderiyoruz.
{
	for (int i = 0; i < 6; i++)
		visit[i] = false;  // D���mler ziyaret edilmedi.

	// G�nderilen d���m� ziyaret edildi olarak i�aretliyoruz.
	visit[root] = true;
	enQueue(root); // kuyru�a ekliyoruz.

	while (_empty() == false)  // kuyruk bo� olmad��� s�rece d�n
	{
		root = front->data;  // kuyru�un �n�ndeki eleman� roota at�yoruz.
		printf("%d ", root); // ziyaret etti�imiz d���m� g�steriyoruz.
		deQueue();  // kuyruktan ��kart�yrouz.

		// Bir d���m�n birden fazla kom�usu olabilir. T�m kom�ular� eklemek i�in d�ng� a��yoruz.
		for (int i = 0; i < 6; i++)
		{
			if (visit[i] == false && arr[root][i] == 1)  // ziyaret edilmemi� ve kom�ulu�un olmas� gerekiyor
			{
				visit[i] = true; // ziyaret edildi�ini belirtip
				enQueue(i);  // kuyru�a ekliyoruz.
			}
		}
	}
}

void matrisRead() {
	int i = 0;
	FILE* fp = fopen("matris.txt", "r");  // txt dosyas� sat�rlar d���mleri s�tunlarsa kom�uluklar� g�sterecek �ekilde d�zenlendi.

	// fscanf dosyadan veri okur. EOF: dosya sonuna kadar oku
	while (fscanf(fp, "%d %d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4], &arr[i][5]) != EOF)  i++;
}
int main()
{
	matrisRead();
	bfs(2);  // 2 de�erli k�k ile ba�lamas�n� s�yl�yoruz.
	return 0;
}
