

#include <iostream>
#include <vector>
#include <random>

using namespace std;
//IMPROVEMENTS TO BE MADE
//makefile
//scalar_multip as *
//improve optimum
//headers

int scalar_multip(vector<int> &one, vector<int> &two)
{
    int res = 0;
    for(int i = 0; i<one.size(); i++)
    {
        res += one[i]*two[i];
    }
    
    return res;
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
bool weight_satisfied(vector<int> &weights, vector<int> &cur, int k)
{
    if(scalar_multip(weights, cur) > k) //the weight of cur vector is > max
    {
        return false;
    }
    return true;
}

vector<int> supplem(vector<int> &weights, vector<int> &values, int k, int n, vector<int> &init, int &limit)
{
//    cout<<limit<<endl;
    vector<int> cur = Hemm_neighbour(init);
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
vector<int> local_optimum(vector<int> &weights, vector<int> &values, int k, int n, vector<int> &init, int &limit)
{
    vector<int> cur = init;
    while(limit<2*n) //can be changed...?
    {
        
        cur = supplem(weights, values, k, n, cur, limit);
        
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
    cout<<"values in"<<endl;
    
    vector<int> init(n,0); //will always satisfy weight, but not values
    
    int limit = 0;
    vector<int> optimal = local_optimum(weights, values, k, n, init, limit);
    int final_val = scalar_multip(values, optimal);
    cout<< final_val<< " "<< 0<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<optimal[i]<< " ";
    }
    
    return 0;
}



//makefile!!!!!!!


