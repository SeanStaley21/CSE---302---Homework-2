

// The class definition for StackType using templates 
class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};


template<class ItemType>		
class StackType
{
public:
	// Class constructor.
    StackType();
    // Parameterized constructor.
    StackType(int max);
    // Destructor
    ~StackType();
    // Function: Determines whether the stack is full.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is full)
    bool IsFull() const;
    // Function: Determines whether the stack is empty.
    // Pre:  Stack has been initialized.
    // Post: Function value = (stack is empty)
    bool IsEmpty() const;
    // Function: Adds newItem to the top of the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is full), FullStack exception is thrown;
    //       otherwise, newItem is at the top of the stack.
    void Push(ItemType item);
    // Function: Removes top item from the stack and returns it.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from stack.
    ItemType Pop();
    // Function: Returns a copy of top item on the stack.
    // Pre:  Stack has been initialized.
    // Post: If (stack is empty), EmptyStack exception is thrown;
    //       otherwise, top element has been removed from stack.
    ItemType Peek();
           
private:
    int top;
    int maxStack;
    ItemType*  items;		
};

// The function definitions for class StackType.

template<class ItemType>
StackType<ItemType>::StackType(int max)
{
  maxStack = max;
  top = -1;
  items = new ItemType[maxStack];
}

template<class ItemType>
StackType<ItemType>::StackType()
{
  maxStack = 500;
  top = -1;
  items = new ItemType[maxStack];
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
  return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
  return (top == maxStack-1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem) 
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}

template<class ItemType>
ItemType StackType<ItemType>::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  ItemType curret = items[top];
  top--;
  return curret;
}

template<class ItemType>
ItemType StackType<ItemType>::Peek()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

template<class ItemType>
StackType<ItemType>::~StackType()
{
  delete [] items;
}




