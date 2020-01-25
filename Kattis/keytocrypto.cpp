// https://open.kattis.com/problems/keytocrypto
//
#include <bits/extc++.h>

using namespace std;

int main() {

    string encrypted, secret;
    cin >> encrypted >> secret;

    // Case 1: the secret >= ciphertext
    if (secret.size() >= encrypted.size()) {
        int length0 = static_cast<int>(encrypted.size());
        for (int i = 0; i < length0; ++i) {
            int shift = static_cast<int>(secret.at(i) - 'A');
            while (shift > 0) {
                // shift the letter back
                if (encrypted.at(i) == 'A') {
                    encrypted.at(i) = 'Z';
                } else {
                    --encrypted.at(i);
                }
                --shift;
            }
        }
    }

        // Case 2: the secret < ciphertext
    else {

        int startPosition = 0;
        int length0 = static_cast<int>(secret.size());
        int endPosition = length0 - 1;
        bool lastIteration = false;

        while (true) {

            int counter = 0;
            for (int i = startPosition; i <= endPosition; ++i) {
                int shift = static_cast<int>(secret.at(counter) - 'A');
                ++counter;
                while (shift > 0) {
                    // shift the letter back
                    if (encrypted.at(i) == 'A') {
                        encrypted.at(i) = 'Z';
                    } else {
                        --encrypted.at(i);
                    }
                    --shift;
                }
            }
            secret = "";
            for (int i = startPosition; i <= endPosition; ++i) {
                secret += encrypted.at(i);
            }

            if (lastIteration) {
                break;
            }

            startPosition = endPosition + 1;
            endPosition = endPosition + static_cast<int>(secret.size());

            if (endPosition > static_cast<int>(encrypted.size()) - 1) {
                endPosition = static_cast<int>(encrypted.size()) - 1;
                lastIteration = true;
            }
        }

    }

    //  output the original text
    cout << encrypted << endl;

    return 0;
}
