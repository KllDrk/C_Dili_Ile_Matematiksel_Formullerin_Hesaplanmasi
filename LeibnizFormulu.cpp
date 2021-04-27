#include <stdio.h>

/*
Not= Normalde bu islem fonksiyonsuz sadece i nin tek mi yoksa cift mi olduguna bakilarak yapilabilirdi ama ben bunu okuyan kiþinin
uslu degerin hazir fonksiyon kullanmadan degerin bulundugunu gormesi icin bu sekilde yazdim.
*/

int Pow(int a,int b);

int main()
{
    double deger;
    int x;
    double formul;
    printf("Formul Ne zamana kadar devam etsin?\n");
    scanf("%d",&x);
    for(int i=0;i<=x;i++)
    {
    	//Burada formul var
        formul=Pow(-1,i);//eger sayi çiftse 1 tekse -1 degerini alacak.Formulde bakildiginda ilk deger 0. indis gibi dusunulurse
        				//birbirleri ile toplama ve cikarma islemlerini yapabilecektir(Formulun isleyisi: 1-1/3+1/5...)
        formul=formul/(2*i+1);//burasi ise payda kismi ile bölünerek formulun degeri elde ediliyor.
        deger=deger+formul;//burada ise bizim asil degerimiz bulunuyor.
    }
    //bu da bizim en basta 4 carpani olan yer
    deger=deger*4;//en son 4 ile carpiliyor.Normalde formulun kendisi pi/4 kadarlik degeri bulmak için tasarlanmiþtir. Biz de 4 ile carparak pi 
    			  //degerinin kendisini buluyoruz.
    printf("deger=%lf",deger);
    return 0;
}
//Math.h olmadan us deger alma
int Pow(int a,int b)
{
	if(b<0)   
	{
        return 1 / Pow (a,-b);//uslu degeri negatif olan sayinin pozitif halini alip ona gore hesapladiktan sonra
        					  //carpanina gore tersini alip sonucu donduruyor.	
							  //normalde bu bolume ihtiyac yoktur ama notta da bahsettigim gibi uslu deger almayi da deginmek icin yazdim.	
	   }   
      else if(b==0)
      {
        return 1;//herhangi bir deðerin sifirinci kuvveti 1'dir bu yuzden 1 dondurur.      	
	  }
      else if(b==1)
      {
        return a;//b azala azala 1'e ulaþtiðinda artýk sonuç hesaplanmis olacak. Bu yuzden sonucun kendisini
        		 //donduruyoruz.      	
	  }
      else
      {
        return a*Pow(a,b-1);//burada sayimiz her seferinde a degeri kadar carpiliyor.Uslu Degerin Kuvveti dedigimiz þey
        			//ayni sayinin kaç defa carpildigini gosterir.(Ornek 2^3=2*2*2 3 adet 2 sayisi carpilmistir.)      	
	  }

}
