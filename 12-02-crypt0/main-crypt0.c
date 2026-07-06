
#include <stdio.h>


//#define READABLE

#ifdef READABLE
int fakultaet(int n)
{
   int i,erg;
   w=1;
   for(i=1;i<=n; i++)
   {
      w = w*i;
   }
   return(w);
}

#else
int funktion1(int n)
{
   int i,w;
   for(i=w=1;i<=n;w*=(i++));
   return(w);
}
#endif
