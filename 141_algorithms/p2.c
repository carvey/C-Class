#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void plotlow(int x0,int y0,int x1,int y1) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	if (dy < 0) {
		yi = -1;
		dy = -dy;
	}
	int d = (2*dy) - dx;
	int y = y0;

	for (int i = x0; i <= x1; i++) {
		printf("%d,%d\n", i, y);	
		if (d > 0) {
			y = y + yi;
			d = d - (2*dx);
		}
		d = d + (2*dy);
	}
}

void plothigh(int x0,int y0,int x1,int y1) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}

	int d = (2*dx - dy);
	int x = x0;

	for (int i = y0; i <= y1; i++) {
		printf("%d,%d\n", x, i);
		if (d > 0) {
			x = x + xi;
			d = d - (2*dy);
		}
		d = d + (2*dx);
	}
}

void plotline(int x0,int y0,int x1,int y1) {
	if (abs(y1-y0) < abs(x1-x0)) {
		if (x0 > x1) {
			plotlow(x1,y1,x0,y0);
		} else { 
			plotlow(x0,y0,x1,y1);
		}
	} else {
		if (y0 > y1) {
			plothigh(x1,y1,x0,y0);
		} else {
			plothigh(x0,y0,x1,y1);
		}
	}	
}


int main(void)
{
  srand((unsigned)time(NULL));
  int x0 = rand()%100;
  int y0 = rand()%100;
  int x1 = rand()%100;
  int y1 = rand()%100;
  
  printf("Starting at: (%d,%d) to (%d,%d)\n", x0,y0,x1,y1);
  plotline(x0,y0,x1,y1);
  printf("%d,%d\n", x1,y1);

  return EXIT_SUCCESS;
}
