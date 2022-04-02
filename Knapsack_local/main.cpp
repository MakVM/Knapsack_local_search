

#include <iostream>
#include <vector>
#include <random>

using namespace std;
//IMPROVEMENTS TO BE MADE
//makefile
//scalar_multip as *
//improve optimum

int scalar_multip(vector<int> &one, vector<int> &two)
{
    int res = 0;
    for(int i = 0; i<one.size(); i++)
    {
        res += one[i]*two[i];
    }
    
    return res;
}

vector<int> local_optimum(vector<int> &weights, vector<int> &values, )
{
    
}

bool weight_satisfied(vector<int> &weights, vector<int> &cur, int k)
{
    if(scalar_multip(weights, cur) > k) //the weight of cur vector is > max
    {
        return false;
    }
    return true;
}


vector<int> Hemm_neighbour(vector<int> &cur)
{
    int coord = rand() %cur.size();
    if(cur[coord]) //if it's a 1
    {
        cur[coord] = 0;
    }
    else //it's a 0
    {
        cur[coord] = 1;
    }
    return cur;
}

int main() {
    int n; //number of items
    int k; //maxweight
    
    int value, weight;
    cin>> n;
    cin>> k;
    
    vector<int> values;
    vector<int> weights;
    
    for(int i = 0; i<n; i++)
    {
        cin>>value;
        values.push_back(value);
        cin>> weight;
        weights.push_back(weight);
        
    }
    
    vector<int> init(n,0);
    
    
   

    
    return 0;
}



//makefile!!!!!!!


