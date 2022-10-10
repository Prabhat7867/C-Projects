#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
	char phone[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	printf("\nWhat do you want to do?");
	printf("\n\n1.Open New account");
	printf("\n2.Login to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt == 1){
		printf("\nEnter your account number:\t");
		scanf("%s",user.ac);
		printf("Enter your phone number:\t");
		scanf("%s",user.phone);
		
		strcpy(filename,user.phone);
		fp = fopen(strcat(filename,".dat"),"r");
		fclose(fp);
		if(fp == NULL){
			printf("Enter your new password:\t");
			scanf("%s",user.password);
			user.balance=0;
			strcpy(filename,user.phone);
			fp=fopen(strcat(filename,".dat"),"w");
			fwrite(&user,sizeof(user),1,fp);
			if(fwrite != 0){
				printf("Succesfully Opened ");}}
		else{
			printf("Account number already registered");
		 	return 0;
		}}

	else if(opt == 2){
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".dat"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				printf("\n\tWelcome %s",user.phone);
				printf("\nPress 1 for Balance Enquiry");
				printf("\nPress 2 for Cash Deposit");
				printf("\nPress 3 for Cash Withdraw");
				printf("\nPress 4 for Online Money Transfer");
				printf("\nPress 5 for Change Yout Password\n\n");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("Your Current Balance is Rs. %.2f",user.balance);
						break;

					case 2:
						printf("Enter amount to deposit:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 100 != 0) printf("\nSorry amount should be multiple of 100");
						else if(amount>user.balance) printf("\nSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;
					
					case 4:
						printf("Please enter the phone number to trasnfer balance:\t");
						scanf("%s",phone);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > user.balance) printf("\nSorry insufficent balance");
						else {
							fptr = fopen(strcat(phone,".dat"),"r");
							if(fptr==NULL) printf("Sorry number is not registered");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);
							
								usr.balance += amount;
								
								fptr = fopen(phone,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){
								// 	printf("Account:%s",usr.ac);
								// printf("\npassword%s",usr.password);
								// printf("\nphone%s",usr.phone);
								// printf("\nbalance%f",usr.balance);
									printf("Your transfer is completed. You have transfered Rs.%d to %s",amount,usr.phone);
									fclose(fptr);
									user.balance -= amount;
									strcpy(filename,user.phone);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");
					
					default:
					break;
				}
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}	
		}
		printf("\n\n***Thank you for banking with SARACA Bank***\n\n");
	}
	
	return 0;
}
