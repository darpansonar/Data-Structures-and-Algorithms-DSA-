 #include<iostream>
 #include<malloc.h>
 using namespace std;
 
 struct sllnode
 {
 	int data;
 	struct sllnode *next;
 }*head;
 
 int count()
 {
 	struct sllnode *ptr;
 	int count=0;
 	ptr=head;
 	
 	while(ptr!=NULL)
 	{
 		ptr=ptr->next;
 		count++;
	}
	return count;
 }
 
 void insertBeg(int d)
 {
 	struct sllnode *ptr;
 	ptr=(struct sllnode *)malloc(sizeof(struct sllnode));
 	ptr->data=d;
 	
 	if(head==NULL)
 	{
 		head=ptr;
 		ptr->next=NULL;
	}
	
	else
	{
		ptr->next=head;
		head=ptr;
	}
 }
 
 void insertEnd(int d)
 {
 	struct sllnode *ptr,*ln;
 	ptr=(struct sllnode *)malloc(sizeof(struct sllnode));
 	ptr->data=d;
 	
 	if(head==NULL)
 	{
 		head=ptr;
 		head->next=NULL;
	}
	
	else
	{
		ln=head;
		while(ln->next!=NULL)
		{
			ln=ln->next;
		}
		ln->next=ptr;
		ptr->next=NULL;
	}
 }
 
 void deleteBeg()
 {
 	struct sllnode *ptr;
 	ptr=head;
 	head=ptr->next;
	free(ptr);
 }
 
 void deleteEnd()
 {
 	struct sllnode *ptr,*ln;
 	ln=head;
 	ptr=head;
 	
 	while(ptr->next!=NULL)
 	{
 		ptr=ptr->next; //ptr=last node
	}
	
	while(ln->next!=ptr)
	{
		ln=ln->next; //ln=second last node
	}
	free(ptr);
	ln->next=NULL;
 }
 
 void display()
 {
 	struct sllnode *ptr;
 	ptr=head;
 	
 	if(ptr==NULL)
	{
		cout<<"SLL is empty";
	}
	
 	while(ptr!=NULL)
 	{
 		cout<<ptr->data<<"\t";
 		ptr=ptr->next;
	}
 }
 
 int main()
 {
 	int c,v;
 	while(c!=7)
 	{
 		cout<<"\n\nEnter => 1.InsertBeg  2.InsertEnd  3.DeleteBeg  4.DeleteEnd  5.Display  6.Count  7.Exit : ";
 		cin>>c;
 		
 		switch (c)
 		{
 			case 1:
 				cout<<"Enter the element to insert : ";
 				cin>>v;
 				
 				insertBeg(v);
 				break;
 				
 			case 2:
 				cout<<"Enter the element to insert : ";
 				cin>>v;
 				
 				insertEnd(v);
 				break;
 				
 			case 3:
 				deleteBeg();
 				cout<<"Deleted first node";
 				break;
 				
 			case 4:
 				deleteEnd();
 				cout<<"Deleted last node";
 				break;
 				
 			case 5:
 				cout<<"Contents of SLL are : ";
 				display();
 				break;
 				
 			case 6:
 				cout<<"No. of elements in SLL : "<<count();
 				break;
 				
 			case 7:
 				exit(0);
		}
	}
	return 0;
 }
