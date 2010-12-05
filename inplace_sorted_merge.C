// phone interview with facebook November 2010

#include <stdio.h>

void inplace_merge(int *a, int *b, size_t n)
{
   size_t ai = n, bi = n, oi = 2*n; // point to +1 element in order to deal with unsigned quantity
   // if bi == 0, we are done because rest of a element are in place
   // if ai == 0, we may not be done, because we still have rest of b to copy
   while (bi > 0 && ai > 0) {
     if (b[bi-1] > a[ai-1]) {
       a[oi-1] = b[bi-1];
       --bi;
     } else {
       a[oi-1] = a[ai-1];
       --ai;
     }
     --oi;
   }
   
   for (; bi > 0; --bi, --oi) {
     a[oi-1] = b[bi-1];
   }
}

void print_array(const char *label, int *a, size_t a_sz)
{
  printf("%s:",label);
  for (size_t i = 0; i < a_sz; ++i) {
    printf(" %d",a[i]);
  }
  printf("\n");
}

void test_run(int *a, int *b, size_t n)
{
  printf("\n");
  print_array("a",a,n);
  print_array("b",b,n);
  inplace_merge(a,b,n);
  print_array("o",a, 2*n);
  printf("\n");
}

int main()
{
   int a[10];
   int b[5];
   size_t n = 1;

   n = 1; a[0] = 0; b[0] = 1;
   test_run(a,b,n);

   n = 1; a[0] = 1; b[0] = 0;
   test_run(a,b,n);

   n = 3; 
   a[0] = 0; a[1] = 1; a[2] = 2;
   b[0] = 3+0; b[1] = 3+1; b[2] = 3+2;
   test_run(a,b,n);

   b[0] = 0; b[1] = 1; b[2] = 2;
   a[0] = 3+0; a[1] = 3+1; a[2] = 3+2;
   test_run(a,b,n);

   a[0] = 0; a[1] = 5; a[2] = 6;
   b[0] = 2; b[1] = 3; b[2] = 4;
   test_run(a,b,n);

   b[0] = 0; b[1] = 5; b[2] = 6;
   a[0] = 2; a[1] = 3; a[2] = 4;
   test_run(a,b,n);
}
