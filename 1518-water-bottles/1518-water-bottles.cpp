class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            int newBottle = empty / numExchange;
            answer += newBottle;
            empty = newBottle + (empty % numExchange);
        }

        return answer;
    }
};