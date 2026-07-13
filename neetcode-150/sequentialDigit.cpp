string digits = "123456789";
        vector<int> result;
        
        for (int length = 2; length <= 9; length++) {
            for (int start = 0; start + length <= 9; start++) {
                string sub = digits.substr(start, length);
                int num = stoi(sub);
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
