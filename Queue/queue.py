# Queue implementation using a list (like an array in C)
MAX = 5  # Maximum size of the queue
queue = [0] * MAX  # Initialize queue with zeros
front = -1  # Points to the front element (-1 means empty)
rear = -1   # Points to the rear element (-1 means empty)


def enqueue(value):
    """Add an element to the rear of the queue"""
    global front, rear
    
    if rear == MAX - 1:
        # Queue is full - no more space to add
        print(f"Queue Overflow! Cannot insert {value}")
    else:
        if front == -1:
            # First element being added - initialize front
            front = 0
        rear += 1
        queue[rear] = value
        print(f"{value} inserted into queue")


def dequeue():
    """Remove an element from the front of the queue"""
    global front, rear
    
    if front == -1 or front > rear:
        # Queue is empty - nothing to remove
        print("Queue Underflow! Queue is empty")
    else:
        print(f"{queue[front]} removed from queue")
        front += 1
        
        # Reset queue when all elements are removed
        if front > rear:
            front = -1
            rear = -1


def display():
    """Display all elements in the queue"""
    if front == -1 or front > rear:
        # Queue is empty
        print("Queue is empty")
    else:
        print("Queue elements are: ", end="")
        for i in range(front, rear + 1):
            print(queue[i], end=" ")
        print()  # Newline


# Test the queue operations
enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)
enqueue(50)
display()
dequeue()
display()