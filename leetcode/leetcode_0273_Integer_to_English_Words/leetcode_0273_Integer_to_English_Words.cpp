class Solution {
public:
    // giving the names to 1,2,3,4......
    void word(int x, string &s){
        if(x == 1){
            s += "One ";
        }
        else if(x == 2){
            s += "Two ";
        }
        else if(x == 3){
            s += "Three ";
        }
        else if(x == 4){
            s += "Four ";
        }
        else if(x == 5){
            s += "Five ";
        }
        else if(x == 6){
            s += "Six ";
        }
        else if(x == 7){
            s += "Seven ";
        }
        else if(x == 8){
            s += "Eight ";
        }
        else if(x == 9){
            s += "Nine ";
        }
    }
    
    //for ten to nineteen
    void t2n(int x, string &s){
        if(x == 10){
            s += "Ten ";
        }
        else if(x == 11){
            s += "Eleven ";
        }
        else if(x == 12){
            s += "Twelve ";
        }
        else if(x == 13){
            s += "Thirteen ";
        }
        else if(x == 14){
            s += "Fourteen ";
        }
        else if(x == 15){
            s += "Fifteen ";
        }
        else if(x == 16){
            s += "Sixteen ";
        }
        else if(x == 17){
            s += "Seventeen ";
        }
        else if(x == 18){
            s += "Eighteen ";
        }
        else if(x == 19){
            s += "Nineteen ";
        }
    }
    
    /// for 20,30,40,50.....
    void tens(int x, string &s){
        x /= 10;
        if(x == 2){
            s += "Twenty ";
        }
        else if(x == 3){
            s += "Thirty ";
        }
        else if(x == 4){
            s += "Forty ";
        }
        else if(x == 5){
            s += "Fifty ";
        }
        else if(x == 6){
            s += "Sixty ";
        }
        else if(x == 7){
            s += "Seventy ";
        }
        else if(x == 8){
            s += "Eighty ";
        }
        else if(x == 9){
            s += "Ninety ";
        }
    }
    
    void solve(int x, string &s){
        int flag = 0;
        
        if(x/100){
            word(x/100, s);
            s += "Hundred ";
        }
        x %= 100;
        
        if(x/10){
            if(x/10 == 1){
                flag = 1;
                t2n(x, s);
            }
            else{
                tens(x, s);
                x %= 10;
            }
        }
        
        if(x){
            word(x, s);
        }
    }
    
    string numberToWords(int num) {
        if(num == 0)return "Zero";
        
        string s;
        
        if(num / 1000000000){
            int x = num / 1000000000;
            solve(x, s);
            s += "Billion ";
        }
        num %= 1000000000;
        
        if(num / 1000000){
            int x = num / 1000000;
            solve(x, s);
            s += "Million ";
        }
        num %= 1000000;
        
        if(num / 1000){
            int x = num / 1000;
            solve(x, s);
            s += "Thousand ";
        }
        num %= 1000;
        
        solve(num, s);
            
        
        s.pop_back();
        return s;
    }
};