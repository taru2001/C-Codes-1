// C++ program to count the distinct transformation 
// of one string to other. 
#include <bits/stdc++.h> 
using namespace std; 

int countTransformation(string a, string b) 
{ 
	int n = a.size(), m = b.size(); 

	// If b = "" i.e., an empty string. There 
	// is only one way to transform (remove all 
	// characters) 
	if (m == 0) 
		return 1; 

	int dp[m][n]; 
	memset(dp, 0, sizeof(dp)); 

	// Fil dp[][] in bottom up manner 
	// Traverse all character of b[] 
	for (int i = 0; i < m; i++) { 

		// Traverse all charaters of a[] for b[i] 
		for (int j = i; j < n; j++) { 

			// Filling the first row of the dp 
			// matrix. 
			if (i == 0) { 
				if (j == 0) 
					dp[i][j] = (a[j] == b[i]) ? 1 : 0; 
				else if (a[j] == b[i]) 
					dp[i][j] = dp[i][j - 1] + 1; 
				else
					dp[i][j] = dp[i][j - 1]; 
			} 

			// Filling other rows. 
			else { 
				if (a[j] == b[i]) 
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]; 
				else
					dp[i][j] = dp[i][j - 1]; 
			} 
		} 
	} 
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		cout << dp[i][j] << " ";
		cout << endl;
	}

	return dp[m - 1][n - 1]; 
} 

// Driver code 
int main() 
{ 
	string a = "abcccdf", b = "abccdf"; 
	cout << endl << countTransformation(a, b) << endl; 
	return 0; 
} 
