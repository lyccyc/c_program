#include <stdio.h>
#include <string.h>

int main()
{
    char num[c] = {};
    char cont[c] = {};
    gets(num);
    for(int i = 0;i < strlen(num);i++)
    {
        if((strlen(num)-i)==4)
        {
            for(int j = 0;j < num[i]-48;j++)
                strcat(cont,"M");
        }
        else if((strlen(num)-i)==3)
        {
            if(num[i]>52)
            {
                if(num[i]==57)
                    strcat(cont,"CM");
                else
                {
                    strcat(cont,"D");
                    for(int j = 0;j < num[i]-53;j++)
                        strcat(cont,"C");
                }
            }
            else if(num[i]==52)
                strcat(cont,"CD");
            else
                for(int j = 0;j < num[i]-48;j++)
                    strcat(cont,"C");
        }
        else if((strlen(num)-i)==2)
        {
            if(num[i]>52)
            {
                if(num[i]==57)
                    strcat(cont,"XC");
                else
                {
                    strcat(cont,"L");
                    for(int j = 0;j < num[i]-53;j++)
                        strcat(cont,"X");
                }
            }
            else if(num[i]==52)
                strcat(cont,"XL");
            else
                for(int j = 0;j < num[i]-48;j++)
                    strcat(cont,"X");
        }
        else if((strlen(num)-i)==1)
        {
            if(num[i]>52)
            {
                if(num[i]==57)
                    strcat(cont,"IX");
                else
                {
                    strcat(cont,"V");
                    for(int j = 0;j < num[i]-53;j++)
                        strcat(cont,"I");
                }
            }
            else if(num[i]==52)
                strcat(cont,"IV");
            else
                for(int j = 0;j < num[i]-48;j++)
                    strcat(cont,"I");
        }
    }                        
    printf("%s",cont);
    return 0;
    
}