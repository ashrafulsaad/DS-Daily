#include <vector>
#include <string>
using namespace std;

class Codec {
public:

    // Encode a list of strings into one string
    string encode(vector<string>& strs) {

        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    // Decode one string back into list
    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#')
                j++;

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract the string
            result.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return result;
    }
};
