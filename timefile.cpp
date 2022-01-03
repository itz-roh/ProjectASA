#include <vector>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;
void problem1(vector<int> array)
{
	int size = array.size();

	vector<int> sub_lengths(size, 1);

	vector<int> n_subs(size, 1);

	int max_length = 0;

	int n_subsequences = 0;

	for (int i = 1 ; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[i] <= array[j])
				continue;
			
			else if (sub_lengths[j] + 1 > sub_lengths[i])
			{
				sub_lengths[i] = sub_lengths[j] + 1;
				n_subs[i] = n_subs[j];
			}
			else if (sub_lengths[j] + 1 == sub_lengths[i])
				n_subs[i] += n_subs[j];
		}
	}
	for (auto i : sub_lengths)
		max_length = max(i, max_length);

	for (int i = 0; i < size; i++)
	{
		if (sub_lengths[i] == max_length)
			n_subsequences += n_subs[i];
	}

	cout << max_length << ' ' << n_subsequences << endl;
}

void problem2(vector<int> array1, vector<int> array2)
{
	int size1 = array1.size();
	int size2 = array2.size();
	int aux[size2] = {0};
	int max_length = 0;

	for (int i = 0; i < size1; i++)
	{
		int current = 0;

		for (int j = 0; j < size2; j++)
		{
			if(array1[i] < array2[j])
				continue;

			else if (array1[i] == array2[j] && current + 1 > aux[j])
				aux[j] = current + 1;

			else if (array1[i] > array2[j] && aux[j] > current)
				current = aux[j];
		}
	}

	for (auto i : aux)
	{
		if (i > max_length)
			max_length = i;
	}

	cout << max_length << endl;
}

vector<int> inputAux(string input)
{
	vector<int> substring;
	int aux = 0;
	for (auto i : input){
		
		if (i == ' ') {
			substring.push_back(aux);
			aux = 0;
		}
		else
			aux = aux*10 + ((int)i) - ((int)'0');
	}
	substring.push_back(aux);
	return substring;
}

int main()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
  
    start = std::chrono::system_clock::now();
	string problem;
	string subsequence1;
	vector<int> s1;

	cin >> problem;
	if (problem.compare("1") == 0)
	{
		cin.ignore();
		getline(cin, subsequence1);
		problem1(inputAux(subsequence1));
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

		problem2(inputAux(subsequence1), inputAux(subsequence2));
    }
    end = std::chrono::system_clock::now();
  
    std::chrono::duration<double> elapsed_seconds = end - start;
  
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	return 0;
}