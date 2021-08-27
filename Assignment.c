#include <stdio.h>
#include <stdlib.h>
//So basically I have implemented the game of life using basic CLI(Command Line Input) in the C langunage
//here the user or the player can change the values of rows and coloumns to set the canvas size and then we randomly assign values to some positions and then use it to determine or find the next generation of that particular matrix 
int row ;
int col ;

//creates row boundary
//a function for creating row border
int row_border(){
	printf("\n");
	for(int i=0; i<col; i++){printf(" -----");}
	printf("\n");
}

//returns the count of alive neighbours
int count_the_live_neighbour_cell(int ar[row][col], int r, int c){
	int i, j, count=0;
	for(i=r-1; i<=r+1; i++){
		for(j=c-1;j<=c+1;j++){
			if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
				continue;
			}
			if(ar[i][j]==1){
				count++;
			}
		}
	}
	return count;
}
//main function
int main(){
    
printf("Enter the value of row and coloumn");
scanf("%d %d",&row , &col);
	int ar[row][col], br[row][col];
	int i,j;
	int neighbour_live_cell;

	//generate matrix canvas with random values (live and dead cells)
	for(i=0; i<row; i++){
		for(j=0;j<col;j++){
			ar[i][j] = rand() % 2;
		}
	}
	
	//print array matrix
	printf("Initial Stage:");
	row_border();
	for(i=0; i<row; i++){
		printf(":");
		for(j=0;j<col;j++){
			printf(" %d :",ar[i][j]);
		}
		row_border();
	}

	//next canvas values based on live neighbour count
	for(i=0; i<row; i++){
		for(j=0;j<col;j++){
			neighbour_live_cell = count_the_live_neighbour_cell(ar,i,j);
			if(ar[i][j]==1 && (neighbour_live_cell==2 || neighbour_live_cell==3)){
				br[i][j]=1;
			}

			else if(ar[i][j]==0 && neighbour_live_cell==3){
				br[i][j]=1;
			}

			else{
				br[i][j]=0;
			}
		}
	}

	//for printing the next generation
	printf("\nNext Generation:");
	row_border(row);
	for(i=0; i<row; i++){
		printf(":");
		for(j=0;j<col;j++){
			printf(" %d :",br[i][j]);
		}
		row_border(row);
	}

	return 0;
}

/*
###################################### OUTPUT ####################################
Initial Stage:
----- ----- ----- -----
: 1 : 1 : 0 : 0 :
----- ----- ----- -----
: 1 : 0 : 0 : 0 :
----- ----- ----- -----
: 0 : 0 : 1 : 1 :
----- ----- ----- -----
: 1 : 1 : 1 : 1 :
----- ----- ----- -----
: 1 : 0 : 1 : 0 :
----- ----- ----- -----

Next Generation:
----- ----- ----- -----
: 1 : 1 : 0 : 0 :
----- ----- ----- -----
: 1 : 0 : 1 : 0 :
----- ----- ----- -----
: 1 : 0 : 0 : 1 :
----- ----- ----- -----
: 1 : 0 : 0 : 0 :
----- ----- ----- -----
: 1 : 0 : 1 : 1 :
----- ----- ----- -----

*/
