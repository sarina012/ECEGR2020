#include<stdio.h>
#include<conio.h>

int main(){
    //Call the following functions by uncommenting the function
    SizeOfVariables();
    //IsLeapYear();
    //IsVowel();
    //ReverseNumber(); 
}

//Function 1 - Size Of Variables
void SizeOfVariables(){
//Declares various variable types
//Prints a statement of the variable's size in bytes 
    int i;
    printf("Size of Int: %d bytes\n", sizeof(i));
    short s; 
    printf("Size of Short: %d bytes\n", sizeof(s));
    char c; 
    printf("Size of Char: %d bytes\n", sizeof(c));
    unsigned int ui;  
    printf("Size of Unsigned Int: %d bytes\n", sizeof(ui));
    unsigned long int ul; 
    printf("Size of Unsigned Long Int: %d bytes\n", sizeof(ul));
    float f;
    printf("Size of Float: %d bytes\n", sizeof(f));
    double d;
    printf("Size of Double: %d bytes\n", sizeof(d));
    long double ld;
    printf("Size of Long Double: %d bytes\n", sizeof(ld));
    void *ptr; 
    printf("Size of Void: %d bytes\n", sizeof(ptr));	
}

//Function 2 - Is Leap Year
int IsLeapYear(){
	//Declares variable and user enters year to check if its a leap year
	int aYear;
	printf("Enter a year: ");
	scanf("%d", &aYear);
	//There were no leap years before 1752
	if (aYear < 1752) {
		printf("%d is not leap year.\n", aYear);
		return 0;
	}
   //Is a leap year if the entered year is divisible by 400
	if (aYear % 400 == 0) {
		printf("%d is a leap year.\n", aYear);
		return 1;
	}
	//Not a leap year if the entered year is divisible by 100
	else if (aYear % 100 == 0) {
		printf("%d is not a leap year.\n", aYear);
		return 0;
	}
   //Is a leap year if the entered year is divisible by 4
	else if (aYear % 4 == 0) {
		printf("%d is a leap year.\n", aYear);
		return 1;
	}
	//All other years are not leap years
	else {
		printf("%d is not a leap year.\n", aYear);
		return 0;
	}
}

//Function 3 - Is Vowel
int IsVowel(){
    //Declaring variable
    char aLetter;
    // Taking in a character (input) from the user
    printf("Enter a Character\n");
    scanf(" %c",&aLetter);
    printf("\nThe character that you have entered is %c", aLetter);
    getchar();
    //Checks to see if the character is in the alphabet
    if (isalpha(aLetter)==0){
		printf("\nERROR: Character not an ASCII letter \n");	    
    }
    //If the character is in the alphabet, the following checks to see if its a vowel/consonant
    else{
	    //Checks if the ascii values for the characters are vowels 'a,e,i,o,u'
	    if (aLetter==97 || aLetter==101 || aLetter==105 || aLetter==111 || aLetter==117 ||aLetter==65 || aLetter==69 || aLetter==73 || aLetter==79 || aLetter==85){
		    printf("\n%c is a vowel! \n",aLetter);
	    return 1;
	    }
	    //States that the character is a consonant since it was not a vowel
	    else{
	        printf("\n%c is a consonant! \n",aLetter);
	    return 0;
	    }
    return 0;
    }
}

//Function 4 - Reverse Number
void ReverseNumber(){
    //Declaring the variables
    long aNumber;
    int count = 0;
    int remainder;
    //User enters a value
    printf("Enter an integer: ");
    scanf("%d", &aNumber);
    //The following while loop reverses the numbers that were entered
    while (aNumber != 0) {
        remainder = aNumber % 10;
        count = count * 10 + remainder;
        aNumber /= 10;
    }
    //Printing the number
    printf("Reversed number: %d \n", count);
}

