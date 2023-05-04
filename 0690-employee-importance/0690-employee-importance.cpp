/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>m;
        for(int i=0;i<employees.size();i++)
        {
            m[employees[i]->id]=employees[i];
        }
        int ans=0;
       queue<int>q;
       q.push(id);
       ans+=m[id]->importance;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto val:m[node]->subordinates){
               ans+=m[val]->importance;
               q.push(val);
           }
       }
        return ans;
    }
};