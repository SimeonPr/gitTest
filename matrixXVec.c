#include <stdio.h>
#include <stdlib.h>


int *matrixTimesVector(int rows, int columns);


int main(int argc, char **argv){
    
    matrixTimesVector(atoi(*(argv+1)),atoi(*(argv+2)));
    return 0;

}

int *matrixTimesVector(int rows, int columns){

    //Allocate Memory

    int *matrix = malloc(sizeof(int) * (rows*columns));
    int *vector = malloc(sizeof(int)*columns);
    int *solutionVector = malloc(sizeof(int)*rows);

    //Get Values for Matrix

    for(int row = 0; row < rows; row++){
        printf("Please type %d values for the %d. row seperated by spaces: ", columns, (row+1));
        for (int column = 0; column < columns; column++) {
        scanf("%d",matrix+(columns*row+column));
        }
    }

    //Get Values for Vector
    
    printf("Please type %d components seperated by spaces: ", columns);
    for (int component = 0; component < columns; component++) {
        scanf("%d",(vector+component));
    }

    //Print formatted problem

    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            printf("%d ",*(matrix+(columns*row+column)));
        }
        printf("| %d\n",*(vector+row));
    }

    //Compute Solution

    for (int row = 0; row < rows; row++){
        int temp = 0;
        for (int column = 0; column < columns; column++){
            temp += *(matrix+column+row*columns) * *(vector+column);
        }
        *(solutionVector+row) = temp;
    }
    //Free Memory

    free(matrix);
    free(vector);

    //Print solution

    for(int row = 0; row < rows; row++){
        if (row == rows/2) printf("Solution:  ");
        else printf("           ");
        printf("%d\n",*(solutionVector+row));
    }
        
    return solutionVector;

}