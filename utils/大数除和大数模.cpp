#include <iostream>
#include <cstring>

using namespace std;

const int L = 110;

/*
@brief sub of two numbers reversely restored in arrays, 123 => [3,2,1]
@param *a: pointer to array a
@param *b: pointer to array b
@param La: length of array a
@param Lb: length of array b
@return type: int
@return length of a after a - b
*/
int sub(int *a, int *b, int La, int Lb){
    int i;
    if(La < Lb)
        return -1;

    if(La == Lb){
        for(i = La-1; i >= 0; i--)
            if(a[i] > b[i])
                break;
            else if(a[i] < b[i])
                return -1;
    }

    // a >= b, so do a - b
    for(i = 0; i < Lb; i++){
        a[i] -= b[i];
        if(a[i] < 0){
            a[i] += 10;
            a[i+1]--;
        }
    }

    // return length of a after subtraction
    for(i = La-1; i >= 0; i--)
        if(a[i])
            return i+1;
    
    return 0;
}

/*
@brief division of two big numbers
@param n1: dividend
@param n2: divisor
@param option: 1 or 2
@return quotient, when option == 1
@return remainder, when option == 2
*/
string div(string n1, string n2, int option){
    string s, v;
    int a[L], b[L], r[L], i;
    int La = n1.size(), Lb = n2.size();
    fill(a, a+L, 0); fill(b, b+L, 0); fill(r, r+L, 0);
    // string n1 => array a, reversely
    for(i = La - 1; i >= 0; i--)
        a[La-1-i] = n1[i] - '0';
    // string n2 => array b, reversely
    for(i = Lb - 1; i >= 0; i--)
        b[Lb-1-i] = n2[i] - '0';
    
    if(La < Lb || (La == Lb && n1 < n2)){
        if(option == 1)
            return "0";
        else
            return n1;
    }

    // enlarge b to the same size of a
    // sub from b * 10^(La-Lb)
    int digit_diff = La - Lb;
    if(digit_diff > 0){
        for(i = La - 1; i >= 0; i--)
            if(i >= digit_diff)
                b[i] = b[i - digit_diff];
            else
                b[i] = 0;
    }
    Lb = La;

    // sub from b * 10^(La-Lb) => ... => b
    int temp;
    for(i = 0; i <= digit_diff; i++){
        while((temp = sub(a, b+i, La, Lb-i)) >= 0){
            La = temp;
            r[digit_diff - i]++;
        }
    }

    // carry of result array r
    for(i = 0; i < digit_diff; i++){
        if(r[i] >= 10){
            r[i+1] += r[i] / 10;
            r[i] %= 10;
        }
    }

    // quotient: array r => string s
    while(!r[i]) i--;
    while(i >= 0){
        // assert(r[i] >= 0 && r[i] <= 9);
        s += r[i--] + '0';
    }

    // remainder: array a => string v
    i = La - 1;
    while(i >= 0){
        assert(a[i] >= 0 && a[i] <= 9);
        v += a[i--] + '0';
    }
    if(v.empty()) v = "0";

    if(option == 1)
        return s;
    else
        return v;
}

int main(){
    string a, b;
    while(cin >> a >> b){
        // quotient
        cout << div(a, b, 1) << endl;
        // remainder
        cout << div(a, b, 2) << endl; 
    }

    return 0;
}