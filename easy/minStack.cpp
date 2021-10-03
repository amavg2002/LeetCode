#include <iostream>
#include <stack>
#include <vector>

using std::stack; using std::vector; using std::cout;
using std::cin; using std::endl;

class MinStack {
private:
    vector<int> stackArr;
    std::stack<int> min;
    int sSize;
public:
    MinStack() {
       sSize=-1;
    }

    void push(int val) {
        if( sSize==-1 ){ min.push(val);}
        else if( val <= min.top() ){min.push(val);}
        stackArr.push_back(val);
        sSize++;
    }

    void pop() {
        if(sSize>=0)
        {
           int temp=top();
            if(temp == min.top()){min.pop();}
            sSize--;
        }
    }

    int top() {

       return stackArr[sSize];
    }

    int getMin() {

        return min.top();
    }
};

int main(int argc, char * argv[])
{
    //[0,1,0]
    MinStack mins= new MinStack();
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    cout<<minStack.getMin()<<endl;
    minStack.pop();
    cout<<minStack.getMin()<<endl;    
   

	return 0;
}
