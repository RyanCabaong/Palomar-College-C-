#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TRACKS 2
#define SEGMENTS 10
#define TRAINS 4
#define SIMTIME 2

struct Segment
{
	int train;
	struct Segment* next, * prev, * next_adj, * prev_adj;
};

void init_tracks(struct Segment *segments[TRACKS][SEGMENTS]);
void print_tracks(struct Segment* segments[TRACKS][SEGMENTS]);
void move_trains(struct Segment* segments[TRACKS][SEGMENTS]);
void release_train(struct Segment* segments[TRACKS][SEGMENTS]);

int main()
{
	struct Segment* segments[TRACKS][SEGMENTS];

	init_tracks(segments);

	for (int i = 0; i < SIMTIME; i++)
	{
		print_tracks(segments);
		cout << "++++++++++++++++++++" << endl;
		move_trains(segments);
	}

	release_train(segments);

	return 0;
}


// release_train
void release_train(struct Segment* segments[TRACKS][SEGMENTS])
{

	for (int i = 0; i < TRACKS; i++)
		for (int j = 0; j < SEGMENTS; j++)
			delete segments[i][j];

}

// init_tracks
void init_tracks(struct Segment* segments[TRACKS][SEGMENTS])
{
	// Allocate memory
	for (int i = 0; i < TRACKS; i++)
		for (int j = 0; j < SEGMENTS; j++)
		{
			segments[i][j] = new Segment;
			segments[i][j]->train = 0;  // init to empty
		}

	// randomize seed
	srand(time(0));

	// connect the segments
	for (int i = 0; i < TRACKS; i++)
	{
		for (int j = 0; j < SEGMENTS; j++)
		{
			int knext, kprev;

			knext = (j + 1) % SEGMENTS;
			kprev = (SEGMENTS + j - 1) % SEGMENTS;

			segments[i][j]->next = segments[i][knext];
			segments[i][j]->prev = segments[i][kprev];
			segments[i][j]->next_adj = segments[TRACKS - i - 1][knext];
			segments[i][j]->prev_adj = segments[TRACKS - i - 1][kprev];
		}
	}

	// place the trains
	int n = 4;
	while (n > 0)
	{
		int trackid, segmentid, dirid;

		trackid = rand() % TRACKS;
		segmentid = rand() % SEGMENTS;
		dirid = 2 * (rand() % 2) - 1;

		if (segments[trackid][segmentid]->train == 0)
		{
			segments[trackid][segmentid]->train = dirid;
			n = n - 1;
		}
	}

}



void move_trains(struct Segment* segments[TRACKS][SEGMENTS])
{
	for (int i = 0; i < TRACKS; i++)
	{
		for (int j = 0; j < SEGMENTS; j++)
		{
			struct Segment* t_segment = segments[i][j];

			if (t_segment->train == 1)  // CW
			{
				if (t_segment->next->train == 0)
				{
					t_segment->train = 0;
					t_segment->next->train = 2;
				}
				else if (t_segment->next_adj->train == 0)
				{
					t_segment->train = 0;
					t_segment->next_adj->train = 2;
				}
			}
			else if (t_segment->train == -1)  // CCW
			{
				if (t_segment->prev->train == 0)
				{
					t_segment->train = 0;
					t_segment->prev->train = -2;
				}
				else if (t_segment->prev_adj->train == 0)
				{
					t_segment->train = 0;
					t_segment->prev_adj->train = -2;
				}
			}
		}
	}

	// reset 2/-2 to 1/-2
	for (int i = 0; i < TRACKS; i++)
		for (int j = 0; j < SEGMENTS; j++)
			if (segments[i][j]->train == 2 || segments[i][j]->train == -2)
				segments[i][j]->train = segments[i][j]->train / 2;
}


void print_tracks(struct Segment* segments[TRACKS][SEGMENTS])
{
	cout << "+-";
	for (int i = 0; i < SEGMENTS / 2; i++)
	{
		if (segments[0][i]->train == 0)
			cout << "---";
		else if (segments[0][i]->train == 1)
			cout << "->-";
		else
			cout << "-<-";
	}
	cout << "-+" << endl << "|  X  X  X  X  X  |" << endl;
	cout << "| ";
	for (int i = 0; i < SEGMENTS / 2; i++)
	{
		if (segments[1][i]->train == 0)
			cout << "---";
		else if (segments[1][i]->train == 1)
			cout << "->-";
		else
			cout << "-<-";
	}
	cout << " |";
	cout << endl << "| |             | |" << endl;
	cout << "| ";
	for (int i = SEGMENTS-1; i >= SEGMENTS/2; i--)
	{
		if (segments[1][i]->train == 0)
			cout << "---";
		else if (segments[1][i]->train == 1)
			cout << "-<-";
		else
			cout << "->-";
	}
	cout << " |";
	cout << endl;
	cout << "|  X  X  X  X  X  | " << endl;
	cout << "+-";
	for (int i = SEGMENTS - 1; i >= SEGMENTS / 2; i--)
	{
		if (segments[0][i]->train == 0)
			cout << "---";
		else if (segments[0][i]->train == 1)
			cout << "-<-";
		else
			cout << "->-";
	}
	cout << "-+";
	cout << endl << endl;
}