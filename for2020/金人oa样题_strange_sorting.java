// "static void main" must be defined in a public class.

public class Main {
    public static void main(String[] args) {
        int [] mapping = new int []{3,5,4,6,2,7,9,8,0,1};
        String [] arr= new String[]{"990","332","32"};
        
        Arrays.sort(arr,(str1,str2)->(transform(str1,mapping)-transform(str2,mapping)));
        
        for(String str: arr){
            System.out.print(str+" ");
        }
    }
    
    private static int transform(String str, int[] mapping){
        int res=0;
        for(int i=0; i<str.length();i++){
            res+=indexOf(str.charAt(i)-'0',mapping);
            res*=10;
        }
        return res/=10;
    }
    private static int indexOf(int elem,int [] map){
        for(int i=0; i<map.length;i++)
            if(elem==map[i])
                return i;
        return -1;
    }
}
