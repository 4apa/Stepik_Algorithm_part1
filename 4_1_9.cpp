/*�� ������ n �������� ���������� ����� ��������� ����� ������������ �������,
��� �������� ������ �� �������� �������� ���� �� ���� �� �����.
� ������ ������ ���� ����� 1<n<100
��������. ������ �� ����������� n ����� �������� �� ��� ����� 0<=l<=r<=10^9,
�������� ������ � ����� �������. �������� ����������� ����� m ����� � ���� m �����.
���� ����� �������� ����� ���������, �������� ����� �� ���.*/

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
