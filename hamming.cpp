#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Read input bits
    string inputBits;
    cout << "Enter input bits: ";
    cin >> inputBits;
    
    // Calculate number of parity bits needed
    int m = 0;
    while (pow(2, m) < inputBits.length() + m + 1) {
        m++;
    }
    
    // Generate Hamming code
    vector<int> hammingCode(inputBits.length() + m);
    int j = 0;
    for (int i = 0; i < hammingCode.size(); i++) {
        if (i == pow(2, j) - 1) {
            hammingCode[i] = 0; // Set parity bit initially to 0
            j++;
        } else {
            hammingCode[i] = inputBits[i - j] - '0'; // Convert input bit from char to int
        }
    }
    
    // Calculate parity bits
    for (int i = 0; i < m; i++) {
        int parity = 0;
        for (int j = pow(2, i) - 1; j < hammingCode.size(); j += pow(2, i + 1)) {
            for (int k = 0; k < pow(2, i) && j + k < hammingCode.size(); k++) {
                parity ^= hammingCode[j + k];
            }
        }
        hammingCode[pow(2, i) - 1] = parity;
    }
    
    // Output Hamming code
    cout << "Hamming code: ";
    for (int i = 0; i < hammingCode.size(); i++) {
        cout << hammingCode[i];
    }
    cout << endl;
    
    return 0;
}
