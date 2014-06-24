// I used sieve of eratosthenes for the algorithm
// you can find more about it here http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// I used online compiler for creating this C++ file - http://ideone.com/
// Created by : Wilson Sumanang - 11/1/2012

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(void)
{
	// used unsigned int instead of signed because of size issue
	unsigned int upperLimit, i, j; 
	double sum = 0;

	cout << "Enter limit for primes ( <= 10 000 000 ) : ";
	cin >> upperLimit;
    
	cout << "\n";
	
	upperLimit = upperLimit + 1;
    
	// allocate memory for the table and zero-ed everything
	bool *primes = (bool*)calloc(upperLimit, sizeof(bool));

	// calculate the square root of n
	unsigned int squareRoot = sqrt(upperLimit);
    
	// ALGORITHM STARTS
	// initially all set to true
	for(i = 0 ; i <= upperLimit ; i++) {
		primes[i] = true;
	}
	
	// start working on the table by eliminating all the multiple
	for (i = 2; i <= squareRoot; i++) {
		if (primes[i]) {
			for (j = i * i ; j < upperLimit ; j += i) {
				primes[j] = false;
			}
		}
	}
	
	// print number on table that is primes and sum it
	// you can also print if you want
	// cout << "List of Primes : \n";
	for (i = 2; i < upperLimit ; i++) {
		if (primes[i]) {
			sum += i;
			//cout << i << " ";
		}
	}
	// ALGORITHMS END
	
	cout.precision(0); // to print all number (without being casted to exponential)
	cout << "Sum of prime number from 1 to " << upperLimit - 1 << " : " << fixed << sum << "\n";
	
	return 0;
}