#include<stdio.h>
void main()
{ 
  int a[9][9],d[9][10],i,j,s=0,m,n,z,k,su,no,po;
  long int b[9],c[9];
  long int co;
 for(i=0;i<9;i++)
   {
     for(j=0;j<9;j++)
     {
       a[i][j]=0;
     }
   }
  printf("ENTER THE SUDOKU PROBLEM:\n");
  printf("ENTER THE NUMBER:");
  scanf("%d",&z);
  for(i=0;i<9;i++)
  {
    b[i]=1;
    c[i]=1;
    d[i][0]=10;
    for(j=1;j<10;j++)
    {
      d[i][j]=j;
    }
  }
  while(z!=0)
  {
    s=s+1;
    printf("ENTER THE POSITION:");
    scanf("%d%d",&i,&j);
    a[i][j]=z;
    if((z==4)||(z==7))
    {
      z=(2*z)+15;
    }
    else
    {
      z=(2*z)+1;
    }
    b[i]=b[i]*z;
    c[j]=c[j]*z;
    m=(i/3)*3+(j/3);
    n=d[m][0];
    for(k=1;k<n;k++)
    {   
      if(d[m][k]==a[i][j])
      { 
        d[m][k]=d[m][n-1];
        d[m][0]=d[m][0]-1;

        break;
      }
      
    }  
    printf("ENTER THE NUMBER:");
    scanf("%d",&z);
  }
  while(s<81)
  { 
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
      {
        su=0;
        if(!(a[i][j]))
        {
          m=(i/3)*3+(j/3);
          n=d[m][0];

          for(k=1;k<n;k++)
          {
            if((d[m][k]==4)||(d[m][k]==7))
            {
              z=(2*d[m][k])+15;
            }
            else
            {
              z=(2*d[m][k])+1;
            }
            co=(b[i]*c[j])%z;
            if(co!=0)
            { 
              su=su+1;
              if(su>1)
              {
                break;
              }
              po=k;
              no=d[m][k];
            }
            
          }
          if(su==1)
            {
              a[i][j]=no;
              if((no==4)||(no==7))
              {
                z=(2*no)+15;
              }
              else
              {
                z=(2*no)+1;
              }
              
              b[i]=b[i]*z;
              c[j]=c[j]*z;
              d[m][po]=d[m][n-1];
              d[m][0]=n-1;
              s=s+1;
            }
        }
      }
    }
  }
   for(i=0;i<9;i++)
   {
     for(j=0;j<9;j++)
     {
       printf("%d\t",a[i][j]);
     }
     printf("\n"); 
   }
}

  
