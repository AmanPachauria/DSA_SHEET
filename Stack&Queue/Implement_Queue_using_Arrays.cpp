class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}
    
	int cnt = 0;
	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		if(arr.size()==cnt) return;
		else arr[rear%arr.size()] = e;
		rear++;
		cnt++;
		// Write your code here.
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(cnt==0) return -1;
	
		int a = arr[front%arr.size()];
		arr[front%arr.size()] = -1;
		front++;
		cnt--;
	
		return a;
		// Write your code here.
	}
};