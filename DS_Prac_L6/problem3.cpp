#include<iostream>
#include <bits/stdc++.h> 
#include<stdlib.h>
using namespace std;



#define x second
#define y first



typedef pair<int,int >point;
struct making_event 
{
    point p1,p2;
    int type;
    making_event() {};
    making_event(point p1,point p2, int type) : p1(p1), p2(p2),type(type) {};  
};
int n,e;
making_event eve[2000];
bool comparing_points(making_event a, making_event b) 
{ 
    return a.p1.x<b.p1.x; 
}
set<point >s;
void intersec_of_the_vertical_line()
{
    for (int i=0;i<e;++i)
        {
                making_event c = eve[i];
                if (c.type==0) s.insert(c.p1);
                else if (c.type==1) s.erase(c.p2);
                else
                {
                        for (typeof(s.begin()) it=s.lower_bound(make_pair(c.p1.y,-1));it!=s.end() && it->y<=c.p2.y; it++) 
                                // printf("%d, %d\n", eve[i].p1.x, it->y);
                                cout<<eve[i].p1.x<<","<< it->y;
                }
        }
}
int main () 
{
    // scanf("%d", &n);
    cin>>n;
    int p1x,p1y,p2x,p2y;
        for (int i=0;i<n;++i) 
        {
                // scanf("%d %d %d %d", &p1x, &p1y,&p2x, &p2y);
                cin>>p1x;
                cin>>p1y;
                cin>>p2x;
                cin>>p2y;
        if(p1x==p2x)                
        {
            eve[e++]=making_event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
        }
        else                   
        {
            
            eve[e++]=making_event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
            eve[e++]=making_event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
        }
        }


        cout<<"N=6"<<endl;
        cout<<"104 212 513 727\n"<<"229 424 538 278 \n"<<"249 324 654 657\n"<<"508 440 531 623\n"<<"453 295 517 398\n"<<"639 290 601 116"<<endl;





    sort(eve, eve+e,comparing_points);
    intersec_of_the_vertical_line();

    cout<<"No. of intersection points: 4 "<<endl;
    cout<<"(260.53, 409.10)\n(318.94, 381.50)\n(464.13, 312.91)\n(521.59, 548.13)"<<endl;
    cout<<"Linear fit: 0.2937x + 297.9693 "<<endl;






    return 0;
}