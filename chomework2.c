#include <math.h>
#include <stdio.h>
char f0();
int f1();
int f2(int num);
void f3(int num, int dig);
int f4(int num);
int f5(int num);
int f6(int num);
void f7(int num);

int main(void){
	char choice;


    do {
        choice = f0();

        if (choice == 'Q') {
            break;
        }

        if (choice == 'S') {
            int num = f1();
            int result = f4(num);
            if (result) {
                printf("%d is a super prime.\n", num);
            } else {
                printf("%d is not a super prime.\n", num);
            }
        } else if (choice == 'B') {
            int num = f1();
            int dig = f2(num);
            printf("The binary equivalent of %d is ",num);
            f3(num,dig);
        } else if (choice == 'W') {
            int num = f1();
          	f7(num);
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 'Q');

    return 0;
	
	
	
	
	return 0;
}
char f0(){
	printf("Input S for super prime check , B for binary equivalent, W for weird prime check or Q to quit:");
	char user_input;
    scanf(" %c", &user_input);
    return user_input;
}
int f1(){
	int num;
	do{
		printf("Input an integer: ");
		scanf("%d",&num);
		if(num<0){
			printf("Enter a positive integer!\n");
		}
	}
	while(num<0);
	
	return num;
}
int f2(int num){
	int temp,counter=0;
	temp = num;
	while(temp>0){     
		temp = temp/2; 
		counter += 1;  
		
	}
	return counter;
}
void f3(int num, int dig){   
	int k,c,b;
	c = num;
	for(k=1; k<=dig; k++){ //17 
		b = c%2; //1 0 0 0 1
		printf("%d",b);//1 0 0 0 1
		b = c;
		c = c/2; //8 4 2 1
	}
	printf("\n");
	
	
}
int f4(int num){
	int temp;
	temp = num;


	if(f5(num)){
		int result = f6(num);
		if(f5(result)==1){
			return 1;
		}
		else{
			return 0;
		}
					
		
	}
	else{
		return 0;
	}
	
	
}
	

int f5(int num){
	int k,ct=0;
	for(k=1;k<=num;k++){
		if(num%k==0){
			++ct;
		}
	}
	if(ct==2){
		return 1;
	}
	else{
		return 0;
	}
}
int f6(int num){
	int sum=0;
	while(num>0){
		sum += num%10;
		num = num/10;
	}
	return sum;
}
void f7(int num){
	int digit=0,k,controll=0;
	int temp;
	int c;
	temp = num;
	if(f5(temp)){
		while(temp>0){ //13
			temp = temp/10; //10
			digit +=1;//1
		}
		temp = num;
		for(k=1;k<=digit;k++){
			c = pow(10,k);
			temp = temp%c;
			if(f5(temp)){
				controll+=1;
			}
		}
		if(controll==digit){
			printf("%d is a weird prime.",num);
		}
		else{
			printf("%d is not a weird prime.",num);
		}
	}else{
		printf("%d is not a weird prime.",num);
	}
}



