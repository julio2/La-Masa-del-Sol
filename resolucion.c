#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  FILE * f;
  FILE * d;
  char buffer[100],buffer2[100],g[]="papa",*p;
  int i=0,k,j=0;
  f=fopen("ejem.txt","r");
  d=fopen("out.txt","w");
  fgets(buffer,100,f);
  printf("%s\n",buffer);
  for(i=0;buffer[i];i++){
    k=(int)buffer[i]+(int)g[j];
    if(k>255)k-=255;
    fprintf(d,"%c(%i) + %c(%i) = %c(%i)\n",buffer[i],buffer[i],g[j],g[j],k,k);
    buffer2[i]=k;
    j++;
    if(!g[j])j=0;
  }
  buffer2[i]=0;
  fprintf(d,"\n%s\n",buffer2);
  fclose(f);
  fclose(d);
  return 0;
}
