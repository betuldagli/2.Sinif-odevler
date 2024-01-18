#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*1-Bir adet stack yapýsý oluþturun. Bu stack yapýsý aþaðýda belirtildiði þekilde çift yönlü baðlý liste olarak oluþturulmalýdýr.
struct node{
	int data;
struct node *next;
struct node *prev;
}
Struct yapýsýnda ilk giren elemaný top olarak tutuyoruz.
struct node *top = NULL; 
2-Programýn içerisinde, indislerinde 5 adet sesli 5 adet sessiz harf bulunduran bir dizi olmalýdýr. Bu dizi bilgisayar tarafýndan oluþturulmuþ
rastgele harflerden oluþmalýdýr. Burada kontrol etmeniz gereken þey dizinin içerisinde mutlaka 5 adet rastgele sesli harf ve 5 adet rastgele 
sessiz harf bulunmalýdýr. (Harfler tekrar edebilir).
3-Daha sonra bu dizideki elemanlarý oluþturduðunuz stack yapýsýna aktaracaðýz. Eðer gelen harf sessiz ise bu harften sonra gelen harf sesli 
olmalýdýr. Eðer sessiz bir harften sonra gelen harf sessiz ise bu harfi stack yapýsýndan atýp listeden rastgele yeni bir harf alacaðýz. Gelen
harfsesli olana kadar bu iþleme devam edilecektir. Ayný þekilde sesli harften sonra da yalnýzca sessiz bir harf gelebilir. Burada pop ve push 
fonksiyonlarýný kodlamanýz gerekiyor. Stack yapýsýna eleman eklemek için push(),stack yapýsýndan eleman çýkarmak içinse pop() fonksiyonunu 
kullanmalýsýnýz. Her yeni eklenen harf stack yapýsýnýn yeni top elemaný olmalýdýr. 
4-Stack yapýsýnda bir sesli - bir sessiz harf þeklinde toplam 6 harf olduðunda LIFO (Last-In-First-Out) mantýðý ile stack yapýsýndan tek tek 
veriler çýkarýlmalýdýr. Her çýkartýlan veri ekrana yazdýrýlmalýdýr. 1.Dönem 1.Ödev
*/


struct node{
	char data;
struct node *next;
struct node *prev;
};
struct node *top = NULL; 
char dizi[20];
int diziIndex=10;
// Geçici liste için baþka bir node tanýmlayýn
struct node *tempList = NULL;

// Stack'ten eleman çýkarmak için fonksiyon
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
    /* Baðlý listeyi yazdýrma
    struct node *current = top;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("\n");*/
}

// Stack'e eleman eklemek için fonksiyon
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
    // Baðlý listeyi yazdýrma
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
    
       // Eðer stack boþsa, bu elemaný ekledikten sonra top'ý en baþa al
    if (top->next == NULL) {
        current = top;
    }
}

// Karakterin ünlü harf olup olmadýðýný kontrol etmek için fonksiyon
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
