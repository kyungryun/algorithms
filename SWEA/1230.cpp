#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main() {
    int n;

    for(int t = 1; t <= 10; t++) {
      vector<string> pass;
      int op;
      scanf("%d",&n);
      for(int i=0 ; i<n ; i++){
        string temp;
        cin>>temp;
        pass.push_back(temp);
      }

      scanf("%d",&op);
      char in;
      int start, copy;
      for(int i=0 ; i<op ; i++){
        vector<string> add;
        scanf(" %c",&in);
        if(in == 'I'){
          scanf("%d%d",&start,&copy);
          for(int j=0 ; j<copy ; j++){
            string temp;
            cin>>temp;
            add.push_back(temp);
          }
          auto it = pass.begin();
          pass.insert(it+start, add.begin(), add.end());
        }else if(in == 'D'){
          scanf("%d%d",&start,&copy);

          auto it = pass.begin();
          pass.erase(it+start, it+start+copy);
        }else if(in == 'A'){
          scanf("%d",&copy);
          for(int j=0 ; j<copy ; j++){
            string temp;
            cin>>temp;
            pass.push_back(temp);
          }
        }

      }
      printf("#%d ", t);
      for(int i=0 ; i<10 ; i++)cout<<pass[i]<<" ";
      printf("\n");
    }
}
