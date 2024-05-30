#include <iostream>
#include <vector>

using namespace std;

bool canReturn(int p, int a, int b, vector<int>& k) {
    int curr_pow = p; 

    // if Abhimanyu can skip more than 11 circles then return true ;
    if (a >= 11) {
        return true;
    }
    
    for (int i = 0; i < 11; i++) {

       // Regenerating the 3rd (index 2) and 7th (index 6) enemies,
      // and adding their energy to the power of the 4th (index 3) and 8th (index 7) enemies.
        if (i == 3 || i == 7) {
            k[i] += k[i-1] / 2;
        }

        cout << "Circle " << i + 1 << ": "; // Adding these  print statement just for testing purpose .
        cout << "Current Power: " << curr_pow << ", Enemy Power: " << k[i] << ", Skips Left: " << a << ", Recharges Left: " << b << endl;
        

        // if abhimanyu has more energy than ith enemy
        if (curr_pow >= k[i]) {
            curr_pow -= k[i];
        } else {

            // checking if we can skip
            if (a > 0) {
                a--;
                cout << "Skipping enemy at Circle " << i + 1 << endl;
            // checking if we can recharge
            } else if (b > 0) {
                // recharging until the power of abhimanyu is more than ith enemy
                while (b > 0 && curr_pow < k[i]) {
                    curr_pow += p;
                    b--;
                    cout << "Recharging, new Current Power: " << curr_pow << ", Recharges Left: " << b << endl;
                }
                if (curr_pow < k[i]) {
                    cout << "Not enough power after recharging, failed at Circle " << i + 1 << endl;
                    return false;
                } else {
                    curr_pow -= k[i];
                }
            }

            // in case of 0 skip and 0 recharge left 
             else {
                cout << "No skips or recharges left, failed at Circle " << i + 1 << endl;
                return false;
            }
        }
    }
    // abhimanyu cross all the circles . 
    return true;
}

int main() {
    vector<int> k1 = {10, 12, 14, 8, 6, 5, 7, 9, 10, 12, 14};
    vector<int> k2 = {20, 15, 14, 13, 12, 11, 19, 18, 17, 16, 15};
    
    // Test Case 1 : will return true 
    int p1 = 15, a1 = 4, b1 = 4;
    bool result1 = canReturn(p1, a1, b1, k1);
    cout << "Test Case 1: " << (result1 ? "True" : "False") << endl;
    
    // Test Case 2 : will return false
    int p2 = 10, a2 = 1, b2 = 1;
    bool result2 = canReturn(p2, a2, b2, k2);
    cout << "Test Case 2: " << (result2 ? "True" : "False") << endl;
    
    return 0;
}
