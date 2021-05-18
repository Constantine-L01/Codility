Task description

You are given N counters, initially set to 0, and you have two possible operations on them:

        increase(X) − counter X is increased by 1,
        max counter − all counters are set to the maximum value of any counter.

A non-empty array A of M integers is given. This array represents consecutive operations:

        if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
        if A[K] = N + 1 then operation K is max counter.

For example, given integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4

the values of the counters after each consecutive operation will be:
    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations.

Write a function:

    vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4

the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

        N and M are integers within the range [1..100,000];
        each element of array A is an integer within the range [1..N + 1].

==Solution==
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int currentMax = 0;
    int lastUpdate = 0;
    vector<int> counters(N, 0);

    for(int i = 0; i < A.size(); i++){
        int currVal = A[i];
        if(currVal == N + 1){
            lastUpdate = currentMax;            
        }
        else {
            int pos = currVal - 1;
            if (counters[pos] < lastUpdate){
                counters[pos] = lastUpdate + 1;
            }
            else {
                counters[pos]++;
            }

            if(counters[pos] > currentMax){
                currentMax = counters[pos];
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(counters[i] < lastUpdate){
            counters[i] = lastUpdate;
        }
    }
    
    return counters;
}
