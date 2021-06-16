// 작업 날짜 : 21년 6월 14일
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