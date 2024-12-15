/*
string txt = "aabaacaadaabaaba";
string pat = "aaba";
indices: 0 9 12 
*/
vector<int> kmp(string txt, string pat){
	int n = txt.size(), m = pat.size();
	vector<int> lps = find_lps(pat);

	int i = 0, j = 0;
	vector<int> matches;

	while(i<n){
		if(txt[i] == pat[j]){
			i += 1;
			j += 1;

			if(j == m){
				//pattern matched successfully
				matches.push_back(i-j);
				j = lps[j-1];
			}
		}

		else{
			//didn't matched
			if(j == 0){
				i += 1;
			}
			else{
				j = lps[j-1];	//fall back and wait for i to match some similar pattern
			}
		}
	}
	return matches;
}
