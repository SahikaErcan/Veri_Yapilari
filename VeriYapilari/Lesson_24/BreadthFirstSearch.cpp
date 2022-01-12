
// BFS Algoritmasý Graflar üzerinde arama algoritmasýdýr. Bir noktadan baþlayarak diðer tüm düðümleri ziyaret etmeyi hedefler.
// Mantýk olarak en yakýndaki düðümleri ziyaret eder, giderek uzaklaþýr. 

#pragma warning(disable : 4996)  // uyarýyý kapattýk
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
		// kuyrukta bir kiþi varsa o hem birincidir hem sonuncudur.
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
	else // çokça eleman varsa
	{
		struct node* temp = front->next;
		free(front);
		front = temp;
	}
}

bool _empty() {  // Kuyruk yapým boþ mu?
	if (front == NULL)
		return true;
	else
		return false;
}

void bfs(int root)  // baþlangýç noktasýný parametre olarak gönderiyoruz.
{
	for (int i = 0; i < 6; i++)
		visit[i] = false;  // Düðümler ziyaret edilmedi.

	// Gönderilen düðümü ziyaret edildi olarak iþaretliyoruz.
	visit[root] = true;
	enQueue(root); // kuyruða ekliyoruz.

	while (_empty() == false)  // kuyruk boþ olmadýðý sürece dön
	{
		root = front->data;  // kuyruðun önündeki elemaný roota atýyoruz.
		printf("%d ", root); // ziyaret ettiðimiz düðümü gösteriyoruz.
		deQueue();  // kuyruktan çýkartýyrouz.

		// Bir düðümün birden fazla komþusu olabilir. Tüm komþularý eklemek için döngü açýyoruz.
		for (int i = 0; i < 6; i++)
		{
			if (visit[i] == false && arr[root][i] == 1)  // ziyaret edilmemiþ ve komþuluðun olmasý gerekiyor
			{
				visit[i] = true; // ziyaret edildiðini belirtip
				enQueue(i);  // kuyruða ekliyoruz.
			}
		}
	}
}

void matrisRead() {
	int i = 0;
	FILE* fp = fopen("matris.txt", "r");  // txt dosyasý satýrlar düðümleri sütunlarsa komþuluklarý gösterecek þekilde düzenlendi.

	// fscanf dosyadan veri okur. EOF: dosya sonuna kadar oku
	while (fscanf(fp, "%d %d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4], &arr[i][5]) != EOF)  i++;
}
int main()
{
	matrisRead();
	bfs(2);  // 2 deðerli kök ile baþlamasýný söylüyoruz.
	return 0;
}
