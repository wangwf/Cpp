#include <iostream>
using namespace std;

int main()
{
	// declare char type varAuthor
	char * varAuthor = "Wenfeng Wang";
	
	// reference variable addr_varAuthor of our original varAuthor
	char ** addr_varAuthor = &varAuthor;
	
	printf(" test pointers and "); 
	printf("Value of our original varAuthor is %s.\n", varAuthor);
	printf("Address (reference) of our original varAuthor is %x.\n", addr_varAuthor);
	printf("Value (pointer) of our address (%x) is %s.\n", addr_varAuthor, *addr_varAuthor);
	printf("Get it?\n");


	int* pToInt=0; 
	cout<<"address of p "<<pToInt<<endl; 
	pToInt++; 
	cout<<"new p "<<pToInt<<endl; 
	return 0;
}
