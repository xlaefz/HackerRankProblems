using namespace std;

template <typename T>
class MinHeap {
public:

	MinHeap (int d)
	{
		currentsize = 0;
		d_ = d;
	}
	/* Constructor that builds a d-ary Min Heap
	This should work for any d >= 2,
	but doesn't have to do anything for smaller d.*/

	~MinHeap ()
	{

	}

	void add (T item, int priority)
	{
		++currentsize;
		tree.push_back(make_pair(item, priority));
		percolateup(currentsize-1); //the index we percolate up
	}
	/* adds the item to the heap, with the given priority. */

	const T & peek () const
	{
		return tree[0].first;
	}
	/* returns the element with smallest priority. */

	void remove ()
	{
		if(isEmpty())
		{
			//if empty don't do anything
		}
		else
		{
			std::iter_swap(tree.begin(), tree.end()-1);
			tree.pop_back();
			currentsize--;
			percolatedown(0);
		}
	}
	/* removes the element with smallest priority. */

	bool isEmpty ()
	{
	    if(currentsize == 0)
	    {
	    	return true;
	    }
	    else
	    {
	    	return false;
	    }
	}
	/* returns true iff there are no elements on the heap. */

	void printme()
	{
		for(int i=0; i < tree.size(); ++ i)
		{
			cout<< "my first " << tree[i].first << " " << "my second " << tree[i].second<< endl;
		}
	}

private:
// whatever you need to naturally store things.
// You may also add helper functions here.
	int d_;
    std::vector<pair<T,int> > tree;
    int currentsize;

    void percolateup(int pos)
    {	

    	while(pos > 0 && tree[pos].second < tree[(pos-1)/d_].second)
    	{
    		std::iter_swap(tree.begin()+pos, tree.begin()+(pos-1)/d_);
    		pos = (pos-1)/d_;
    	}
	}

	void percolatedown(int pos)
	{
		int child = d_*pos + 1;
		if(child < currentsize)
		{
			int lowestpriority = tree[child].second;
			int index = child;
			for(int i = 0; i < d_; ++i) //look for smallest priority
			{
				if(child + i < currentsize && lowestpriority > tree[child+i].second)
				{
					lowestpriority = tree[child+i].second;
					index = child + i;
				}
			}
			child = index;
			if(tree[child].second < tree[pos].second)
			{
				std::iter_swap(tree.begin()+child, tree.begin()+ pos); //swaps
				percolatedown(child);
			}
		}
	}
};