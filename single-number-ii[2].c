int singleNumber(int A[], int n) {
   int one = 0, two = 0, reset;
   int i;
   for(i = 0; i < n; ++i){
       two |= (one & A[i]);
       one ^= A[i];
       reset = one & two;
       two ^= reset;
       one ^= reset;
   }
   
   return one;
}
