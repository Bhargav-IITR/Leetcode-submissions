class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }

    void unite(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;

        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pv]<rank[pu])
            parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();
        DSU dsu(n);

        unordered_map<string,int> mailToAcc;

        // Step 1: union accounts sharing email
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){

                string mail=accounts[i][j];

                if(mailToAcc.count(mail)==0)
                    mailToAcc[mail]=i;
                else
                    dsu.unite(i, mailToAcc[mail]);
            }
        }

        // Step 2: collect emails by parent
        unordered_map<int,set<string>> mp;

        for(auto &it: mailToAcc){
            string mail=it.first;
            int acc=it.second;

            int parent=dsu.findParent(acc);

            mp[parent].insert(mail);
        }

        // Step 3: build answer
        vector<vector<string>> ans;

        for(auto &it: mp){

            int accIndex=it.first;

            vector<string> temp;

            temp.push_back(accounts[accIndex][0]);

            for(auto &mail: it.second)
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};