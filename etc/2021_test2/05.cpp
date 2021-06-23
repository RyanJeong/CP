#include <bits/stdc++.h>

using namespace std;

float getY(float x, float x1, float x2, float y1, float y2)
{
    // y = m(x-x1)+y1
    // y = mx-mx1+y1
    float y, m;

    m=(y2-y1)/(x2-x1);
    y=m*x-m*x1+y1;

    return y;
}

string interpolate(int n, vector<int> instances, vector<float> price) {
    // preprocess, erase zero or negative prices
    for (int i = 0; i<price.size(); ++i) {
        if (price[i]<=0) {
            instances.erase(instances.begin()+i);
            price.erase(price.begin()+i);
            --i;
        }
    }
    
    // get a plot(price) associated with the number of instance(n)
    const int m = price.size();
    char arr[8]; //  1999.99 + '\0'
    memset(arr,0,sizeof arr);
    do {
        if (m==1) {
            snprintf(arr,sizeof arr,"%.2f",price.front());
            break;
        }
        if (n<instances.front()) {
        // case 1. n = 5, instances = {10, 15, ...}
            float x1 = instances[0];
            float y1 = price[0];
            float x2 = instances[1];
            float y2 = price[1];

            snprintf(arr,sizeof arr,"%.2f",getY(n,x1,x2,y1,y2));
            break;
        }
        if (n>instances.back()) {
        // case 2. n = 100, instances = {..., 80, 90}
            float x1 = instances[m-2];
            float y1 = price[m-2];
            float x2 = instances[m-1];
            float y2 = price[m-1];
            
            snprintf(arr,sizeof arr,"%.2f",getY(n,x1,x2,y1,y2));
            break;
        }
        //       V  
        // X 5 _ 7 _ 12 _ 39 _ 54 X
        for (int i = 1; i<m; ++i) {
            if (instances[i]==n) {
            // case 3-1. n = 50, instances = {..., 45, 50, 55, ...}
                snprintf(arr,sizeof arr,"%.2f",price[i]);
                break;
            }
            else if (instances[i]>n) {
            // case 3-2. n = 50, instances = {..., 47, 49, 51, ...}
                float x1 = instances[i-1];
                float y1 = price[i-1];
                float x2 = instances[i];
                float y2 = price[i];

                snprintf(arr,sizeof arr,"%.2f",getY(n,x1,x2,y1,y2));
                break;
            }    
        }
    } while (0);
    string res(arr);

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> instances;
    for (int i = 0; i<m; ++i) {
        int temp;
        cin>>temp;

        instances.push_back(temp);
    }
    cin>>m;
    vector<float> price;
    for (int i = 0; i<m; ++i) {
        float temp;
        cin>>temp;

        price.push_back(temp);
    }
    cout << interpolate(n,instances,price);

    return 0;
}