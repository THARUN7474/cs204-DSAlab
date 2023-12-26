// #include<stdio.h>
// #include<string.h>
// #define MAX 100
// // int main(){
// //    char str[10]="tharun";
// //    printf("hello");
// //    printf("%c",str[1]);
// //    return 0;
// // }
// int main(){
//    printf("hello follow along\n");
//    char char_arr[MAX],str[MAX];char pos;; // Assuming a maximum input length of 99 characters

//    printf("enter the string1 to be in char array\n");
//    fgets(char_arr, sizeof(char_arr), stdin);
//    printf("You entered: %s\n", char_arr);

//    printf("enter the string2 to find in str1(char_array):\n");
//    fgets(str, sizeof(str), stdin);
//    printf("You entered: %s\n", str);

//    printf("%c and %c",char_arr[1],str[1]);
//    return 0;
// }
#include <stdio.h>

int findString(const char* arr, const char* str, char** pos) {
    if (*str == '\0') {
        // An empty string is always considered found at the start of arr
        *pos = (char*)arr;
        return 1;
    }

    while (*arr != '\0') {
        const char* arr_ptr = arr;
        const char* str_ptr = str;

        // Compare each character of arr and str
        while (*str_ptr != '\0' && *arr_ptr == *str_ptr) {
            arr_ptr++;
            str_ptr++;
        }

        // If we reached the end of str, it means we found it in arr
        if (*str_ptr == '\0') {
            *pos = (char*)arr;
            return 1;
        }

        arr++;
    }

    return 0; // String not found
}

int main() {
    const char arr[] = "This is a sample string.";
    const char str[] = "sample";
    char* pos;

    int found = findString(arr, str, &pos);

    if (found) {
        printf("String found at position: %ld\n", pos - arr);
    } else {
        printf("String not found.\n");
    }

    return 0;
}

int findstring(char* arr,char* str,char* pos){
   int i,j,k,c,l1,l2;
   l1=strlen(*arr);
   l2=strlen(*str);
   i=0;
   for(int i=0;i<l1;i++){
      j=0;
      k=match(str[i],arr[j]);
      if(k==1){
         c++;
         i++;
         j++;
         match(str[i],arr[j]);
      }
   }
   while(i<l1 && j<l2){
      if(str[i]==arr[j]){
         i++;
         j++;
      }
      else{
         j++;
      }
   }
}
// int findstring(char* arr,char* str,char* pos){
//    if (str == '\0') {//if string is empty case so it will be 1st case
//       pos = (char*)arr;
//       return 1;
//    }
//    while (arr != '\0') {
//       const char* ptr_toarr = arr;
//       const char* ptr_tostr = str;
//       while (ptr_tostr != '\0' && ptr_toarr == ptr_tostr) {
//          ptr_toarr++;
//          ptr_tostr++;
//       }
//       if (ptr_tostr == '\0') {//if str is matched in char arr
//          *pos = (char*)arr;
//          printf("%d\n",pos);
//          printf("%d\n",*pos);
//          return 1;
//       }
//       arr++;
//    }
//    return 0;//not found case
// }
#include<stdio.h>
#include<string.h>
#define MAX 100

int findstring(char* arr,char* str,char* pos ,int* posi){
	if(str==NULL){
		return 0;
	}
   printf("%s\t",arr);
   printf("%s\t",str);
   printf("%d\n",strlen(arr));
   printf("%d\n",strlen(str));
	int i=0;
   printf("%c\n",str[0]);
   printf("%c\n",str[1]);
	while(arr[i]!='\0'){
		if(arr[i]==str[0]){
         *pos=arr[i];
         *posi=i;
         int j=1;
         printf("\n%d\n",i);
			i++;
         printf("%c and %c\n",arr[i],str[j]);
         if(str[j]==' '){
            // pos=(char*)arr;
				return 1;
         }
         printf("%d\n",strlen(str));
         if(strlen(str)==2){
            return 1;
         }
			while(str[j]!='\0' && str[j]==arr[i]){
					j++;
					i++;
			}
			if(str[j]=='\0'){
            // pos=(char*)arr;
				return 1;
			}
         else{
            i--;
         }
		}
      printf("%d\t",i);
      printf("%c\t",arr[i]);
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

   int found = findstring(char_arr, str, &pos, &posi);

   if (found) {
      printf("String found at position pointing to char is %d and the char is %c \n ", posi, pos);
   } else {
      printf("String not found.\n");
   }
   return 0;
}

