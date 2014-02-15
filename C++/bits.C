
//using bitwise operation
/*
 & and
 ^ XOR
 | OR
 >>  right shift == division by 2^shift
 <<  left shift  == multiplication by 2^shift
 */

int Add(int a, int b){
  if(b==0) return a;
  int sum, carry;
  sum = a ^ b; // XOR,
  carry= (a&b) <<1; //

  return Add(sum, carry);
}

//int Add(int a, int b){  return b? Add( a^b, (a&b)<<1): a;}

int minus(int a, int b){//add a with b's 2's complement
  return add(a, add(~b,1));}


int multiply(int a, int b){
  int ans=0;
  for(int i=01; i; i<<=1, a<<=1)
    if(b&i) ans += a;
  return ans;
}


int divi(int dividend, int divisor){

  int sign=1;

}

