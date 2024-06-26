#ifndef VERIFY_SOLUTION_H
#define VERIFY_SOLUTION_H 

int verifyNqueenSolution(char board[N][N])
{	
	char analyze_board[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			analyze_board[i][j] = board[i][j];
		}
	}

	int queen_number = 0;
	bool line_queen = false;

	for (int i = 0; i < N; i++)	
	{	
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'Q')
			{
				analyze_board[i][j] = '-';
				
				queen_number++;
			
				if (!verifyPosition(analyze_board, i, j))
					return -1;
			
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						analyze_board[i][j] = board[i][j];
					}
				}
			}
		}
	}	

	if (queen_number != N)
		return -2;

	return queen_number;
}

#endif