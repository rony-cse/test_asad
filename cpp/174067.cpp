#include <bits/stdc++.h>
using namespace std;
int counter=0;
int size, time1 = 1;
list<int> mainList[9999];
list<int> transposeList[9999];
list<int> visitList[9999];
list<int> timeList[9999];
pair<int, int> timePair[9999];
void FirstDFS(int);
void SecondDFS(int);
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int main()
{
	ifstream dataFile;
	dataFile.open("testFile.txt");
	dataFile >> size;
	int input1, input2;
	map<int, int> nodeMap;
	while (dataFile >> input1 >> input2)
	{
		mainList[input1].push_back(input2);
		transposeList[input2].push_back(input1);
		nodeMap[input1] = input2;
	}
	// for (int k = 0; k < size; k++)
	// {
	// 	cout<<"["<<k<<"]";
	// 	for (auto &i : mainList[k])
	// 		cout << i<<"-";
	// 	cout<<endl;
	// }
	// for (int k = 0; k < size; k++)
	// {
	// 	cout<<"["<<k<<"]";
	// 	for (auto &i : transposeList[k])
	// 		cout << i<<"-";
	// 	cout<<endl;
	// }
	// dfs(mainList[0]);

	for (auto &i : nodeMap)
	{
		// cout << "sending" << i.first << endl;
		if (visitList[i.first].front() != 1)
			FirstDFS(i.first);
	}
	// for (int k = 1; k <= size; k++)
	// {
	// 	cout << "[" << k << "]"<<timePair[k].second;
	// 	for (auto &i : timeList[k])
	// 		cout << i << "-";
	// 	cout << endl;
	// }

	int maxTime = 0, maxItem=0;
	for (int i = 1; i <= size; i++)
	{
		visitList[i].pop_back();
		visitList[i].push_back(0);
	}
	// cout<<"visit List: \n";
	// for (int i = 1; i <= size; i++)
	// {
	// 	cout<<i<<"-"<<visitList[i].front()<<endl;
	// }
	cout<<"Found SCC: "<<endl;
	for (int k = 1; k <= size; k++)
	{
		maxTime = 0;
		for (int i = 1; i <= size; i++)
		{
			if (timePair[i].second > maxTime && visitList[i].back() != 1)
			{
				maxTime= timePair[i].second;
				maxItem=i;
			}
		}
		// cout<<maxItem<<"-"<<maxTime<<endl;
		if (visitList[maxItem].back() != 1)
		{	
			SecondDFS(maxItem);
			counter++;
			cout<<endl;
		}
	}
	cout<<"Total no of SCC: "<<counter<<endl;
	return 0;
}

void FirstDFS(int item)
{
	time1++;
	visitList[item].push_back(1);
	for (auto &i : mainList[item])
	{
		if (visitList[i].front() != 1)
		{
			FirstDFS(i);
		}
	}
	// timeList[item].push_back(time1++);
	timePair[item].first = item;
	timePair[item].second = time1++;
}

void SecondDFS(int item)
{
	cout <<item<<"--> ";
	visitList[item].push_back(1);
	for (auto &i : transposeList[item])
		if (visitList[i].back() != 1)
			SecondDFS(i);

}
