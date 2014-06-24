// A string is a palindrome if it has exactly the same sequence of characters when read left-to-right as it has when read right-to-left. For example, the following strings are palindromes:
//
// "kayak", "codilitytilidoc", "neveroddoreven". A string A is an anagram of a string B if A can be obtained from B by rearranging the characters. For example, in each of the following pairs one string is an anagram of the other:
//
// "mary" and "army", "rocketboys" and "octobersky", "codility" and "codility". Write a function:
//
// int isAnagramOfPalindrome(char *S);
//
// that, given a non-empty string S consisting of N characters, returns 1 if S is an anagram of some palindrome and returns 0 otherwise.
//
// Assume that:
//
// N is an integer within the range [1..100,000]; string S consists only of lower-case letters (a-z). For example, given S = "dooernedeevrvn", the function should return 1, because "dooernedeevrvn" is an anagram of the palindrome "neveroddoreven". Given S = "aabcba", the function should return 0.
//
// Complexity:
//
// expected worst-case time complexity is O(N); expected worst-case space complexity is O(1) (not counting the storage required for input arguments).
//
// This solution relies on the following facts:
//
// A string is an anagram of a palindrome if and only if at most one character appears an odd number of times in it.
//
// The specification stated that the input can only contain the 26 lowercase letters a – z, which have consecutive codepoints in Unicode.
//
// An int is 32 bits long, and so can store one bit for each of the allowed letters.
//
// The expression b & (b - 1) evaluates to zero if and only if b has at most one bit set.
/*
**Solved By : Wilson Sumanang
*/
int isAnagramOfPalindrome ( char *S ) {
    //... write your code here ...
    int val = 0;
    int i;
    for(i = 0 ; i < strlen(S) ; i++) {
        val ^=  1 << (S[i] - 'a');
    }
    if((val & (val - 1)) == 0) {
        return 1;
    }
    return 0;
}
