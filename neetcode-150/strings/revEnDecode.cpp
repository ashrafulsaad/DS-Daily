class solution{
	public:
		string encode(vector<string> &str){

			string ans = "";

			for(string s:str){
				ans+= to_string(s.size());
				ans+='#';
				ans+=s;
			}
			return ans;
		}

	vector<string>decode(string s){
		vector<string> ans;

		int i=0;

		while(i<s.size()){
			int j=i;

			while(s[j]!='#'){
				j++;
			}

		int len = stoi(s.substr(i,j-1));
		
		string word = s.substr(j+1,len);

		ans.push_back(word);

		i=j+1+len;
		
		}

		return ans;
	}
};
