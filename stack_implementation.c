 #include<stdio.h>
 #include<stdlib.h>
 
 
 struct Stack                    //data structure of stack.
 {
	 int top;
	 int length;
	 int * array;
 };
 
 struct Stack* Create_Stack(int n)     // function to create stack   ;; returns pointer to created stack
 {
	 struct Stack * stack = (struct Stack*) malloc(sizeof(struct Stack));
	 stack->top = -1;
	 stack->length = n;
	 stack->array = (int *) malloc(stack->length*sizeof(int));
	 return stack;
 }
 
 int Push(struct Stack* stack,int i)            //pushing into stack  ;; return if successful or failure
 {
	if(stack->top < (stack->length - 1) )   //check for overflow
	{
		stack->top++;
		stack->array[stack->top] = i;
		return 1;
	}
	else
	{
		printf("\nstack overflow");
		exit(1);
	}
 }
 
 
 int Pop(struct Stack* stack)                          //function to pop an element from the stack
 {
	 if(stack->top != -1)           //check for underflow
	 {
		return(stack->array[stack->top--])	 ;
	 }
	else
	{
		printf("\nstack underflow");
		exit(1);
	}
 }
 
 int main()
 {
	 int i,n,opt;
	 struct Stack* stack ;
	 printf("Enter length of stack : ");
	 scanf("%d",&n);
	 stack = Create_Stack(n);
	 printf("\nEnter a number : \n1.) Push into stack\n2.) Pop from Stack\n3.) View Contents of stack\n4.) Exit. "); //operations on stack
	 while(1)
	 {
		printf("\ninput option : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1 :
				printf("input number to push : ");
				scanf("%d",&n);
				if(Push(stack,n))
					break;
			case 2 : 
				printf("popped  element : %d",Pop(stack));
				break;
			case 3 :
				printf("contents of stack : ");
				for(i=0;i <= stack->top; i++)
				{
					printf("%d ",stack->array[i]);
				}
				break;
			case 4 : 
				return 0;
			default : 
				printf("\nInvalid option. Input correct option");
		}
	 }
 }
