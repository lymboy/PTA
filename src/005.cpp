#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int num,low,first;  //low及格线 first优先线

struct S{ //结构体存输入信息
    int no;
    int de;
    int cai;
};

bool cmp( S x, S y){  //自定义比较函数

    if(x.de+x.cai!=y.de+y.cai)
        return (x.de+x.cai)>(y.de+y.cai);
    else
    if(x.de!=y.de)
        return x.de>y.de;
    else
        return x.no<y.no;
}

int main(){
    S stu;
    vector<S> v1,v2,v3,v4;//v1德才双尽，v2德胜才，v3才德不及，仍德胜才，v4及格线守门员
    int count=0;
    cin>>num>>low>>first;
    for(int i=0;i<num;i++)
    {
        cin>>stu.no>>stu.de>>stu.cai;

        if(stu.de>=low&&stu.cai>=low){ //边输入 边分类
            count++;
            if(stu.de>=first&&stu.cai>=first) //德才双尽
                v1.push_back(stu);
            else  if(stu.de>=first)         //德胜才
                v2.push_back(stu);
            else  if(stu.de>=stu.cai)       //才德兼亡 德胜才
                v3.push_back(stu);
            else
                v4.push_back(stu);      //及格线守门员
        }
    }

    sort(v1.begin(),v1.end(),cmp); //sort函数排序
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);

    cout<<count<<endl;      //及格人数

    for(int i=0;i<v1.size();i++)   //第一类在前，依次输出
        cout<<v1[i].no<<" "<<v1[i].de<<" "<<v1[i].cai<<endl;
    for(int i=0;i<v2.size();i++)
        cout<<v2[i].no<<" "<<v2[i].de<<" "<<v2[i].cai<<endl;
    for(int i=0;i<v3.size();i++)
        cout<<v3[i].no<<" "<<v3[i].de<<" "<<v3[i].cai<<endl;
    for(int i=0;i<v4.size();i++)
        cout<<v4[i].no<<" "<<v4[i].de<<" "<<v4[i].cai<<endl;


    return 0;
}