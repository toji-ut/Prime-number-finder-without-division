#include <stdio.h>
#include <stdbool.h>

// Sieve of Eratosthenes algorithm                                                                                                                             
// Crossing out the multiples of a number starting with 2 (setting it to false)                                                                                
void sieveOfEratosthenes(bool isPrime[], int n)
{
    // Set all of the value of the array to true                                                                                                               
    for (int ii = 0; ii < n; ii++)
    {
        isPrime[ii] = true;
    }

    // 0 and 1 are not prime so make it false                                                                                                                  
    isPrime[0] = false;
    isPrime[1] = false;

    // Begin from 2 and mark true if prime and false if not prime                                                                                              
    for (int ii = 2; ii * ii < n; ii++)
    {
        if (isPrime[ii])
        {
            for (int jj = ii * ii; jj < n; jj += ii)
            {
                isPrime[jj] = false;
            }
        }
    }
}

// Print prime numbers from 1 to 999                                                                                                                           
void printPrimes(bool isPrime[], int n)
{
    printf("Prime numbers from 1 to %d:\n", n);

    for (int ii = 2; ii < n; ii++)
    {
        if (isPrime[ii])
        {
            printf("%d ", ii);
        }
    }
}

// Find the largest prime number from the array                                                                                                                
int findLargestPrime(bool isPrime[], int n)
{
    int largestPrimeFound = 0;

    for (int ii = 2; ii < n; ii++)
    {
        if (isPrime[ii])
        {
            largestPrimeFound = ii;
        }
    }

    return largestPrimeFound;
}

int main()
{
    // Initialize the boolean array of size                                                                                                                    
    // (I tried a lot of limits and this seems to be the most optimal one,                                                                                     
    // because otherwise segmentation fault)                                                                                                                   
    int MAX = 8381000;
    bool isPrime[MAX]; // Initialize the array straight to the limit, cause don’t want to resize it later
    sieveOfEratosthenes(isPrime, MAX); // Call the function to determine which numbers are prime or not                                                        

    printPrimes(isPrime, 999); // Print prime numbers from 1 to 999                                                                                            

    printf("\n");
    printf("Looking for the largest prime number for MAX = %d...\n", MAX);
    int largestPrime1 = findLargestPrime(isPrime, MAX); // Find the largest number I could find using the algorithm                                            
    printf("The largest prime number found for MAX = %d: %d\n", MAX, largestPrime1);

    return 0;
}
