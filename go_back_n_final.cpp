
#include <iostream>
using namespace std;

int main() {
    int n, ws;

    cout << "Enter number of frames: ";
    cin >> n;

    cout << "Enter window size: ";
    cin >> ws;

    int start = 0;

    while (start < n) {
        int end = start + ws;

        if (end > n) {
            end = n;
        }

        cout << "\nSending Frames: ";

        for (int i = start; i < end; i++) {
            cout << i << " ";
        }

        int lost;
        cout << "\nEnter lost frame (-1 if none): ";
        cin >> lost;

        if (lost >= start && lost < end) {
            cout << "Frame " << lost << " lost!";
            cout << "\nRetransmitting frames: ";

            start = lost;
        }
        else {
            cout << "All frames acknowledged.";
            start = end;
        }

        cout << endl;
    }

    cout << "\nAll frames transmitted successfully.";

    return 0;
}
