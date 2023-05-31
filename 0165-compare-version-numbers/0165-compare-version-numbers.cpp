class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>s1,s2;
        string temp="";
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                s1.push_back(temp);
                temp="";
            }
            else{
                temp.push_back(version1[i]);
            }
        }
        s1.push_back(temp);
        temp="";
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                s2.push_back(temp);
                temp="";
            }
            else{
                temp.push_back(version2[i]);
            }
        }
        s2.push_back(temp);
        if(s1.size()==s2.size()){
            int i=0,j=0;
            while(i<s1.size() && j<s2.size()){
                if(stoi(s1[i])>stoi(s2[j])){
                    return 1;
                }
                else if(stoi(s1[i])<stoi(s2[j])){
                    return -1;
                }
                i++,j++;
            }
            return 0;
        }
        else if(s1.size()>s2.size()){
            int i=0,j=0;
            while(i<s1.size() && j<s2.size()){
                if(stoi(s1[i])>stoi(s2[j])){
                    return 1;
                }
                else if(stoi(s1[i])<stoi(s2[j])){
                    return -1;
                }
                i++,j++;
            }
            int k=s2.size();
            int val=0;
            while(k<s1.size()){
                if(stoi(s1[k])>val){
                    return 1;
                }
                else if(stoi(s1[k])<val){
                    return -1;
                }
                k++;
            }
            return 0;
        }
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(stoi(s1[i])>stoi(s2[j])){
                return 1;
            }
            else if(stoi(s1[i])<stoi(s2[j])){
                return -1;
            }
            i++,j++;
        }
        int k=s1.size();
        int val=0;
        while(k<s2.size()){
            if(stoi(s2[k])>val){
                return -1;
            }
            else if(stoi(s2[k])<val){
                return 1;
            }
            k++;
        }
        return 0;
    }
};