/* 
 * CSE 351 HW1 (Data Lab )
 * 
 * Shakeel Mohamed
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this homework by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   Use the dlc compiler to check that your solutions conform
 *   to the coding rules.
 */


#endif
// Rating: 1
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /** Invert both values then | them to isolate the &
   * values as 0s. Invert that result to get the & value.
   */
  int xPrime = ~x;
  int yPrime = ~y;
  int orOfPrimes = xPrime | yPrime;
  return ~orOfPrimes;
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /**
   * TODO: explain this :)
   * ~(~x & ~y) & ~(x & y)
   */
  int and = x & y;
  int xPrime = ~x;
  int yPrime = ~y;
  int andOfPrimes = xPrime & yPrime;
  int andOfPrimesPrime = ~andOfPrimes;
  int andPrime = ~and;
  return andOfPrimesPrime & andPrime;
}
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 * and the rest set to 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) {
  /**
   * goal: 01001001 00100100 10010010 01001001 (1227133513 in decimal)
   * Start with 73, the first byte of data 01001001,
   * shift it over 9 bits to "clear" it to the next
   * trio of 3 bits (every 3 bits is a 1). Then,
   * apply the | operator to fill in the next byte
   * of data. Repeat 3 times
   */
  int start = 73; // The first byte of data: 01001001
  int a1 = start << 9;
  int a2 = a1 | start;
  int a3 = a2 << 9;
  int a4 = a3 | start;
  int a5 = a4 << 9;
  int a6 = a5 | start;
  return a6;
}
// Rating: 2
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  // failing cases:
  // fitsBits(2147483647[0x7fffffff],31[0x1f]) = 01111111 11111111 11111111 11111111
  // fitsBits(2147483647[0x7fffffff],32[0x20])
  // TODO: the negative values are tricky
  int withoutNBits = x >> n;
  int inFormation = withoutNBits << n;
  printf("%d %d %d\n", x, n, inFormation);
  return !inFormation;
  // return 2;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  /**
   * Isolate 2 values, the signed bit and bool representation of x.
   * From there, determine the polarity then clean up for the 0 case.
   */
  // TODO: reduce to 10 ops, 12 currently
  
  int hasLength = !!x;
  int signedBit = x >> 31 & 1;
  int negatedSB = ~signedBit + 1;
  int negativeOne = -1;
  int polarity = (negatedSB & negativeOne) + (~negatedSB & 1);
  int xorVal = hasLength ^ polarity;
  int xorvalInc = xorVal + 1;
  return xorvalInc & polarity;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  // Compute how many bits left/right need to be shifted from the number of bytes
  // (n*8). Right shift x by n*8 bits to move the byte we want to the LSB position.
  // Use & with the 0xFF mask to isolate those values (zero out the non-LSB bits).
  int numBits = n << 3; // multiply by 8
  int shifted = x >> numBits;
  int masked = shifted & 0xFF;
  return masked;
}
// Rating: 3
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // TODO: lookup the definition of this
  // 10000111 01100101 01000011 00100001
  // 00001000 01110110 01010100 00110010
  // int signedBit = (x >> 31) << 31;
  // int magnitude = (x << 1) >> 1;
  // int result = magnitude >> n;
  // result = signedBit | result; // restore the signed bit...

  return 2;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  return 2;
}
// Rating: 4
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return 2;
}
// Extra Credit: Rating: 3
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // TODO: this should work... but there's an infinite loop
  // int xAsBool = !!x;
  // int negated = ~xAsBool + 1;
  // int result = (negated & y) + (~negated & z);
  
  // printf("%d %d %d %d\n", x, y, z, result);
  // return result;
  return 2;
}
// Extra Credit: Rating: 4
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  // There can only 0 bits on, or 1 if it's not the signed bit
  int signedBit = x >> 31 & 1;
  // x<0 ? 0 : 1 // 0 it's negative, no hope
  
  return 2;
}
