# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <vector>


using namespace std;


struct myStackBall
{
	stack<pair<int, int>>nums;
	int cnt = 0;

	void my_push(int num)
	{
		if (nums.empty())
		{
			pair<int, int> x;
			x.first = num;
			x.second = 1;
			nums.push(x);
		}

		else
		{
			pair<int, int> x;

			if (nums.top().first == num)
			{
				x.first = num;
				x.second = nums.top().second + 1;
				nums.push(x);
			}

			else
			{
				if (nums.top().second >= 3)
				{
					int checker = nums.top().first;
					while (!nums.empty() && nums.top().first == checker)
					{
						cnt++;
						nums.pop();
					}

					if (!nums.empty() && nums.top().first == num)
					{
						x.first = num;
						x.second = nums.top().second + 1;
						nums.push(x);
					}

					else
					{
						x.first = num;
						x.second = 1;
						nums.push(x);
					}
				}

				else
				{
					x.first = num;
					x.second = 1;
					nums.push(x);
				}
			}
		}
	}

	void cout_res()
	{
		if (!nums.empty())
			if (nums.top().second >= 3)
			{
				int checker = nums.top().first;
				while (!nums.empty() && (nums.top().first == checker))
				{
					cnt++;
					nums.pop();
				}
			}
		cout << cnt;
	}
};


int main()
{
	myStackBall nums;
	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		nums.my_push(num);
	}

	nums.cout_res();

	return 0;

}