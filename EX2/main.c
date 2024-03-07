#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE *fp;
   int a1[] = {0, 1, 2}, a2[3];
   char b1[] = "ABC", b2[3];
   float c1[] = {1.1, 1.2, 1.3}, c2[3];
   
   fp = fopen("a.bin", "wb+");
   fwrite(a1, sizeof(int), 3, fp);
   fwrite(b1, sizeof(char), 3, fp);
   fwrite(c1, sizeof(float), 3, fp);    //在最後面
   fseek(fp, 0, SEEK_SET);  //移動回最開頭
   
   fread(a2, sizeof(int), 3, fp);
   fread(b2, sizeof(char), 3, fp);
   fread(c2, sizeof(float), 3, fp);
   
   for (int i = 0; i < 3; i++){
       printf("%d\t", a1[i]);
   }
   printf("\n");
   for (int i = 0; i < 3; i++){
       printf("%c\t", b1[i]);
   }
   printf("\n");
   for (int i = 0; i < 3; i++){
       printf("%f\t", c1[i]);
   }
   printf("\n");
   
   fclose(fp);
   
}