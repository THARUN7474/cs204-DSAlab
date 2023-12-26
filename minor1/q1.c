#include<stdio.h>
#include<string.h>
#define MAX 100

int findstring(char* arr,char* str,char* pos ,int* posi){
	if(str==NULL){
		return 0;
	}
	int i=0;
	while(arr[i]!='\0'){
		if(arr[i]==str[0]){
         *pos=arr[i];
         *posi=i;
         int j=1;
			i++;
         if(strlen(str)==2){//for only char in str case
            return 1;
         }
			while(str[j]!='\0' && str[j]==arr[i]){
					j++;
					i++;
			}
			if(str[j]=='\0'){
				return 1;
			}
         else{
            i--;//if str[j]==arr[i] failed .....means repeated 1st char of str is present
         }
		}
		i++;
	}
	return 0;
}
int main(){
   printf("hello\n");
   char char_arr[MAX],str[MAX];char pos;int posi;

   printf("enter the string1 to be in char array\n");
   fgets(char_arr, sizeof(char_arr), stdin);
   printf("You entered: %s\n", char_arr);

   printf("enter the string2 to find in str1(char_array):\n");
   fgets(str, sizeof(str), stdin);
   printf("You entered: %s\n", str);

   int found = findstring(char_arr, str, &pos,&posi);

   if (found) {
      printf("String found at position pointing to char is %d and the char is %c \n ", posi, pos);
   } else {
      printf("String not found.\n");
   }
   return 0;
}

