#include <stdio.h>

int main(){
	int row,col,i,j,value,from,to,choice,x,k;
	printf("Enter the number of rows of columns in the array:\n");
	scanf("%d %d", &row,&col);
	int arr[row][col];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
        	printf("Enter element No [%d][%d]::",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Your array before Updatation::\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("Enter the number of operations to be performed on the array:");
    scanf("%d",&k);
    for(x=0;x<k;x++)
    {
    	printf("Enter choice whether to update rows or columns::(1-Rows 2-Columns)::");
    	scanf("%d",&choice);
    
        if(choice==1)
        {
        	printf("Enter the row from where you want to update:");
    		scanf("%d",&from);
    		printf("Enter the row upto where you want to update:");
    		scanf("%d",&to);
    	    printf("Enter the value to be added in the element:");
            scanf("%d",&value);
            for(i=from-1;i<to;i++)
            {
                for(j=0;j<col;j++)
                {
                    arr[i][j]+=value;
                }
            }
        }
         if(choice==2)
        {
        	printf("Enter the row from where you want to update:");
    		scanf("%d",&from);
    		printf("Enter the row upto where you want to update:");
    		scanf("%d",&to);
    	    printf("Enter the value to be added in the element:");
    	    scanf("%d",&value);
            for(i=from-1;i<to;i++)
            {
                for(j=0;j<row;j++)
                {
                    arr[j][i]+=value;
                }
            }
        }
   	printf("Array after updatation No. %d::\n",x+1);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    }
    printf("Your array after updatation is:\n");
     for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}



