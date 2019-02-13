/*
Count the number of prime numbers less than a non-negative number, n.
*/

/* This solution uses the Sieve of Eratosthenes*/

int countPrimes(int n) {
    // vector that holds list of primes
    vector<bool> primes;
    
    // mark 0 and 1 as false
    primes.push_back(false);
    primes.push_back(false);
    
    // mark numbers 2 to n-1 as true
    for (int i = 2; i < n; i++)
    {
        primes.push_back(true);
    }
    
    // go thru array and mark non-primes
    for (int p = 2; p < n; p++)
    {
        if (primes[p] == true)
        {
            // start at p+p because we don't want to mark p
            // increment in p to get to multiples of p
            for (int j = p+p; j < n; j += p)
            {
                primes[j] = false;
            }
        }
    }
    
    // count the indices marked as true to get number of primes
    int count = 0;
   
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i])
            count++;
    }
    
    return count;
}