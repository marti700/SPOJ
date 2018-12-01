#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int MALE = 1; 
const int FEMALE = 2;
const int UNDEFINED_SEX = 0; 


map<int,int> bug_gender_registry;


/**
 * assigns a sex to a interaction partner
 * returns opposite sex of the one specified as argument 
 **/
int assign_sex(int sex){
    if(sex == MALE)
        return FEMALE;
    else
        return MALE;
}

/**
    uses BFS and coloring to find out if the graph formed by bug interactions
    is bipartite.

    args: a map based adjacency list which key is the bug number and the value a vector containing all the bugs
    with which the bug in the key have intereacted with
    returns true if graph is not bipartite (suspicios interaction found) and false otherwise
**/
bool is_suspicious_interaction(map<int, vector<int>> &interactions){
    /*
        since graph can be disconected keys in the interactions adjacency list are deleted after being processed
        this way if this function recives a disconected graph the BFS algorithm will be restarted with the 
        first element of the interaction adjacency list (the value returnded by interactions.begin())
    */
    queue<int> tracker;

    while(!interactions.empty()){
    tracker.push(interactions.begin()->first);
        while(!tracker.empty()){
            if(interactions.find(tracker.front()) != interactions.end()){
                for(int i=0; i<interactions.find(tracker.front())->second.size(); ++i){
                    if(bug_gender_registry.find(tracker.front()) -> second == UNDEFINED_SEX &&  
                    bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second == UNDEFINED_SEX){
                        bug_gender_registry.find(tracker.front()) -> second = MALE;
                    bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second = FEMALE; 
                }
                    else if(bug_gender_registry.find(tracker.front()) -> second != UNDEFINED_SEX && 
                    bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second == UNDEFINED_SEX){
                        bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second = assign_sex(bug_gender_registry.find(tracker.front()) -> second);
                    }
                    else if (bug_gender_registry.find(tracker.front()) -> second == UNDEFINED_SEX && 
                    bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second != UNDEFINED_SEX){
                        bug_gender_registry.find(tracker.front()) -> second = assign_sex(bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second);
                    }
                    else if (bug_gender_registry.find(tracker.front()) -> second == bug_gender_registry.find(interactions.find(tracker.front())->second[i]) -> second) {
                        return true;
                    }
                    tracker.push(interactions.find(tracker.front()) -> second[i]);
                }
                interactions.erase(tracker.front());
                tracker.pop();
            }
            else {
                tracker.pop();
            }
        }
    }
    return false;
}

int main (){

    ios_base::sync_with_stdio(false);
    int scenarios,bugs, interactions, bug1, bug2;
    map<int, vector<int>> adjacency_list;

    cin>>scenarios;
    for(int i=0; i<scenarios; ++i){
        cin>>bugs>>interactions;
        //build adjacency list
        for(int j=0;j<interactions;++j){
            cin>>bug1>>bug2;
            adjacency_list[bug1].push_back(bug2);
            adjacency_list[bug2].push_back(bug1);
        bug_gender_registry[bug1] = UNDEFINED_SEX;
        bug_gender_registry[bug2] = UNDEFINED_SEX;
    }

    cout<<"Scenario #"<<i+1<<":"<<endl;
    if(is_suspicious_interaction(adjacency_list))
        cout<<"Suspicious bugs found!"<<endl;
    else
        cout<<"No suspicious bugs found!"<<endl;
    
    adjacency_list.clear();
    
    }
    return 0;
}