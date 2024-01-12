#include <stdio.h>
#include <string.h>

int main()
{
    char c[1001]
    while (gets(c)!=NULL){  
        int i,j,temp,ans=0;
        int cnt[128] = {0},b[128];

        for(i = 0; c[i]; i++){
            cnt[c[i]]++;
        }

        for (i=0;i<128;i++){
            if (cnt[i]>0){
                b[ans++]=i;
            }
        }
        for (i=0;i<ans-1;i++){
            for(j=0;j<ans-i-1;j++){
                if(cnt[b[j]]>cnt[b[j+1]] || (cnt[b[j]]==cnt[b[j+1]] && b[j]<b[j+1])){
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        }
        for(i=0;i<ans;i++){
            printf("%d %d\n",b[i],cnt[b[i]]);
        }
      printf("\n");
    }  
    return 0;
}