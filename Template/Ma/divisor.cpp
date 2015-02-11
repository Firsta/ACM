//求约数
vector<int> divisor(int n)
{
	vector<int> temp;
	for(int i=1;i*i<=n;i++)
		if(n%i==0)
		{
			temp.push_back(i);
			if(i!=n/i)
				temp.push_back(n/i);
		}
	return temp;
}
