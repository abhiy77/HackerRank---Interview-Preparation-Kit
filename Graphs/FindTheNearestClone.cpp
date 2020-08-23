#include <bits/stdc++.h>

using namespace std;

#define MAX 1000003
using namespace std;

vector<int> v[MAX];
bool visit[MAX];
int a[MAX],c,id;
vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

void bfs(int i)
{
    memset(visit, false, sizeof visit);
    queue<pair<int,int> > q;
    pair<int,int> p;
    q.push({i,0});
    visit[i]=true;

    while(!q.empty()) {
        p=q.front();
        q.pop();
        for(auto x: v[p.first]) {
            if(!visit[x]) {
                if(a[x] == id) {
                    c=p.second+1;
                    return;
                }
                visit[x]=true;
                q.push({x,p.second+1});
            }
        }
    } 
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    for(auto i =0;i<graph_from.size();i++){
        cout << graph_from[i] << " " ;
    }
    for(auto i=0;i<graph_from.size();i++){
        v[graph_from[i]-1].push_back(graph_to[i]-1);
        v[graph_to[i]-1].push_back(graph_from[i]-1);
    }
    int i = 0;
    int n = graph_nodes;
    int ans=1e9;
    for(i=0;i<n;++i) {
        if(ids[i]==id) {
            c=1e9;
            bfs(i);
            ans=min(ans, c);
        }
    }
    if(ans==1e9) {
        ans=-1;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000003
using namespace std;

vector<int> v[MAX];
bool visit[MAX];
int a[MAX],c,id;
vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

void bfs(int i)
{
    memset(visit, false, sizeof visit);
    queue<pair<int,int> > q;
    pair<int,int> p;
    q.push({i,0});
    visit[i]=true;

    while(!q.empty()) {
        p=q.front();
        q.pop();
        for(auto x: v[p.first]) {
            if(!visit[x]) {
                if(a[x] == id) {
                    c=p.second+1;
                    return;
                }
                visit[x]=true;
                q.push({x,p.second+1});
            }
        }
    } 
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    for(auto i =0;i<graph_from.size();i++){
        cout << graph_from[i] << " " ;
    }
    for(auto i=0;i<graph_from.size();i++){
        v[graph_from[i]-1].push_back(graph_to[i]-1);
        v[graph_to[i]-1].push_back(graph_from[i]-1);
    }
    int i = 0;
    int n = graph_nodes;
    int ans=1e9;
    for(i=0;i<n;++i) {
        if(ids[i]==id) {
            c=1e9;
            bfs(i);
            ans=min(ans, c);
        }
    }
    if(ans==1e9) {
        ans=-1;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}