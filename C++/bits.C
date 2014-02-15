
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

