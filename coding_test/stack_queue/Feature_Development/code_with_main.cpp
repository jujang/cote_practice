#include <string>
#include <vector>
#include <iostream> 

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    int size = progresses.size();      
    vector<int> days(size, 0);         
    vector<int> days_remain(size, 0);  

    for (int i = 0; i < size; i++) {
        days[i] = (100 - progresses[i]) / speeds[i];
        days_remain[i] = (100 - progresses[i]) % speeds[i];
        if (days_remain[i] != 0) {
            days[i]++;
        }
    }
    
    vector<int> answer; 
    int a = 0;  
    int currentValue;
    for (int k = 0; k < days.size(); ) {
        currentValue = days.at(k++);
        answer.push_back(1);
        while (k < days.size() && currentValue >= days.at(k)) {
            answer[a]++;
            k++;
        }
        a++;
    }
        
    return answer;
}

int main(void) {

    vector<int>a1;
    a1.push_back(95);
    a1.push_back(90);
    a1.push_back(99);
    a1.push_back(99);
    a1.push_back(80);
    a1.push_back(99);

    vector<int>b1;
    b1.push_back(1);
    b1.push_back(1);
    b1.push_back(1);
    b1.push_back(1);
    b1.push_back(1);
    b1.push_back(1);

    solution(a1, b1);
    return 0;

}