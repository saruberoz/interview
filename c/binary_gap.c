// A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
//
// For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001) and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.
//
// Write a function:
//
// int binary_gap(int N);
//
// that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
//
// For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.
//
// Assume that:
//
// N is an integer within the range [1..2,147,483,647]. Complexity:
//
// expected worst-case time complexity is O(log(N)); expected worst-case space complexity is O(1).

int binary_gap ( int N ) {
    //... write your code here ...
    int length = 0;
    int temp = N;
    while(temp){
        length++;
        temp /= 2;
    }
    temp = N;
    char *binary = malloc(length);
    int i = 0;
    while(temp){
        binary[i] = temp % 2;
        temp /= 2;
        i++;
    }
    i = 0;
    int count = 0;
    int maxCount = 0;
    for(i = 0 ; i < length ; i++){
        if(maxCount < count){
            maxCount = count;
        }
        if(binary[i] == 1){
            count = 0;
        }else if(binary[i] == 0){
            count += 1;
        }
    }
    return maxCount;
}
