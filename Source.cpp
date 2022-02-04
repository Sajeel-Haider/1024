#include<iostream>
#include<cstdlib>
#include<ctime>
#include"mygraphics.h"
#include"myconsole.h"
#include<conio.h>

using namespace std;
const int row = 4;
const int col = 4;


void numbers(int number, int x, int y, int ht)
{
	COLORREF random = RGB(255, 255, 255);
	switch (number)
	{
	case 0:
		myEllipse(x, y, x + ht, y + ht, random, random);
		myEllipse(x + 3, y + 3, x + ht - 3, y + ht - 3, COLORREF(RGB(0, 0, 0)), COLORREF(RGB(0, 0, 0)));
		break;

	case 1:
		myLine(x, y, x, y + ht, random);
		break;

	case 2:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + ht, y + ht / 2, random);
		myLine(x + ht, y + ht / 2, x, y + ht / 2, random);
		myLine(x, y + ht / 2, x, y + ht / 2 + 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		break;

	case 3:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + ht, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x + ht, y + 4 * ht / 5 + 2, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		break;

	case 4:
		myLine(x, y, x, y + 3 * ht / 5, random);
		myLine(x, y + 3 * ht / 5, x + ht, y + 3 * ht / 5, random);
		myLine(x + 2 * ht / 5, y + ht / 4, x + 2 * ht / 5, y + 4 * ht / 5 + 3, random);
		break;

	case 5:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x, y + 3 * ht / 5, random);
		myLine(x + ht, y + 3 * ht / 5, x + ht, y + 4 * ht / 5, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		break;

	case 6:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht + ht / 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		myLine(x + ht, y + ht + ht / 5, x + ht, y + ht / 2, random);
		myLine(x + ht, y + ht / 2, x, y + ht / 2, random);
		break;

	case 7:
		myLine(x, y, x + ht, y, random);
		myLine(x + ht, y, x + 4 * ht / 5, y + ht, random);
		break;

	case 8:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht + ht / 4, random);
		myLine(x + ht, y, x + ht, y + ht + ht / 4, random);
		myLine(x, y + ht + ht / 4, x + ht, y + ht + ht / 4, random);
		myLine(x, y + 3 * ht / 5, x + ht, y + 3 + ht / 4, random);
		break;

	case 9:
		myLine(x, y, x + ht, y, random);
		myLine(x, y, x, y + ht / 2, random);
		myLine(x + ht, y, x + ht, y + ht + ht / 5, random);
		myLine(x, y + ht + ht / 5, x + ht, y + ht + ht / 5, random);
		myLine(x, y + ht / 2, x + ht, y + 3 + ht / 5, random);
		break;
	}
}
void printNumber(int number, int x, int y, int ht) 
{
	int printable = number;
	int i = 0;
	while (printable >= 10)
	{
		numbers(printable % 10, x - (i++ * 20), y, ht);
		printable /= 10;
	}
	numbers(printable, x - (i++ * 20), y, ht);
}
void printScore(int number, int x, int y, int ht)
{
	int printable = number;
	int i = 0;
	while (printable >= 10)
	{
		numbers(printable % 10, x - (++i * 30), y, ht);
		printable /= 10;
	}
	numbers(printable, x - (++i * 30), y, ht);
}
void drawGrid(int nums[][4], int row)
{
	int x1, x2, y1, y2, size;
	size = 100;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			x1 = (i * size) + 100;
			y1 = (j * size) + 150;
			x2 = ((i + 1) * size) + 100;
			y2 = ((j + 1) * size) + 150;
			myRect(x1, y1, x2, y2, COLORREF(RGB(0, 255, 255)), COLORREF(RGB(100, 100, 100)));
			if (nums[i][j] != 0)
			{
				printNumber(nums[i][j], x1 + (size-20), y1 + 35, 15);
			}
		}
	}

}
void placeRandomly(int nums[][col], int r)
{
	int ri = rand() % r;
	int rj = rand() % col;
	int size = row*col;
	int i = 0;
	while (nums[ri][rj] != 0&&i<size)
	{
		ri = rand() % r;
		rj = rand() % col;
		i++;
	}
	if (i < size)
	{
		nums[ri][rj] = (rand() % 2) + 1;
	}
	
}
void swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void shiftDown(int nums[][col], int ri, int ci)
{
	for (int j = ci; j > 0; j--) 
	{
		swap(nums[ri][j], nums[ri][j - 1]);
	}
}
bool checkIfAllZero(int nums[][col], int r, int col)
{
	bool skip = true;
	for (int j = 0; j < col; j++) 
	{
		skip = skip && (nums[r][j] == 0);
	}
	return skip;
}
bool checkIfRemainingRowZero(int nums[][col], int r, int ci, int col)
{
	bool skip = true;
	for (int j = ci; j >= 0; j--)
	{
		skip = skip && (nums[r][j] == 0);
	}
	return skip;
}
bool checkIfUpSideZero(int nums[][col], int r, int ci, int col)
{
	bool skip = true;
	for (int j = ci; j < col; j++) 
	{
		skip = skip && (nums[r][j] == 0);
	}
	return skip;
}
void shiftUp(int nums[][col], int ri, int ci)
{
	for (int j = ci; j < col - 1; j++)
	{
		swap(nums[ri][j], nums[ri][j + 1]);
	}
}
void handleShiftDown(int nums[][col], int ri, int col)
{
	for (int j = col - 1; j > 0; j--) 
	{
		while (nums[ri][j] == 0 && !checkIfRemainingRowZero(nums, ri, j, col))
        {
			shiftDown(nums, ri, j);
		}
	}
}
void handleShiftUp(int nums[][col], int ri, int col)
{
	for (int j = 0; j < col; j++) 
	{
		while (nums[ri][j] == 0 && !checkIfUpSideZero(nums, ri, j, col))
		{
			shiftUp(nums, ri, j);
		}
	}
}
bool checkIfAllColumnZero(int nums[][col], int row, int c)
{
	bool skip = true;
	for (int i = 0; i < row; i++)
	{
		skip = skip && (nums[i][c] == 0);
	}
	return skip;
}
bool checkIfLeftSideZero(int nums[][col], int ri, int c, int row)
{
	bool skip = true;
	for (int i = ri; i < row; i++) 
	{
		skip = skip && (nums[i][c] == 0);
	}
	return skip;
}
bool checkIfRightSideZero(int nums[][col], int ri, int c, int row)
{
	bool skip = true;
	for (int i = ri; i >= 0; i--)
	{
		skip = skip && (nums[i][c] == 0);
	}
	return skip;
}
void shiftLeft(int nums[][col], int ri, int ci)
{
	for (int i = ri; i < row - 1; i++)
	{
		swap(nums[i][ci], nums[i + 1][ci]);
	}
}
void shiftRight(int nums[][col], int ri, int ci)
{
	for (int i = ri; i > 0; i--) 
	{
		swap(nums[i][ci], nums[i - 1][ci]);
	}
}

void handleShiftLeft(int nums[][col], int ci, int col)
{
	for (int i = 0; i < row; i++) 
	{
		while (nums[i][ci] == 0 && !checkIfLeftSideZero(nums, i, ci, col)) 
		{
			shiftLeft(nums, i, ci);
		}
	}
}
void handleShiftRight(int nums[][col], int ci, int col)
{
	for (int i = row - 1; i > 0; i--) 
	{
		while (nums[i][ci] == 0 && !checkIfRightSideZero(nums, i, ci, col))
		{
			shiftRight(nums, i, ci);
		}
	}
}
bool isGridFull(int nums[][col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (nums[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool ifMatchExists(int arr[][col])
{
	int nums[row][col];
	bool match = false;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			nums[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!checkIfAllZero(nums, i, col))
		{
			handleShiftUp(nums, i, col);
		}
		for (int j = 0; j < col - 1; j++)
		{
			if (nums[i][j] == nums[i][j + 1] && nums[i][j] != 0)
			{
				
				nums[i][j] += nums[i][j + 1];
				nums[i][j + 1] = 0;
				match = true;
			}
		}
		if (!checkIfAllZero(nums, i, col))
		{
			handleShiftUp(nums, i, col);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!checkIfAllZero(nums, i, col)) {
			handleShiftDown(nums, i, col);
		}
		for (int j = 3; j > 0; j--)
		{
			if (nums[i][j] == nums[i][j - 1] && nums[i][j] != 0) {
		
				nums[i][j] += nums[i][j - 1];
				nums[i][j - 1] = 0;
				match = true;
			}
		}
		if (!checkIfAllZero(nums, i, col)) {
			handleShiftDown(nums, i, col);
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (!checkIfAllColumnZero(nums, row, j)) {
			handleShiftLeft(nums, j, row);
		}
		for (int i = 0; i < row - 1; i++)
		{
			if (nums[i][j] == nums[i + 1][j] && nums[i][j] != 0) {
		
				nums[i][j] += nums[i + 1][j];
				nums[i + 1][j] = 0;
				match = true;
			}
		}
		if (!checkIfAllColumnZero(nums, row, j)) {
			handleShiftLeft(nums, j, row);
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (!checkIfAllColumnZero(nums, row, j)) {
			handleShiftRight(nums, j, row);
		}
		for (int i = row - 1; i > 0; i--)
		{
			if (nums[i][j] == nums[i - 1][j] && nums[i][j] != 0) {
	
				nums[i][j] += nums[i - 1][j];
				nums[i - 1][j] = 0;
				match = true;
			}
		}
		if (!checkIfAllColumnZero(nums, row, j)) {
			handleShiftRight(nums, j, row);
		}
	}
	return match;
}
bool checkWin(int nums[][col],int row,bool checkBeforeGrid)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (nums[i][j] == 1024)
			{
				char winGrid[] = "You Win !! \nCONGRATULATIONS\n";
				myDrawTextWithFont(200, 200, 100, winGrid, COLORREF RGB(0, 0, 0), COLORREF RGB(255, 255, 255));
				return true;
			}
		}
	}
	return false;
}
void move(int nums[][col], int r)
{
	int score = 0;
	int begin = true;
	while (begin)
	{
		char scoreCalculate[] = "Score: ";
		myRect(500, 200, 1000, 300, COLORREF(RGB(0, 0, 0)), COLORREF(RGB(0, 0, 0)));
		myDrawTextWithFont(600, 200, 40, scoreCalculate, COLORREF(RGB(130, 130, 130)), COLORREF(RGB(0, 0, 0)));
		printScore(score, 930, 210, 20);
		drawGrid(nums, 4);
		COLORREF white = RGB(255, 255, 255);
		COLORREF black = RGB(0, 0, 0);
		char instruc1[] = "Press e to exit\nYou can also use Arrow buttons\n";
		char instruc[] = "Press w for up\nPress a for right\nPress s for down\nPress d for right\n";
		myDrawTextWithFont(25, 20, 20, instruc1, white, black);
		myDrawTextWithFont(25, 60, 20, instruc, white, black);
		bool match = false;
		switch (_getch())
		{
		case 72:
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col))
				{
					handleShiftUp(nums, i, col);
				}
				for (int j = 0; j < col - 1; j++)
				{
					if (nums[i][j] == nums[i][j + 1] && nums[i][j] != 0)
					{
						score += nums[i][j];
						nums[i][j] += nums[i][j + 1];
						nums[i][j + 1] = 0;
						match = true;
					}
				}
				if (!checkIfAllZero(nums, i, col))
				{
					handleShiftUp(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 80:
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
				for (int j = 3; j > 0; j--)
				{
					if (nums[i][j] == nums[i][j - 1] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i][j - 1];
						nums[i][j - 1] = 0;
						match = true;
					}
				}
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 75:
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
				for (int i = 0; i < row - 1; i++)
				{
					if (nums[i][j] == nums[i + 1][j] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i + 1][j];
						nums[i + 1][j] = 0;
						match = true;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 77:
		{

			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
				for (int i = row - 1; i > 0; i--)
				{
					if (nums[i][j] == nums[i - 1][j] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i - 1][j];
						nums[i - 1][j] = 0;
						match = true;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 'e':
			begin = false;
			break;
		case 'd':
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
				for (int i = row - 1; i > 0; i--)
				{
					if (nums[i][j] == nums[i - 1][j] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i - 1][j];
						nums[i - 1][j] = 0;
						match = true;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftRight(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 's':
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
				for (int j = 3; j > 0; j--)
				{
					if (nums[i][j] == nums[i][j - 1] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i][j - 1];
						nums[i][j - 1] = 0;
						match = true;
					}
				}
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftDown(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 'a':
		{
			for (int j = 0; j < col; j++)
			{
				if (!checkIfAllColumnZero(nums, row, j)) 
				{
					handleShiftLeft(nums, j, row);
				}
				for (int i = 0; i < row - 1; i++)
				{
					if (nums[i][j] == nums[i + 1][j] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i + 1][j];
						nums[i + 1][j] = 0;
						match = true;
					}
				}
				if (!checkIfAllColumnZero(nums, row, j)) {
					handleShiftLeft(nums, j, row);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		case 'w':
		{
			for (int i = 0; i < 4; i++)
			{
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftUp(nums, i, col);
				}
				for (int j = 0; j < col - 1; j++)
				{
					if (nums[i][j] == nums[i][j + 1] && nums[i][j] != 0) {
						score += nums[i][j];
						nums[i][j] += nums[i][j + 1];
						nums[i][j + 1] = 0;
						match = true;
					}
				}
				if (!checkIfAllZero(nums, i, col)) {
					handleShiftUp(nums, i, col);
				}
			}
			placeRandomly(nums, 4);
			break;
		}
		default:
			break;
		

		}
		drawGrid(nums, 4);
		bool winBeforeGrid = false;
		winBeforeGrid = checkWin(nums, 4, winBeforeGrid);
		if (winBeforeGrid)
		{
			break;
		}
		if (!ifMatchExists(nums) && isGridFull(nums, row, col))
		{
			bool win = false;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (nums[i][j] == 1024)
					{
						win = true;
					}
				}
			}
			if (!win)
			{
				char lose[] = "You lose !! \n";
				myDrawTextWithFont(100, 250, 100, lose, COLORREF RGB(0, 0, 0), COLORREF RGB(255, 255, 255));
				begin = false;
			}
			else if (win)
			{
				char win[] = "You Win !! \nCONGRATULATIONS\n";
				myDrawTextWithFont(200, 200, 100, win, COLORREF RGB(0, 0, 0), COLORREF RGB(255, 255, 255));
				begin = false;
			}
		}
	}
}
void drawMenu()
{
	COLORREF white = RGB(255, 255, 255);
	COLORREF black = RGB(0, 0, 0);
	myRect(2000, 900, 0, 0, black, COLORREF RGB(0, 255, 255));
	char msg[] = "Welcome To 1024 Game \n";
	myDrawTextWithFont(440, 230, 60, msg, black, COLORREF RGB(0, 255, 255));
	char startMsg[] = "Press any key to play \n";
	myDrawTextWithFont(580, 300, 25, startMsg,black , COLORREF RGB(0, 255, 255));
}
void eraseMenu()
{
	COLORREF white = RGB(255, 255, 255);
	COLORREF black = RGB(0, 0, 0);
	myRect(2000, 900, 0, 0, black, black);
	char msg[] = "Welcome To 1024\n";
	myDrawTextWithFont(440, 230, 60, msg, black, black);
	char startMsg[] = "Press any key to play \n";
	myDrawTextWithFont(580, 300, 25, startMsg, black, black);
}
bool starter()
{
	char start = _getch();
	while (!start)
	{
		drawMenu();
		start = _getch();
	}
	eraseMenu();
	return true;
}
int main()
{
	srand(time(0));
	int nums[4][4]={};
	int x1, x2, y1, y2;
	drawMenu();
	bool begin = starter();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			nums[i][j] = 0;
		}
	}
	int ri = rand() % 4;
	int rj = rand() % 4;
	nums[ri][rj] = (rand() % 2) + 1;

	ri = rand() % 4;
	rj = rand() % 4;
	nums[ri][rj] = (rand() % 2) + 1;
	drawGrid(nums, 4);
	move(nums, 4);
	return 0;
}