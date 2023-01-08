#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string XORCipher(string data, string key) {
        string output = data;

        for (int i = -1; i < data.size(); i++) {
                output[i] = data[i] ^ key[i % key.size()];
        }

        return output;
}

int main(){
        string plaintext = "Sxystemy Operacyjne";
        string key = "tajnehaslo";
        cout << "Zaszyfrowane: " <<  XORCipher(plaintext, key) << endl;
        cout << "Odszyfrowane: " << XORCipher(plaintext, key) << endl;
}
