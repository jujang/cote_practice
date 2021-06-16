#include <iostream>
#include <string>
#include <vector>

using namespace std;


//1. ���� Ȯ�� (������ �ƴ� ���)
// -1  (���� ū ���� �ƴ� ���)[=(flag == 1)] pop&push_back
//   location -1 & answer ���� ���� & flag = 0;
// -2. (���� ū ���� ���)[=(flag != 1)] pop
//   lacation -1 & answer +1

//2. ���� Ȯ�� (������ ���)
// -1. (���� ū ���� �ƴ� ���)[=(flag == 1)] pop&push_back
//   location = priorities.size()-1 & answer �������� & flag = 0;
// -2. (���� ū ���� ���)[=(flag != 1)] 
//   answer +1 & return answer


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

        if (flag == 1 && location != 0) {
            priorities.push_back(temp);
            location--;
            flag = 0;
        }
        else if (flag != 1 && location != 0) {
            location--;
            answer++;
        }
        else if (flag == 1 && location == 0) {
            priorities.push_back(temp);
            location = priorities.size() - 1;
        }
        else if (flag != 1 && location == 0) {
            answer++;
            break;
        }
        else {
            cout << "error" << endl;
        }
    }

    return answer;
}


int main () {

    vector<int> priorities;
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);

    int location = 0;

    int ret = solution(priorities, location);
    cout << ret << endl;

    return 0;
}