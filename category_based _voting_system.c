#include <stdio.h>
#define MAX_CAT 20
#define MAX_NAME 20
#define VOTE_SIZE 1000
#define V_F_E 100 

void first_case(char cat_name[MAX_NAME],int*cat_num,char sub_cat[MAX_CAT][MAX_NAME]){
	int i;
	
	printf("\nEnter category name:");
	scanf("%19s",cat_name);
	while (1){
			
		printf("\nEnter number of categories:");
		
		{
			if (scanf("%d",cat_num)!=1)
			{
				printf("Unvalid input, you have to enter a number .");
				while (getchar()!= '\n');
			}
			else if (*cat_num<=0 || *cat_num >MAX_CAT)
			{
				printf("Number out of range.\n");
				continue;
			}
			else
				break;
			 
		}
	}			
	for(i=0;i<*cat_num;i++)
	{
		printf("Enter category%d\n\t",i+1);
		scanf("%19s",sub_cat[i]);
	}
	for (i=0;i<*cat_num;i++)
		printf("CATEGPRIES ARE : %s\n", sub_cat[i]);
}

void secound_case(char sub_cat[MAX_CAT][MAX_NAME],int *vote,int *cat_num,int vot_num[VOTE_SIZE]){
	
	int choice=0,i,j;
	 
	
	do{
						
		printf("Vote: %d\n ",*vote+1);
		for(i=0;i<*cat_num;i++ )
		{
			printf("\n[%d] %s\n ",i+1,sub_cat[i]);
		}
		printf("\n[%d] Finish\n",*cat_num+1);
		
		if(scanf("%d",&choice)!= 1)
		{
			while(getchar()!='\n');
			printf("ERROR! you can only choose from the available numbers.\n");
			choice=0;
			continue;
		}
		
		else if (choice>0 && choice<*cat_num+1 )
		{
			vot_num[*vote]=choice;
			(*vote)++;
							
							
		}
						
		}while( choice != *cat_num+1);
					
		
}

void calculate_votes(int vote_for_each[V_F_E],
                     int vot_num[VOTE_SIZE],
                     int vote)
{
    int i;
    for (i = 0; i < vote; i++)
        vote_for_each[vot_num[i] - 1]++;
}


void third_case(char cat_name[MAX_NAME],int cat_num,char sub_cat[MAX_CAT][MAX_NAME],int vote_for_each[V_F_E],int vot_num[VOTE_SIZE],int vote){
                
	int i,j;
    for (i = 0; i < V_F_E; i++)
        vote_for_each[i] = 0;
    
    calculate_votes(vote_for_each,vot_num,vote);
	printf("\n****** VOTING RESULTS ******");
    printf("\nCategory: %s\n", cat_name);
	                
	for (i=0;i<cat_num;i++)
	                
	{
	                	
	    printf("\n[%d] %s ",i+1,sub_cat[i]);
	                	
	    printf("\t%d\n",vote_for_each[i]);
	    for(j=0;j<vote_for_each[i];j++)
	        printf("*");
	    printf("\n");
	}
}

void fourth_case(char sub_cat[MAX_CAT][MAX_NAME],int cat_num,int vote,int vote_for_each[V_F_E]){
	int less = vote_for_each[0];
	int most = vote_for_each[0];
	int less_p = 0;
	int most_p = 0;
	int i;
					
	for(i=0;i<cat_num;i++)
	{
						
		if(vote_for_each[i]<less)
		{
			less = vote_for_each[i];
			less_p=i;	
		}
		else if (vote_for_each[i]>most)
		{
			most= vote_for_each[i];
			most_p=i;
		}
							
	}
					
	printf("\nVOTES NUMBER:%d\nMOST POPULAR: %s",vote,sub_cat[most_p]);
	printf("\nLEAST POPULAR :%s\n",sub_cat[less_p]);
}
int main ()
{	

	char *menu[] = {
      "Enter categories",
      "Enter votes",
      "Show results",
      "display statistics",
      "Exit"
    };
  
    char cat_name[MAX_NAME];
    char sub_cat[MAX_CAT][MAX_NAME];
    char less_popular[10],most_popular[10];
    
	int i,j,cho,cat_num=0,vote=0;
	int vot_num[VOTE_SIZE]={0},vote_for_each[V_F_E]={0};
	int less=VOTE_SIZE ,most=0 ;
	int less_p=0,most_p=0;
	

	
	printf("\n ======================== ");
	printf("\n||                        ||");
	printf("\n||     VOTING MACHINE     ||");
	printf("\n||                        ||");
	printf("\n||       ver. 1.0         ||");
	printf("\n||                        ||");
	printf("\n ========================");
	

	do{
		printf("\n****** MAIN MENU ******");
		for (i=0;i<5;i++)
		{
		
			printf("\n[%d] %s",i+1,menu[i]);
			
		}
		printf("\n");
		if (scanf("%d",&cho)!=1)
		{
			printf("ERROR! YOU HAVE TO CHOOSE NUMBER FROM THE LIST.");
			while(getchar()!='\n');
			continue;
		}	
		switch(cho){
			case 1:
			
				first_case(cat_name, &cat_num,sub_cat);
				break;  
				
			case 2:
				
				if (cat_num==0)
				{
					printf("Please choose 1 to enter categories first.");
					
				}
					
					
				else
					secound_case(sub_cat,&vote,&cat_num,vot_num);
			
				break;
			
			case 3:
				
                if (vote==0)
                	printf("Please choose 2 to vote first.");
				else
				third_case(cat_name,cat_num,sub_cat,vote_for_each,vot_num,vote);
				break;
				
			case 4:
				if (vote==0)
                	printf("Please choose 2 to vote first.");
                else
				fourth_case(sub_cat, cat_num, vote,vote_for_each);
				break;
			
			default:
				printf("UNAVAILABLE CHOICE YOU  CAN CHOOSE FROM 1 TO 5 :");
				break;
			}
	}while (cho !=5 );		
		
		
	return 0;	
		
	

}



		 


