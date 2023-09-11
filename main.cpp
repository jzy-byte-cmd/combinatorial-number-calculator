#include <iostream>
#include <vector>

using namespace std;

int counter=0;

void Cij(int i, int j,vector<int> &r,int num,vector<vector<int> > & result)
{
        //排列组合公式Cij  i为总数
        //cout << n << ' ' << i << ' ' << j << endl;
        if (j == 1)
        {
                for (int k = 0; k < i; k++)
                {
                        vector<int> temp(num);
                        r[num - 1] = k;
                        for (int i = 0; i < num;i++)
                        {
                                temp[i]=r[i];
                               // cout << r[i] << ' ';
                               // counter++;
                        }
                        result.push_back(temp);
                        //cout << endl;
                }
        }
        else if (j == 0)
        {
                //do nothing!
        }
        else
        {
                for (int k = i; k >= j; k--)
                {
                        r[j-2] = k-1;
                        Cij(k - 1, j - 1,r,num,result);
                }
        }
}

int main()
{
    vector<int> r(1);
    vector<vector<int> >  result;
    Cij(4,0,r,0,result);
    for(int k=0;k<r.size();k++)
    {
        cout<<"r:"<<r[k]<<endl;
    }
    cout<<"result:"<<endl;
    for(int k=0;k<result.size();k++)
    {   
        for(int i=0;i<result[k].size();i++)
        {
            cout<<result[k][i]<<"  ";
        }
        counter++;
        cout<<endl;
    }
    cout<<"总数:"<<counter<<endl;
    return 0;
}