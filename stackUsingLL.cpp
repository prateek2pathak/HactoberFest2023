class Queue {
	Node *head;
	Node *tail;
	int size;

   public:
    Queue() {
		head=NULL;
		tail=NULL;
		size=0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		return size;
	}

    bool isEmpty() {
		return size==0;
	}

    void enqueue(int data) {
		size++;
		if(head==NULL){
			head= new Node(data);
			tail=head;
			return;
		}
		Node *temp=new Node(data);
		tail->next=temp;
		tail=temp;
	}

    int dequeue() {
		if(size==0) return -1;

        int data=head->data;
		Node *temp=head;
		head=head->next;
		delete temp;
		size--;
		return data;

    }

    int front() {
		if(size==0) return -1;
       return head->data;
    }
};
