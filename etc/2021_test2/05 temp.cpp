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
    vector<pair<int, float>> v;

    // preprocess
    for (int i = 0; i<price.size(); ++i) {
        if (price[i]>0) {
            v.push_back(make_pair(instances[i],price[i]));
        }
    }

    // find a position which is plotted
    char arr[8]; //  1999.99 + '\0'
    memset(arr,0,sizeof arr);
    if (n<v.front().first) {
    // case 1. n = 5, instances = {10, 15, ...}
        float x1 = v[0].first;
        float y1 = v[0].second;
        float x2 = v[1].first;
        float y2 = v[1].second;

        snprintf(arr,sizeof arr,"%.2f",getY(n,x1,x2,y1,y2));
        cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';
    }
    else if (n>v.back().first) {
    // case 2. n = 100, instances = {..., 80, 90}
        float x1 = v[v.size()-2].first;
        float y1 = v[v.size()-2].second;
        float x2 = v[v.size()-1].first;
        float y2 = v[v.size()-1].second;

        snprintf(arr,sizeof arr,"%.2f",getY(n,x1,x2,y1,y2));
    }
    else {
        //       V  
        // X 5 _ 7 _ 12 _ 39 _ 54 X
        for (int i = 1; i<v.size(); ++i) {
            if (v[i].first==n) {
            // case 3-1. n = 50, instances = {..., 45, 50, 55, ...}
                snprintf(arr,sizeof arr,"%.2f",v[i].second);
                break;
            }
            else if (v[i].first>n) {
            // case 3-2. n = 50, instances = {..., 47, 49, 51, ...}
                float x1 = v[i-1].first;
                float y1 = v[i-1].second;
                float x2 = v[i].first;
                float y2 = v[i].second;

                snprintf(arr,sizeof arr,"%.2f",getY(n,x1,x2,y1,y2));
                break;
            }    
        }
    }
    string res(arr);

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> instances = {
        5,
        10,
        25,
        50,
        100,
        500,
    };
    vector<float> price = {
        5,
        2.46,
        2.58,
        2.0,
        2.25,
        3.0
    };
    /*
    cout << 4 << ' ' << interpolate(4,instances,price) << '\n';
    cout << 25 << ' ' << interpolate(25,instances,price) << '\n';
    cout << 499 << ' ' << interpolate(499,instances,price) << '\n';
    cout << 501 << ' ' << interpolate(501,instances,price) << '\n';
    */
    
    int n = 2;
    vector<float> price1={
        5,
        0.0,
        0.0,
        0.0,
        0.0,
        54.25
    };
    cout << n << ' ' << interpolate(n,instances,price1) << '\n';

    n=1999;
    vector<float> price2={
        5,
        27.32,
        23.13,
        21.25,
        18.0,
        15.5
    };
    /*
    cout << n << ' ' << interpolate(n,instances,price2) << '\n';
    */

    return 0;
}