#include<stdio.h>
#include<string.h>
char str[100],pat[100],rep[100],ans[100];
int i,j,c,m,k,flag=0;
void string_match()
{
  i=m=c=j=0;
  while(str[c]!='\0')
  {
    if(str[m]==pat[i])
    {
      i++,m++;
      if(pat[i]=='\0')
      {
        flag=1;
        for(k=0;rep[k]!='\0';k++,j++)
        ans[j]=rep[k];
        i=0;
        c=m;
      }
    }
    else
    {
      ans[j]=str[c];
      j++;
      c++;
      m=c;
      i=0;
    }
  }
  ans[j]='\0';
}
void main()
{
  printf("\nenter the main string\n");
  scanf("%s",str);
  printf("\nenter the pattern string\n");
  scanf("%s",pat);
  printf("\nenter the replacement string\n");
  scanf("%s",rep);
  string_match();
  if(flag==1)
  {
  printf("The resultant string is %s",ans);
  }
  else
  { 
    printf("pattern string not found");
  }

}
