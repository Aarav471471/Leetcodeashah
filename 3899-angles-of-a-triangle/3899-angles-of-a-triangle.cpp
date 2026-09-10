class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        sort(sides.begin(),sides.end());
      if(sides[0]>=sides[1]+sides[2]){
        return {};
      }  
      if(sides[1]>=sides[0]+sides[2]){
        return {};
      }
      if(sides[2]>=sides[1]+sides[0]){
        return {};
      }
      double s=((double)sides[0]+(double)sides[1]+(double)sides[2])/2.0;
      double area=s*(s-(double)sides[0])*(s-(double)sides[1])*(s-(double)sides[2]);
      area=sqrt(area);
      double base=(double)sides[2];
      double h=(area/(base))*2.0;
    //   cout<<area<<" ";
    //   cout<<h;
      ans.push_back((asin(h/(double)sides[0])*180)/M_PI);
    //   cout<<ans[0]<<" ";
      ans.push_back((asin(h/(double)sides[1])*180)/M_PI);
    //   cout<<ans[1]<<" ";
    ans.push_back((180.0-ans[0]-ans[1]));
    sort(ans.begin(),ans.end());
    return ans;
    }
};