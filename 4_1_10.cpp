/* Первая строка содержит количество предметов 1≤n≤10^3 и вместимость рюкзака 0≤W≤2*10^6.
Каждая из следующих n строк задаёт стоимость 0≤ci≤2*10^6 и объём 0<wi≤2*10^6 предмета (n, W, ci, wi — целые числа).
Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть,
стоимость и объём при этом пропорционально уменьшатся),
помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

struct item
{
	int weight;
	double cw;
};

bool cmp(item a, item b)
{
	return a.cw > b.cw;
}

int main()
{
	int n = 0, vol = 0;
	double max_price = 0.0;
	cin >> n >> vol;
	vector <item> a(n);
	for (int i = 0; i < n; ++i)
	{
		int c, w;
		cin >> c >> w;
		item struct_temp;
		struct_temp.weight = w;
		struct_temp.cw = (double)c / w;
		a[i] = struct_temp;
	}
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; ++i)
	{
		if (a[i].weight >= vol)
		{
			max_price += (a[i].cw)*vol;
			break;
		}
		else
		{
			vol -= a[i].weight;
			max_price += a[i].weight*a[i].cw;
		}
	}
	cout << setprecision(3) << fixed << max_price;
			return 0;
}
