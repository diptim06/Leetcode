class Solution {
public:
    int daysnumber(string date,int cal[]){
        // we know the position of the - mark i.e 2
        int a=stoi(date.substr(0,2));//month
        int b=stoi(date.substr(3,2));//date
        
        if(a==1) return b;
        return cal[a-2]+b; 
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int cal[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<12;i++){
            cal[i]+=cal[i-1];
        }
        
        //converting the given string into days number of the year
        int arrivealice=daysnumber(arriveAlice,cal);
        int leavealice=daysnumber(leaveAlice,cal);
        int arrivebob=daysnumber(arriveBob,cal);
        int leavebob=daysnumber(leaveBob,cal);
        //ex.   148 152       150 154    output=3
        //min of leave - max of arrive = 152-150 +1 = 3
        int overlap=min(leavealice,leavebob) - max(arrivealice,arrivebob) +1;
        return max(0,overlap);
    }
};