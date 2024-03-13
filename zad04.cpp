#include <iostream>

static int last_id = 0;

class Student{
public:
    char name[5];
    float s;
    int d, m, id;
    Student(){
        id = last_id++;
    }
};

bool compare(const Student& a, const Student& b, char sort_c[3]);
void ShakeSort(Student arr[], unsigned int n, char sort_c[]);

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    char sortConfig[3];
    std::cin >> n >> sortConfig[0] >> sortConfig[1] >> sortConfig[2];

    Student boys[n], girls[n];

    for(int i = 0; i < n; i++)
        std::cin >> boys[i].name >> boys[i].s >> boys[i].d >> boys[i].m
        >> girls[i].name >> girls[i].s >> girls[i].d >> girls[i].m;

    ShakeSort(boys, n, sortConfig);
    ShakeSort(girls, n, sortConfig);

    for(int i = 0; i < n; i++)
        std::cout << boys[i].name << ' ' << girls[i].name << ' ';

    return 0;
}

bool compare(const Student& a, const Student& b, char sort_c[3]){

    if(sort_c[0] == 's' && sort_c[1] == 'd' && sort_c[2] == 'm'){
        if(a.s != b.s)
            return a.s > b.s;
        else if(a.d != b.d)
            return a.d > b.d;
        else if(a.m != b.m)
            return a.m > b.m;
    }

    else if(sort_c[0] == 's' && sort_c[2] == 'd' && sort_c[1] == 'm'){
        if(a.s != b.s)
            return a.s > b.s;
        else if(a.m != b.m)
            return a.m > b.m;
        else if(a.d != b.d)
            return a.d > b.d;
    }

    else if(sort_c[1] == 's' && sort_c[0] == 'd' && sort_c[2] == 'm'){
        if(a.d != b.d)
            return a.d > b.d;
        else if(a.s != b.s)
            return a.s > b.s;
        else if(a.m != b.m)
            return a.m > b.m;
    }

    else if(sort_c[1] == 's' && sort_c[2] == 'd' && sort_c[0] == 'm'){
        if(a.m != b.m)
            return a.m > b.m;
        else if(a.s != b.s)
            return a.s > b.s;
        else if(a.d != b.d)
            return a.d > b.d;
    }

    else if(sort_c[2] == 's' && sort_c[0] == 'd' && sort_c[1] == 'm'){
        if(a.d != b.d)
            return a.d > b.d;
        else if(a.m != b.m)
            return a.m > b.m;
        else if(a.s != b.s)
            return a.s > b.s;
    }

    else if(sort_c[2] == 's' && sort_c[1] == 'd' && sort_c[0] == 'm'){
        if(a.m != b.m)
            return a.m > b.m;
        else if(a.d != b.d)
            return a.d > b.d;
        else if(a.s != b.s)
            return a.s > b.s;
    }
    
    return a.id < b.id;    
}

void ShakeSort(Student arr[], unsigned int n, char sort_c[]){
    unsigned int left=0, right=n-1, lastSwap=n-1;
    Student temp;
    do {
        int i=right;
        while (i>left){
            if (compare(arr[i],arr[i-1], sort_c)) {
                temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                lastSwap=i;
            }
            i--;
        }

        left=lastSwap;
        
        i=left;
        while (i<right){
            if (compare(arr[i+1],arr[i], sort_c)){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                lastSwap=i;
            }
            i++;
         }
        right=lastSwap;
    }while (left<right);
    return;
}