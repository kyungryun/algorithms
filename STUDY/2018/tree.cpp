#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct NODE{
    NODE *left;
    NODE *right;
    int id;
    int x;
    int y;
    NODE(){
        left = NULL;
        right = NULL;
    }
};

bool comp(NODE a, NODE b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}
void preorder(NODE *node, vector<int> &order){
    order.push_back(node->id);
    if(node->left != NULL) preorder(node->left, order);
    if(node->right != NULL) preorder(node->right, order);
}
void postorder(NODE *node, vector<int> &order){
    if(node->left != NULL) postorder(node->left, order);
    if(node->right != NULL) postorder(node->right, order);
    order.push_back(node->id);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<NODE> tree;
    NODE temp;
    for(int i=0 ; i<nodeinfo.size() ; i++){
        temp.id = i+1;
        temp.x = nodeinfo[i][0];
        temp.y = nodeinfo[i][1];
        tree.push_back(temp);
    }
    sort(tree.begin(), tree.end(), comp);
    NODE node = tree[0];
    NODE *it;
    for(int i=1 ; i<tree.size() ; i++){
        it = &node;
        while(1){
            if(it->x > tree[i].x){
                if(it->left == NULL){
                    it->left = new NODE(tree[i]);
                    break;
                }else it = it->left;
            }else{
                if(it->right == NULL){
                    it->right = new NODE(tree[i]);
                    break;
                }else it = it->right;
            }
        }
    }
    vector<int> order;
    preorder(&node, order);
    answer.push_back(order);
    order.clear();
    postorder(&node, order);
    answer.push_back(order);
    return answer;
}
