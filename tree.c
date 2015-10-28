#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
	int num;
	struct node * rptr,*lptr;
}node;
struct node *root=NULL,*temp,*current;

int choice,x;
char ch;

void create()
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		printf("\nenter a value:\t");
		scanf("%d",&root->num);
		root->lptr=root->rptr=NULL;
	}
	else
	{
	
			temp=(struct node*)malloc(sizeof(struct node));
			printf("\nenter a value:\t");
			scanf("%d",&temp->num);
		    temp->lptr=temp->rptr=NULL;
		    current=root;
		    for(;;)
		    {
		    	if(temp->num<current->num)
		    	{
		    		if(current->lptr==NULL)
		    		{
		    			current->lptr=temp;
		    			break;
		    		}
		    		else
		    		{
		    			current=current->lptr;
		    			continue;
		    		}
		    		
		    	}
		    	else
		    	{
		    		if(current->rptr==NULL)
		    		{
		    			current->rptr=temp;
		    			break;
		    		}
		    		else
		    		{
		    			current=current->rptr;
		    			continue;
		    		}
	    		}
           }	 
       }
}

void inorder(struct node *root)
{
     if(root!=NULL)
     {
   	               inorder(root->lptr);
    	           printf("\n%d",root->num);
	               inorder(root->rptr);
     }
     else
         printf("NO DATA");
}

void preorder(struct node *root)
{
	 if(root!=NULL)
     {
  	               printf("\n%d",root->num);
   	               inorder(root->lptr);
	               inorder(root->rptr);
     }
     else
         printf("NO DATA");
}

void postorder(struct node *root)
{
	 if(root!=NULL)
     {
                   inorder(root->lptr);
   	               inorder(root->rptr);
	               printf("\n%d",root->num);
     }
     else
         printf("NO DATA");
}

void Delete(struct node *p,struct node *cur,char d)
{
	struct node *p1=NULL,*c1=NULL;
	if(cur->lptr==NULL && cur->rptr==NULL)
	{
		if(d=='r')
			p->rptr=NULL;
		else
			p->lptr=NULL;
	}
	else if(cur->lptr==NULL && cur->rptr!=NULL)
	{
		if(d=='r')
			p->rptr=cur->rptr;
		else
			p->lptr=cur->rptr;
	}
	else if(cur->lptr!=NULL && cur->rptr==NULL)
	{
		if(d=='r')
			p->rptr=cur->lptr;
		else
			p->lptr=cur->lptr;
	}
    else
	{
		p1=cur->rptr;
		c1=p1->lptr;
		while(c1->lptr!=NULL)
		{
			p1=c1;
			c1=c1->lptr;
		}
		cur->num=c1->num;
		p1->lptr=c1->rptr;	
	}
}

void search(int x)
{
	struct node *cur=root,*p=NULL;
	char d;
	while(1)
	{
		if(cur==NULL)
		{
			printf("\nValue not found!");
			break;
		}
		if(cur->num>x)
		{
			p=cur;
			d='l';
			cur=cur->lptr;	
		}
		else if(cur->num<x)
		{
			p=cur;
			d='r';
			cur=cur->rptr;
		}
		else
		{
			Delete(p,cur,d);
			break;
		}
	}
}

int main()
{
	printf("\nmenu:");
	printf("\n\t1.create");
	printf("\n\t2.inorder");
	printf("\n\t3.preorder");
	printf("\n\t4.postorder");
	printf("\n\t5.search and delete");
	printf("\n\t6.exit");
	while(1)
	{
            printf("\nenter ur choice:\t");
	        scanf("%d",&choice);
	        switch(choice)
	        {
		                  case 1:
                               create();
	        	               break;
                          case 2:
                               inorder(root);
		  		               break;
		                  case 3:
                                preorder(root);
                                break;
                          case 4:
                                postorder(root);
		  		                break;
	                      case 5:
                               printf("\nenter a number to be deleted:\t");
                               fflush(stdin);
	                           scanf("%d",&x);
			                   search(x);
		  	                   break;
		                  case 6:
                               exit(0);  
		                  default:
                                  printf("\n\tenter valid choice!");		
                    }
         }
	     return(0);
}
