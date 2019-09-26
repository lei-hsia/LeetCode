// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        
       int [][] matrix= new int [][]{
           {7,7,3,8,1},
           {13,5,4,5,2},
           {9,2,12,3,9},
           {6,2,1,11,41}
       };
        List<Integer> result= new ArrayList<>();
        spiral(matrix,result);
        for(int num: result){
            System.out.print(num+" ");
        }
    }
    private static void spiral(int [][]matrix, List<Integer> result){
        int row=matrix.length, col=matrix[0].length;
        int startRow=0,endRow=matrix.length-1,startCol=0,endCol=matrix[0].length-1;
        while(startRow<=endRow && startCol<=endCol){

            for(int i=startCol;i<=endCol;i++)
                if(isPrime(matrix[startRow][i]))
                    result.add(matrix[startRow][i]);
            startRow++;

            for(int i=startRow; i<=endRow;i++)
                if(isPrime(matrix[i][endCol]))
                    result.add(matrix[i][endCol]);
            endCol--;
            
            for(int i=endCol;i>=startCol;i--)
                if(isPrime(matrix[endRow][i]))
                    result.add(matrix[endRow][i]);
            endRow--;

            for(int i=endRow; i>=startRow;i--)
                if(isPrime(matrix[i][startCol]))
                    result.add(matrix[i][startCol]);
            startCol++;
        }
    }
    private static boolean isPrime(int x){
        if(x<=1)
            return false;
        for(int i=2; i*i<=x;i++){
            if(x%i==0)
                return false;
        }
        return true;
    }
}
