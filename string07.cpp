#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<fstream>
#include<string.h>
using namespace std;
 
ifstream fin;
ofstream fout;
 
typedef pair<string,int> PAIR;
 
char b[20];
struct CmpByValue
{
	bool operator()(const PAIR& lhs,const PAIR& rhs)
	{
		return lhs.second > rhs.second;
	}
 
};

/*char* chmaker(string a)
{
    char b[a.length()];
    for(int i = 0; i < a.length(); i++)
    {
        cout<<i<<endl;
    }
    return b;

}

string srt(char* a)
{
	int j;
	char temp;
	for(j=0;j<strlen(a);j++)//注意是i<4
	{
			if(a[j]>a[j+1])//字符串比较:>0表示前面的字符串比后面的大则交换
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		
	}
    string op = a;
    return op;
}*/

//using char to rewrite the words
char* chmaker(string a)
{
    for(int i = 0; i < a.length(); i++)
    {
        b[i] = a[i];
		//printf("%c\n",b[i]);
    }
	//printf("%d",b);
    return b;

}

string srt(char* a)
{
	int j;
	char temp;
	int t =strlen(a);
	sort(a,a+t);
    string op = a;
	return op;
}

int main()
{
	fin.open("seq.txt");
	fout.open("result.txt");
	if(!fin || !fout)
	{
		cerr<<"file cannot be opened"<<endl;
		exit(1);
	}
 
	string word;
	map<string,int> map_word;
	map<string,int>:: iterator it;
	//count words
	while(fin>>word)
	{
        char* word1 = chmaker(word);
		map_word[srt(word1)]++;
        memset(b, 0, 20);
	}
	
    // resort by frequency
	vector<PAIR> vec_word(map_word.begin(),map_word.end());
	sort(vec_word.begin(),vec_word.end(),CmpByValue()); 
	for(int i=0;i<vec_word.size();i++)
	{
		fout<<vec_word[i].first<<" "<<vec_word[i].second<<endl;
	}
 

	fout<<"Number of Words : "<<vec_word.size()<<endl;
 
	fin.close();
	fout.close();
	return 0;
}
