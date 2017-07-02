/*По данным n отрезкам необходимо найти множество точек минимального размера,
для которого каждый из отрезков содержит хотя бы одну из точек.
В первой строке дано число 1<n<100
отрезков. Каждая из последующих n строк содержит по два числа 0<=l<=r<=10^9,
задающих начало и конец отрезка. Выведите оптимальное число m точек и сами m точек.
Если таких множеств точек несколько, выведите любое из них.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	int n = 0, k = 0;
	cin >> n;
	vector <pair <int, int>> a(n);
	vector <int> points;
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;
		a[i] = {r, l};
	}
	sort(a.begin(), a.end());
	points.push_back(a[0].first);
	for (int i = 1; i < n; ++i)
	{
		if (a[i].second > points[k])
		{
			++k;
			points.push_back(a[i].first);
		}
	}
	cout << k + 1 << '\n';
	for (auto now : points)
		cout << now << " ";
			return 0;
}
