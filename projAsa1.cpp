// C++ program for the
// above approach
#include <bits/stdc++.h>
using namespace std;

//Function to count the number
// of LIS in the array nums[]
vector<int> findNumberOfLIS(vector<int> nums, int n)
{

	vector<int> res;
	//Base Case
	if (n == 0)
		{
			res.push_back(0);
			res.push_back(0);
			return res;
		}

	//Initialize dp_l array with
	// 1s
	vector<int> dp_l(n, 1);

	//Initialize dp_c array with
	// 1s
	vector<int> dp_c(n, 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
		//If current element is
		// smaller
		if (nums[i] <= nums[j])
			continue;

		if (dp_l[j] + 1 > dp_l[i])
		{
			dp_l[i] = dp_l[j] + 1;
			dp_c[i] = dp_c[j];
		}
		else if (dp_l[j] + 1 == dp_l[i])
			dp_c[i] += dp_c[j];
		}
	}

	//Store the maximum element
	// from dp_l
	int max_length = 0;

	for (int i : dp_l)
		max_length = max(i,max_length);

	//Stores the count of LIS
	int count = 0;

	//Traverse dp_l and dp_c
	// simultaneously
	for(int i = 0; i < n; i++)
	{
		//Update the count
		if (dp_l[i] == max_length)
			count += dp_c[i];
	}

	res.push_back(max_length);
	res.push_back(count);
	//Return the count of LIS
	return res;
}

// Returns the length and the LCIS of two
// arrays arr1[0..n-1] and arr2[0..m-1]
int LCIS(vector<int> arr1, int n, vector<int> arr2, int m)
{
	// table[j] is going to store length of LCIS
	// ending with arr2[j]. We initialize it as 0,
	int table[m];

	for (int j = 0; j < m; j++)
		table[j] = 0;

	// Traverse all elements of arr1[]
	for (int i = 0; i < n; i++)
	{
		// Initialize current length of LCIS
		int current = 0;

		// For each element of arr1[], traverse all
		// elements of arr2[].
		for (int j = 0; j < m; j++)
		{
			// If both the array have same elements.
			// Note that we don't break the loop here.
			if (arr1[i] == arr2[j])
				if (current + 1 > table[j])
					table[j] = current + 1;

			/* Now seek for previous smaller common
			element for current element of arr1 */
			if (arr1[i] > arr2[j])
				if (table[j] > current)
					current = table[j];
		}
	}

	// The maximum value in table[] is out result
	int res = 0;
	for (int i=0; i<m; i++){
		if (table[i] > res)
		    res = table[i];
        }

	return res;
}

int main()
{
	string problem;
	string subsequence1;
	string subsequence2;
	vector<int> s1;
	vector<int> s2;
	int size1 = 0;
	int size2 = 0;
	
	char blank = ' ';
	vector<int> res1;
	int res2 = 0;

	cin >> problem;
	if (problem.compare("1") == 0) 
	{
		int size1 = 0;
		cin.ignore();
		getline(cin, subsequence1);
		for(int i = 0; i < (int)subsequence1.length(); i++) {
			if (subsequence1[i] != blank) {
				s1.push_back(((int)subsequence1[i]) - ((int)'0'));
				size1++;
			}
		}
		res1 = findNumberOfLIS(s1, size1);
		cout << res1[0] << ' ' << res1[1] << endl;
	}

	else if (problem.compare("2") == 0) 
	{
		cin.ignore();
		getline(cin, subsequence1);
		for(int i = 0; i < (int)subsequence1.length(); i++) {
			if (subsequence1[i] != blank) {
				s1.push_back(((int)subsequence1[i]) - ((int)'0'));
				size1++;
			}
		}

		getline(cin, subsequence2);
		for(int i = 0; i < (int)subsequence2.length(); i++) {
			if (subsequence2[i] != blank) {
				s2.push_back(((int)subsequence2[i]) - ((int)'0'));
				size2++;
			}
		}

		res2 = LCIS(s1, size1, s2, size2);
		cout << res2 << endl;
	}

	return 0;
}