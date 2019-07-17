#include<bits/stdc++.h>

using namespace std;
class Box {
private:
    int l, b, h;

public:
    Box() { l = 0, b = 0, h = 0; }
    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }
    Box(const Box & other) {
        l = other.l;
        b = other.b;
        h = other.h;
    }
    int getLength()  { return l; }
    int getBreadth() { return b; }
    int getHeight()  { return h; }
    long long CalculateVolume() {
        long long l_long = l, b_long = b, h_long = h;
        return l_long * b_long * h_long;
    }

    bool operator < (Box &b) {
        if (getLength() == b.getLength()) {
            if (getBreadth() == b.getBreadth()) {
                return (getHeight() < b.getHeight());
            }
            return (getBreadth() < b.getBreadth());
        }
        return (getLength() < b.getLength());
    }
};

ostream & operator << (ostream &out, Box &A) {
    out << A.getLength() << ' ' << A.getBreadth() << ' ' << A.getHeight();
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}