#include <stdio.h>
#include <string.h>

typedef struct {
  char integer[1000];
  char decimal[1000];
} DeciVar;

// Function to add two DeciVar values
DeciVar addDeciVars(DeciVar num1, DeciVar num2) {
    DeciVar result;

    int len1 = strlen(num1.decimal);
    int len2 = strlen(num2.decimal);
    int maxlen=len1;
    int sum,carry = 0;
    int digital1,digital2;
    if(len1<len2){
        maxlen=len2;
    }
    //小數點
    for(int i=maxlen-1;i>=0;i--){
        if(i<len1){
            digital1=num1.decimal[i]-'0';
        }
        else{
            digital1=0;
        }
        if(i<len2){
            digital2=num2.decimal[i]-'0';
        }
        else{
            digital2=0;
        }

        sum=digital1+digital2+carry;
        sum=sum%10;
        result.decimal[i]=sum+'0';
        carry=sum/10;
    }
        
    //整數
    len1=strlen(num1.integer);
    len2=strlen(num2.integer);
    if(len1<len2){
        maxlen=len2;
    }
    maxlen=len1;
    if(len1<len2){
        maxlen=len2;
    }

    for(int i=0;i<maxlen;i++){
        if(i<len1){
            digital1=num1.integer[i]-'0';
        }
        else{
            digital1=0;
        }
        if(i<len2){
            digital2=num2.integer[i]-'0';
        }
        else{
            digital2=0;
        }
        sum=digital1+digital2+carry;
        sum=sum%10;
        result.integer[i]=sum+'0';
        carry=sum/10;
    }

    return result;
}

int main(){
    DeciVar num1, num2, result;

    scanf("%s.%s", num1.integer,num1.decimal);

    scanf("%s.%s", num2.integer,num2.decimal);

    // Add the two decimal values
    result = addDeciVars(num1, num2);

    // Print the result
    printf("%s.%s\n", result.integer, result.decimal);

    return 0;
}
