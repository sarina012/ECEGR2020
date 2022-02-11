#include <stdio.h>
#include <stdlib.h>
FILE *newFilePtr;

long Factorial(long num);
int IsPalidrome(long value);
int HighestBitSet(int value);
void ReverseIt(void);
void ReverseItAgain(void);
void Pyramid(int lines);

int main(){
/*//Part A - Factorial Function
	long value_fact;
	for(int i=0;i<5;i++){
		printf("Enter a number: ");
		scanf(" %ld", &value_fact);
		printf("The factorial of %ld is: %ld \n\n", value_fact, Factorial(value_fact));
	}	*/

/*//Part B - Palidrome Function
	long counter_pal;
	for(int i=0;i<5;i++){
		printf("Enter a number: ");
		scanf(" %ld", &counter_pal);
		if(IsPalidrome(counter_pal)){
			printf("%ld is a palidrome\n\n", counter_pal);
		}
		else{
			printf("%ld is not a palidrome\n\n", counter_pal);
		}
	}
    return 0;*/
	
/*//Part C - Highest Bit Function
	for(int i=0;i<5;i++){
		int value, num1;
		printf("Enter the value: ");
		scanf("%d", &value);
		printf("Value = %d  ", value);      
		num1 = HighestBitSet(value);
		if(num1 <= -1){
		printf("No bit is set\n");
		}
		else{
			printf("Highest bit set = %d\n", num1);
		}
		printf("\n");
	}
    return 0;*/
	
//Part D - Reverse It Function
//ReverseIt();

//Part E - Reverse It Again Function
//ReverseItAgain();

/*//Part F - Pyramid Function
	int totalLines;
	printf("Enter a number: \n");
	scanf(" %d", &totalLines);
	Pyramid(totalLines);*/
}

//Factorial Function
long Factorial(long value){
    long factorialValue = 1;
    while(value > 0){
        factorialValue *= value;
        value--;
    }
    return factorialValue;
}

//IsPalindrome Function
int IsPalidrome(long value){
	long enteredNumber = value;
	long temp = 0; 
	long reversedNumber = 0;
	while(enteredNumber != 0) 
	{
		reversedNumber *= 10;
		temp = enteredNumber%10;
		reversedNumber += temp;
		enteredNumber /= 10;
	}
	return reversedNumber == value; 
}

int HighestBitSet(int value){
    long binary = 0;
    int remainder, num1 = -1, num2 = 1, i = 0;
	while(value != 0){
		remainder = value % 2;
		if(remainder == 1){
			num1 = i;
		}
		binary = binary + remainder * num2;
		num2 = num2 * 10;
		value = value / 2;
		i++;
    }
	printf("Binary = %ld  ", binary);
	return num1;
}

//Reverse It Function
void ReverseIt (void){
	newFilePtr = fopen ("ReverseItFunction.txt", "w+");
	float input1;
	float input2;
	float input3;
	float input4;
	float input5;
	printf("\nEnter 1st float value: ");
	scanf(" %f", &input1);
	fprintf(newFilePtr,"%.2f ", input1);
	printf("Enter 2nd float value: ");
	scanf(" %f", &input2);
	fprintf(newFilePtr,"%.2f ", input2);
	printf("Enter 3rd float value: ");
	scanf(" %f", &input3);
	fprintf(newFilePtr,"%.2f ", input3);
	printf("Enter 4th float value: ");
	scanf(" %f", &input4);
	fprintf(newFilePtr,"%.2f ", input4);
	printf("Enter 5th float value: ");
	scanf(" %f", &input5);
	fprintf(newFilePtr,"%.2f\n", input5);
	
	printf("\nFloats in Reverse Order: \n");
	printf("%.2f\n", input5);
	fprintf(newFilePtr,"%.2f ", input5);
	printf("%.2f\n", input4);
	fprintf(newFilePtr,"%.2f ", input4);
	printf("%.2f\n", input3);
	fprintf(newFilePtr,"%.2f ", input3);
	printf("%.2f\n", input2);
	fprintf(newFilePtr,"%.2f ", input2);
	printf("%.2f\n", input1);
	fprintf(newFilePtr,"%.2f ", input1);
	fclose(newFilePtr);
}

//Reverse It Again Function
void ReverseItAgain(void){
	float value;
	newFilePtr = fopen("ReverseItFunction.txt", "r");
	printf("\nReverse It Again Function: \n");
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f\n",value);
	
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f ",value);
	fscanf(newFilePtr,"%f",&value);
	printf("%f \n",value);
	fclose(newFilePtr);
}

//Pyramid Function
void Pyramid(int lines){
	newFilePtr = fopen("Pyramid.txt", "w+");
	int temp = lines;
	int line = 1;
	for(int i=line; i<=lines; i++){ 
		for(int j=lines-i; j>0; j--){ 
			printf(" ");
			fprintf(newFilePtr, " ");
		}
		printf("*");
		fprintf(newFilePtr, "*");
		for(int j=i-1;j>0;j--){ 
			printf("*");
			fprintf(newFilePtr, "*");
			printf("*");
			fprintf(newFilePtr, "*");
		}
		printf("\n"); 
		fprintf(newFilePtr, "\n");
	}
	return;
	fclose(newFilePtr); 
}


