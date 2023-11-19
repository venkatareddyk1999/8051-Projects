
#include "delay.h"




void delay(unsigned int sec )
{
int i ,j ;
for(i=0;i<sec;i++)
  for(j=0; j<1275; j++);
}