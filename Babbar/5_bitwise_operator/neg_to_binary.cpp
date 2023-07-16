#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter value of n:\n";
    cin >> n;
    cout << endl;

    // int bin[32];
    // for (int i = 0; i < 32; i++)
    // {
    //     bin[i] = -1;
    // }
    int ans = 0, i = 0;
    while (n != -1 && n != 0)
    {
        int bit = (n & 1);
        if (bit == 1)
            bit = 0;
        else
            bit = 1;
        ans = ans + bit * pow(10, i);
        i++;
        n = (n >> 1);
    }
    cout << (-1) * (ans);

    return 0;
}
// #include <iostream>
// using namespace std;

// void print_binary(int num)
// {
//     // `result` stores the binary notation of `num` in decimal format
//     int result = 0;

//     // It ignores leading zeros and leading ones
//     int place_value = 1;
//     while (!(num == 0 | num == -1))
//     {
//         // Extracting the rightmost bit from `num`
//         int bit = num & 1;

//         // appending `bit` to `result`
//         result += bit * place_value;

//         // Shifting `num` to the right
//         // so that second bit (from right) now become the rightmost bit
//         num = num >> 1;
//         place_value *= 10;
//     }

//     cout << result << endl;
// }

// int main()
// {
//     int number = -6;
//     int neg_number = ~number + 1; // Took 2's compliment of number

//     print_binary(number);
//     print_binary(neg_number);
// }