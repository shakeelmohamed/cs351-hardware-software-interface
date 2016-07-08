#include <stdio.h>
#include <stdbool.h>

bool testInts(int a, int b, char* testname)
{
    if (!testname) {
        testname = "";
    }
    int result = a == b;
    if (!result) {
        printf("Test %s failed for a=%d b=%d\n", testname, a, b);
    }
    return result;
}

/**
 * 1.
 * 
 * Suppose we are given the task of generating code to multiply integer variable x by various
 * different constant factors K. To be efficient, we want to use only the operations +, -, <<.
 * For the following values of K, write C expressions to perform the multiplication using at
 * most three operations per expression.
 * A. K = 17:
 * B. K = -7:
 * C. K = 60:
 * D. K = -112:
 */
int oneA(int x)
{
    // A. K = 17
    int a = x << 4; // x*16
    a += x; // x*16 + x = x*17
    return a;
}
int oneB(int x)
{
    // B. K = -7:
    int b = x << 3; // x*8
    b = x - b; // (x*1 - x*8) = x*(1 - 8) = x*-7
    return b;
}
int oneC(int x)
{
    // C. K = 60:
    int c = x << 6; // x*64
    c -= x << 2; // x*64 - x*4 = x*(64 - 4) = x*60
    return c;
}
int oneD(int x)
{
    // D. K = -112: 
    int d = x << 7; // x*128
    d = (x << 4) - d; // x*16 - x*128 = x*(16 - 128) = x*-112
    return d;
}
void testOne()
{
    int cases[10] = {-10, -2, -1, 0, 1, 2, 3, 4, 5, 10};
    for (int i = 0; i < 10; i++) {
        int cur = cases[i];
        if (!testInts(oneA(cur), (cur*17), "oneA")) {
            return;
        }
        if (!testInts(oneB(cur), (cur*-7), "oneB")) {
            return;
        }
        if (!testInts(oneC(cur), (cur*60), "oneC")) {
            return;
        }
        if (!testInts(oneD(cur), (cur*-112), "oneD")) {
            return;
        }
    }
    printf("All tests passed for problem 1!\n");
}

/**
 * 2.
 * What, if anything, is wrong with the code below?
 * 
 * int test(int i, long int l) {
 *     return i == ((int)l);
 * }
 *
 * A:
 * - long int as a type is redundant, long is already 8 bytes "int" has no effect
 * - casting from long -> int can cause data loss
 */

/**
 * TODO: #3, and maybe optional material questions
 */

int main()
{
    testOne();
    long i = 0;
    printf("%lu\n", sizeof(i));
}