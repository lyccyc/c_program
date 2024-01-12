#include <stdio.h>

typedef struct {
  float x, y;
} Point;

typedef struct {
  Point point;
  float slope;
} Line;

// Function to check if a point lies on a line
int isinLine(Line line, Point point) {
  // Check if the y-coordinate of the point is equal to the y-coordinate of the line equation
  return point.y == (line.slope * (point.x - line.point.x) + line.point.y);
}

int main() {
  Line line;
  Point point;

  scanf("%f, %f, %f", &line.point.x,&line.point.y,&line.slope);

  scanf("%f, %f", &point.x,&point.y);

  // Check if the point is on the line
  if (isinLine(line, point)) {
    printf("Yes");
  } 
  else {
    printf("No");
  }

  return 0;
}
