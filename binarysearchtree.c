#include<stdio.h>
#include<stdlib.h>

////\\\
///..\\\
//  - \\\

void add();
void search();

////\\\
///<<\\\
// -  \\\

typedef struct bst{
struct bst *left;
int n;
struct bst *right;
}bst;

////\\\\
///==\\\\
// -- \\\\

bst *temp1=NULL, *temp=NULL,*base=NULL;

////\\\\
///>>\\\\
// -  \\\\

void add(){
temp1=(bst*)malloc(sizeof(bst));
printf("Enter the value of node:\n");
scanf("%d",&temp1->n);
//condition check
while(1){
if(temp->n<temp1->n)
  {
    if(temp->right==NULL)
      { temp->right=temp1;
      break; }
    else
      { temp=temp->right;
      continue; }
  }
else
  {
    if(temp->left==NULL)
      { temp->left=temp1;
      break; }
    else
      { temp=temp->left;
      continue; }
  }
break;}
}

////\\\
///@@\\\
// __ \\\
//    ///
//_/_///

void search(){
int element,count=0;
printf("Enter the NUMBER you want to search in BST: \n");
scanf("%d", &element);
//check if the element is in root node
if(base->n==element)
   { printf("Element was found in root node: \nLEVEL %d\n", count); }
else
   {
  while(1){//--------------------------------------------------------------------------------- while 01 starts here
   count++; 
    if(base->n>element)
       {
          if(base->left==NULL)
             {printf("\nELEMENT NOT FOUND\n");
             break;}
           else
              {// count++;
                temp=base;
                temp=base->left;
                if(temp->n==element)
                  {
                     printf("Element was found in BST at: \nLEVEL %d\n",count);
                     break;
                  }
                if(temp->n>element)
                  {
                 //    count++;
                     temp=temp->left;
                     if(temp->n==element)
                     {// count++;
                     printf("Element was found in BST at: \nLEVEL %d\n",count);
                     break; }
                  }
               if(temp->n<element)
                  {
                     temp=temp->right;
                     if(temp->n==element)
                     { //count++;
                     printf("Element was found in BST at: \nLEVEL %d\n",count);
                     break; }
                  }
                else
                 printf("\nELEMENT NOT FOUND\n");
            }
        }
     else
           {   if(temp->right==NULL)
                {printf("\nELEMENT NOT FOUND\n");
                 break;}
              else
                {   //count++;
                  temp=temp->right;
                  if(temp->n==element)
                   {
                     printf("Element was found in BST at: \nLEVEL %d\n",count);
                     break;
                   }
                  if(temp->n>element)
                   {
                     temp=temp->left;
                     if(temp->n==element)
                     {// count++;
                     printf("Element was found in BST at: \nLEVEL %d\n",count);
                     break; }
                   }
                  if(temp->n<element)
                   {
                     temp=temp->right;
                     if(temp->n==element)
                     {// count++;
                     printf("Element was found in BST at: \nLEVEL %d\n",count);
                     break; }
                   }
                 else
                  printf("\nELEMENT NOT FOUND\n");
                }
        }
           }//-------------------------------------------------------------------------------while 01 ends here
   }
}


////\\\
///^^\\\
// -- \\\


int main(){
char Yn,srch;
base=(bst*)malloc(sizeof(bst));
base->left = base->right =NULL;
printf("Enter the value of root node:\n");
scanf("%d",&base->n);
temp=base;

while(1){
printf("\nWant to add a node: (Y/n)\n");
scanf("%s",&Yn);
//check if user wants to add or not
if(Yn=='Y' || Yn=='y')
  { add();
  continue; }
if(Yn=='N'|| Yn=='n')
 {
   printf("\nWant to search an element in BST? (Y/n)\n");
   scanf("%s",&srch);
//check if user wants to search or not
  if(srch=='Y'||srch=='y')
   search();
  if(srch=='N'||srch=='n')
   break;
  else
  if(srch!='Y' && srch!='y' && srch!='N' && srch!='n')
   continue;
  }
else
if(Yn!='Y' && Yn!='y' && Yn!='N' && Yn!='n')
  { printf("\nWrong, Try Again...\n");
  continue;}
}
return 0;
}
