// package tw5;

class Stack {
    int ele[];
    int top;

    void initStack(int size) {
        ele = new int[size];
        top = -1;
    }

    void initStack(Stack obj) {
        ele = new int[obj.ele.length];
        top = -1;

        for(int i: obj.ele) push(i);
    }

    void initStack(int arr[]) {
        ele = new int[arr.length];
        top = -1;

        for(int i: arr) push(i);
    }

    void push(int element) {
        if(top == ele.length - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        ele[++top] = element;
        System.out.println("Pushed element " + element);
    }

    int pop() {
        if(top == -1) {
            System.out.println("Stack Underflow");
            return -1;
        }
        return ele[top--];
    }

    int peek() {
        if(top == -1) {
            System.out.println("Stack Underflow");
            return -1;
        }
        return ele[top];
    }
}

public class TW5A {
    public static void main(String[] args) {
        Stack s1 = new Stack();
        Stack s2 = new Stack();
        Stack s3 = new Stack();

        s1.initStack(5);
        s1.push(10);
        s1.push(20);
        s1.push(30);
        s1.push(40);
        s1.push(50);

        s2.initStack(s1);

        int arr[] = {1, 2, 3, 4, 5};
        s3.initStack(arr);

        System.out.println("Poped element from s1 " + s1.pop());
        System.out.println("Top element of s1 " + s1.peek());
        System.out.println("Top element of s2 " + s2.peek());
    }
}
