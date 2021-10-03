#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) { 
        double weight; 
        cin>>weight; 
        
        if (weight<0.0) { 
            break; 
        } 
        cout << fixed;
        cout.precision(2);
        cout << "Objects weighing " << weight << " on Earth will weigh " << weight*0.167 << " on the moon." << '\n';
    }

    return 0;
}