#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum[10]={0,0,0,0,0,0,0,0,0};

void * sum_array(void *arg)
{
   int i=0;
   int count=0;
   int value=(int) arg;
 
   for(i=value;i<100+value;i++)
   {
      count=count+1;
   }
   sum[value/100]=count;
}
  
int main()
{
  int array[1000];
  int i=0;
  
  for(i=0;i<1000;i++)
  {
     array[i]=i+1;
  }


  pthread_t threads[10];
  int value=0;
   
  for(i=0;i<10;i++)
  {
    pthread_create(&threads[i],NULL,sum_array,(void*)array[value]);
    value=value+100;
  }

  for(i=0;i<10;i++)

    pthread_join(threads[i],NULL);

  int total=0;
  
  for(i=0;i<10;i++)
    total=total+sum[i];
 
  printf("%d",total);
  return 0;
}
