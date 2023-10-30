#include <iostream>
 
using namespace std;
 
int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		if(n == 1)
		{
			printf("-1\n");
			continue;
		}
		printf("4");
		for(int i = 1; i <= n - 1; i ++)
			printf("3");
		printf("\n");
	}
	return 0;
}