#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    srand(time(0));
    vector<int> v;

    for (int i = 0; i < 20; i++){
        v.push_back(rand()%100-50);
    }

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }cout << endl;
    
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++){
        cout  << *it << " ";
    }cout << endl;
    
    for (int item : v){
        cout << item << " ";
    }cout << endl;
    
    for (int& item : v){
        cout << item << " ";
    }cout << endl;

    for (auto& item : v){
        cout << item << " ";
    }cout << endl;

    cout << "========================\n";
    cout << "Task 1\n";

    it = v.begin() + v.size() / 2;
    it = v.insert(it, 6, 0);

    for (int item : v){
        cout << item << " ";
    }cout << endl;

    cout << "========================\n";
    cout << "Task 2\n";

    v.erase(v.begin() + v.size() / 2, v.end());

    for (int item : v){
        cout << item << " ";
    }cout << endl;

    cout << "========================\n";
    cout << "Task 3\n";

    cout << "Max: " << *max_element(v.begin(), v.end()) << endl;

    cout << "========================\n";
    cout << "Task 4\n";

    replace_if(v.begin(), v.begin() + v.size() / 2, [](int item){return item < 0;}, -1);
    replace_if(v.begin() + v.size() / 2, v.end(), [](int item){return item > 0;}, 1);

    for (int item : v){
        cout << item << " ";
    }cout << endl;

    cout << "========================\n";
    cout << "Task 5\n";

    remove_if(v.begin(), v.begin() + v.size() / 2, [](int item){return item == -1;});

    for (int item : v){
        cout << item << " ";
    }cout << endl;

    cout << "========================\n";
    cout << "Task 6\n";

    v[2] = 0;
    v[4] = 0;

    for (int item : v){
        cout << item << " ";
    }cout << endl;

    it = find(v.begin(), v.end(), 0);
    if (it == v.end()){
        cout << "no 0";
    }else{
        it = find(it+1, v.end(), 0);
        if (it == v.end()){
            cout << "no second 0";
        }else{
            v.erase(it);
        }
    }
    
    for (int item : v){
        cout << item << " ";
    }cout << endl;
    

    return 0;
}