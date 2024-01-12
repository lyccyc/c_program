#include <stdio.h>

typedef struct {
  char studentID[20];
  int programming, programmingLab, calculus;
} Student;

int calculateTotalScore(Student student) {
  return student.programming + student.programmingLab + student.calculus;
}

int main() {
  int num;

  scanf("%d", &num);

  Student students[num],temp;

  for (int i = 0; i < num; i++) {
    scanf("%s", students[i].studentID);
    scanf("%d", &students[i].programming);
    scanf("%d", &students[i].programmingLab);
    scanf("%d", &students[i].calculus);
  }

  for (int i = 0; i < num - 1; i++) {
    for (int j = 0; j < num - i - 1; j++) {
      if (calculateTotalScore(students[j]) < calculateTotalScore(students[j + 1])) {
        temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    printf("%s\n", students[i].studentID);
  }

  return 0;
}
