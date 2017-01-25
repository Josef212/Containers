#ifndef __HEAP__
#define __HEAP__

template<class TYPE>
class HeapNode
{
public:
	HeapNode()
	{}

	HeapNode(int hIndex) : heapIndex(hIndex)
	{}

	virtual int compareTo(HeapNode node) = 0;
	/*{
		int compare = fCost.CompareTo(nodeToCompare.fCost);
        if(compare == 0)
        {
            compare = hCost.CompareTo(nodeToCompare.hCost);
        }

        return -compare;
	}*/

public:	
	int heapIndex = 0;
};

template<class TYPE>
class Heap
{
public:
	Heap(int maxSize)
	{
		items = new TYPE[maxSize];
	}

	~Heap()
	{
		if (items != nullptr)
			delete[] items;
	}

	void add(TYPE item)
	{
		item.heapIndex = curretnItemCount;
		items[curretnItemCount] = item;
		sortUp(item);
		++curretnItemCount;
	}

	TYPE removeFirst()
	{
		TYPE ret = items[0];
		--curretnItemCount;
		items[0] = items[curretnItemCount];
		items[0].heapIndex = 0;
		sortDown(items[0]);
		return ret;
	}

	int count()
	{
		return curretnItemCount;
	}

	void updateItem(TYPE item)
	{
		sortUp(item);
	}

	bool contains(TYEP item)
	{
		return (items[item.heapIndex] == item);
	}

private:
	void sortUp(TYPE item)
	{
		int parentIndex = (item.heapIndex - 1) / 2;

		while (true)
		{
			TYPE parentItem = items[parentIndex];

			if (item.compareTo(parentItem) > 0)
				swap(item, parentItem);
			else
				break;

			parentIndex = (item.heapIndex - 1) / 2;
		}
	}

	void sortDown(TYPE item)
	{
		while (true)
		{
			int childInL = item.heapIndex * 2 + 1;
			int childInR = item.heapIndex * 2 + 2;
			
			int swapIndex = 0;

			if (childInL < curretnItemCount)
			{
				swapIndex = childInL;

				if (childInR < curretnItemCount)
				{
					if (items[childInL].compareTo(items[childInR]) < 0)
						swap(item, items[swapIndex]);
				}

				if (item.compareTo(items[swapIndex]) < 0)
					swap(item, items[swapIndex]);
				else
					return;
			}
			else
				return;		
		}
	}

	void swap(TYPE a, TYPE b)
	{
		items[a.heapIndex] = b;
		items[b.heapIndex] = a;
		int tmp = a.heapIndex;
		a.heapIndex = b.heapIndex;
		b.heapIndex = tmp;
	}

private:
	TYPE* items = nullptr;
	int curretnItemCount = 0;

};

/*class Node : public HeapNode<Node>
{
public:
	Node()
	{}

	int gCost;
	int hCost;
	bool walkable;
	Node* parent = nullptr;

	int fCost()
	{
		return gCost + hCost;
	}

	int compareTo(Node* node)
	{
		int ret = (fCost == node->fCost) ? 0 : 1; //NOTE: Check this
		
		return (ret == 0) ? ((hCost == node->hCost) ? 0 : -1) : (-ret);
	}
};*/

#endif // !__HEAP__