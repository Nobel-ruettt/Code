#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1000000
const ll inf = 2000000000; // a large value as infinity
ll n,value; // the number of items in the sequence
ll Sequence[maxi]; // the sequence of llegers
ll L[maxi]; // L[] as described in the algorithm
ll I[maxi]; // I[] as described in the algorithm
ll LisSequence[maxi];
void takeInput()
{
    ll i;
    for(i=0;; i++)
    {
        if(scanf("%lld",&value)!=1)
        {
            break;
        }
        Sequence[i]=value;
    }
    n=i;
}
ll LisNlogK()   // which runs the NlogK LIS algorithm
{
    ll i; // auxilary variable for iteration
    I[0] = -inf; // I[0] = -infinite
    for(i=1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite
    ll LisLength = 0; // keeps the maximum position where a data is inserted
    for( i = 0; i < n; i++ )   // iterate left to right
    {
        ll low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high )   // binary search to find the correct position
        {
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        L[i]=low;
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }
    return LisLength; // return the result
}
void findSequence(ll maxLength )   // finds a valid sequence
{
    ll i, j; // variable used for iteration
    // at first find the position of the item whose L[] is maximum
    i = 0;
    for( j = 1; j < n; j++ )
    {
        if( L[j] > L[i] )
            i = j;
    }
    // initialize the position in LisSequence where the items can be added.
    // observe that the data are saving from right to left!
    ll top = L[i] - 1;
    // insert the item in i-th position to LisSequence
    LisSequence[top] = Sequence[i];
    top--; // is decreasing such that a new item can be added in a new place
    // now find the other valid numbers to form the sequence
    for( j = i - 1; j >= 0; j-- )
    {
        if( Sequence[j] < Sequence[i] && L[j] == L[i] - 1 )
        {
            // we have found a valid item so, we will save it
            i = j; // as in our algorithm
            LisSequence[top] = Sequence[i]; // stored
            top--; // decreased for new items
        }
    }
    // so, we have got the sequence, now we want to print it
    for( i = 0; i < maxLength; i++ )
    {
        printf("%lld\n", LisSequence[i]);
    }
}
int main()
{
    takeInput();
    ll result = LisNlogK();
    printf("%lld\n-\n", result);
    findSequence(result);
    return 0;
}
