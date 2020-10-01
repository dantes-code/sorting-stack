#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct{
	int data[max];          //array of size 10
	int top;
 }STACK;
void pop(STACK* S, int *v);
void push(STACK* S, int v);
int main(){
	STACK S1,Temp;
	S1.top = -1;
	Temp.top = -1;
	int i,n,val,valRetained,ValR;
	printf("How many elements are to be inserted ? : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter Data : ");
		scanf("%d",&val);
		if(S1.top == -1){
			push(&S1,val);	
		}	
		else{
			pop(&S1,&valRetained);
			if(val<valRetained){
				push(&S1,valRetained);
				push(&S1,val);			
			}
			else {				
				if(S1.top == -1){
					push(&S1,val);
					push(&S1,valRetained);
				}
				else{
					while(val>valRetained){
						if(S1.top == -1){
							push(&S1,val);	
							push(&S1,valRetained);
							break;
										
						}
						else{
							push(&Temp,valRetained);
							pop(&S1,&valRetained);
						}
					}
					push(&S1,val);
					while(Temp.top != -1){
						pop(&Temp,&ValR);
						push(&S1,ValR);							
					}								
				}
			}
		}
	}
	while(S1.top != -1){
		pop(&S1,&valRetained);
		printf("%d  ",valRetained);
	}
 }

void pop(STACK* S, int *v){         //this is the pop function which will delete the value of the Stack from the top
	if( S->top == -1 ){
		printf("UNDERFLOWED!!!!!");	
	}
	else{
		*v = S->data[S->top];
		S->top--;	
	}
 }  
void push(STACK* S, int v){         //this is the push function which will add a value on the top of the Stack
	if( S->top == max - 1){
		printf("OVERFLOWED!!!!!!!");	
	}
	else{
		S->top++;
		S->data[S->top] = v;	
	}
 }
