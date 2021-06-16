//21년 6월 15일
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int flag = 0;

    while (1) {

        for (int i = 1; i < priorities.size(); i++) {
            if (priorities[0] < priorities.at(i)) {
                flag = 1;
            }
        }

        int temp = priorities.at(0);
        priorities.erase(priorities.begin());

        if (location != 0) {
            location--;
            if (flag == 1) {
                priorities.push_back(temp);
                flag = 0;
            }
            else {
                answer++;
            }
        }
        else {
            if (flag == 1) {
                priorities.push_back(temp);
                location = priorities.size() - 1;
                flag = 0;
            }
            else {
                answer++;
                break;
            }
        }
    }
    return answer;
}
