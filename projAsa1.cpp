#include <bits/stdc++.h>
using namespace std;

// Function to n_subsequences the number
// of LIS in the array nums[]
void findNumberOfLIS(vector<int> nums)
{
	int size = nums.size();
	// Base Case
	if (size == 0)
		cout << 0 << ' ' << 0 << endl;

	// Initialize all sub_lengths's indeces with 1s
	vector<int> sub_lengths(size, 1);

	// Initialize all n_subs' indeces with 1s
	vector<int> n_subs(size, 1);

	int max_length = 0;

	int n_subsequences = 0;

	for (int i = 0 ; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// If current element is smaller or equal than the next element
			// then we won't have an increasing subsequence
			if (nums[i] <= nums[j])
				continue;

			if (sub_lengths[j] + 1 > sub_lengths[i])
			{
				sub_lengths[i] = sub_lengths[j] + 1;
				n_subs[i] = n_subs[j];
			}
			else if (sub_lengths[j] + 1 == sub_lengths[i])
				n_subs[i] += n_subs[j];
		}
	}
	// Update the max_length
	for (int i : sub_lengths)
		max_length = max(i, max_length);

	// Traverse sub_lengths and n_subs
	// simultaneously
	for (int i = 0; i < size; i++)
	{
		// Update the n_subsequences
		if (sub_lengths[i] == max_length)
			n_subsequences += n_subs[i];
	}

	cout << max_length << ' ' << n_subsequences << endl;
}

//  Returns the length and the LCIS of two
//  arrays arr1[0..n-1] and arr2[0..m-1]
void LCIS(vector<int> arr1, vector<int> arr2)
{
	int n = arr1.size();
	int m = arr2.size();
	//  table[j] is going to store length of LCIS
	//  ending with arr2[j]. We initialize it as 0,
	int table[m];

	for (int j = 0; j < m; j++)
		table[j] = 0;

	//  Traverse all elements of arr1[]
	for (int i = 0; i < n; i++)
	{
		//  Initialize current length of LCIS
		int current = 0;

		//  For each element of arr1[], traverse all
		//  elements of arr2[].
		for (int j = 0; j < m; j++)
		{
			//  If both the array have same elements.
			//  Note that we don't break the loop here.
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

	//  The maximum value in table[] is out result
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
	input += ' ';
	int aux = 0;
	for (auto i : input)
		if (i == ' ') {
			substring.push_back(aux);
			aux = 0;
		}
		else
			aux = aux*10 + ((int)i) - ((int)'0');
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