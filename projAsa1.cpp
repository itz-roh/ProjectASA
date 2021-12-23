// C++ program for the
// above approach
#include <bits/stdc++.h>
using namespace std;

//Function to count the number
// of LIS in the array nums[]
void findNumberOfLIS(vector<int> nums)
{
	int n = nums.size();
	//Base Case
	if (n == 0)
		cout << 0 << ' ' << 0 << endl;

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
		max_length = max(i, max_length);

	//Stores the count of LIS
	int count = 0;

	//Traverse dp_l and dp_c
	// simultaneously
	for (int i = 0; i < n; i++)
	{
		//Update the count
		if (dp_l[i] == max_length)
			count += dp_c[i];
	}

	cout << max_length << ' ' << count << endl;
}

// Returns the length and the LCIS of two
// arrays arr1[0..n-1] and arr2[0..m-1]
void LCIS(vector<int> arr1, vector<int> arr2)
{
	int n = arr1.size();
	int m = arr2.size();
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
	for (int i = 0; i < m; i++)
	{
		if (table[i] > res)
			res = table[i];
	}

	cout << res << endl;
}

vector<int> inputAux(string input)
{
	vector<int> substring;
	char blank = ' ';
	for (auto i : input)
		if (i != blank)
			substring.push_back(((int)i) - ((int)'0'));
	return substring;
}

int main()
{
	string problem;
	string subsequence1;
	vector<int> s1;

	cin >> problem;
	if (problem.compare("1") == 0)
	{
		cin.ignore();
		getline(cin, subsequence1);
		findNumberOfLIS(inputAux(subsequence1));
	}

	else if (problem.compare("2") == 0)
	{
		string subsequence2;
		vector<int> s2;
		cin.ignore();
		getline(cin, subsequence1);
		s1 = inputAux(subsequence1);
		getline(cin, subsequence2);
		s2 = inputAux(subsequence2);

		LCIS(inputAux(subsequence1), inputAux(subsequence2));
	}

	return 0;
}