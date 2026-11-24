
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
using namespace std;

// Function to convert IP address into a 32-bit number
uint32_t ipToNumber(string ip) {
    stringstream ss(ip);
    string part;
    uint32_t result = 0;

    for (int i = 0; i < 4; i++) {
        if (!getline(ss, part, '.'))
            throw string("Invalid IP address");

        int octet = stoi(part);

        if (octet < 0 || octet > 255)
            throw string("Invalid IP address");

        result = (result << 8) | octet;
    }

    if (getline(ss, part, '.'))
        throw string("Invalid IP address");

    return result;
}

// Function to convert 32-bit number into IP address
string numberToIP(uint32_t ip) {
    return to_string((ip >> 24) & 255) + "." +
           to_string((ip >> 16) & 255) + "." +
           to_string((ip >> 8) & 255) + "." +
           to_string(ip & 255);
}

int main() {
    string ip;
    int prefix;

    cout << "Enter IPv4 address: ";
    cin >> ip;

    cout << "Enter prefix length (0-32): ";
    cin >> prefix;

    try {
        if (prefix < 0 || prefix > 32)
            throw string("Prefix must be between 0 and 32");

        uint32_t address = ipToNumber(ip);

        uint32_t mask = (prefix == 0)
            ? 0
            : (0xFFFFFFFFu << (32 - prefix));

        uint32_t network = address & mask;
        uint32_t broadcast = network | ~mask;

        uint64_t total = 1ULL << (32 - prefix);
        uint64_t usable;

        if (prefix <= 30)
            usable = total - 2;
        else if (prefix == 31)
            usable = 2;
        else
            usable = 1;

        cout << "\n--- Subnet Calculator ---\n";
        cout << "IP Address: " << numberToIP(address) << endl;
        cout << "Subnet Mask: " << numberToIP(mask) << endl;
        cout << "Network Address: " << numberToIP(network) << endl;
        cout << "Broadcast Address: " << numberToIP(broadcast) << endl;
        cout << "Prefix Length: /" << prefix << endl;
        cout << "Total Addresses: " << total << endl;
        cout << "Usable Hosts: " << usable << endl;

        if (prefix <= 30) {
            cout << "First Usable IP: "
                 << numberToIP(network + 1) << endl;
            cout << "Last Usable IP: "
                 << numberToIP(broadcast - 1) << endl;
        }
        else if (prefix == 31) {
            cout << "Usable IP Range: "
                 << numberToIP(network) << " - "
                 << numberToIP(broadcast) << endl;
        }
        else {
            cout << "Usable IP: "
                 << numberToIP(network) << endl;
        }
    }
    catch (...) {
        cout << "Invalid input. Enter a valid IPv4 address and prefix.\n";
        return 1;
    }

    return 0;
}
