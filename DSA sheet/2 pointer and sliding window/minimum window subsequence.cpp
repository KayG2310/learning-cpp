string minWindow(string S, string T)
{
	int i=0, j=0, sn = S.length(), tn = T.length(), end =0, len=1e9, startindex=-1;
	while(i<sn){
		// bool flag = true;
		while(i<sn && j<tn){
			if(S[i]==T[j]){
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		end = i;
		if(j != tn) break;
		i--;
		j--;
		while(i>=0 && j>=0){
			if(S[i]==T[j]){
				i--;
				j--;
			}
			else{
				i--;
			}
		}
		int len2 = end - i-1;
		if(len2<len){
			len = len2;
			startindex = i+1;
			// flag = false;
		}
		i+=2;
		j=0;
	}
	if(startindex == -1) return "";
	return S.substr(startindex, len);
}

// tc = n2, sc = 1
