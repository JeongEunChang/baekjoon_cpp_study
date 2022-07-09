#include <iostream>
#include <algorithm>
#include <stdio.h>



using namespace std;

int main()
{
	int SubjectNum = 0;
	int Mileage = 0;
	int Arr[100]; // 과목, 학생수

	//cin >> SubjectNum >> Mileage;
	scanf("%d %d", &SubjectNum, &Mileage);

	for (int i = 0; i < SubjectNum; i++)
	{
		int RequestNum = 0;
		int RequestLimit = 0;

		//cin >> RequestNum >> RequestLimit;
		scanf("%d %d", &RequestNum, &RequestLimit);

		int tmpArr[100];

		for (int j = 0; j < RequestNum; j++)
		{
			cin >> tmpArr[j];
		}

		sort(tmpArr, tmpArr + RequestNum, greater<>());

		if (RequestNum >= RequestLimit)
		{
			Arr[i] = tmpArr[RequestLimit - 1];
		}

		else if (RequestNum < RequestLimit)
		{
			Arr[i] = 1;
		}
	}

	sort(Arr, Arr + SubjectNum);
	int sum = 0;
	int i = 0;

	while (sum <= Mileage && SubjectNum >= i)
	{
		sum += Arr[i];
		i++;
	}

	if (i != 0)
	{
		i = i - 1;
	}

	//cout << i;
	printf("%d", i);
}