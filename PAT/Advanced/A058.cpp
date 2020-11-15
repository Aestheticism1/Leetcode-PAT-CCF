#include <iostream>

using namespace std;

int main()
{
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int g3, s3, k3;
    k3 = k1+k2;
    s3 = s1 + s2 + k3 / 29;
    g3 = g1 + g2 + s3 / 17;
    printf("%d.%d.%d", g3, s3%17, k3%29);
    return 0;
}