#include <bits/stdc++.h>

void hanoi(int N, char A, char B, char C);

int main(){

    int N;
    std::cin>>N;
    char A='A',B='B',C='C';

    hanoi(N,A,B,C);

    return 0;

}

void hanoi(int N, char A, char B, char C){

    if(N>0){
        hanoi(N-1, A, C, B);
        std::cout<<"Move "<<A<<" to "<<C<<"\n";
        hanoi(N-1, B, A, C);
    }
}

/* --------------------------------------------------
# Implemented by Alejandro del Castillo Diaz / 01/03/2025
# Description:
# This algorithm returns an optimal solution for hanoi towers problem
# How to get the solution:
# You have to take a look to the first three cases
# Case 1:
# When you have just one disc we have to move the disc from A to C, at this point its not necessary an auxiliar tower
# Case 2:
# When you have two discs we have to move N-1 disc to B, move A to C, and move the N-1 disc from B to C, we can notice that its necessary to move N-1 disc from the first tower to the auxiliar tower, move the remaining to the destination tower and then move the N-1 discs to C
# Case 3:
# When you have three discs we have to repeat the steps of case 2, and move the N-1 discs from B to C
# From this we can infer the following pseudocode:
# We will stop when there are not more discs in the stack
# Move N-1 dics from A to B using C as auxiliar
# Move A to C
# Move N-1 discs from B to C using A as auxiliar
# --------------------------------------------------
*/
