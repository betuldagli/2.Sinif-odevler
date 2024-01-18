#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*1-Bir adet stack yap�s� olu�turun. Bu stack yap�s� a�a��da belirtildi�i �ekilde �ift y�nl� ba�l� liste olarak olu�turulmal�d�r.
struct node{
	int data;
struct node *next;
struct node *prev;
}
Struct yap�s�nda ilk giren eleman� top olarak tutuyoruz.
struct node *top = NULL; 
2-Program�n i�erisinde, indislerinde 5 adet sesli 5 adet sessiz harf bulunduran bir dizi olmal�d�r. Bu dizi bilgisayar taraf�ndan olu�turulmu�
rastgele harflerden olu�mal�d�r. Burada kontrol etmeniz gereken �ey dizinin i�erisinde mutlaka 5 adet rastgele sesli harf ve 5 adet rastgele 
sessiz harf bulunmal�d�r. (Harfler tekrar edebilir).
3-Daha sonra bu dizideki elemanlar� olu�turdu�unuz stack yap�s�na aktaraca��z. E�er gelen harf sessiz ise bu harften sonra gelen harf sesli 
olmal�d�r. E�er sessiz bir harften sonra gelen harf sessiz ise bu harfi stack yap�s�ndan at�p listeden rastgele yeni bir harf alaca��z. Gelen
harfsesli olana kadar bu i�leme devam edilecektir. Ayn� �ekilde sesli harften sonra da yaln�zca sessiz bir harf gelebilir. Burada pop ve push 
fonksiyonlar�n� kodlaman�z gerekiyor. Stack yap�s�na eleman eklemek i�in push(),stack yap�s�ndan eleman ��karmak i�inse pop() fonksiyonunu 
kullanmal�s�n�z. Her yeni eklenen harf stack yap�s�n�n yeni top eleman� olmal�d�r. 
4-Stack yap�s�nda bir sesli - bir sessiz harf �eklinde toplam 6 harf oldu�unda LIFO (Last-In-First-Out) mant��� ile stack yap�s�ndan tek tek 
veriler ��kar�lmal�d�r. Her ��kart�lan veri ekrana yazd�r�lmal�d�r. 1.D�nem 1.�dev
*/


struct node{
	char data;
struct node *next;
struct node *prev;
};
struct node *top = NULL; 
char dizi[20];
int diziIndex=10;
// Ge�ici liste i�in ba�ka bir node tan�mlay�n
struct node *tempList = NULL;

// Stack'ten eleman ��karmak i�in fonksiyon
void pop() {
    if (top == NULL) {
        printf("Stack bos.\n");
        return;
    }
  
    struct node *temp = top;
    //printf("%c cikartildi.\n", temp->data);
   // printf("eklenen harf:%c\n",temp->data);
    
    dizi[diziIndex] = temp->data;
         diziIndex++;
     
    top = top->next;
    top->next->prev=top->prev;
    /* Ba�l� listeyi yazd�rma
    struct node *current = top;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("\n");*/
}

// Stack'e eleman eklemek i�in fonksiyon
void push(char newData) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = top;
    newNode->prev = NULL;

    if (top != NULL) {
        top->prev = newNode;
    }

    top = newNode;
    int sayac=0;
    // Ba�l� listeyi yazd�rma
    struct node *current = top;
    while (current != NULL) {
    	
    	if(sayac<6){
    	
    	 printf("%c -> ", current->data);
        sayac++;	if(sayac==6){
    			break;
			}
		}
		else{
			break;
		}
	current = current->next;

    } printf("\n");
    
       // E�er stack bo�sa, bu eleman� ekledikten sonra top'� en ba�a al
    if (top->next == NULL) {
        current = top;
    }
}

// Karakterin �nl� harf olup olmad���n� kontrol etmek i�in fonksiyon
int sesliMi(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
 	
			
 int main(){
    struct node *gecici = NULL; 
 	char rastgeleHarf;
 	int sesliSayac=0,sessizSayac=0,i=0;
    
	gecici=(struct node*) malloc(1*sizeof(struct node));
 	srand(time(0));
 	 while(i<10){
	  	rastgeleHarf = 'a'+ rand()%26;
	  	
 	if(sesliSayac<5 &&sesliMi(rastgeleHarf)){
 			sesliSayac++;
 			dizi[i]=rastgeleHarf;
 			i++;
	 }
	 if(sessizSayac<5 && !sesliMi(rastgeleHarf)){
 			sessizSayac++;
 			dizi[i]=rastgeleHarf;
 			i++;
	 }	
}
     for(int j=0;dizi[j]!='\0';j++){
     	printf("%c\t",dizi[j]);
    }
    printf("\n");
    int a=-1;
	  while(a<20){
    	if(top==NULL){
		top=(struct node*) malloc(1*sizeof(struct node));
		top->data=dizi[0];	
		top->next='\0'; 
		top->prev='\0';	
        gecici=top;
		}
		
		else{
			if(sesliMi(dizi[a])){
				if(sesliMi(dizi[a+1])){
				//	printf("\n%c sesli sonrasi sesli\n",dizi[a+1]);
				pop();
				push(dizi[a+1]);
				} 
				else{
				//	printf("\n%c sesli sonrasi sessiz\n",dizi[a+1]);
					push(dizi[a+1]);
				}
			}
			else{
					if(!sesliMi(dizi[a+1])){
				//		printf("\n%c sessiz sonrasi sessiz\n",dizi[a+1]);
					pop();
				push(dizi[a+1]);
					
				}
				else{
				//	printf("\n%c sessiz sonrasi sesli\n",dizi[a+1]);
						push(dizi[a+1]);
				}
			}
		}
		a++;
	}
 	return 0;
	 }
