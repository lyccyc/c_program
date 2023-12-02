#include <stdio.h>

#define MAX_M 1000
#define MAX_N 1000

struct Course {
    int sid;
    int student_id;
    int course_id;
};

struct Score {
    int sid;
    int score;
};

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    struct Course courses[MAX_M];
    struct Score scores[MAX_N];

    // 讀取 courses 的內容
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &courses[i].sid, &courses[i].student_id, &courses[i].course_id);
    }

    // 讀取 scores 的內容
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &scores[i].sid, &scores[i].score);
    }

    int studentCount = 0;
    int failCount = 0;

    // 遍歷每位學生
    for (int i = 0; i < m; i++) {
        int studentID = courses[i].student_id;
        int hasFailed = 0;
        int totalScore = 0;
        int courseCount = 0;

        // 遍歷該學生的每一科目
        for (int j = 0; j < n; j++) {
            if (scores[j].sid == courses[i].sid) {
                totalScore += scores[j].score;
                courseCount++;

                // 如果該科目分數不及格
                if (scores[j].score < 60) {
                    hasFailed = 1;
                }
            }
        }

        // 如果有至少一科被當
        if (hasFailed) {
            failCount++;
        }

        // 如果有修過科目
        if (courseCount > 0) {
            studentCount++;
        }
    }

    // 輸出結果
    printf("%d %d\n", studentCount, failCount);

    return 0;
}
