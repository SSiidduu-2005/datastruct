#include<stdio.h>
#include<stdlib.h>
struct NODE{
    float coeff;
    int exp;
    struct NODE *next;
};
typedef struct NODE node;
node* insert_a_term(node *head, float co, int ex){
    node *new_term=(node *)malloc(sizeof(node));
    new_term->coeff=co;
    new_term->exp = ex;
    new_term->next = NULL;

    if(head == NULL || new_term->exp>head->exp){
    	new_term->next=head;
        head=new_term;
    }
    else{
        node *temp = head;
        while (temp->next != NULL && temp->next->exp>new_term->exp){
            temp = temp->next;
        }
        new_term->next=temp->next;
        temp->next= new_term;
    }
    return head;
}
node* create_polynomial()
{
    node 
	*head =NULL;
    int n,i;
    printf("enter no. of terms: ");
    scanf("%d",&n);
    for( i = 1; i<=n ; i++){
        float co;
        int ex;
        printf("Enter coeff for term %d: ",i);
        scanf("%f",&co);
        printf("Enter exp for term %d: ",i);
        scanf("%d",&ex);
        head = insert_a_term(head,co,ex);
    }
    return head;
}
void display_polynomial(node *head){
    node *temp = head;
    while(temp!= NULL){
        printf("(%.fx^%d)",temp->coeff,temp->exp);
        if(temp->next!=NULL)
		{
            printf(" + ");
        }
        else
		{
            printf("\n");
        }
        temp= temp->next;
    }
}
node *poly_addition(node *poly1,node *poly2)
{
	node *t1=poly1;
	node *t2=poly2;
	node *head=NULL;//for resultant polynomial
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->exp==t2->exp)
		{
			head=insert_a_term(head,t1->coeff+t2->coeff,t1->exp);//t1->exp we can use t2->exp since both exps will same
			t1=t1->next;
			t2=t2->next;
		}
		else if(t1->exp>t2->exp)
		{
			head=insert_a_term(head,t1->coeff,t1->exp);
			t1=t1->next;
			
		}
		else
		{
			head=insert_a_term(head,t2->coeff,t2->exp);
			t2=t2->next;
		}
	}
	while(t1!=NULL)
	{
		head=insert_a_term(head,t1->coeff,t1->exp);
		t1=t1->next;
	}
	while(t2!=NULL)
	{
		head=insert_a_term(head,t2->coeff,t2->exp);
		t2=t2->next;
	}
	return head;
}
int main()
{
    //takeinput();
    printf("Polyomial1:\n");
    node *poly1=create_polynomial();//creating poly1
    printf("Polyomial2:\n");
    node *poly2=create_polynomial();//creating poly2
    node *sum=poly_addition(poly1,poly2);
    display_polynomial(poly1);//display the poly1
    display_polynomial(poly2);//dispaly the poly2
    display_polynomial(sum);//display the resultent poly(sum)
}
