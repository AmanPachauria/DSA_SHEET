#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int> st;
	int m = 0;
	while(m<n){
		st.push(m);
		m++;
	}

	while(st.size()>1){
        int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();

		if(knows(a,b)) st.push(b);
		else if(knows(b,a)) st.push(a);
		else if(knows(a,b)==false) st.push(a);
		else if(knows(b,a)==false) st.push(b);
	}
    
	int a = st.top();
	for( int i = 0; i < n; i++ ){
		if(i==a) continue;
		if(knows(a,i)) return -1;
		if(knows(i,a)==false) return -1;
		
	}


	 return a;
}