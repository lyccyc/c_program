#include <stdio.h>

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

    struct Course courses[MAX_N];
    struct Score scores[MAX_N];
    int stuid[n];
    // 讀取 courses 的內容
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &courses[i].sid, &courses[i].student_id, &courses[i].course_id);
        stuid[i]=courses[i].student_id;
    }

    // 讀取 scores 的內容
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &scores[i].sid, &scores[i].score);
    }

    int studentCount = 1;
    int failCount = 0;
    int hasFailed = 0;
    int courseCount = 0;
    int total,ave;
    // 遍歷每位學生
    for (int i = 0; i < m; i++) {

        // 遍歷該學生的每一科目
        for (int j = 0; j < n; j++) {
            if (scores[j].sid == courses[i].sid) {
                total += scores[j].score;
                courseCount++;
            }
        }
        // 如果該科目分數不及格
        if (total < 60*courseCount) {
            hasFailed += 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(stuid[j]>stuid[j+1]){
                int temp=stuid[j+1];
                stuid[j]=stuid[j+1];
                stuid[j+1]=temp;
            }
        }
        if(stuid[i] != stuid[i+1]){
            studentCount++;
        }
    }

    // 輸出結果
    printf("%d %d\n", studentCount, hasFailed);

    return 0;
}
