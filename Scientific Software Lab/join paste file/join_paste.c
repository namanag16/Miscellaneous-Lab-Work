#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

int main()
{
	FILE *f1,*f2,*f3,*f4,*f5;
	char ch1,ch2,ch3,file1[30],file2[30],file3[30],file4[30];
	char mySystem1[80],mySystem2[80],line1[100],line2[100];
	int i=0,j=1,match=0;
	int ch;
	char temp1[100]="",temp2[100]="";

	printf("\nEnter first file: ");
	scanf("%s",file1);

	printf("\nEnter second file: ");
	scanf("%s",file2);

	f1=fopen(file1,"r");
	f2=fopen(file2,"r");

        if( f1 == NULL || f2 == NULL )
        {
      		perror("Error ");
	        printf("\nPress any key to exit...\n");
	        //getch();
	        exit(1);
	}

/*
	strcat(mySystem1,"sort ");
	strcat(mySystem1,file1);
	strcat(mySystem1," -o ");
	strcat(mySystem1,file1);
	printf("\n%s",mySystem1);
	system(mySystem1); // sort first file

	strcat(mySystem2,"sort ");
	strcat(mySystem2,file2);
	strcat(mySystem2," -o ");
	strcat(mySystem2,file2);
	printf("%\ns",mySystem2);
	system(mySystem2); // sort second file


*/

			printf("\nenter choice.... \n1.Join \n2.Paste ");
			fflush(stdin);
			scanf("%d",&ch);

		switch(ch)
		{
			case 1: 	printf("\nThe program will join the files ");
						f3 = fopen("join_file.txt","w");

						if(f3== NULL)
						{
							printf("\n unable to open the file \n");
							exit(2);
						}
						// what if we have characters other than space and numbers .. the code busts
						if(fgets(line1,99,f1) != NULL && fgets(line2,99,f2) !=NULL)
						{
							//printf("point 1 ");
							//getch();
						do
						{
							i=0;
							match=1;
							do
							{
								//printf("\nsee the value of i here %d and match is %d \n",i,match);
								if(line1[i] == 32 || line2[i] == 32)
								{
									match = 0;
									break;
								}
								if(line1[i] != line2[i])
								{
									match = 0;
									break;
								}
								//printf("\n\n%c    %c\n\n",line1[i],line2[i]);
								i++;
							}while(line1[i] != 32 || line2[i] != 32);
							//printf("\npoint 2... the value of match is %d and i is %d",match,i);

							//getch();
							if(match==0)
							{
								// match was not found.. now find from which file new line will be pulled out
								if(line1[i] == 32 && line2[i] == 32)
								{

									// fetch new lines from both the files and continue
									if(fgets(line1,99,f1) != NULL && fgets(line2,99,f2) !=NULL)
										continue;
									else //my job is done
										j=0;

								}
								else if(line1[i]==32)
								{
									if(fgets(line1,99,f1) != NULL)
										continue;
									else //my job is done
										j=0;
								}
								else if(line2[i]==32)
								{
									if(fgets(line2,99,f2) != NULL)
										continue;
									else //my job is done
										j=0;
								}
								else if(line2[i]>line1[i])
								{

									if(fgets(line1,99,f1) != NULL)
										continue;
									else //my job is done
										j=0;
								}
								else
								{
									if(fgets(line2,99,f2) != NULL)
										continue;
									else //my job is done
										j=0;
								}

							}
							else  // a match is found on the key field
							{
								//printf("\nfound a match");
								strncpy(temp2,line2+i,strlen(line2));
								strncpy(temp1,line1,(strlen(line1)-1));
								fputs(temp1,f3);
								fputs(temp2,f3);
								fputs("\n",f3);

								printf("%s%s",temp1,temp2);

								if(fgets(line1,99,f1) != NULL && fgets(line2,99,f2) != NULL)
									;
								else
									break;

							}


						}while(j==1);
						}
						else
						{
							// cannot join anything in two files
							printf("\n one of the files is empty");
						}
						/*printf("\nthe merged file is \n\n");
						while(fgets(line1,100,f3) != NULL)
						{
							printf("%s",line1);
						}*/

                        break;


			case 2: 	printf("Inside code for paste two files next to each other\n");
						f3 = fopen("paste_file.txt","w");
						while(1)
						{
							fgets(line1,99,f1);
							fgets(line2,99,f2);
							if(feof(f1) && feof(f2))
							 break;
							else if(!feof(f1) && !feof(f2))
							{
								strncpy(temp1,line1,(strlen(line1)-1));
								//strncpy(temp1,line2,(strlen(line2)-1));
								fputs(temp1,f3);
								fputs(line2,f3);
								
								printf("%s\t%s",temp1,line2);

							}
							else if ( !feof(f1) && feof(f2))
							{
								//strncpy(temp1,line1,(strlen(line1)-1));
								fputs(line1,f3);
								printf("%s",line1);
							}
							else if (feof(f1) && !feof(f2))
							{
								fputs("\t",f3);
								fputs(line2,f3);
								printf("\t%s",line2);
							}
						}
                        break;
		}

	printf("\nsuccessful completion \n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
	scanf("%d",&ch);
	exit(0);
}







