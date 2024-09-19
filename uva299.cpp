//uva299 Train Swapping
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int testcase;
  int L, swap_num;
  int train[55];
  while( scanf( "%d", &testcase ) != EOF ){
    for( int i = 0 ; i < testcase ; i++ ){
      scanf( "%d", &L );
      for( int j = 0 ; j < L ; j++ )
        scanf( "%d", &train[j] );

      swap_num = 0;
      for( int j = 0 ; j < L ; j++ )
        for( int k = L-1 ; k > j ; k-- )
          if( train[k-1] > train[k] ){
            swap( train[k-1], train[k] );
            swap_num++;
          }
      printf( "Optimal train swapping takes %d swaps.\n", swap_num );
    }
  }
  return 0;
}