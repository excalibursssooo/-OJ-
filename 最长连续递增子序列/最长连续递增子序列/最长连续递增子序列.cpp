

#include <iostream>
int a[10001];
int n;
using namespace std;
int k = 0;
int l = 0;
int ans[10001];

int main()
{
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a[i] = num;
    }
    int len=0;
    int len1;
    for (int i = 0; i < n; i++) {
        int left = i;
        int right = left;
        for (int i = left; i < n; i++) {
            if (a[right + 1] > a[i]) {
                right++;
            }
            else {
                    break;
            }
            
        }
        len1 = right - left;
            if (len1 > len) {
                len = len1;
                int j = 0;
                for (int i = left; i <=right; i++) {
                    ans[j] = a[i];
                    j++;
                }
            }
        
        
    }
    for (int i = 0; i <=len; i++) {
        cout << ans[i] << " ";
    }

}

