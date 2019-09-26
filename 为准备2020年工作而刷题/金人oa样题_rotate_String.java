// "static void main" must be defined in a public class.

public class Main {
    public static void main(String[] args) {
        int [] direction= new int[]{0,1,0,0};
        int [] amount= new int[]{1,2,3,5};
        String str="TestingRotation";
        int finalVal=0;
        boolean right=false;
        for(int i=0; i<direction.length;i++){
            if(direction[i]==0)
                finalVal-=amount[i];
            else
                finalVal+=amount[i];
        }
     //   System.out.println(finalVal);
        if(finalVal>=0)
            right=true;
        finalVal=Math.abs(finalVal)%str.length();
        StringBuffer sb= new StringBuffer("");
        int pivot=-1;
        if(right)
            pivot=str.length()-finalVal;    
        else
            pivot=finalVal;
        sb.append(str.substring(pivot,str.length())).append(str.substring(0,pivot));
        System.out.println(sb.toString());
    }
}
