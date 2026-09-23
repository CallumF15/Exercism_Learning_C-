public class SpiralMatrix
{
    public static int[,] GetMatrix(int size)
    { 
        int[,] numbers = new int[size, size];
        int count = 1;
        int currentRow = 0;
        int currentCol = 0;

        int rowDirection = 0; 
        int colDirection = 1;

        int MatrixSize = size * size;

        for(int i = 0; i < MatrixSize; i++) //loop runs to play the amount of numbers needed for matrix
        {    
            numbers[currentRow, currentCol] = count++;  

            int nextRow = currentRow + rowDirection;   //0
            int nextCol = currentCol + colDirection;   //2 + 1 = 3

            //check to see if the row or col is less or greater than size of matrix 
            //then 'turns' the direction
            if(nextRow < 0 || nextRow >= size || 
               nextCol < 0 ||  nextCol >= size ||  
               numbers[nextRow, nextCol] != 0 )
            {
                int temp = rowDirection;  //0 
                rowDirection = colDirection; //1
                colDirection = -temp;  //0

                nextRow = currentRow + rowDirection;  
                nextCol = currentCol + colDirection; 
            }
            currentRow = nextRow; 
            currentCol = nextCol; 
        }

        return numbers;
    }
}
