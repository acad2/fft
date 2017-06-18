#include <bits/stdc++.h>
using namespace std;

unsigned int bitreversed(unsigned int, int);
void printdata(vector< pair<float,float> >);

vector< pair<float, float> > data;

int main(){
  int nn;
  cout<<"enter the number of data points: "; cin>>nn;
  cout<<endl;
  cout<<"enter the data points (in format \"Real Imaginary\") :"<<endl;
  float x,y;
  //figuring out the nearest power of two greater than nn
  int n_data = pow(2,ceil(log2(nn)));

  for(int i=0; i<n_data; i++){
    if(i<nn){
      cin>>x>>y;
      data.push_back(make_pair(x,y));
    }
    //padding with zeros
    else{
      data.push_back(make_pair(0,0));
    }
  }
  cout<<"The original data points: "<<endl;
  printdata(data);
  cout<<bitreversed(8,ceil(log2(nn)))<<endl;
}

void printdata(vector< pair<float,float> > d){
  for(auto itr = d.begin(); itr != d.end(); itr++){
    cout<<itr->first<<"+ j"<<itr->second<<endl;
  }
}

unsigned int bitreversed(unsigned int x, int s){
  unsigned int r = x&1;
  s -= 1;
  for(x = x>>1; x; x >>= 1){
    r <<= 1;
    r |= x & 1;
    s--;
  }
  r <<= s;
  return r;
}
