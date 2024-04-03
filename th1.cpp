#include<stdio.h>
//Cau truc nut
struct nut{
	int hs;
	int mu;
	nut *tiep;
};
typedef nut Node;
// khai bao bien con tro qlds
Node *dau;
Node *dau1;
Node *dt; //tro den da thuc tong
// khoi tao
void khoitao(Node *dau)
{dau=NULL;
}
// Nhap da thuc
void nhapdt(Node *&dau)
{Node *p, *q;
 int hstam;
 int smtam;
 q=NULL;p=NULL;
 	do {
   printf("\n Nhap he so, ket thuc:0  ");
   scanf("%d", &hstam);
   		if(hstam!=0)
   		 { // tao nut moi
   		 		p=new Node;
   		 		p->hs=hstam;
   		 		printf("\n Nhap so mu: ");
   		 		scanf("%d", &smtam);
   		 		p->mu=smtam;
   		 		p->tiep=NULL;
   		 	// Moc nut vao ds
   		 	if (dau==NULL)
   		 		dau=p;
   		 	else
   		 		q->tiep=p;
   		 		q=p;
   		 }
   	}
   	while (hstam!=0);
   }
// duyet ds
void duyetds(Node *dau)
{ Node *p;
	p=dau;
	printf("\n Da thuc: \n");
	 while (p!=NULL)
	 {	if (p->hs>0)
	 	printf("+%dx^%d",p->hs,p->mu);
	 	else
	 	
	 	
	 printf("%d x^%d",p->hs,p->mu);
	 p=p->tiep;}
}	 	
// Dao ham cua da thuc
void daoham(Node *dau)
{	Node *p;
	int hsdh;
	int hsmu;
	p=dau;
	while(p!=NULL)
	{	hsdh=p->hs*p->mu;
		hsmu=p->mu-1;
			if(hsdh!=0)
				if(hsdh>0)
			printf("+%dx^%d",hsdh,hsmu);
			else
			printf("%dx^%d",hsdh,hsmu);
			p=p->tiep;
	}
	}	
void chendt(Node *&dau)
{	Node *p,*q;
	int hsm,smm;
		printf("\n Nhap hsm:  "); scanf("%d",&hsm);
		printf("\n Nhap smm:  "); scanf("%d",&smm);
		if(hsm!=0)
		{// tao nut moi
			p=new Node;
			p->hs=hsm;
			p->mu=smm;
			p->tiep=NULL;
		// tim nut de chen
			q=dau;
				while ((q->mu>smm)&&(q->tiep!=NULL)&&(q->tiep->mu>smm))
					q=q->tiep;
					// nut moi co so mu > sm nut dau
				if (q->mu<smm)
					{	p->tiep=dau;
						dau=p;
					}
					// nut moi co so mu < so mu nut cuoi
				if(q->tiep==NULL)
					q->tiep=p;
					// nut moi chen vao giua ds
				if(q->tiep->mu<smm)
					{ p->tiep=q->tiep;
					  q->tiep=p;
					}
				
		}
}
void xoadau(Node *&dau)
{Node *p;
	if(dau!=NULL)
	{ p=dau;
	  dau=dau->tiep;
	  delete p;
	}
}
void xoacuoidt(Node *&dau)
{Node *p, *q;
	q=NULL; p=dau;
	if(dau!=NULL)
	{//Tim nut cuoi 
		while(p->tiep!=NULL)
		{q=p;
		p=p->tiep;
		}
		//p dia chi nut cuoi
		if(p==dau) xoadau(dau);
		else
		{q->tiep=NULL;
		delete p;
		}
}
}
void congdt(Node *dau, Node *dau1, Node *&dt)
{ Node *p, *q, *t, *l;
	int hst,hsm;
	l=NULL;
	p=dau;q=dau1;
	 while ((p!=NULL)&&(q!=NULL))
	 {	if (p->mu>q->mu)
	 		{hst=p->hs;hsm=p->mu;
	 		 p=p->tiep;
			 }
	else
		if	(p->mu>q->mu)
	 		{hst=p->hs;hsm=q->mu;
	 		 q=q->tiep;
			 }
		 else
		 if (p->mu==q->mu)
		 {hst=p->hs+q->hs;
		  hsm=p->mu;
		  p=p->tiep;q=q->tiep;
		  
		 }
		 // tao ra nut moi cua dt tong
		 t=new Node;
		 t->hs=hst;
		 t->mu=hsm;
		 t->tiep=NULL;
		 // moc nut moi vao da thuc tong
		 if (dt==NULL)
		  dt=t;
		 else
		  l->tiep=t;
		  l=t;
		 
	 }
	 // neu dt1 chua duyet xong
	 while (p!=NULL)
	 {t=new Node;
	 t->hs=p->hs;
	 t->mu=p->mu;
	 t->tiep=NULL;
	 p=p->tiep;
	 l->tiep=t;l=t;
	}
	// neu dt2 chua duyet xong
	 while (q!=NULL)
	 {t=new Node;
	 t->hs=q->hs;
	 t->mu=q->mu;
	 t->tiep=NULL;
	 q=q->tiep;
	 l->tiep=t;l=t;
	}
}
int main()
{
	khoitao(dau);
	khoitao(dau1);
	khoitao(dt);
	printf("\n Nhap da thuc 1 \n");
	nhapdt(dau);
	
	duyetds(dau);
	printf("\n Nhap da thuc 2 \n");
	nhapdt(dau1);
	duyetds(dau1);
	
	congdt(dau,dau1,dt);
	printf("\n Tong cua 2 da thuc: \n");
	duyetds(dt);
	/*printf("\n Dao ham da thuc \n");
	daoham(dau);
	chendt(dau);
	printf("\n Da thuc sau khi chen \n");
	duyetds(dau);
	xoacuoidt(dau);
	printf("\n Xoa nut cuoi dt \n");
	duyetds(dau);*/
	return 0;
}












