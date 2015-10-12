#include <stdio.h>
 
void print_length( int int_array[]);
 
int main( )
{
  int my_int_array[] = {1, 2, 3, 4, 5, 6, 7, 8};

  print_length(my_int_array);
 
  return 0;
}
 
void print_length( int int_array[])
{
  int length = sizeof int_array / sizeof int_array[0];

  printf( "Length of array = %d\n", length);
}
