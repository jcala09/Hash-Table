#include <stdio.h>
#define mod 10

//
// AUTHOR: Jerome Cala
// FILENAME: Problem1.c
// SPECIFICATION: Quadratic Probing
// FOR: CS 2413 Data Structure Section 502

// function declaration
int hashi(int n);
void insertval(int hash[],int n);
int probe(int hash[],int n);
void searchval(int hash[],int n);
int main(void) {
  int H[10]= {0};

	insertval(H,27);
	insertval(H,6);
	insertval(H,9);
	insertval(H,32);
	insertval(H,82);
	insertval(H,12);
	insertval(H,56);

	for(int i=0; i<10; i++)
	printf("%d \t",H[i]);
  

	searchval(H,12);

	searchval(H,69);
}

//
// NAME: hashi
// INPUT Param.: int n
// OUTPUT Param.: returns mod index
// PURPOSE: returns the index
int hashi(int n)
{
	return n%mod;
}

//
// NAME: probe
// INPUT Param.: hash table, int n
// OUTPUT Param.: index free space
// PURPOSE:functions probes quadratically to find free space in hash table
int probe(int hash[],int n)
{
	int index= hashi(n);
	int i=0;
	while(hash[index+i%mod]!=0)
	{
		i++; // add i 
		i=i*i;// quadratic probe
	}
	return (index+i)%mod;
}

//
// NAME: insertval
// INPUT Param.: hash table, int n
// OUTPUT Param.: none
// PURPOSE:functions inserts value in hash
void insertval(int hash[],int n)
{
int index=hashi(n);

if(hash[index]!=0)
{
	index= probe(hash,n); // find index if its not empty
}
hash[index]=n; // if it is then just slap it in there
}

//
// NAME: searchval
// INPUT Param.: hash table, int n
// OUTPUT Param.: none
// PURPOSE:functions searches for value
void searchval(int hash[],int n)
{
	int index= hashi(n);
	int i=0;

	while(hash[index+i%mod]!=n)
	{
		i++; // quadratic probing
		i=i*i;
		if(i>100)
		break;
	}

index= (index+i)%mod;

if(hash[index]==n)
printf("\n%d is found\n",n);
if(hash[index]!=n)
	printf("\n%d is not found\n",n);

}
