public class GFG {
    GFG(int x){
        x = (5+10)+((2+3)+((4+5)+(3+4)));
        // t0 = 5+10
        // t1 = 2+3
        // t2 = 4+5
        // t3 = 3+4
    }
    GFG(){
        int x = 5+10;
    }
    public 
    static void main(){
        GFG gfg = new GFG(2);
        int a = 1, b = 2, c = 3, d = 4;
        a = b * c / d;
        a %= b;
        
        if (a == 1) {
            if (b == 2) {
                if (c == 3) {
                    if (d >= 4) {
                        d=5;
                    }
                }
            }
        }
        while(a<10){
            a++;
            for(int i=0;i<10;i++){
                if(i==5){
                    break;
                }
            }
        }
    }
}
