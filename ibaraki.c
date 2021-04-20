#include <stdio.h>

char  *f(char *s, int *a, int n)
{
  for(int i=0; i<n; i++)
    s[i] += a[i];
  return (s);
}

int  main()
{
  char s[] = "Hello, world!\n";

  printf("%s", s);
  printf("%s", f(s, (int[]){6,-4,8,8}, 4));
  return (0);
}
