enum State{
	Unvisited, Visited, Visiting;
}

bool search(Graph g, Node* start, Node* end)
{
	if(start == end) return true;
	queue<node*> q = new queue<node*>();
	for(Node* curr: g.getNodes())
	{
		curr->state = State.Unvisited; //initialize as unvisited
	}
	start->state = State.Visiting;
	q.add(start);
	Node* curr;
	while(!q.empty())
	{
		curr = q.front();
		q. pop();
		if(curr != NULL)
		{
			for(node* neighbors: curr.getAdjacent())
			{
				if(neighbors.state == State.Unvisited)
				{
					if(neighbors == end)
					{
						return true;
					}
					else
					{
						neighbors.state = State.Visiting;
						q.add(neighbors);
					}
				}
			}
			curr->state = State.Visited;
		}
	}

	return false;
}