#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("input.txt");

vector<vector<int>> delta;
vector<char> alfabet;
vector<int> stfin;
string cuvant;

int getPos(char c, vector<char> alf)
{
	for (unsigned int i = 0; i < alf.size(); i++)
		if (c == alf[i])
			return i;
}

bool isFin(int x)
{
	for (unsigned int i = 0; i < stfin.size(); i++)
		if (x == stfin[i])
			return true;
	return false;
}

int OK = 1;

void eval(int nod, unsigned int posLit)
{
	int pos;
	pos = getPos(cuvant[posLit], alfabet);
	if (posLit < cuvant.size())
	{
		if (delta[nod][pos] != 0)
		{
			eval(delta[nod][pos] - 1, posLit + 1);
		}
		else
		{
			cout <<cuvant<< " - FALSE\n";
		}
	}
	else
	{
		if (isFin(nod))
			cout << cuvant << " - TRUE\n";
		else
		{
			cout << cuvant << " - FALSE\n";
		}

	}

}

int main()
{
	int n, m, i, q0, k, st, fn, pos;
	char chr;
	fin >> n >> m;

	vector<int> temp(m);

	for (i = 0; i < n; i++)
		delta.push_back(temp);

	for (i = 0; i < m; i++)
	{
		fin >> chr;
		alfabet.push_back(chr);
	}

	fin >> q0 >> k;
	for (i = 0; i < k; i++)
	{
		fin >> fn;
		stfin.push_back(fn);
	}

	fin >> m;
	for (i = 0; i < m; i++)
	{
		fin >> st >> chr >> fn;
		pos = getPos(chr, alfabet);
		delta[st][pos] = fn+1;
	}

	fin >> fn;
	for (i = 0; i < fn; i++)
	{
		fin >> cuvant;
		eval(q0,0);
	}

    return 0;
}






