#include<stdio.h>
#include<stdlib.h>
int arr[6757],size;
void view()
{
    int i;
    printf("Your array is: ");
    for(i=1; i<=size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void newelement()
{
    int item, pos, i,*s;
    printf("Enter the ITEM to be inserted: ");
    scanf("%d",&item);
    printf("Enter position of ITEM: ");
    scanf("%d",&pos);
    for(i=size; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    s=&size;
    //size=&size+1;
    *s=*s+1;
    view();
}
void search()
{
    int item,loc=0,i=1;
    printf("Enter an ITEM to be searched: ");
    scanf("%d",&item);
    for(i=1; i<=size; i++)
    {
        if(arr[i]==item)
        {
            loc=i;
            printf("%d is found in location %d\n",item,loc);
        }
    }
    if(loc==0)
    {
        printf("ITEM not found");
    }
}
void del()
{
    int x=size;
    int item,loc=0,i=1,j,*s,ok=0;
    printf("Enter an ITEM to be deleted: ");
    scanf("%d",&item);
    for(i=1; i<=size; i++)
    {
        if(ok==1 && i!=1){
            i--;
            ok=0;
        }
        if(arr[i]==item)
        {
            loc=i;
            for(j=loc; j<=size-1; j++)
            {
                arr[j]=arr[j+1];
            }
            //delete(arr[j+1]);
            size--;
            ok=1;
            //size=size-1;
            //*s=*s-1;
        }
    }
    if(loc==0)
    {
        printf("ITEM not found");
    }
    else
    {
        view();
    }
}
void asort()
{
    int i,ptr,swap;
    for (i=1; i<=size-1; i++)
    {
        for (ptr=1; ptr<=size-i; ptr++)
        {
            if (arr[ptr]>arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }

    printf("Sorted list in ascending order:\n");

    view();
}

void dsort()
{
    int i,ptr,swap;
    for (i=1; i<=size-1; i++)
    {
        for (ptr=1; ptr<=size-i; ptr++)
        {
            if (arr[ptr]<arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }

    printf("Sorted list in descending order:\n");

    view();
}

void mem()
{
    int p,i,index,ad,loc;
    p=*arr+1;
    printf("Enter the index (N.B. index 1 means first element): ");
    scanf("%d",&index);
    index--;
    if(index>size)
    {
        printf("Index should be from 0 to size-1. So, your given index is invalid.");
    }
    else
    {
        ad=p+sizeof(int)*index;
        printf("The %dth element is allocated in location %d",index+1,ad);
    }
}
void choose()
{
    int choice;
    printf("Enter your choice:\n1. view\n2. insert\n3. search\n4. Delete\n5. ascending sorting\n6. Descending sorting\n7. memory allocation\n");
    while(scanf("%d",&choice)!=0)
    {
        if(choice==1)
        {
            view();
        }
        else if(choice==2)
        {
            newelement();
        }
        else if(choice==3)
        {
            search();
        }
        else if(choice==4)
        {
            del();
        }
        else if(choice==5)
        {
            asort();
        }
        else if(choice==6)
        {
            dsort();
        }
        else if(choice==7)
        {
            mem();
        }
    }
}
void more()
{
    int more;
    printf("Do you want to do perform more job? if YES, enter 1; otherwise enter 0: ");
    scanf("%d",&more);
    if(more==1)
    {
        system("cls");
        choose();
    }
    else
        exit;
}
int main()
{
    int i,choice,decide;
    printf("Enter array size: ");
    scanf("%d",&size);
    //arr = (int*) malloc(size * sizeof(int));
    printf("Enter array elements: ");
    for(i=1; i<=size; i++)
    {
        scanf("%d",arr+i);
    }
    printf("Dear user, you can do some jobs with your array.. if you want to see the job menu, enter 1. otherwise enter 0\n");
    scanf("%d",&decide);
    if(decide==1)
    {
        choose();
    }
    else
        exit;
    //system("cls");
    //printf("yo!");
}
