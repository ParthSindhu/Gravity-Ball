// game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

enum edir
{
	stop, Right, down, upright, downright
};

class ball
{
public:

	inline int getx()
	{
		return x;
	}

	inline int gety()
	{
		return y;
	}

	inline int getdir()
	{
		return direction;
	}

	void reset()
	{
		x = originalx;
		y = originaly;
		direction = stop;
	}

	inline void reducex()
	{
		x--;
	}

	ball(int posx, int posy)
	{
		originalx = posx;
		originaly = posy;
		x = originalx;
		y = originaly;
		direction = stop;
	}

	void move()
	{
	switch(direction)
	{
	case stop:
		break;
	case Right:
		x++;
		break;
	case upright:
		x++;
		y--;
		break;
	case downright:
		x++;
		y++;
		break;
	case down:
		y++;
		break;
	}
	}

	inline void changedir(edir d)
	{
		direction = d;		
	}
	
private:
	edir direction;
	int type;
	int x, y;
	int originalx, originaly;
	
};

class barrier 
{
private:
	int x, y;
	int originalx, originaly;

public:
	inline int getx()
	{
		return x;
	}

	inline int gety()
	{
		return y;
	}

	barrier(int posx,int posy)
	{
		originalx = posx;
		originaly = posy;
		x = originalx;
		y = originaly;
	}

	inline void move()
	{
		x--;
	}
};

class gamemanager
{
private:
	int score;
	char character;
	int width, height;
	bool quit;
	ball *cball;
	barrier *barrier1 , *barrier2 , *barrier3 ,*barrier4 , *barrier5;
public:
	gamemanager(int w, int h)
	{
		srand(time(NULL));
		score = 0;
		quit = false;
		character = 'a';
		width = w; height = h;
		cball = new ball(0, h - 1);
		barrier1 = new barrier(40, rand() % (h - 5) + 2);
		barrier2 = new barrier(60, rand() % (h - 5) + 2);
		barrier3 = new barrier(80, rand() % (h - 5) + 2);
		barrier4 = new barrier(100, rand() % (h - 5) + 2);
		barrier5 = new barrier(120, rand() % (h - 5) + 2);
	}

	~gamemanager()
	{
		delete cball , barrier1 , barrier2 , barrier3 , barrier4 , barrier5;
	}

	void logic()
	{
		int ballx = cball->getx();
		int bally = cball->gety();
		int barrier1x = barrier1->getx();
		int barrier1y = barrier1->gety();
		int barrier2x = barrier2->getx();
		int barrier2y = barrier2->gety();
		int barrier3x = barrier3->getx();
		int barrier3y = barrier3->gety();
		int barrier4x = barrier4->getx();
		int barrier4y = barrier4->gety();
		int barrier5x = barrier5->getx();
		int barrier5y = barrier5->gety();

		for (int i = 0; i < 4; i++)
		{
			if (ballx == barrier1x + 1)
				if (bally == barrier1y + i)
				{
					cball->reducex();
					score--;
					cball->changedir((edir)down);
				}
		

		
		
			if (ballx == barrier2x + 1)
				if (bally == barrier2y + i)
				{
					cball->reducex();
					score--;
					cball->changedir((edir)down);
				}
	

		
		
			if (ballx == barrier3x + 1)
				if (bally == barrier3y + i)
				{
					cball->reducex();
					score--;
					cball->changedir((edir)down);
				}
		

		
			if (ballx == barrier4x + 1)
				if (bally == barrier4y + i)
				{
					cball->reducex();
					score--;
					cball->changedir((edir)down);
				}
		

		
			if (ballx == barrier5x + 1)
				if (bally == barrier5y + i)
				{
					cball->reducex();
					score--;
					cball->changedir((edir)down);
				}
		}


		if (bally == height - 1)
		{
			cball->changedir((edir)Right);
		}

		if (bally == 0)
		{
			cball->changedir((edir)Right);
		}

		if (ballx == 0)
		{
			cball->reset();
		}

		if (ballx == width-1)
		{
			cball->reset();
			score++;
		}

		if (barrier1x==0)
			barrier1=new barrier(80, rand() % (height - 5) + 2);

		if (barrier4x == 0)
			barrier4 = new barrier(60, rand() % (height - 5) + 2);

		if (barrier3x == 0)
			barrier3 = new barrier(60, rand() % (height - 5) + 2);

		if (barrier2x == 0)
			barrier2 = new barrier(80, rand() % (height - 5) + 2);

		if (barrier5x == 0)
			barrier5 = new barrier(80, rand() % (height - 5) + 2);
	}

	void input()
	{
		 cball->move();
		 barrier1->move();
		 barrier2->move();
		 barrier3->move();
		 barrier4->move();
		 barrier5->move();

		int ballx = cball->getx();
		int bally = cball->gety();
		int barrier1x = barrier1->getx();
		int barrier1y = barrier1->gety();
		int barrier2x = barrier2->getx();
		int barrier2y = barrier2->gety();
		int barrier3x = barrier3->getx();
		int barrier3y = barrier3->gety();
		int barrier4x = barrier4->getx();
		int barrier4y = barrier4->gety();
		int barrier5x = barrier5->getx();
		int barrier5y = barrier5->gety();

	
		if (_kbhit())
		{
			char current = _getch();
			if (current == character)
			{
				if (bally == 0)
				{
					cball->changedir((edir)downright);
				}
				if (bally == height - 1)
					cball->changedir((edir)upright);

				cball->move();
			}
			barrier1->move();
			barrier2->move();
			barrier3->move();
			barrier4->move();
			barrier5->move();

			if (current == 'q')
				quit = true;
		}

	}

	void draw()
	{
		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j <= width; j++)
			{
				int ballx = cball->getx();
				int bally = cball->gety();
				int barrier1x = barrier1->getx();
				int barrier1y = barrier1->gety();
				int barrier2x = barrier2->getx();
				int barrier2y = barrier2->gety();
				int barrier3x = barrier3->getx();
				int barrier3y = barrier3->gety();
				int barrier4x = barrier4->getx();
				int barrier4y = barrier4->gety();
				int barrier5x = barrier5->getx();
				int barrier5y = barrier5->gety();


				if (j == 0)
					cout << "\xB2";
				if (ballx == j && bally == i)
					cout << "o";
				else if (barrier1x == j && barrier1y == i) // barrier 1-5
					cout << "\xDB";
				else if (barrier2x == j && barrier2y == i)
					cout << "\xDB";
				else if (j == width)
					cout << "\xB2";
				else if (barrier1x == j && barrier1y + 1 == i)
					cout << "\xDB";
				else if (barrier1x == j && barrier1y + 2 == i)
					cout << "\xDB";
				else if (barrier1x == j && barrier1y + 3 == i)
					cout << "\xDB";
				else if (barrier2x == j && barrier2y + 1 == i)
					cout << "\xDB";
				else if (barrier2x == j && barrier2y + 2 == i)
					cout << "\xDB";
				else if (barrier2x == j && barrier2y + 3 == i)
					cout << "\xDB"; // jkjk
				else if (barrier3x == j && barrier3y == i)
					cout << "\xDB";
				else if (barrier4x == j && barrier4y == i)
					cout << "\xDB";
				else if (j == width)
					cout << "\xB2";
				else if (barrier3x == j && barrier3y + 1 == i)
					cout << "\xDB";
				else if (barrier3x == j && barrier3y + 2 == i)
					cout << "\xDB";
				else if (barrier3x == j && barrier3y + 3 == i)
					cout << "\xDB";
				else if (barrier4x == j && barrier4y + 1 == i)
					cout << "\xDB";
				else if (barrier4x == j && barrier4y + 2 == i)
					cout << "\xDB";
				else if (barrier4x == j && barrier4y + 3 == i)
					cout << "\xDB";
				else if (barrier5x == j && barrier5y == i)
					cout << "\xDB";
				else if (barrier5x == j && barrier5y + 1 == i)
					cout << "\xDB";
				else if (barrier5x == j && barrier5y + 2 == i)
					cout << "\xDB";
				else if (barrier5x == j && barrier5y + 3 == i)
					cout << "\xDB";
				
				else
					cout << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "\xB2";
		cout << endl;

		cout << "Score : " << score << endl;
	}

	void run()
	{
		while (!quit)
		{
			draw();
			input();
			logic();
			quit = false;
		}
	}
};

int main()
{
	system("title Gravity Guy");
	system("color 79");
	system("mode 650");
	gamemanager c(100, 20);
	c.run();
	return 0;
}
