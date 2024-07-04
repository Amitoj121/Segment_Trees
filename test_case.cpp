#include<bits/stdc++.h>
#include "Segment_Tree.h"

using namespace std;

void interactiveMode(Segment_Tree& st, int n, vector<int>& arr) {
    while (true) {
        int l, r;
        cout << "Enter Your Range (l <= r, 0-based index): ";
        cin >> l >> r;
        
        if (l < 0 || r >= n || l > r) {
            cout << "Invalid range. Please try again." << endl;
            continue;
        }

        int option;
        cout << "Choose Operation:" << endl;
        cout << "1. Query Maximum" << endl;
        cout << "2. Query Minimum" << endl;
        cout << "3. Query Bitwise OR" << endl;
        cout << "4. Query Bitwise AND" << endl;
        cout << "5. Update Value" << endl;
        cout << "6. Query Sum" << endl;
        cout << "7. Update Range (Only for Sum Calculation)" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Max in Given Range: " << st.maximum(l, r) << endl;
                break;
            case 2:
                cout << "Minimum in Given Range: " << st.minimum(l, r) << endl;
                break;
            case 3:
                cout << "Bitwise OR of Given Range: " << st.orri(l, r) << endl;
                break;
            case 4:
                cout << "Bitwise AND of Given Range: " << st.anddi(l, r) << endl;
                break;
            case 5:
                int idx, val;
                cout << "Enter index to update (0-based): ";
                cin >> idx;
                cout << "Enter new value: ";
                cin >> val;
                if (idx < 0 || idx >= n) {
                    cout << "Invalid index. Please try again." << endl;
                    break;
                }
                st.update(idx, val);
                cout << "Updated!" << endl;
                break;
            case 6:
                cout << "Sum in Given Range: " << st.sumi(l, r) << endl;
                break;
            case 7:
                int update_val;
                cout << "Enter value to add in range [" << l << ", " << r << "]: ";
                cin >> update_val;
                st.rangeupdate(l, r, update_val);
                cout << "Range updated for sum calculation." << endl;
                cout << "Sum in range [" << l << ", " << r << "]: " << st.sumi(l, r) << endl;
                break;
            case 8:
                cout << "Exiting interactive mode..." << endl;
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
}

void automatedTest(Segment_Tree& st, int n) {
    // Seed for random number generation
    srand(time(0));

    // Perform some example queries and updates
    int queries = 1000;
    cout << "Performing " << queries << " random queries and updates on the segment tree." << endl;
    
    for (int i = 0; i < queries; i++) {
        // Generate random indices
        int l = rand() % n;
        int r = rand() % n;
        if (l > r) swap(l, r);

        // Perform random operation (query or update)
        if (rand() % 2 == 0) {
            // Query operation
            int max_val = st.maximum(l, r);
            int min_val = st.minimum(l, r);
            int or_val = st.orri(l, r);
            int and_val = st.anddi(l, r);
            int sum_val = st.sumi(l, r);

            cout << "Query results for range [" << l << ", " << r << "]" << endl;
            cout << "Maximum: " << max_val << endl;
            cout << "Minimum: " << min_val << endl;
            cout << "OR: " << or_val << endl;
            cout << "AND: " << and_val << endl;
            cout << "Sum: " << sum_val << endl;
        } else {
            // Update operation
            int idx = rand() % n;
            int val = rand() % 1000;
            st.update(idx, val);
            cout << "Updated index " << idx << " to value " << val << endl;
        }
    }
}

int main() {
    int mode;
    cout << "Choose Mode:" << endl;
    cout << "1. Interactive Mode" << endl;
    cout << "2. Automated Large-Scale Test" << endl;
    cout << "Enter mode: ";
    cin >> mode;

    if (mode == 1) {
        int n;
        cout << "Enter Array Size: ";
        cin >> n;

        // Input array elements
        vector<int> arr(n);
        cout << "Enter " << n << " Elements:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Initialize segment tree with the array
        Segment_Tree st(arr);

        // Build the segment tree
        st.build(0, 0, n - 1, arr);

        // Run interactive mode
        interactiveMode(st, n, arr);
    } else if (mode == 2) {
        // Generate a large array with random values
        int n = 100000;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000; // Random values between 0 and 999
        }

        // Initialize segment tree with the array
        Segment_Tree st(arr);

        // Build the segment tree
        st.build(0, 0, n - 1, arr);

        // Run automated large-scale test
        automatedTest(st, n);
    } else {
        cout << "Invalid mode. Exiting." << endl;
    }

    return 0;
}
