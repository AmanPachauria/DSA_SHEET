#include <bits/stdc++.h> 
void sortStack(stack<int> &stk)
{
	stack<int> st1, st2;
	while(!stk.empty()){
	     if(st1.empty()){
			 st1.push(stk.top());
		 }
		 else{
			 while(!st1.empty() && st1.top()>stk.top()){
				        st2.push(st1.top());
						st1.pop();
			 }

			 st1.push(stk.top());
			 while(!st2.empty()){
				 st1.push(st2.top());
				 st2.pop();
			 }
		 }
		 stk.pop();
	}

	stk = st1;
}