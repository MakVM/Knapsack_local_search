#include <iostream>
#include <vector>
#include <random>

using namespace std;
//IMPROVEMENTS TO BE MADE
//makefile
//scalar_multip as *
//improve optimum
//headers

long int scalar_multip(vector<long int> &one, vector<long int> &two)
{
    long int res = 0;
    for(long int i = 0; i<one.size(); i++)
    {
        res += one[i]*two[i];
    }
    
    return res;
}
vector<long int> Hemm_neighbour(vector<long int> &cur)
{
    long int coord = rand() %cur.size();
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
bool weight_satisfied(vector<long int> &weights, vector<long int> &cur, long int k)
{
    if(scalar_multip(weights, cur) > k) //the weight of cur vector is > max
    {
        return false;
    }
    return true;
}

vector<long int> supplem(vector<long int> &weights, vector<long int> &values, long int k, long int n, vector<long int> &init, long int &limit)
{
    //cout<<limit<<endl;
    vector<long int> cur = Hemm_neighbour(init);
//    for(int i = 0; i<n; i++)
//    {
//        cout<<cur[i]<< " ";
//    }
//    cout<<endl;
    
    if(weight_satisfied(weights, cur, k) &&
       (scalar_multip(values, cur) > scalar_multip(values, init)) ) //something to work with; it is both weight and value optimal
    {
        limit = 0;
        return cur;
    }
    
    else //eh.. CAN GO ETERNALLY
    {
        limit++;
        return init;
    }
}
vector<long int> local_optimum(vector<long int> &weights, vector<long int> &values, long int k, long int n, vector<long int> &init, long int &limit)
{
    vector<long int> cur = init;
    while(limit<2*n) //can be changed...?
    {
        
        cur = supplem(weights, values, k, n, cur, limit);
        
    }

    return cur;
    
}


int main() {
    long int n; //number of items
    long int k; //maxweight
    
    long int value, weight;
    cin>> n;
    cin>> k;
    
    vector<long int> values;
    vector<long int> weights;
    
    for(long int i = 0; i<n; i++)
    {
        cin>>value;
        values.push_back(value);
        cin>> weight;
        weights.push_back(weight);
        
    }
    //cout<<"values in"<<endl;
    
    vector<long int> init(n,0); //will always satisfy weight, but not values
    
    long int limit = 0;
    vector<long int> optimal = local_optimum(weights, values, k, n, init, limit);
    long int final_val = scalar_multip(values, optimal);
    cout<< final_val<< " "<< 0<<endl;
    for(long int i = 0; i<n; i++)
    {
        cout<<optimal[i]<< " ";
    }
    
    return 0;
}



//makefile!!!!!!!


