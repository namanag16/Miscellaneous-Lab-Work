#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a;
	char *v,*s;
	char snew[90]="";
	char snew2[90]="";
	char snew3[90]="";
	char *x;

		printf("what operation dude: ");
		printf("\n1. edit file\n2. change modification date of the file\n3. merge two files 4. print the user\n5. print working directory");
		printf("\n6. list the files\n7. sort the file\n8. change file permissions\n9. create a hardlink 10. find a file ");
		printf("\n11. just print the file\n12. see the word count in the file\n13. append output of a command into a file");
		printf("\n14. echo something \n15. cut a field from a file and save into another file:\n\n");
		scanf("%d",&a);

		switch(a)
		{
			case 1 :
					 printf("enter name of the file to be edited along with full file path");
					 scanf("%[^\n]s",snew);
					 snew2="vi ";
					 strcat(snew2,snew);
					 system(snew2);
					 break;

			case 2 :
					 printf("enter the fully specified modification date");
					 scanf("%[^\n]s",snew);
					 snew2="touch ";
					 strcat(snew2,snew);
					 printf("enter name of the file to be edited along with full file path");
					 scanf("%[^\n]s",snew);
					 strcat(snew2,snew);
					 system(snew2);
					 break;

			case 3 :
					 printf("enter name of the file one");
					 scanf("%[^\n]s",snew);

					 printf("enter name of the file two");
					 scanf("%[^\n]s",snew3);
					 snew2 = "pr -m -t";
					 snprintf(snew2,200,"%s %s >> mergedfile",snew,snew3);
					 system(snew2);
					 break;

			case 4 : printf("\nthe user is : ");
					 system("whoami");
					 break;

			case 5 : printf("the working directory is : ");
					 system("pwd");
					 break;

			case 6 :
					 printf("\n give fully specified path of the folder for which u wanna list d files: ");
					 scanf("%[^\n]s",snew);
					 snew2 = "ls -l ";
					 strcat(snew2,snew);
					 system(snew2);
					 break;

			case 7 :
					 printf("\n give fully specified file name along with path: ");
					 scanf("%[^\n]s",snew);
					 snew2 = "sort ";
					 strcat(snew2,snew);
					 system(snew2);
					 break;

			case 8 :
					 printf("\nenter file name with path: ");
					 scanf("%[^\n]s",snew);
					 printf("\n enter permissions ");
					 scanf("%s",snew3);
					 snew2 = "chmod ";
					 snprintf(snew2,200," %s %s",snew3,snew);
					 system(snew2);
					 break;

			case 9 :
					 printf("\n give fully specified file name along with path: ");
					 scanf("%[^\n]s",snew);
					 snew2 = "ln hard-link_1 ";
					 strcat(snew2,snew);
					 system(snew2);
					 break;

			case 10: printf("we will find a file starting from the current directory");

					 printf("\n give file name with path: ");
					 scanf("%[^\n]s",snew);
					 snew2= "find . ";
					 strcat(snew2,snew);
					 system(snew2);
					 break;

		}
}
